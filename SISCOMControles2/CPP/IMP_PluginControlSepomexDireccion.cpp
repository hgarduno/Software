#include <IMP_PluginControlSepomexDireccion.h>
#include <IMP_QControlSepomexDireccion.h>

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

ControlSepomex::ControlSepomex()
{
}

QStringList ControlSepomex::keys() const
{
    QStringList list;
    list << "SepomexDireccion";
    return list;
}

QWidget* ControlSepomex::create( const QString &key, QWidget* parent, const char* name )
{
    if ( key == "SepomexDireccion" )
	return new CQControlSepomexDireccion( parent, name );
    return 0;
}

QString ControlSepomex::group( const QString& feature ) const
{
    if ( feature == "SepomexDireccion" )
	return "SISCOM";
    return QString::null;
}

QIconSet ControlSepomex::iconSet( const QString& ) const
{
    return QIconSet( QPixmap( filechooser_pixmap ) );
}

QString ControlSepomex::includeFile( const QString& feature ) const
{
    if ( feature == "SepomexDireccion" )
	return "IMP_QControlSepomexDireccion.h";
    return QString::null;
}

QString ControlSepomex::toolTip( const QString& feature ) const
{
    if ( feature == "SepomexDireccion" )
	return "Contro Sepomex De Direcciones";
    return QString::null;
}

QString ControlSepomex::whatsThis( const QString& feature ) const
{
    if ( feature == "SepomexDireccion" )
	return "Control Para adminsitrar las direcciones";
    return QString::null;
}

bool ControlSepomex::isContainer( const QString& ) const
{
    return FALSE;
}


Q_EXPORT_PLUGIN( ControlSepomex )
