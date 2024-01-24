#ifndef __PDFFACTURA_H__
#define __PDFFACTURA_H__

#include <hpdf.h>
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

typedef struct siscomPdfHaruTexto
{
int intX;
int intY;
int intTamano;
const char *chrPtrTipoLetra;
const char *chrPtrTexto;
HPDF_Doc HpdfDocPtrArchivo;
HPDF_Page HpdfPagePtrPagina;
}SiscomHaruTexto;

typedef struct siscomPdfHaruColumna
{
    int intX;
    int intY;
    int intTamano;
    const char *chrPtrTipoLetra;
    const char *chrPtrTexto;
    int intTamColumna;
    HPDF_Doc HpdfDocPtrArchivo;
    HPDF_Page HpdfPagePtrPagina;
}SiscomHaruColumna;
    
int PdfFacturaSiscomElectronica(SiscomOperaciones *pSisOpePtrDato);

void SiscomPdfTexto(int pintX,
		    int pintY,
		    const char *pchrPtrLetra,
		    int pintTamano,
		    HPDF_Doc pHpdfDocPtrArchivo,
		    HPDF_Page pHpdfPagePtrPagina,
		    const char *pchrPtrTexto);

void SiscomHaruEscribe(SiscomHaruTexto *,const char *);
SiscomRegistroProL *SiscomHaruTabla(SiscomHaruColumna *pSisHaruColumnas,
		     const char *pchrPtrCampos[],
		     SiscomRegistroProL *pSisRegProLPtrDatos,
		     int *);

#endif
