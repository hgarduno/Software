#include <SqlPrecios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>

#include <stdio.h>



/* Tepotzotlan Mexico
 * 12 de De Marzo 2016
 * Durante las pruebas del contrato de beneficios integrales
 * me di cuenta que el precio que se usa es el precio general
 * aun cuendo se trate de la tienda del interior
 * En este esquema de solucion, por lo que el esquema planteado
 * de replicar el precio foraneo a las tiendas se tendra que 
 * revisar, por lo pronto para no hacer dos conexiones 
 * para replicar el precio general y el foraneo agrego la
 * funcion replica precio general y el foraneo
 *
 */
int SqlRegistraPrecioGeneralForaneo(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioGeneral);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoPrecioGeneral);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateUltimoPrecioGeneral);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoForaneo",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioForaneo);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoForaneo",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoPrecioForaneo);
SiscomReplicaMaquinasSistema("Servidor",
			     "SqlInsertaPrecio",
			     lchrArrBuffer,
			     gSiscomRegProLPtrMemoria,
			     0,
			     pSiscomOpePtrDat);
}


int SqlRegistraPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioGeneral);
/*
SiscomReplicaMaquinaLocal("SqlInsertaPrecio", lchrArrBuffer, 0, pSiscomOpePtrDat); 
*/
}

int SqlRegistraPrecioBruto(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoBruto",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioBruto);
SiscomReplicaMaquinaLocal("SqlInsertaPrecio", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlRegistraPreciosCostosDescuentos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioGeneral);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToUltimoPrecioGeneral);

SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecio",
				     "Envio",
				     "CostoGeneral",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateUltimoPrecioGeneral);
SiscomAsociadosArgumentoLog("SqlInsertaPrecio","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDat);
/*
SiscomReplicaMaquinaSistema(SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDat),
			    "SqlInsertaPrecio",
			    lchrArrBuffer,
			    gSiscomRegProLPtrMemoria,
			    0,
			    pSiscomOpePtrDat);
*/
}
int SqlRegistraPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaPrecioForaneo",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlInsertaPrecioForaneo",
				     "Envio",
				     "CostoForaneo",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToPrecioForaneo);
SiscomReplicaMaquinaLocal("SqlInsertaPrecioForaneo",lchrArrBuffer,0,pSiscomOpePtrDat); 
/*
 *
SiscomReplicaMaquinasSistema("Servidor",
			     "SqlInsertaPrecioForaneo",
			     lchrArrBuffer,
			     gSiscomRegProLPtrMemoria,
			     0,
			     pSiscomOpePtrDat);
*/
}


void InsertToPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into PrecioForaneo values(%s,%s,%s,%s,'%s',%s);",
	 SiscomObtenCampoRegistroProLChar("idprecioforaneo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("precioforaneo",pSiscomRegProLPtrEnt),
	 "0",
	 "0",
	 SiscomObtenCampoRegistroProLChar("fecha",pSiscomRegProLPtrEnt),
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDatos));
}
void InsertToPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
/* Queretaro Martes 1 de Marzo del 2016 , 
 * por concepto el Precio den ServiSNTE no tiene IVA 
 */
sprintf(pchrPtrSql,
	"insert into PrecioGeneral values(%s,%s,%s,%s,'%s',%s);",
	 SiscomObtenCampoRegistroProLChar("idpreciogeneral",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("preciogeneral",pSiscomRegProLPtrEnt),
	 "0",
	 "0",
	 SiscomObtenCampoRegistroProLChar("fecha",pSiscomRegProLPtrEnt),
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDatos));
}

void InsertToPrecioGeneral2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
/* Queretaro Martes 1 de Marzo del 2016 , 
 * por concepto el Precio den ServiSNTE no tiene IVA 
 */
sprintf(pchrPtrSql,
	"insert into PrecioGeneral values(%s,%s,%s,%s,'%s',%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdPrecio",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Precio",pSiscomOpePtrDatos),
	 "0",
	 "0",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDatos));
}
void UpdateUltimoPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ultimopreciogeneral 				\n\
		set idprecio = ( select idpreciogeneral 	\n\
				 from preciogeneral 		\n\
				 where idproducto=%s		\n\
				 order by fecha desc limit 1) 	\n\
	  where idproducto=%s;",
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt));
}

void InsertToUltimoPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoPrecioGeneral values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("idpreciogeneral",pSiscomRegProLPtrEnt));
}

void InsertToUltimoPrecioGeneral2(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoPrecioGeneral values(%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdPrecio",pSiscomRegProLPtrEnt));
}


void InsertToUltimoPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{


}


void InsertToPrecioBruto(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CostoBruto values(%s,%s,%s,%s,'%s',%s);",
	 SiscomObtenCampoRegistroProLChar("idcostobruto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("costobruto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("costoneto",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("iva",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("fecha",pSiscomRegProLPtrEnt),
	 SiscomCampoAsociadoEntradaOperacion("Envio","idproducto",pSiscomOpePtrDatos));
}

void InsertToCostoBruto3(SiscomOperaciones *pSiscomOpePtrDato,
		        SiscomRegistroProL *pSiscomRegProLPtrEnt,
			char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into CostoBruto values(%s,%s,%s,0,'%s',%s);",
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Costo","idcostobruto",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Costo","costobruto",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Costo","costoneto",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato));

}

void InsertToUltimoCosto(SiscomOperaciones *pSiscomOpePtrDato,
		        SiscomRegistroProL *pSiscomRegProLPtrEnt,
			char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into UltimoCosto values(%s,%s);",
SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Costo","idcostobruto",pSiscomOpePtrDato));

}

