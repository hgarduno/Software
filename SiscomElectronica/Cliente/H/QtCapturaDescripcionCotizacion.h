#ifndef __QTCAPTURADESCRIPCIONCOTIZACION_H__
#define __QTCAPTURADESCRIPCIONCOTIZACION_H__

#include <UIC_H_CapturaDescripcionCotizacion.h>
#include <zEscuelas.h>
class zSiscomConexion;
class zOrdenVenta;
class zCotizacionMediaCenter;
class zClienteSiscom;

class QRadioButton;

class zSiscomRegistros;
class QtCapturaDescripcionCotizacion:public CapturaDescripcionCotizacion
{
Q_OBJECT
public:
	QtCapturaDescripcionCotizacion(zOrdenVenta *pzOrdenVenta,
				       zSiscomConexion *pzSisConexion,
				       QWidget *,
				       const char *,
				       bool ,
				       WFlags);
	void IniciaVariables();
	void ConectaSlots();
	zOrdenVenta *Orden();
	zSiscomConexion *Conexion();
	zEscuela *Escuela();
	QRadioButton *Escuela(zEscuela *);
	void HabilitandoAceptar();
	void Cotizando();
	int SoloDescripcion();
	void SoloDescripcion(int);
	void Modo(const char *);
	const char *Modo();
private:
	zSiscomConexion *zSisConexion;
	zOrdenVenta *zOrdVenta;
	zCotizacionMediaCenter *zCotMedCenter;
	zSiscomRegistros *zSisRegsEscuelas;
	zEscuelas zEscuelasS;
	int intCotizando;
	int intSoloDescripcion;
	const char *chrPtrModo;
private:
	void Descripcion();
	void Telefono();
	void Hora();
	void PagaCon();
	zCotizacionMediaCenter *Cotizacion();
	void EscuelasEntrega();
	void MuestraEscuelasEntrega();
	void MuestraEscuelas();
	void HabilitaDesHabilita(bool);
	void TraeEscuela(zClienteSiscom *);
	void ComoInicioCotizacion();
	void LlevandoA(const char *);
	void IniciandoSoloDescripcion();
	void Nombre();
	void HabilitaDesHabilitaEscuelas(bool);
	void TeclasEspeciales(QKeyEvent *);
	void keyPressEvent(QKeyEvent *pQKEvent);

	void Muestra();

private slots:
	void SlotFocoAPagaCon();
	void SlotFocoAAceptar();
	void SlotFocoAHora();
	void SlotAceptar();
	void SlotEscuela(int);
	void SlotSoloDescripcion(int,int);
	void SlotCapturandoDescripcion();
	void SlotCapturaNombre();
	void SlotFocoAEscuela();
};

#endif
