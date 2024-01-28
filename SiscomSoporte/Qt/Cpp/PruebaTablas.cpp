#include <stdio.h>
#include <PruebaTablas.h>
#include <QtImpCaja.h>
#include <zSiscomConexion.h>

#include <qapplication.h>

FILE *gPtrFleArchivoLog;
zSiscomConexion *gzSiscomConexion;
int main(int pintArgc,char **pchrPtrArgv)
{
QApplication a(pintArgc,pchrPtrArgv);
QtCorteCajaImp *lQtCorteCajaImp;
gPtrFleArchivoLog=stdout;
lQtCorteCajaImp=CorteCaja();
a.setMainWidget(lQtCorteCajaImp);
lQtCorteCajaImp->show();
a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
a.exec();
}
QtCorteCajaImp *CorteCaja()
{
QtCorteCajaImp *lQtCorteCajaImp;
lQtCorteCajaImp=new QtCorteCajaImp;
lQtCorteCajaImp->setNumRows(25);
lQtCorteCajaImp->setNumCols(19);
lQtCorteCajaImp->IniciaControl(0,0);
AgregaCajaPedidosEsime(lQtCorteCajaImp);
AgregaCajaPedidosEscom(lQtCorteCajaImp);
return lQtCorteCajaImp;
}
void AgregaCajaPedidosEsime(QtCorteCajaImp *pQtCorteCaja)
{
pQtCorteCaja->AgregaCaja("Whats Esime Zacatenco", 17,1);
}
void AgregaCajaPedidosEscom(QtCorteCajaImp *pQtCorteCaja)
{
pQtCorteCaja->AgregaCaja("Whats Escom",17,5);
}
