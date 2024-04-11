/****************************************************************************
** QCapturaIva meta object code from reading C++ file 'IMP_CapturaIva.h'
**
** Created: Wed Apr 10 21:10:16 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CapturaIva.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCapturaIva::className() const
{
    return "QCapturaIva";
}

QMetaObject *QCapturaIva::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCapturaIva( "QCapturaIva", &QCapturaIva::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCapturaIva::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaIva", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCapturaIva::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCapturaIva", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCapturaIva::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CapturaIva::staticMetaObject();
    static const QUMethod slot_0 = {"S_MasIva", 0, 0 };
    static const QUMethod slot_1 = {"S_ConIva", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_MasIva()", &slot_0, QMetaData::Private },
	{ "S_ConIva()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCapturaIva", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCapturaIva.setMetaObject( metaObj );
    return metaObj;
}

void* QCapturaIva::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCapturaIva" ) )
	return this;
    return CapturaIva::qt_cast( clname );
}

bool QCapturaIva::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_MasIva(); break;
    case 1: S_ConIva(); break;
    default:
	return CapturaIva::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCapturaIva::qt_emit( int _id, QUObject* _o )
{
    return CapturaIva::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCapturaIva::qt_property( int id, int f, QVariant* v)
{
    return CapturaIva::qt_property( id, f, v);
}

bool QCapturaIva::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
