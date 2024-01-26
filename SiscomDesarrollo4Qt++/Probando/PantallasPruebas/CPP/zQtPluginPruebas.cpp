#include <zQtPluginPruebas.h>
#include <zPruebas.h>
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
zQtPluginPruebas::zQtPluginPruebas()
{

}


QStringList zQtPluginPruebas::keys() const
{
    QStringList list;
    list << 
    "zPruebas";
    return list;
}

QWidget* zQtPluginPruebas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "zPruebas" )
	return new zPruebas( parent, name );


    return 0;
}

QString zQtPluginPruebas::group( const QString& feature ) const
{
    if ( feature == "zPruebas" )
	return "Pruebas";
    return QString::null;
}

QIconSet zQtPluginPruebas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString zQtPluginPruebas::includeFile( const QString& feature ) const
{
    if ( feature == "zPruebas" )
	return "zPruebas.h";
    return QString::null;
}

QString zQtPluginPruebas::toolTip( const QString& feature ) const
{
    if ( feature == "zPruebas" )
	return "Selecciona Productos";
    return QString::null;
}

QString zQtPluginPruebas::whatsThis( const QString& feature ) const
{
    if ( feature == "zPruebas" )
	return "Selecciona un producto";
    return QString::null;
}

bool zQtPluginPruebas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( zQtPluginPruebas )

