#ifndef __IMP_EXTNOALCANZAN_H__
#define __IMP_EXTNOALCANZAN_H__

#include <UIC_H_ExtNoAlcanzan.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;

class QExtNoAlcanzan : public ExtNoAlcanzan
{
    Q_OBJECT

public:
    QExtNoAlcanzan( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QExtNoAlcanzan();
    void PonProductos(const ProductosE &);
    void MuestraProductos();
private:
	ProductosE PProductos;
};

#endif 
