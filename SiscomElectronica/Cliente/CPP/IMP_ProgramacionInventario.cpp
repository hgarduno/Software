#include <IMP_ProgramacionInventario.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlMotivoInventario.h>

#include <CQSisProgramacionInventario.h>


#include <qtextedit.h>
#include <qpushbutton.h>
QProgramacionInventario *InstanciaProgramacionInventario(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProgramacionInventario((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProgramacionInventario::QProgramacionInventario(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProgramacionInventario(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProgramacionInventario::~QProgramacionInventario()
{

}
void QProgramacionInventario::SlotMotivoInventario(SiscomRegistro3 *pSisReg3Motivo)
{
	SisReg3Motivo=pSisReg3Motivo;
	SiscomDesarrollo3Qt::PasaFocoControl(QTEDescripcion);
}
void QProgramacionInventario::SlotRegistra()
{
	EnviaRegistro();
	InformaEdoRegistro();
}
void QProgramacionInventario::ConectaSlots()
{
	connect(QCtrMotivoInventario,
		SIGNAL(SignalMotivoInventario(SiscomRegistro3 *)),
		SLOT(SlotMotivoInventario(SiscomRegistro3 *)));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QProgramacionInventario::IniciaVariables()
{
QCtrMotivoInventario->Servidor(SisDatCom);
QCtrMotivoInventario->IdExpendio(chrPtrArgumentos[0]);
QCtrMotivoInventario->IniciaControl();
}
void QProgramacionInventario::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}

void QProgramacionInventario::EnviaRegistro()
{
CQSisOpProgramacionInventario lCQSOpProgInventario(SisDatCom);
CQSProgInventario=new CQSisProgramacionInventario(
				(SiscomRegistro3 *)chrPtrArgumentos[5],
				SisReg3Motivo,
				SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTEDescripcion));
lCQSOpProgInventario.Registra(CQSProgInventario);
}
void QProgramacionInventario::InformaEdoRegistro()
{

}
