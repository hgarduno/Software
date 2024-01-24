#include <IMP_ActualizaPesosPPunto.h>
#include <SiscomDesarrollo3Qt++.h>
QActualizaPesosPPunto *InstanciaActualizaPesosPPunto(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaPesosPPunto((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaPesosPPunto::QActualizaPesosPPunto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaPesosPPunto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaPesosPPunto::~QActualizaPesosPPunto()
{

}

void QActualizaPesosPPunto::ConectaSlots()
{


}
void QActualizaPesosPPunto::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEPesosPPuntoM);
}
