#ifndef __IMPRIMECOMPROBANTECURSO_H__
#define __IMPRIMECOMPROBANTECURSO_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpImprimeComprobanteCurso();
void ImprimeComprobanteCurso(SArgsSiscom *pSAgsSiscom);


void ArchivoTemporalTicketPagoCurso(
		     const char *pchrPtrTexto,
		     char *pchrPtrArchivo);

void ImprimiendoTicketPagoCurso(const char *pchrPtrTexto);
void TextoTicketPagoCurso(SArgsSiscom *pSAgsSiscom,char *pchrPtrTexto);
#endif
