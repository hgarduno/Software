#ifndef __SISCOMRECIBEARCHIVO_H__
#define __SISCOMRECIBEARCHIVO_H__

typedef  struct SiscomArchivoProtocolo
{
int intTamanoBloque;
unsigned char *chrPtrBloque;
}SiscomBloqueArchivo;

typedef struct ListaBloqueArchivo
{
 SiscomBloqueArchivo zSiscomBloqueArchivo;
 struct ListaBloqueArchivo *SiscomBloArcPtrSig;
 int intNBloques;
}SiscomBloqueArchivoL;

void SiscomMemoriaNodoBloqueArchivo(const SiscomBloqueArchivo *pSiscomBloArcPtrDato,
				    SiscomBloqueArchivoL **pSiscomBloArcLPtrDato);

void SiscomRecibeArchivo(int pintSocket,
			 SiscomBloqueArchivoL **pSiscomBloArLPtrArchivo);
void SiscomNodoBloqueArchivo(const SiscomBloqueArchivo *pSiscomBloArPtrDato,
			     SiscomBloqueArchivoL **pSiscomBloArLPtrPrim,
			     SiscomBloqueArchivoL **pSiscomBloArLPtrAct);
void SiscomEscribeArchivoSocket(const char *pchrPtrNombre,
				SiscomBloqueArchivoL *pSiscomBloArLPtrDato);

int SiscomTamanoBloque(SiscomBloqueArchivoL *pSiscomBloArLPtrDato);
const unsigned char *SiscomDatoBloqueArchivo(SiscomBloqueArchivoL *pSiscomBloArLPtrDato);
int SiscomNumeroBloques(SiscomBloqueArchivoL *pSiscomBloArLPtrDato);
#endif
