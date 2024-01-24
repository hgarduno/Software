#include <SQLProductos.h>
#include <ComunSiscomTiendas4.h>

#include <string.h>
#include <stdlib.h>
void SQLActualizaFamiliaProductos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act,
		  *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];
ObtenInformacionArgumento("Productos",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"update famproducto set idFamilia=%s where idproducto=%s;",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdFamilia"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
AsignaInformacionArgumento("Productos",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);

}
void SQLActualizaProductos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act,
		  *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];
ObtenInformacionArgumento("Productos",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"update producto set clave='%s',dsc='%s' where idproducto=%s;",
	SiscomObtenDato(lLCSiscomPro2Contador,"Clave"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Dsc"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
AsignaInformacionArgumento("Productos",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);
}
void SQLRegistraProductos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act,
		  *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];

SiscomMensajesLog2("SQLRegistraProductos");

ObtenInformacionArgumento("Productos",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into producto values(%s,'%s','%s');",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Clave"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Dsc"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
AsignaInformacionArgumento("Productos",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);
}
void SQLRegistraFamiliaProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim,
		  *lLCSiscomPro2Act,
		  *lLCSiscomPro2Contador;
int lintNRegistros;
char lchrArrSQL[1024];


ObtenInformacionArgumento("Productos",
			  pSAgsSiscom,
			  &lLCSiscomPro2Prim,
			  &lLCSiscomPro2Act,
			  &lintNRegistros);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into famproducto values(%s,%s);",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdFamilia"));
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
AsignaInformacionArgumento("Productos",
			   pSAgsSiscom,
			   lLCSiscomPro2Prim,
			   lLCSiscomPro2Act,
			   lintNRegistros);
}
StcArgsConsulta *ConsultaProductos()
{
StcArgsConsulta *lSAConsulta=(StcArgsConsulta *)malloc(sizeof(StcArgsConsulta)*100);
memset(lSAConsulta,sizeof(StcArgsConsulta)*100,0);
lSAConsulta->intNConsultas=0;
AnexaArgsConsulta(SQLProductosPorFamilia,"PorFamilia",lSAConsulta);
AnexaArgsConsulta(SQLProductosSemejantesALaClave,"ClaveSemejante",lSAConsulta);
AnexaArgsConsulta(SQLProductosConsultaRegistrados,"Registrados",lSAConsulta);
return lSAConsulta;
}
void SQLProductosRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
StcArgsConsulta *lSAConsulta;
SQLGeneraConsulta lSQGCCadena;
lSAConsulta=ConsultaProductos();
lSQGCCadena=ObtenFuncionGeneraConsulta(lSAConsulta,
			   0,
			   pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomLog("-->");
lSQGCCadena(pSAgsSiscom,lchrArrSQL);
SiscomLog("%s",lchrArrSQL);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLProductosPorFamilia(SArgsSiscom *pSAgsSiscom,char *pchrPtrSQL)
{
SiscomMensajesLog2("SQLProductosPorFamilia");
}
void SQLProductosSemejantesALaClave(SArgsSiscom *pSAgsSiscom,char *pchrPtrSQL)
{
SiscomMensajesLog2("SQLProductosSemejantesALaClave");
}
void SQLProductosConsultaRegistrados(SArgsSiscom *pSAgsSiscom,
				     char *pchrPtrSQL)
{
SiscomMensajesLog2("SQLProductosConsultaRegistrados");
sprintf(pchrPtrSQL,
	"								\
	select	a.idProducto,						\
		a.clave,						\
	       	a.dsc as dscproducto,					\
	       	b.idfamilia,						\
	       	c.Familia,						\
	       	c.dsc as dscfamilia					\
	from	producto as a inner join 				\
		famproducto as b using(idproducto) inner join 		\
		familia as c using(idfamilia)				\
	order by a.clave");
}
