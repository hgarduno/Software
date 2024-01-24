#include <IMP_TransferenciaExpendioAExpendio.h>
#include <IMP_CapturaDato.h>
#include <QCtrlExpendios.h>
#include <QCtrlProductosSE.h>

#include <zProductoTransferir.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>

QTransferenciaExpendioAExpendio *InstanciaTransferenciaExpendioAExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QTransferenciaExpendioAExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QTransferenciaExpendioAExpendio::QTransferenciaExpendioAExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TransferenciaExpendioAExpendio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				SisReg3ExpendioO(0),
				SisReg3ExpendioD(0)

{
IniciaVariables();
ConectaSlots();
}

QTransferenciaExpendioAExpendio::~QTransferenciaExpendioAExpendio()
{

}

void QTransferenciaExpendioAExpendio::ConectaSlots()
{
connect(QCtrExpendiosO,
	SIGNAL(SignalExpendio(SiscomRegistro3 *)),
	SLOT(SlotExpendioO(SiscomRegistro3 *)));

connect(QCtrExpendiosD,
	SIGNAL(SignalExpendio(SiscomRegistro3 *)),
	SLOT(SlotExpendioD(SiscomRegistro3 *)));
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexar()));
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturoCantidad()));
connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistrar()));
connect(QTDatos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));
connect(QPBEliminar,SIGNAL(clicked()),SLOT(SlotEliminaProducto()));
	
}
void QTransferenciaExpendioAExpendio::SlotEliminaProducto()
{
int lintProductos;
 for(lintProductos=0;
     lintProductos<QTDatos->numRows();
     lintProductos++)
 {
     if(QTDatos->isRowSelected(lintProductos))
     zProdsTransferir.EliminaProducto(lintProductos);
 }
 MuestraProductosTransferir();
}
void QTransferenciaExpendioAExpendio::SlotSeleccionaProducto(int pintNProducto,
							     int pintNColumna,
							     int,
							     const QPoint &)
{
  QTDatos->selectRow(pintNProducto); 
  if(pintNColumna==1)
  {
  CambiaCantidad(pintNProducto);
  MuestraProductosTransferir();
  }
}
void QTransferenciaExpendioAExpendio::SlotRegistrar()
{
  EnviandoTransferencia();
  LiberaDespuesRegistro();
}
void QTransferenciaExpendioAExpendio::SlotAnexar()
{
    AnexarProductoTransferencia();
    MuestraProductosTransferir();
    QPBRegistrar->setEnabled(zProdsTransferir.NNodos());
    zSiscomQt3::Foco(QCtrProductos);
    QPBAnexar->setEnabled(false);
}
void QTransferenciaExpendioAExpendio::SlotCapturoCantidad()
{
      ValidandoDatosTransferencia();    
}
void QTransferenciaExpendioAExpendio::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
       zSisRegProducto=pzSisRegProducto;
       AnalizandoExistencia();
}
void QTransferenciaExpendioAExpendio::SlotExpendioO(SiscomRegistro3 *pSisReg3ExpOrigen)
{
   SisReg3ExpendioO=pSisReg3ExpOrigen;
   HabilitaDesHabilitaProductos();
   zSiscomQt3::Foco(QCtrExpendiosD);
}
void QTransferenciaExpendioAExpendio::SlotExpendioD(SiscomRegistro3 *pSisReg3ExpDestino)
{
   SisReg3ExpendioD=pSisReg3ExpDestino;
   HabilitaDesHabilitaProductos();
   zSiscomQt3::Foco(QCtrProductos);
}

