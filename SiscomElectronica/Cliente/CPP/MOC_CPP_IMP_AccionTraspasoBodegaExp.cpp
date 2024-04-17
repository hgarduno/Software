/****************************************************************************
** QAccionTraspasoBodegaExp meta object code from reading C++ file 'IMP_AccionTraspasoBodegaExp.h'
**
** Created: Fri Apr 12 21:26:10 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AccionTraspasoBodegaExp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAccionTraspasoBodegaExp::className() const
{
    return "QAccionTraspasoBodegaExp";
}

QMetaObject *QAccionTraspasoBodegaExp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAccionTraspasoBodegaExp( "QAccionTraspasoBodegaExp", &QAccionTraspasoBodegaExp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAccionTraspasoBodegaExp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccionTraspasoBodegaExp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAccionTraspasoBodegaExp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccionTraspasoBodegaExp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAccionTraspasoBodegaExp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AccionTraspasoBodegaExp::staticMetaObject();
    static const QUMethod slot_0 = {"SlotTraspasoExistenciaBodegaExpendio", 0, 0 };
    static const QUMethod slot_1 = {"SlotCancelar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotTraspasoExistenciaBodegaExpendio()", &slot_0, QMetaData::Private },
	{ "SlotCancelar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAccionTraspasoBodegaExp", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAccionTraspasoBodegaExp.setMetaObject( metaObj );
    return metaObj;
}

void* QAccionTraspasoBodegaExp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAccionTraspasoBodegaExp" ) )
	return this;
    return AccionTraspasoBodegaExp::qt_cast( clname );
}

bool QAccionTraspasoBodegaExp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotTraspasoExistenciaBodegaExpendio(); break;
    case 1: SlotCancelar(); break;
    default:
	return AccionTraspasoBodegaExp::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAccionTraspasoBodegaExp::qt_emit( int _id, QUObject* _o )
{
    return AccionTraspasoBodegaExp::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAccionTraspasoBodegaExp::qt_property( int id, int f, QVariant* v)
{
    return AccionTraspasoBodegaExp::qt_property( id, f, v);
}

bool QAccionTraspasoBodegaExp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
