#ifndef __COMPRAIMPORTACION_H__
#define __COMPRAIMPORTACION_H__


#include <SiscomFuncionesComunes.h>
#include <SiscomErrores.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomLineaComandos.h>
#include <stdio.h>
FILE *ObtenArchivo(const char *);
int LeyendoEntrada(FILE *pFlePtrArchivo,
		   SiscomRegistroProL **pSisRegProLPtrComImportacion,
		   SiscomRegistroProL **pSisRegProLPtrDetComImportacion);
void ObtenDatosImportacion(const char *pchrPtrNmbCampos,
			   FILE *pFlePtrArchivo,
			   SiscomRegistroProL **pSisRegProLPtrPrim,
			   SiscomRegistroProL **pSisRegProLPtrAct);
SiscomCampoProL *FormaRegistro(char **pchrPtrNmbCampos, char **pchrPtrDatos);
void RegistroDetalleCompraImportacion(FILE *pFlePtrArchivo,
				      const char *pchrPtrLinea,
				      SiscomRegistroProL **pSisRegProLPtrPrimDetCompra,
				      SiscomRegistroProL **pSisRegProLPtrActDetCompra);
SiscomCampoProL *FormaRegistroDetalleCompra(char **pchrPtrProducto,char **pchrPtrDatos);
void GeneraSentenciasSql(const char *pchrPtrIdProveedor,SiscomRegistroProL *,SiscomRegistroProL *);
const char *EstaClaveProducto(const char *pchrPtrLinea);
#endif
