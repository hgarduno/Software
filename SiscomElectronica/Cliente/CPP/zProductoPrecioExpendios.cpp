#include <zProductoPrecioExpendios.h>
#include <zSiscomCampo.h>

#include <zEmpresas.h>
zProductoPrecioExpendios::zProductoPrecioExpendios(const char *pchrPtrClave):
					zProductoPrecio(pchrPtrClave)
{
(*this) 			<< 
new zSiscomCampo("Expendios");
}

void zProductoPrecioExpendios::Expendios(zEmpresas *pzEmpresas)
{
 ActualizaCampo("Expendios",pzEmpresas);
}
