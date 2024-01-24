#include <QCtrlPluginServidoresSiscom.h>
#include <QCtrlServidoresSiscom.h>

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

QCtrlPluginServidoresSiscom::QCtrlPluginServidoresSiscom()
{
}

QStringList QCtrlPluginServidoresSiscom::keys() const
{
    QStringList list;
    list << "QCtrlServidoresSiscom";
    return list;
}

QWidget* QCtrlPluginServidoresSiscom::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "QCtrlServidoresSiscom" )
	return new QCtrlServidoresSiscom( parent, name );
    return 0;
}

QString QCtrlPluginServidoresSiscom::group( const QString& feature ) const
{
    if ( feature == "QCtrlServidoresSiscom" )
	return "Siscom Electronica";
    return QString::null;
}

QIconSet QCtrlPluginServidoresSiscom::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString QCtrlPluginServidoresSiscom::includeFile( const QString& feature ) const
{
    if ( feature == "QCtrlServidoresSiscom" )
	return "QCtrlServidoresSiscom.h";
    return QString::null;
}

QString QCtrlPluginServidoresSiscom::toolTip( const QString& feature ) const
{
    if ( feature == "QCtrlServidoresSiscom" )
	return "Control para la seleccion de servidores";
    return QString::null;
}

QString QCtrlPluginServidoresSiscom::whatsThis( const QString& feature ) const
{
    if ( feature == "QCtrlServidoresSiscom" )
	return "Control para la seleccion de servidores";
    return QString::null;
}

bool QCtrlPluginServidoresSiscom::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( QCtrlPluginServidoresSiscom )
