#ifndef __ADllREALIZAALTADEPRODUCTOS_H__
#define __ADllREALIZAALTADEPRODUCTOS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int ADDllRealizaAltaCompras(PARDEPURACION int ,int [],int,char *);
int  ADDllRealizaAltaDeProductos(PARDEPURACION int ,int[],int,char *);
int ADDllInsertaDatos(PARDEPURACION STRUCTDatosDeLaOperacion ,STRUCTLtaProductos *,STRUCTLtaErrorAltaProductos **);

#endif 
