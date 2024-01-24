
#include <QCtrlPluginPersonas.h>
#include <QCtrlPersonas.h>

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

QCtrlPluginPersonas::QCtrlPluginPersonas()
{
}

QStringList QCtrlPluginPersonas::keys() const
{
    QStringList list;
    list << "QCtrlPersonas";
    return list;
}

QWidget* QCtrlPluginPersonas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlPersonas" )
	return new QCtrlPersonas( parent, name );
    return 0;
}

QString QCtrlPluginPersonas::group( const QString& feature ) const
{
    if ( feature == "QCtrlPersonas" )
	return "Siscom Clinicas3";
    return QString::null;
}

QIconSet QCtrlPluginPersonas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginPersonas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlPersonas" )
	return "QCtrlPersonas.h";
    return QString::null;
}

QString QCtrlPluginPersonas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlPersonas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginPersonas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlPersonas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginPersonas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginPersonas )

