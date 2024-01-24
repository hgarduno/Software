#include <IMP_PluginControlNombres.h>
#include <IMP_QControlNombres.h>
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
PluginControlNombres::PluginControlNombres()
{

}

QStringList PluginControlNombres::keys() const 
{
QStringList lQSLList;
	lQSLList<< "CQControlNombres";
	return lQSLList;

}
QWidget *PluginControlNombres::create(const QString &pQSKey,
				    QWidget *pQWParent,
				    const char *pchrPtrNombre)
{
	
	if(pQSKey=="CQControlNombres")
	 return new CQControlNombres(pQWParent,pchrPtrNombre);
	return 0;

}
QString PluginControlNombres::group(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlNombres")
	return "SISCOM";
	return QString::null;
}
QIconSet PluginControlNombres::iconSet(const QString &) const 
{

	return QIconSet(QPixmap(filechooser_pixmap));		
}
QString PluginControlNombres::includeFile(const QString &pQSControl)const 
{
	if(pQSControl=="CQControlNombres")
	 return "IMP_QControlNombres.h";
	return QString::null;
}
QString PluginControlNombres::toolTip(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlNombres")
	 return "Control Direcciones";
	return QString::null;

}
QString PluginControlNombres::whatsThis(const QString &pQSControl) const 
{
	if(pQSControl=="CQControlNombres")
	 return "Control Direcciones";
	return QString::null;

}
bool PluginControlNombres::isContainer(const QString &) const 
{
	return false;
}
Q_EXPORT_PLUGIN( PluginControlNombres )


