#ifndef __IMP_AVISONOALCANZA_H__
#define __IMP_AVISONOALCANZA_H__

#include <UIC_H_AvisoNoAlcanza.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class ProductoE;

class QAvisoNoAlcanza : public AvisoNoAlcanza
{
    Q_OBJECT

public:
    QAvisoNoAlcanza(ProductoE *,
    			QWidget* parent = 0,
			const char* name = 0,
			bool modal = FALSE,
			WFlags fl = 0 );
    ~QAvisoNoAlcanza();
    int Opcion();
private:
	ProductoE *PProducto;
	int intOpcion;
private:
	void MuestraDatos();
	void ConectaSlots();
private slots:
	void S_VendoLoQueHay();
	void S_CambiaCantidad();
	void S_Eliminar();
};

#endif 
