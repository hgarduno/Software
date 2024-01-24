#include <PruebaControl.h>
#include <PruebaPlugin.h>

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

PruebaPlugin::PruebaPlugin()
{
}

QStringList PruebaPlugin::keys() const
{
    QStringList list;
    list << "PruebaControl";
    return list;
}

QWidget* PruebaPlugin::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "PruebaControl" )
	return new PruebaControl( parent, name );
    return 0;
}

QString PruebaPlugin::group( const QString& feature ) const
{
    if ( feature == "PruebaControl" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet PruebaPlugin::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString PruebaPlugin::includeFile( const QString& feature ) const
{
    if ( feature == "PruebaControl" )
	return "PruebaControl.h";
    return QString::null;
}

QString PruebaPlugin::toolTip( const QString& feature ) const
{
    if ( feature == "PruebaControl" )
	return "Probando el control";
    return QString::null;
}

QString PruebaPlugin::whatsThis( const QString& feature ) const
{
    if ( feature == "PruebaControl" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool PruebaPlugin::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( PruebaPlugin )

