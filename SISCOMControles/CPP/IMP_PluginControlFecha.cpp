#include <IMP_PluginControlFecha.h>
#include <IMP_QControlFecha.h>
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
PluginControlFecha::PluginControlFecha()
{


}

QStringList PluginControlFecha::keys() const 
{
QStringList lQSLList;
	lQSLList<< "CQControlFecha";
	return lQSLList;

}
QWidget *PluginControlFecha::create(const QString &pQSKey,
				    QWidget *pQWParent,
				    const char *pchrPtrNombre)
{
	
	if(pQSKey=="CQControlFecha")
	 return new CQControlFecha(pQWParent,pchrPtrNombre);
	return 0;

}
QString PluginControlFecha::group(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha")
	return "SISCOM";
	return QString::null;
}
QIconSet PluginControlFecha::iconSet(const QString &) const 
{

	return QIconSet(QPixmap(filechooser_pixmap));		
}
QString PluginControlFecha::includeFile(const QString &pQSControl)const 
{
	if(pQSControl=="CQControlFecha")
	 return "IMP_QControlFecha.h";
	return QString::null;
}
QString PluginControlFecha::toolTip(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha")
	 return "Control De Fechas Nuevo";
	return QString::null;

}
QString PluginControlFecha::whatsThis(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlFecha")
	 return "Control De Fechas Nuevo";
	return QString::null;

}
bool PluginControlFecha::isContainer(const QString &) const 
{
	return false;
}
Q_EXPORT_PLUGIN( PluginControlFecha )


