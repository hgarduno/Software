#ifndef __IMPRESION_H__
#define __IMPRESION_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpImprimeTicketVenta();
void ImprimeTicketVenta(SArgsSiscom *);
void RegistraTicketVenta(SArgsSiscom *);
void ArgumentosTicketVenta(SArgsSiscom *);
char *TextoImpresion(SArgsSiscom *,int *);
#endif
