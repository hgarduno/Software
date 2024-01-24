#include <zTransfiereBodegaBodega.h>
#include <zBodega.h>

#include <zSiscomCampo.h>
zTransfiereBodegaBodega::zTransfiereBodegaBodega()
{
 (*this)			<< 
 new zSiscomCampo("BodegaO") 	<<
 new zSiscomCampo("BodegaD")	<<
 new zSiscomCampo("Cantidad")	<<
 new zSiscomCampo("CveProducto");
}
zTransfiereBodegaBodega::zTransfiereBodegaBodega(zBodega *pzBodegaO,
						 zBodega *pzBodegaD,
						 const char *pchrPtrCantidad)
{
(*this) 					<< 
	new zSiscomCampo("BodegaO",pzBodegaO) 	<<
	new zSiscomCampo("BodegaD",pzBodegaD)	<<
	new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad) <<
	new zSiscomCampo("CveProducto");
}

void zTransfiereBodegaBodega::BodegaO(zBodega *pzBodegaO)
{
    ActualizaCampo("BodegaO",pzBodegaO);
}

void zTransfiereBodegaBodega::BodegaD(zBodega *pzBodegaD)
{
    ActualizaCampo("BodegaD",pzBodegaD);
}
void zTransfiereBodegaBodega::Cantidad(const char *pchrPtrCantidad)
{
   ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void zTransfiereBodegaBodega::CveProducto(const char *pchrPtrCveProducto)
{
  ActualizaCampo("CveProducto",(const unsigned char *)pchrPtrCveProducto);
}
