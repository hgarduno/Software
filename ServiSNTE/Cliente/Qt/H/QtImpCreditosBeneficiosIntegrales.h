#ifndef __QTIMPCREDITOSBENEFICIOSINTEGRALES_H__
#define __QTIMPCREDITOSBENEFICIOSINTEGRALES_H__
#include <CreditosBeneficiosIntegrales.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpCreditosBeneficiosIntegrales:public CreditosBeneficiosIntegrales
{
Q_OBJECT
public:
	QtImpCreditosBeneficiosIntegrales(QWidget *pQWParent=0,
					  const char *pchrPtrName=0,
					  bool pBolModal=false,
					  WFlags pWFlags=false);
	zSiscomRegistro *Credito();
	int Aceptar();
private:
	void IniciaVariables();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void reject();
	int Consultando();
	int Consulta();
	void Muestra();
	void ConectaSlots();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegCredsBeneficios;
	zSiscomRegistros *zSisRegsCreditos;
	zSiscomRegistro *zSisCredito;
	int intAceptar;
	int intCreditoSeleccionado;
private slots:
	void SlotCancelar();
	void SlotAceptar();
	void SlotSeleccionaCredito(int,int,int,const QPoint &);
};

#endif

