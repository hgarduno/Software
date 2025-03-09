#include <SiscomNormalizacion.h>
#include <SiscomFuncionesComunes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void AsignaMemoriaNormalizacion(const char *pchrPtrEntrada,
				unsigned char **pchrPtrNormalizada)
{
int lintTamCadena=strlen(pchrPtrEntrada);
int lintTamano;

	lintTamano=lintTamCadena +
		   lintTamCadena +
		   2;


	*pchrPtrNormalizada=(unsigned char *)malloc(lintTamano);
}

void SiscomCambiaMayusculas(char *pchrPtrCadena)
{

	while(*pchrPtrCadena)
	{
		*pchrPtrCadena=toupper(*pchrPtrCadena);
		*pchrPtrCadena++;
	}

}
void CambiaCaracteres2(unsigned char *pchrPtrCambia,
		      unsigned char *pchrPtrCadena)
{
	while(*pchrPtrCadena)
	{
	   if(pchrPtrCambia[*pchrPtrCadena])
	   *pchrPtrCadena=pchrPtrCambia[*pchrPtrCadena];
	  pchrPtrCadena++;
	}
}
void CambiaCaracteres(unsigned char *pchrPtrCambia,
		      unsigned char *pchrPtrCadena)
{
int lintTamano=strlen(pchrPtrCadena);
unsigned char *lchrPtrCadenaOriginal=pchrPtrCadena+lintTamano+1;
	while(*pchrPtrCadena)
	{
	   *lchrPtrCadenaOriginal=*pchrPtrCadena;
	   if(pchrPtrCambia[*pchrPtrCadena])
	   *pchrPtrCadena=pchrPtrCambia[*pchrPtrCadena];
	  *pchrPtrCadena++;
	  *lchrPtrCadenaOriginal++;
	}
}
void CambiaNulo(unsigned char *pchrPtrCadena)
{
int lintTamano=strlen(pchrPtrCadena);

	pchrPtrCadena[lintTamano]='^';
	

}
/*
 * Funcion que permitira normalizar las cadenas de entrada a una aplicacion
 * La normalizacion tiene como objetivo asegurar que dos textos que se 
 * capturen de forma diferente, seguramente por las faltas de ortografia
 * se interpreten de la misma forma, es decir esta funcion nos ayudara 
 * a reducir la duplicidad de informacion, ya que se ha observado que
 * los nombres propios que se capturan con asentos, causan que se duplique
 * la informacion, ya que en otras capturas no se consideran los asentos
 * esto trae como consecuencia que en las bases de datos haya informacion
 * de la misma persona mas de una vez.
 *
 *
 */
void SiscomNormaliza(const char *pchrPtrCadena,
		     unsigned char *pchrPtrCambia,
		     unsigned char **pchrPtrSalida)
{
		AsignaMemoriaNormalizacion(pchrPtrCadena,
					   pchrPtrSalida);
	strcpy(*pchrPtrSalida,pchrPtrCadena);
	SiscomQuitaMasDeUnEspacio(*pchrPtrSalida);
	CambiaCaracteres(pchrPtrCambia,*pchrPtrSalida);
	SiscomCambiaMayusculas(*pchrPtrSalida);
	CambiaNulo(*pchrPtrSalida);
	SiscomEliminaEspaciosInicio(*pchrPtrSalida);
	SiscomEliminaEspaciosFinal(*pchrPtrSalida);
}
void SiscomNormaliza2(const char *pchrPtrCadena,
		     unsigned char *pchrPtrCambia,
		     unsigned char **pchrPtrSalida)
{

	*pchrPtrSalida=(unsigned char *)strdup(pchrPtrCadena);
	/*
	strcpy(*pchrPtrSalida,pchrPtrCadena);
	*/
	SiscomQuitaMasDeUnEspacio(*pchrPtrSalida);
	CambiaCaracteres2(pchrPtrCambia,*pchrPtrSalida);
	SiscomCambiaMayusculas(*pchrPtrSalida);
	SiscomEliminaEspaciosInicio(*pchrPtrSalida);
	SiscomEliminaEspaciosFinal(*pchrPtrSalida);
}

void SiscomQuitaMasDeUnEspacio(char *pchrPtrCadena)
{
char *lchrPtrCadena=strdup(pchrPtrCadena);
	memset(pchrPtrCadena,0,strlen(lchrPtrCadena));
	while(*lchrPtrCadena)
	{
	  *pchrPtrCadena=*lchrPtrCadena;
	  if(*lchrPtrCadena==' ')
	  {
	  *pchrPtrCadena++;
	   while(*lchrPtrCadena==' ')
	    *lchrPtrCadena++;
	  *pchrPtrCadena=*lchrPtrCadena;
	  }
	  *lchrPtrCadena++;
	  *pchrPtrCadena++;
	}
}
unsigned char *SiscomCaracteresCambiados()
{
unsigned char *lchrPtrRegreso;
		lchrPtrRegreso=(unsigned char *)malloc(256);

memset(lchrPtrRegreso,0,256);
	lchrPtrRegreso[225]='a'; 
	lchrPtrRegreso[233]='e';
	lchrPtrRegreso[237]='i'; 
	lchrPtrRegreso[241]='n';
	lchrPtrRegreso[243]='o';
	lchrPtrRegreso[250]='u';
	return lchrPtrRegreso;
}
