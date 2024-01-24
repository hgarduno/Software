#ifndef __OPCIONESDEPURACION_H__
#define __OPCIONESDEPURACION_H__
#ifdef DEBUG
#define PARDEPURACION char *pchrPtrTabulador,
#define PDEPURACION   pchrPtrTabulador,
#define DATODEP lchrArrRegreso,
#else
#define DATODEP
#define PDEPURACION
#define PARDEPURACION
#endif
#endif 
