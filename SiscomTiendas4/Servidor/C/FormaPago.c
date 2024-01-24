#include <FormaPago.h>
#include <SQLFormaPago.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>
SiscomOperaciones2 *OPConsultaFormasPago()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLFormaPago,lSOpOperaciones);
return lSOpOperaciones;
}
