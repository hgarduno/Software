#include <IMP_SueldosEmpleados.h>
#include <IMP_CapturaSueldo.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisSueldos.h>
#include <QCtrlEmpleados.h>
#include <SiscomDatCom.h>
#include <SiscomRegistros3.h>

#include <qlineedit.h>
#include <qpushbutton.h>
QSueldosEmpleados *InstanciaSueldosEmpleados(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QSueldosEmpleados((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QSueldosEmpleados::QSueldosEmpleados(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				SueldosEmpleados(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QSueldosEmpleados::~QSueldosEmpleados()
{

}

void QSueldosEmpleados::ConectaSlots()
{
connect(QPBCambia,
	SIGNAL(clicked()),
	SLOT(SlotCambia()));
connect(QCtrEmpleados,
	SIGNAL(SignalEmpleado(SiscomRegistro3 *)),
	SLOT(SlotEmpleado(SiscomRegistro3 *)));

}
void QSueldosEmpleados::SlotEmpleado(SiscomRegistro3 *pSReg3Empleado)
{
	SReg3Empleado=pSReg3Empleado;
}
void QSueldosEmpleados::SlotCambia()
{
QCapturaSueldo lQCSueldo(SReg3Empleado);
(this->*CambiaSueldo[lQCSueldo.Opcion()])(lQCSueldo.Sueldo());
}
void QSueldosEmpleados::IniciaVariables()
{
QCtrEmpleados->Servidor(SisDatCom);
QCtrEmpleados->Expendio(chrPtrArgumentos[0]);
QCtrEmpleados->IniciaControl();
CambiaSueldo[0]=&QSueldosEmpleados::Cancela;
CambiaSueldo[1]=&QSueldosEmpleados::Registra;
}
void QSueldosEmpleados::Cancela(CQSisSueldo *)
{
SiscomEscribeLog3Qt("");
}
void QSueldosEmpleados::Registra(CQSisSueldo *pCQSSueldo)
{
CQSis3QtOperaciones lCQS3QtOperacion(SisDatCom);
lCQS3QtOperacion.RegistraSueldo(pCQSSueldo);
}
void QSueldosEmpleados::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
