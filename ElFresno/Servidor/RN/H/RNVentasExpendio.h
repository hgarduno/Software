#ifndef __RNVENTASEXPENDIO_H__
#define __RNVENTASEXPENDIO_H__
#include <FuncionesComunes.h>

/******************
* Ya se generalizo la consulta a empresas lo unico que se
  requiere es que la Funcion EjecutaCreaConsulta regrese
  los registros Empresas, y con eso se ejecuta la consulta


typedef struct CreaConsultas
{
   const char *chrPtrNmbConsulta;
   void (*EjecutaCreaConsulta)(char **,
			       StcLtaRegComSISCOM *,
			       StcLtaRegComSISCOM **,
			       int *,
			       char *);
}StcCreaConsultas;

*/
StcLtaRegComSISCOM *OperacionesVentasExpendio(int ,
				     const char *,
				     StcLtaRegComSISCOM *,
				     int *);

void RespuestaGeneralVentasExpendio(int,
				const char *,
				int,
				StcLtaRegComSISCOM *,
				StcLtaRegComSISCOM **,
				int *);
int EsConsultaVentasExpendio(char **,
			char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void ConsultaVentasExpendio(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			int ,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaConsultaVentasExpendio(int,
				const char *,
				int,
				StcLtaRegComSISCOM *,
				StcLtaRegComSISCOM **,
				int *);
/******** Funciones para las consultas  */

void GeneraConsultaVentaExpendio(char **,
			     StcLtaRegComSISCOM *,
			     StcLtaRegComSISCOM **,
			     int *,
			     char *);
				
#endif
