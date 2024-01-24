#ifndef __RNDLLCONSULTAS_H__
#define __RNDLLCONSULTAS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int RNDllCNSIdentificaConsulta(PARDEPURACION int ,int[],int,char *,STRUCTError *);
int RNDllCNSConsultaProductos(PARDEPURACION int,int [],char *,STRUCTCantidadYProducto *,int,char *,STRUCTError *);
int RNDllCNSConsultaCompras(PARDEPURACION int,int [],char *,int ,char *,STRUCTError *);
int RNDllCNSFormaCamposConsulta(PARDEPURACION char *,char *,STRUCTCantidadYProducto *,STRUCTError *);
int RNDllCNSEliminaFechasDuplicadas(PARDEPURACION STRUCTLtaCompras **,int *);
int RNDllCNSObtenCantidad(PARDEPURACION char *,STRUCTCantidadYProducto *);
int RNDllCNSCotizaOrden(PARDEPURACION int,int [],char *,STRUCTCantidadYProducto *,int,char *,STRUCTError *);
int RNDllCNSObtenPrecios(PARDEPURACION STRUCTLtaCompras *,STRUCTLtaCompras **,int *,STRUCTError *);
int RNDllCNSEnviaCotizacion(PARDEPURACION int ,STRUCTLtaCompras *,STRUCTCantidadYProducto *,int ,STRUCTError *);
#endif 
