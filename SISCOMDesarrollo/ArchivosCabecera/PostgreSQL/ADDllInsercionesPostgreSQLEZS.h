#ifndef __ADDLLINSERCIONESPOSTRESQLEZS_H__
#define __ADDLLINSERCIONESPOSTRESQLEZS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
#include <RNADFuncionesComunesEZS.h>
#include <libpq-fe.h>
#include <ADFuncionesComunesPostgreSQL.h>
int POSTGRESQLInsertaVentas(PARDEPURACION STRUCTDatosDeLaOperacion, STRUCTLtaVentas *, STRUCTError *);
int POSTGRESQLActualizaInventarioXVenta(PARDEPURACION PGconn *, STRUCTVentas, STRUCTError *);
int POSTGRESQLActualizaOrden(PARDEPURACION PGconn *,STRUCTVentas,STRUCTError *);
int POSTGRESQLActualizaInventarioXVentas(PARDEPURACION PGconn *pPGconn, STRUCTVentas pstcVentasDat, STRUCTError *pstcErrorPtrReg);
#endif

