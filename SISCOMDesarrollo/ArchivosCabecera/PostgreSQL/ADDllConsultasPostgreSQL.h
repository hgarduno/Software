#ifndef __ADDLLCONSULTASPOSTGRESQL_H__
#define __ADDLLCONSULTASPOSTGRESQL_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
#include <ADFuncionesComunesPostgreSQL.h>
int ADDllConsultasPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion ,char *,STRUCTLtaProductos **,int *,int *,STRUCTError *);
int ADDllConsultaComprasPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCompras **,int *,int *,STRUCTError *);
int ADDllConsultaClientesPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCliente **,int *,int *,STRUCTError *);
#endif 
