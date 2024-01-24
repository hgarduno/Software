#ifndef __IMP_RANGOFECHAS_H__
#define __IMP_RANGOFECHAS_H__

#include <UIC_H_RangoFechas.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;

class QRangoFechas : public RangoFechas
{
    Q_OBJECT

public:
	  enum BTN_Opciones
	  {
		  Aceptar,
		  Cancelar
	  };
    QRangoFechas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QRangoFechas();
    BTN_Opciones ObtenSeleccion();
    void ObtenRangoFechas(char **,char **);
private:
    BTN_Opciones BTNOpcion;
private:
    	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_Aceptar();
	void S_Cancelar();
	void S_PasaFocoFechaFin();
	void S_PasaFocoAceptar();
};

#endif 
