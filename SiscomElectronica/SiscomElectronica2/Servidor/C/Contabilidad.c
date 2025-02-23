#include <Contabilidad.h>
#include <SqlContabilidad.h>

#include <ComunElectronica2.h>
#include <string.h>

SiscomOperaciones2 *OpEjecutaContabilidad()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosContabilidad,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosVendidosFacturados,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlComprasProductosVendidos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EjecutaProcesoContable,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlInsertaResultadoContable,lSOpOperaciones2); 
SiscomAnexaOperacionAlArreglo2(RegistraCalculos,lSOpOperaciones2);

return lSOpOperaciones2;
}
void RegistraCalculos(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlResultados");
}
void ArgumentosContabilidad(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlVendidosFacturados",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlComprasProductos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"Resultados",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SqlResultados",pSAgsSiscom);
}
void AgrupaProductos(const char *pchrPtrArgumento,
		     SArgsSiscom *pSAgsSiscom,
		   LCamposSiscomPro2Agrupados **pLCSiscomPro2Agrupa)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom);
SiscomAgrupaListaPorCampoPro2("cveproducto",
			      lLCSiscomPro2Dat,
			      pLCSiscomPro2Agrupa);
}
void AgrupaProductosComprasVentas(
		SArgsSiscom *pSAgsSiscom,
		LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrVentas,
		LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrCompras)
{
AgrupaProductos("SqlVendidosFacturados",
		pSAgsSiscom,
		pLCSiscomPro2AgrVentas);
AgrupaProductos("SqlComprasProductos",
		pSAgsSiscom,
		pLCSiscomPro2AgrCompras);


}
int EsElProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat1,
		 LCamposSiscomPro2 *pLCSiscomPro2Dat2)
{
return !strcmp(SiscomObtenDato(pLCSiscomPro2Dat1,"cveproducto"),
	       SiscomObtenDato(pLCSiscomPro2Dat2,"CveProducto"));
}
void AgregaProductoCalculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			   LCamposSiscomPro2 **pLCSiscomPro2CalculoPrim,
			   LCamposSiscomPro2 **pLCSiscomPro2CalculoAct,
			   int *pintPtrNRegistrosCalculo)
{
/*
 * EdoCalculo 
 * por default es 0 -> si se realizo el calculo de las ganancias etc 
 *
 * Si es 1 -> No se realizo el calculo para no tener en las facturas
 * registradas compras 
 *
 * Si es 2 -> ... 
 */
SiscomAnexaRegistroPro2(pLCSiscomPro2CalculoPrim,
			pLCSiscomPro2CalculoAct,
			pintPtrNRegistrosCalculo,
			"IdProceso,		\
			 CveProducto,		\
			 Cantidad,		\
			 VentaTotal,		\
			 Ganancia,		\
			 Existencia,		\
			 ImporteExistencia,	\
			 EdoCalculo",
			 "0",
			 SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"),
			 "0",
			 "0",
			 "0",
			 "0",
			 "0",
			 "0");
}
float CantidadDisponibleCompra(LCamposSiscomPro2 *pLCSiscomPro2Compra)
{
return SiscomObtenCampoAFloat(pLCSiscomPro2Compra,"cantidad")-
       SiscomObtenCampoAFloat(pLCSiscomPro2Compra,"cuantostomo");
}
void ActualizaCuantosTomo(LCamposSiscomPro2 *pLCSiscomPro2Prod,
			  LCamposSiscomPro2 *pLCSiscomPro2ComprasProducto)
{
float lfltCantidad=SiscomObtenCampoAFloat(pLCSiscomPro2Prod,"cantidad");
float lfltCuantosTomo;
lfltCuantosTomo=SiscomObtenCampoAFloat(pLCSiscomPro2ComprasProducto,"cuantostomo")+
                lfltCantidad;

SiscomAsignaDatoCampoFloat2(pLCSiscomPro2ComprasProducto,
			    "cuantostomo",
			    lfltCuantosTomo);
}
void ActualizaGanancia(LCamposSiscomPro2 *pLCSiscomPro2Calculo,
		       LCamposSiscomPro2 *pLCSiscomPro2Vendido,
		       LCamposSiscomPro2 *pLCSiscomPro2CompraProducto)
{
float lfltGanancia=SiscomObtenCampoAFloat(pLCSiscomPro2Calculo,"Ganancia");
float lfltCalGanancia;
lfltCalGanancia=(SiscomObtenCampoAFloat(pLCSiscomPro2Vendido,"precio")-
                 SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"precio"))*
		 SiscomObtenCampoAFloat(pLCSiscomPro2Vendido,"cantidad");
