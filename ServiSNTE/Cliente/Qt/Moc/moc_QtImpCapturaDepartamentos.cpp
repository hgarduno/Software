/****************************************************************************
** QtImpCapturaDepartamentos meta object code from reading C++ file 'QtImpCapturaDepartamentos.h'
**
** Created: Thu Aug 15 00:49:44 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpCapturaDepartamentos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpCapturaDepartamentos::className() const
{
    return "QtImpCapturaDepartamentos";
}

QMetaObject *QtImpCapturaDepartamentos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpCapturaDepartamentos( "QtImpCapturaDepartamentos", &QtImpCapturaDepartamentos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpCapturaDepartamentos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDepartamentos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpCapturaDepartamentos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpCapturaDepartamentos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpCapturaDepartamentos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDepartamentos::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotCrear", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAbreviatura", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoANombreDepartamento", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoACrear", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotCrear()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAbreviatura()", &slot_3, QMetaData::Private },
	{ "SlotFocoANombreDepartamento()", &slot_4, QMetaData::Private },
	{ "SlotFocoACrear()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpCapturaDepartamentos", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpCapturaDepartamentos.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpCapturaDepartamentos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpCapturaDepartamentos" ) )
	return this;
    return CapturaDepartamentos::qt_cast( clname );
}

bool QtImpCapturaDepartamentos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotCrear(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotFocoAAbreviatura(); break;
    case 4: SlotFocoANombreDepartamento(); break;
    case 5: SlotFocoACrear(); break;
    default:
	return CapturaDepartamentos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpCapturaDepartamentos::qt_emit( int _id, QUObject* _o )
{
    return CapturaDepartamentos::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpCapturaDepartamentos::qt_property( int id, int f, QVariant* v)
{
    return CapturaDepartamentos::qt_property( id, f, v);
}

bool QtImpCapturaDepartamentos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
