#ifndef __IMP_SELORDEN_H__
#define __IMP_SELORDEN_H__

#include <UIC_H_SelOrden.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;
class QIconVOrdenE;
class QOrdenElectronica;
class QSelOrden : public SelOrden
{
    Q_OBJECT

public:
    QSelOrden(QIconView *,
    	      QWidget* parent = 0,
	      const char* name = 0, 
	      bool modal = FALSE, 
	      WFlags fl = 0 );
~QSelOrden();
	QOrdenElectronica *ObtenOrden();
	int ObtenSeleccion();

private:
	void AnexaOrdenesDisponibles(QIconView *);
	void ConectaSlots();
private slots:
	void S_SeleccionaOrden(QIconViewItem *);
	void S_SeleccionoOrden(QIconViewItem *);
	void S_Cancelar();
	void S_Aceptar();
private :
	int intOpcion;
	QOrdenElectronica *QOElectronica;
	
};

#endif 
