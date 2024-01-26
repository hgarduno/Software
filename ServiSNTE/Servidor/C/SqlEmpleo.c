#include <SqlEmpleo.h>
#include <SqlPersonas.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <Empleo.h>
#include  <stdio.h>

void SqlEmpresaPorRazonSocial(SiscomOperaciones *pSiscomOpePtrDat,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"select a.*,										\n\
	b.*,										\n\
	d.*,										\n\
	f.*,										\n\
	h.*										\n\
from empresas as a left outer join 							\n\
	empresagiro as b using(idempresa) left outer join				\n\
	direccionesempresa as c using(idempresa) left outer join			\n\
	direcciones as d using(iddireccion) left outer join 				\n\
	correoempresa as e using(idempresa) left outer join				\n\
	correos as f using(idcorreo) left outer join					\n\
	telefonosempresa as g using(idempresa) left outer join				\n\
	telefonos as h using(idtelefono)						\n\
where razonsocial='%s'",
SiscomCampoAsociadoEntradaOperacion("Envio","RazonSocial",pSiscomOpePtrDat));
}

int SqlEmpresaYaRegistrada(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSql[1024],
	lchrArrBuffer[1024];
SqlEmpresaPorRazonSocial(pSiscomOpePtrDat,lchrArrSql);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
				pSiscomOpePtrDat,
				"SqlEmpresaRegistrada%",
				lchrArrSql);
}
int SqlInsertaEmpleo(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlEmpleo",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToEmpresa);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToEmpresaGiro);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToEmpleo);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToTelefonoEmpleo);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToTelefonoEmpresaEmpleo);
if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToCorreoEmpleo);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToCorreoEmpresaEmpleo);
if(!EstaElJefeYaRegistrado(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Jefe",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToPersonas);

SiscomAgregaSentenciasSqlDelAsociado("SqlEmpleo",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToJefes);
SiscomAgregaSentenciasSqlDelAsociado("SqlEmpleo",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToDatosEmpleo);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "OtrosIngresos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToOtrosIngresos);
if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToDireccionEmpleo);

if(!EstaLaEmpresaYaRegistrada(pSiscomOpePtrDat))
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       InsertToDireccionEmpresa);
SiscomReplicaMaquinaLocal("SqlEmpleo", lchrArrBuffer, 0, pSiscomOpePtrDat);  
return 0;
}
int SqlActualizaEmpleo(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlEmpleo",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateEmpresa);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateEmpresaGiro);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateTelefonoEmpleo);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateCorreoEmpleo);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Jefe",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdatePersonas);

SiscomAgregaSentenciasSqlDelAsociado("SqlEmpleo",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateDatosEmpleo);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "OtrosIngresos",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateOtrosIngresos);

SiscomAgregaSentenciasSqlCampoAsociado("SqlEmpleo",
				       "Envio",
				       "Empresa",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDat,
				       UpdateDireccionEmpleo);
/*
SiscomReplicaMaquinaLocal("SqlEmpleo", lchrArrBuffer, 0, pSiscomOpePtrDat);  
*/
return 0;
}


void InsertToEmpresa(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into empresas values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("RazonSocial",pSiscomRegProLPtrEnt),
	"");
}
void UpdateEmpresa(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update empresas set razonsocial='%s' where idempresa= '%s';",
	SiscomObtenCampoRegistroProLChar("RazonSocial",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt));
}

void InsertToEmpresaGiro(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into empresagiro values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Giro",pSiscomRegProLPtrEnt));
}
void UpdateEmpresaGiro(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update empresagiro set giro='%s' where idempresa= %s;",
	SiscomObtenCampoRegistroProLChar("Giro",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt));
}

void InsertToEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Empleo values(%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdEmpleo",pSiscomOpePtr),
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtr));
}

void InsertToJefes(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLJefe=SiscomRegistrosAsociadosCampoEntrada("Envio","Jefe",pSiscomOpePtr);
sprintf(pchrPtrSql,
	"insert into Jefes values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdEmpleo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLJefe));
}


void InsertToDatosEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DatosEmpleo values(%s,%s,'%s',%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdEmpleo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Antiguedad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Puesto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Sueldo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("FrecuenciaPago",pSiscomRegProLPtrEnt));
}

void UpdateDatosEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update DatosEmpleo set antiguedad='%s',puesto='%s',sueldo='%s',frecuenciapago='%s' where idempleo=%s;",
	SiscomObtenCampoRegistroProLChar("Antiguedad",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Puesto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("Sueldo",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("FrecuenciaPago",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdEmpleo",pSiscomRegProLPtrEnt));
}

void InsertToOtrosIngresos(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrMonto;
lchrPtrMonto=SiscomObtenCampoRegistroProLChar("Monto",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"insert into OtrosIngresos values(%s,%s,'%s');",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtr),
	*lchrPtrMonto ? lchrPtrMonto : "0" ,
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt));
}

