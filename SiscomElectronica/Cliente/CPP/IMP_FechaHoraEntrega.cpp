#include <IMP_FechaHoraEntrega.h>
#include<SiscomDesarrollo3Qt++.h>
QFechaHoraEntrega::QFechaHoraEntrega(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				FechaHoraEntrega(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QFechaHoraEntrega::~QFechaHoraEntrega()
{

}

void QFechaHoraEntrega::ConectaSlots()
{


}
void QFechaHoraEntrega::IniciaVariables()
{

}
