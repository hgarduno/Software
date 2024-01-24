#include <Productos.h>
#include <SQLProductos.h>
#include <ComunSiscomTiendas4.h>

#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OperacionesProductos()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosProductos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CambiaMayusculasClave,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraIdProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLRegistraProductos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraFamiliaProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraProducto,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *ProductosRegistrados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
/*
 * Por alguna extrana razon, si quito la impresion del
 * rotulo de la siguiente linea de codigo, el sistema truena
 *
 * Queretaro 05/06/2008
 *
 *
 *
 *
 */
/*
SiscomMensajesLog2("Productos.c -> ProductosRegistrados");

*/
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLProductosRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OperacionesActualizaProductos()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosProductos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CambiaMayusculasClave,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLActualizaProductos,lSOpOperaciones);  
SiscomAnexaOperacionAlArreglo2(SQLActualizaFamiliaProductos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(RegistraProducto,lSOpOperaciones); 
return lSOpOperaciones;
}
void ArgumentosProductos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Productos",pSAgsSiscom);
}
void CambiaMayusculasClave(SArgsSiscom *pSAgsSiscom)
{
CambiaCampoProtocoloMayusculas(pSAgsSiscom->LCSiscomPro2Dat,"Clave");
}
void RegistraProducto(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"Productos");
}

void GeneraIdProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Contador;
char lchrArrIdProducto[12];

for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
	SiscomObtenNumeroUnicoChar(lchrArrIdProducto);
	SiscomAsignaDatoCampo2("IdProducto",lchrArrIdProducto,lLCSiscomPro2Contador);
}
}
