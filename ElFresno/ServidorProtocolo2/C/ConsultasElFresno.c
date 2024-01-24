#include <ConsultasElFresno.h>
#include <Empleados.h>
#include <stdlib.h>
SiscomOperaciones2 *OConsultasElFresno()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaElFresno,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}

void ConsultaElFresno(SArgsSiscom *pSAgsSiscom)
{
SSiscomOperaciones2 *lSSOperaciones=0;
SiscomOperaciones2 *lSOpPtrCnsElFresno=0;
SiscomLeeEntradaOperaciones2(pSAgsSiscom);
SiscomCopiaArgumentosConsulta(pSAgsSiscom);
SiscomLog("ConsultaElFresno");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSAgsSiscom->LCSiscomPro2Dat);
SiscomAnexaOperacion2("Empleados",OEmpleados(),&lSSOperaciones);
/*
SiscomAnexaOperacion2("ParametrosEjercicio",OParametrosEjercicio(),&lSSOperaciones); 

*/
lSOpPtrCnsElFresno=SiscomOperaciones2CualEjecuta(
				pSAgsSiscom->chrPtrArgConsulta[0],
				lSSOperaciones,
				ConsultaNoSoportada,
				pSAgsSiscom);
SiscomOperaciones2Ejecuta(lSOpPtrCnsElFresno,pSAgsSiscom);
}
void ConsultaNoSoportada(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("ConsultaNoSoportada");
}
