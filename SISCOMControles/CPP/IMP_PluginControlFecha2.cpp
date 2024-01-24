#include <IMP_PluginControlFecha2.h>
#include <IMP_QControlFecha2.h>
#include <qfile.h>

static const char *filechooser_pixmap[] = {
    "22 22 8 1",
    "  c Gray100",
    ". c Gray97",
    "X c #4f504f",
    "o c #00007f",
    "O c Gray0",
    "+ c none",
    "@ c Gray0",
    "# c Gray0",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "OOXXXXXXXXXXXXXXXXXXOO",
    "OXX.          OO OO  O",
    "OX.      oo     O    O",
    "OX.      oo     O   .O",
    "OX  ooo  oooo   O    O",
    "OX    oo oo oo  O    O",
    "OX  oooo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX oo oo oo oo  O    O",
    "OX  oooo oooo   O    O",
    "OX            OO OO  O",
    "OO..................OO",
    "+OOOOOOOOOOOOOOOOOOOO+",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++",
    "++++++++++++++++++++++"
};
PluginControlFecha2::PluginControlFecha2()
{


}

QStringList PluginControlFecha2::keys() const 
{
QStringList lQSLList;
	lQSLList<< "CQControlFecha2";
	return lQSLList;

}
QWidget *PluginControlFecha2::create(const QString &pQSKey,
				    QWidget *pQWParent,
				    const char *pchrPtrNombre)
{
	
	if(pQSKey=="CQControlFecha2")
	 return new CQControlFecha2(pQWParent,pchrPtrNombre);
	return 0;

}
QString PluginControlFecha2::group(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha2")
	return "SISCOM";
	return QString::null;
}
QIconSet PluginControlFecha2::iconSet(const QString &) const 
{

	return QIconSet(QPixmap(filechooser_pixmap));		
}
QString PluginControlFecha2::includeFile(const QString &pQSControl)const 
{
	if(pQSControl=="CQControlFecha2")
	 return "IMP_QControlFecha2.h";
	return QString::null;
}
QString PluginControlFecha2::toolTip(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha2")
	 return "Control De Fechas Nuevo";
	return QString::null;

}
QString PluginControlFecha2::whatsThis(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha2")
	 return "Control De Fechas Nuevo";
	return QString::null;

}
bool PluginControlFecha2::isContainer(const QString &) const 
{
	return false;
}
Q_EXPORT_PLUGIN( PluginControlFecha2 )


