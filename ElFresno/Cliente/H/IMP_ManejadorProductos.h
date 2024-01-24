#ifndef __IMP_MANEJADORPRODUCTOS_H__
#define __IMP_MANEJADORPRODUCTOS_H__

#include <UIC_H_ManejadorProductos.h>
#include <Productos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class CQSeleccionaFamilia;
class CQSeleccionaUnidades;
class CSISCOMDatComunicaciones;
class Familia;
class SiscomDatCom;

class QManejadorProductos : public ManejadorProductos
{
    Q_OBJECT

public:
    QManejadorProductos(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QManejadorProductos();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    SiscomDatCom *SDatCom;
    CQSeleccionaFamilia *CQSFamilia;
    CQSeleccionaUnidades *CQSUnidades;
    QWidget *QWParent;	
    QLineEdit *QLECFamilias;
    QLineEdit *QLECUnidades;

    Familia *F_Familia;
    Unidad *U_Unidad;
    CQProductos CQ_Productos;
private:
	void IniciaVariables();
	void ConectaSlots();
private slots:
	void S_SeleccionoFamilia(Familia *);
	void S_SeleccionoUnidad(Unidad *);
	void S_PasaFocoDescripcion();
	void S_PasaFocoAnexar();
	void S_PasaFocoUnidades();
	void S_Registrar();
	void S_Anexar();
	void S_ModificaProducto();
};
extern "C" QManejadorProductos *InstanciaManejadorProductos(void *,void *,const char *,int );
#endif 
