#include <SqlPuntosPromocionesClientes.h>

void SqlComprasCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"select total as CompsCliente 	\n\
	 from ComprasClientes 		\n\
	 where idpersona=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseAsignaArgumento(
		"SqlComprasCliente",
		lchrArrSql,
		pSAgsSiscom);
}
void SqlPromocionesCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
SiscomPonPrimerRegistroArgumento("PuntosCliente",pSAgsSiscom);
sprintf(lchrArrSql,
	"select *,			\n\
	 %s as \"IdExpendio\",		\n\
	 %s as \"PuntosCliente\"	\n\
	 from promocion",
	 pSAgsSiscom->chrPtrArgConsulta[1],
	 SiscomObtenCampoArgumento("PuntosCliente","PuntosCliente",pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(
		"SqlPromociones",
		lchrArrSql,
		pSAgsSiscom);
}

void SqlCostoPuntos(SArgsSiscom *pSAgsSiscom)
{
SiscomConsultaBaseAsignaArgumento(
		"SqlCostoPunto",
		"select * from valorpuntos",
		pSAgsSiscom);
}

void SqlPuntosCanjeados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"SELECT sum(puntostotalestomados) as \"TotalPuntosCanjeados\"	\n\
	 from seguimientopuntosclientes					\n\
	 where idpersona=%s",
	 pSAgsSiscom->chrPtrArgConsulta[2]);
SiscomConsultaBaseAsignaArgumento(
		"SqlPuntosCanjeados",
		lchrArrSql,
		pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlPuntosCanjeados",pSAgsSiscom);
}
