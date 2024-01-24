#include <IMP_Entrenadores.h>
#include <SISCOMComunicaciones++.h>
#include <qapplication.h>
int main(int pintArgc,
	 char **pchrPtrArgv)
{
SiscomDatCom *lSisDatCom=new SiscomDatCom(5630,"127.0.0.1");
QApplication a( pintArgc, pchrPtrArgv);
gPtrFleArchivoLog=stdout;
QEntrenadores *lQEntrena=new QEntrenadores(lSisDatCom,0);
lQEntrena->show();
a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
return a.exec();

}
