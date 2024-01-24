#include <DatosProductosPorFamilia.h>
#include <SqlDatosProductosPorFamilia.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>
SiscomOperaciones2 *ODatosProductosPorFamilia()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosDatosProductos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlProductosPorFamilia,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlPreciosProductosPorFamilia,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlUltimaCompraProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(FormaInformacionPorProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(DatosProductosPorFamilia,lSOpOperaciones); 
return lSOpOperaciones;


}
void DatosProductosPorFamilia(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomImprimeArgumento("SqlProductos",pSAgsSiscom);
SiscomImprimeArgumento("SqlPreciosProducto",pSAgsSiscom);
SiscomImprimeArgumento("SqlUltimaCompra",pSAgsSiscom);
SiscomImprimeArgumento("InformacionProducto",pSAgsSiscom);

SiscomEnviaArgumentoCliente("InformacionProducto",pSAgsSiscom);
				
}
void CalculaGanaciaConUltimaCompra(SArgsSiscom *pSAgsSiscom)
{


}
void ArgumentosDatosProductos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlPreciosProducto",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlUltimaCompra",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"InformacionProducto",pSAgsSiscom);
}
void AgregaInformacionProducto(LCamposSiscomPro2 *pLCSiscomPro2Informacion,
		   LCamposSiscomPro2 *pLCSiscomPro2Producto,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdPrim,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdAct)
{
const char *lchrPtrIdProducto;
lchrPtrIdProducto=SiscomObtenDato(pLCSiscomPro2Producto,"idproducto");
for(; 
pLCSiscomPro2Informacion;
pLCSiscomPro2Informacion=pLCSiscomPro2Informacion->SCP2PtrSig)
{
if(!strcmp(lchrPtrIdProducto,SiscomObtenDato(pLCSiscomPro2Informacion,"idproducto")))
SiscomCreaListaCamposPro2(pLCSiscomPro2Informacion->SCSiscomPro2,
		  pLCSiscomPro2InfoProdPrim,
		  pLCSiscomPro2InfoProdAct);
}

}
void AgregaUltimaCompraProducto(LCamposSiscomPro2 *pLCSiscomPro2UCompra,
		LCamposSiscomPro2 *pLCSiscomPro2Producto,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdPrim,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdAct)
{
AgregaInformacionProducto(pLCSiscomPro2UCompra,
		  pLCSiscomPro2Producto,
		  pLCSiscomPro2InfoProdPrim,
		  pLCSiscomPro2InfoProdAct);
}
void AgregaPreciosProducto(LCamposSiscomPro2 *pLCSiscomPro2Precios,
		   LCamposSiscomPro2 *pLCSiscomPro2Producto,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdPrim,
		   LCamposSiscomPro2 **pLCSiscomPro2InfoProdAct)
{
AgregaInformacionProducto(pLCSiscomPro2Precios,
		 pLCSiscomPro2Producto,
		 pLCSiscomPro2InfoProdPrim,
		 pLCSiscomPro2InfoProdAct);
}
		   
void FormaInformacionPorProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prod;
LCamposSiscomPro2 *lLCSiscomPro2InfoProdPrim=0;
LCamposSiscomPro2 *lLCSiscomPro2InfoProdAct=0;
LCamposSiscomPro2 *lLCSiscomPro2Precios;
LCamposSiscomPro2 *lLCSiscomPro2UCompra;
int lintNRegistros;
lLCSiscomPro2Precios=SiscomArgumentoOperacionPrim("SqlPreciosProducto",pSAgsSiscom);
lLCSiscomPro2Prod=SiscomArgumentoOperacionPrim("SqlProductos",pSAgsSiscom);
lLCSiscomPro2UCompra=SiscomArgumentoOperacionPrim("SqlUltimaCompra",pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros("SqlProductos",pSAgsSiscom) +
	       SiscomArgumentosNumeroRegistros("SqlPreciosProducto",pSAgsSiscom)+
	       SiscomArgumentosNumeroRegistros("SqlUltimaCompra",pSAgsSiscom);
for(;
    lLCSiscomPro2Prod;
    lLCSiscomPro2Prod=lLCSiscomPro2Prod->SCP2PtrSig)
{
SiscomCreaListaCamposPro2(lLCSiscomPro2Prod->SCSiscomPro2,
			  &lLCSiscomPro2InfoProdPrim,
			  &lLCSiscomPro2InfoProdAct);
AgregaPreciosProducto(lLCSiscomPro2Precios,
		      lLCSiscomPro2Prod,
		      &lLCSiscomPro2InfoProdPrim,
		      &lLCSiscomPro2InfoProdAct);
AgregaUltimaCompraProducto(lLCSiscomPro2UCompra,
			   lLCSiscomPro2Prod,
			   &lLCSiscomPro2InfoProdPrim,
			   &lLCSiscomPro2InfoProdAct);
}
SiscomAsignaInformacionArgumento("InformacionProducto",
				 pSAgsSiscom,
				 lLCSiscomPro2InfoProdPrim,
				 lLCSiscomPro2InfoProdAct,
				 lintNRegistros);
SiscomLog("Se enviaran %d Registros",lintNRegistros);
}
