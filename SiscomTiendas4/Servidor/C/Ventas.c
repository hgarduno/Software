#include <Ventas.h>
#include <SQLVentas.h>
#include <stdlib.h>
#include <string.h>
#include <ComunSiscomTiendas4.h>
SiscomOperaciones2 *OPRegistraVenta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosVenta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ProcesoVentas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraVenta,lSOpOperaciones); 
return lSOpOperaciones;
}
void ArgumentosVenta(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLVenta",pSAgsSiscom);
}

void RegistraVenta(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"SQLVenta");  
}
StcProcesoVentas *ObtenPerfilProceso(StcProcesoVentas *pSPVentas,
				    LCamposSiscomPro2 *pLCSiscomPro2)
{
const char *lchrPtrEdoVenta=SiscomObtenDato(pLCSiscomPro2,"EdoVenta");
const char *lchrPtrTipoCliente=SiscomObtenDato(pLCSiscomPro2,"TipoCliente");
int lintContador;
SiscomLog("");
for(lintContador=0;
    (pSPVentas+lintContador)->chrPtrEdoVenta;
    lintContador++)
if(!strcmp(lchrPtrEdoVenta,(pSPVentas+lintContador)->chrPtrEdoVenta) &&
   (!strcmp(lchrPtrTipoCliente,(pSPVentas+lintContador)->chrPtrTipoCliente) ||
    !(pSPVentas+lintContador)->chrPtrTipoCliente[0]))
{
SiscomLog("El Perfil:%d",lintContador);
return (pSPVentas+lintContador);
}
return 0;
}
void ProcesoVentas(SArgsSiscom *pSAgsSiscom)
{
StcProcesoVentas lSPVentas[]={ { "0","Fisica",
			       {
			        SQLVenta,
			        SQLDetalleVenta,
				SQLVentaFisica,
				SQLActualizaInventarioVentas,
				SQLRemisionFactura,

				}
				},
				{"0","Moral",
				{
				SQLVenta,
			        SQLDetalleVenta,
				SQLVentaMoral,
				SQLActualizaInventarioVentas
				}
				},
			       { "1","Fisica",
			       {
			        SQLVenta,
			        SQLDetalleVenta,
				SQLVentaFisica
				}
				},
				{"1","Moral",
				{
				SQLVenta,
			        SQLDetalleVenta,
				SQLVentaMoral
				}
				},
				{"2","",
				{
				 SQLActualizaVenta,
				 SQLEliminaDetalleVenta,
				 SQLDetalleVenta
				 }
				 },
				{"3","",
				{
				 SQLMarcaComoVendida,
				 SQLActualizaInventarioVentas 
				 }
				 }
				};
int lintContador;
StcProcesoVentas *lSPVEjecuta=ObtenPerfilProceso(
				lSPVentas,	
				pSAgsSiscom->LCSiscomPro2Dat);
if(lSPVEjecuta)
for(lintContador=0;
    lSPVEjecuta->SQLVentas[lintContador];
    lintContador++)
  lSPVEjecuta->SQLVentas[lintContador](pSAgsSiscom);
 else
 SiscomLog("No Se encontro El Perfil Seleccionado");
}
