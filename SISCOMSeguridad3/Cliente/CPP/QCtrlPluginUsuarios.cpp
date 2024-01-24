#include <QCtrlPluginUsuarios.h>
#include <QCtrlUsuarios.h>

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

QCtrlPluginUsuarios::QCtrlPluginUsuarios()
{
}

QStringList QCtrlPluginUsuarios::keys() const
{
    QStringList list;
    list << "QCtrlUsuarios";
    return list;
}

QWidget* QCtrlPluginUsuarios::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlUsuarios" )
	return new QCtrlUsuarios( parent, name );
    return 0;
}

QString QCtrlPluginUsuarios::group( const QString& feature ) const
{
    if ( feature == "QCtrlUsuarios" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet QCtrlPluginUsuarios::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginUsuarios::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlUsuarios" )
	return "QCtrlUsuarios.h";
    return QString::null;
}

QString QCtrlPluginUsuarios::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlUsuarios" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginUsuarios::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlUsuarios" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginUsuarios::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginUsuarios )
