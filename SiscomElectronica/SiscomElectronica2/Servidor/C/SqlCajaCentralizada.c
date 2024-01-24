#include <SqlCajaCentralizada.h>
/* Domingo 13 De Enero del 2013
 * Por ejemplo para este caso se requiere ir armando 
 * los registros que formaran cada registro de regreso
 * y se realizan 3 consultas por separado, se debera
 * plantear un esquema mediante el cual se puedan 
 * enviar varias consultas al mismo tiempo al servidor
 * y regresar todos los datos, como ya se hace en la
 * version 4
 */
void SqlOrdenesPendientes(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];

sprintf(lchrArrSql,
	"select idventa,				\n\
		idcaja,					\n\
		nombre,					\n\
		idescuela,				\n\
		fecha,					\n\
		total					\n\
	 from cajacentral  inner join 			\n\
	      escuelaorden using(idventa) inner join 	\n\
	      escuelas using(idescuela)			\n\
	 where Estado=0");
SiscomConsultaBaseAsignaArgumento(
                "SqlOrdenesPendientes",
		lchrArrSql,       
		pSAgsSiscom);
}

void SqlDatosCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"							\n\
	select  idventa,					\n\
		b.*						\n\
	from ordencliente inner join 				\n\
     		personas as b  using(idpersona) inner join	\n\
     		cajacentral using(idventa)			\n\
	where estado=0;");
SiscomConsultaBaseAsignaArgumento(
                "Cliente",
		lchrArrSql,       
		pSAgsSiscom);
}
void SqlProductosOrdenCajaCentral(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 			\n\
	 from ventas 			\n\
	 where idventa=%s",
	 SiscomCampoSubRegistroArgs(0,"idventa",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
                "SqlProductosOrden",
		lchrArrSql,       
		pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
void SqlActualizaEstadoVenta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[128];
SiscomInsercionActualizacionEntradaSubRegistroAArgumento2(
		pSAgsSiscom,
		"SqlRegistraOrden",
		lchrArrBuffer,
		0,
		SqlSentenciaEstadoVenta);
}
void SqlInsertaVentaCaja(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[128];
SiscomInsercionActualizacionRegPrincipal(
		pSAgsSiscom,
		"SqlRegistraOrden",
		lchrArrBufferSql, 
		SqlSentenciaInsertaVentasCaja);
}
void SqlActualizaEstadoOrdenCaja(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[128];
SiscomInsercionActualizacionRegPrincipal(
		pSAgsSiscom,
		"SqlRegistraOrden",
		lchrArrBufferSql, 
		SqlSentenciaActualizaEstadoOrdenCaja);

}
void SqlSentenciaEstadoVenta(LCamposSiscomPro2 *pLCSiscomPro2DatOrden, char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update ventas set edoventa=0 where idventa=%s;",
	SiscomObtenDato(pLCSiscomPro2DatOrden,"idventa"));
}
void SqlActualizaExistenciaPorOrdenCaja(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[128];
SiscomGeneraInsercionActualizacionReCorreArgEntrada(
	pSAgsSiscom,
	"SqlProductosOrden",
	"SqlRegistraOrden",
	lchrArrBufferSql,
	SqlSentenciaActualizaExistencia);
}
void SqlSentenciaActualizaExistencia(SArgsSiscom *pSAgsSiscom,
				     LCamposSiscomPro2 *pLCSiscomPro2Dat,
				     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set Existencia=Existencia-%s where idExpendio=%s and CveProducto='%s'",
	SiscomObtenDato(pLCSiscomPro2Dat,"cantidad"),
	 SiscomCampoSubRegistroPrincipalArgs("IdExpendio",pSAgsSiscom),
	 SiscomObtenDato(pLCSiscomPro2Dat,"cveproducto"));
}
void SqlSentenciaInsertaVentasCaja(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				   char *pchrPtrSql)
{
char lchrArrFechaHoy[28];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(pchrPtrSql,
	"insert into VentasCaja values(%s,%s,%s,%s,%s,'%s');",
	SiscomCampoSubRegistro(0,"idcaja",pLCSiscomPro2SRDat),
	SiscomCampoSubRegistro(0,"idventa",pLCSiscomPro2SRDat),
	SiscomCampoSubRegistro(0,"total",pLCSiscomPro2SRDat),
	SiscomCampoSubRegistro(1,"Pago",pLCSiscomPro2SRDat),
	SiscomCampoSubRegistro(1,"Cambio",pLCSiscomPro2SRDat),
	lchrArrFechaHoy);

}

void SqlSentenciaActualizaEstadoOrdenCaja(
		LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update cajacentral set estado=1 where idventa=%s;",
	SiscomCampoSubRegistro(0,"idventa",pLCSiscomPro2SRDat));
}
