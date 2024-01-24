#include <SQLDirecciones.h>

void SQLSiscomDireccionesReg(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
"								\
select	a.calle,						\
	a.numero,						\
	a.referencias,						\
	b.asentamiento,						\
	e.asentamiento as TipoAsentamiento,			\
	c.estado,						\
	d.municipio						\
from	direcciones as a inner join				\
	asentamientos as b using(idasentamiento) inner join	\
	estados as c using(numestado) inner join 		\
	municipios as d using(nummunicipio) inner join		\
	tipoasentamientos as e using(tipo)			\
where a.idpersona=%s;",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}


void SQLSiscomRegistraDireccion(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SQLDireccion",
				   SQLGeneraSiscomRegistraDireccion);
}

void SQLGeneraSiscomRegistraDireccion(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"insert into direcciones values('%s','%s','%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"Calle"),
	SiscomObtenDato(pLCSiscomPro2,"Numero"),
	SiscomObtenDato(pLCSiscomPro2,"Referencias"),
	SiscomObtenDato(pLCSiscomPro2,"IdAsentamiento"),
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
