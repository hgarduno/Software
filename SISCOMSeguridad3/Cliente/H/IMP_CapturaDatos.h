#ifndef __CQSISCAPTURADATOS_H__
#define __CQSISCAPTURADATOS_H__

#include <UIC_H_CapturaDatos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;

class CQSisCapturaDatos : public CapturaDatos
{
    Q_OBJECT

public:
	enum BTN_Seleccion
	{
	    BTN_Aceptar,
	    BTN_Cancelar
	};
    CQSisCapturaDatos(QString, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    BTN_Seleccion ElBotonSeleccionado(); 
    QString ObtenDatoNuevo();	
    ~CQSisCapturaDatos();
private:
	QString QSDato;
	BTN_Seleccion BTN_Boton;
private:
	void ConectaSlots();
private slots:
	void SlotAceptar();	
	void SlotCancelar();
};

#endif 
