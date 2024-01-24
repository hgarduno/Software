#ifndef __IMP_CARGAPEDIDO_H__
#define __IMP_CARGAPEDIDO_H__

#include <UIC_H_CargaPedido.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class QCargaPedido : public CargaPedido
{
    Q_OBJECT

public:
    QCargaPedido(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCargaPedido();
private:
    CSISCOMDatComunicaciones *CSisDatCom;

};
extern "C" QCargaPedido *InstanciaCargaPedido(void *,void *,const char *,int );
#endif 
