/****************************************************************************
** QtImpRegistroUsuarios meta object code from reading C++ file 'QtImpRegistroUsuarios.h'
**
** Created: Thu Apr 11 21:08:54 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpRegistroUsuarios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpRegistroUsuarios::className() const
{
    return "QtImpRegistroUsuarios";
}

QMetaObject *QtImpRegistroUsuarios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpRegistroUsuarios( "QtImpRegistroUsuarios", &QtImpRegistroUsuarios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpRegistroUsuarios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroUsuarios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpRegistroUsuarios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpRegistroUsuarios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpRegistroUsuarios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroUsuarios::staticMetaObject();
    static const QUMethod slot_0 = {"SlotNombre", 0, 0 };
    static const QUMethod slot_1 = {"SlotApellidoPaterno", 0, 0 };
    static const QUMethod slot_2 = {"SlotApellidoMaterno", 0, 0 };
    static const QUMethod slot_3 = {"SlotCtrPerfiles", 0, 0 };
    static const QUMethod slot_4 = {"SlotFirma", 0, 0 };
    static const QUMethod slot_5 = {"SlotContrasena", 0, 0 };
    static const QUMethod slot_6 = {"SlotRepetirContrasena", 0, 0 };
    static const QUMethod slot_7 = {"SlotRegistrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotNombre()", &slot_0, QMetaData::Private },
	{ "SlotApellidoPaterno()", &slot_1, QMetaData::Private },
	{ "SlotApellidoMaterno()", &slot_2, QMetaData::Private },
	{ "SlotCtrPerfiles()", &slot_3, QMetaData::Private },
	{ "SlotFirma()", &slot_4, QMetaData::Private },
	{ "SlotContrasena()", &slot_5, QMetaData::Private },
	{ "SlotRepetirContrasena()", &slot_6, QMetaData::Private },
	{ "SlotRegistrar()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpRegistroUsuarios", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpRegistroUsuarios.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpRegistroUsuarios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpRegistroUsuarios" ) )
	return this;
    return RegistroUsuarios::qt_cast( clname );
}

bool QtImpRegistroUsuarios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotNombre(); break;
    case 1: SlotApellidoPaterno(); break;
    case 2: SlotApellidoMaterno(); break;
    case 3: SlotCtrPerfiles(); break;
    case 4: SlotFirma(); break;
    case 5: SlotContrasena(); break;
    case 6: SlotRepetirContrasena(); break;
    case 7: SlotRegistrar(); break;
    default:
	return RegistroUsuarios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpRegistroUsuarios::qt_emit( int _id, QUObject* _o )
{
    return RegistroUsuarios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpRegistroUsuarios::qt_property( int id, int f, QVariant* v)
{
    return RegistroUsuarios::qt_property( id, f, v);
}

bool QtImpRegistroUsuarios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
