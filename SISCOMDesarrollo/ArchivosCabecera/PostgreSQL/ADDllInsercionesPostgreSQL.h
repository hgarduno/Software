#ifndef __ADDLLINSERCIONESPOSTRESQL_H__
#define __ADDLLINSERCIONESPOSTRESQL_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
#include <libpq-fe.h>
int POSTGRESQLInsertaProductos(PARDEPURACION STRUCTDatosDeLaOperacion ,STRUCTLtaProductos *,STRUCTLtaErrorAltaProductos **);
int POSTGRESQLInsertaCompras(PARDEPURACION STRUCTDatosDeLaOperacion ,STRUCTLtaCompras *,STRUCTLtaCompras **,int *);
//int POSTGRESQLConectate(PARDEPURACION PGconn **,STRUCTError *);
int POSTGRESQLActualizaInventarioXCompras(PARDEPURACION PGconn *,STRUCTCompras,STRUCTError *);
#endif 
