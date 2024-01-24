#include <IMP_CapturaDireccion.h>
#include <CQSisEntrenadores.h>
#include <QSisSepomex.h>
#include<SISCOMComunicaciones++.h>

QCapturaDireccion::QCapturaDireccion(SiscomDatCom *pSisDatCom, 
				    CQSisEntrenador *pCQSEPersona,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaDireccion(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				CQSEPersona(pCQSEPersona)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaDireccion::~QCapturaDireccion()
{

}

void QCapturaDireccion::ConectaSlots()
{


}
void QCapturaDireccion::IniciaVariables()
{

	QCtrDireccion->PonServidor(SisDatCom);
	QCtrDireccion->IniciaControl();
}
