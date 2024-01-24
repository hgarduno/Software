
#ifndef __IMP_SELECCIONAINVENTARIO_H__
#define __IMP_SELECCIONAINVENTARIO_H__
#include <UIC_H_SeleccionaInventario.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QSeleccionaInventario:public SeleccionaInventario
{
 Q_OBJECT
public:
	QSeleccionaInventario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	 SiscomRegistro3 *Inventario();
	~QSeleccionaInventario();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3InventariosProg;
	SiscomRegistro3 *SisReg3Inventario;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consulta();
	void Consultando();
	void Muestra();
private slots:
	void SlotSeleccionaInventario(int,int,int ,const QPoint &);
};
#endif
