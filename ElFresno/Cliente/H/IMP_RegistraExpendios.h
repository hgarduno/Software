#ifndef __IMP_REGISTRAEXPENDIOS_H__
#define __IMP_REGISTRAEXPENDIOS_H__

#include <IMP_ManejadorProveedores.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QTable;
class QPushButton;
class CSISCOMDatComunicaciones;
class QRegistraExpendios: public QManejadorProveedores
{
    Q_OBJECT

public:
    QRegistraExpendios(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QRegistraExpendios();
private:
    CSISCOMDatComunicaciones *CSisDatCom;
};
extern "C" QRegistraExpendios *InstanciaRegistraExpendios(void *,void *,const char *,int );
#endif 
