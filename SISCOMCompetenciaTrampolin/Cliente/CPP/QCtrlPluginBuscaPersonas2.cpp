#include <QCtrlPluginBuscaPersonas2.h>
#include <QCtrlBuscaPersonas2.h>

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

QCtrlPluginBuscaPersonas2::QCtrlPluginBuscaPersonas2()
{
}

QStringList QCtrlPluginBuscaPersonas2::keys() const
{
    QStringList list;
    list << "QCtrlBuscaPersonas2";
    return list;
}

QWidget* QCtrlPluginBuscaPersonas2::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlBuscaPersonas2" )
	return new QCtrlBuscaPersonas2( parent, name );
    return 0;
}

QString QCtrlPluginBuscaPersonas2::group( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas2" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginBuscaPersonas2::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginBuscaPersonas2::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas2" )
	return "QCtrlBuscaPersonas2.h";
    return QString::null;
}

QString QCtrlPluginBuscaPersonas2::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas2" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginBuscaPersonas2::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlBuscaPersonas2" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginBuscaPersonas2::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginBuscaPersonas2 )
