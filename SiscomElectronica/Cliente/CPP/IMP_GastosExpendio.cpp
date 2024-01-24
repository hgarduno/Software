#include <IMP_GastosExpendio.h>


#include <QCtrlGastosSE.h>
#include <zOrdenes.h> 
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

QGastosExpendio *InstanciaGastosExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGastosExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGastosExpendio::QGastosExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				GastosExpendio(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QGastosExpendio::~QGastosExpendio()
{

}

void QGastosExpendio::ConectaSlots()
{


}
void QGastosExpendio::IniciaVariables()
{
QCtrGastos->Servidor(zSisConexion);
QCtrGastos->IniciaControl();
}
