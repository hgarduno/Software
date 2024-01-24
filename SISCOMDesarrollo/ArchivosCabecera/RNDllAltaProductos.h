#ifndef __RNDLLALTAPRODUCTOS_H__
#define __RNDLLALTAPRODUCTOS_H__
#include <RNADFuncionesComunes.h>	
	int RNDLLObtenDatosAltaProducto(int ,STRUCTLtaProductos **,STRUCTError *);	
	int RNDLLValidaDatosAltaProducto(STRUCTLtaProductos *);
	int RNDLLEnviaDatosAlServidorAD(int ,char *,char *,STRUCTError *);
	int RNDllUneEncabezadoYProductos(int ,char *,char *,STRUCTError *);
#endif 
