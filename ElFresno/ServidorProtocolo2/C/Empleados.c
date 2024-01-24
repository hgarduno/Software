#include <Empleados.h>
#include <SQLEmpleados.h>
#include <ComunElFresno.h>
SiscomOperaciones2 *OEmpleados()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenComunicacionElFresno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEmpleados,lSOpOperaciones);
return lSOpOperaciones;


}

SiscomOperaciones2 *OBorraEmpleado()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenComunicacionElFresno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosEmpleados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLBorraEmpleado,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(OperacionesEmpleados,lSOpOperaciones);
return lSOpOperaciones; 
}

void OperacionesEmpleados(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SQLEmpleados");
}
void ArgumentosEmpleados(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLEmpleados",pSAgsSiscom);
}
