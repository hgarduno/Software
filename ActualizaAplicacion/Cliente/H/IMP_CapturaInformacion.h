#ifndef __IMP_CAPTURAINFORMACION_H__
#define __IMP_CAPTURAINFORMACION_H__

#include <UIC_H_CapturaInformacion.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class QCapturaInformacion : public CapturaInformacion
{
    Q_OBJECT

public:
    QCapturaInformacion(const char *,
			const char *,	
			QWidget* parent = 0,
			const char* name = 0,
			bool modal = FALSE,
			WFlags fl = 0 );
    ~QCapturaInformacion();
     const char *ObtenDato();
	int ObtenCualBoton();
private:
	void ConectaSlots();
private:
	int intBoton;
private slots:
	void S_PasaFocoAceptar();
	void S_Cancelar();
	void S_Aceptar();
};

#endif 
