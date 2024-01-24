#ifndef __IMPRESIONTRANSFERENCIAS_H__
#define __IMPRESIONTRANSFERENCIAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
void ImprimePedidoOtrosExpendios(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
int ImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato);

void TextoEncabezadoImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
					      char **pchrPtrTexto);
void FormaTextoImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
				         char **pchrPtrTexto);
void TextoProductosImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
					     char **pchrPtrTexto);
void ArchivoTransferenciaExpendioAExpendio(SiscomOperaciones *pSiscomOpePtrDato,
					  char *pchrPtrArchivo);
void EscribiendoArchivoTicketTransferencia(const char *pchrPtrArchivo,
					   char *pchrPtrTextoImpresion);
#endif
