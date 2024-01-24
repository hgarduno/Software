#include <SqlEmpresas.h>

#include <stdio.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>
int SqlRFCsRegistrados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"					\n\
	select * 				\n\
	from empresas 				\n\
	order by rfc ");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "Empresas%",
		   lchrArrSql);
return 0;
}

int SqlRegistraRegimenFiscal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrBufferSql[256];
LogSiscom("Registrando el regimen Fiscal del cliente");

SiscomAgregaSentenciasSqlDelAsociado("SqlRegimenFiscal",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSisOpePtrDato,
				       UpdateEmpresaRegimenFiscal);


SiscomEnviaRegistrosAlServidorBD("SqlRegimenFiscal",
 				  lchrArrBuffer,
				  pSisOpePtrDato);
return 0;
}
void UpdateEmpresaRegimenFiscal(SiscomOperaciones *pSiscomOpePtrDato,
                         	SiscomRegistroProL *pSiscomRegProLPtrDatos,
                        	char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update empresas set regimenfiscal=%s where rfc='%s';",
	SiscomObtenCampoRegistroProLChar("Regimen",pSiscomRegProLPtrDatos),
	SiscomObtenCampoRegistroProLChar("Rfc",pSiscomRegProLPtrDatos));
}
