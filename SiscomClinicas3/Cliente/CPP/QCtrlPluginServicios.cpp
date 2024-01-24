
#include <QCtrlPluginServicios.h>
#include <QCtrlServicios.h>

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

QCtrlPluginServicios::QCtrlPluginServicios()
{
}

QStringList QCtrlPluginServicios::keys() const
{
    QStringList list;
    list << "QCtrlServicios";
    return list;
}

QWidget* QCtrlPluginServicios::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlServicios" )
	return new QCtrlServicios( parent, name );
    return 0;
}

QString QCtrlPluginServicios::group( const QString& feature ) const
{
    if ( feature == "QCtrlServicios" )
	return "Siscom Clinicas3";
    return QString::null;
}

QIconSet QCtrlPluginServicios::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginServicios::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlServicios" )
	return "QCtrlServicios.h";
    return QString::null;
}

QString QCtrlPluginServicios::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlServicios" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginServicios::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlServicios" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginServicios::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginServicios )

