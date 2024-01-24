#include <qapplication.h>
#include <IMP_PruebaGUI.h>
#include <CSISCOMComunicaciones.h>
int main(int pintArgC,
	 char **pchrPtrArgv)
{
CSISCOMDatComunicaciones lCDSDatCom(1645,
                                    "127.0.0.1"    ,
                                        "hgarduno",
                                        "hgarduno");

QApplication a(pintArgC,pchrPtrArgv);
CQSisPruebasGUI *lCQSPruebaGUI=new CQSisPruebasGUI(&lCDSDatCom);
lCQSPruebaGUI->show();
a.connect(&a,SIGNAL(lastWindowClosed()), &a ,SLOT(quit()));


return a.exec();



}
