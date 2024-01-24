#include <QCtrlPluginClientes.h>
#include <QCtrlClientes.h>

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

QCtrlPluginClientes::QCtrlPluginClientes()
{
}

QStringList QCtrlPluginClientes::keys() const
{
    QStringList list;
    list << "QCtrlClientes";
    return list;
}

QWidget* QCtrlPluginClientes::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlClientes" )
	return new QCtrlClientes( parent, name );
    return 0;
}

QString QCtrlPluginClientes::group( const QString& feature ) const
{
    if ( feature == "QCtrlClientes" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginClientes::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginClientes::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlClientes" )
	return "QCtrlClientes.h";
    return QString::null;
}

QString QCtrlPluginClientes::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlClientes" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginClientes::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlClientes" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginClientes::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginClientes )
