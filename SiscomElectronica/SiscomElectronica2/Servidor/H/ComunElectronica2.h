#ifndef __COMUNELECTRONICA2_H__
#define __COMUNELECTRONICA2_H__
#include <SiscomDesarrollo2.h>
/*
 * Esta funcion obtendra los datos de comunicacion
 * para el expendio apartir de la funcion
 * ElectronicaComunicacionExpendio2,
 * para esto se requiere que en el campo
 * chrPtrArgumentos, en el indice # 1 del
 * arreglo se coloque el idExpendio, para que
 * se pueda copiar a los campos de las estructura
 * SArgsSiscom los datos de comunicacion
 *
 *
 *
 */
void ComunicacionExpendioConsulta(SArgsSiscom *);
void ComunicacionExpendio(const char *pchrPtrIdExpendio,
			  SArgsSiscom *pSAgsSiscom);
void SiscomComunicacionMatriz(SArgsSiscom *pSAgsSiscom);

/* Esta funcion copiara los datos del servidor
 * de acceso a datos, pero debera contene en el
 * registro de entrad un campo con nombre IdExpendio
 *
 */
void ComunicacionExpendioRegistra(SArgsSiscom *);

void ComunicacionExpendio3(SArgsSiscom *);
void SemestreAnterior(char *pchrPtrFechaIni,
		      char *pchrPtrFechaFin);
void SemestreActual(char *pchrPtrFechaIni,
		      char *pchrPtrFechaFin);


void SiscomComunicacionExpendio2(const char *pchrPtrIdExpendio,
				     int *pintPtrPtoCom,
				     char *pchrPtrDirIpSvr,
				     char *pchrPtrBaseDatos);

void SiscomDatosComunicacionMatriz(int *pintPtrPtoCom,
			      char *pchrPtrDirIpSvr,
			      char *pchrPtrBaseDatos);

void SiscomDatosComunicacionMatriz2(int *pintPtrPtoCom,
			      char *pchrPtrDirIpSvr,
			      char *pchrPtrBaseDatos,
			      char *pchrPtrIdMatriz);

void SqlAExpendioAsignaArgumento(const char *pchrPtrIdExpendio,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrSql,
				     SArgsSiscom *pSAgsSiscom);

/* Toma los datos de pchrPtrArgumento de SArgsSiscom, y los
 * envia al servidor con id pchrPtrIdExpendio. el resultado 
 * de la insercion lo deja en LCSiscomPro2Regreso
 */
const char *SqlEnviaSentenciasArgumento(const char *pchrPtrIdExpendio,
				 const char *pchrPtrArgumento,
				 SArgsSiscom *pSAgsSiscom);


void SqlEnviaSentenciasCampoRegreso(const char *pchrPtrIdExpendio,
				 SArgsSiscom *pSAgsSiscom);

/* Viernes 20 de Diciembre del 2013 
 * Para poder realizar las inserciones en todas las tablas 
 * de un producto nuevo, o en este caso para la sincronizacion
 * de los expendios se desarrolla la siguiente funciona que tomara
 * como entrada en pLCSiscomPro2Dat los productos que se requieren
 * registrar en el Sistema, y dejara en los argumentos de la lista
 * las sentencias sql necesarias para insertar en cada una de las
 * tablas.
 * Los campos de cada producto que se necesita registrar deberan
 *
 * La funcion solo genera las inserciones cuando es un expendio, 
 * por lo que las inserciones para bodegas por ejemplo , no son
 * consideradas.
 */
void SqlGenerandoProductosSiscomExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql);


void SqlInsertIntoProductosSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql);
void SqlInsertIntoPreciosSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql);
void SqlInsertIntoExistenciasSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql);

#endif
