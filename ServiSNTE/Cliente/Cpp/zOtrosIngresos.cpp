#include <zOtrosIngresos.h>
#include <zSiscomCampo.h>
zOtrosIngresos::zOtrosIngresos(const char *pchrPtrIdPersona)
{
  (*this)			<<
  new zSiscomCampo("IdPersona",(const unsigned char *)pchrPtrIdPersona) <<
  new zSiscomCampo("Monto")	<<
  new zSiscomCampo("Descripcion");
}
zOtrosIngresos::zOtrosIngresos()
{

}
zOtrosIngresos *zOtrosIngresos::DesdeDatosEmpleo(zSiscomRegistro *pzSisRegEmpleo)
{
zOtrosIngresos *lzOtrosIngs=new zOtrosIngresos((const char *)(*pzSisRegEmpleo)["idpersonaempleo"]);
lzOtrosIngs->Monto((const char *)(*pzSisRegEmpleo)["monto"]);
lzOtrosIngs->Descripcion((const char *)(*pzSisRegEmpleo)["descripcion"]);

return lzOtrosIngs;

}
void zOtrosIngresos::Monto(const char *pchrPtrMonto)
{
	ActualizaCampo("Monto",(const unsigned char *)pchrPtrMonto);
}
void zOtrosIngresos::Descripcion(const char *pchrPtrDescripcion)
{
	ActualizaCampo("Descripcion",(const unsigned char *)pchrPtrDescripcion);
}
