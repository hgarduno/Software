#include <zExpendio.h>
#include <zSiscomCampo.h>
zExpendio::zExpendio()
{
(*this) 				<<	
	new zSiscomCampo("RazonSocial")	<<
	new zSiscomCampo("DirIp") 	<<
	new zSiscomCampo("Puerto")	<<
	new zSiscomCampo("IdExpendio")	<<
	new zSiscomCampo("Base");
}

zExpendio::zExpendio(const char *pchrPtrRSocial,
		     const char *pchrPtrDirIp,
		     const char *pchrPtrPuerto,
		     const char *pchrPtrIdExpendio)
{
(*this) 				<<	
	new zSiscomCampo("RazonSocial",(const unsigned char *)pchrPtrRSocial)	<<
	new zSiscomCampo("DirIp",(const unsigned char *)pchrPtrDirIp) 		<<
	new zSiscomCampo("Puerto",(const unsigned char *)pchrPtrPuerto)		<<
	new zSiscomCampo("IdExpendio",(const unsigned char *)pchrPtrIdExpendio);
}
zExpendio::zExpendio(zExpendio *pzExpendio)
{
 (*this)									  <<
  new zSiscomCampo("RazonSocial",(const unsigned char *)pzExpendio->RazonSocial())<<
  new zSiscomCampo("DirIp",(const unsigned char *)pzExpendio->DirIp())		  <<
  new zSiscomCampo("Puerto",(const unsigned char *)pzExpendio->Puerto())	  <<
  new zSiscomCampo("IdExpendio",(const unsigned char *)pzExpendio->IdExpendio())  <<
  new zSiscomCampo("Basae");
}
zExpendio::zExpendio(zSiscomRegistro *pzSisRegExpendio)
{
(*this)									<<
new zSiscomCampo("RazonSocial",(*pzSisRegExpendio)["razonsocial"]) 	<<
new zSiscomCampo("DirIp",(*pzSisRegExpendio)["diripsvrad"])		<<
new zSiscomCampo("Puerto",(*pzSisRegExpendio)["puerto"])		<<
new zSiscomCampo("IdExpendio",(*pzSisRegExpendio)["idempresa"])		<<
new zSiscomCampo("Base",(*pzSisRegExpendio)["basedatos"]);

}
void zExpendio::RazonSocial(const char *pchrPtrRazonSocial)
{
   ActualizaCampo("RazonSocial",(const unsigned char *)pchrPtrRazonSocial);
}
void zExpendio::DirIp(const char *pchrPtrDirIp)
{
   ActualizaCampo("DirIp",(const unsigned char*)pchrPtrDirIp);

}
void zExpendio::Base(const char *pchrPtrBase)
{
 ActualizaCampo("Base",(const unsigned char *)pchrPtrBase);
}
void zExpendio::Puerto(const char *pchrPtrPuerto)
{
   ActualizaCampo("Puerto",(const unsigned char*)pchrPtrPuerto);

}
void zExpendio::Puerto(int pintPuerto)
{
   ActualizaCampo("Puerto",pintPuerto);
}
void zExpendio::IdExpendio(const char *pchrPtrIdExpendio)
{
   ActualizaCampo("IdExpendio",(const unsigned char*)pchrPtrIdExpendio);
}
const char *zExpendio::DirIp()
{
   return (const char *)Campo("DirIp");
}

const char *zExpendio::Puerto()
{
   return (const char *)Campo("Puerto");
}
int zExpendio::PuertoInt()
{
   return CampoInt("Puerto");
}
const char *zExpendio::IdExpendio()
{
   return (const char *)Campo("IdExpendio");
}
const char *zExpendio::RazonSocial()
{
   return (const char *)Campo("RazonSocial");
}
