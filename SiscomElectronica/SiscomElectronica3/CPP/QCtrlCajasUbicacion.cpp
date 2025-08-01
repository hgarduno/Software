#include <QCtrlCajasUbicacion.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>

#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

QCtrlCajasUbicacion::QCtrlCajasUbicacion(QWidget *pQWParent,
		     const char *pchrPtrName):
		     QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlCajasUbicacion::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBCajasUbicacion=new QComboBox(this);
QHBLayout->addWidget(QCBCajasUbicacion);
QLERFC=zSiscomQt3::EditAlCombo(QCBCajasUbicacion,"QLERFC");
QCBCajasUbicacion->setAutoCompletion(true);
QCBCajasUbicacion->setDuplicatesEnabled(false);
QCBCajasUbicacion->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlCajasUbicacion::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlCajasUbicacion::IniciaControl()
{
   Consultando();
}
void QCtrlCajasUbicacion::ConectaSlots()
{
connect(QCBCajasUbicacion,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBCajasUbicacion,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
}
void QCtrlCajasUbicacion::SlotCapturoRfc()
{
 LogSiscom("");
}
void QCtrlCajasUbicacion::SlotCambioRFC(const QString &pQStrRFC)
{

}
void QCtrlCajasUbicacion::SlotSeleccionoRFC()
{
   LogSiscom("El RFC Seleccionado %d",
   	      QCBCajasUbicacion->currentItem());
}
void QCtrlCajasUbicacion::SlotSelecciono(int pintNProducto)
{
 if(pintNProducto!=-1)
 emit SignalSelecciono((*zSisRegsCajasUbicacion)[pintNProducto]);
}
void QCtrlCajasUbicacion::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsCajasUbicacion)[pintNProducto]);
}
void QCtrlCajasUbicacion::ConsultaCajasUbicacion()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CajasMaterial");
zSisRegsCajasUbicacion=lzSisElectronica.CajasMaterial(); 
}
void QCtrlCajasUbicacion::MuestraCajasUbicacion()
{
zSiscomQt3::RegistrosAlCombo(QCBCajasUbicacion,"caja",zSisRegsCajasUbicacion);
}
QLineEdit *QCtrlCajasUbicacion::RFC()
{
	return QLERFC;
}
void QCtrlCajasUbicacion::setFocus()
{
zSiscomQt3::Foco(QLERFC);
}
void QCtrlCajasUbicacion::Consultando()
{
 ConsultaCajasUbicacion();
 MuestraCajasUbicacion();
}
void QCtrlCajasUbicacion::IdEscuela(const char *pchrPtrIdEscuela)
{
    chrPtrIdEscuela=pchrPtrIdEscuela;
}
void QCtrlCajasUbicacion::ReConsultando()
{
 QCBCajasUbicacion->clear();
 Consultando();
}
