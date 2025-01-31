#ifndef __SISCOMELECTRONICA_H__
#define __SISCOMELECTRONICA_H__
#include <SiscomVentanaPrincipal.h>
#include <zXY.h>

class Persona;
class EmpresaN;
class SiscomDatCom;
class QPopupMenu;
class SiscomRegistro3;
class zManejadorEjecucion;
class SiscomElectronica:public SiscomVentanaPrincipal
{

Q_OBJECT
public:
	SiscomElectronica(zManejadorEjecucion*,QApplication *pQAppPrincipal);
	Persona *ObtenEmpleado();
private:
	void FirmaAlSistema();
	void AccesoSiscomElectronica();
	void SiscomIniciaSeguridad();
	void SiscomIniciaMenuVentanas();
	void ColocaEncabezado();
	void closeEvent(QCloseEvent *);
	SiscomRegistro3 *ExpendioRegistro3();
	void customEvent(QCustomEvent *);
	void AsignaConexionVersion4(SiscomDatCom *);
	void SeleccionandoExpendio();
	void OrganizaVentanas();
	void IniciaVariables();
	void Redimensiona();
protected:
	void keyPressEvent(QKeyEvent *pQKEvent);
	void resizeEvent(QResizeEvent *);
	void PosicionVentana(QWidget *,zXY *);
	void MasGrandeLetra();
	void MasPequenaLetra();
private:
	Persona *Empleado;
	EmpresaN *Expendio;
	QPopupMenu *QPMVentanas;
	zXYArreglo zXYModulos;
	zXY zXYPedido;
	zXY zXYVenta;
	zManejadorEjecucion *zMnEjecucion;
	QApplication *QAppPrincipal;

	
private slots:
	void SlotCargaModuloAdministracion();
};

#endif


