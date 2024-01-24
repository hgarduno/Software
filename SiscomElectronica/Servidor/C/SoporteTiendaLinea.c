#include <SoporteTiendaLinea.h>
#include <SiscomManejoLog.h>
void LogOrdenTiendaLinea(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 SiscomRegistroProL *pSisRegProLPtrDatoTL)
{
char lchrArrCadena[512];
/*
SiscomMensajesLog4(pchrPtrArchivo,
		   pchrPtrFuncion,
		   pintNoLinea,
	"{OrdenId}						%s\n"
	"{OrdenRastreo} 			%s\n"
	"{OrdenFecha} 				%s\n"
	"{OrdenDescuentoPorcentaje} 		%s\n"
	"{OrdenPrecioEspecial} 			%s\n"
	"{ClienteId} 				%s\n"
	"{ClienteNombre}				%s\n"
	"{ClienteApellido}			%s\n"
	"{ClienteCelular}			%s\n"
	"{DireccionCalle}			%s\n"
	"{DireccionNoExterior}			%s\n"
	"{DireccionNoInterior}			%s\n"
	"{DireccionCP}				%s\n"
	"{DireccionEstado}			%s\n",
	SiscomObtenCampoRegistroProLChar("ordenid",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("ordenrastreo",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("ordenfecha",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("ordendescuentoporcentaje",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("ordenpreciototal",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clienteid",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clientenombre",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clienteapellido",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clientecelular",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccioncalle",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccionnoexterior",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccionnointerior",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccioncp",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccionestado",pSisRegProLPtrDatoTL));
*/
sprintf(lchrArrCadena,
	"%8s%12s%27s%14s%28s%28s%5s%5s%28s",
	"OrdenId",
	"OrdenFecha",
	"ClienteId",
	"ClienteNombre",
	"ClienteApellido",
	"DireccionCalle",
	"DireccionNoExterior",
	"DireccionCp",
	"DireccionEstado"); 
	
SiscomMensajesLog4(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",lchrArrCadena);

sprintf(lchrArrCadena,
	"%8s%28s%12s%28s%28s%28s%5s%5s%28s",
	SiscomObtenCampoRegistroProLChar("ordenid",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("ordenfecha",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clienteid",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clientenombre",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("clienteapellido",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccioncalle",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccionnoexterior",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccioncp",pSisRegProLPtrDatoTL),
	SiscomObtenCampoRegistroProLChar("direccionestado",pSisRegProLPtrDatoTL));
SiscomMensajesLog4(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",lchrArrCadena);

}
