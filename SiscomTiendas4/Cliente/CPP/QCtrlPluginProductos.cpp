#include <QCtrlPluginProductos.h>
#include <QCtrlProductos.h>

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

QCtrlPluginProductos::QCtrlPluginProductos()
{
}

QStringList QCtrlPluginProductos::keys() const
{
    QStringList list;
    list << "QCtrlProductos";
    return list;
}

QWidget* QCtrlPluginProductos::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlProductos" )
	return new QCtrlProductos( parent, name );
    return 0;
}

QString QCtrlPluginProductos::group( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginProductos::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginProductos::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "QCtrlProductos.h";
    return QString::null;
}

QString QCtrlPluginProductos::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginProductos::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlProductos" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginProductos::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginProductos )
