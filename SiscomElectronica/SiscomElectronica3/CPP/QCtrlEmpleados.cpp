
#include <QCtrlEmpleados.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomDatCom.h>
#include <qlayout.h>
#include <qiconview.h>

QCtrlEmpleados::QCtrlEmpleados(
				QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
gPtrFleArchivoLog3Qt=stdout;
IniciaVariables();
ConectaSlots();

}
void QCtrlEmpleados::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QIVEmpleados=new QIconView(this);
QHBLayout->addWidget(QIVEmpleados);
}
void QCtrlEmpleados::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlEmpleados::Expendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlEmpleados::IniciaControl()
{
	ConsultaEmpleados();
	MuestraEmpleados();
}
void QCtrlEmpleados::ConectaSlots()
{
connect(QIVEmpleados,
	SIGNAL(clicked(QIconViewItem *)),
	SLOT(SlotEmpleado(QIconViewItem *)));
}

void QCtrlEmpleados::SlotEmpleado(QIconViewItem *pQIVIEmpleado)
{
QIconViewItemEmpleado *lQIVIEmpleado=(QIconViewItemEmpleado *)pQIVIEmpleado;
emit SignalEmpleado(lQIVIEmpleado->Empleado());
}
void QCtrlEmpleados::ConsultaEmpleados()
{
SiscomOperaciones3 lSOp3Empleados(SisDatCom);
lSOp3Empleados.SiscomEnvia("ConsultasSiscomElectronica2",
			   &SReg3LstEmpleados,
			   "%s%s",
			   "EmpleadosSiscom",
			   chrPtrIdExpendio);
}
void QCtrlEmpleados::MuestraEmpleados()
{
SiscomRegistro3 *lSReg3Empleado;
QIconViewItemEmpleado *lQIVIEmpleado;
for(lSReg3Empleado=SReg3LstEmpleados.first();
    lSReg3Empleado;
    lSReg3Empleado=SReg3LstEmpleados.next())
{
   lQIVIEmpleado=new QIconViewItemEmpleado(lSReg3Empleado,QIVEmpleados);
   QIVEmpleados->insertItem(lQIVIEmpleado);
}
}


QIconViewItemEmpleado::QIconViewItemEmpleado(SiscomRegistro3 *pSReg3Empleado,
					     QIconView *pQIVControl):
			QIconViewItem(pQIVControl),
			SReg3Empleado(pSReg3Empleado)
{
	setText(QString((*SReg3Empleado)["nombre"])	+
			" "				+
			(*SReg3Empleado)["apaterno"]	+
			" "				+
			(*SReg3Empleado)["amaterno"]);
}
SiscomRegistro3 *QIconViewItemEmpleado::Empleado()
{
	return SReg3Empleado;
}
