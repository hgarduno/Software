#include <IMP_EstadoInventario.h>
#include<SISCOMComunicaciones++.h>
QEstadoInventario *InstanciaEstadoInventario(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QEstadoInventario((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QEstadoInventario::QEstadoInventario(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				EstadoInventario(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QEstadoInventario::~QEstadoInventario()
{

}

void QEstadoInventario::ConectaSlots()
{


}
void QEstadoInventario::IniciaVariables()
{

}
void QEstadoInventario::closeEvent(QCloseEvent *)
{
 emit SignalTerminar(this);
 }
