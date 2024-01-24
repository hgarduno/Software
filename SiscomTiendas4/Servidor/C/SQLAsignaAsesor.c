#include <SQLAsignaAsesor.h>



void SqlClientePorNumeroTelefonico(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
const char *lchrPtrArgumento;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Arg=0;
int lintNRegistrosRes;
sprintf(lchrArrSql,
 	"SELECT a.*,							\
		b.*,							\
		d.*,							\
		e.idventa,						\
		e.fecha as VentaFechaRegistro, 				\
		f.fecha as PedidoFechaEntrega,				\
		f.observaciones,					\
		g.Nombre as NombreEntrego, 				\
		g.APaterno as APaternoEntrego,				\
		g.AMaterno as AMaternoEntrego				\
	 from personas 	as a inner join					\
	      Seguimiento as b on a.idpersona=idcliente inner join	\
	      Asesores	  as c on idAsesor=c.idpersona	inner join	\
	      Estaciones  as d using(idEstacion) inner join		\
	      Ventas      as e on a.idpersona=e.idcliente inner join	\
	      Pedidos 	  as f on e.idventa=f.idventa inner join	\
	      Personas    as g on f.identrego=g.idpersona		\
	 where a.idpersona = (select idpersona 				\
	                    from comunicacionpersona 			\
			    where idmedio=1 and dato='%s')		\
	 order by e.fecha desc						\
	 limit 1", 
	 SiscomObtenDato(lLCSiscomPro2Dat,"Numero"));
SiscomConsultaBaseDatosSinDatosConexion(
		lchrArrSql,
		pSAgsSiscom->chrArrDirIpAD,
		pSAgsSiscom->intPtoComAD,
		&lLCSiscomPro2Arg,
		&lintNRegistrosRes);
SiscomLog("%s",lchrArrSql);
if(lLCSiscomPro2Arg)
lchrPtrArgumento="SQLCliente";
else
{
SiscomLog("Cliente Nuevo");
sprintf(lchrArrSql,
	"select * 		\
	 from estaciones	\
	 where estado=0");
SiscomConsultaBaseDatosSinDatosConexion(
		lchrArrSql,
		pSAgsSiscom->chrArrDirIpAD,
		pSAgsSiscom->intPtoComAD,
		&lLCSiscomPro2Arg,
		&lintNRegistrosRes);
lchrPtrArgumento="SqlClienteNuevo";
}
SiscomAsignaInformacionArgumento(
		lchrPtrArgumento,
		pSAgsSiscom,
		lLCSiscomPro2Arg,
		0,
		lintNRegistrosRes);
				
}
