#ifndef __RNCOMUNFRESNO_H__
#define __RNCOMUNFRESNO_H__
#include <FuncionesComunes.h>
typedef struct ConsultasAlSistema
{

	int (*EsConsulta)(char **,char *);
	void (*ObtenInformacionConsulta)(int,
					 const char *,
					 const char *,
					 StcLtaRegComSISCOM **,
					 int *);
	void (*RealizaOperacionesRespuesta)(int,
					    const char *,
					    int,
					    StcLtaRegComSISCOM *,
					    StcLtaRegComSISCOM **,
					    int *);	


}StcConsultasAlSistema;
typedef struct OperacionesAlSistema
{

	int (*EsOperacion)(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
	void (*EjecutaOperacionAlSistema)(int,
					 const char *,
					 const char *,
					 StcLtaRegComSISCOM *,
					 StcLtaRegComSISCOM **,
					 int *);
	void (*FormaRespuestaOperacion)(int,
					    const char *,
					    int,
					    StcLtaRegComSISCOM *,
					    StcLtaRegComSISCOM **,
					    int *);	


}StcOperacionesAlSistema;

void SeleccionaYEjecutaConsultaGeneral(int,
				       const char *,
				       StcConsultasAlSistema *,
				       int,
				       StcLtaRegComSISCOM *,
				       StcLtaRegComSISCOM **,
				       int *);
void SeleccionaYEjecutaOperacionAlSistema(int,
				       const char *,
				       StcOperacionesAlSistema *,
				       int,
				       StcLtaRegComSISCOM *,
				       StcLtaRegComSISCOM **,
				       int *);


#endif
