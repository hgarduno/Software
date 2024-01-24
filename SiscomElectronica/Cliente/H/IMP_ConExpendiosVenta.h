
#ifndef __IMP_CONEXPENDIOSVENTA_H__
#define __IMP_CONEXPENDIOSVENTA_H__
#include <UIC_H_ConExpendiosVenta.h>
#include <zExpendios.h>

class zSiscomConexion;
class SiscomRegistro3;
class SiscomDatCom;
class zExpendio;
class zConexionExpendio;
class QConExpendiosVenta:public ConExpendiosVenta
{
 Q_OBJECT
public:
	QConExpendiosVenta(zSiscomConexion *,
		char **pchrPtrArgumentos,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QConExpendiosVenta();
	int Corriendo();
	const char *DireccionIp();
	int Puerto();
	const char *IdExpendioActual();
	int EsPrincipal();
	int DejaPrecios();

	zConexionExpendio *Expendio(int pint);
	zConexionExpendio *Actual();
	
private:
	
	zExpendios zExpsSiscom;
	zSiscomConexion *zSisConexion;
	zExpendio *zExActual;
	int intDejaPrecios;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ExpendioPrincipal();
	int SeCambioExpendio();
	int Seleccionando();
	const char *IdExpendio();
	const char *Expendio();
	void Muestra();
	void MuestraExpendios();
	void OtroExpendio(SiscomRegistro3 *,SiscomDatCom *);
	void FocoAAceptar();
private slots:
	void SlotOExpendio();
	void SlotExpendio(int,int,int,const QPoint &);
	void SlotAceptar();
	void SlotDejaPrecios();
};
#endif
