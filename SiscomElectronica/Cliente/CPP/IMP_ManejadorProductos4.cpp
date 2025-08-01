#include <IMP_ManejadorProductos4.h>
#include <IMP_RegistrarCajaMaterial.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
#include <zProductos.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>

#include <QCtrlProductosSE.h>
#include <QCtrlCajasUbicacion.h>
#include <QCtrlEstantes.h>

#include <zSiscomElectronica.h>

QManejadorProductos4 *InstanciaManejadorProductos4(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManejadorProductos4((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManejadorProductos4::QManejadorProductos4(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorProductos4(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				 zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QManejadorProductos4::~QManejadorProductos4()
{

}

void QManejadorProductos4::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrEstantes->Servidor(zSisConexion);
QCtrCajas->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
QCtrCajas->IniciaControl();
QCtrEstantes->IniciaControl();
zSiscomQt3::Foco(QCtrProductos);
}
void QManejadorProductos4::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QCtrProductos,
	SIGNAL(SignalSeleccionados(zProductos *)),
	SLOT(SlotSeleccionados(zProductos *)));
connect(QPBRegistrarCaja,
        SIGNAL(clicked()),
	SLOT(SlotRegistrarCaja()));
connect(QCtrCajas,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoCaja(zSiscomRegistro *)));
connect(QCtrEstantes,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotEstante(zSiscomRegistro *)));
connect(QPBAsignarUbicacion,SIGNAL(clicked()),SLOT(SlotAsignarUbicacion()));
connect(QPBAsigCajaDeDescripcion,SIGNAL(clicked()),SLOT(SlotAsignaCajaDeDescripcion()));
connect(QTUbicacion,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotProducto(int,int,int,const QPoint &)));
}
void QManejadorProductos4::SlotProducto(int pintNProducto,
				        int,
					int,
					const QPoint &)
{
/*
  if(pintNProducto!=-1)
  {
  zSisRegProducto=ProductoComoConsultaBase((*zProdsSeleccionados)[pintNProducto]);
  SeleccionoProducto();
  }

*/
}
void QManejadorProductos4::SlotEstante(zSiscomRegistro *pzSisRegEstante)
{
  AsignandoEstante(pzSisRegEstante);
  QCtrCajas->setEnabled(true);
  zSiscomQt3::Foco(QCtrCajas);
  HabilitarAsignarUbicacion();
}
void QManejadorProductos4::SlotAsignaCajaDeDescripcion()
{
  AsignaCajaDeDescripcion();
}
void QManejadorProductos4::SlotAsignarUbicacion()
{
  AsignandoCaja();
  QCtrProductos->IniciaControl();
  zSisRegCaja=zSisRegEstante=0;
  QLECaja->setText("");
  zSiscomQt3::Foco(QCtrProductos);
  MuestraProductoActualizado();
}
void QManejadorProductos4::SlotSeleccionoCaja(zSiscomRegistro *pzSisRegCaja)
{
  AsignandoCaja(pzSisRegCaja);
  QPBAsignarUbicacion->setEnabled(true);
  AsignaCajaAlProducto();
  HabilitarAsignarUbicacion();
  zSiscomQt3::Foco(QPBAsignarUbicacion);
}
void QManejadorProductos4::SlotRegistrarCaja()
{
 RegistrarCaja();
}
void QManejadorProductos4::SlotSeleccionados(zProductos *pzProductos)
{
  zProdsSeleccionados=pzProductos;
  MuestraProductos(zProdsSeleccionados);
}
void QManejadorProductos4::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
   zSisRegProducto=pzSisRegProducto;
   SeleccionoProducto();
}
void QManejadorProductos4::MuestraDescripcion()
{
 QLECveProducto->setText((const char *)(*zSisRegProducto)["cveproducto"]);
 QTEDescripcion->setText((const char *)(*zSisRegProducto)["dscproducto"]);
}
void QManejadorProductos4::MuestraUbicacion()
{
QString lQSUbicacion="";

if(!(*zSisRegProducto)["estante"])
lQSUbicacion=QString("Caja:") 		+
	     " "			+
	     (const char *)(*zSisRegProducto)["caja"];
else
if(!(*zSisRegProducto)["caja"])
lQSUbicacion=QString("Estante:") 		+
	    " "					+
	    (const char *)(*zSisRegProducto)["estante"];
else
lQSUbicacion=QString("Estante:")				+
	     " "						+
	     (const char *)(*zSisRegProducto)["estante"] 	+
	     " "						+
	     "Caja:"						+
	     " "						+
	     (const char *)(*zSisRegProducto)["caja"];
QLECaja->setText(lQSUbicacion);
}
void QManejadorProductos4::MostrandoUbicacion()
{
  if(TieneUbicacion())
   MuestraUbicacion();
   else
   QLECaja->setText("");
}
void QManejadorProductos4::RegistrarCaja()
{
QRegistrarCajaMaterial lQRegCajaMat;
if(lQRegCajaMat.Aceptar()==2)
  QCtrCajas->ReConsultando();
}
void QManejadorProductos4::AsignandoCaja()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"AsignaCajaProducto");
lzSisElectronica.AsignaCajaProducto(zSisRegProducto);
SiscomRegistroLog2(zSisRegProducto);
}
void QManejadorProductos4::AsignaCajaAlProducto()
{
  zSisRegProducto->ActualizaCampo("idcaja",(*zSisRegCaja)["idcaja"]);
  zSisRegProducto->ActualizaCampo("idestante",(*zSisRegEstante)["idestante"]);
}
void QManejadorProductos4::MuestraProductos(zProductos *pzProductos)
{
const char *lchrPtrCampos[]={"Clave","Estante","Caja",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,(zSiscomRegistros *)pzProductos,QTUbicacion);
}
void QManejadorProductos4::AsignaCajaDeDescripcion()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"UbicacionDeLaDescripcion");
lzSisElectronica.UbicacionDeLaDescripcion();
}
int QManejadorProductos4::TieneUbicacion()
{
   return (*zSisRegProducto)["estante"] || 
          (*zSisRegProducto)["caja"] ;
}
int QManejadorProductos4::SinCajaOSinEstante(const char *pchrPtrCampo,
					     zSiscomRegistro *pzSisRegEstante)
{
if(pzSisRegEstante)
 return pzSisRegEstante->CampoInt(pchrPtrCampo)==-1;
 else
 return 1;
}
int QManejadorProductos4::SinEstante(zSiscomRegistro *pzSisRegEstante)
{
  return SinCajaOSinEstante("idestante",pzSisRegEstante);
}
int QManejadorProductos4::SinCaja(zSiscomRegistro *pzSisRegEstante)
{
  return SinCajaOSinEstante("idcaja",pzSisRegEstante);
}

