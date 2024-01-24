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
class MedioComunicacion;

class QCapturaTelefono : public CapturaTelefono
{
    Q_OBJECT

public:
    QCapturaTelefono( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaTelefono();
    MedioComunicacion *ObtenTelefono();
    int ObtenSeleccion();
private:
	void ConectaSlots();
	void IniciaVariables();	
private:
	int intSeleccion;
	MedioComunicacion *MCTelefono;
private slots:
	void S_PasaFocoDescripcion();
	void S_PasaFocoAceptar();
	void S_Aceptar();
	void S_Cancelar();
	
};

#endif 
