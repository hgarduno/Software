#include <SqlTransferencias.h>

void SqlTransferencias(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
const char *lchrPtrIdExpendioConsulta;

lchrPtrIdExpendioConsulta=pSAgsSiscom->chrPtrArgConsulta[4];
if(lchrPtrIdExpendioConsulta  &&
   !*lchrPtrIdExpendioConsulta)
sprintf(lchrArrSql,
	"select a.fechahora,						\n\
		cantidad,						\n\
		cveproducto,						\n\
		b.razonsocial as destino,				\n\
		f.razonsocial as origen,				\n\
		estado,							\n\
		a.idtransferencia					\n\
	 from transfierematerial as a  inner join 			\n\
	      empresas as b on(b.idempresa=idempresadestino) inner join	\n\
	      transferencias as c using(idtransferencia) inner join 	\n\
	      estadotransferencia as de using(idestado)  inner join	\n\
	      empresas as f on (f.idempresa=a.idempresaorigen)		\n\
	 where a.fechahora::date>='%s'  and 				\n\
	       a.fechahora::date<='%s'					\n\
	 order by fechahora desc,					\n\
	 	  cveproducto",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3]);
else
if(lchrPtrIdExpendioConsulta &&
   *lchrPtrIdExpendioConsulta)
sprintf(lchrArrSql,
	"select a.fechahora,						\n\
		cantidad,						\n\
		cveproducto,						\n\
		b.razonsocial as destino,				\n\
		f.razonsocial as origen,				\n\
		estado,							\n\
		a.idtransferencia					\n\
	 from transfierematerial as a  inner join 			\n\
	      empresas as b on(idempresa=idempresadestino) inner join	\n\
	      transferencias as c using(idtransferencia) inner join 	\n\
	      estadotransferencia as de using(idestado)	inner join	\n\
	      empresas as f on (f.idempresa=a.idempresaorigen)		\n\
	 where a.fechahora::date>='%s'  and 				\n\
	       a.fechahora::date<='%s'  and 				\n\
	       b.idempresa=%s						\n\
	 order by fechahora desc,					\n\
	 		    cveproducto",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3],
	pSAgsSiscom->chrPtrArgConsulta[4]);
SiscomLog("%s",lchrArrSql);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}

void SqlInformacionTransferencia(int pintPtoCom,
				   const char *pchrPtrDirIp,
				   const char *pchrPtrIdTransferencia,
				   LCamposSiscomPro2 **pLCSiscomPro2Regreso)

{
char lchrArrSql[256];
int lintNRegreso=0;
sprintf(lchrArrSql,
	"select *					\n\
	from transferencias as a inner join 		\n\
	     expendios as b on a.idexpendio=b.idempresa	\n\
	 where idtransferencia=%s",
	 pchrPtrIdTransferencia);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSql,
					pchrPtrDirIp,
					pintPtoCom,
					pLCSiscomPro2Regreso,
					&lintNRegreso);
}

void SqlProductosATransferir(int pintPtoCom,
				   const char *pchrPtrDirIp,
				   const char *pchrPtrIdTransferencia,
				   LCamposSiscomPro2 **pLCSiscomPro2Regreso)

{
char lchrArrSql[256];
int lintNRegreso=0;
sprintf(lchrArrSql,
	"select * 			\n\
	 from transfierematerial	\n\
	 where idtransferencia=%s",
	 pchrPtrIdTransferencia);
SiscomConsultaBaseDatosSinDatosConexion(lchrArrSql,
					pchrPtrDirIp,
					pintPtoCom,
					pLCSiscomPro2Regreso,
					&lintNRegreso);
}

char *SqlInsercionesAlExpendio(LCamposSiscomPro2 *pLCSiscomPro2InfTrans,
			 LCamposSiscomPro2 *pLCSiscomPro2ProdsTrans)
{
char lchrArrSql[256],*lchrPtrEdoConexion;

LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
  		  *lLCSiscomPro2SqlAct=0,
		  *lLCSiscomPro2Respuesta=0;

int lintNRegistros=0,lintSocket,lintNRegistrosResp=0;
for(; 
    pLCSiscomPro2ProdsTrans;
    pLCSiscomPro2ProdsTrans=pLCSiscomPro2ProdsTrans->SCP2PtrSig)
{
 sprintf(lchrArrSql,
 	"update existencias set existencia=existencia+%s\n\
	 where CveProducto='%s' and IdExpendio=%s",
	 SiscomObtenDato(pLCSiscomPro2ProdsTrans,"cantidad"),
	 SiscomObtenDato(pLCSiscomPro2ProdsTrans,"cveproducto"),
	 SiscomObtenDato(pLCSiscomPro2ProdsTrans,"idempresadestino"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2SqlPrim,
			&lLCSiscomPro2SqlAct,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
SiscomInformacionServidorConRespuesta(SiscomObtenDatoInt(pLCSiscomPro2InfTrans,"ptocomad"),
				      SiscomObtenDato(pLCSiscomPro2InfTrans,"diripsvrad"),
				      "Inserciones",
				      lintNRegistros,
				      lLCSiscomPro2SqlPrim,
				      &lchrPtrEdoConexion,
				      &lintSocket,
				      &lLCSiscomPro2Respuesta,
				      &lintNRegistrosResp);
return lchrPtrEdoConexion;
}

void SqlActualizaTransferenciaExitosa(int pintPuerto,
				      const char *pchrPtrDirIp,
				      const char *pchrPtrIdTransferencia)
{
char lchrArrSql[256],*lchrPtrEdoConexion;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
  		  *lLCSiscomPro2SqlAct=0,
		  *lLCSiscomPro2Respuesta=0;

int lintNRegistros=0,lintSocket,lintNRegistrosResp=0;
 sprintf(lchrArrSql,
 	"update transferencias set idestado=0 where idtransferencia=%s;",
	pchrPtrIdTransferencia);
SiscomAnexaRegistroPro2(&lLCSiscomPro2SqlPrim,
			&lLCSiscomPro2SqlAct,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
SiscomInformacionServidorConRespuesta(pintPuerto,
				      pchrPtrDirIp,
				      "Inserciones",
				      lintNRegistros,
				      lLCSiscomPro2SqlPrim,
				      &lchrPtrEdoConexion,
				      &lintSocket,
				      &lLCSiscomPro2Respuesta,
				      &lintNRegistrosResp);
}
