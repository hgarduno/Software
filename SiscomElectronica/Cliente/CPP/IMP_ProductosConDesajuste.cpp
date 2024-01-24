#include <IMP_ProductosConDesajuste.h>
#include<SISCOMComunicaciones++.h>
QProductosConDesajuste::QProductosConDesajuste(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductosConDesajuste(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QProductosConDesajuste::~QProductosConDesajuste()
{

}

void QProductosConDesajuste::ConectaSlots()
{


}
void QProductosConDesajuste::IniciaVariables()
{

}
