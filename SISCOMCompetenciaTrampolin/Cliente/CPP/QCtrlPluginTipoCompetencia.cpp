#include <QCtrlPluginTipoCompetencia.h>
#include <QCtrlTipoCompetencia.h>

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

QCtrlPluginTipoCompetencia::QCtrlPluginTipoCompetencia()
{
}

QStringList QCtrlPluginTipoCompetencia::keys() const
{
    QStringList list;
    list << "QCtrlTipoCompetencia";
    return list;
}

QWidget* QCtrlPluginTipoCompetencia::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlTipoCompetencia" )
	return new QCtrlTipoCompetencia( parent, name );
    return 0;
}

QString QCtrlPluginTipoCompetencia::group( const QString& feature ) const
{
    if ( feature == "QCtrlTipoCompetencia" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginTipoCompetencia::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginTipoCompetencia::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlTipoCompetencia" )
	return "QCtrlTipoCompetencia.h";
    return QString::null;
}

QString QCtrlPluginTipoCompetencia::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlTipoCompetencia" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginTipoCompetencia::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlTipoCompetencia" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginTipoCompetencia::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginTipoCompetencia )
