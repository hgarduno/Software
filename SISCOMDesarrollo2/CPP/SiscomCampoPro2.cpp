#include <SiscomCampoPro2.h>
SiscomCampoPro2::SiscomCampoPro2()
{
}
SiscomCampoPro2::~SiscomCampoPro2()
{
}
SiscomCampoPro2::SiscomCampoPro2(const char *pchrPtrNmbCampo,
				 const char *pchrPtrDato):
			chrPtrNmbCampo(pchrPtrNmbCampo),
			chrPtrDato(pchrPtrDato)
			
{
}
void SiscomCampoPro2::PonCampo(const char *pchrPtrNmbCampo)
{
		chrPtrNmbCampo=pchrPtrNmbCampo;	
}
void SiscomCampoPro2::PonDato(const char *pchrPtrDato)
{
	chrPtrDato=pchrPtrDato;
}
const char *SiscomCampoPro2::SiscomObtenCampo()
{
	return chrPtrNmbCampo;
}
const char *SiscomCampoPro2::SiscomObtenDato()
{
	return chrPtrDato;
}

