#ifndef __IMP_INVENTARIO_H__
#define __IMP_INVENTARIO_H__

#include <UIC_H_Inventario.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class SiscomRegistro3;
class QInventario : public Inventario
{
    Q_OBJECT

public:
    QInventario(SiscomDatCom *,
    	        char **,
		QWidget* parent = 0,
		const char* name = 0, 
		WFlags fl = 0 );

    ~QInventario();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ProductosE PProductos;
	ProductoE *PProducto;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	/*
	 * Viernes 23 De Septiembre 2011
	 * Por la problematica del desajuste en el inventario
	 *
	 */
	SiscomRegistro3 *SisReg3Motivo;
	SiscomRegistro3 *SisReg3Inventario;
	int intInventarioPorDesajuste;

	const char *chrPtrExistenciaFisica;
private:
	void IniciaVariables();
	void ConectaSlots();
	void closeEvent(QCloseEvent *);
	void RegistroPorDesajuste();
	void SeleccionaInventario();
	void CapturaExistenciaFisica();
private slots:
	void S_SelProducto(ProductoE *);
	void S_PasaFocoRegistrar();
	void S_Registrar();
	void S_Actualiza();
	void S_NoEstaClave(const char *);
	/* 
	 * Viernes 23 De Septiembre 2011
	 */
	void SlotPasaFocoProductos(SiscomRegistro3 *);
	void SlotActivaMotivoInventario();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QInventario *InstanciaInventario(void *,char **,void *,const char *,int);
#endif 
