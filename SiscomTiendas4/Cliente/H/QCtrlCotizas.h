#ifndef __QCTRLCOTIZA_H__
#define __QCTRLCOTIZA_H__
#include <qwidget.h>
#include <qwidgetplugin.h>

class QCtrlClientes;
class QCtrlContactos;
class QCtrlFormaPago;
class QCtrlPrecios;
class QCtrlProductos;

class QHBoxLayout;
class SiscomDatCom;
class QVBoxLayout;
class QSisHEspacio;
class QGridLayout;
class QLabel;
class QLineEdit;
class QLCDNumber;
class QTextEdit;
class CQSisCliente;
class CQSisFormaPago;
class CQSisPrecio;
class CQSisProducto;
class CQSisProdCotiza;
class CQSisContacto;

class QT_WIDGET_PLUGIN_EXPORT QCtrlCotizas: public QWidget
{
    Q_OBJECT
public:
    QCtrlCotizas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void ConElCliente(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	QGridLayout *QGLRegilla;
	QSisHEspacio *QSHECliCoFPago;
	QSisHEspacio *QSHEPreProCaImp;
	QSisHEspacio *QSHEPreProImpProd;
	QVBoxLayout *QVBLDisplays;
	SiscomDatCom *SisDatCom;
	QCtrlClientes *QCtrClientes;
	QCtrlContactos *QCtrContactos;
	QCtrlFormaPago *QCtrFPago;
	QCtrlPrecios *QCtrPrecios;
	QCtrlProductos *QCtrProductos;

	QLabel *QLClientes;
	QLabel *QLCliente;
	QLabel *QLContactos;
	QLabel *QLFPago;
	QLabel *QLPrecios;
	QLabel *QLProductos;
	QLabel *QLCantidad;
	QLabel *QLImporte;
	QLabel *QLDescripcion;
	QLabel *QLPreProducto;
	QLabel *QLImProducto;
	QLabel *QLExistencia;
	QLabel *QLTotal;


	QLineEdit *QLECantidad;
	QLineEdit *QLEPImporte;
	QLineEdit *QLECliente;
	QTextEdit *QTEDsc;
	QLCDNumber *QLCDNExistencia;
	QLCDNumber *QLCDNPrecio;
	QLCDNumber *QLCDNImporte;
	QLCDNumber *QLCDNTotal;

	CQSisCliente *CQSCliente;
	CQSisFormaPago *CQSFPago;
	CQSisPrecio *CQSPrecio;
	CQSisProducto *CQSProducto;
	CQSisProdCotiza *CQSPCotiza;
	CQSisContacto *CQSContacto;

private:
	void IniciaVariables();
	void IniciaInterfaz();
	void IniciaControles();
	void ConsultaCotizas();
	void MuestraCotizas();
	void ConectaSlots();
	QVBoxLayout *Clientes();
	QVBoxLayout *Contactos();
	QVBoxLayout *FormaPago();
	QVBoxLayout *Precios();
	QVBoxLayout *Productos();
	QVBoxLayout *ClienteDescripcion();
	QLabel *CreaEtiqueta(const char *,const char *);
	QLineEdit *CreaEdit(const char *);
	QTextEdit *CreaTextEdit(const char *);
	QVBoxLayout *CreaDisplayEtiqueta(const char *,
					const char *,
					const char *,
					QLCDNumber **,
					QLabel **);
	
	void MuestraContactos();
	void MuestraDescripcion();
	void MuestraCotizacion();
	void Cotiza();
	CQSisProdCotiza *ProductoCotiza();
private slots:
	void SlotFisica(CQSisCliente *);
	void SlotMoral(CQSisCliente *);
	void SlotFormaPago(CQSisFormaPago *);
	void SlotPrecio(CQSisPrecio *);
	void SlotProducto(CQSisProducto *);
	void SlotCotiza();
signals:
	void SignalCotizacion(CQSisCliente *,
			      CQSisFormaPago *,
			      CQSisPrecio *,
			      CQSisProducto *,
			      CQSisProdCotiza *,
			      CQSisContacto *);
	void SignalClienteFisica(CQSisCliente *);
};

#endif

