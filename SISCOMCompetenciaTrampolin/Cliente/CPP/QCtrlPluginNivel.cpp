#include <QCtrlPluginNivel.h>
#include <QCtrlNivel.h>

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

QCtrlPluginNivel::QCtrlPluginNivel()
{
}

QStringList QCtrlPluginNivel::keys() const
{
    QStringList list;
    list << "QCtrlNivel";
    return list;
}

QWidget* QCtrlPluginNivel::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlNivel" )
	return new QCtrlNivel( parent, name );
    return 0;
}

QString QCtrlPluginNivel::group( const QString& feature ) const
{
    if ( feature == "QCtrlNivel" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginNivel::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginNivel::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlNivel" )
	return "QCtrlNivel.h";
    return QString::null;
}

QString QCtrlPluginNivel::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlNivel" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginNivel::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlNivel" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginNivel::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginNivel )
