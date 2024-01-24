#ifndef __RNPROCESOATIENDE_H__
#define __RNPROCESOATIENDE_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
	int RNLeeParametrosAtiende(PARDEPURACION int ,char **,int *,unsigned long *,int *,char *,STRUCTError *);
	int RNIdentificaMovimiento(PARDEPURACION int,STRUCTProcesosYDll *,STRUCTProcesosYDll *,STRUCTError *);
	int RNLeeInformacionDeLaOperacion(PARDEPURACION int,STRUCTDatosDeLaOperacion *,STRUCTError *);
	int RNMemoriaSHM(PARDEPURACION unsigned long,STRUCTProcesosYDll **,STRUCTError *);
	int RNBuscaMovimiento(PARDEPURACION STRUCTProcesosYDll *,int ,STRUCTProcesosYDll,STRUCTError *);
	int RNCopiaDllYFuncion(PARDEPURACION char *,char *,STRUCTDatosDeLaOperacion *);
	int RNCopiaDatosSTRUCTProcesosYDllASTRUCTDatosDeLaOperacion(PARDEPURACION STRUCTProcesosYDll ,STRUCTDatosDeLaOperacion *);
	
#endif 
