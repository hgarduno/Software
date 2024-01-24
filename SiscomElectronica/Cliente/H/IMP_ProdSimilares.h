#ifndef __IMP_PRODSIMILARES_H__
#define __IMP_PRODSIMILARES_H__

#include <UIC_H_ProdSimilares.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;

class QProdSimilares : public ProdSimilares
{
    Q_OBJECT

public:
    QProdSimilares(const ProductosE &, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QProdSimilares();
    ProductoE *ObtenProducto();
private:
	ProductosE PProductos;
	ProductoE *Producto;
private:
	void MuestraProductos();
	void ConectaSlots();
private slots:
	void S_SeleccionoProducto(int,int,int,const QPoint &);
};

#endif 
