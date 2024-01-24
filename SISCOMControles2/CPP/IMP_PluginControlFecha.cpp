#include <IMP_PluginControlFecha.h> 
#include <IMP_QControlFecha.h>
#include <QCtrlFechaHora.h>
#include <QCtrlRangoHora.h>

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

PluginFecha2::PluginFecha2()
{
}

QStringList PluginFecha2::keys() const
{
    QStringList list;
    list 		<< 
    "CQControlFecha"	<<
    "QCtrlFechaHora"	<<
    "QCtrlRangoHora";
    return list;
}

QWidget* PluginFecha2::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "CQControlFecha" )
	return new CQControlFecha( parent, name );
    if ( key == "QCtrlFechaHora" )
	return new QCtrlFechaHora( parent, name );

    if ( key == "QCtrlRangoHora" )
	return new QCtrlRangoHora( parent, name );

    return 0;
}

QString PluginFecha2::group( const QString& feature ) const
{
    if ( feature == "CQControlFecha" )
	return "Siscom Electronica";
    if ( feature == "QCtrlFechaHora" )
	return "Siscom Electronica";

    if ( feature == "QCtrlRangoHora" )
	return "Siscom Electronica";

    return QString::null;
}

QIconSet PluginFecha2::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString PluginFecha2::includeFile( const QString& feature ) const
{
    if ( feature == "CQControlFecha" )
	return "IMP_QControlFecha.h";
    if ( feature == "QCtrlFechaHora" )
	return "QCtrlFechaHora.h";

    if ( feature == "QCtrlRangoHora" )
	return "QCtrlRangoHora.h";
    return QString::null;
}

QString PluginFecha2::toolTip( const QString& feature ) const
{
    if ( feature == "CQControlFecha" )
	return "File Chooser Widget";
    if ( feature == "QCtrlFechaHora" )
	return "File Chooser Widget";
    if ( feature == "QCtrlRangoHora" )
	return "File Chooser Widget";

    return QString::null;
}

QString PluginFecha2::whatsThis( const QString& feature ) const
{
    if ( feature == "CQControlFecha" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlFechaHora" )
	return "A widget to choose a file or directory";
    if ( feature == "QCtrlRangoHora" )
	return "A widget to choose a file or directory";

    return QString::null;
}

bool PluginFecha2::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( PluginFecha2 )
