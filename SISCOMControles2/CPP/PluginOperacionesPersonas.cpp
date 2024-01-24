#include <PluginOperacionesPersonas.h> 
#include <QSisOperacionesPersonas.h> 

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

PluginOperacionesPersonas::PluginOperacionesPersonas()
{
}

QStringList PluginOperacionesPersonas::keys() const
{
    QStringList list;
    list << "QSisOperacionesPersonas";
    return list;
}

QWidget* PluginOperacionesPersonas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QSisOperacionesPersonas" )
	return new QSisOperacionesPersonas( parent, name );
    return 0;
}

QString PluginOperacionesPersonas::group( const QString& feature ) const
{
    if ( feature == "QSisOperacionesPersonas" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet PluginOperacionesPersonas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString PluginOperacionesPersonas::includeFile( const QString& feature ) const
{
    if ( feature == "QSisOperacionesPersonas" )
	return "QSisOperacionesPersonas.h";
    return QString::null;
}

QString PluginOperacionesPersonas::toolTip( const QString& feature ) const
{
    if ( feature == "QSisOperacionesPersonas" )
	return "File Chooser Widget";
    return QString::null;
}

QString PluginOperacionesPersonas::whatsThis( const QString& feature ) const
{
    if ( feature == "QSisOperacionesPersonas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool PluginOperacionesPersonas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( PluginOperacionesPersonas )
