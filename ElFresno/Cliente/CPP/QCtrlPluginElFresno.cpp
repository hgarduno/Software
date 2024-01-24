
#include <QCtrlPluginElFresno.h>
#include <QCtrlElFresno.h>

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

QCtrlPluginElFresno::QCtrlPluginElFresno()
{
}

QStringList QCtrlPluginElFresno::keys() const
{
    QStringList list;
    list << "QCtrlElFresno";
    return list;
}

QWidget* QCtrlPluginElFresno::create( const QString &key, QWidget* parent, const char* name )
{
/*
    if ( key == "QCtrlElFresno" )
	return new QCtrlElFresno( parent, name );

*/
    return 0;
}

QString QCtrlPluginElFresno::group( const QString& feature ) const
{
    if ( feature == "QCtrlElFresno" )
	return "";
    return QString::null;
}

QIconSet QCtrlPluginElFresno::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginElFresno::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlElFresno" )
	return "QCtrlElFresno.h";
    return QString::null;
}

QString QCtrlPluginElFresno::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlElFresno" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginElFresno::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlElFresno" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginElFresno::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginElFresno )

