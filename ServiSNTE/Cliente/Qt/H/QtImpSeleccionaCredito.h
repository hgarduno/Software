#ifndef __QTIMPSELECCIONACREDITO_H__
#define __QTIMPSELECCIONACREDITO_H__
#include <cstddef>
#include <SeleccionaCredito.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zCreditosCliente;
class zDireccion;
class QtImpSeleccionaCredito:public SeleccionaCredito
{
Q_OBJECT
public:
	QtImpSeleccionaCredito(QWidget *pQWParent=0,
			       const char *pchrPtrName=0,
				bool pbModal=false,
			       WFlags pWFlags=false);
	zSiscomRegistro *Cliente();
	zSiscomRegistro *Credito();
	zDireccion *Direccion();
	int Aceptar();
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();
	int ConsultaCreditos();
	void MuestraCreditos();
	void MuestraCliente();
	void ConsultandoCreditos();
	void reject();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsCreditos;
	zSiscomRegistro *zSisRegCliente;
	zSiscomRegistro *zSisRegCredito;
	zCreditosCliente *zCredsCliente;
	int intAceptar;
private slots:

	void SlotRFC();
	void SlotSeleccionaApartado(int ,int,int,const QPoint &);
	void SlotAceptar();
	void SlotCancelar();
};

#endif
