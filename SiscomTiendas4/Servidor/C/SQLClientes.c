#include <SQLClientes.h>

void SqlRegistraDirecciones2(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(pSAgsSiscom,
			     "SqlDirecciones2",
			     SqlGeneraDirecciones2);

}

void SqlGeneraDirecciones2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
if(SiscomObtenDato(pLCSiscomPro2Dat,"EdoRegistro")[0]=='0')
{
sprintf(lchrArrSql,
	"insert into Direcciones2 values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"idpersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"direccion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
SiscomLog("%s",lchrArrSql);
}
}
void SqlRegistraCargoRespVehiculo(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SisSQLPersona",
			     SqlGeneraCargoRespVehiculo);

}

void SqlGeneraCargoRespVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into CargoResponsable values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Cargo"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
SiscomLog("%s",lchrArrSql);
}
void SqlRegistraTipoPersonaRespVehiculo(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SisSQLPersona",
			     SqlGeneraTipoPersonaRespVehiculo);

}

void SqlGeneraTipoPersonaRespVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into TipoPersona values(%s,1001);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlRegistraTipoPersonaPropVehiculo(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SisSQLPersona",
			     SqlGeneraTipoPersonaPropVehiculo);

}

void SqlGeneraTipoPersonaPropVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into TipoPersona values(%s,1000);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlRegistraTipoPersona(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SisSQLPersona",
			     SqlGeneraTipoPersona);

}

void SqlGeneraTipoPersona(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into TipoPersona values(%s,0);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPersona"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SqlRegistraClienteFisica(SArgsSiscom *pSAgsSiscom)
{
GeneraInsercionActualizacion(pSAgsSiscom,
			     "SisSQLPersona",
			     SqlGeneraClienteFisica);

}

void SqlGeneraClienteFisica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[1024];
sprintf(lchrArrSql,
	"insert into ClientesFisica values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2Dat,"RFC"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void SQLClientesRegistrados(SArgsSiscom *pSAgsSiscom)
{
EjecutaConsultaYResponde(
pSAgsSiscom,
"							\
select 'Fisica' as TipoPersona,				\
       b.idPersona,					\
       b.Nombre,					\
       b.APaterno,					\
       b.AMaterno					\
from	clientesfisica as a inner join 			\
	personas as b using(idpersona)			\
union							\
select 'Moral' as TipoPersona,				\
	b.idempresa as identificador,			\
	b.razonsocial as nombre,			\
	'' as APaterno,					\
	'' as AMaterno					\
from	clientesmoral as a inner join 			\
	empresas as b using(idempresa)			\
order by Nombre						\
");


}
void SqlDireccionesCliente2(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
"							\n\
select  direccion					\n\
from direcciones2 					\n\
where idpersona=%s",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCliente"));
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("Direccion",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlNombreCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
"							\n\
select  *						\n\
from personas 						\n\
where idpersona=%s",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCliente"));
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("Nombre",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlDireccionesCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
/*
 * Queretaro 6 de abril 2011
 * Se coloco como parte del regreso de la consulta 
 * los campos IdExpendio y EdoRegistro para simplificar 
 * la operacion para anexar una direccion, ya que de 
 * esta manera solo en la interfaz se agrega la direccion
 * a anexar con EdoRegistro=0
 */
sprintf(lchrArrSql,
"							\n\
select  '1' as \"EdoRegistro\",				\n\
	idpersona,					\n\
       rfc,						\n\
       direccion					\n\
from clientesfisica as a left outer join		\n\
     direcciones2 using(idpersona) 			\n\
where idpersona=%s",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomLog("%s",lchrArrSql);
EjecutaConsultaYResponde(
pSAgsSiscom,
lchrArrSql);
}
