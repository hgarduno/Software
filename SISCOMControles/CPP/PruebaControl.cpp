#include <qapplication.h>
#include <IMP_QControlFecha.h>
#include <IMP_QControlDireccion.h>

int main(int pintArgc,
	 char **pzCArgv)

{
	QApplication a(pintArgc,pzCArgv);
	CQControlFecha *lCQFecha=new CQControlFecha;
	CQControlDireccion *lCQDireccion=new CQControlDireccion;
	lCQFecha->show();
	lCQDireccion->show();

	return a.exec();


}
	
