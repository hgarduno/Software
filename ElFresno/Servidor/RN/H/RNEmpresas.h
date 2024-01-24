#ifndef __RNEMPRESAS_H__
#define __RNEMPRESAS_H__
#include <FuncionesComunes.h>

/******************
* Ya se generalizo la consulta a empresas lo unico que se
  requiere es que la Funcion EjecutaCreaConsulta regrese
  los registros Empresas, y con eso se ejecuta la consulta

*/

typedef struct CreaConsultas
{
   const char *chrPtrNmbConsulta;
   void (*EjecutaCreaConsulta)(char **,
			       StcLtaRegComSISCOM *,
			       StcLtaRegComSISCOM **,
			       int *,
			       char *);
}StcCreaConsultas;

StcLtaRegComSISCOM *OperacionesEmpresas(int ,
				     const char *,
				     StcLtaRegComSISCOM *,
				     int *);

char *RN_EMPRESA_ObtenRazonSocial(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenRFC(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenIdEmpresa(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenCalle(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenNumero(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenColonia(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenCP(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenMunicipio(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenEstado(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenReferencias(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConNombre(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConAPaterno(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConAMaterno(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConRFC(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConTipoPersona(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenConIdPersona(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenTelefono(StcLtaRegComSISCOM *);
char *RN_EMPRESA_ObtenEsExpendio(StcLtaRegComSISCOM *);

int EsRegistroProveedor(char **,
			char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RegistraProveedores(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			int ,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaGeneralProveedores(int,
				const char *,
				int,
				StcLtaRegComSISCOM *,
				StcLtaRegComSISCOM **,
				int *);
int EsConsultaEmpresas(char **,
			char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void ConsultaEmpresas(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			int ,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaConsultaEmpresas(int,
				const char *,
				int,
				StcLtaRegComSISCOM *,
				StcLtaRegComSISCOM **,
				int *);
/******** Funciones para las consultas  */

void GeneraConsultaExpendios(char **,
			     StcLtaRegComSISCOM *,
			     StcLtaRegComSISCOM **,
			     int *,
			     char *);
				
void GeneraConsultaProveedores(char **,
			     StcLtaRegComSISCOM *,
			     StcLtaRegComSISCOM **,
			     int *,
			     char *);
void GeneraConsultaMatriz(char **,
			     StcLtaRegComSISCOM *,
			     StcLtaRegComSISCOM **,
			     int *,
			     char *);
void GeneraConsultaDatosDeLaEmpresa(char **,
			     StcLtaRegComSISCOM *,
			     StcLtaRegComSISCOM **,
			     int *,
			     char *);
void GeneraConsultaPorRazonSocial(char **,
				  StcLtaRegComSISCOM *,
				  StcLtaRegComSISCOM **,
				  int *,
				  char *);


int EsRegistraMatriz(char **,
			char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RegistraMatriz(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			int ,
			StcLtaRegComSISCOM **,
			int *);
#endif
