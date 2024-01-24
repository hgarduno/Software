#ifndef __SISCOMVARIABLEINI_H__
#define __SISCOMVARIABLEINI_H__

class SiscomVariableIni
{
public:
	SiscomVariableIni();
	SiscomVariableIni(const char *pchrPtrNombre,const char *pchrPtrValor);
	void Nombre(char *pchrPtrNombre);
	void Valor(char *pchrPtrValor);
	const char *Nombre();
	const char *Valor();

	int operator==(const char *pchrPtrVariable);

	SiscomVariableIni *VariablePorNivel(int pintNivel,const char *pchrPtrNombre);
	int EsVariablePorNivel(int pintNivel,const char *pchrPtrNombre);

private:
	char chrPtrValor[256];
	char chrPtrNombre[128];
private:
	void IniciaVariables();
};

#endif
