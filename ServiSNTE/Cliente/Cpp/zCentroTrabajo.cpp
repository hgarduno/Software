#include <zCentroTrabajo.h>
#include <zSiscomCampo.h>
zCentroTrabajo::zCentroTrabajo()
{
(*this)		<< 
new zSiscomCampo("IdPersona")		<<
new zSiscomCampo("CentroTrabajo")	<<
new zSiscomCampo("ClavePresupuestal");
}

zCentroTrabajo::zCentroTrabajo(zSiscomRegistro *pzSisRegCentroTrabajo)
{
(*this)		<< 
new zSiscomCampo("IdPersona",(*pzSisRegCentroTrabajo)["idpersona"])		<<
new zSiscomCampo("CentroTrabajo",(*pzSisRegCentroTrabajo)["centrotrabajo"])	<<
new zSiscomCampo("ClavePresupuestal",(*pzSisRegCentroTrabajo)["clavepresupuestal"]);
}

zCentroTrabajo::zCentroTrabajo(const char *pchrPtrIdPersona,
			       const char *pchrPtrCentroTrabajo,
			       const char *pchrPtrClavePresupuestal)
{
(*this)		<< 
new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona)			<<
new zSiscomCampo("CentroTrabajo",(const unsigned char *)pchrPtrCentroTrabajo)		<<
new zSiscomCampo("ClavePresupuestal",(const unsigned char *)pchrPtrClavePresupuestal);
}
