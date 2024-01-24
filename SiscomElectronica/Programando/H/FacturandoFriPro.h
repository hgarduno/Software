#ifndef __FACTURANDOFRIPRO_H__
#define __FACTURANDOFRIPRO_H__
#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomLineaComandos.h>
#include <stdio.h>

void FacturandoFriPro(StcSiscomOpciones *pStcPtrSisOpciones,SiscomRegistroProL *);
void ImportesFactura(StcSiscomOpciones *pStcPtrSisOpciones,
		     float *pfltPtrIva,
		     float *pfltPtrImporte,
		     float *pfltPtrTotal);

void FormaArchivoSiscomFactura(StcSiscomOpciones *pStcPtrSisOpciones,
				const char *pchrPtrFechaHora,
				const char *pchrPtrImporteLetra,
			       float pfltIva,
			       float pfltImporte,
			       float pfltTotal);
void FormaArchivoSiscomFacturaGeneral(StcSiscomOpciones *pStcPtrSisOpciones,
				SiscomRegistroProL *pSisRegProLConfig,
				const char *pchrPtrFechaHora,
				const char *pchrPtrImporteLetra,
			       float pfltIva,
			       float pfltImporte,
			       float pfltTotal);

const char *RfcAmbiente(StcSiscomOpciones *pStcPtrSisOpciones);
const char *RfcSiscomProduccion();
const char *RfcSiscomPruebas();

void EjecutandoFacturacion(StcSiscomOpciones *pStcPtrSisOpciones,
			   SiscomRegistroProL *pSisRegProLPtrConfig,
			   const char *);
const char *ComandoFacturacion(StcSiscomOpciones *pStcPtrSisOpciones,
				SiscomRegistroProL *pSisRegProLConfig,
				const char *pchrPtrPrefijoArchivo);


const char *ServidorTimbrado(StcSiscomOpciones *pStcPtrSisOpciones);
const char *UsuarioTimbrado(StcSiscomOpciones *pStcPtrSisOpciones);

const char *UsuarioTimbradoProduccion();
const char *ServidorTimbradoProduccion();

const char *UsuarioTimbradoPruebas();
const char *ServidorTimbradoPruebas();
void MensajesEjecucion(FILE *pFlePtrEjecucion);

#endif
