#ifndef __RNDLLALTAPRODUCTOS_H__
#define __RNDLLALTAPRODUCTOS_H__
#include <RNADFuncionesComunes.h>	
	int RNDLLObtenDatosAltaProducto(int ,STRUCTLtaProductos **,STRUCTError *);	
	int RNDLLValidaDatosAltaProducto(STRUCTLtaProductos *);
	int RNDLLEnviaDatosAlServidorAD(int ,char *,char *,STRUCTError *);
	int RNDllUneEncabezadoYProductos(int ,char *,char *,STRUCTError *);
int RNDllEnviaDatosAlServidorAD(PARDEPURACION int pintPuerto,char *pchrPtrDirIPSAD,STRUCTLtaProductos *pstcLtaProductosPtrDat,int pintNRegistros,char *pchrPtrEncabezado,STRUCTError *pstcErrorPtrReg);
#endif 