lfltGanancia+=lfltCalGanancia;
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Calculo,	
			   "Ganancia",
			   lfltGanancia);
}
/*
void ActualizaImporteExistencia(LCamposSiscomPro2 *pLCSiscomPro2Calculo,
			 LCamposSiscomPro2 *pLCSiscomPro2CompraProducto)
{
float lfltImporteExistencia=
	SiscomObtenCampoAFloat(pLCSiscomPro2Calculo,"ImporteExistencia");
float lfltCalImporteExistencia=
	(SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cantidad")-
	SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cuantostomo"))*
	SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"precio");
lfltImporteExistencia+=lfltCalImporteExistencia;
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Calculo,
			    "ImporteExistencia",
			   lfltImporteExistencia); 
	
}
*/
void ActualizaExistenciaCalcula(LCamposSiscomPro2 *pLCSiscomPro2Prod,
			 LCamposSiscomPro2 *pLCSiscomPro2Calculo,
			 LCamposSiscomPro2 *pLCSiscomPro2ComprasProducto)
{
for(;
    pLCSiscomPro2ComprasProducto;
    pLCSiscomPro2ComprasProducto=pLCSiscomPro2ComprasProducto->SCP2PtrSig)
{
   if(CantidadDisponibleCompra(pLCSiscomPro2ComprasProducto)>=
      SiscomObtenCampoAFloat(pLCSiscomPro2Prod,"cantidad"))
   {
	ActualizaCuantosTomo(pLCSiscomPro2Prod,pLCSiscomPro2ComprasProducto);
	ActualizaGanancia(pLCSiscomPro2Calculo,
			  pLCSiscomPro2Prod,
			  pLCSiscomPro2ComprasProducto);
	/*
	ActualizaImporteExistencia(pLCSiscomPro2Calculo,
			      pLCSiscomPro2ComprasProducto);

	*/
	return ;
   } 
}
}
void CalculaVentaTotal(LCamposSiscomPro2 *pLCSiscomPro2Prod,
		       LCamposSiscomPro2 *pLCSiscomPro2Vendido)
{
float lfltVentaTotal=SiscomObtenCampoAFloat(pLCSiscomPro2Prod,"VentaTotal")   +
		     SiscomObtenCampoAFloat(pLCSiscomPro2Vendido,"total");
 SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Prod,"VentaTotal",lfltVentaTotal);
}
float CalculaCantidad(LCamposSiscomPro2 *pLCSiscomPro2Prod,
		       LCamposSiscomPro2 *pLCSiscomPro2Vendido)
{
float lfltCantidad=SiscomObtenCampoAFloat(pLCSiscomPro2Prod,"Cantidad");
float lfltCVendida=SiscomObtenCampoAFloat(pLCSiscomPro2Vendido,"cantidad");
float lfltTotal=lfltCantidad+lfltCVendida;
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Prod,"Cantidad",lfltTotal);
return lfltTotal;
}
void AgregaVentaProducto(LCamposSiscomPro2 *pLCSiscomPro2Prod,
			 LCamposSiscomPro2 *pLCSiscomPro2Vendido,
			 LCamposSiscomPro2 *pLCSiscomPro2ComprasProducto)
{
CalculaCantidad(pLCSiscomPro2Prod,pLCSiscomPro2Vendido);
CalculaVentaTotal(pLCSiscomPro2Prod,pLCSiscomPro2Vendido);
if(pLCSiscomPro2ComprasProducto)
ActualizaExistenciaCalcula(pLCSiscomPro2Vendido,
			   pLCSiscomPro2Prod,
			   pLCSiscomPro2ComprasProducto);
else
SiscomAsignaDatoCampo2("EdoCalculo","1",pLCSiscomPro2Prod);

}
void AnalizaVentaProducto(LCamposSiscomPro2 *pLCSiscomPro2Prod,
		   LCamposSiscomPro2 *pLCSiscomPro2ComprasProducto, 
		    LCamposSiscomPro2 **pLCSiscomPro2ACalPrim,
		    LCamposSiscomPro2 **pLCSiscomPro2ACalAct,
		    int *pintPtrNProductos)
{
LCamposSiscomPro2 *lLCSiscomPro2Cont=*pLCSiscomPro2ACalPrim;
int lintEstaElProducto;
for(;
    pLCSiscomPro2Prod;
    pLCSiscomPro2Prod=pLCSiscomPro2Prod->SCP2PtrSig)
{
for(lLCSiscomPro2Cont=*pLCSiscomPro2ACalPrim;
    lLCSiscomPro2Cont;
    lLCSiscomPro2Cont=lLCSiscomPro2Cont->SCP2PtrSig)
if((lintEstaElProducto=EsElProducto(pLCSiscomPro2Prod,lLCSiscomPro2Cont)))
{
    AgregaVentaProducto(lLCSiscomPro2Cont,
    			pLCSiscomPro2Prod,
    			pLCSiscomPro2ComprasProducto);
    break;
}
if(!lintEstaElProducto)
{
AgregaProductoCalculo(pLCSiscomPro2Prod,
		       pLCSiscomPro2ACalPrim,
		       pLCSiscomPro2ACalAct,
		       pintPtrNProductos);
AgregaVentaProducto(*pLCSiscomPro2ACalAct,
		    pLCSiscomPro2Prod,
		    pLCSiscomPro2ComprasProducto);
}
}
}
void ObtenComprasProducto(const char *pchrPtrCveProducto,
			  LCamposSiscomPro2Agrupados *pLCSiscomPro2AgrupaCompras,
			  LCamposSiscomPro2 **pLCSiscomPro2Compras)
{
  for(;
      pLCSiscomPro2AgrupaCompras;
      pLCSiscomPro2AgrupaCompras=pLCSiscomPro2AgrupaCompras->LCSiscomPro2AgrupaS)
  if(!strcmp(pchrPtrCveProducto,
  	     pLCSiscomPro2AgrupaCompras->chrPtrCampo))
  {
    *pLCSiscomPro2Compras=pLCSiscomPro2AgrupaCompras->LCSiscomPro2Prim;
    return ;
  }
  *pLCSiscomPro2Compras=0;
}
int SeTomaParaElCalculo(LCamposSiscomPro2 *pLCSiscomPro2Compra)
{
return SiscomObtenDato(pLCSiscomPro2Compra,"cantidad")[0]!='0' &&
       SiscomObtenDato(pLCSiscomPro2Compra,"cuantostomo")[0]!='0';
}
float GananciaEnLaCompra(LCamposSiscomPro2 *pLCSiscomPro2Compra)
{
float lfltGanancia=SiscomObtenCampoAFloat(pLCSiscomPro2Compra,"precioventa")-
                  SiscomObtenCampoAFloat(pLCSiscomPro2Compra,"precio");
return lfltGanancia*SiscomObtenCampoAFloat(pLCSiscomPro2Compra,"cuantostomo");
}
void CalculaGananciasProducto(LCamposSiscomPro2 *pLCSiscomPro2Producto,
			      LCamposSiscomPro2 *pLCSiscomPro2Compras)
{
float lfltGanancia=0;
for(;
    pLCSiscomPro2Compras;
    pLCSiscomPro2Compras=pLCSiscomPro2Compras->SCP2PtrSig)
{
   if(SeTomaParaElCalculo(pLCSiscomPro2Compras))
   {
	lfltGanancia+=GananciaEnLaCompra(pLCSiscomPro2Compras);
   }
}
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Producto,
			    "Ganancia",
			    lfltGanancia);
}
void ActualizaImporteExistencia(LCamposSiscomPro2 *pLCSiscomPro2Calculo,
				 LCamposSiscomPro2 *pLCSiscomPro2CompraProducto)
{
float lfltImporteExistencia=
   SiscomObtenCampoAFloat(pLCSiscomPro2Calculo,"ImporteExistencia");
float lfltImporte;
lfltImporte=(SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cantidad")-
	     SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cuantostomo"))*
	     SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"precio");
lfltImporteExistencia+=lfltImporte;
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Calculo,
			    "ImporteExistencia",
			    lfltImporteExistencia);
}
void ActualizaExistenciaProducto(LCamposSiscomPro2 *pLCSiscomPro2Calculo,
				 LCamposSiscomPro2 *pLCSiscomPro2CompraProducto)
{
float lfltExistencia=SiscomObtenCampoAFloat(pLCSiscomPro2Calculo,"Existencia");
float lfltCuantosQuedan;
lfltCuantosQuedan=SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cantidad")-
		  SiscomObtenCampoAFloat(pLCSiscomPro2CompraProducto,"cuantostomo");
lfltExistencia+=lfltCuantosQuedan;
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Calculo,
			    "Existencia",
			    lfltExistencia);
}
void RealizaCalculosInventario(LCamposSiscomPro2 *pLCSiscomPro2Calculo,
			       LCamposSiscomPro2 *pLCSiscomPro2ComprasProductos)
{

for(;
	pLCSiscomPro2ComprasProductos;
	pLCSiscomPro2ComprasProductos=pLCSiscomPro2ComprasProductos->SCP2PtrSig)
{
   ActualizaExistenciaProducto(pLCSiscomPro2Calculo,
   			       pLCSiscomPro2ComprasProductos);
   ActualizaImporteExistencia(pLCSiscomPro2Calculo,
   			      pLCSiscomPro2ComprasProductos);
}

}
void AgregaProductoYCalculaInventario(
			LCamposSiscomPro2 *pLCSiscomPro2ComprasProducto,
			LCamposSiscomPro2 **pLCSiscomPro2CalculoPrim,
			LCamposSiscomPro2 **pLCSiscomPro2CalculoAct,
			int *pintPtrNRegistros)
{
SiscomAnexaRegistroPro2(pLCSiscomPro2CalculoPrim,
			pLCSiscomPro2CalculoAct,
			pintPtrNRegistros,
			"IdProceso,		\
			 CveProducto,		\
			 Cantidad,		\
			 VentaTotal,		\
			 Ganancia,		\
			 Existencia,		\
			 ImporteExistencia,	\
			 EdoCalculo",
			 "0",
			 SiscomObtenDato(pLCSiscomPro2ComprasProducto,"cveproducto"),
			 "0",
			 "0",
			 "0",
			 "0",
			 "0",
			 "2");
RealizaCalculosInventario(*pLCSiscomPro2CalculoAct,
			  pLCSiscomPro2ComprasProducto);
}
void AgregaProductosSinVender(LCamposSiscomPro2Agrupados *pLCSiscomPro2AgrCompras,
			      LCamposSiscomPro2 **pLCSiscomPro2CalculoPrim,
			      LCamposSiscomPro2 **pLCSiscomPro2CalculoAct,
			      int *pintPtrNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
int lintSiEsta;
for( ;
    pLCSiscomPro2AgrCompras;
    pLCSiscomPro2AgrCompras=pLCSiscomPro2AgrCompras->LCSiscomPro2AgrupaS)
{
lintSiEsta=0;
for(lLCSiscomPro2Dat=*pLCSiscomPro2CalculoPrim;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
   if(!strcmp(pLCSiscomPro2AgrCompras->chrPtrCampo,
   	     SiscomObtenDato(lLCSiscomPro2Dat,"CveProducto")))
   {

	lintSiEsta=1;
	break;

   }
   if(!lintSiEsta)
	AgregaProductoYCalculaInventario(
		pLCSiscomPro2AgrCompras->LCSiscomPro2Prim,
		pLCSiscomPro2CalculoPrim,
		pLCSiscomPro2CalculoAct,
		pintPtrNRegistros);
}


}
void EjecutaProcesoContable(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaCompras=0,
			   *lLCSiscomPro2AgrupaVentas=0;
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaCont;
LCamposSiscomPro2 *lLCSiscomPro2CalculoPrim=0,
		  *lLCSiscomPro2CalculoAct=0,
		  *lLCSiscomPro2ComprasProducto;
int lintNProductos=0;
AgrupaProductosComprasVentas(pSAgsSiscom,
			     &lLCSiscomPro2AgrupaVentas,
			     &lLCSiscomPro2AgrupaCompras);
/*
SiscomLog("Ventas Facturadas");
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgrupaVentas);

SiscomLog("Compras Realizadas");
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgrupaCompras);
*/
for(lLCSiscomPro2AgrupaCont=lLCSiscomPro2AgrupaVentas;
    lLCSiscomPro2AgrupaCont;
    lLCSiscomPro2AgrupaCont=lLCSiscomPro2AgrupaCont->LCSiscomPro2AgrupaS)
{
 ObtenComprasProducto(lLCSiscomPro2AgrupaCont->chrPtrCampo,
 		      lLCSiscomPro2AgrupaCompras,
 		      &lLCSiscomPro2ComprasProducto);
 AnalizaVentaProducto(lLCSiscomPro2AgrupaCont->LCSiscomPro2Prim,
 		      lLCSiscomPro2ComprasProducto,
 		      &lLCSiscomPro2CalculoPrim,
		      &lLCSiscomPro2CalculoAct,
		      &lintNProductos);
 RealizaCalculosInventario(lLCSiscomPro2CalculoAct,
 			    lLCSiscomPro2ComprasProducto);
}
AgregaProductosSinVender(lLCSiscomPro2AgrupaCompras,
			 &lLCSiscomPro2CalculoPrim,
			 &lLCSiscomPro2CalculoAct,
			 &lintNProductos);
/*
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgrupaCompras);

*/

SiscomAsignaInformacionArgumento("Resultados",
				 pSAgsSiscom,
				 lLCSiscomPro2CalculoPrim,
				 lLCSiscomPro2CalculoAct,
				 lintNProductos);
}
