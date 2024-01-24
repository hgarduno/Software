#include <SQLTipoPrecio.h>

void SQLTipoPrecio(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "TipoPrecio",
				   SQLGeneraRegistroTipoPrecio);
}

void SQLGeneraRegistroTipoPrecio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into TipoPrecio values(%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPrecio"),
	SiscomObtenDato(pLCSiscomPro2,"Nombre"),
	SiscomObtenDato(pLCSiscomPro2,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}

void SQLTipoPrecioRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,"select * from precios order by Nombre");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SQLAnexaTipoPrecioServicios(SArgsSiscom *pSAgsSiscom)
{
SQLPreciosServicio("TipoPrecio",pSAgsSiscom);
}
void SQLAnexaTipoPrecioServiciosMedico(SArgsSiscom *pSAgsSiscom)
{
SQLPreciosServicioMedico("TipoPrecio",pSAgsSiscom);
}
