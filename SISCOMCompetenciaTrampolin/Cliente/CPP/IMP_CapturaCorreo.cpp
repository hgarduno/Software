#include <IMP_CapturaCorreo.h>
#include <CQSisEntrenadores.h>
#include<SISCOMComunicaciones++.h>

QCapturaCorreo::QCapturaCorreo(SiscomDatCom *pSisDatCom, 
				CQSisEntrenador *pCQSEPersona,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaCorreo(pQWParent,
						pchrPtrName,
						pbModal,
						pWFlags),
				SisDatCom(pSisDatCom),
				CQSEPersona(pCQSEPersona)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaCorreo::~QCapturaCorreo()
{

}

void QCapturaCorreo::ConectaSlots()
{


}
void QCapturaCorreo::IniciaVariables()
{

}
