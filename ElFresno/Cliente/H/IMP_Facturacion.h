#ifndef __IMP_FACTURACION_H__
#define __IMP_FACTURACION_H__

#include <UIC_H_Facturacion.h>
#include <Facturacion.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLCDNumber;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQ_Persona;
class Factura;

class QFacturacion : public Facturacion
{
    Q_OBJECT

public:
    QFacturacion(CSISCOMDatComunicaciones *,
		 QWidget* parent = 0,
		 const char* name = 0,
		 WFlags fl = 0 );
    ~QFacturacion();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	CQ_Persona *CQPCliente;
	char *chrPtrFechaIni;
	char *chrPtrFechaFin;
	const char *chrPtrConSinIva;
	Factura *FFactura;
	QStringList QSLPFacturacion;
	CQFacturas CQFFacturas;
private:
	void ConectaSlots();
	void ConsultaOrdenes();
	void MuestraOrdenes();
	void IniciaVariables();
	void AnexaOrdenParaFacturar(int);
	void EjecutaFacturacion();
	void MuestraFacturacion();
private slots:
	void S_SelCliente();
	void S_RangoFechas();
	void S_AnexaOrden(int,int,int,const QPoint &);
	void S_NoIncluyeIva();
	void S_IncluyeIva();
};
extern "C" QFacturacion *InstanciaFacturacion(void *,
					      void *,
					      const char *,
					      int );
#endif 
