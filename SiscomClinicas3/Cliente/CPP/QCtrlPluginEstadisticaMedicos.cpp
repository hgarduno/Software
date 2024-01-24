
#include <QCtrlPluginEstadisticaMedicos.h>
#include <QCtrlEstadisticaMedicos.h>

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

QCtrlPluginEstadisticaMedicos::QCtrlPluginEstadisticaMedicos()
{
}

QStringList QCtrlPluginEstadisticaMedicos::keys() const
{
    QStringList list;
    list << "QCtrlEstadisticaMedicos";
    return list;
}

QWidget* QCtrlPluginEstadisticaMedicos::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlEstadisticaMedicos" )
	return new QCtrlEstadisticaMedicos( parent, name );
    return 0;
}

QString QCtrlPluginEstadisticaMedicos::group( const QString& feature ) const
{
    if ( feature == "QCtrlEstadisticaMedicos" )
	return "Siscom Clinicas3";
    return QString::null;
}

QIconSet QCtrlPluginEstadisticaMedicos::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginEstadisticaMedicos::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlEstadisticaMedicos" )
	return "QCtrlEstadisticaMedicos.h";
    return QString::null;
}

QString QCtrlPluginEstadisticaMedicos::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlEstadisticaMedicos" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginEstadisticaMedicos::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlEstadisticaMedicos" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginEstadisticaMedicos::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginEstadisticaMedicos )

