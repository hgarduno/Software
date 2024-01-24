#ifndef __RNPERSONAS_H__
#define __RNPERSONAS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>
typedef struct Consultas
{
     int (*Consulta)(char **);
     void (*FormaConsulta)(char **,SiscomOperacionesServidor *);
}StcConsultas;

typedef struct RegistraPersona
{
	const char *chrPtrTipoPersona;
	void (*RegistraPersonas)(LCamposSiscomPro2 *,
				 int ,
				 const char *,
				 int);
}StcRegistraPersona;
				 
void CambiaEstadoFirma(int,int);
void RegistraEmpleado(LCamposSiscomPro2 *,int,const char *,int);
void RegistraPersonas(int,int);
void ConsultaPersonas(int,int);

int EsConsultaClientes(char **);
void FormaConsultaClientes(char **,SiscomOperacionesServidor *);
int EsConsultaPorRFC(char **);
void FormaConsultaClienteRFC(char **,SiscomOperacionesServidor *);
int EsConsultaUsuariosSeguridad3(char **);
void FormaConsultaUsuariosSeguridad3(char **,SiscomOperacionesServidor *);
int EsConsultaPersonaFirma(char **);
void FormaConsultaDatosFirma(char **,SiscomOperacionesServidor *);
int EsConsultaEmpleadosExpendio(char **);
void FormaConsultaEmpleadosExpendio(char **,SiscomOperacionesServidor *);

int EsConsultaValidaFirmaEmpleado(char **);
void FormaConsultaValidaFirmaEmpleado(char **,SiscomOperacionesServidor *);
#endif
