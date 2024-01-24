#include <QSisSepomex.h>
#include <PluginSepomex.h>

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

PluginSepomex::PluginSepomex()
{
}

QStringList PluginSepomex::keys() const
{
    QStringList list;
    list << "QSisSepomex";
    return list;
}

QWidget* PluginSepomex::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QSisSepomex" )
	return new QSisSepomex( parent, name );
    return 0;
}

QString PluginSepomex::group( const QString& feature ) const
{
    if ( feature == "QSisSepomex" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet PluginSepomex::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString PluginSepomex::includeFile( const QString& feature ) const
{
    if ( feature == "QSisSepomex" )
	return "QSisSepomex.h";
    return QString::null;
}

QString PluginSepomex::toolTip( const QString& feature ) const
{
    if ( feature == "QSisSepomex" )
	return "Direcciones Sepomex";
    return QString::null;
}

QString PluginSepomex::whatsThis( const QString& feature ) const
{
    if ( feature == "QSisSepomex" )
	return "Control para el manejo de direcciones";
    return QString::null;
}

bool PluginSepomex::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( PluginSepomex )
