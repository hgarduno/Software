#include <zListaExpendios.h>
#include <zSiscomCampo.h>


#include <zEmpresa.h>
zListaExpendios::zListaExpendios()
{
  (*this)		<< 
  new zSiscomCampo("Expendios");

}

void zListaExpendios::Agrega(zEmpresa *pzEmpresa)
{
   AgregaCampo("Expendios",pzEmpresa); 
}
