#ifndef __IMP_PRODUCTOPRACTICA_H__
#define __IMP_PRODUCTOPRACTICA_H__

#include <UIC_H_ProductoPractica.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QLCDNumber;
class SiscomDatCom;
class QManProductos;
class ProductoE;
class QProductoPractica : public ProductoPractica
{
    Q_OBJECT

public:
    QProductoPractica(SiscomDatCom *,
    		      const char *,
		      const char *, 
		      QWidget* parent = 0,
		      const char* name = 0,
		      bool modal = FALSE,
		      WFlags fl = 0 );
    ~QProductoPractica();
    ProductoE *ObtenProducto();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdExpendio;
	const char *chrPtrNmbTipoPrecio;
	QManProductos *QMProductos;
	ProductoE *PProducto;
	QLineEdit *QLECProductos;
private:
	void IniciaVariables();
	void ConectaSlots();
private slots:
	void S_SeleccionoProducto(ProductoE *);
	void S_PasaFocoAnexar();
	void S_Anexar();
};

#endif 
