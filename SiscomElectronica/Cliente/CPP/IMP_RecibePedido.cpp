#include <IMP_RecibePedido.h>
#include <IMP_CapturaDato.h>
#include <IMP_QControlFecha.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QRecibePedido *InstanciaRecibePedido(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRecibePedido((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRecibePedido::QRecibePedido(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RecibePedido(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRecibePedido::~QRecibePedido()
{

}

void QRecibePedido::ConectaSlots()
{
}
void QRecibePedido::IniciaVariables()
{

}
