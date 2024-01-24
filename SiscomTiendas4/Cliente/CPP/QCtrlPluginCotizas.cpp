
#include <QCtrlPluginCotizas.h>
#include <QCtrlCotizas.h>

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

QCtrlPluginCotizas::QCtrlPluginCotizas()
{
}

QStringList QCtrlPluginCotizas::keys() const
{
    QStringList list;
    list << "QCtrlCotizas";
    return list;
}

QWidget* QCtrlPluginCotizas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlCotizas" )
	return new QCtrlCotizas( parent, name );
    return 0;
}

QString QCtrlPluginCotizas::group( const QString& feature ) const
{
    if ( feature == "QCtrlCotizas" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginCotizas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginCotizas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlCotizas" )
	return "QCtrlCotizas.h";
    return QString::null;
}

QString QCtrlPluginCotizas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlCotizas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginCotizas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlCotizas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginCotizas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginCotizas )

