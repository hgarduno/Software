#ifndef __CLIENTES_H__
#define __CLIENTES_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void Direcciones(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void ClientesMayoreo(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraClientePersona(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegistraCelularAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);


void RegistraCorreoAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void RegistraDireccionAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

void PublicoEnGeneral(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);

void DireccionEscuela(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct);
void ArmaRespuestaNombreNoCoincide(SiscomOperaciones *pSiscomOpePtrDato);

int RegistrandoClientePersona(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato);

int GeneraIdPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaRFCPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato);
int RegresandoIdPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaPublicoEnGeneral(SiscomOperaciones *pSiscomOpePtrDato);
int ClienteRegistrado(SiscomOperaciones *pSiscomOpePtrDato);
int ElClienteYaSeRegistro(SiscomOperaciones *pSiscomOpePtrDato);
int NombreNoCoincide(SiscomOperaciones *pSiscomOpePtrDato);
int BuscandoAUnClienteEnLaBase(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaDireccionEscuela(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaDirecciones(SiscomOperaciones *pSiscomOpePtrDato);
int NormalizaPersona(SiscomOperaciones *pSiscomOpePtrDato);
int AsignaIdDireccion(SiscomOperaciones *pSisOpePtrDato);

int EnviaClientesMayoreo(SiscomOperaciones *pSiscomOpePtrDato);


void ConsultasInformacionPersona(SiscomOperaciones *pSiscomOpePtrDato,
				 char *pchrPtrSqlDirecciones,
				 char *pchrPtrSqlCorreos,
				 char *pchrPtrSqlTelefonos);


int IdPersonaANormalizada(SiscomOperaciones *pSiscomOpePtrDato);

/* Para Pasar a la biblioteca 
 *
 *
 */


void SiscomNormalizaCadenas(char **pchrPtrCampos,
			   const char *pchrPtrAsoEntrada,
			   const char *pchrPtrAsoSalida,
			   SiscomOperaciones *pSiscomOpePtrDato);
void SiscomNormalizaCamposPro2(char **pchrPtrCampos,
			       SiscomRegistroProL *pSisRegProLPtrDato,
			       SiscomRegistroProL **pSisRegProLPtrPrimSal,
			       SiscomRegistroProL **pSisRegProLPtrActSal);
#endif
