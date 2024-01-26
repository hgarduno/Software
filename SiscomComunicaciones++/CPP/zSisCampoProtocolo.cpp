#include <zSisCampoProtocolo.h>
#include <string.h>

zSisCampoProtocolo::zSisCampoProtocolo(const char *pchrPtrNombre,
				       const char *pchrPtrDato):
				       chrPtrDato(pchrPtrDato)
{
strcpy(chrArrNombre,pchrPtrNombre);
}

const char *zSisCampoProtocolo::Campo()
{
  return chrPtrDato;
}
void zSisCampoProtocolo::NmbCampo(char *pchrPtrNmbCampo)
{
  strcpy(pchrPtrNmbCampo,chrArrNombre);
}