void QTransferenciaExpendioAExpendio::IniciaVariables()
{
QCtrExpendiosO->Servidor(SisDatCom);
QCtrExpendiosD->Servidor(SisDatCom);
QCtrExpendiosO->Expendio(chrPtrArgumentos[0]);
QCtrExpendiosD->Expendio(chrPtrArgumentos[0]);
QCtrExpendiosO->IniciaControl();
QCtrExpendiosD->IniciaControl();
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
setCaption("Transferencia Expendio a Expendio");
}
void QTransferenciaExpendioAExpendio::HabilitaDesHabilitaProductos()
{
QCtrProductos->setEnabled(SisReg3ExpendioO &&
			  SisReg3ExpendioD );
}
int QTransferenciaExpendioAExpendio::ConsultaExistenciaExpendioDestinoOrigen()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ExistenciaExpendioOrigenDestino");
return lzSisElectronica.ExistenciaExpendioOrigenDestino(
				(*SisReg3ExpendioO)["idempresa"],
				(*SisReg3ExpendioD)["idempresa"],
				zSisRegProducto,
				&zSisRegExiExpOrigenDestino);
}
void QTransferenciaExpendioAExpendio::MuestraConsultaExistenciaExpendioDestinoOrigen()
{
QLEExistenciaOrigen->setText((const char *)(*zSisRegExiExpOrigenDestino)["ExistenciaOrigen"]);
QLEExistenciaDestino->setText((const char *)(*zSisRegExiExpOrigenDestino)["ExistenciaDestino"]);
}
int QTransferenciaExpendioAExpendio::ConsultandoExistenciaExpendioDestinoOrigen()
{
int lintRegreso;
   lintRegreso=ConsultaExistenciaExpendioDestinoOrigen();
   MuestraConsultaExistenciaExpendioDestinoOrigen();
   return lintRegreso;
}
void QTransferenciaExpendioAExpendio::AnalizandoExistencia()
{
       if(ConsultandoExistenciaExpendioDestinoOrigen()<0)
       ExpendioSinConexion();
       else
       {
       	  QCtrExpendiosO->setEnabled(false);
	  QCtrExpendiosD->setEnabled(false);
       	  QLECantidad->setEnabled(true);
	  zSiscomQt3::Foco(QLECantidad);

       }
}
int QTransferenciaExpendioAExpendio::SePuedeTransferirLaCantidad()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidandoTransferenciaExpendioOrigen");
zSisRegExiExpOrigenDestino->ActualizaCampo("Cantidad",(const unsigned char *)zSiscomQt3::Texto(QLECantidad));
return lzSisElectronica.ValidandoTransferenciaExpendioOrigen(zSisRegExiExpOrigenDestino);
}

void QTransferenciaExpendioAExpendio::ValidandoDatosTransferencia()
{
if(SePuedeTransferirLaCantidad())
{
    zSiscomQt3::HabilitaPasaFoco(QPBAnexar);
}
else
{
    QPBAnexar->setEnabled(false);
    zSiscomQt3::Foco(QLECantidad);
}

}
void QTransferenciaExpendioAExpendio::AnexarProductoTransferencia()
{
zProductoTransferir *lzProdTransferir;
 	lzProdTransferir=new zProductoTransferir;
	lzProdTransferir->Clave((const char *)(*zSisRegProducto)["cveproducto"]);
	lzProdTransferir->Cantidad(zSiscomQt3::Texto(QLECantidad));
 	zProdsTransferir.Agrega(lzProdTransferir);
}
void QTransferenciaExpendioAExpendio::MuestraProductosTransferir()
{
const char *lchrPtrCampos[]={"Clave","Cantidad",0};
zSiscomRegistros *lzSisRegsProductos;
if((lzSisRegsProductos=zProdsTransferir.Productos()))
{
zSiscomQt3::LlenaTabla(lchrPtrCampos,lzSisRegsProductos,QTDatos);
zSiscomQt3::AjustaColumnasTabla(QTDatos);
}
}
void QTransferenciaExpendioAExpendio::AgregaDatosTransferencia()
{
  zProdsTransferir.ExpendioO((*SisReg3ExpendioO)["idempresa"]);
  zProdsTransferir.ExpendioD((*SisReg3ExpendioD)["idempresa"]);
  zProdsTransferir.IdEmpleado(chrPtrArgumentos[1]);
}
void QTransferenciaExpendioAExpendio::EnviandoTransferencia()
{
	AgregaDatosTransferencia();
	EnviaTransferencia();
}
void QTransferenciaExpendioAExpendio::EnviaTransferencia()
{
   zSiscomElectronica lzSisElectronica(zSisConexion,"TransfiereExpendioAExpendio"); 
   lzSisElectronica.TransfiereProductosExpendioExpendio(&zProdsTransferir);
}
void QTransferenciaExpendioAExpendio::CambiaCantidad(int pintNProducto)
{
char lchrArrCantidad[28];
QCapturaDato lQCDato("Cambia Cantidad","Cantidad");
lQCDato.ObtenDato(lchrArrCantidad);
zProdsTransferir.Cantidad(pintNProducto,lchrArrCantidad);
}
void QTransferenciaExpendioAExpendio::LiberaDespuesRegistro()
{
  zProdsTransferir.Productos()->Libera(); 
  QTDatos->setNumRows(0);
  QCtrExpendiosO->setEnabled(true);
  QCtrExpendiosD->setEnabled(true);
}
void QTransferenciaExpendioAExpendio::ExpendioSinConexion()
{
 QMessageBox::information(this,
 			  "Aviso Sistema",
			  (const char *)(*zSisRegExiExpOrigenDestino)["Error"]);

}
