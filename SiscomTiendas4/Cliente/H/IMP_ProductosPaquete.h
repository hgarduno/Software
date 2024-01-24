
#ifndef __IMP_PRODUCTOSPAQUETE_H__
#define __IMP_PRODUCTOSPAQUETE_H__
#include <UIC_H_ProductosPaquete.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QProductosPaquete:public ProductosPaquete
{
 Q_OBJECT
public:
	QProductosPaquete(SiscomDatCom *,
	    char **,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductosPaquete();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrIdPaquete;
	const char *chrPtrIdProducto;
	SiscomRegistro3Lst SReg3LstProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
private slots:
	void SlotElimina();
	void SlotAnexar();
	void SlotCambiarCantidad();
	void SlotSeleccionaProducto(int,int,int,const QPoint &);
};
#endif
