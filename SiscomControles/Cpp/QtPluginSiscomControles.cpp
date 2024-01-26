#include <QtPluginSiscomControles.h>
#include <QBarCode.h>

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


QtPluginSiscomControles::QtPluginSiscomControles()
{
}


QStringList QtPluginSiscomControles::keys() const
{

    QStringList list;
    list << 
    "QBarCode"	;
    return list;
}

QWidget* QtPluginSiscomControles::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QBarCode" )
	return new QBarCode(parent, name );

    return 0;


}

QString QtPluginSiscomControles::group( const QString& feature ) const
{
    if ( feature == "QBarCode" )
	return "Siscom Controles";

    return QString::null;
}

QIconSet QtPluginSiscomControles::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QtPluginSiscomControles::includeFile( const QString& feature ) const
{
    if ( feature == "QBarCode" )
	return "QBarCode.h";


    return QString::null;
}

QString QtPluginSiscomControles::toolTip( const QString& feature ) const
{
    if ( feature == "QBarCode" )
	return "Generador de codigo de barras 128B";


    return QString::null;
}

QString QtPluginSiscomControles::whatsThis( const QString& feature ) const
{
    if ( feature == "QBarCode" )
	return "Generador de codigo de barras 128B";


    return QString::null;
}

bool QtPluginSiscomControles::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QtPluginSiscomControles )

