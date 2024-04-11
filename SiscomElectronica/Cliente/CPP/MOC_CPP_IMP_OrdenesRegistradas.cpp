/****************************************************************************
** QOrdenesRegistradas meta object code from reading C++ file 'IMP_OrdenesRegistradas.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenesRegistradas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenesRegistradas::className() const
{
    return "QOrdenesRegistradas";
}

QMetaObject *QOrdenesRegistradas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenesRegistradas( "QOrdenesRegistradas", &QOrdenesRegistradas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenesRegistradas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesRegistradas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenesRegistradas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesRegistradas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenesRegistradas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtOrdenesRegistradas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotConsulta", 0, 0 };
    static const QUMethod slot_1 = {"SlotImprimir", 0, 0 };
    static const QUMethod slot_2 = {"SlotVender", 0, 0 };
    static const QUMethod slot_3 = {"SlotDevolucion", 0, 0 };
    static const QUMethod slot_4 = {"SlotSeReflejo", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotConsulta()", &slot_0, QMetaData::Private },
	{ "SlotImprimir()", &slot_1, QMetaData::Private },
	{ "SlotVender()", &slot_2, QMetaData::Private },
	{ "SlotDevolucion()", &slot_3, QMetaData::Private },
	{ "SlotSeReflejo()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenesRegistradas", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenesRegistradas.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenesRegistradas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenesRegistradas" ) )
	return this;
    return QtOrdenesRegistradas::qt_cast( clname );
}

bool QOrdenesRegistradas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotConsulta(); break;
    case 1: SlotImprimir(); break;
    case 2: SlotVender(); break;
    case 3: SlotDevolucion(); break;
    case 4: SlotSeReflejo(); break;
    default:
	return QtOrdenesRegistradas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenesRegistradas::qt_emit( int _id, QUObject* _o )
{
    return QtOrdenesRegistradas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenesRegistradas::qt_property( int id, int f, QVariant* v)
{
    return QtOrdenesRegistradas::qt_property( id, f, v);
}

bool QOrdenesRegistradas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
