#ifndef __IMPRESIONTICKETVENTA_H__
#define __IMPRESIONTICKETVENTA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <stdio.h>
void ImprimeTicketVenta4(int pintSocket,
			 SiscomRegistroProL *pSiscomRegProLPtrPrim,
			 SiscomRegistroProL *pSiscomRegProLPtrAct);
int ImprimiendoTicketVenta(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoFechaHora(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaCampoIdImpresion(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoDireccionExpendio(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoTelefonosExpendio(SiscomOperaciones *pSiscomOpePtrDato);
void FormaTextoEncabezadoTicket(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto);
int TamanoBufferImpresion4(SiscomOperaciones *pSiscomOpePtrDato);
void FormaTextoTicket(SiscomOperaciones *pSiscomOpePtrDato,
		     char **pchrPtrTexto);
void FormaProductosTicket(SiscomOperaciones *pSiscomOpePtrDato,
			  char *pchrPtrTexto);
void FormaTicketImpresion(SiscomOperaciones *pSiscomOpePtrDato,
			  char **pchrPtrTextoImpresion);
void EscribiendoArchivoImpresion(SiscomOperaciones *pSiscomOpePtrDato,
				 const char *pchrPtrTicket,
				 char *pchrPtrArchivo);


int ArgumentoImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoImpresoras(SiscomOperaciones *pSiscomOpePtrDato);

int EsApartado(SiscomOperaciones *pSiscomOpePtrDato);
int EsCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int EsPedido(SiscomOperaciones *pSiscomOpePtrDato);
int EsCancelacion(SiscomOperaciones *pSiscomOpePtrDato);
int EsRegistroImpreso(SiscomOperaciones *pSiscomOpePtrDato);
int EsMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato);
int EsDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato);

const char *ObtenObservacionesApartado(SiscomOperaciones *pSiscomOpePtrDato);
float ObtenRestaPago(SiscomOperaciones *pSiscomOpePtrDato);
void EjecutaComandoImpresion4(SiscomOperaciones *,const char *pchrPtrArchivo);
void EjecutaComandoImpresion4ConMensaje(SiscomOperaciones *,
					const char *pchrPtrArchivo,
					const char *pchrPtrMensaje);
FILE *ArchivoImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato,
			     const char *pchrPtrArchivo);
const char *ObtenImpresoraParaTicket(SiscomOperaciones *pSiscomOpePtrDatos);
const char *TelefonoExpendio(SiscomOperaciones *pSiscomOpePtrDato);
void TextoWhatsApp(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTextoImpresion);
void TextoRifa(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto);
#endif
