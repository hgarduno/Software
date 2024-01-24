#include <IMP_SeleccionaCliente.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlClientes3Qt.h>
#include <QCtrlContactos3Qt.h>
QSeleccionaCliente::QSeleccionaCliente(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				SeleccionaCliente(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSeleccionaCliente::~QSeleccionaCliente()
{

}

void QSeleccionaCliente::ConectaSlots()
{
connect(QCtrClientes,
	SIGNAL(SignalMoral(SiscomRegistro3 *)),
	SLOT(SlotMoral(SiscomRegistro3 *)));
connect(QCtrClientes,
	SIGNAL(SignalFisica(SiscomRegistro3 *)),
	SLOT(SlotFisica(SiscomRegistro3 *)));

}
void QSeleccionaCliente::IniciaVariables()
{
QCtrClientes->Servidor(SisDatCom);
QCtrClientes->IniciaControl();
}
void QSeleccionaCliente::SlotMoral(SiscomRegistro3 *pSReg3Cliente)
{
SReg3Cliente=pSReg3Cliente;
MuestraContactos();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrContactos);
}
void QSeleccionaCliente::SlotFisica(SiscomRegistro3 *pSReg3Cliente)
{

}
void QSeleccionaCliente::MuestraContactos()
{
QCtrContactos->Servidor(SisDatCom);
QCtrContactos->PonEmpresa(SReg3Cliente);
QCtrContactos->IniciaControl();
}
