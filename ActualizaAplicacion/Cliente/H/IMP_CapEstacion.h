#ifndef __IMP_CAPESTACION_H__
#define __IMP_CAPESTACION_H__

#include <UIC_H_CapEstacion.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class Estacion;

class QCapEstacion : public CapEstacion
{
    Q_OBJECT

public:
    QCapEstacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapEstacion();
     Estacion *ObtenEstacion();
	int ObtenBoton();
private:
	Estacion *EEstacion;
	int intBoton;
private:
	void ConectaSlots();
	void AsignaEstacion();
private slots:
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
