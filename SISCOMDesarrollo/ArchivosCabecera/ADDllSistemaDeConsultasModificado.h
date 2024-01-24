#ifndef __ADDLLSISTEMADECONSULTASMODIFICADO_H__
#define __ADDLLSISTEMADECONSULTASMODIFICADO_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int ADDllCNSProductos(PARDEPURACION int,char ***,STRUCTError *);
int ADDllCNSFormaCadenaConsulta(PARDEPURACION int ,char **,char *);
int ADDllCNSCompras(PARDEPURACION int,char ***,STRUCTError *);
int ADDllCNSClientes(PARDEPURACION int,char ***,STRUCTError *);
int ADDllCNSEstGananciasNDisp(PARDEPURACION int, char ***,STRUCTError *);
int ADDllCNSFormaCadenaConsultaCompras(PARDEPURACION char *,char *);
int ADDllCNSFormaCadenaCotizacion(PARDEPURACION int,char **,char *);
#endif 
