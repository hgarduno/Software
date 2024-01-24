
#include <QCtrlEstadisticaMedicos.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisEstadisticaMedicos.h>
#include <qlayout.h>


QCtrlEstadisticaMedicos::QCtrlEstadisticaMedicos( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlEstadisticaMedicos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	/*
	QIVEstadisticaMedicos=new QIconView(this);
	QHBLayout->addWidget(QIVEstadisticaMedicos);

	*/
}
void QCtrlEstadisticaMedicos::MuestraEstadisticaMedicos()
{
}
void QCtrlEstadisticaMedicos::IniciaControl()
{
	ConsultaEstadisticaMedicos();
	MuestraEstadisticaMedicos();
}
void QCtrlEstadisticaMedicos::ConsultaEstadisticaMedicos()
{

}
void QCtrlEstadisticaMedicos::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlEstadisticaMedicos::Medico(CQSisPersona *pCQSMedico)
{
	CQSMedico=pCQSMedico;
}
void QCtrlEstadisticaMedicos::ConectaSlots()
{

}
void QCtrlEstadisticaMedicos::setFocus()
{
	
}
void QCtrlEstadisticaMedicos::LimpiaSeleccion()
{
}
void QCtrlEstadisticaMedicos::Limpia()
{
}
