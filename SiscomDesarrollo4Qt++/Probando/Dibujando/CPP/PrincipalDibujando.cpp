#include <zSiscomMenu.h>
#include <zSiscomMenus.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistros.h>
#include <zSiscomMenusVentana.h>
#include <stdio.h>

#include <zDibujando.h>


#include <qapplication.h>
#include <qwidgetfactory.h>
#include <qworkspace.h>
#include <qvbox.h>
#include <qpainter.h>

FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;
int main(int pintArgc,
	 char **pchrPtrArgv)
{
QApplication lQAVentana(pintArgc,pchrPtrArgv);
gPtrFleArchivoLog=stdout;
zDibujando *lzDibujando=new zDibujando;
lzDibujando->show();
lQAVentana.connect(&lQAVentana,SIGNAL(lastWindowClosed()),SLOT(quit()));
return lQAVentana.exec();

}


