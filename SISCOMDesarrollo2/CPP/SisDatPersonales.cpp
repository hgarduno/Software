#include <SisDatPersonales.h>
SisDatPersonales::SisDatPersonales(const char *pchrPtrNombre,
				   const char *pchrPtrAPaterno,
				   const char *pchrPtrAMaterno,
				   const char *pchrPtrIdPersona):
		SisPersona(pchrPtrNombre,
			   pchrPtrAPaterno,
			   pchrPtrAMaterno,
			   pchrPtrIdPersona)
{

	SiscomAnexaCampos(SisMedCom());
	SiscomAnexaCampos(SisDireccion("","","",""));
	IniciaVariables();

}
void SisDatPersonales::IniciaVariables()
{
	SDirDato=new SisDireccion("","","","");
}
void SisDatPersonales::SiscomAnexaMedio(SisMedCom *pSCMComDat)
{
	SLCMComMedios << pSCMComDat;	
}
void SisDatPersonales::SiscomAnexaDireccion(SisDireccion &pSDDato)
{
	*SDirDato=pSDDato;
}
