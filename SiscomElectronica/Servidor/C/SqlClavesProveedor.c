#include <SqlClavesProveedor.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>

#include <stdio.h>

int SqlConsultaClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];

SqlFormaConsultaProductoClaveProveedor(pSiscomOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "ClaveProveedor%",
		   lchrArrSql);
return 0;
}

void SqlFormaConsultaProductoClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato,
					    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *						\n\
	 from ClavesProveedores left outer join 		\n\
	      PesoProducto as b using(cveproducto) inner join	\n\
              empresas using(idempresa)				\n\
	 where cveproducto='%s' and 				\n\
	       idempresa=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Clave",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdEmpresa",pSiscomOpePtrDato));
}
int SqlRegistraClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
        lchrArrSql[256];


SiscomAgregaSentenciasSqlDelAsociado("SqlClavesProveedor",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     InsertToClavesProveedor);

SiscomEnviaRegistrosAlServidorBD("SqlClavesProveedor",
                               lchrArrBuffer,
                               pSiscomOpePtrDato);

return 0;
}

int SqlActualizaClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
        lchrArrSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlClavesProveedor",
                                     "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSiscomOpePtrDato,
                                     UpdateClaveProveedor);
SiscomEnviaRegistrosAlServidorBD("SqlClavesProveedor",
                               lchrArrBuffer,
                               pSiscomOpePtrDato);
return 0;
}

void InsertToClavesProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL *pSiscomRegProLPtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ClavesProveedores values(%s,'%s','%s','%s');", 
   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Proveedor","IdEmpresa",pSiscomOpePtrDato),
   SiscomObtenCampoRegistroProLChar("ClaveP",pSiscomRegProLPtrDato),
   SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
   SiscomObtenCampoRegistroProLChar("DescripcionP",pSiscomRegProLPtrDato));
}
void UpdateClaveProveedor(SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL *pSiscomRegProLPtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update clavesproveedores set cveproveedor='%s',	\n\
	           		      descripcion='%s'		\n\
	 where cveproducto='%s' and idempresa=%s;", 
   SiscomObtenCampoRegistroProLChar("ClaveP",pSiscomRegProLPtrDato),
   SiscomObtenCampoRegistroProLChar("DescripcionP",pSiscomRegProLPtrDato),
   SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Proveedor","IdEmpresa",pSiscomOpePtrDato));
}
