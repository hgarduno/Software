#ifndef __IMP_CAPTURACONTACTO_H__
#define __IMP_CAPTURACONTACTO_H__

#include <UIC_H_CapturaContacto.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class Persona;

class QCapturaContacto : public CapturaContacto
{
    Q_OBJECT

public:
    QCapturaContacto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaContacto();
    Persona *ObtenContacto();
    int ObtenSeleccion();
private:
	void ConectaSlots();
	void IniciaVariables();
private:
	Persona *PContacto;
	int intSeleccion;
private slots:
	void S_PasaFocoAPaterno();
	void S_PasaFocoAMaterno();
	void S_PasaFocoDescripcion();

	void S_PasaFocoAceptar();
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
