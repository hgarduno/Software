
#ifndef __IMP_ANEXARFACTURA_H__
#define __IMP_ANEXARFACTURA_H__
#include <UIC_H_AnexarFactura.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QAnexarFactura:public AnexarFactura
{
 Q_OBJECT
public:
	QAnexarFactura(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QAnexarFactura();
	int Opcion();
	SiscomRegistro3 *Factura();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstFacturas;
	SiscomRegistro3 *SisReg3Factura;
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void QueHagoDespuesConsulta();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotConsultaFactura();
	void SlotSeleccionaFactura(int,int,int,const QPoint &);
};
#endif
