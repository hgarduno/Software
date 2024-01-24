#include <IMP_DispositivosVendidos.h>
#include<SiscomDesarrollo3Qt++.h>
QDispositivosVendidos *InstanciaDispositivosVendidos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QDispositivosVendidos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QDispositivosVendidos::QDispositivosVendidos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				DispositivosVendidos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QDispositivosVendidos::~QDispositivosVendidos()
{

}

void QDispositivosVendidos::ConectaSlots()
{


}
void QDispositivosVendidos::IniciaVariables()
{

}
