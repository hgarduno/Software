/****************************************************************************
** QCambiaEdoControlCaja meta object code from reading C++ file 'IMP_CambiaEdoControlCaja.h'
**
** Created: Fri Apr 12 21:26:08 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CambiaEdoControlCaja.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCambiaEdoControlCaja::className() const
{
    return "QCambiaEdoControlCaja";
}

QMetaObject *QCambiaEdoControlCaja::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCambiaEdoControlCaja( "QCambiaEdoControlCaja", &QCambiaEdoControlCaja::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCambiaEdoControlCaja::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCambiaEdoControlCaja", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCambiaEdoControlCaja::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCambiaEdoControlCaja", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCambiaEdoControlCaja::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CambiaEdoControlCaja::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotEstado", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAceptar()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private },
	{ "SlotEstado(int)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCambiaEdoControlCaja", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCambiaEdoControlCaja.setMetaObject( metaObj );
    return metaObj;
}

void* QCambiaEdoControlCaja::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCambiaEdoControlCaja" ) )
	return this;
    return CambiaEdoControlCaja::qt_cast( clname );
}

bool QCambiaEdoControlCaja::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAceptar(); break;
    case 1: SlotCancelar(); break;
    case 2: SlotEstado((int)static_QUType_int.get(_o+1)); break;
    default:
	return CambiaEdoControlCaja::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCambiaEdoControlCaja::qt_emit( int _id, QUObject* _o )
{
    return CambiaEdoControlCaja::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCambiaEdoControlCaja::qt_property( int id, int f, QVariant* v)
{
    return CambiaEdoControlCaja::qt_property( id, f, v);
}

bool QCambiaEdoControlCaja::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
