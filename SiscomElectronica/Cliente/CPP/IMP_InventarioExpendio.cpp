#include <IMP_InventarioExpendio.h>
#include <QCtrlProductosSE.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
QInventarioExpendio *InstanciaInventarioExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QInventarioExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QInventarioExpendio::QInventarioExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				InventarioExpendio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QInventarioExpendio::~QInventarioExpendio()
{

}

void QInventarioExpendio::ConectaSlots()
{


}
void QInventarioExpendio::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
}
