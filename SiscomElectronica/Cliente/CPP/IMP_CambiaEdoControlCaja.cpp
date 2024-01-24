#include <IMP_CambiaEdoControlCaja.h>
#include<SISCOMComunicaciones++.h>
#include <QtSeguridadCajas.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

QCambiaEdoControlCaja::QCambiaEdoControlCaja(
				    QtListViewItemEstadoControl *pQtLstViewItemEdoControl,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CambiaEdoControlCaja(pQWParent,
						     pchrPtrName,
						     pbModal,
						     pWFlags),
				QtLstViewItemEdoControl(pQtLstViewItemEdoControl)
{
IniciaVariables();
ConectaSlots();
MuestraDatosControl();
exec();
}

QCambiaEdoControlCaja::~QCambiaEdoControlCaja()
{

}

void QCambiaEdoControlCaja::ConectaSlots()
{

	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QGBEstados,
		SIGNAL(clicked(int)),
		SLOT(SlotEstado(int)));
}
void QCambiaEdoControlCaja::SlotEstado(int pintEstado)
{
  AsignaEstadoControl(pintEstado);
}
void QCambiaEdoControlCaja::SlotAceptar()
{
	intOpcion=1;
	done(1);
}
void QCambiaEdoControlCaja::SlotCancelar()
{
	intOpcion=0;
	SiscomEscribeLog3Qt("El Estado inicial:%s",
			 chrPtrEstadoInicial);
	AsignaEstadoControl(chrPtrEstadoInicial);
	done(1);
}
void QCambiaEdoControlCaja::IniciaVariables()
{
	ObtenEstadoInicial();
}
void QCambiaEdoControlCaja::MuestraDatosControl()
{
QtListViewItemControlCaja *lQtLstViewItemControlCaja;
lQtLstViewItemControlCaja=(QtListViewItemControlCaja *)QtLstViewItemEdoControl->parent();
if(lQtLstViewItemControlCaja)
{
SiscomRegistro3 *lSisReg3Control;
	lSisReg3Control=lQtLstViewItemControlCaja->ControlCaja();
	QGBEstados->setTitle((*lSisReg3Control)["nombreqt"]);
	if(((*lSisReg3Control)["estado"])[0]=='0')
	QRBDesHabilitado->setChecked(true);
	if(((*lSisReg3Control)["estado"])[0]=='1')
	QRBHabilitado->setChecked(true);
}

}

void QCambiaEdoControlCaja::AsignaEstadoControl(int pintEdoControl)
{
SiscomRegistro3 *lSisReg3EdoControl;
const char *lchrPtrEstado=pintEdoControl ? "0" : "1";
lSisReg3EdoControl=QtLstViewItemEdoControl->Control();
if(lSisReg3EdoControl)
{
   lSisReg3EdoControl->SiscomActualizaCampo("estado",lchrPtrEstado);
   QtLstViewItemEdoControl->setText(0,lchrPtrEstado);
}
}
void QCambiaEdoControlCaja::AsignaEstadoControl(const char *pchrPtrEdoControl)
{
SiscomRegistro3 *lSisReg3EdoControl;
lSisReg3EdoControl=QtLstViewItemEdoControl->Control();
if(lSisReg3EdoControl)
{
   lSisReg3EdoControl->SiscomActualizaCampo("estado",pchrPtrEdoControl);
   QtLstViewItemEdoControl->setText(0,pchrPtrEdoControl);
   SiscomEscribeLog3Qt("Estado:%s",pchrPtrEdoControl);
}
}
int QCambiaEdoControlCaja::Opcion()
{
	return intOpcion;
}
void QCambiaEdoControlCaja::closeEvent(QCloseEvent *)
{

}
void QCambiaEdoControlCaja::ObtenEstadoInicial()
{
SiscomRegistro3 *lSisReg3EdoControl;
lSisReg3EdoControl=QtLstViewItemEdoControl->Control();
chrPtrEstadoInicial=(*lSisReg3EdoControl)["estado"];
SiscomEscribeLog3Qt("El Estado inicial:%s",chrPtrEstadoInicial);
}
