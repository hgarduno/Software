/****************************************************************************
** QtImpAccesoServiSNTE meta object code from reading C++ file 'QtImpAccesoServiSNTE.h'
**
<<<<<<< HEAD
** Created: Mon Apr 1 17:32:06 2024
=======
** Created: Thu Apr 11 21:10:11 2024
>>>>>>> d8559e8a5b2006215346761b79004c9434166dbc
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QtImpAccesoServiSNTE.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtImpAccesoServiSNTE::className() const
{
    return "QtImpAccesoServiSNTE";
}

QMetaObject *QtImpAccesoServiSNTE::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtImpAccesoServiSNTE( "QtImpAccesoServiSNTE", &QtImpAccesoServiSNTE::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtImpAccesoServiSNTE::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpAccesoServiSNTE", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtImpAccesoServiSNTE::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtImpAccesoServiSNTE", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtImpAccesoServiSNTE::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AccesoServiSNTE::staticMetaObject();
    static const QUMethod slot_0 = {"reject", 0, 0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_2 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAPassword", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAAceptar", 0, 0 };
    static const QUMethod slot_5 = {"SlotTipoLetra", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "reject()", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private },
	{ "SlotCancelar()", &slot_2, QMetaData::Private },
	{ "SlotFocoAPassword()", &slot_3, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_4, QMetaData::Private },
	{ "SlotTipoLetra()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtImpAccesoServiSNTE", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtImpAccesoServiSNTE.setMetaObject( metaObj );
    return metaObj;
}

void* QtImpAccesoServiSNTE::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtImpAccesoServiSNTE" ) )
	return this;
    return AccesoServiSNTE::qt_cast( clname );
}

bool QtImpAccesoServiSNTE::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reject(); break;
    case 1: SlotAceptar(); break;
    case 2: SlotCancelar(); break;
    case 3: SlotFocoAPassword(); break;
    case 4: SlotFocoAAceptar(); break;
    case 5: SlotTipoLetra(); break;
    default:
	return AccesoServiSNTE::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtImpAccesoServiSNTE::qt_emit( int _id, QUObject* _o )
{
    return AccesoServiSNTE::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtImpAccesoServiSNTE::qt_property( int id, int f, QVariant* v)
{
    return AccesoServiSNTE::qt_property( id, f, v);
}

bool QtImpAccesoServiSNTE::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
