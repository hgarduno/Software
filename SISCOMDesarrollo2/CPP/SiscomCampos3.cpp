#include <SiscomCampos3.h>
#include <string.h>
#include <stdlib.h>
/*
#include <SiscomDesarrollo3Qt++.h>
*/
SiscomCampo3::SiscomCampo3(const char *pchrPtrNmbCampo,
			   const char *pchrPtrDato)
{

chrPtrNmbCampo=strdup(pchrPtrNmbCampo);
chrPtrDato=strdup(pchrPtrDato);
}
SiscomCampo3::~SiscomCampo3()
{
free((void *)chrPtrNmbCampo);
free((void *)chrPtrDato);
}
const char *SiscomCampo3::SiscomDato()
{
	return chrPtrDato;
}
const char *SiscomCampo3::SiscomNmbCampo()
{
	return chrPtrNmbCampo;
}
int SiscomCampo3::operator==(const char *pchrPtrNmbCampo)
{
    return !strcmp(chrPtrNmbCampo,pchrPtrNmbCampo);
}
int SiscomCampo3::operator==(SiscomCampo3 *pSisCampo3)
{
  return (*this)==pSisCampo3->SiscomNmbCampo();
}
void SiscomCampo3::SiscomActualizaCampo(const char *pchrPtrDato)
{
     free((void *)chrPtrDato);
     chrPtrDato=strdup(pchrPtrDato);
}
SiscomCampo3Lst::SiscomCampo3Lst()
{


}
SiscomCampo3Lst::~SiscomCampo3Lst()
{
setAutoDelete(true);
clear();
}
SiscomCampo3Lst &SiscomCampo3Lst::operator<<(SiscomCampo3 *pSCampo3)
{
	append(pSCampo3);
	return *this;
}
const char *SiscomCampo3Lst::operator[](const char *pchrPtrCampo)
{
SiscomCampo3 *lSCampo3;
for(lSCampo3=first(); 
    lSCampo3;
    lSCampo3=next())
if((*lSCampo3)==pchrPtrCampo)
return lSCampo3->SiscomDato();

return "Campo No Encontrado";
}
SiscomCampo3 *SiscomCampo3Lst::Campo3(const char *pchrPtrCampo)
{
SiscomCampo3 *lSCampo3;
for(lSCampo3=first(); 
    lSCampo3;
    lSCampo3=next())
if((*lSCampo3)==pchrPtrCampo)
return lSCampo3;
return 0;
}
const char *SiscomCampo3Lst::operator[](int pintNCampo)
{
SiscomCampo3 *lSCampo3=at(pintNCampo);
if(lSCampo3)
return lSCampo3->SiscomDato();
else
return 0;
}
int SiscomCampo3Lst::operator==(const char *pchrPtrRegistro)
{
char lchrArrRegistro[512];
SiscomCampo3 *lSisCamp3Dato;
lchrArrRegistro[0]=0;
for(lSisCamp3Dato=first();
    lSisCamp3Dato;
    lSisCamp3Dato=next())
   strcat(lchrArrRegistro,lSisCamp3Dato->SiscomNmbCampo());
return !strcmp(pchrPtrRegistro,lchrArrRegistro);
}
void SiscomCampo3Lst::SiscomActualizaCampo(const char *pchrPtrNmbCampo,
					   const char *pchrPtrDato)
{
SiscomCampo3 *lSCampo3;
for(lSCampo3=first(); 
    lSCampo3;
    lSCampo3=next())
if((*lSCampo3)==pchrPtrNmbCampo)
lSCampo3->SiscomActualizaCampo(pchrPtrDato);



}
