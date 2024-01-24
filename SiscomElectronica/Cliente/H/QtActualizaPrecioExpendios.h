#ifndef __QTACTUALIZAPRECIOEXPENDIOS_H__
#define __QTACTUALIZAPRECIOEXPENDIOS_H__
#include <UIC_H_ActualizaPrecioExpendios.h>
class SiscomDatCom;
class ManTipoPrecio;
class TipoPrecio;
class ProductoE;
class SiscomRegistro3;

class zSiscomConexion;
class zSiscomRegistro;
class zProductoPrecioExpendios;
class zEmpresas;
class zPrecio;

class QLineEdit;
class QtActualizaPrecioExpendios:public ActualizaPrecioExpendios
{
Q_OBJECT
public:
	QtActualizaPrecioExpendios(SiscomDatCom *pSisDatCom,
				   char **pchrPtrArgumentos,
				   QWidget *pQWParent,
				   const char *,
				   WFlags );
	void IniciaVariables();
	void ConectaSlots();
	virtual void Actualizando();
	const char *Clave();
	zEmpresas *Expendios();
	zPrecio *TipoPrecioSeleccionado();
	const char *PrecioNuevo();
private:
	SiscomDatCom *SisDatCom;
	zSiscomConexion *zSisConexion;
	ManTipoPrecio *MTipoPrecio;
	TipoPrecio *TTipoPrecio;
	QLineEdit *QLECTipoPrecio;
	zSiscomRegistro *zSisRegProducto;
	char **chrPtrArgumentos;
	ProductoE *PProducto;
	zEmpresas *zEExpendios;
private:
	void Variables();
	void IniciaTipoPrecio();
	void IniciaProductos();
	void IniciaExpendios();
	void MuestraDescripcion();
	ProductoE *Producto(zSiscomRegistro *);
	int ConsultaPrecioProducto();
	void ConsultandoPrecioProducto();
	void PasandoFocoNuevoPrecio();
	void AgregandoExpendio(zSiscomRegistro *);
	void MuestraExpendios();
	void HabilitaInterfazCaptura(bool);
private slots:
	void SlotTipoPrecio(TipoPrecio *);
	void SlotProducto(zSiscomRegistro *);
	void SlotExpendio(SiscomRegistro3 *);
	void SlotActualiza();
	void SlotFocoAActualizar();
	void SlotHabilitandoActualizar(const QString &);
};

#endif
				
