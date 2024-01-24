#ifndef __RNADFUNCIONESCOMUNESEZS_H__
#define __RNADFUNCIONESCOMUNESEZS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>

typedef struct STRUCTVentas
	{
	 char chrArrFechaVenta[100];
	 char chrArrCveVenta[100];
	 char chrArrCveProducto[100];
	 char chrArrCantidad[100];
	 char chrArrCveCliente[100];
	 char chrArrPUnitario[100];
	 char chrArrPTotal[100];
	 char chrArrNOrden[100];
	}STRUCTVentas;

typedef struct STRUCTLtaVentas
	{
	 STRUCTVentas stcVentas;
	 struct STRUCTLtaVentas *stcLtaVentasPtrSig;
	}STRUCTLtaVentas;

int RNADAsignaMemoriaVentas(PARDEPURACION STRUCTVentas, STRUCTLtaVentas **, STRUCTError *);
int RNADGeneraListaVentas(PARDEPURACION int,int *,STRUCTLtaVentas **,STRUCTError *);
int RNADCreaListaDeVentas(PARDEPURACION STRUCTVentas, STRUCTLtaVentas **, STRUCTLtaVentas **, STRUCTError *);
int RNADFormaCadenaVentas(PARDEPURACION STRUCTLtaVentas *, char **, STRUCTError *);
int RNADLlenaVentas(PARDEPURACION char *,char *, char *, char *, char *, char *, char *, char *, STRUCTVentas *);
int RNADEnviaRegistrosDeVentas(PARDEPURACION int, int, int, STRUCTLtaVentas *, STRUCTError *);
int RNADObtenRegistroDeVentas(PARDEPURACION int, STRUCTVentas *, STRUCTError *);
	
#endif
