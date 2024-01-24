#ifndef __IMP_COTIZADISPOSITIVOS_H__
#define __IMP_COTIZADISPOSITIVOS_H__

#include <UIC_H_CotizaDispositivos.h>
#include <Seguridad3Protocolo2.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QLCDNumber;
class QPushButton;
class SiscomDatCom;

class QCotizaDispositivos : public CotizaDispositivos,
			    public Seguridad3Protocolo2

{
    Q_OBJECT

public:
    QCotizaDispositivos(SiscomDatCom *,
    			const char *,
    			const char *,
			const char *,
    			QWidget* parent = 0,
			const char* name = 0,
			WFlags fl = 0 );
    ~QCotizaDispositivos();
    void setFocus();
private:
	SiscomDatCom *SisDatCom;
	ProductosE PProductos;
	ProductoE *PProducto;
	QLineEdit *QLEDispositivo;
	const char *chrPtrIdExpendio;
	const char *chrPtrNmbTipoPrecio;
private:
	void ConsultaProductos();
	void IniciaVariables();
	void ConectaSlots();
	void CotizaDispositivo();
	int EsParteLista(const char *);
	void ConsultaClavesSimilares(const char *);
	
	void BuscaProductosPorDescripcion(const char *);
private slots:
	void S_PasaFocoDispositivo();
	void S_PasaFocoAnexarOrden();
	void S_MuestraDescripcion(int);
	void S_AnexarALaOrden();
	void S_ProductosPorDescripcion();
signals:
	void SignalAnexarALaOrden(ProductoE *);
};

#endif 
