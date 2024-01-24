
#include <QCtrlPluginRecetas.h>
#include <QCtrlRecetas.h>

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

QCtrlPluginRecetas::QCtrlPluginRecetas()
{
}

QStringList QCtrlPluginRecetas::keys() const
{
    QStringList list;
    list << "QCtrlRecetas";
    return list;
}

QWidget* QCtrlPluginRecetas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlRecetas" )
	return new QCtrlRecetas( parent, name );
    return 0;
}

QString QCtrlPluginRecetas::group( const QString& feature ) const
{
    if ( feature == "QCtrlRecetas" )
	return "Siscom Clinicas3";
    return QString::null;
}

QIconSet QCtrlPluginRecetas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginRecetas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlRecetas" )
	return "QCtrlRecetas.h";
    return QString::null;
}

QString QCtrlPluginRecetas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlRecetas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginRecetas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlRecetas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginRecetas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginRecetas )

