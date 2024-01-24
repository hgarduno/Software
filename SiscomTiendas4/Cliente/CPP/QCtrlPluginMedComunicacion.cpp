#include <QCtrlPluginMedComunicacion.h>
#include <QCtrlMedComunicacion.h>

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

QCtrlPluginMedComunicacion::QCtrlPluginMedComunicacion()
{
}

QStringList QCtrlPluginMedComunicacion::keys() const
{
    QStringList list;
    list << "QCtrlMedComunicacion";
    return list;
}

QWidget* QCtrlPluginMedComunicacion::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlMedComunicacion" )
	return new QCtrlMedComunicacion( parent, name );
    return 0;
}

QString QCtrlPluginMedComunicacion::group( const QString& feature ) const
{
    if ( feature == "QCtrlMedComunicacion" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginMedComunicacion::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginMedComunicacion::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlMedComunicacion" )
	return "QCtrlMedComunicacion.h";
    return QString::null;
}

QString QCtrlPluginMedComunicacion::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlMedComunicacion" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginMedComunicacion::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlMedComunicacion" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginMedComunicacion::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginMedComunicacion )
