#ifndef __SISCOMARCHIVOINI_H__
#define __SISCOMARCHIVOINI_H__
#include <SiscomClasesIni.h>
#include <stdio.h>
class SiscomVariableIni;
class SiscomArchivoIni
{
public:
	SiscomArchivoIni(const char *pchrPtrArchivo);
	SiscomClasesIni &Clases();
private:

     const char *chrPtrArchivo;
     FILE *FlePtrArchivo;
     SiscomClasesIni SisClassIni;
private:
	void IniciaVariables();
	int AbreArchivo();
	void LeeArchivo();
	int EsLineaParaAnalizar(const char *);
	void ObtenDatosVariable(const char *pchrPtrLinea,
				SiscomVariableIni *);
	void DatosVariable(const char *pchrPtrVariable,
			   char  *pchrPtrNombre,
			   char *pchrPtrDato);
	void CadenasSeparadasPor(const char *pchrPtrCadena,	
				 char pchrSeparador,
				 char *pchrPtrCadena1,
				 char *pchrPtrCadena2);
	SiscomClaseIni *FormaClase(const char *pchrNombre,
				   const char *pchrPtrValor,
				   int pintNCamposNombre,
				   char **pchrPtrCamposNombre);

				   
};

#endif
