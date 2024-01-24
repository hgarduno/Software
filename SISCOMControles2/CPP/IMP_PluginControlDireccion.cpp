#include <IMP_PluginControlDireccion.h>
#include <IMP_QControlDireccion.h>
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
PluginControlDireccion::PluginControlDireccion()
{

}

QStringList PluginControlDireccion::keys() const 
{
QStringList lQSLList;
	lQSLList<< "CQControlDireccion";
	return lQSLList;

}
QWidget *PluginControlDireccion::create(const QString &pQSKey,
				    QWidget *pQWParent,
				    const char *pchrPtrNombre)
{
	
	if(pQSKey=="CQControlDireccion")
	 return new CQControlDireccion(pQWParent,pchrPtrNombre);
	return 0;

}
QString PluginControlDireccion::group(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlDireccion")
	return "SISCOM";
	return QString::null;
}
QIconSet PluginControlDireccion::iconSet(const QString &) const 
{

	return QIconSet(QPixmap(filechooser_pixmap));		
}
QString PluginControlDireccion::includeFile(const QString &pQSControl)const 
{
	if(pQSControl=="CQControlDireccion")
	 return "IMP_QControlDireccion.h";
	return QString::null;
}
QString PluginControlDireccion::toolTip(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlDireccion")
	 return "Control Direcciones";
	return QString::null;

}
QString PluginControlDireccion::whatsThis(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlDireccion")
	 return "Control Direcciones";
	return QString::null;

}
bool PluginControlDireccion::isContainer(const QString &) const 
{
	return false;
}
Q_EXPORT_PLUGIN( PluginControlDireccion )


