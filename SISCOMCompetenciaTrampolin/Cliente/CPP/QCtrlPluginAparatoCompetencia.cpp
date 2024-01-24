#include <QCtrlPluginAparatoCompetencia.h>
#include <QCtrlAparatoCompetencia.h>

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

QCtrlPluginAparatoCompetencia::QCtrlPluginAparatoCompetencia()
{
}

QStringList QCtrlPluginAparatoCompetencia::keys() const
{
    QStringList list;
    list << "QCtrlAparatoCompetencia";
    return list;
}

QWidget* QCtrlPluginAparatoCompetencia::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlAparatoCompetencia" )
	return new QCtrlAparatoCompetencia( parent, name );
    return 0;
}

QString QCtrlPluginAparatoCompetencia::group( const QString& feature ) const
{
    if ( feature == "QCtrlAparatoCompetencia" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginAparatoCompetencia::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginAparatoCompetencia::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlAparatoCompetencia" )
	return "QCtrlAparatoCompetencia.h";
    return QString::null;
}

QString QCtrlPluginAparatoCompetencia::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlAparatoCompetencia" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginAparatoCompetencia::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlAparatoCompetencia" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginAparatoCompetencia::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginAparatoCompetencia )
