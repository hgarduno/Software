#ifndef __ZPRACTICA_H__
#define __ZPRACTICA_H__
#include <zSiscomRegistro.h>
class zSiscomRegistros;
class zPractica:public zSiscomRegistro
{
public:
	zPractica();
	void Producto(zSiscomRegistro *pzSisRegProducto);
	void Nombre(const char *pchrPtrNombre);
	void Materia(const char *pchrPtrMateria);
	void Escuela(zSiscomRegistro *pzSisRegEscuela);
	void Productos(zSiscomRegistros *pzSisRegsProductos);
	zSiscomRegistros *Productos();
	int DatosPractica();
	int DatosProfesor();

	void Practica(zSiscomRegistro *pzSisRegPractica);
private:
	 void HayDatosPractica(zSiscomRegistro *);
	 void HayDatosProfesor(zSiscomRegistro *);
private:
	int intDatosPractica;
	int intDatosProfesor;

};
#endif
