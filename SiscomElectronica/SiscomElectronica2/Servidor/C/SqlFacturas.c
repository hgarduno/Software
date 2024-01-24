#include <SqlFacturas.h>

void SqlBuscaFacturas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
AnalizaNumeroFactura(pSAgsSiscom,lchrArrSql);
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
void AnalizaNumeroFactura(SArgsSiscom *pSAgsSiscom,	
			  char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"select distinct numfactura,			\n\
		fecha,					\n\
		razonsocial,				\n\
		proveedor,				\n\
		idexpendio as \"IdExpendio\"		\n\
	 from compras inner join 			\n\
	      empresas on proveedor=idempresa		\n\
	 where numfactura='%s'",
	pSAgsSiscom->chrPtrArgConsulta[2]);

}
void CadenaConsultaComprasPeriodo(SArgsSiscom *pSAgsSiscom,
				  char *pchrPtrSql)
{

	if(!pSAgsSiscom->chrPtrArgConsulta[4][0])
sprintf(pchrPtrSql,
	"select distinct numfactura,				\n\
		fecha,					\n\
		razonsocial,				\n\
		proveedor,				\n\
		idexpendio as \"IdExpendio\"		\n\
	 from compras inner join 			\n\
	      empresas on proveedor=idempresa		\n\
	 where fecha::date>='%s' and 			\n\
	       fecha::date<='%s'",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3]);
	else
sprintf(pchrPtrSql,
	"select distinct numfactura,			\n\
		fecha,					\n\
		razonsocial,				\n\
		proveedor,				\n\
		idexpendio as \"IdExpendio\"		\n\
	 from compras inner join 			\n\
	      empresas on proveedor=idempresa		\n\
	 where fecha::date>='%s' and 			\n\
	       fecha::date<='%s' and			\n\
	       proveedor=%s",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3],
	pSAgsSiscom->chrPtrArgConsulta[4]);

}
void SqlFacturasComprasPeriodo(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
CadenaConsultaComprasPeriodo(pSAgsSiscom,lchrArrSql);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSAgsSiscom);
}
void CadenaConsultaDetalleFactura(SArgsSiscom *pSAgsSiscom,
			          char *pchrPtrSql)
{
   if(pSAgsSiscom->chrPtrArgConsulta[2][0] &&
      pSAgsSiscom->chrPtrArgConsulta[3][0])
	sprintf(pchrPtrSql,
		"select *			\n\
		 from compras 			\n\
		 where numfactura='%s'",
		pSAgsSiscom->chrPtrArgConsulta[2]);
   if(!pSAgsSiscom->chrPtrArgConsulta[2][0] &&
      pSAgsSiscom->chrPtrArgConsulta[3][0])
     sprintf(pchrPtrSql,
     	     "select *			\n\
	      from compras		\n\
	      where fecha='%s'",
	      pSAgsSiscom->chrPtrArgConsulta[3]);
}
void SqlDetalleFactura(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
CadenaConsultaDetalleFactura(pSAgsSiscom,lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlActualizaNumeroFactura(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SqlFacturas",
		SqlGeneraActualizaNumeroFactura);
}

void SqlGeneraActualizaNumeroFactura(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update compras set numfactura='%s' where fecha='%s'",
	SiscomObtenDato(pLCSiscomPro2,"numfactura"),
	SiscomObtenDato(pLCSiscomPro2,"fecha"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SqlInsertaFacturasCompras(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SqlFacturas",
		SqlGeneraInsertaFacturasCompras);
}

void SqlGeneraInsertaFacturasCompras(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
for(;
	pLCSiscomPro2;
     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into facturascompras values(0,%s);",
	SiscomObtenDato(pLCSiscomPro2,"numfactura"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
/*  Queretaro Martes 22 de septiembre del 2015 
 * con la administracion de los rfc's se debe 
 * integrar el registro de las facturas ....
 */
void SqlRegistrandoFactura(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionRegistroPrincipal(pSAgsSiscom,
					      "SqlRegistraFactura",
					      lchrArrBuffer,
					      SqlInsertIntoFacturas);
			
}

void SqlRegistrandoFacturaPersonaFisica(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionRegistroPrincipal(pSAgsSiscom,
					      "SqlRegistraFactura",
					      lchrArrBuffer,
					      SqlInsertIntoFacturasFisicas);
			
}

void SqlRegistrandoFacturaPersonaMoral(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
SiscomInsercionActualizacionRegistroPrincipal(pSAgsSiscom,
					      "SqlRegistraFactura",
					      lchrArrBuffer,
					      SqlInsertIntoFacturasMorales);
			
}

void SqlRegistrandoDetalleFactura(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];

SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlRegistraFactura",
					 lchrArrSql,
					 SqlInsertIntoDetalleFactura);

}
void SqlInsertIntoFacturas(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Facturas values(%s,%s,'%s',%s);",
	SiscomObtenCampoArgumento("DatosFactura","IdFactura",pSAgsSiscom),
	"0",
	SiscomObtenCampoArgumento("DatosFactura","Fecha",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(0,"TotalMIVA",pSAgsSiscom));

}

void SqlInsertIntoFacturasFisicas(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into FacturasFisicas values(%s,%s);",
	SiscomObtenCampoArgumento("DatosFactura","IdFactura",pSAgsSiscom),
	SiscomCampoSubRegistroPrincipalArgs("idpersona",pSAgsSiscom));
}

void SqlInsertIntoFacturasMorales(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat,
			   SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into FacturasMorales values(%s,%s);",
	SiscomObtenCampoArgumento("DatosFactura","IdFactura",pSAgsSiscom),
	SiscomCampoSubRegistroPrincipalArgs("idpersona",pSAgsSiscom));
}
void SqlInsertIntoDetalleFactura(LCamposSiscomPro2 *pLCSiscomPro2PtrDat,
				 SArgsSiscom *pSAgsSiscom,
				 char *pchrPtrSql)
{
  sprintf(pchrPtrSql,
  	  "insert into detallefactura values(%s,'%s',%s,%s,%s);",
	  SiscomObtenCampoArgumento("DatosFactura","IdFactura",pSAgsSiscom),
	  SiscomObtenDato(pLCSiscomPro2PtrDat,"cveproducto"),
	  SiscomObtenDato(pLCSiscomPro2PtrDat,"cantidad"),
	  SiscomObtenDato(pLCSiscomPro2PtrDat,"precio"),
	  SiscomObtenDato(pLCSiscomPro2PtrDat,"importe"));

}
