#include <SqlPaquetes.h>

void SQLRegistraPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLPaquetes",
		SQLGeneraRegistraPaquete);
}

void SQLGeneraRegistraPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Paquetes values(%s,'%s','%s',0.0);",
	SiscomObtenDato(pLCSiscomPro2,"IdPaquete"),
	SiscomObtenDato(pLCSiscomPro2,"Clave"),
	SiscomObtenDato(pLCSiscomPro2,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SQLRegistraProductosPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLPaquetes",
		SQLGeneraRegistraProductosPaquete);
}

void SQLGeneraRegistraProductosPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
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
	"insert into ProductosPaquete values(%s,%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPaquete"),
	SiscomObtenDato(pLCSiscomPro2,"idproducto"),
	SiscomObtenDato(pLCSiscomPro2,"Cantidad"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}


void SqlEliminaPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLPaquetes",
		SqlGeneraRegistraEliminaPaquete);
}
void Sql_EliminaProductosPaquete(const char *pchrPtrIdPaquete,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"delete from productospaquete 		\
	 where idPaquete=%s",
	 pchrPtrIdPaquete);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");

}

void Sql_EliminaPaquete(const char *pchrPtrIdPaquete,
				LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"delete from paquetes 		\
	 where idPaquete=%s",
	 pchrPtrIdPaquete);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");

}
void SqlGeneraRegistraEliminaPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
const char *lchrPtrIdPaquete;
for(;
    pLCSiscomPro2;
    pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
lchrPtrIdPaquete=SiscomObtenDato(pLCSiscomPro2,"IdPaquete");
Sql_EliminaProductosPaquete(lchrPtrIdPaquete,
			   pLCSiscomPro2Prim,
			   pLCSiscomPro2Act,
			   pintPtrNRegistros);
Sql_EliminaPaquete(lchrPtrIdPaquete,
			   pLCSiscomPro2Prim,
			   pLCSiscomPro2Act,
			   pintPtrNRegistros);

/*
sprintf(lchrArrSQL,
	"delete from paquetes 		\
	 where idPaquete=%s",
	 SiscomObtenDato(pLCSiscomPro2,"IdPaquete"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");

*/

}
}

void SqlEliminaProductoPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLPaquetes",
		SqlGeneraRegistraEliminaProductoPaquete);
}

void SqlGeneraRegistraEliminaProductoPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
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
	"delete from productospaquete		\
	 where idPaquete=%s and idProducto=%s",
	 SiscomObtenDato(pLCSiscomPro2,"IdPaquete"),
	 SiscomObtenDato(pLCSiscomPro2,"IdProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}


void SqlAnexarProductoPaquete(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLPaquetes",
		SqlGeneraRegistraAnexarProductoPaquete);
}

void SqlGeneraRegistraAnexarProductoPaquete(LCamposSiscomPro2 *pLCSiscomPro2,
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
	"insert into productospaquete values(%s,%s,%s);",
	 SiscomObtenDato(pLCSiscomPro2,"IdPaquete"),
	 SiscomObtenDato(pLCSiscomPro2,"IdProducto"),
	 SiscomObtenDato(pLCSiscomPro2,"Cantidad"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}


void SqlPaquetesDisponibles(SArgsSiscom *pSAgsSiscom)
{
SiscomEjecutaConsultaYResponde(pSAgsSiscom,"select * from paquetes");
}
void SqlProductosPaquete(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 				\
	 from ProductosPaquete inner join	\
	      producto using(idproducto)	\
	 where idPaquete=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}
