#include <SqlClientes.h>
void SqlClientes(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"						\n\
select nombre,						\n\
	apaterno,					\n\
	amaterno,					\n\
	rfc,						\n\
	idpersona,					\n\
	'PersonaFisica' as Persona,			\n\
	b.calle,					\n\
	b.numero,					\n\
	b.colonia,					\n\
	b.cp,						\n\
	b.municipio,					\n\
	b.estado,					\n\
	c.telefono,					\n\
	d.correo					\n\
from personas as a inner join				\n\
     direcciones as b using(idpersona) inner join	\n\
     telefonos as c using(idpersona) left outer join		\n\
     correos   as d using(idpersona) 			\n\
where tipopersona=1 and 				\n\
	rfc!='GENERAL' 					\n\
union 							\n\
select razonsocial,					\n\
	'',						\n\
	'',						\n\
	rfc,						\n\
	idempresa,					\n\
	'PersonaMoral',					\n\
	b.calle,					\n\
	b.numero,					\n\
	b.colonia,					\n\
	b.cp,						\n\
	b.municipio,					\n\
	b.estado,					\n\
	c.telefono,					\n\
	d.correo					\n\
from empresas as a inner join 				\n\
     direcciones as b using(idempresa) inner join 	\n\
     telefonos as c using(idempresa)  left outer join	\n\
     correos as d   using(idempresa)			\n\
where idempresa>0 					\n\
order by rfc");
SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSql);
}
/* Sabado 14 de Diciembre del 2013 
 * Se debera agregar la informacion, de direccion, telefono etc 
 */
void SqlDatosGeneralesCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select * 			\n\
	 from personas where idpersona=%s",
	 pSAgsSiscom->Condicion(pSAgsSiscom));
SiscomConsultaBaseAsignaArgumento(pSAgsSiscom->AAlArgumento(pSAgsSiscom),
				  lchrArrSql,
				  pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
void SqlInsertaDireccionCliente(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlGeneraInsertaDireccionCliente);
}
void SqlGeneraInsertaDireccionCliente(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Direcciones values(%s,0,'%s','%s','%s','%s','%s','%s');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Calle"),
	 SiscomObtenDato(pLCSiscomPro2,"Numero"),
	 SiscomObtenDato(pLCSiscomPro2,"Colonia"),
	 SiscomObtenDato(pLCSiscomPro2,"CP"),
	 SiscomObtenDato(pLCSiscomPro2,"Municipio"),
	 SiscomObtenDato(pLCSiscomPro2,"Estado"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlInsertaDireccionClienteMoral(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlGeneraInsertaDireccionClienteMoral);
}
void SqlGeneraInsertaDireccionClienteMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"insert into Direcciones values(0,%s,'%s','%s','%s','%s','%s','%s');",
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	 SiscomObtenDato(pLCSiscomPro2,"Calle"),
	 SiscomObtenDato(pLCSiscomPro2,"Numero"),
	 SiscomObtenDato(pLCSiscomPro2,"Colonia"),
	 SiscomObtenDato(pLCSiscomPro2,"CP"),
	 SiscomObtenDato(pLCSiscomPro2,"Municipio"),
	 SiscomObtenDato(pLCSiscomPro2,"Estado"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlActualizaRFC(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
				   "SisSQLPersona",
				   SqlGeneraActualizaRFC);
}
void SqlGeneraActualizaRFC(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"update personas set rfc='%s',tipopersona=1 "
	"where idpersona=%s;",
	 SiscomObtenDato(pLCSiscomPro2,"RFC"),
	 SiscomObtenDato(pLCSiscomPro2,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

