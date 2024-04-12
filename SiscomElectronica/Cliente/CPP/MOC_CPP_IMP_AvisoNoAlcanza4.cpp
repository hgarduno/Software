/****************************************************************************
** QAvisoNoAlcanza4 meta object code from reading C++ file 'IMP_AvisoNoAlcanza4.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AvisoNoAlcanza4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAvisoNoAlcanza4::className() const
{
    return "QAvisoNoAlcanza4";
}

QMetaObject *QAvisoNoAlcanza4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAvisoNoAlcanza4( "QAvisoNoAlcanza4", &QAvisoNoAlcanza4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAvisoNoAlcanza4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAvisoNoAlcanza4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAvisoNoAlcanza4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAvisoNoAlcanza4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAvisoNoAlcanza4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AvisoNoAlcanza4::staticMetaObject();
    static const QUMethod slot_0 = {"SlotCambiaCantidad", 0, 0 };
    static const QUMethod slot_1 = {"SlotEliminar", 0, 0 };
    static const QUMethod slot_2 = {"SlotVende", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCambiaCantidad()", &slot_0, QMetaData::Private },
	{ "SlotEliminar()", &slot_1, QMetaData::Private },
	{ "SlotVende()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAvisoNoAlcanza4", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAvisoNoAlcanza4.setMetaObject( metaObj );
    return metaObj;
}

void* QAvisoNoAlcanza4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAvisoNoAlcanza4" ) )
	return this;
    return AvisoNoAlcanza4::qt_cast( clname );
}

bool QAvisoNoAlcanza4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCambiaCantidad(); break;
    case 1: SlotEliminar(); break;
    case 2: SlotVende(); break;
    default:
	return AvisoNoAlcanza4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAvisoNoAlcanza4::qt_emit( int _id, QUObject* _o )
{
    return AvisoNoAlcanza4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAvisoNoAlcanza4::qt_property( int id, int f, QVariant* v)
{
    return AvisoNoAlcanza4::qt_property( id, f, v);
}

bool QAvisoNoAlcanza4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
