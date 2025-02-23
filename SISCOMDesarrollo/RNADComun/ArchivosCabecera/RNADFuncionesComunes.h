#ifndef __RNADFUNCIONESCOMUNES_H__
#define __RNADFUNCIONESCOMUNES_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#define NODATOSOPERACION 5
typedef struct STRUCTDatosDeLaOperacion 
{
       char chrArrMovimiento[11];
       char chrArrUsuario[21];
       char chrArrPassword[21];
       char chrArrNomDll[126];
       char chrArrNomFuncion[126];

}STRUCTDatosDeLaOperacion;
typedef struct STRUCTProductos
{
	char chrArrClaveProd[51];
	char chrArrNomDelProducto[51];
	char chrArrClaveProv[51];
	char chrArrDescProd[91];
        char chrArrCantidad[11];
}STRUCTProductos;
typedef struct STRUCTLtaProductos
{
	STRUCTProductos stcProductosDat;
	struct STRUCTLtaProductos *stcLtaProductosSig;

}STRUCTLtaProductos;
typedef struct STRUCTLtaErrorAltaProductos
{
	STRUCTError stcErrorDat;
	STRUCTProductos stcProductosDat;
	struct STRUCTLtaErrorAltaProductos *stcLtaErrorAltaProductosSig;
}STRUCTLtaErrorAltaProductos;
typedef struct STRUCTCompras
{
	char chrArrCveProducto[51];
	char chrArrCveProveedor[16];
	char chrArrPVenta[16];
	char chrArrPCompra[16];
	char chrArrCveVendedor[51];
	char chrArrCantidad[11];
	char chrArrFechaCompra[25];
	char chrArrFormaDePago[51];
	char chrArrPMayoreo[16];	
	char chrArrExistencia[256];	
}STRUCTCompras;
typedef struct STRUCTLtaCompras
{
	STRUCTCompras stcCompras;
	struct STRUCTLtaCompras *stcLtaComprasPtrSig;
}STRUCTLtaCompras;
typedef struct
{
	int intCantidad;
	char chrTipoPrecio;
	char chrArrCveProducto[51];

}STRUCTCantidadYProducto;
typedef struct
{
	char chrArrCveProducto[51];
	char chrArrCantidad[11];
	char chrArrCostoUnitario[16];
	char chrArrCostoTotal[16];
	char chrArrImporteTotal[16];
	char chrArrPMayoreo[16];
	char chrArrExistencia[11];

}STRUCTCotizacion;
typedef struct STRUCTLtaCotizacion
{
	STRUCTCotizacion stcCotizacionDat;
	struct STRUCTLtaCotizacion *stcLtaCotizacionPtrSig;

}STRUCTLtaCotizacion;
typedef struct STRUCTCliente
{
	char chrArrCveCliente[51];
	char chrArrNmbCliente[51];
	char chrArrDirCliente[257];
}STRUCTCliente;
typedef struct STRUCTLtaCliente
{
	STRUCTCliente stcClienteDat;
	struct STRUCTLtaCliente *stcLtaClienteSig;

}STRUCTLtaCliente;
typedef struct EstGananciaNDisp
{
	char chrArrCveProducto[50];
	char chrArrNoDispositivos[25];
	char chrArrGanancia[25];

}STRUCTEstGananciaNDisp;
typedef struct STRUCTLtaEstGananciaNDisp
{
	STRUCTEstGananciaNDisp stcEstGananciaNDispDat;
	struct 	STRUCTLtaEstGananciaNDisp *stcLtaEstGananciaNDispSig;
}STRUCTLtaEstGananciaNDisp;
int RNADObtenDllConsultaYFuncion(PARDEPURACION char *,char *,char *);
int RNADCargaDllYEjecutaFuncion(PARDEPURACION char *,char *,int,int[],int,char *,STRUCTError *);
int RNADLeeDatosDeLaOperacion(PARDEPURACION int,STRUCTDatosDeLaOperacion *,STRUCTError *);
int RNADObtenDatosAltaProducto(PARDEPURACION int ,int *,STRUCTLtaProductos **,STRUCTError *);
int RNADAsignaMemoriaLtaProducto(PARDEPURACION STRUCTLtaProductos **,STRUCTProductos ,STRUCTError *);
int RNADObtenDatoDelProducto(PARDEPURACION int ,STRUCTProductos *,STRUCTError *);
int RNADCreaListaDatosDelProducto(PARDEPURACION STRUCTProductos ,STRUCTLtaProductos **,STRUCTLtaProductos **,STRUCTError *);
int RNADFormaCadenaEncabezado(PARDEPURACION char *,char *,char *,char *,char *,char *);
int RNADFormaCadenaConsultaYConsultaSVR(PARDEPURACION int,char *,char *,char *,char *,char *,char *,int *);
int RNADFormaCadenaYRealizaAltaSVR(PARDEPURACION int ,char *,char *,char *,char *,char *,char *,int *);

