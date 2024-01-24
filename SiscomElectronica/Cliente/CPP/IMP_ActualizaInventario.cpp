#include <IMP_ActualizaInventario.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QActualizaInventario::QActualizaInventario(SiscomDatCom *pSisDatCom,
					   char **pchrPtrArgumentos,
					   QWidget* parent,
					   const char* name,
					   bool modal,
					   WFlags fl )
    : ActualizaInventario( parent, name, modal, fl ),
      SisDatCom(pSisDatCom),
      chrPtrArgumentos(pchrPtrArgumentos)


{

	exec();
}


QActualizaInventario::~QActualizaInventario()
{
}
