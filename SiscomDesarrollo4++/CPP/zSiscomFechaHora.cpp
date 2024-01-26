#include <zSiscomFechaHora.h>
#include <stdio.h>
#include <time.h>

zSiscomFechaHora::zSiscomFechaHora()
{

}

void zSiscomFechaHora::Actual(char *pchrPtrFechaHora)
{
char lchrArrFecha[12];
char lchrArrHora[12];
zSiscomFecha::Actual(lchrArrFecha);
zSiscomHora::Actual(lchrArrHora);
sprintf(pchrPtrFechaHora,
	"%s %s",
	lchrArrFecha,
	lchrArrHora);

}
void zSiscomFechaHora::Actual2(char *pchrPtrFechaHora)
{
char lchrArrFecha[35];
char lchrArrHora[12];
zSiscomFecha::Actual2(lchrArrFecha);
zSiscomHora::Actual(lchrArrHora);
sprintf(pchrPtrFechaHora,
	"%s %s",
	lchrArrFecha,
	lchrArrHora);

}
const char *zSiscomFechaHora::Actual3(char *pchrPtrFechaHora)
{
    zSiscomFechaHora::Actual2(pchrPtrFechaHora);
    return pchrPtrFechaHora;
}
zSiscomFecha::zSiscomFecha()
{

}
void zSiscomFecha::Actual(int *pintPtrDiaMes,
			  int *pintPtrMes,
			  int *pintPtrAno,
			  int *pintPtrDiaSemana)
{
time_t regTime;
struct tm *stctm;
time(&regTime);
stctm=gmtime(&regTime);

*pintPtrAno=stctm->tm_year+1900;
*pintPtrMes=stctm->tm_mon+1;
*pintPtrDiaMes=stctm->tm_mday;
if(pintPtrDiaSemana)
*pintPtrDiaSemana=stctm->tm_wday;
}
void zSiscomFecha::Actual(char *pchrPtrFecha)
{
time_t regTime;
struct tm *stctm;
time(&regTime);
stctm=gmtime(&regTime);

sprintf(pchrPtrFecha,
	"%04d-%02d-%02d",
	stctm->tm_year+1900,
	stctm->tm_mon+1,
	stctm->tm_mday);
}
const char *zSiscomFecha::Actual3(char *pchrPtrFecha)
{
     zSiscomFecha::Actual2(pchrPtrFecha);
     return pchrPtrFecha;
}
void zSiscomFecha::Actual2(char *pchrPtrFecha)
{
char *lchrArrDias[]={ "Domingo",
		     "Lunes",
		     "Martes",
		     "Miercoles",
		     "Jueves",
		     "Viernes",
		     "Sabado"
		     };
char *lchrArrMeses[]={"",
		      "Enero",
		      "Febrero",
		      "Marzo",
		      "Abril",
		      "Mayo",
		      "Junio",
		      "Julio",
		      "Agosto",
		      "Septiembre",
		      "Octubre",
		      "Noviembre",
		      "Diciembre"};
int lintDia,
    lintDiaSemana,
    lintMes,
    lintAno;

zSiscomFecha::Actual(&lintDia,
		   &lintMes,
		   &lintAno,
		   &lintDiaSemana);
sprintf(pchrPtrFecha,
	"%s %02d de %s del %d",
	lchrArrDias[lintDiaSemana],	
	lintDia,
	lchrArrMeses[lintMes],
	lintAno);
}
zSiscomHora::zSiscomHora()
{

}

void zSiscomHora::Actual(char *pchrPtrHora)
{

time_t regTime;
struct tm *stctm;
regTime=time(NULL);
stctm=gmtime(&regTime);
	sprintf(pchrPtrHora,
		"%02d:%02d:%02d",
		stctm->tm_hour,
		stctm->tm_min,
		stctm->tm_sec);
}

