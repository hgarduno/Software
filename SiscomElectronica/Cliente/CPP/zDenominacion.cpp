#include <zDenominacion.h>
#include <zSiscomCampo.h>
zDenominacion::zDenominacion(const char *pchrPtrId,
			     const char *pchrPtrDenominacion)
{

(*this)										<< 
new zSiscomCampo("Id",(const unsigned char *)pchrPtrId) 			<<
new zSiscomCampo("Denominacion",(const unsigned char *)pchrPtrDenominacion) ;
}

zDenominacion::zDenominacion()
{
  (*this)		<<
  new zSiscomCampo("Id") <<
  new zSiscomCampo("Denominacion");

}

const char *zDenominacion::Id()
{

	return (const char *)(*this)["Id"];
}

const char *zDenominacion::Denominacion()
{
	return (const char *)(*this)["Denominacion"];
}
