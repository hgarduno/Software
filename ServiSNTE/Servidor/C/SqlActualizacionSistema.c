#include <SqlActualizacionSistema.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>


int SqlActualizacionSistema(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
      lchrArrSql[1024];
sprintf(lchrArrSql,
	"									\n\
select d.idactualizacion,							\n\
	d.aplicar,								\n\
	b.idmaquina as maquina,							\n\
	b.puerto,								\n\
	c.archivo,								\n\
	e.*									\n\
from arquitecturamaquinas as a inner join					\n\
	maquinas as b using(idmaquina)   inner join				\n\
	archivoactualizacion as c on c.arquitectura=a.maquina inner join	\n\
	actualizasistema as d using(idactualizacion) left outer join 		\n\
	maquinasactualizadas as e on e.idmaquina=a.idmaquina and 		\n\
				     e.idactualizacion=d.idactualizacion	\n\
where nombre='%s' 	and 							\n\
	maquina='%s'   	and 							\n\
	aplicar=1       and 							\n\
	e.idmaquina is null",
	SiscomCampoAsociadoEntradaOperacion("Envio","NombreMaquina",pSiscomOpePtrDat),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Arquitectura",pSiscomOpePtrDat));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "ActualizaSistema%",
			      lchrArrSql);
LogSiscom("%s",lchrArrSql);
return 0;
}

int SqlInsertaMaquinaActualizada(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlMaquinaActualizada",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlMaquinaActualizada",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToMaquinasActualizadas);

SiscomReplicaMaquinaLocal("SqlMaquinaActualizada",lchrArrBuffer,0,pSiscomOpePtrDat);
return 0;
}
void InsertToMaquinasActualizadas(SiscomOperaciones *pSiscomOpePtrDatos,
				  SiscomRegistroProL *pSiscomRegProLPtrEnt,
				  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into MaquinasActualizadas values(%s,%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdActualizacion",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdMaquina",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt));

}
