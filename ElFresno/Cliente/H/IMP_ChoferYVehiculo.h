#ifndef __IMP_CHOFERYVEHICULO_H__
#define __IMP_CHOFERYVEHICULO_H__

#include <UIC_H_ChoferYVehiculo.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQSeleccionaVehiculo;
class Vehiculo;
class CQSeleccionaChoferes;
class Chofer;

class QChoferYVehiculo : public ChoferYVehiculo
{
    Q_OBJECT

public:
	enum BTN_Opciones
	{
	    BTN_Aceptar,
	    BTN_Cancelar
	};
    QChoferYVehiculo(const char *,
    		     const char *,
		     const char *,
			CSISCOMDatComunicaciones *,
		     QWidget* parent = 0,
			 const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QChoferYVehiculo();
	Vehiculo *ObtenVehiculo();
	Chofer *ObtenChofer();
	BTN_Opciones ObtenSeleccion();

private:
	CSISCOMDatComunicaciones *CSisDatCom;
	CQSeleccionaVehiculo *CQSVehiculo;
	CQSeleccionaChoferes *CQSChofer;
	QWidget *QWParent;
	QLineEdit *QLECPlacas;
	QLineEdit *QLECChofer;
	Vehiculo *V_Vehiculo;
	Chofer *C_Chofer;
	BTN_Opciones BTN_Seleccion;
	const char *chrPtrIdChoferes;
	const char *chrPtrFechaIni;
	const char *chrPtrFechaFin;
private:
	void IniciaVariables();
	void PedidosAsignadosAlVehiculo();
	void ConectaSlots();
private slots:
	void S_Vehiculo(Vehiculo *);
	void S_Chofer(Chofer *);
	void S_Seleccionar();
	void S_Cancelar();
	
};

#endif 
