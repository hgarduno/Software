#include <zDepartamento.h>
#include <zSiscomCampo.h>
zDepartamento::zDepartamento(const char *pchrPtrIdDepartamento,
		 const char *pchrPtrNombreDepto,
		 const char *pchrPtrAbrevDepto)
{
  (*this) 							<< 
  new zSiscomCampo("IdDepartamento",(unsigned char *)pchrPtrIdDepartamento) 	<<
  new zSiscomCampo("NombreDepto",(unsigned char *)pchrPtrNombreDepto)       	<<
  new zSiscomCampo("AbrevDepto",(unsigned char *)pchrPtrAbrevDepto);
}
