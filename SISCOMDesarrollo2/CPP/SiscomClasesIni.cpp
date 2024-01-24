#include <SiscomClasesIni.h>
#include <SiscomDesarrollo3Qt++.h>
#include <stdio.h>
#include <string.h>
SiscomClasesIni::SiscomClasesIni()
{




}

SiscomClasesIni &SiscomClasesIni::operator<<(SiscomClaseIni *pSisClasIni)
{
 append(pSisClasIni);
 return *this;
}
void SiscomClasesIni::FormaNombre(int pintNCamposNombre,
				  char **pchrPtrCamposNombre,
				  char *pchrPtrNombre)
{
int lintContador;
char lchrArrPaso[128];
*pchrPtrNombre=0;
  for(lintContador=0;
      lintContador<(pintNCamposNombre-1);
      lintContador++)
  {
     sprintf(lchrArrPaso,"%s.",pchrPtrCamposNombre[lintContador]);
     strcat(pchrPtrNombre,lchrArrPaso);
  }
pchrPtrNombre[strlen(pchrPtrNombre)-1]=0;
}
SiscomClaseIni *SiscomClasesIni::YaEstaLaClase(int pintNCamposNombre,
				   char **pchrPtrCamposNombre,
				   char *pchrPtrNombre)
{
SiscomClaseIni *lSisClasIni;
  FormaNombre(pintNCamposNombre,pchrPtrCamposNombre,pchrPtrNombre);
for(lSisClasIni=first();
    lSisClasIni;
    lSisClasIni=next())
{
  if(((*lSisClasIni)==pchrPtrNombre))
  return lSisClasIni;
  
}
return 0;
}

void SiscomClasesIni::ClasesPorNombre(const char *pchrPtrNombre,
				      SiscomClasesIni &pSisClassIni)
{
SiscomClaseIni *lSisClasIni;
for(lSisClasIni=first();
    lSisClasIni;
    lSisClasIni=next())
if(lSisClasIni->EsLaClasePorNombre(pchrPtrNombre))
 pSisClassIni << lSisClasIni;
}
SiscomClaseIni *SiscomClasesIni::ClasePorNombre(const char *pchrPtrNombre,
						int pintNivel)
{
SiscomClaseIni *lSisClasIni;
for(lSisClasIni=first();
    lSisClasIni;
    lSisClasIni=next())
if(lSisClasIni->EsLaClasePorNombre(pchrPtrNombre,pintNivel))
return lSisClasIni;

return 0;
}
void SiscomClasesIni::ClasesPorNombre(const char *pchrPtrNombre,
				      int pintNivel,
				      SiscomClasesIni &pSisClassIni)
{
SiscomClaseIni *lSisClasIni;
for(lSisClasIni=first();
    lSisClasIni;
    lSisClasIni=next())
if(lSisClasIni->EsLaClasePorNombre(pchrPtrNombre,pintNivel))
 pSisClassIni << lSisClasIni;
}
const char *SiscomClasesIni::ValorPropiedad(const char *pchrPtrClase,
				       const char *pchrPtrPropiedad)
{
SiscomClaseIni *lSisClasIni=ClasePorNombre(pchrPtrClase,0);
SiscomVariableIni *lSisVarIni;
if(lSisClasIni)
{
   if((lSisVarIni=lSisClasIni->Propiedad(pchrPtrPropiedad)))
	return lSisVarIni->Valor();	
   return 0;
}
return 0;
}
