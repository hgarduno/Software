#ifndef __QTIMPCAPTURADEPARTAMENTOS_H__
#define __QTIMPCAPTURADEPARTAMENTOS_H__
#include <cstddef>
#include <CapturaDepartamentos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zDepartamento;

class QtImpCapturaDepartamentos:public CapturaDepartamentos
{
Q_OBJECT
public:
	QtImpCapturaDepartamentos(QWidget *pQWParent,
			  const char *pchrPtrName);
	zDepartamento *Departamento();
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	zDepartamento *FormaDepartamento();
private:
	zSiscomConexion *zSisConexion;
	zDepartamento *zDatDepartamento;
private slots:
	void reject();
	void SlotCrear();
	void SlotCancelar();
	void SlotFocoAAbreviatura();
	void SlotFocoANombreDepartamento();
	void SlotFocoACrear();
};



#endif
