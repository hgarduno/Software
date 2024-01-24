#include <qapplication.h>
#include <IMP_ControladorSeguridad.h>
const  char *gchrPtrSiscomSeguridad3NmbAplicacion="Prueba";
const  char *gchrPtrSiscomSeguridad3Perfil="General";
QFont gQFTipoLetra;
FILE *gPtrFleArchivoLog;
int main(int pintArgC,
	 char **pchrPtrArgv)
{
QApplication a(pintArgC,pchrPtrArgv);
gPtrFleArchivoLog=stdout;
CQSisControladorSeguridad *lCQSContSeguridad=new CQSisControladorSeguridad;
lCQSContSeguridad->show();
a.connect(&a,SIGNAL(lastWindowClosed()), &a ,SLOT(quit()));


return a.exec();



}
