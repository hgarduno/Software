#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlBuscaPersonas.h>
QBuscaPersonas::QBuscaPersonas(const char *pchrPtrPersona,
				SiscomDatCom *pSisDatCom, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				BuscaPersonas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrPersona(pchrPtrPersona),
				CQSPersona(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QBuscaPersonas::~QBuscaPersonas()
{

}

void QBuscaPersonas::ConectaSlots()
{
	connect(QCtrBPersonas,
		SIGNAL(SignalPersona(CQSisEntrenador *,const char *)),
		SLOT(SlotPersona(CQSisEntrenador *,const char *)));

}
void QBuscaPersonas::SlotPersona(
			CQSisEntrenador *pCQSPersona,
			const char *)
{
	CQSPersona=pCQSPersona;
	done(1);
}
void QBuscaPersonas::IniciaVariables()
{
	QCtrBPersonas->PonServidor(SisDatCom);
	QCtrBPersonas->PonPersona(chrPtrPersona);
	QCtrBPersonas->IniciaControl();
}
CQSisEntrenador *QBuscaPersonas::ObtenPersona()
{
	return CQSPersona;
}
