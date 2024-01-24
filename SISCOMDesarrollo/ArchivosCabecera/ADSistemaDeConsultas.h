#ifndef __SISTEMADECONSULTAS_H__
#define __SISTEMADECONSULTAS_H__
#include <EstructurasSISCOM.h>
tydef struct STRUCTListaProcesosYDll
{
STRUCTProcesosYDll strProcesosYDllDat;	
struct STRUCTListaProcesosYDll *strListaSig;

}STRUCTListaProcesosYDll;
tydef struct STRUCTRealizaConsultas
{
	void *ObtenDatos;
	void *EjecutaConsulta;
	void *RespondeConsulta;

}STRUCTRealizaConsultas;
int ADLeeArgumentosSistemaDeConsultas(int ,char **,int *,char *,STRUCTError *);	
int ADRealizaConsulta(int,char *,STRUCTError *);
int ADObtenDatosConsultaProcesosYDll(int,int *,STRUCTError *);
int ADRespondeConsultaProcesosYDll(int,STRUCTListaProcesosYDll *,STRUCTError *);

int (*SISCOMEjecutaConsulta)(int,STRUCTListaProcesosYDll **,STRUCTError *);

#endif 
