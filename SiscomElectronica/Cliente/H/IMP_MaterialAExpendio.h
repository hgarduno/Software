#ifndef __IMP_MATERIALAEXPENDIO_H__
#define __IMP_MATERIALAEXPENDIO_H__

#include <UIC_H_MaterialAExpendio.h>
#include <TransfiereProducto.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QIconView;
class QIconViewItem;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTable;
class SiscomDatCom;
class EmpresaN;
class QManProductos;
class ProductoE;

class QMaterialAExpendio : public MaterialAExpendio
{
    Q_OBJECT

public:
    QMaterialAExpendio(SiscomDatCom *,
    			char **,
    			QWidget* parent = 0,
			const char* name = 0,
			WFlags fl = 0 );
    ~QMaterialAExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	EmpresaN *EExpendio;
	EmpresaN *EMatriz;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	ProductoE *PProducto;
	RegsProductoTransfiere RegsProTransfiere;
	int intProductoActual;
private:
	void ConectaSlots();
	void ConsultaMatriz();
	void IniciaVariables();
	int VerificaExistencia(char *);
	void ListaNoAlcanza(SiscomRegistrosPro2 *pSisReg2NoAlcanza);
	void MuestraProductosATransferir();
	void closeEvent(QCloseEvent *);
private slots:
	void S_SeleccionaExpendio();
	void S_Producto(ProductoE *);
	void S_PasaFocoAnexar();
	void S_Anexar();
	void S_RegistraEnvio();
	void S_Eliminar();
	void S_Producto(int,int,int, const QPoint &);
	void S_CambiaCantidad();
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QMaterialAExpendio *InstanciaMaterialAExpendio(void *,
						char **,
						void *,
						const char *,
						int );
#endif 
