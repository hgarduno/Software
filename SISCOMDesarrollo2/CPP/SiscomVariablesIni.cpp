#include <SiscomVariablesIni.h>
#include <SiscomDesarrollo3Qt++.h>
SiscomVariablesIni::SiscomVariablesIni()
{


}
SiscomVariablesIni &SiscomVariablesIni::operator<<(SiscomVariableIni *pSisVarIni)
{
  append(pSisVarIni);
  return *this;
}
void SiscomVariablesIni::MuestraVariables()
{
SiscomVariableIni *lSisVarIni;
char lchrArrNombre[128];
char lchrArrValor[256];
for(lSisVarIni=first();
    lSisVarIni;
    lSisVarIni=next())
{
lSisVarIni->Nombre(lchrArrNombre);
lSisVarIni->Valor(lchrArrValor);
SiscomEscribeLog3Qt("%s=%s",lchrArrNombre,lchrArrValor);

}
}

void SiscomVariablesIni::VariablesPorNombre(const char *pchrPtrNombre,
					    int pintNivel,
					    SiscomVariablesIni &pSisVarsIni)
{
SiscomVariableIni *lSisVarIni;
for(lSisVarIni=first();
    lSisVarIni;
    lSisVarIni=next())
if(lSisVarIni->EsVariablePorNivel(pintNivel,pchrPtrNombre))
 pSisVarsIni << lSisVarIni;
}
