#ifndef __QTIMPMULTIAPOYOS_H__
#define __QTIMPMULTIAPOYOS_H__
#include <MultiApoyos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpMultiApoyos:public MultiApoyos
{
Q_OBJECT
public:
	QtImpMultiApoyos(QWidget *pQWParent=0,
					  const char *pchrPtrName=0);
	zSiscomRegistro *Credito();
	int Aceptar();
private:
	void IniciaVariables();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void Formato();
	int Consultando();
	int Consulta();
	void Muestra();
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
	int intAceptar;
	char *chrPtrFormato;
	char *chrPtrSalida;
private slots:
	void SlotCancelar();
	void SlotAceptar();
	void SlotSeleccionaCredito(int,int,int,const QPoint &);
};

#endif

