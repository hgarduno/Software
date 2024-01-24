#ifndef __RNFACTURACION_H__
#define __RNFACTURACION_H__
#include <FuncionesComunes.h>


StcLtaRegComSISCOM *OperacionesFacturacion(int,
					     const char *,
					     StcLtaRegComSISCOM *,
					     int *);
int EsRegistroFacturacion(int,
			    const char *,
			    char **,
			    char *,
			    StcLtaRegComSISCOM *,
			    StcLtaRegComSISCOM **,
			    int *);	
void RegistraFacturacion(int,
			   const char *,
			   const char *,
			   StcLtaRegComSISCOM *,
			   int,
			   StcLtaRegComSISCOM **,
			   int *);

void RespuestaGeneralFacturacion(int,
				   const char *,
				   int,
				   StcLtaRegComSISCOM *,
				   StcLtaRegComSISCOM **,
				   int *);

int EsConsultaFacturacion(int,
			    const char *,
			    char **,
			    char *,
			    StcLtaRegComSISCOM *,
			    StcLtaRegComSISCOM **,
			    int *);
void ConsultaFacturacion(int,
			   const char *,
			   const char *,
			   StcLtaRegComSISCOM *,
			   int,
			   StcLtaRegComSISCOM **,
			   int *);



void CreaConsultaOrdenesPorFecha(char **,
			       StcLtaRegComSISCOM *,
			       StcLtaRegComSISCOM **,
			       int *,
			       char *);
void CreaConsultaOrdenesAFacturar(char **,
				  StcLtaRegComSISCOM *,
				  StcLtaRegComSISCOM **,
				  int *,
				  char *);
#endif
