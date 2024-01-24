
#ifndef __IMP_SALIDAMATERIAL_H__
#define __IMP_SALIDAMATERIAL_H__
#include <UIC_H_SalidaMaterial.h>
#include <ProductosE.h>
#include <CQSisMotivosSalidas.h>
class SiscomDatCom;
class CQSisProducto4;
class QSalidaMaterial:public SalidaMaterial
{
 Q_OBJECT
public:
	QSalidaMaterial(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSalidaMaterial();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;

	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	QLineEdit *QLECMotivos;
	ProductosE PProductos;
	int intActivarAnexarProductos;
	CQSisMotivosSalidas CQSMSalidas;
	SiscomRegistro3 *SisReg3Motivo;
	ProductoE *ProdSeleccionado;
	CQSisProducto4 *CQSProductos;
private:
	void ConectaSlots();
	void IniciaVariables();

	void ConsultandoMotivos();
	void ConsultaMotivos();
	void MuestraMotivos();
	void MuestraProductos();
	void EnviaSalida();
	void VerificaExistencia();
private slots:
	void SlotSeleccionoMotivo(int);
	void SlotPasaFocoProductos();
	void SlotSeleccionoProducto(ProductoE *);
	void SlotAnexar();
	void SlotRegistrar();
};
extern "C" QSalidaMaterial *InstanciaSalidaMaterial(void *,char **,void *,const char *,int);
#endif
