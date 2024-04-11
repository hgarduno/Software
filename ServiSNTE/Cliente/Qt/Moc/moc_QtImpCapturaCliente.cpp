/****************************************************************************
** QtImpCapturaCliente meta object code from reading C++ file 'QtImpCapturaCliente.h'
**
** Created: Thu Apr 11 21:07:59 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaCliente.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaCliente::className() const
{
    return "QtImpCapturaCliente";
}

QMetaObject *QtImpCapturaCliente::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaCliente( "QtImpCapturaCliente", &QtImpCapturaCliente::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaCliente::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCliente", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaCliente::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaCliente", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaCliente::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaCliente::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotCrear", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoARFC", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAApellidoPaterno", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAApellidoMaterno", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoANombres", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACrear", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"SlotCambioTexto", 1, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotCrear()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private },
	{ "SlotFocoARFC()", &slot_4, QMetaData::Private },
	{ "SlotFocoAApellidoPaterno()", &slot_5, QMetaData::Private },
	{ "SlotFocoAApellidoMaterno()", &slot_6, QMetaData::Private },
	{ "SlotFocoANombres()", &slot_7, QMetaData::Private },
	{ "SlotFocoACrear()", &slot_8, QMetaData::Private },
	{ "SlotCambioTexto(const QString&)", &slot_9, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaCliente", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaCliente.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaCliente::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaCliente" ) )
	return this;
    return CapturaCliente::qt_cast( clname );
}

bool QtImpCapturaCliente::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotCrear(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotCancelar(); break;
    case 4: SlotFocoARFC(); break;
    case 5: SlotFocoAApellidoPaterno(); break;
    case 6: SlotFocoAApellidoMaterno(); break;
    case 7: SlotFocoANombres(); break;
    case 8: SlotFocoACrear(); break;
    case 9: SlotCambioTexto((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return CapturaCliente::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaCliente::qt_emit( int _id, QUObject* _o )
{
    return CapturaCliente::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaCliente::qt_property( int id, int f, QVariant* v)
{
    return CapturaCliente::qt_property( id, f, v);
}

bool QtImpCapturaCliente::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
