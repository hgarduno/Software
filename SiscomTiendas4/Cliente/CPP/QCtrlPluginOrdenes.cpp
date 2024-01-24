#include <QCtrlPluginOrdenes.h>
#include <QCtrlOrdenes.h>

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

QCtrlPluginOrdenes::QCtrlPluginOrdenes()
{
}

QStringList QCtrlPluginOrdenes::keys() const
{
    QStringList list;
    list << "QCtrlOrdenes";
    return list;
}

QWidget* QCtrlPluginOrdenes::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlOrdenes" )
	return new QCtrlOrdenes( parent, name );
    return 0;
}

QString QCtrlPluginOrdenes::group( const QString& feature ) const
{
    if ( feature == "QCtrlOrdenes" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginOrdenes::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginOrdenes::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlOrdenes" )
	return "QCtrlOrdenes.h";
    return QString::null;
}

QString QCtrlPluginOrdenes::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlOrdenes" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginOrdenes::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlOrdenes" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginOrdenes::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginOrdenes )
