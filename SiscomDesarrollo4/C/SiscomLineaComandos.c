#include <SiscomLineaComandos.h>
#include <SiscomDesarrolloMacros.h>
#include <stdlib.h>
#include <string.h>
/*
 * Codigo para la biblioteca 
 *
 */




void ObtenOpcion(const char *pchrPtrArgumento,
		 char *pchrPtrOpcion)
{
    while(*pchrPtrArgumento &&
          *pchrPtrArgumento!='-')
    {
	*pchrPtrOpcion=*pchrPtrArgumento;
	pchrPtrOpcion++;
	pchrPtrArgumento++;

    }
 *pchrPtrOpcion=0;
}
void AgregaOpcion(const char *pchrPtrOpcion,
		  int pintContadorOpciones,
		     StcSiscomOpciones **pStcSiscomOpciones)
{
char lchrArrNmbArgumento[256];
char lchrArrArgumento[256];
int lintContador=0;
  while(*pchrPtrOpcion &&
        *pchrPtrOpcion!=' ')
  {
      lchrArrNmbArgumento[lintContador]=*pchrPtrOpcion;
      lintContador++;
      pchrPtrOpcion++;
  }
   pchrPtrOpcion++;
   lchrArrNmbArgumento[lintContador]=0;
   strcpy(lchrArrArgumento,pchrPtrOpcion);
   lchrArrArgumento[strlen(pchrPtrOpcion)-1]=0;
   if(pintContadorOpciones)
   *pStcSiscomOpciones=(StcSiscomOpciones *)realloc(
   					 *pStcSiscomOpciones,
   					sizeof(StcSiscomOpciones)*(pintContadorOpciones+1));
   (*pStcSiscomOpciones+pintContadorOpciones)->chrPtrNmbComando=strdup(lchrArrNmbArgumento);
   (*pStcSiscomOpciones+pintContadorOpciones)->chrPtrComando=strdup(lchrArrArgumento);
}
void ObtenOpciones(const char *pchrPtrArgumentos,
		   StcSiscomOpciones **pStcSiscomOpciones)
{
char lchrArrOpcion[256];
int lintContadorOpciones=0;
  *pStcSiscomOpciones=(StcSiscomOpciones *)malloc(sizeof(StcSiscomOpciones));
  while(*pchrPtrArgumentos)
  {
     if(*pchrPtrArgumentos=='-')
     {
     ObtenOpcion(++pchrPtrArgumentos,lchrArrOpcion);
     AgregaOpcion(lchrArrOpcion,lintContadorOpciones,pStcSiscomOpciones);
     lintContadorOpciones++;

     }
     pchrPtrArgumentos++;
  }
  (*pStcSiscomOpciones)->intNOpciones=lintContadorOpciones;
}
/*
 * Martes 27 de Septiembre 2011 
 * Se desarrolla la siguiente funcion para manipular los argumentos
 * de entrada de los programas
 * la consideracion que se toma es que el nombre del argumento antecede
 * un signo - despues el nombre del argumento termina con espacio, el dato
 * del argumento lo determina el siguiente - de la linea de comandos 
 *
 */
void SiscomAnalizaOpciones(char **pchrPtrArgv,
			   int pintArgc,
			   StcSiscomOpciones **pStcSiscomOpciones)
{
char **lchrPtrAnaliza=pchrPtrArgv+1;
char lchrArrArgumento[2048];
lchrArrArgumento[0]=0;
	while(*lchrPtrAnaliza)
	{
	  strcat(lchrArrArgumento,*lchrPtrAnaliza); 
	  strcat(lchrArrArgumento," ");
	  lchrPtrAnaliza++;
	}
ObtenOpciones(lchrArrArgumento,pStcSiscomOpciones);
}


const StcSiscomOpciones *SiscomObtenOpcion(const StcSiscomOpciones *pStcSiscomOpciones,
					  const char *pchrPtrOpcion)
{
int lintContador;
for(lintContador=0;
    lintContador<pStcSiscomOpciones->intNOpciones;
    lintContador++)
if(!strcmp((pStcSiscomOpciones+lintContador)->chrPtrNmbComando,pchrPtrOpcion))
 return (pStcSiscomOpciones+lintContador);
return 0;
}

void SiscomMuestraOpciones(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNoLinea,
			   const StcSiscomOpciones *pStcSiscomOpciones)
{

while(pStcSiscomOpciones->chrPtrNmbComando)
{
SiscomMensajesLog4(pchrPtrArchivo,
		    pchrPtrFuncion,
		    pintNoLinea,
		    "%s=%s",
		    pStcSiscomOpciones->chrPtrNmbComando,
		    pStcSiscomOpciones->chrPtrComando);
pStcSiscomOpciones++;
}

}

const char *SiscomObtenOpcionAChar(const StcSiscomOpciones *pStcSiscomOpciones)
{
if(pStcSiscomOpciones)
return pStcSiscomOpciones->chrPtrComando;
else 
return 0;
}
int SiscomObtenOpcionAInt(const StcSiscomOpciones *pStcSiscomOpciones)
{
 if(pStcSiscomOpciones)
 return atoi(SiscomObtenOpcionAChar(pStcSiscomOpciones));
 else
 return 0;
}

float SiscomObtenOpcionAFloat(const StcSiscomOpciones *pStcSiscomOpciones)
{
 if(pStcSiscomOpciones)
 return atof(SiscomObtenOpcionAChar(pStcSiscomOpciones));
 else
 return 0;
}

const char *SiscomOpcionAChar(const char *pchrPtrOpcion,
			      const StcSiscomOpciones *pStcSiscomOpciones)
{
const StcSiscomOpciones *lStcSisOpcOpcion;
if((lStcSisOpcOpcion=SiscomObtenOpcion(pStcSiscomOpciones,pchrPtrOpcion)))
  return SiscomObtenOpcionAChar(lStcSisOpcOpcion);
else
return 0;
}

int SiscomOpcionAInt(const char *pchrPtrOpcion,
			      const StcSiscomOpciones *pStcSiscomOpciones)
{
const StcSiscomOpciones *lStcSisOpcOpcion;
if((lStcSisOpcOpcion=SiscomObtenOpcion(pStcSiscomOpciones,pchrPtrOpcion)))
  return SiscomObtenOpcionAInt(lStcSisOpcOpcion);
else
return 0;
}

float SiscomOpcionAFloat(const char *pchrPtrOpcion,
			      const StcSiscomOpciones *pStcSiscomOpciones)
{
const StcSiscomOpciones *lStcSisOpcOpcion;
if((lStcSisOpcOpcion=SiscomObtenOpcion(pStcSiscomOpciones,pchrPtrOpcion)))
  return SiscomObtenOpcionAFloat(lStcSisOpcOpcion);
else
return 0;
}

int SiscomLineaComandosCompleta(char *pchrPtrOpciones[],
				const StcSiscomOpciones *pStcSiscomOpciones,
				StcSiscomOpciones *pStcSisOpcFaltantes)
{
int lintContador=0;
int lintNOpciones;
 for(lintNOpciones=0;
     *pchrPtrOpciones;
      pchrPtrOpciones++,
      lintNOpciones++)
 {
    if(SiscomObtenOpcion(pStcSiscomOpciones,*pchrPtrOpciones))
     lintContador++;
 }
   return lintNOpciones==lintContador; 
}

int SiscomEstaLaOpcion(const char *pchrPtrOpcion,
		       const StcSiscomOpciones *pStcSiscomOpciones)
{
  return SiscomObtenOpcion(pStcSiscomOpciones,pchrPtrOpcion) ? 1 :0 ;
}

void SiscomAgregaLineaComandos(const char *pchrPtrOpcion,
			const char *pchrPtrValor,
			StcSiscomOpciones **pStcSiscomOpciones)
{
int lintNOpcion;

lintNOpcion=(*pStcSiscomOpciones)->intNOpciones;
  lintNOpcion++;
   *pStcSiscomOpciones=(StcSiscomOpciones *)realloc(*pStcSiscomOpciones,
   						   sizeof(StcSiscomOpciones)*lintNOpcion);

  ((*pStcSiscomOpciones)+lintNOpcion-1)->chrPtrNmbComando=strdup(pchrPtrOpcion);
  ((*pStcSiscomOpciones)+lintNOpcion-1)->chrPtrComando=strdup(pchrPtrValor);
  (*pStcSiscomOpciones)->intNOpciones=lintNOpcion;
}

void SiscomActualizaOpcion(const char *pchrPtrOpcion,
			   const char *pchrPtrValor,
			   const StcSiscomOpciones *pStcSiscomOpciones)
{
const StcSiscomOpciones *lStcSisOpciones;

if((lStcSisOpciones=SiscomObtenOpcion(pStcSiscomOpciones,pchrPtrOpcion)))
   ((StcSiscomOpciones *)lStcSisOpciones)->chrPtrComando=strdup(pchrPtrValor);
}
