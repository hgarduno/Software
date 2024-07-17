#include <zDenominaciones.h>
#include <zDenominacion.h>
#include <zSiscomDesarrollo4.h>
zDenominaciones::zDenominaciones()
{

}
zDenominaciones::zDenominaciones(zSiscomRegistros *pzDenominaciones)
{
zSiscomRegistro *lzSisRegDato;
for(lzSisRegDato=pzDenominaciones->Primer();
    lzSisRegDato;
    lzSisRegDato=pzDenominaciones->Siguiente())
   Agrega(new zDenominacion(lzSisRegDato));
}
zDenominaciones &zDenominaciones::operator<<(zDenominacion *pzDenominacion)
{
	Agrega(pzDenominacion);
	return *this;
}

/* Ecatepec a Miercoles 16 de Junio 2021 
 *
 * ya en semaforo verde COVID, pero no regresan aun los del IPN
 * termina el semestre ...
 *
 *
 *
 * Debo ver como regresar el importe total de las 
 * cantidades de cada una de las denominaciones 
 */

zDenominacion *zDenominaciones::Denominacion(int pintFila,int pintColumna)
{
zDenominacion *lzDenoD;
for(lzDenoD=(zDenominacion *)Primer();lzDenoD;lzDenoD=(zDenominacion *)Siguiente())
{
   if((lzDenoD->Fila() == pintFila && 
       lzDenoD->Columna()+1 == pintColumna))
    return lzDenoD;
}
return 0;
}
void zDenominaciones::Actualiza(zSiscomRegistros *pzSisRegsDatos)
{
zDenominacion *lzDeno;
for(lzDeno=(zDenominacion *)Primer() ;lzDeno;lzDeno=(zDenominacion *)Siguiente())
       Actualiza(lzDeno,pzSisRegsDatos);
}
int zDenominaciones::Actualiza(zDenominacion *pzDeno,
			       zSiscomRegistros *pzSisRegsDatos)
{
zDenominacion *lzDeno;
for(lzDeno=(zDenominacion *)pzSisRegsDatos->Primer();
    lzDeno;
    lzDeno=(zDenominacion *)pzSisRegsDatos->Siguiente())
if((*pzDeno)==(*lzDeno))
{
 pzDeno->Importe(lzDeno->Importe());
 return 1;
}
return 0;
}
		


void zDenominaciones::ActualizaCantidades(zDenominaciones *pzDenominacionesAct)
{
zDenominacion *lzDenominacion;

for(lzDenominacion=(zDenominacion *)Primer();
     lzDenominacion;
     lzDenominacion=(zDenominacion *)Siguiente())
  ActualizaCantidad(lzDenominacion,pzDenominacionesAct);
}
void zDenominaciones::ActualizaCantidad(zDenominacion *pzDenominacion,
					zDenominaciones *pzDenominacionesAct)
{
 zDenominacion *lzDenominacion;

 for(lzDenominacion=(zDenominacion *)pzDenominacionesAct->Primer();
     lzDenominacion;
     lzDenominacion=(zDenominacion *)pzDenominacionesAct->Siguiente())
 {
   if((*lzDenominacion)==(*pzDenominacion))
   {
       pzDenominacion->Cantidad(lzDenominacion->Cantidad());
       break;
   }
 }
}



void zDenominaciones::ActualizaImportes(zDenominaciones *pzDenominacionesAct)
{
zDenominacion *lzDenominacion;

for(lzDenominacion=(zDenominacion *)Primer();
     lzDenominacion;
     lzDenominacion=(zDenominacion *)Siguiente())
  ActualizaImporte(lzDenominacion,pzDenominacionesAct);
}
void zDenominaciones::ActualizaImporte(zDenominacion *pzDenominacion,
					zDenominaciones *pzDenominacionesAct)
{
 zDenominacion *lzDenominacion;

 for(lzDenominacion=(zDenominacion *)pzDenominacionesAct->Primer();
     lzDenominacion;
     lzDenominacion=(zDenominacion *)pzDenominacionesAct->Siguiente())
 {
   if((*lzDenominacion)==(*pzDenominacion))
   {
       pzDenominacion->Importe(lzDenominacion->Importe());
       break;
   }
 }
}
