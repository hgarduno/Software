
#include <QCtrlPluginSepomexComunicas.h>
#include <QCtrlSepomexComunicas.h>
#include <QSisDirecciones.h>
#include <QSisTelefonos.h>

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

QCtrlPluginSepomexComunicas::QCtrlPluginSepomexComunicas()
{
}

QStringList QCtrlPluginSepomexComunicas::keys() const
{
    QStringList list;
    list << 
    "QCtrlSepomexComunicas"	<<
    "QSisDirecciones"		<<
    "QSisTelefonos";
    return list;
}

QWidget* QCtrlPluginSepomexComunicas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlSepomexComunicas" )
	return new QCtrlSepomexComunicas( parent, name );
    if( key=="QSisDirecciones")
       return new QSisDirecciones(parent,name);
    if( key=="QSisTelefonos")
       return new QSisTelefonos(parent,name);
    return 0;
}

QString QCtrlPluginSepomexComunicas::group( const QString& feature ) const
{
    if ( feature == "QCtrlSepomexComunicas" )
	return "Siscom Electronica";
    if( feature == "QSisDirecciones")
	return "Siscom Electronica";
    if( feature == "QSisTelefonos")
	return "Siscom Electronica";
    return QString::null;
}

QIconSet QCtrlPluginSepomexComunicas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginSepomexComunicas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlSepomexComunicas" )
	return "QCtrlSepomexComunicas.h";
    if ( feature == "QSisDirecciones" )
	return "QSisDirecciones.h";
    if ( feature == "QSisTelefonos" )
	return "QSisTelefonos.h";
    return QString::null;
}

QString QCtrlPluginSepomexComunicas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlSepomexComunicas" )
	return "File Chooser Widget";
    if ( feature == "QSisDirecciones" )
	return "File Chooser Widget";
    if ( feature == "QSisTelefonos" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginSepomexComunicas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlSepomexComunicas" )
	return "A widget to choose a file or directory";
    if ( feature == "QSisDirecciones" )
	return "A widget to choose a file or directory";
	    if ( feature == "QSisTelefonos" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginSepomexComunicas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginSepomexComunicas )

