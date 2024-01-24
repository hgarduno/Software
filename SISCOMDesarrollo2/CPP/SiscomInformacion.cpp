#include <SiscomInformacion.h>


SiscomInformacion::SiscomInformacion()
{
}
SiscomInformacion::~SiscomInformacion()
{
}
void SiscomInformacion::SiscomActualizaCampo(const char *pchrPtrCampo,
					     const char *pchrPtrValor)
{

	SRegistrosPro2.SiscomActualizaCampo(pchrPtrCampo,pchrPtrValor);

}
/*
const char *SiscomInformacion::operator[](const char *pchrPtrNmbCampo)
{
	return SRegistrosPro2[pchrPtrNmbCampo];
}

*/
