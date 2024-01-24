#ifndef __SISCOMVARIABLESINI_H__
#define __SISCOMVARIABLESINI_H__
#include <SiscomVariableIni.h>
#include <qptrlist.h>
class SiscomVariablesIni:public QPtrList<SiscomVariableIni>
{
public:
	SiscomVariablesIni();
	SiscomVariablesIni &operator<<(SiscomVariableIni *pSisVarIni);
	void MuestraVariables();
	void VariablesPorNombre(const char *pchrPtrNombre,
				int pintNivel,
			        SiscomVariablesIni &pSisVarsIni);
};

#endif
