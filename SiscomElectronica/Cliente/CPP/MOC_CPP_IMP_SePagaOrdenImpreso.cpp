/****************************************************************************
** QSePagaOrdenImpreso meta object code from reading C++ file 'IMP_SePagaOrdenImpreso.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SePagaOrdenImpreso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSePagaOrdenImpreso::className() const
{
    return "QSePagaOrdenImpreso";
}

QMetaObject *QSePagaOrdenImpreso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSePagaOrdenImpreso( "QSePagaOrdenImpreso", &QSePagaOrdenImpreso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSePagaOrdenImpreso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSePagaOrdenImpreso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSePagaOrdenImpreso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSePagaOrdenImpreso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSePagaOrdenImpreso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SePagaOrdenImpreso::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSePagaCompleto", 0, 0 };
    static const QUMethod slot_1 = {"SlotSeDaAdelanto", 0, 0 };
    static const QUMethod slot_2 = {"SlotAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotFocoAAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSePagaCompleto()", &slot_0, QMetaData::Private },
	{ "SlotSeDaAdelanto()", &slot_1, QMetaData::Private },
	{ "SlotAceptar()", &slot_2, QMetaData::Private },
	{ "SlotFocoAAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSePagaOrdenImpreso", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSePagaOrdenImpreso.setMetaObject( metaObj );
    return metaObj;
}

void* QSePagaOrdenImpreso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSePagaOrdenImpreso" ) )
	return this;
    return SePagaOrdenImpreso::qt_cast( clname );
}

bool QSePagaOrdenImpreso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSePagaCompleto(); break;
    case 1: SlotSeDaAdelanto(); break;
    case 2: SlotAceptar(); break;
    case 3: SlotFocoAAceptar(); break;
    default:
	return SePagaOrdenImpreso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSePagaOrdenImpreso::qt_emit( int _id, QUObject* _o )
{
    return SePagaOrdenImpreso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSePagaOrdenImpreso::qt_property( int id, int f, QVariant* v)
{
    return SePagaOrdenImpreso::qt_property( id, f, v);
}

bool QSePagaOrdenImpreso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
