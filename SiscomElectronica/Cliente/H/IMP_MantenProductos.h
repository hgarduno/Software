#ifndef __IMP_MANTENPRODUCTOS_H__
#define __IMP_MANTENPRODUCTOS_H__

#include <UIC_H_MantenProductos.h>
#include <Familias.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QComboBox;
class QLineEdit;
class SiscomDatCom;
class QManProductos;
class ProductoE;
class ManFamilias;
class ManUnidades;
class Unidad;
class QMantenProductos : public MantenProductos
{
    Q_OBJECT

public:
    QMantenProductos(SiscomDatCom *,
    		     const char *,
    		     QWidget* parent = 0, 
		     const char* name = 0, 
		     bool modal = FALSE, 
		     WFlags fl = 0 );
    ~QMantenProductos();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrIdExpendio;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	QLineEdit *QLECFamilias;
	QLineEdit *QLECUnidades;
	ProductoE *PProducto;
	ManFamilias *MFamilias;
	ManUnidades *MUnidades;
	Familia *FFamilia;
	Unidad *UUnidad;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDatos();
private slots:
	void S_SelProducto(ProductoE *);
	void S_SelFamilia(Familia *);
	void S_SelUnidad(Unidad *);
	void S_ModificaProducto();
};

#endif 
