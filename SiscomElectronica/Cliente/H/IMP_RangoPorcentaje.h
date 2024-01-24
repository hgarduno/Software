#ifndef __IMP_RANGOPORCENTAJE_H__
#define __IMP_RANGOPORCENTAJE_H__

#include <UIC_H_RangoPorcentaje.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class QRangoPorcentaje : public RangoPorcentaje
{
    Q_OBJECT

public:
    QRangoPorcentaje( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QRangoPorcentaje();
    void ObtenRango(char *,char *);
    int ObtenOpcion();
private:
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_PasaFocoPorcentajeAlto();
	void S_PasaFocoAceptar();
	void S_Aceptar();
	void S_Cancelar();
};

#endif 
