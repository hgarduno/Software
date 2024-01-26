#ifndef __QTIMPPOSICIONESBENEFICIOS_H__
#define __QTIMPPOSICIONESBENEFICIOS_H__
#include <PosicionesBeneficios.h>
#include <QtImprimeBeneficiosIntegrales.h>
class QtImpPosicionesBeneficios:public PosicionesBeneficios
{
Q_OBJECT
public:
	QtImpPosicionesBeneficios(Registro *pRegistro,
				 QWidget *pQWParent=0,
				 const char *pchrPtrName=0,
				 bool pbModal=false,
				 WFlags pWFlags=0);
	void PosicionesAImpresion(Registro *pRegistro);
	int Aceptar();
private:
	void IniciaVariables();
	void IniciaPosiciones();
	void ConectaSlots();
	void PosicionCampo(const char *pchrPtrCampo,int pintNCampo,int pintX,int pintY);
	int TraeInformacionPosiciones();
	void AsignaPosiciones();
	void IncrementandoCamposY(int pintIncremento);
	int CapturaCantidadIncremento();
	void AsignaIncrementoY();
	
private:
	Registro *RegPosiciones;
	int intAceptar;
private slots:
	void SlotIncrementaX();
	void SlotIncrementaY();
	void SlotAceptar();

};

#endif
