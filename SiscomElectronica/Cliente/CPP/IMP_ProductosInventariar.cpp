#include <IMP_ProductosInventariar.h>
#include<SISCOMComunicaciones++.h>
QProductosInventariar *InstanciaProductosInventariar(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProductosInventariar((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProductosInventariar::QProductosInventariar(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductosInventariar(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProductosInventariar::~QProductosInventariar()
{

}

void QProductosInventariar::ConectaSlots()
{


}
void QProductosInventariar::IniciaVariables()
{

}
void QProductosInventariar::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
