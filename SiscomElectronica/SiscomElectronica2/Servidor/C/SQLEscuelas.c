#include <SQLEscuelas.h>

void SQLEscuelas(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];


/*
 *
 * En un principio se penso agrupar
 * las escuelas por expendio, esto al final
 * en la practica no tiene ningun sentido
 * ya que los expendios se controlan de forma
 * separada en otro servidor
 *
sprintf(lchrArrSQL,
	"select * 			\
	 from escuelas			\
	 where idempresa=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);


*/
sprintf(lchrArrSQL,
	"select * 			\
	 from escuelas");

SiscomEjecutaConsultaYResponde(pSAgsSiscom,
			       lchrArrSQL);
}
