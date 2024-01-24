#include <IMP_ActualizaPersonales.h>
#include <IMP_CapActPersonales.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlBuscaPersonas.h>
#include <CQSisEntrenadores.h>

QActualizaPersonales *InstanciaActualizaPersonales(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaPersonales((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaPersonales::QActualizaPersonales(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaPersonales(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaPersonales::~QActualizaPersonales()
{

}

void QActualizaPersonales::ConectaSlots()
{
	connect(QCtrBPersonas,
	       SIGNAL(SignalPersona(CQSisEntrenador *,const char *)),
	       SLOT(SlotPersona(CQSisEntrenador *,const char *)));

}
void QActualizaPersonales::SlotPersona(
				CQSisEntrenador *pCQEPersona,
				const char *pchrPtrPersona)
{
QCapActPersonales lQCAPersona(pCQEPersona,
			      SisDatCom,
			      pchrPtrPersona);
}
					
void QActualizaPersonales::IniciaVariables()
{
	QCtrBPersonas->PonServidor(SisDatCom);
	QCtrBPersonas->IniciaControl();
	QCtrBPersonas->HabilitaGimnasta(true);
	QCtrBPersonas->HabilitaEntrenador(true);
}
