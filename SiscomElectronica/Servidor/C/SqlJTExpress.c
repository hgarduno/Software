#include <SqlJTExpress.h>
#include <SiscomDesarrolloMacros.h>
int SqlCoberturaJTExpress(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SqlConsultaCoberturaJTExpress(pSiscomOpePtrDato,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			     pSiscomOpePtrDato,
			     "Cobertura%",
			     lchrArrSql);
return 0;
}

void SqlConsultaCoberturaJTExpress(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"							\n\
select *, 						\n\
	case estado 					\n\
	 when 'Distrito Federal'			\n\
	 then 						\n\
	       (select precio 				\n\
	       from precios 				\n\
	       where cveproducto = 'ENVIOLOC' and 	\n\
	       idpersona=1153257207) 			\n\
	  when 'México'					\n\
	  then						\n\
		(select precio 				\n\
	         from precios 				\n\
	         where cveproducto = 'ENVIOLOC' and 	\n\
	               idpersona=1153257207)		\n\
	  else						\n\
		(select precio 				\n\
	         from precios 				\n\
	         where cveproducto = 'ENVIOFORANEO' and \n\
	               idpersona=1153257207)		\n\
	  end as tarifa					\n\
from coberturasjtexpress				\n\
where cp ='%s';",
	SiscomCampoAsociadoEntradaOperacion("Envio","CP",pSiscomOpePtrDato));
}
