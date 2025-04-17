#ifndef __ADPROCESOATIENDECLIENTE_H__
#define __ADPROCESOATIENDECLIENTE_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int ADLeeArgumentosProcesoAtiendeCliente(PARDEPURACION int,char **,int *,STRUCTError *);
int ADCargaDllYEjecutaFuncion(PARDEPURACION char *,char *,int,STRUCTError *);
int ADObtenNombreDllYFuncion(PARDEPURACION int ,char *,char *,STRUCTError *);
int ADCopiaDatosDeLaOperacionALaTuberia(PARDEPURACION int ,STRUCTDatosDeLaOperacion ,STRUCTError *);
int ADLeeArgumentosProcesosAtiendeCliente(PARDEPURACION int pintArgc,char **pchrPtrArgv,int *pintPtrSocket,STRUCTError *pstcErrorPtrReg);
#endif 
