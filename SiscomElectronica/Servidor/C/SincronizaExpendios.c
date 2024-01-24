#include <SincronizaExpendios.h>
#include <Precios.h>


#include <SqlSincronizaExpendios.h>


#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SqlSiscomElectronica.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>


#include <string.h>

void SincronizaProductosExpendio(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoProductosMatriz,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoProductosExpendio,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoBodegasExpendio,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoCondicionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoSqlProductosASincronizar,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoProductosASincronizar,&lSiscomProDat);
SiscomAgregaOperacion(CopiaExpendiosPrecios,&lSiscomProDat);
SiscomAgregaOperacion(CondicionConsultaUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultandoUnosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlProductosMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlProductosExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(SqlLasBodegasDelExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(ProductosASincronizarExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlInsertaProductoExpendioSincroniza,&lSiscomProDat); 
SiscomAgregaOperacion(SincronizandoProductosExpendio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int SincronizandoProductosExpendio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[8192];
SiscomAsociadoAsociadoLog("Envio","Expendios",lchrArrBuffer,pSisOpePtrDato);
SiscomArgumentoLog("Expendios",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoRespuestaLog("Matriz",lchrArrBuffer,pSisOpePtrDato);
SiscomArgumentoLog("BodegasExpendio",lchrArrBuffer,pSisOpePtrDato);
/*
SiscomArgumentoLog("ProductosMatriz",lchrArrBuffer,pSisOpePtrDato);
SiscomArgumentoLog("ProductosExpendio",lchrArrBuffer,pSisOpePtrDato);
*/
/*
SiscomArgumentoLog("ProductosASincronizar",lchrArrBuffer,pSisOpePtrDato);
*/
/*
SiscomAsociadosArgumentoLog("SqlProductosASincronizar",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSisOpePtrDato);
*/
LogSiscom("Si termino");
}
int ProductosASincronizarExpendio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrProdsASi;
ObtenProductosASincronizar(pSisOpePtrDato,&lSisRegProLPtrProdsASi);
SiscomAsignaRegistrosArgumentoOperaciones(lSisRegProLPtrProdsASi,
					  lSisRegProLPtrProdsASi,
					  "ProductosASincronizar",
					  pSisOpePtrDato);
}
int EstaElProductoEnElExpendio(SiscomRegistroProL *pSisRegProLPtrProdsMatriz,
			       SiscomRegistroProL *pSisRegProLPtrProdsExpendio)
{
for(;pSisRegProLPtrProdsExpendio;
     pSisRegProLPtrProdsExpendio=pSisRegProLPtrProdsExpendio->SiscomRegProLPtrSig)
{
   if(!SiscomComparaCampoRegistrosProL("cveproducto",
   				       pSisRegProLPtrProdsMatriz,
				       pSisRegProLPtrProdsExpendio))
     return 1;
}
return 0;
}
SiscomRegistroProL *ProductosExpendioMatriz(const char *pchrPtrArgumento,
					    SiscomOperaciones *pSisOpePtrDato)
{

return SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSisOpePtrDato);

}
void ObtenProductosASincronizar(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL **pSisRegProLPtrProASi)
{
SiscomRegistroProL *lSisRegProLPtrProdsMatriz,
		   *lSisRegProLPtrProdsExpendio;
SiscomRegistroProL *lSisRegProLPtrProdASi=0;

*pSisRegProLPtrProASi=0;
lSisRegProLPtrProdsMatriz=ProductosExpendioMatriz("ProductosMatriz",pSisOpePtrDato);
lSisRegProLPtrProdsExpendio=ProductosExpendioMatriz("ProductosExpendio",pSisOpePtrDato);

   for(;lSisRegProLPtrProdsMatriz;
        lSisRegProLPtrProdsMatriz=lSisRegProLPtrProdsMatriz->SiscomRegProLPtrSig)
    if(!EstaElProductoEnElExpendio(lSisRegProLPtrProdsMatriz,
    				  lSisRegProLPtrProdsExpendio))
    {
        
	/*LogSiscom("El Producto %s no esta en el expendio", 
	 SiscomObtenCampoRegistroProLChar("cveproducto",lSisRegProLPtrProdsMatriz),
	 SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Expendios","IdEmpresa",
	 	pSisOpePtrDato));
		*/
	SiscomNodoRegistroPro(lSisRegProLPtrProdsMatriz->SiscomCamProLPtrDato,
			      pSisRegProLPtrProASi,
			      &lSisRegProLPtrProdASi);
    }

}
int ArgumentoProductosMatriz(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("ProductosMatriz",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
}

int ArgumentoBodegasExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("BodegasExpendio",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
}

int ArgumentoProductosExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("ProductosExpendio",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
}

int ArgumentoProductosASincronizar(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("ProductosASincronizar",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
}

int ArgumentoSqlProductosASincronizar(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlProductosASincronizar",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
