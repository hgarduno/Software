#ifndef __ZDIRECCIONCOMUNICACION_H__
#define __ZDIRECCIONCOMUNICACION_H__
#include <zSiscomRegistro.h>
/* Martes 05 de enero 2016
 * Clase que permite almacenar la informacion para 
 * la pantalla de Beneficios integrales, y poder 
 * encapsular los datos de direccion y comunicacion 
 * mas tipo de vivienda de la pantalla de, 
 * CapturaDireccionParticular
 */

class zDireccion;
class zDireccionComunicacion:public zSiscomRegistro
{
public:
	zDireccionComunicacion(zDireccion *pzDireccion);
private:
	zDireccion *zDirDato;
};
#endif
