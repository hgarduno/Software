#ifndef __SISCOMTRANSFORMAIMPORTEALETRA_H__
#define __SISCOMTRANSFORMAIMPORTEALETRA_H__

typedef struct ImporteALetra
{
   char *chrArrLetra[10];

}StcImporteALetra;

void SiscomTransformaImporteALetra(const char *pchrPtrImporte,
				    char *pchrPtrImporteALetra);

void SiscomTransformaImporteALetraFloat(float pfltImporte,
				   char *pchrPtrImporteALetra);

void ObtenNoEnterosImporte(const char *pchrPtrImporte,
			   int *pintPtrNoEnteros,
			   int *pintPtrNoDecimales,
			   int *pintPtrImporte,
			   int *pintPtrDecimal);

void DescomponImporte(int pintImporte,
		      int pintNoEnteros,
		      int *pintPtrDescompuesto);

void ObtenLetraPosicionNumero(int pintPosicion,
			      int pintNumero,
			      char *pchrPtrLetra);
#endif
