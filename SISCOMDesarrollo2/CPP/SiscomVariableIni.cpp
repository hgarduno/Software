#include <SiscomVariableIni.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
SiscomVariableIni::SiscomVariableIni()
{

}
SiscomVariableIni::SiscomVariableIni(const char *pchrPtrNombre,
				     const char *pchrPtrValor)
{
strcpy(chrPtrValor,pchrPtrValor);
strcpy(chrPtrNombre,pchrPtrNombre);

}
void SiscomVariableIni::IniciaVariables()
{

}
void SiscomVariableIni::Nombre(char *pchrPtrNombre)
{
	strcpy(pchrPtrNombre,chrPtrNombre);
}
void SiscomVariableIni::Valor(char *pchrPtrValor)
{
 	strcpy(pchrPtrValor,chrPtrValor);
}
int SiscomVariableIni::operator==(const char *pchrPtrNombre)
{
return !strcmp(chrPtrNombre,pchrPtrNombre);
}

SiscomVariableIni *SiscomVariableIni::VariablePorNivel(int pintNivel,
						       const char *pchrPtrNombre)
{
char **lchrPtrNombres;
int lintRegreso;
if((lintRegreso=SiscomDesarrollo3Qt::CadenasPorSeparador(chrPtrNombre,
					 '.',
					 &lchrPtrNombres)))
{

}
SiscomDesarrollo3Qt::LiberaCadenas(lchrPtrNombres);
return  !strcmp(lchrPtrNombres[pintNivel],pchrPtrNombre) &&
        lintRegreso ?
	this : 0;
}
int SiscomVariableIni::EsVariablePorNivel(int pintNivel,
				          const char *pchrPtrNombre)
{
char **lchrPtrNombres;
int lintRegreso;
if((lintRegreso=SiscomDesarrollo3Qt::CadenasPorSeparador(chrPtrNombre,
					 '.',
					 &lchrPtrNombres)))
{

}
lintRegreso=!strcmp(lchrPtrNombres[pintNivel],pchrPtrNombre) &&
        lintRegreso ?
	1 : 0;

SiscomDesarrollo3Qt::LiberaCadenas(lchrPtrNombres);
return lintRegreso;

}

const char *SiscomVariableIni::Valor()
{
const char *lchrPtrRegreso=chrPtrValor;
return lchrPtrRegreso;
}
const char *SiscomVariableIni::Nombre()
{
const char *lchrPtrRegreso=chrPtrNombre;
return lchrPtrRegreso;
}
