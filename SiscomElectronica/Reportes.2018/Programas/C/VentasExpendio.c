#include <VentasExpendio.h>
#include <SiscomDesarrolloMacros.h>
#include <Soporte.h>
#include <Reportes.h>

#include <stdlib.h>
FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;


int main(int pintArgC,char **pchrPtrArgv)
{
StcSiscomOpciones *lStcPtrSisOpciones;
gPtrFleArchivoLog=stdout;
ArgumentosVentasExpendio(pintArgC,pchrPtrArgv,&lStcPtrSisOpciones);
EjecutandoReporte(lStcPtrSisOpciones);
}
void ArgumentosVentasExpendio(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones)
{
StcSiscomOpciones lStcSisOpciones;

char *lchrPtrComandos[]={ "FechaInicio",
			  "FechaFin",
			  0
			};

SiscomAnalizaOpciones(pchrPtrArgv,pintArgc,pStcPtrSisOpciones);
if(!SiscomLineaComandosCompleta(lchrPtrComandos,*pStcPtrSisOpciones,&lStcSisOpciones))
{
  printf("Modo de Uso:							\n"
  	 "Programa que ejecuta reportes de ventas por producto por mes  \n"
	 "se pasa la base de datos a la que se conectara en el argumento\n"
	 "Base y el rango de fechas del cual se generara el reporte de  \n"
	 "ventas, el programa regresa y agrupa por mes y por productos  \n"
	 "las ventas. 							\n"
	 " 								\n"
	 "Si no se pasa el tipo de reportes (Ventas o ComparacionPeriodo)\n"
	 "el programa ejecuta por default el reporte Ventas		\n"
	 "								\n"
	 "El programa puede ejecutar los siguientes tipos de reportes	\n"
	 "	Ventas							\n"
	 "	   	Se genera la consulta a la base de datos de los \n"
	 "		productos y suma por mes la cantidad de ventas 	\n"
	 "	ComparacionPeriodo ??????				\n"
  	 "		-Base Base de datos				\n"
	 " 		-FechaInicio					\n"
	 "		-FechaFin					\n"
	 "		-ComparacionPeriodo	 			\n"
	 "		-Ventas						\n"
	 "Donde 							\n"
	 "	Base 							\n"
	 "		Se pueden pasar varios argumentos Base, en cada \n"
	 "		uno se pone la base de datos de la que se desea \n"
	 "		obtener el reporte, el programa tomara los 	\n"
	 "		resultados de cada una de las consultas agrupara\n"
	 "		por producto y realizara la suma y la separara  \n"
	 "		por mes, para tener el total de ventas 		\n"
	 "		en varios expendios.				\n"
	 "								\n"
	 "	Las fechas se deben pasar en formato yyyy/mm/aa  	\n"
	 "								\n"
	 "	Ventas Si se pasa la opcion -Ventas , el progra-	\n"
	 "		ma genera el reporte de cada uno de las bases   \n"
	 "		de datos que se pasan, en el Rango de Fechas    \n"
	 "		establecido por FechaInicio y FechaFin		\n"
	 "\n");
exit(0);
}
}

void ComparacionPeriodo(StcSiscomOpciones *pStcPtrSisOpciones)
{

StcSiscomOpciones lStcSisOpciones;
char *lchrPtrOpciones[]={"Base",
			"FechaInicio",
		        "FechaFin",
			"Periodo",
			0};
if(!SiscomLineaComandosCompleta(lchrPtrOpciones,pStcPtrSisOpciones,&lStcSisOpciones))
{
 	ModoUsoComparacionPeriodo();
	exit(0);
}
else
	EjecutandoComparacionPeriodo(pStcPtrSisOpciones);
}
void ModoUsoComparacionPeriodo()
{
printf("VentasExpendios					\n"
       "	ComparacionPeriodo			\n"
       "\n");	
}
