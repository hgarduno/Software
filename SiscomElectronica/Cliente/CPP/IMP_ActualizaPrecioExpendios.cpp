#include <IMP_ActualizaPrecioExpendios.h>

#include <zSiscomDesarrollo4.h>
#include <zPrecio.h>
#include <zProductoPrecio.h>
#include <zPrecios.h>
#include <zProductoPrecioExpendios.h>
#include <zSiscomElectronica.h>
QActualizaPrecioExpendios *InstanciaActualizaPrecioExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaPrecioExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaPrecioExpendios::QActualizaPrecioExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtActualizaPrecioExpendios(pSisDatCom,pchrPtrArgumentos,pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
			 	chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{


}


void QActualizaPrecioExpendios::Actualizando()
{
zProductoPrecioExpendios lzPPrecioExs(Clave()); 
zPrecio *lzPrecio=TipoPrecioSeleccionado();
lzPrecio->Precio(PrecioNuevo());
zPrecios lzPrecios; 
lzPrecios << lzPrecio;
lzPPrecioExs.Precios(&lzPrecios);
lzPPrecioExs.Expendios(Expendios());
EjecutaActualizacion(&lzPPrecioExs);
}
void QActualizaPrecioExpendios::EjecutaActualizacion(zProductoPrecioExpendios *pzPPrecioExs)
{
zSiscomElectronica lzSisEleAPPExs(zSisConexion,"ActualizaPrecioExpendios");
lzSisEleAPPExs.ActualizaPrecioExpendios(pzPPrecioExs);
}

QActualizaPrecioExpendios::~QActualizaPrecioExpendios()
{

}
