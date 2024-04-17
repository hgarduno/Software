/****************************************************************************
** QCapturaDireccionE meta object code from reading C++ file 'IMP_CapturaDireccionE.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaDireccionE.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaDireccionE::className() const
{
    return "QCapturaDireccionE";
}

QMetaObject *QCapturaDireccionE::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaDireccionE( "QCapturaDireccionE", &QCapturaDireccionE::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaDireccionE::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaDireccionE", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaDireccionE::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaDireccionE", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaDireccionE::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaDireccionE::staticMetaObject();
    static const QUMethod slot_0 = {"SlotPasaFocoLinea2", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoLinea3", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoAceptar", 0, 0 };
    static const QUMethod slot_3 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotPasaFocoLinea2()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoLinea3()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoAceptar()", &slot_2, QMetaData::Private },
	{ "SlotAceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaDireccionE", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaDireccionE.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaDireccionE::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaDireccionE" ) )
	return this;
    return CapturaDireccionE::qt_cast( clname );
}

bool QCapturaDireccionE::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotPasaFocoLinea2(); break;
    case 1: SlotPasaFocoLinea3(); break;
    case 2: SlotPasaFocoAceptar(); break;
    case 3: SlotAceptar(); break;
    default:
	return CapturaDireccionE::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaDireccionE::qt_emit( int _id, QUObject* _o )
{
    return CapturaDireccionE::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaDireccionE::qt_property( int id, int f, QVariant* v)
{
    return CapturaDireccionE::qt_property( id, f, v);
}

bool QCapturaDireccionE::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
