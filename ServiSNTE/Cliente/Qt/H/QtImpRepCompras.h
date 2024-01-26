#ifndef __QTIMPREPCOMPRAS_H__
#define __QTIMPREPCOMPRAS_H__
#include <RepCompras.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zDatosCompra;
class QtImpRepCompras:public RepCompras
{
	Q_OBJECT
	public:
			QtImpRepCompras(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
		void IniciaVariables();
		void ConectaSlots();
		void Conexion(zSiscomConexion *pzSisConexion);
		void Consultando();
		void Consulta();
		void Muestra();
private:
		zSiscomConexion *zSisConexion;
		zSiscomRegistro *zSisRegProveedor;
		zSiscomRegistro *zSisRegDepartamento;
		zDatosCompra *zDatCompra;
private:
		
private slots:
	void SlotDepartamento(zSiscomRegistro *);
	void SlotProveedor(zSiscomRegistro *);
	void SlotImprimir();

};

#endif
