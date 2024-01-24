#include <QCtrlPluginEmpresas.h>
#include <QCtrlEmpresas.h>

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

QCtrlPluginEmpresas::QCtrlPluginEmpresas()
{
}

QStringList QCtrlPluginEmpresas::keys() const
{
    QStringList list;
    list << "QCtrlEmpresas";
    return list;
}

QWidget* QCtrlPluginEmpresas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlEmpresas" )
	return new QCtrlEmpresas( parent, name );
    return 0;
}

QString QCtrlPluginEmpresas::group( const QString& feature ) const
{
    if ( feature == "QCtrlEmpresas" )
	return "Siscom Tiendas4";
    return QString::null;
}

QIconSet QCtrlPluginEmpresas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginEmpresas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlEmpresas" )
	return "QCtrlEmpresas.h";
    return QString::null;
}

QString QCtrlPluginEmpresas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlEmpresas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginEmpresas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlEmpresas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginEmpresas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginEmpresas )
