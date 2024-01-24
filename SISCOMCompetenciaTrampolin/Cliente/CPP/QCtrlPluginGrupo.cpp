#include <QCtrlPluginGrupo.h>
#include <QCtrlGrupo.h>

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

QCtrlPluginGrupo::QCtrlPluginGrupo()
{
}

QStringList QCtrlPluginGrupo::keys() const
{
    QStringList list;
    list << "QCtrlGrupo";
    return list;
}

QWidget* QCtrlPluginGrupo::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlGrupo" )
	return new QCtrlGrupo( parent, name );
    return 0;
}

QString QCtrlPluginGrupo::group( const QString& feature ) const
{
    if ( feature == "QCtrlGrupo" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginGrupo::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginGrupo::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlGrupo" )
	return "QCtrlGrupo.h";
    return QString::null;
}

QString QCtrlPluginGrupo::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlGrupo" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginGrupo::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlGrupo" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginGrupo::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginGrupo )
