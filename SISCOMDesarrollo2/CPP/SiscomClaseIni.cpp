#include <SiscomClaseIni.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
SiscomClaseIni::SiscomClaseIni(const char *pchrPtrClase)
{
	strcpy(chrArrNombre,pchrPtrClase);
}

int SiscomClaseIni::operator==(const char *pchrPtrClase)
{
return !strcmp(chrArrNombre,pchrPtrClase);
}
int SiscomClaseIni::EsLaClasePorNombre(const char *pchrPtrNombre,
				       int pintNivel)
{
char **lchrPtrCamposNombre;
int lintRegreso;
 SiscomDesarrollo3Qt::CadenasPorSeparador(chrArrNombre,
 					  '.',
					  &lchrPtrCamposNombre);

lintRegreso=strcmp(lchrPtrCamposNombre[pintNivel],pchrPtrNombre);
SiscomDesarrollo3Qt::LiberaCadenas(lchrPtrCamposNombre);

return !lintRegreso;

}
int SiscomClaseIni::EsLaClasePorNombre(const char *pchrPtrNombre)
{
  return strstr(chrArrNombre,pchrPtrNombre)? 1:0;
}
void SiscomClaseIni::AgregaPropiedad(const char *pchrPtrPropiedad,
				     const char *pchrPtrValor)
{
append(new SiscomVariableIni(pchrPtrPropiedad,pchrPtrValor));
}

void SiscomClaseIni::Muestra()
{
SiscomVariableIni *lSisVarIni;
char lchrArrNombre[128];
char lchrArrValor[256];
SiscomEscribeLog3Qt("%s",chrArrNombre);
for(lSisVarIni=first();
    lSisVarIni;
    lSisVarIni=next())
{
lSisVarIni->Nombre(lchrArrNombre);
lSisVarIni->Valor(lchrArrValor);
SiscomEscribeLog3Qt("\t%s=%s",lchrArrNombre,lchrArrValor);
}

}
void SiscomClaseIni::Clase(char *pchrPtrClase)
{
 strcpy(pchrPtrClase,chrArrNombre);
}
SiscomVariableIni *SiscomClaseIni::Propiedad(const char *pchrPtrPropiedad)
{
SiscomVariableIni *lSisVarIni;
char lchrArrNombre[256];
for(lSisVarIni=first();
    lSisVarIni;
    lSisVarIni=next())
{
   if((*lSisVarIni)==pchrPtrPropiedad)
    return lSisVarIni;
}
return 0;
}
