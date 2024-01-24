#include <IMP_EjecutaInventario.h>
#include<SISCOMComunicaciones++.h>
QEjecutaInventario *InstanciaEjecutaInventario(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QEjecutaInventario((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QEjecutaInventario::QEjecutaInventario(SiscomDatCom *pSisDatCom, 
				    char **pchrPtrArgumentos, QWidget
				    *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				EjecutaInventario(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QEjecutaInventario::~QEjecutaInventario()
{

}

void QEjecutaInventario::ConectaSlots()
{


}
void QEjecutaInventario::IniciaVariables()
{

}
void QEjecutaInventario::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
