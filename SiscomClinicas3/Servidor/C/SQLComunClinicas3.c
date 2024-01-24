#include <SQLComunClinicas3.h>

void SQLPreciosServicio(const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   pchrPtrArgumento,
				   SQLGeneraRegistroPreciosServicio);
}

void SQLGeneraRegistroPreciosServicio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"							\
insert into PreciosServicio					\
select a.idservicio,a.idprecio,1				\
from TipoPrecioServicios as a left outer join			\
     PreciosServicio as b on( a.idservicio=b.idservicio and	\
                              a.idprecio=b.idprecio)		\
where precio isnull"); 
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");

}


void SQLPreciosServicioMedico(const char *pchrPtrArgumento,
			SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   pchrPtrArgumento,
				   SQLGeneraRegistroPreciosServicioMedico);
}

void SQLGeneraRegistroPreciosServicioMedico(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,"							\
insert into PrecioServicioMedico					\
select a.idservicio,a.idPrecio,a.idPersona,1				\
from TipoPrecioServiciosMedico as a left outer join			\
     PrecioServicioMedico as b on(a.idservicio=b.idservicio and		\
                                  a.idprecio=b.idprecio     and		\
				  a.idPersona=b.idpersona)		\
where precio isnull");
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
