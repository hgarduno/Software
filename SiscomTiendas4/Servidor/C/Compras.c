#include <Compras.h>
#include <SQLCompras.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OPDetalleCompra()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLDetalleCompra,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPCompras()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLCompras,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRegistraCompra()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosCompras,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraIdCompra,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLRegistraCompra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLProductosCotizando,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraCompras,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPUltimaCompraProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLUltimaCompraProducto,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosCompras(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLCompras",pSAgsSiscom);
}
void RegistraCompras(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"SQLCompras");
}
void GeneraIdCompra(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdCompra[20];
SiscomObtenNumeroUnicoChar(lchrArrIdCompra);
for(;
     lLCSiscomPro2Dat;
     lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
SiscomAsignaDatoCampo2("IdCompra",lchrArrIdCompra,lLCSiscomPro2Dat);
}
