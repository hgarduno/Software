#ifndef __COTIZACIONIMPORTACION_H__
#define __COTIZACIONIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistrandoCotizacionImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void ConsultandoCotizacionImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraProductoCotizaImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void SeleccionoCotizaImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
int RegistraCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int ConsultaCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoProductoCotizaImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int CalculandoPrecioImporteProductosCotizados(SiscomOperaciones *pSiscomOpePtrDato);
int CalculandoImporteCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int CalculandoPesoCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int SeleccionandoCotizacionImportacion(SiscomOperaciones *pSiscomOpePtrDato);

#endif
