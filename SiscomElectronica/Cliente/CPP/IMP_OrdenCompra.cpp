#include <IMP_OrdenCompra.h>
#include<SISCOMComunicaciones++.h>
QOrdenCompra *InstanciaOrdenCompra(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenCompra((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenCompra::QOrdenCompra(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenCompra(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QOrdenCompra::~QOrdenCompra()
{

}

void QOrdenCompra::ConectaSlots()
{


}
void QOrdenCompra::IniciaVariables()
{

}
void QOrdenCompra::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
	}
