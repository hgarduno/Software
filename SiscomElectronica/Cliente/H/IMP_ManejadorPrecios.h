#ifndef __IMP_MANEJADORPRECIOS_H__
#define __IMP_MANEJADORPRECIOS_H__

#include <UIC_H_ManejadorPrecios.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTable;
class SiscomDatCom;
class ManTipoPrecio;
class TipoPrecio;
class QManProductos;
class ProductoE;
class QManejadorPrecios : public ManejadorPrecios
{
    Q_OBJECT

public:
    QManejadorPrecios(SiscomDatCom *,char **, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QManejadorPrecios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ManTipoPrecio *MTipoPrecio;
	TipoPrecio *TTipoPrecio;
	QLineEdit *QLECTipoPrecio;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	ProductoE *PProducto;
private:
	void IniciaVariables();
	void ConectaSlots();
	int ConsultaPrecioProducto();
	void closeEvent(QCloseEvent *);
	void HabilitaDesHabilita(bool);
private slots:
	void S_TipoPrecio(TipoPrecio *);
	void S_Producto(ProductoE *);
	void S_NoEstaLaClave(const char *);
	void S_RegistrarPrecio();
	void S_PasaFocoRegistrarPrecio();
	void S_HabilitandoRegistro(const QString &);
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QManejadorPrecios *InstanciaManejadorPrecios(void *,char **,void *,const char *,int);
#endif 
