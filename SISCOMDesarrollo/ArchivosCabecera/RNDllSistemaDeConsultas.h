#ifndef __RNDLLSISTEMADECONSULTAS_H__
#define __RNDLLSISTEMADECONSULTAS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int RNDllCNSConsultaProductos(PARDEPURACION int,int [],char *,int,char *,STRUCTError *);
int RNDllCNSConsultaCompras(PARDEPURACION int,int [],char *,int ,char *,STRUCTError *);
int RNDllCNSFormaCamposConsulta(PARDEPURACION char *,int *,char *,STRUCTCantidadYProducto *,STRUCTError *);
int RNDllCNSEliminaFechasDuplicadas(PARDEPURACION STRUCTLtaCompras **,int *);
int RNDllCNSObtenCantidad(PARDEPURACION char *,STRUCTCantidadYProducto *);
int RNDllCNSCotizaOrden(PARDEPURACION int,int [],char *,int,char *,STRUCTError *);
int RNDllCNSObtenPrecios(PARDEPURACION STRUCTLtaCompras *,STRUCTLtaCompras **,int *,STRUCTError *);
int RNDllCNSEnviaCotizacion(PARDEPURACION int ,STRUCTLtaCompras *,STRUCTCantidadYProducto *,int ,STRUCTError *);
int RNDllCNSConsultaClientes(PARDEPURACION int ,int [],char *,int  ,char *,STRUCTError *);
int RNDllCNSConsultaEstGananciaNDisp(PARDEPURACION int ,int [],char *,int  ,char *,STRUCTError *);
#endif 
