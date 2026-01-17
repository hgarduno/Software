#include <IMP_ContabilidadSiscom.h>
#include <IMP_QControlFecha.h> 


QContabilidadSiscom *InstanciaContabilidadSiscom(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
        return new QContabilidadSiscom((SiscomDatCom *)pSisDatCom,
                        pchrPtrArgumentos,
                        (QWidget *)pQWParent,
                        pchrPtrName,
                        pintWFlags);
}



QContabilidadSiscom::QContabilidadSiscom(SiscomDatCom *pSisDatCom,
				         char **pchrPtrArgumentos,
					 QWidget *pQWParent,
				         const char *pchrPtrName,
					 WFlags pWFlags):
				QtContabilidadSiscom(pQWParent,pchrPtrName,pWFlags)
{
IniciaVariables();
ConectaSlots();

}

QContabilidadSiscom::~QContabilidadSiscom()
{


}


void QContabilidadSiscom::ConectaSlots()
{

}

void QContabilidadSiscom::IniciaVariables()
{

}
