#include <QCtrlPluginClase.h>
#include <QCtrlClase.h>

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

QCtrlPluginClase::QCtrlPluginClase()
{
}

QStringList QCtrlPluginClase::keys() const
{
    QStringList list;
    list << "QCtrlClase";
    return list;
}

QWidget* QCtrlPluginClase::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlClase" )
	return new QCtrlClase( parent, name );
    return 0;
}

QString QCtrlPluginClase::group( const QString& feature ) const
{
    if ( feature == "QCtrlClase" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginClase::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginClase::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlClase" )
	return "QCtrlClase.h";
    return QString::null;
}

QString QCtrlPluginClase::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlClase" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginClase::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlClase" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginClase::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginClase )
