#ifndef __SISCOMLINEACOMANDOS_H__
#define __SISCOMLINEACOMANDOS_H__
/*
 * Martes 27 De Septiembre 2011 
 *
 * Se debe copiar a los archivos de la biblioteca Siscom
 *
 *
 */
typedef struct Opciones
{
   char *chrPtrNmbComando;
   char *chrPtrComando;
   int intNOpciones;
}StcSiscomOpciones;



void AgregaOpcion(const char *pchrPtrOpcion,
		  int pintContadorOpciones,
		     StcSiscomOpciones **pStcSiscomOpciones);

void ObtenOpcion(const char *pchrPtrArgumento,
		 char *pchrPtrOpcion);

void ObtenOpciones(const char *pchrPtrArgumentos,
		   StcSiscomOpciones **pStcSiscomOpciones);
void SiscomAnalizaOpciones(char **pchrPtrArgv,
			   int pintArgc,
			   StcSiscomOpciones **pStcSiscomOpciones);

const StcSiscomOpciones *SiscomObtenOpcion(const StcSiscomOpciones *pStcSiscomOpciones,
					  const char *pchrPtrOpcion);
			   
const char *SiscomObtenOpcionAChar(const StcSiscomOpciones *pStcSiscomOpciones);
int SiscomObtenOpcionAInt(const StcSiscomOpciones *pStcSiscomOpciones);

void SiscomMuestraOpciones(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNoLinea,
			   const StcSiscomOpciones *pStcSiscomOpciones);

int SiscomLineaComandosCompleta(char *pchrPtrOpciones[],
				const StcSiscomOpciones *pStcSiscomOpciones,
				StcSiscomOpciones *pStcSisOpcFaltantes);
		
const char *SiscomOpcionAChar(const char *pchrPtrOpcion,
			      const StcSiscomOpciones *pStcSiscomOpciones);

int SiscomOpcionAInt(const char *pchrPtrOpcion,
			      const StcSiscomOpciones *pStcSiscomOpciones);
int SiscomEstaLaOpcion(const char *pchrPtrOpcion,
		       const StcSiscomOpciones *pStcSiscomOpciones);
#define LOGSiscomLineaComandos(pStcSiscomOpciones)	\
SiscomMuestraOpciones(__FILE__,__FUNCTION__,__LINE__,pStcSiscomOpciones);
#endif