//int RNADEnvia
int RNADFormaCadenaDatosDeLaOperacion(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTError *);
int RNADCopiaDatosDelProducto(PARDEPURACION char *,char *,char *,char *,STRUCTProductos *);
int RNADFormaCadenaAltaProductos(PARDEPURACION STRUCTLtaProductos *,int pintNRegistros,char *,STRUCTError *);
int RNADImprimeSTRUCTDatosDeLaOperacion(STRUCTDatosDeLaOperacion );
int RNADImprimeSTRUCTProductos(STRUCTProductos);
int RNADImprimeSTRUCTLtaProductosPtr(STRUCTLtaProductos *);
int RNADImprimeSTRUCTProductosPtr(STRUCTProductos *);
int RNADLeeCabeceraProtocolo(PARDEPURACION int ,char *);
int RNADFormaCadenaProtocoloXRegistroProducto(PARDEPURACION STRUCTProductos ,char *,STRUCTError *);
int RNADAsignaMemoriaErrorAltaProductos(PARDEPURACION STRUCTLtaErrorAltaProductos **,STRUCTError ,STRUCTProductos );
int RNADAnexaErrorALaLista(PARDEPURACION STRUCTLtaErrorAltaProductos **, STRUCTLtaErrorAltaProductos **,STRUCTError ,
			   STRUCTProductos);
int RNADEnviaErroresAlSvr(PARDEPURACION int,STRUCTLtaErrorAltaProductos *);

int RNADAsignaMemoriaCompras(PARDEPURACION STRUCTCompras,STRUCTLtaCompras **,STRUCTError *);
int RNADCreaListaDeCompras(PARDEPURACION STRUCTCompras ,STRUCTLtaCompras **,STRUCTLtaCompras **,STRUCTError *);
int RNADFormaCadenaCompras(PARDEPURACION STRUCTLtaCompras *,char **,STRUCTError *);
int RNADLlenaCompras(PARDEPURACION char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,STRUCTCompras *);
int RNADAsignaMemoriaCharPtr(PARDEPURACION char **,int ,STRUCTError *);
int RNADEnviaRegistrosDeCompras(PARDEPURACION int,int ,int ,STRUCTLtaCompras *,STRUCTError *);
int RNADObtenRegistroDeCompras(PARDEPURACION int ,STRUCTCompras *,STRUCTError *);
int RNADGeneraListaCompras(PARDEPURACION int ,int *,STRUCTLtaCompras **,STRUCTError *);

int RNADAsignaMemoriaLtaCotizacion(PARDEPURACION STRUCTCotizacion ,STRUCTLtaCotizacion **,STRUCTError *);
int RNADCreaListaCotizacion(PARDEPURACION STRUCTCotizacion ,STRUCTLtaCotizacion **,STRUCTLtaCotizacion **,STRUCTError *);
int RNADEnviaCotizacion(PARDEPURACION int,int,int,STRUCTLtaCotizacion *,STRUCTError *);
int RNADGeneraListaCotizacion(PARDEPURACION int,int *,STRUCTLtaCotizacion **,STRUCTError *);
int RNADLlenaCotizacion(PARDEPURACION STRUCTCompras,STRUCTCantidadYProducto ,STRUCTCotizacion *,float *,STRUCTError *);
int RNADObtenRegistroCotizacion(PARDEPURACION int,STRUCTCotizacion *,STRUCTError *);

int RNFormaCadenaTipoDePrecio(char *,char *);
int RNADFechasDelPrecio(PARDEPURACION char *,char *);
int RNADRegistroVacioCompras(PARDEPURACION int);

int RNADLlenaCliente(PARDEPURACION char *,char *,char *,STRUCTCliente *);
int RNADAsignaMemoriaLtaCliente(PARDEPURACION STRUCTCliente ,STRUCTLtaCliente **);
int RNADCreaLtaCliente(PARDEPURACION STRUCTCliente, STRUCTLtaCliente **,STRUCTLtaCliente **);
int RNADObtenRegistroCliente(PARDEPURACION int ,STRUCTCliente *);
int RNADGeneraLtaCliente(PARDEPURACION int,int *,STRUCTLtaCliente **);
int RNADEnviaClientes(PARDEPURACION int,int,int,STRUCTLtaCliente *);

int RNADLlenaStcEstGananciaNDisp(PARDEPURACION char *,char *,char *,STRUCTEstGananciaNDisp *);
int RNADAsignaMemoriaLtaEstGananciaNDisp(PARDEPURACION STRUCTEstGananciaNDisp,STRUCTLtaEstGananciaNDisp **);
int RNADCreaLtaEstGananciaNDisp(PARDEPURACION STRUCTEstGananciaNDisp,STRUCTLtaEstGananciaNDisp **,STRUCTLtaEstGananciaNDisp **);
int RNADObtenRegistroLtaEstGananciaNDisp(PARDEPURACION int,STRUCTEstGananciaNDisp *);
int RNADGeneraLtaEstGananciaNDisp(PARDEPURACION int,int *,STRUCTLtaEstGananciaNDisp **);
int RNADEnviaLtaEstGananciaNDisp(PARDEPURACION int,int,int,STRUCTLtaEstGananciaNDisp *);
int RNADEnviaDatosDelProducto(PARDEPURACION int pintSocketCliente,int pintNRegistros,int pintNCampos,STRUCTLtaProductos *pstcLtaProductosPtrLta,STRUCTError *pstcErrorPtrReg);

int RNADFormaProtocoloEncabezado(PARDEPURACION int pintPipe,STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionReg,STRUCTError *pstcErrorReg);
#endif
