#include <SQLEmpleados.h>

void SQLEmpleados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,"						\
select	personas.*,						\
	tipospersona.nmbtipopersona				\
from	personas inner join 					\
	tipospersona using(tipopersona)				\
     								\
where tipopersona in (						\
			select tipopersona			\
			from tipospersona			\
			where nmbtipoPersona 			\
				in('VendedoresExpendio',	\
				   'Choferes',			\
				   'Recepcionista',		\
				   'Supervisor')) and		\
	edoRegistro=1						\
order by apaterno,						\
         amaterno,						\
	 nombre,						\
	 nmbtipopersona",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);

}

void SQLBorraEmpleado(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
		pSAgsSiscom,
		"SQLEmpleados",
		SQLGeneraRegistroBorraEmpleado);
}
void SQLGeneraRegistroBorraEmpleado(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"update personas set edoRegistro=0	\
	where idpersona=%s",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
