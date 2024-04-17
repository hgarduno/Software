/****************************************************************************
** QAvisoNoAlcanza meta object code from reading C++ file 'IMP_AvisoNoAlcanza.h'
**
** Created: Fri Apr 12 21:25:32 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_AvisoNoAlcanza.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QAvisoNoAlcanza::className() const
{
    return "QAvisoNoAlcanza";
}

QMetaObject *QAvisoNoAlcanza::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAvisoNoAlcanza( "QAvisoNoAlcanza", &QAvisoNoAlcanza::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAvisoNoAlcanza::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAvisoNoAlcanza", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAvisoNoAlcanza::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAvisoNoAlcanza", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAvisoNoAlcanza::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = AvisoNoAlcanza::staticMetaObject();
    static const QUMethod slot_0 = {"S_VendoLoQueHay", 0, 0 };
    static const QUMethod slot_1 = {"S_CambiaCantidad", 0, 0 };
    static const QUMethod slot_2 = {"S_Eliminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_VendoLoQueHay()", &slot_0, QMetaData::Private },
	{ "S_CambiaCantidad()", &slot_1, QMetaData::Private },
	{ "S_Eliminar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAvisoNoAlcanza", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAvisoNoAlcanza.setMetaObject( metaObj );
    return metaObj;
}

void* QAvisoNoAlcanza::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAvisoNoAlcanza" ) )
	return this;
    return AvisoNoAlcanza::qt_cast( clname );
}

bool QAvisoNoAlcanza::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_VendoLoQueHay(); break;
    case 1: S_CambiaCantidad(); break;
    case 2: S_Eliminar(); break;
    default:
	return AvisoNoAlcanza::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAvisoNoAlcanza::qt_emit( int _id, QUObject* _o )
{
    return AvisoNoAlcanza::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAvisoNoAlcanza::qt_property( int id, int f, QVariant* v)
{
    return AvisoNoAlcanza::qt_property( id, f, v);
}

bool QAvisoNoAlcanza::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
