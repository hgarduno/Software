#include <QCtrlPluginFamilias.h>
#include <QCtrlFamilias.h>

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

QCtrlPluginFamilias::QCtrlPluginFamilias()
{
}

QStringList QCtrlPluginFamilias::keys() const
{
    QStringList list;
    list << "QCtrlFamilias";
    return list;
}

QWidget* QCtrlPluginFamilias::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlFamilias" )
	return new QCtrlFamilias( parent, name );
    return 0;
}

QString QCtrlPluginFamilias::group( const QString& feature ) const
{
    if ( feature == "QCtrlFamilias" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginFamilias::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginFamilias::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlFamilias" )
	return "QCtrlFamilias.h";
    return QString::null;
}

QString QCtrlPluginFamilias::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlFamilias" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginFamilias::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlFamilias" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginFamilias::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginFamilias )
