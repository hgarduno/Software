
#ifndef __IMP_BUSCAPROVEEDOR_H__
#define __IMP_BUSCAPROVEEDOR_H__
#include <UIC_H_BuscaProveedor.h>
class SiscomDatCom;
#include <SiscomRegistros3.h>
class QBuscaProveedor:public BuscaProveedor
{
 Q_OBJECT
public:
	QBuscaProveedor(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QBuscaProveedor();
	int Opcion();
	SiscomRegistro3 *Proveedor();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstProveedores;
	SiscomRegistro3 *SisReg3Proveedor;
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Muestra(int );
	void Consulta();
	void LlenaCombo();
private slots:
	void SlotSeleccionando(int pintProveedor);
	void SlotSelecciono(int pintProveedor);
	void SlotAceptar();
	void SlotCancelar();
};
#endif
