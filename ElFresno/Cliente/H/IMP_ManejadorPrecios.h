#ifndef __IMP_MANEJADORPRECIOS_H__
#define __IMP_MANEJADORPRECIOS_H__

#include <UIC_H_ManejadorPrecios.h>
#include <TiposPrecios.h>
#include <Precios.h>
#include <GeneralBibliotecaSeguridad3.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTable;
class CSISCOMDatComunicaciones;
class CQSeleccionaProducto;
class Producto;
class QManejadorPrecios : public ManejadorPrecios,
			  private QSiscomSeguridad3
{
    Q_OBJECT

public:
    QManejadorPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
    		      QWidget* parent = 0,
		      const char* name = 0,
		      WFlags fl = 0 );
    ~QManejadorPrecios();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
    CQSeleccionaProducto *CQSProducto;
    QWidget *QWParent;
    QLineEdit *QLECProductos;
    Producto *P_Producto;
    CQ_Persona *CQPCliente;
private:
	void IniciaVariables();
	void ConectaSlots();
	void MuestraPrecios(CQPrecios );
	void ConsultaPreciosDelProducto();

	void BuscaCliente();
private slots:
	void S_SProducto(Producto *);
	void S_AnexarPrecio();
	void S_PasaFocoAnexarPrecio();
	void S_Registrar();
	void S_ModificarPrecio();
	void S_AsignarPreciosAProductos();
	void S_AsignaPreciosDefaultAlCliente();
	void S_SCliente();

	void SlotSeleccionandoProducto(int,int,int,const QPoint &);
};
extern "C" QManejadorPrecios *InstanciaManejadorPrecios(void *,void *,const char *,int);
#endif 
