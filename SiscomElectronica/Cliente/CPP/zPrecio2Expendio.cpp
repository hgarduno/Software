#include <zPrecio2Expendio.h>
#include <zSiscomCampo.h>
#include <zEmpresa.h>
zPrecio2Expendio::zPrecio2Expendio(const char *pchrPtrPrecio,
				   zEmpresa *pzEExpendio)
{
(*this) 								<< 
   new zSiscomCampo("Precio",(const unsigned char *)pchrPtrPrecio) 	<<
   new zSiscomCampo("Expendio",pzEExpendio) ;
}
