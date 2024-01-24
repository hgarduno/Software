#include <QCtrlPluginPrecios.h>
#include <QCtrlPrecios.h>

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

QCtrlPluginPrecios::QCtrlPluginPrecios()
{
}

QStringList QCtrlPluginPrecios::keys() const
{
    QStringList list;
    list << "QCtrlPrecios";
    return list;
}

QWidget* QCtrlPluginPrecios::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlPrecios" )
	return new QCtrlPrecios( parent, name );
    return 0;
}

QString QCtrlPluginPrecios::group( const QString& feature ) const
{
    if ( feature == "QCtrlPrecios" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginPrecios::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginPrecios::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlPrecios" )
	return "QCtrlPrecios.h";
    return QString::null;
}

QString QCtrlPluginPrecios::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlPrecios" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginPrecios::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlPrecios" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginPrecios::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginPrecios )
