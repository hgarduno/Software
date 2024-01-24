#include <SiscomArchivoIni.h>
#include <SiscomDesarrollo3Qt++.h>
SiscomArchivoIni::SiscomArchivoIni(const char *pchrPtrArchivo):
					chrPtrArchivo(pchrPtrArchivo)
{
IniciaVariables();
LeeArchivo();
}
void SiscomArchivoIni::IniciaVariables()
{
SiscomEscribeLog3Qt("");

}
int SiscomArchivoIni::AbreArchivo()
{
return (FlePtrArchivo=fopen(chrPtrArchivo,"r")) ? 0 : 1 ;
}
void SiscomArchivoIni::LeeArchivo()
{
char lchrArrLinea[1024];
SiscomVariableIni lSisVarIni;
  if(!AbreArchivo())
  {
    while(!SiscomDesarrollo3Qt::LeeLinea(FlePtrArchivo,lchrArrLinea))
    {
     if(EsLineaParaAnalizar(lchrArrLinea))
     ObtenDatosVariable(lchrArrLinea,&lSisVarIni);
    }
  }
  else
  SiscomEscribeLog3Qt("No se pudo Abrir el Archivo:%s",chrPtrArchivo ?
     chrPtrArchivo : "Archivo Nulo");
}
void SiscomArchivoIni::ObtenDatosVariable(const char *pchrPtrLinea,
					  SiscomVariableIni *pSisVarIni)
{
char lchrArrNombre[128];
char lchrArrValor[1024];
char **lchrPtrCamposNombre;
char lchrArrNombreClase[256];
int lintNCamposNombre;
SiscomClaseIni *lSisClasIni;
DatosVariable(pchrPtrLinea,lchrArrNombre,lchrArrValor);
SiscomDesarrollo3Qt::EliminaCaracteres("\t",lchrArrNombre);
SiscomDesarrollo3Qt::EliminaCaracteres("\t",lchrArrValor);
SiscomDesarrollo3Qt::EliminaEspaciosInicio(lchrArrNombre);
SiscomDesarrollo3Qt::EliminaEspaciosInicio(lchrArrValor);
SiscomDesarrollo3Qt::EliminaEspaciosFinal(lchrArrNombre);
SiscomDesarrollo3Qt::EliminaEspaciosFinal(lchrArrValor);
if((lintNCamposNombre=SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrNombre,
					     '.',
					     &lchrPtrCamposNombre)))
{
if((lSisClasIni=SisClassIni.YaEstaLaClase(lintNCamposNombre,
  			     lchrPtrCamposNombre,
			     lchrArrNombreClase)))
{
/*
SiscomEscribeLog3Qt("Ya esta la clase (%s) Se agrega la propiedad:(%s=%s)",
		    lchrArrNombreClase,
		    lchrPtrCamposNombre[lintNCamposNombre-1],
		    lchrArrValor);
*/
lSisClasIni->AgregaPropiedad(lchrPtrCamposNombre[lintNCamposNombre-1],
			     lchrArrValor);
}
else
{
/*
SiscomEscribeLog3Qt("No esta la clase:%s, Se agrega ",
		    lchrArrNombreClase);
*/
   SisClassIni << FormaClase(lchrArrNombreClase,
   			     lchrArrValor,
			     lintNCamposNombre,
			     lchrPtrCamposNombre);
}


}
SiscomDesarrollo3Qt::LiberaCadenas(lchrPtrCamposNombre);
}
void SiscomArchivoIni::DatosVariable(const char *pchrPtrVariable,
				     char *pchrPtrNombre,
				     char *pchrPtrValor)
{
	CadenasSeparadasPor(pchrPtrVariable,
			    '=',
			    pchrPtrNombre,
			    pchrPtrValor);
}
int SiscomArchivoIni::EsLineaParaAnalizar(const char *pchrPtrLinea)
{
  return (*pchrPtrLinea=='#' ||
         !*pchrPtrLinea ) ? 0 : 1 ;
}

void SiscomArchivoIni::CadenasSeparadasPor(const char *pchrPtrCadena,
					   char pchrSeparador,
					   char *pchrPtrCadena1,
					   char *pchrPtrCadena2)
{
	while(*pchrPtrCadena!=pchrSeparador)
	{
	  *pchrPtrCadena1=*pchrPtrCadena;
	  pchrPtrCadena++;
	  pchrPtrCadena1++;
	}
	*pchrPtrCadena1=0;
	pchrPtrCadena++;
	strcpy(pchrPtrCadena2,pchrPtrCadena);
}

SiscomClaseIni *SiscomArchivoIni::FormaClase(const char *pchrPtrNombre,
					     const char *pchrPtrValor,
					     int pintNCamposNombre,
					     char **pchrPtrCamposNombre)
{
SiscomClaseIni *lSisClasIni=new SiscomClaseIni(pchrPtrNombre);
lSisClasIni->AgregaPropiedad(pchrPtrCamposNombre[pintNCamposNombre-1],
			     pchrPtrValor);
return lSisClasIni;
}

SiscomClasesIni &SiscomArchivoIni::Clases()
{
return SisClassIni;
}
