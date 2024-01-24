#include <ActualizaExpendio.h>
#include <SqlActualizaExpendio.h>
#include <ComunElectronica2.h>

SiscomOperaciones2 *OpProductosNoExpendio()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosProductosNoExpendio,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosRegistradosMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosRegistradosExpendio,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ProductosNoExpendio,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpSincronizaProductosNoExpendio()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosProductosNoExpendio,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosRegistradosMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosRegistradosExpendio,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SincronizaProductosNoExpendio,lSOpOperaciones2);
return lSOpOperaciones2;
}

void ArgumentosProductosNoExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductosMatriz",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlProductosExpendio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"ProductosNoExpendio",pSAgsSiscom);
}
void ProductosNoExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
/*
SiscomImprimeArgumento("SqlProductosExpendio",pSAgsSiscom); 
*/
ObtenProductosNoExpendio(pSAgsSiscom);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
if(pSAgsSiscom->intNumRegRegreso)
SiscomEnviaRegreso(pSAgsSiscom);
else
EnviaProductosSincronizados(pSAgsSiscom);
}


void SincronizaProductosNoExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
		  *lLCSiscomPro2SqlAct=0,
		  *lLCSiscomPro2Datos;
int lintNRegSql;
char lchrArrSql[256];
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
ObtenProductosNoExpendio(pSAgsSiscom);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
lLCSiscomPro2Datos=pSAgsSiscom->LCSiscomPro2Regreso;
while(lLCSiscomPro2Datos)
{
SqlGenerandoProductosSiscomExpendio(lLCSiscomPro2Datos,
			     &lLCSiscomPro2SqlPrim,
			     &lLCSiscomPro2SqlAct,
			     &lintNRegSql);
lLCSiscomPro2Datos=lLCSiscomPro2Datos->SCP2PtrSig;
}
SiscomContenidoProtocolo(lLCSiscomPro2SqlPrim);
}
void EnviaProductosSincronizados(SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "CodigoRetorno,Mensaje",
			   "0",
			   "Los productos de la matriz son los mismos en el expendio");
}
int VeSiElProductoEstaEnElExpendio(
	LCamposSiscomPro2 *pLCSiscomPro2Producto,
	LCamposSiscomPro2 *pLCSiscomPro2ProdsExpendio)
{

   while(pLCSiscomPro2ProdsExpendio)
   {
      if(!SiscomComparaCampo(pLCSiscomPro2Producto,
      			     pLCSiscomPro2ProdsExpendio,
			     "CveProducto"))
   	return 1;    
      pLCSiscomPro2ProdsExpendio=pLCSiscomPro2ProdsExpendio->SCP2PtrSig;
   }

return 0;
}
void ObtenProductosNoExpendio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2ProdsMatriz=0,
		  *lLCSiscomPro2ProdsExpendio=0;
lLCSiscomPro2ProdsMatriz=SiscomArgumentoOperacionPrim("SqlProductosMatriz",
						      pSAgsSiscom);
lLCSiscomPro2ProdsExpendio=SiscomArgumentoOperacionPrim("SqlProductosExpendio",
							 pSAgsSiscom);
while(lLCSiscomPro2ProdsMatriz)
{
    if(!VeSiElProductoEstaEnElExpendio(lLCSiscomPro2ProdsMatriz,
    				   lLCSiscomPro2ProdsExpendio))
    	SiscomAnexaRegistroRegreso2(pSAgsSiscom,lLCSiscomPro2ProdsMatriz);
  lLCSiscomPro2ProdsMatriz=lLCSiscomPro2ProdsMatriz->SCP2PtrSig;
}
}
