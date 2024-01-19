#ifndef __SISCOMARCHIVOSINI_H__
#define __SISCOMARCHIVOSINI_H__
typedef struct siscomVariblesIni
{
  char chrArrNombre[256];
  char chrArrDato[256];
}SiscomVariableIni;

typedef struct siscomVariblesIniL
{
  SiscomVariableIni SiscomVIni;
  struct siscomVariablesIniL *SiscomVIniLPtrSig;
  struct siscomVariablesIniL *SiscomVIniLPtrAnt;
}SiscomVariablesIniL;

typedef struct siscomVariableIniArregloL
{
   int intNDatosArreglo;
   char chrArrNombre[256];
   SiscomVariablesIniL *SiscomVILPtrDatos;
   struct siscomVariableIniArregloL *SiscomVIAPtrSig;
}SiscomVariableIniArregloL;
typedef struct SiscomDatosIni
{
   SiscomVariableIniArregloL *SiscomVIALPtrArreglo;
   SiscomVariablesIniL *SiscomVILPtrVariables;
}SiscomDatosIni;

int SiscomObtenInformacionVariableArreglo(const char *pchrPtrNombreArreglo,
			       const SiscomDatosIni *pSiscomDatIniPtrDatos,
			       SiscomVariableIniArregloL **pSiscomVarIniArrLPtrDat);
int SiscomAsignaMemoriaNodoArreglo(const char *pchrPtrNombre,
				   SiscomVariablesIniL *pSiscomVILPtrInfo,
				   SiscomVariableIniArregloL **pSiscomVALPtrNodo);

int SiscomNodoVariableArregloIni(const char *pchrPtrNombre,
				 SiscomVariablesIniL *pSiscomVILPtrInfo,
				 SiscomVariableIniArregloL **pSiscomVIALPtrPrim,
				 SiscomVariableIniArregloL **pSiscomVIALPtrAct);
int SiscomVarIniAsignaMemoriaNodo(const SiscomVariableIni *pSiscomVIniPtrDato,
				SiscomVariablesIniL **pSiscomVILPtrDato);
int SiscomVarIniNodoVariableIni(const SiscomVariableIni *pSiscomVIniPtrDato,
				SiscomVariablesIniL **pSisccomVILPtrPrim,
				SiscomVariablesIniL **pSiscomVILPtrActual);
int SiscomEsLineaConAsignacion(const char *pchrPtrLinea);
void SiscomObtenVariablesArreglo(int pintNLineas,
    			 	   char **pchrPtrVariables,
				   SiscomVariableIniArregloL **pSiscomVIALPtrPrim,
				   SiscomVariableIniArregloL **pSiscomVIALPtrAct);
void SiscomObtenVariablesAsignacion(int pintNLineas,
				    char **pchrPtrVariables,
				    SiscomVariablesIniL **pSiscomVILPtrIni,
				    SiscomVariablesIniL **pSiscomVILPtrActual);
int SiscomEsLaVariableNodoActual(
		const char *pchrPtrVariable,
		const SiscomVariablesIniL *pSiscomVILPtrDato);
int SiscomObtenVariableIni(const char *pchrPtrNombre,
		      const SiscomDatosIni *pSiscomDIPtrDatos,
		      SiscomVariableIni *pSiscomVIPtrRegreso);
int SiscomObtenVariablesArregloIni(const char *pchrPtrNombreArreglo,
				   const SiscomDatosIni *pSiscomDatIni,
				   SiscomVariableIni *pSisVarIniReg,
				   int *pintPtrNVariables);
int SiscomObtenVariableArregloIni(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
		      		  SiscomVariableIni *pSiscomVIPtrRegreso);
int SiscomObtenVariableArregloIniAInt(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos);
int SiscomObtenVariableArregloIniAChar(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
				  char *pchrPtrDato);

const char *SiscomObtenVariableArregloIniAChar2(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
				  char *pchrPtrDato);
int SiscomAnalizaArchivoIni(const char *pchrPtrArchivo,
			    SiscomDatosIni *pSiscomDIPtrRegreso);

int SiscomVariableIniAInt(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos);
/* Miercoles 9 de mayo del 2012
 * OJOOOOOOOOOOOOOOOOOOOOOOOOO, esta funcion regresa la direccion de memoria
 * de un elemento de la estructura SiscomDatosIni, por lo cual se debera 
 * utilizar cuando la variable de datos del ini sea global
 */
int SiscomVariableIniAChar(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos,
			  char *pchrPtrDato);

char *SiscomVariableIniAChar2(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos,
			  char *pchrPtrDato);
/*
 * Martes 15 Abril del 2014
 * Estas funciones se deberan agregar a la biblioteca SiscomDesarrollo4
 * en el manejo de archivos ini
 *
 */
/*
void SiscomCompletaVariableConVariables(int pintNVarsIni,
					SiscomVariableIni *pSisVarIni);
*/
const char *SiscomEsVariableConSubValorVariable(const char *pchrPtrValor,
						char *pchrPtrVariable);


const char *SiscomObtenDatoVariableArreglo(const SiscomDatosIni *pSisDatIni,
					   const SiscomVariableIni *pSisVarArrIni,
					   int pintNVarsIni,
					   const char *pchrPtrVariable,
					   char *pchrPtrRegreso);

const char *SiscomObtenDatoVariableArreglo2(const SiscomDatosIni *pSisDatIni,
					   const char *pchrPtrArreglo,
					   const char *pchrPtrVariable,
					   char *pchrPtrRegreso);
int SiscomObtenVariableArregloACharChar(const SiscomDatosIni *pSisDatIni,
				 	const char *pchrPtrVariable,
					char ***pchrPtrVariables);

extern SiscomDatosIni gSiscomDatIni;
#endif
