#include <QCtrlPluginBuscaPersonas.h>
#include <QCtrlBuscaPersonas.h>

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

QCtrlPluginBuscaPersonas::QCtrlPluginBuscaPersonas()
{
}

QStringList QCtrlPluginBuscaPersonas::keys() const
{
    QStringList list;
    list << "QCtrlBuscaPersonas";
    return list;
}

QWidget* QCtrlPluginBuscaPersonas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlBuscaPersonas" )
	return new QCtrlBuscaPersonas( parent, name );
    return 0;
}

QString QCtrlPluginBuscaPersonas::group( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginBuscaPersonas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginBuscaPersonas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas" )
	return "QCtrlBuscaPersonas.h";
    return QString::null;
}

QString QCtrlPluginBuscaPersonas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginBuscaPersonas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginBuscaPersonas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginBuscaPersonas )
