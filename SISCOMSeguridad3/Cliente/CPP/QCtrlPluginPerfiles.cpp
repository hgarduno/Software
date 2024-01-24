#include <QCtrlPluginPerfiles.h>
#include <QCtrlPerfiles.h>

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

QCtrlPluginPerfiles::QCtrlPluginPerfiles()
{
}

QStringList QCtrlPluginPerfiles::keys() const
{
    QStringList list;
    list << "QCtrlPerfiles";
    return list;
}

QWidget* QCtrlPluginPerfiles::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlPerfiles" )
	return new QCtrlPerfiles( parent, name );
    return 0;
}

QString QCtrlPluginPerfiles::group( const QString& feature ) const
{
    if ( feature == "QCtrlPerfiles" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet QCtrlPluginPerfiles::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginPerfiles::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlPerfiles" )
	return "QCtrlPerfiles.h";
    return QString::null;
}

QString QCtrlPluginPerfiles::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlPerfiles" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginPerfiles::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlPerfiles" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginPerfiles::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginPerfiles )
