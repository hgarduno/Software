#include <SqlSeguridadCajas.h>

void SqlCajasYControles(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
select *,'' as \"IdExpendio\"				\n\
from cajas inner join 					\n\
	estadocontrolescaja using(idcaja) inner join	\n\
	Controlesventa using(idcontrol)			\n\
order by idcaja,					\n\
	 idcontrol	");
SiscomLog("%s",lchrArrSql);	
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
void SqlControlesCaja(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"						\n\
select *						\n\
from cajas inner join 					\n\
	estadocontrolescaja using(idcaja) inner join	\n\
	Controlesventa using(idcontrol)			\n\
where DireccionIp='%s'",
pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
SiscomLog("%s",lchrArrSql);
}
void SqlActualizaEdoControl(SArgsSiscom *pSArgsSiscom)
{
SiscomGeneraInsercionActualizacion(
	pSArgsSiscom,
	"SqlActualizaEdoControl",
	SqlGeneraActualizaEdoControl);
}
void SqlGeneraActualizaEdoControl(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				  LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
				  LCamposSiscomPro2 **pLCSiscomPro2DatAct,
				  int *pintPtrNRegistros)
{
char lchrArrSql[256];
for(;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"update estadocontrolescaja set estado=%s 	\n\
	 where idcaja=%s and				\n\
	 	idcontrol=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"estado"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idcaja"),
	SiscomObtenDato(pLCSiscomPro2Dat,"idcontrol"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}
