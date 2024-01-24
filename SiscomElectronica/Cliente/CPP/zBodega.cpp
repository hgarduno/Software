#include <zBodega.h>
#include <zSiscomCampo.h>
#include <zExpendio.h>
#include <zSiscomDesarrollo4.h>
zBodega::zBodega(const char *pchrPtrIdBodega,
		 const char *pchrPtrBodega)
{

  (*this) 								<< 
  new zSiscomCampo("IdBodega",(const unsigned char *)pchrPtrIdBodega) 	<<
  new zSiscomCampo("Bodega",(const unsigned char *)pchrPtrBodega)	<<
  new zSiscomCampo("Expendio");
}
zBodega::zBodega(zSiscomRegistro *pzSisRegBodExp)
{
   (*this)							<<
   new zSiscomCampo("IdBodega",(*pzSisRegBodExp)["idbodega"])   <<
   new zSiscomCampo("Bodega",(*pzSisRegBodExp)["bodega"])	<<
   new zSiscomCampo("Expendio");
   Expendio(new zExpendio(pzSisRegBodExp));
}
void zBodega::Expendio(zExpendio *pzExpendio)
{
 ActualizaCampo("Expendio",pzExpendio);
}
const char *zBodega::Bodega()
{
   return (const char *)(*this)["Bodega"];
}
zExpendio *zBodega::Expendio()
{
  return (zExpendio *)AsociadoDelCampo("Expendio");
}
