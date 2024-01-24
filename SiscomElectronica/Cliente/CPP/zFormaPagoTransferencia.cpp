#include <zFormaPagoTransferencia.h>
#include <zSiscomCampo.h>

zFormaPagoTransferencia::zFormaPagoTransferencia()
{
 (*this)					<<
 new zSiscomCampo("YaSeReflejo")		<<
 new zSiscomCampo("Observaciones");
}

zFormaPagoTransferencia::zFormaPagoTransferencia(zSiscomRegistro *pzSisRegistro)
{
 (*this)								<<
 new zSiscomCampo("YaSeReflejo",(*pzSisRegistro)["sereflejo"])		<<
 new zSiscomCampo("Observaciones",(*pzSisRegistro)["observaciones"]);
}
void zFormaPagoTransferencia::YaSeReflejo(const char *pchrPtrYaSeReflejo)
{
  ActualizaCampo("YaSeReflejo",(const unsigned char *)pchrPtrYaSeReflejo);
}
void zFormaPagoTransferencia::Observaciones(const char *pchrPtrObservaciones)
{
 ActualizaCampo("Observaciones",(const unsigned char *)pchrPtrObservaciones);
}
int zFormaPagoTransferencia::YaSeReflejoInt()
{
return CampoInt("YaSeReflejo");
}

const char *zFormaPagoTransferencia::Observaciones()
{
  return (const char *)Campo("Observaciones");
}
