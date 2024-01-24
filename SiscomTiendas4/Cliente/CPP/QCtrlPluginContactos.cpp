#include <QCtrlPluginContactos.h>
#include <QCtrlContactos.h>

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

QCtrlPluginContactos::QCtrlPluginContactos()
{
}

QStringList QCtrlPluginContactos::keys() const
{
    QStringList list;
    list << "QCtrlContactos";
    return list;
}

QWidget* QCtrlPluginContactos::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlContactos" )
	return new QCtrlContactos( parent, name );
    return 0;
}

QString QCtrlPluginContactos::group( const QString& feature ) const
{
    if ( feature == "QCtrlContactos" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginContactos::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginContactos::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlContactos" )
	return "QCtrlContactos.h";
    return QString::null;
}

QString QCtrlPluginContactos::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlContactos" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginContactos::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlContactos" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginContactos::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginContactos )
