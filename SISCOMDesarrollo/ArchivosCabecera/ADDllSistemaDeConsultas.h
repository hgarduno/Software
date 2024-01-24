#ifndef __ADDLLSISTEMADECONSULTAS_H__
#define __ADDLLSISTEMADECONSULTAS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int ADDllCNSIdentificaConsulta(PARDEPURACION int ,int [],int ,char *);
int ADDllCNSProductos(PARDEPURACION int,char *,STRUCTError *);
int ADDllCNSFormaCadenaConsulta(PARDEPURACION int ,char **,char *);
int ADDllCNSCompras(PARDEPURACION int,char *,STRUCTError *);
int ADDllCNSFormaCadenaConsultaCompras(PARDEPURACION char *,char *);
int ADDllCNSFormaCadenaCotizacion(PARDEPURACION int,char **,char *);
#endif 
