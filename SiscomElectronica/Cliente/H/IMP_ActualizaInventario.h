#ifndef __IMP_ACTUALIZAINVENTARIO_H__
#define __IMP_ACTUALIZAINVENTARIO_H__

#include <UIC_H_ActualizaInventario.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class SiscomDatCom;
class QActualizaInventario : public ActualizaInventario
{
    Q_OBJECT

public:
    QActualizaInventario(SiscomDatCom *,
    			 char **,
    			QWidget* parent = 0,
			const char* name = 0,
			bool modal = FALSE,
			WFlags fl = 0 );
    ~QActualizaInventario();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
};

#endif 
