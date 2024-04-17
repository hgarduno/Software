/****************************************************************************
** SiscomElectronica meta object code from reading C++ file 'SiscomElectronica.h'
**
** Created: Fri Apr 12 21:36:25 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomElectronica.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomElectronica::className() const
{
    return "SiscomElectronica";
}

QMetaObject *SiscomElectronica::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomElectronica( "SiscomElectronica", &SiscomElectronica::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomElectronica::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomElectronica", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomElectronica::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomElectronica", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomElectronica::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SiscomVentanaPrincipal::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCargaModuloAdministracion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCargaModuloAdministracion()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"SiscomElectronica", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomElectronica.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomElectronica::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomElectronica" ) )
	return this;
    return SiscomVentanaPrincipal::qt_cast( clname );
}

bool SiscomElectronica::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCargaModuloAdministracion(); break;
    default:
	return SiscomVentanaPrincipal::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SiscomElectronica::qt_emit( int _id, QUObject* _o )
{
    return SiscomVentanaPrincipal::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SiscomElectronica::qt_property( int id, int f, QVariant* v)
{
    return SiscomVentanaPrincipal::qt_property( id, f, v);
}

bool SiscomElectronica::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
