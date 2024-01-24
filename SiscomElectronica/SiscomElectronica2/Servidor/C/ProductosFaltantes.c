#include <ProductosFaltantes.h>
#include <SqlProductosFaltantes.h>
#include <ComunElectronica2.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OpProductosFaltantes()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*10);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*10);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosProductosFaltantes,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlProductosFaltantes,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaProductosFaltantes,lSOpOperaciones); 
return lSOpOperaciones;
}

void ArgumentosProductosFaltantes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductosFaltantes",pSAgsSiscom);
}

void EnviaProductosFaltantes(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentoCliente("SqlProductosFaltantes",pSAgsSiscom);
SiscomImprimeArgumento("SqlProductosFaltantes",pSAgsSiscom);
}
