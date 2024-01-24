#include <IMP_ManejadorPracticas.h>
#include <IMP_SeleccionandoProducto.h>
#include <QCtrlProductosSE.h>
#include <QCtrlEscuelasSE.h>
#include <zSiscomElectronica.h>
#include <zPractica.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>


#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QManejadorPracticas *InstanciaManejadorPracticas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManejadorPracticas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManejadorPracticas::QManejadorPracticas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorPracticas(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QManejadorPracticas::~QManejadorPracticas()
{

}

void QManejadorPracticas::ConectaSlots()
{
connect(QPBSeleccionaPractica,SIGNAL(clicked()),SLOT(SlotSeleccionaPractica()));
connect(QLENombrePractica,SIGNAL(returnPressed()),SLOT(SlotFocoAMateria()));
connect(QLEMateria,SIGNAL(returnPressed()),SLOT(SlotFocoAEscuelas()));


connect(QPBRegistraPractica,SIGNAL(clicked()),SLOT(SlotRegistraPractica()));
connect(QCtrEscuelas,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotEscuela(zSiscomRegistro *)));
}
void QManejadorPracticas::SlotEscuela(zSiscomRegistro *pzSisRegEscuela)
{
	zSisRegEscuela=pzSisRegEscuela;
	zSiscomQt3::Foco(QPBRegistraPractica);
}
void QManejadorPracticas::SlotFocoAEscuelas()
{
	zSiscomQt3::Foco(QCtrEscuelas);
}
void QManejadorPracticas::SlotFocoAMateria()
{
	zSiscomQt3::Foco(QLEMateria);
}
void QManejadorPracticas::SlotSeleccionaPractica()
{
  SeleccionandoPractica();
  zSiscomQt3::Foco(QLENombrePractica);
}

void QManejadorPracticas::SlotRegistraPractica()
{
  RegistrandoPractica();
}
void QManejadorPracticas::IniciaVariables()
{
QCtrEscuelas->Servidor(zSisConexion);
QCtrProductos->Servidor(zSisConexion);
QCtrEscuelas->IniciaControl();
QCtrProductos->IniciaControl();
HabilitaDesHabilita(false);
}

void QManejadorPracticas::SeleccionandoPractica()
{
QSeleccionandoProducto lQSelProductos;
if(lQSelProductos.Aceptar())
{
  zSisRegProducto=lQSelProductos.Producto();
  if(EstaPracticaRegistrada())
  MostrandoPractica();
  DatosPractica();
  DatosProfesor();
}
}
void QManejadorPracticas::MostrandoPractica()
{
   MuestraPractica(zSisRegProducto);
   MuestraProductos();

}
void QManejadorPracticas::MuestraPractica(zSiscomRegistro *pzSisRegPractica)
{
  QLECvePractica->setText((const char *)(*pzSisRegPractica)["cveproducto"]);
  QTEDescripcion->setText((const char *)(*pzSisRegPractica)["dscproducto"]);
}
void QManejadorPracticas::RegistraPractica()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraPractica");
lzSisElectronica.RegistraPractica(Practica());
}
void QManejadorPracticas::RegistrandoPractica()
{
  RegistraPractica();
}
zPractica *QManejadorPracticas::Practica()
{
zPractica *lzPractica;
lzPractica=new zPractica;
lzPractica->Producto(zSisRegProducto);
lzPractica->Nombre(zSiscomQt3::Texto(QLENombrePractica));
lzPractica->Materia(zSiscomQt3::Texto(QLEMateria));
lzPractica->Escuela(zSisRegEscuela);
return lzPractica;
}

void QManejadorPracticas::HabilitaDesHabilita(bool pbEstado)
{
QLECvePractica->setEnabled(pbEstado);
QLENombrePractica->setEnabled(pbEstado);
QLEMateria->setEnabled(pbEstado);
QCtrEscuelas->setEnabled(pbEstado);
QLENombre->setEnabled(pbEstado);
QLEAPaterno->setEnabled(pbEstado);
QLEAMaterno->setEnabled(pbEstado);
QTEDescripcion->setEnabled(pbEstado);
QTEObservaciones->setEnabled(pbEstado);
QCtrProductos->setEnabled(false);
QPBRegistraPractica->setEnabled(false);
}
int QManejadorPracticas::EstaPracticaRegistrada()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"PracticaRegistrada");
return lzSisElectronica.Practica(zSisRegProducto,&zPraPractica);
}
void QManejadorPracticas::MuestraProductos()
{
const char *lchrPtrProducto[]={"cveproducto","cantidad",0};
zSiscomQt3::LlenaTabla(lchrPtrProducto,zPraPractica.Productos(),QTProductos);
}
void QManejadorPracticas::HabilitaDesHabilitaDatosPractica(bool pbEstado)
{
QLENombrePractica->setEnabled(pbEstado);
QLEMateria->setEnabled(pbEstado);
}
void QManejadorPracticas::HabilitaDesHabilitaDatosProfesor(bool pbEstado)
{
QLENombre->setEnabled(pbEstado);
QLEAPaterno->setEnabled(pbEstado);
QLEAMaterno->setEnabled(pbEstado);
}
void QManejadorPracticas::DatosPractica()
{
    HabilitaDesHabilitaDatosPractica(!zPraPractica.DatosPractica());
}
void QManejadorPracticas::DatosProfesor()
{
   HabilitaDesHabilitaDatosProfesor(!zPraPractica.DatosProfesor());
}
