#ifndef __IMP_CAPTURAFECHA_H__
#define __IMP_CAPTURAFECHA_H__

#include <UIC_H_CapturaFecha.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;

class QCapturaFecha : public CapturaFecha
{
    Q_OBJECT

public:
    enum BTN_Opciones
    {
	    Aceptar,
	    Cancelar
    };
    QCapturaFecha( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaFecha();
    QString ObtenFecha();
    BTN_Opciones ObtenSeleccion();
private:
    BTN_Opciones Opcion;
private:
    	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_Aceptar();
	void S_Cancelar();
	void S_PasaFocoAceptar();
};

#endif 