void QManejadorProductos4::AsignandoEstante(zSiscomRegistro *pzSisRegEstante)
{
   zSisRegEstante=pzSisRegEstante;
}
void QManejadorProductos4::AsignandoCaja(zSiscomRegistro *pzSisRegCaja)
{
   zSisRegCaja=pzSisRegCaja;
}

void QManejadorProductos4::HabilitarAsignarUbicacion()
{
  if(SinEstante(zSisRegEstante) && SinCaja(zSisRegCaja))
  {
   QPBAsignarUbicacion->setEnabled(true);
   //zSiscomQt3::Foco(QPBAsignarUbicacion);
  }
  else
   if(zSisRegEstante && zSisRegCaja)
   {
   QPBAsignarUbicacion->setEnabled(true);
   //zSiscomQt3::Foco(QPBAsignarUbicacion);
   }
}
void QManejadorProductos4::SeleccionoProducto()
{
   MostrandoUbicacion();
   MuestraDescripcion();
   QCtrEstantes->setEnabled(true);
   zSiscomQt3::Foco(QCtrEstantes);
}
zSiscomRegistro *QManejadorProductos4::ProductoComoConsultaBase(zSiscomRegistro *pzSisRegProducto)
{
 zSiscomRegistro *lzSisRegProducto=new zSiscomRegistro;
 (*lzSisRegProducto) 						    <<
 new zSiscomCampo("cveproducto",(*pzSisRegProducto)["Clave"]) 	    <<
 new zSiscomCampo("dscproducto",(*pzSisRegProducto)["Descripcion"]) <<
 new zSiscomCampo("idcaja")					    <<
 new zSiscomCampo("idestante") ;
return lzSisRegProducto;
}
void QManejadorProductos4::MuestraProductoActualizado()
{
zSiscomRegistro *lzSisRegProducto;
int lintFilaAct;
lzSisRegProducto=QCtrProductos->Producto((const char *)(*zSisRegProducto)["cveproducto"]);
lintFilaAct=QTUbicacion->numRows();
if(lzSisRegProducto)
{
QTUbicacion->setNumRows(lintFilaAct+1);
QTUbicacion->setText(lintFilaAct,0,(const char *)(*lzSisRegProducto)["cveproducto"]);
QTUbicacion->setText(lintFilaAct,1,(const char *)(*lzSisRegProducto)["estante"]);
QTUbicacion->setText(lintFilaAct,2,(const char *)(*lzSisRegProducto)["caja"]);
}
zSiscomQt3::AjustaColumnasTabla(QTUbicacion);
}
