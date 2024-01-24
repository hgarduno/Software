#include <IMP_ExpendioOrigen.h>
#include<SISCOMComunicaciones++.h>
QExpendioOrigen::QExpendioOrigen(SiscomDatCom *pSisDatCom,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QtExpendioOrigen(pSisDatCom,
						 pchrPtrArgumentos,
						 pQWParent,
						 pchrPtrName,
						 pbModal,
						 pWFlags)
{
}

QExpendioOrigen::~QExpendioOrigen()
{

}