void UpdateOtrosIngresos(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
const char *lchrPtrMonto;
lchrPtrMonto=SiscomObtenCampoRegistroProLChar("Monto",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"update OtrosIngresos set monto='%s', descripcion='%s' where idpersona=%s;",
	*lchrPtrMonto ? lchrPtrMonto : "0" ,
	SiscomObtenCampoRegistroProLChar("Descripcion",pSiscomRegProLPtrEnt),
	SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtr));
}
void InsertToDireccionEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrDireccion;
lSisRegProLPtrDireccion=SiscomObtenRegistrosCampoProL("Direccion",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"insert into Direcciones values(%s,'%s','%s','%s','%s','%s','%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdDireccion",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Calle",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("NumInterior",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("NumExterior",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Colonia",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("DelegMunic",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Estado",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("CodigoPostal",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Referencias",lSisRegProLPtrDireccion));
}

void UpdateDireccionEmpleo(SiscomOperaciones *pSiscomOpePtr,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrDireccion;
lSisRegProLPtrDireccion=SiscomObtenRegistrosCampoProL("Direccion",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"update Direcciones set calle='%s',numinterior='%s',numexterior='%s',colonia='%s',delegmunic='%s',estado='%s',codigopostal='%s',referencias='%s' where iddireccion=%s;",
	SiscomObtenCampoRegistroProLChar("Calle",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("NumInterior",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("NumExterior",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Colonia",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("DelegMunic",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Estado",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("CodigoPostal",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("Referencias",lSisRegProLPtrDireccion),
	SiscomObtenCampoRegistroProLChar("IdDireccion",lSisRegProLPtrDireccion));
}
void InsertToDireccionEmpresa(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrDireccion;
lSisRegProLPtrDireccion=SiscomObtenRegistrosCampoProL("Direccion",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
	"insert into direccionesempresa values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdDireccion",lSisRegProLPtrDireccion));


}

void InsertToTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrTelefono,*lSisRegProLPtrNumerosTelefono;
lSisRegProLPtrTelefono=SiscomObtenRegistrosCampoProL("Telefonos",pSiscomRegProLPtrEnt);
lSisRegProLPtrNumerosTelefono=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefono);
sprintf(pchrPtrSql,
 	"insert into telefonos values(%s,'%s','%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("Telefono",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("Extension",lSisRegProLPtrNumerosTelefono));
}
void UpdateTelefonoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrTelefono,*lSisRegProLPtrNumerosTelefono;
lSisRegProLPtrTelefono=SiscomObtenRegistrosCampoProL("Telefonos",pSiscomRegProLPtrEnt);
lSisRegProLPtrNumerosTelefono=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefono);
sprintf(pchrPtrSql,
 	"update telefonos set telefono='%s',descripcion='%s',extension='%s' where idtelefono='%s';",
	SiscomObtenCampoRegistroProLChar("Telefono",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("Extension",lSisRegProLPtrNumerosTelefono),
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumerosTelefono));
}

void InsertToTelefonoEmpresaEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrTelefono,*lSisRegProLPtrNumerosTelefono;
lSisRegProLPtrTelefono=SiscomObtenRegistrosCampoProL("Telefonos",pSiscomRegProLPtrEnt);
lSisRegProLPtrNumerosTelefono=SiscomObtenRegistrosCampoProL("Telefonos",lSisRegProLPtrTelefono);
sprintf(pchrPtrSql,
 	"insert into telefonosempresa values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdTelefono",lSisRegProLPtrNumerosTelefono));
}

void InsertToCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrCorreo;
lSisRegProLPtrCorreo=SiscomObtenRegistrosCampoProL("Correos",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
 	"insert into correos values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCorreo",lSisRegProLPtrCorreo),
	SiscomObtenCampoRegistroProLChar("Correo",lSisRegProLPtrCorreo),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrCorreo));
}

void UpdateCorreoEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrCorreo;
lSisRegProLPtrCorreo=SiscomObtenRegistrosCampoProL("Correos",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
 	"update correos set correo='%s',descripcion='%s' where idcorreo='%s';",
	SiscomObtenCampoRegistroProLChar("Correo",lSisRegProLPtrCorreo),
	SiscomObtenCampoRegistroProLChar("Descripcion",lSisRegProLPtrCorreo),
	SiscomObtenCampoRegistroProLChar("IdCorreo",lSisRegProLPtrCorreo));
}
void InsertToCorreoEmpresaEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
			      SiscomRegistroProL *pSiscomRegProLPtrEnt,
			      char *pchrPtrSql)
{
SiscomRegistroProL *lSisRegProLPtrCorreo;
lSisRegProLPtrCorreo=SiscomObtenRegistrosCampoProL("Correos",pSiscomRegProLPtrEnt);
sprintf(pchrPtrSql,
 	"insert into correoempresa values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdEmpresa",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("IdCorreo",lSisRegProLPtrCorreo));
}
