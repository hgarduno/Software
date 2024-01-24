#include <QCtrlPluginFormaPago.h>
#include <QCtrlFormaPago.h>

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

QCtrlPluginFormaPago::QCtrlPluginFormaPago()
{
}

QStringList QCtrlPluginFormaPago::keys() const
{
    QStringList list;
    list << "QCtrlFormaPago";
    return list;
}

QWidget* QCtrlPluginFormaPago::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlFormaPago" )
	return new QCtrlFormaPago( parent, name );
    return 0;
}

QString QCtrlPluginFormaPago::group( const QString& feature ) const
{
    if ( feature == "QCtrlFormaPago" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginFormaPago::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginFormaPago::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlFormaPago" )
	return "QCtrlFormaPago.h";
    return QString::null;
}

QString QCtrlPluginFormaPago::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlFormaPago" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginFormaPago::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlFormaPago" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginFormaPago::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginFormaPago )
