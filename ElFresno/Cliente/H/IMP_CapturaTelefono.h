#ifndef __IMP_CAPTURATELEFONO_H__
#define __IMP_CAPTURATELEFONO_H__

#include <UIC_H_CapturaTelefono.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class QCapturaTelefono : public CapturaTelefono
{
    Q_OBJECT

public:
	enum BTN_Opciones
	{
	   Aceptar,
	   Cancelar
	};
    QCapturaTelefono( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaTelefono();
	BTN_Opciones ObtenOpcion();
	const char *ObtenTelefono();
	const char *ObtenDescripcion();
	const char *ObtenTelefonoYDescripcion();
private:
	BTN_Opciones Seleccion;
private:
	void ConectaSlots();
	
private slots:
	void S_PasaFocoDescripcion();
	void S_PasaFocoAceptar();
	void S_Aceptar();
	void S_Cancelar();
	
};

#endif 
