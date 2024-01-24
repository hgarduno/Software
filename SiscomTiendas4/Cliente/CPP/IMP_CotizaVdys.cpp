#include <IMP_CotizaVdys.h>
#include <IMP_SeleccionaCliente.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>


#include <qpushbutton.h>
QCotizaVdys *InstanciaCotizaVdys(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCotizaVdys((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCotizaVdys::QCotizaVdys(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CotizaVdys(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QCotizaVdys::~QCotizaVdys()
{

}

void QCotizaVdys::ConectaSlots()
{
connect(QPBSCliente,
	SIGNAL(clicked()),
	SLOT(SlotSCliente()));

}
void QCotizaVdys::SlotSCliente()
{
SiscomEscribeLog3Qt("");
QSeleccionaCliente lQSCliente(SisDatCom,chrPtrArgumentos);
			
}
void QCotizaVdys::IniciaVariables()
{

}
