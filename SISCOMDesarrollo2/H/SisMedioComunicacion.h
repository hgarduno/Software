#ifndef __SISMEDIOCOMUNICACION_H__
#define __SISMEDIOCOMUNICACION_H__
#include <SISCOMComunicaciones++.h>
/*!
 * Clase que almacena los datos del medio de comunicacion <br>
 *
 * Esta clase es derivada de SiscomInformacion<br>
 *
 * Contiene los siguientes campos: <br>
 *
 * IdMedio <br>
 * Medio <br>
 * Dato<br>
 * Descripcion<br>
 *
 */
class SisMedCom:public SiscomInformacion
{
public:
	SisMedCom(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	SisMedCom();
	SisMedCom(const char *,
		     const char *,
		     const char *,
		     const char *);
private:
private:
};
/*!
 * Almacena una lista de medios de comunicacion 
 *
 */
class SisLstMedCom:public QPtrList<SisMedCom>
{
public:
	SisLstMedCom();
	SisLstMedCom &operator<<(SisMedCom *);

};
#endif
