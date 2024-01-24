#include <QCtrlPluginGimnasios.h>
#include <QCtrlGimnasios.h>

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

QCtrlPluginGimnasios::QCtrlPluginGimnasios()
{
}

QStringList QCtrlPluginGimnasios::keys() const
{
    QStringList list;
    list << "QCtrlGimnasios";
    return list;
}

QWidget* QCtrlPluginGimnasios::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlGimnasios" )
	return new QCtrlGimnasios( parent, name );
    return 0;
}

QString QCtrlPluginGimnasios::group( const QString& feature ) const
{
    if ( feature == "QCtrlGimnasios" )
	return "Siscom Gimnasia";
    return QString::null;
}

QIconSet QCtrlPluginGimnasios::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginGimnasios::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlGimnasios" )
	return "QCtrlGimnasios.h";
    return QString::null;
}

QString QCtrlPluginGimnasios::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlGimnasios" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginGimnasios::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlGimnasios" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginGimnasios::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginGimnasios )
