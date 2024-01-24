#ifndef __IMP_OPCIONCERRAR_H__
#define __IMP_OPCIONCERRAR_H__

#include <UIC_H_OpcionCerrar.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;

class QOpcionCerrar : public OpcionCerrar
{
    Q_OBJECT

public:
    QOpcionCerrar( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QOpcionCerrar();
    enum Opciones
    {
    	Realizar_Venta ,
	Cancelar_Venta
    };
    Opciones ObtenSeleccion();
private:
	Opciones OpcSeleccionada;
 private:
 	void closeEvent(QCloseEvent *);
	void ConectaSlots();
private slots:
	void S_Cancelar();
	void S_RealizarVenta();
};

#endif 
