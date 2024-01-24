#ifndef __IMP_MANTENVEHICULO_H__
#define __IMP_MANTENVEHICULO_H__

#include <UIC_H_MantenVehiculo.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class Vehiculo;
class SiscomDatCom;

class QMantenVehiculo : public MantenVehiculo
{
    Q_OBJECT

public:
    QMantenVehiculo(SiscomDatCom *,
    			Vehiculo *,
    			QWidget* parent = 0,
    		     const char* name = 0,
		     bool modal = FALSE,
		     WFlags fl = 0 );
    ~QMantenVehiculo();
private:
	SiscomDatCom *SDatCom;
	Vehiculo *VVehiculo;
private:
	void MuestraDatos();
	void ConectaSlots();
private slots:
	void S_Modificar();
	void S_Eliminar();
	void S_Cancelar();

};

#endif 
