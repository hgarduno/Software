#ifndef __SQLCLIENTES4_H__
#define __SQLCLIENTES4_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>


int SqlConsultaParaReEnvioFactura(SiscomOperaciones *pSiscomOpePtrDato);

int SqlRegistraFacturaFisica(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraOrdenesFacturadas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraFacturaMoral(SiscomOperaciones *pSiscomOpePtrDato);
int SqlClienteEmpresaRegistrado4(SiscomOperaciones *pSiscomOpePtrDato);


int SqlRegistraPersona4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraPersonaNormalizada4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraDireccion4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraEmpresa4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraTelefonos4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCorreos4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlAgregaCorreoCliente(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraAlumnoEscuela4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato);

int SqlDireccionesPersona(const char *,SiscomOperaciones *pSiscomOpePtrDato);
int SqlDireccionesPersonaEnvioIdPersona(SiscomOperaciones *pSisOpePtrDato);

int SqlBuscandoClienteRegistrado(SiscomOperaciones *pSiscomOpePtrDato);

int SqlDatosFisicaRegistrada(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato);


int SqlDatosMoralRegistrada(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			    SiscomOperaciones *pSiscomOpePtrDato);

int SqlAmbienteFacturacionPhp(SiscomOperaciones *pSiscomOpePtrDato);
int SqlClientePublicoEnGeneral(SiscomOperaciones *pSiscomOpePtrDato);
int SqlClienteRegistrado4(SiscomOperaciones *pSiscomOpePtrDato);
int SqlDireccionEscuela(SiscomOperaciones *pSiscomOpePtrDato);
int SqlClientesMayoreo(SiscomOperaciones *pSiscomOpePtrDato);

int SqlEnviaRegistroCliente(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEnviaRegistroFactura(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraClientePersona(SiscomOperaciones *pSiscomOpePtrDato);

int SqlCompletaDatosPersona(const char *,
			    SiscomOperaciones *pSisOpePtrDato);
void InsertToPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToPersona4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToPersonaNormalizada4(SiscomOperaciones *pSiscomOpePtrDato,
		      		SiscomRegistroProL *pSiscomRegProLPtrDato,
		      		char *pchrPtrSql);
void InsertToEmpresa4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToDireccionFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToDireccionMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToTelefonoMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToTelefonoFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);


void InsertToCorreoMoral4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToCorreoFisica4(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToFacturadoFisica(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);

void InsertToFacturadoMoral(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql);

void InsertToOrdenesFacturadas(SiscomOperaciones *pSiscomOpePtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrDato,
			       char *pchrPtrSql);

void InsertToAlumnoEscuela(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
void InsertToDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);

void InsertToEntreCallesAlumno(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql);
#endif
