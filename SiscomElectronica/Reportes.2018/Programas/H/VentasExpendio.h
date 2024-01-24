#ifndef __VENTASEXPENDIO_H__
#define __VENTASEXPENDIO_H__
#include <SiscomFuncionesComunes.h>
#include <SiscomLineaComandos.h>
#include <SiscomErrores.h>
#include <PostgresAccesoDatos.h>




void ArgumentosVentasExpendio(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones);
int CualReporteEjecuta(StcSiscomOpciones *pStcPtrSisOpciones);
void ModoUsoComparacionPeriodo();
#endif
