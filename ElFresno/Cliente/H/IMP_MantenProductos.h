#ifndef __IMP_MANTENPRODUCTOS_H__
#define __IMP_MANTENPRODUCTOS_H__

#include <UIC_H_MantenProductos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class CSISCOMDatComunicaciones;
class Unidad;
class Familia;
class CQSeleccionaFamilia;
class CQSeleccionaUnidades;
class CQSeleccionaProducto;
class Producto;

class QMantenProductos : public MantenProductos
{
    Q_OBJECT

public:
    QMantenProductos(SiscomDatCom *pSisDatCom,
    		     CSISCOMDatComunicaciones *,
    		     QWidget* parent = 0,
		     const char* name = 0,
		     bool modal = FALSE,
		     WFlags fl = 0 );
    ~QMantenProductos();
private:
	
    	CQSeleccionaFamilia *CQSFamilia;
    	CQSeleccionaUnidades *CQSUnidades;
	CQSeleccionaProducto *CQSProducto;
	SiscomDatCom *SDatCom;
	CSISCOMDatComunicaciones *CSisDatCom;
	QLineEdit *QLECFamilias;
	QLineEdit *QLECUnidades;
	QLineEdit *QLECProducto;
	QWidget *QWParent;
	Producto *PProducto;
	Unidad *UUnidad;
	Familia *FFamilia;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_SeleccionoUnidad(Unidad *);
	void S_SeleccionoFamilia(Familia *);
	void S_SeleccionoProducto(Producto *);
		
	void S_ModificaProducto();
	void S_Cancelar();
};

#endif 
