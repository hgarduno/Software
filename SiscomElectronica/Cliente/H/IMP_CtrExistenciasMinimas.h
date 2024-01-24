#ifndef __IMP_CTREXISTENCIASMINIMAS_H__
#define __IMP_CTREXISTENCIASMINIMAS_H__

#include <UIC_H_CtrExistenciasMinimas.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTable;
class QPushButton;
class SiscomDatCom;
class QManProductos;

class QCtrExistenciasMinimas : public CtrExistenciasMinimas
{
    Q_OBJECT

public:
    QCtrExistenciasMinimas(SiscomDatCom *,
    		    char **,
    		    QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCtrExistenciasMinimas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	ProductosE PProductos;
private:
	void IniciaVariables();
	void ConectaSlots();
	void MuestraProductos();
	void closeEvent(QCloseEvent *);
private slots:
	void S_SeleccionoProducto(ProductoE *);
	void S_NoEstaClave(const char *);
	void S_AsignarExistenciaALaLista();
	void S_ActualizarExistencias();
	void S_PasaFocoAsignaEMinima();
	void S_PasaFocoActualizaEMinima();
	void S_Eliminar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCtrExistenciasMinimas *InstanciaCtrExistenciasMinimas(void *,
						   char **,
						   void *,
						   const char *,
						   int );
#endif 
