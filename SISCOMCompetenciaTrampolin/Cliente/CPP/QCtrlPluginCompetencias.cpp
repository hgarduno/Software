#include <QCtrlPluginCompetencias.h>
#include <QCtrlCompetencias.h>

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

QCtrlPluginCompetencias::QCtrlPluginCompetencias()
{
}

QStringList QCtrlPluginCompetencias::keys() const
{
    QStringList list;
    list << "QCtrlCompetencias";
    return list;
}

QWidget* QCtrlPluginCompetencias::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlCompetencias" )
	return new QCtrlCompetencias( parent, name );
    return 0;
}

QString QCtrlPluginCompetencias::group( const QString& feature ) const
{
    if ( feature == "QCtrlCompetencias" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginCompetencias::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginCompetencias::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlCompetencias" )
	return "QCtrlCompetencias.h";
    return QString::null;
}

QString QCtrlPluginCompetencias::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlCompetencias" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginCompetencias::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlCompetencias" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginCompetencias::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginCompetencias )
