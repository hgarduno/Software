#include <IMP_SincronizaExpendio.h>

#include <zListaExpendios.h>


#include <qpushbutton.h>
#include <zSiscomElectronica.h>

#include <zSiscomDesarrollo4.h>
QSincronizaExpendio *InstanciaSincronizaExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QSincronizaExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QSincronizaExpendio::QSincronizaExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtSincronizaExpendio(pSisDatCom,
						     pchrPtrArgumentos,
						     pQWParent,
						     pchrPtrName,
						     pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
}

QSincronizaExpendio::~QSincronizaExpendio()
{

}

void QSincronizaExpendio::SincronizaProductos(zListaExpendios *pzLstExpendios)
{
zSiscomElectronica lzSisEleSProExpendio(zSisConexion,"SincronizaProductosExpendio");
lzSisEleSProExpendio.SincronizaProductosExpendio(pzLstExpendios);
}
void QSincronizaExpendio::SincronizaPrecios()
{
zSiscomElectronica lzSisEleSPreciosExpendio(zSisConexion,"SincronizaPreciosExpendio");
lzSisEleSPreciosExpendio.SincronizaPreciosExpendio(Expendios());
}
