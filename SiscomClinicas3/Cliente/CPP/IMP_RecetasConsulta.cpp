#include <IMP_RecetasConsulta.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlRecetas.h>

#include <qpushbutton.h>
QRecetasConsulta::QRecetasConsulta(
				    CQSisConsulta *pCQSConsulta,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RecetasConsulta(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSConsulta(pCQSConsulta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRecetasConsulta::~QRecetasConsulta()
{

}

void QRecetasConsulta::ConectaSlots()
{
	connect(QPBOFolio,
		SIGNAL(clicked()),
		SLOT(SlotOFolio()));
	connect(QCtrRecetas,
		SIGNAL(SignalRegistroReceta(QSisReceta *)),
		SLOT(SlotRegistroReceta(QSisReceta *)));
	connect(QPBTerminar,
		SIGNAL(clicked()),
		SLOT(SlotTerminar()));
}
void QRecetasConsulta::SlotTerminar()
{
	done(1);
}
void QRecetasConsulta::SlotRegistroReceta(QSisReceta *)
{
done(1);
}
void QRecetasConsulta::closeEvent(QCloseEvent *)
{

}

void QRecetasConsulta::SlotOFolio()
{
QCtrRecetas->OtroFolio();
}
void QRecetasConsulta::IniciaVariables()
{
QCtrRecetas->PonServidor(SisDatCom);
QCtrRecetas->Consulta(CQSConsulta);
QCtrRecetas->IniciaControl();
}
int QRecetasConsulta::Recetas()
{
return QCtrRecetas->Recetas();
}
