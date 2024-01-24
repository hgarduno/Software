#include <SqlClavesProveedores.h>

void SqlClavesProveedores(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"									\n\
	select distinct 							\n\
		b.razonsocial,							\n\
		b.idempresa,							\n\
		c.cveproveedor,							\n\
		c.descripcion							\n\
	from compras as a   inner join 						\n\
     		empresas as b on a.proveedor=b.idempresa left outer join	\n\
     		clavesproveedores as c  on  b.idempresa=c.idempresa and		\n\
		                            a.cveproducto=c.cveproducto		\n\
	where a.cveproducto='%s'  and  						\n\
		b.idempresa!=0							\n\
	order by b.razonsocial",
	SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom));	
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlActualizaClaveProveedor(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlClavesProveedores",
				   SqlUpdateClavesProveedores);
}
void SqlInsertaClaveProveedor(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SqlClavesProveedores",
				   SqlInsertClavesProveedores);
}

void SqlUpdateClavesProveedores(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"update ClavesProveedores set CveProveedor='%s' 	\n\
	 where idempresa=%s and 				\n\
	 	cveproducto='%s'",
	SiscomObtenDato(pLCSiscomPro2Dat,"ClaveProveedor"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdProveedor"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlInsertClavesProveedores(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
				      LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
				      int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into ClavesProveedores values(%s,'%s','%s','');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdProveedor"),
	SiscomObtenDato(pLCSiscomPro2Dat,"ClaveProveedor"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
