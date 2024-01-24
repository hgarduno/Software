#include <QCtrlPluginEscuelas.h>
#include <QCtrlEscuelas.h>

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

QCtrlPluginEscuelas::QCtrlPluginEscuelas()
{
}

QStringList QCtrlPluginEscuelas::keys() const
{
    QStringList list;
    list << "QCtrlEscuelas";
    return list;
}

QWidget* QCtrlPluginEscuelas::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlEscuelas" )
	return new QCtrlEscuelas( parent, name );
    return 0;
}

QString QCtrlPluginEscuelas::group( const QString& feature ) const
{
    if ( feature == "QCtrlEscuelas" )
	return "Siscom Eletronica2";
    return QString::null;
}

QIconSet QCtrlPluginEscuelas::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginEscuelas::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlEscuelas" )
	return "QCtrlEscuelas.h";
    return QString::null;
}

QString QCtrlPluginEscuelas::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlEscuelas" )
	return "File Chooser Widget";
    return QString::null;
}

QString QCtrlPluginEscuelas::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlEscuelas" )
	return "A widget to choose a file or directory";
    return QString::null;
}

bool QCtrlPluginEscuelas::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginEscuelas )
