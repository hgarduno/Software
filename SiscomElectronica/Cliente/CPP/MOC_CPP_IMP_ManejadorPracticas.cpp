/****************************************************************************
** QManejadorPracticas meta object code from reading C++ file 'IMP_ManejadorPracticas.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorPracticas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorPracticas::className() const
{
    return "QManejadorPracticas";
}

QMetaObject *QManejadorPracticas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorPracticas( "QManejadorPracticas", &QManejadorPracticas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorPracticas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorPracticas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorPracticas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorPracticas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorPracticas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorPracticas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistraPractica", 0, 0 };
    static const QUMethod slot_1 = {"SlotSeleccionaPractica", 0, 0 };
    static const QUMethod slot_2 = {"SlotFocoAMateria", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAEscuelas", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotEscuela", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistraPractica()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaPractica()", &slot_1, QMetaData::Private },
	{ "SlotFocoAMateria()", &slot_2, QMetaData::Private },
	{ "SlotFocoAEscuelas()", &slot_3, QMetaData::Private },
	{ "SlotEscuela(zSiscomRegistro*)", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorPracticas", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorPracticas.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorPracticas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorPracticas" ) )
	return this;
    return ManejadorPracticas::qt_cast( clname );
}

bool QManejadorPracticas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistraPractica(); break;
    case 1: SlotSeleccionaPractica(); break;
    case 2: SlotFocoAMateria(); break;
    case 3: SlotFocoAEscuelas(); break;
    case 4: SlotEscuela((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ManejadorPracticas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorPracticas::qt_emit( int _id, QUObject* _o )
{
    return ManejadorPracticas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QManejadorPracticas::qt_property( int id, int f, QVariant* v)
{
    return ManejadorPracticas::qt_property( id, f, v);
}

bool QManejadorPracticas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
