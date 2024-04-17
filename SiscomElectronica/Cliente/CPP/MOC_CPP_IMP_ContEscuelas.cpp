/****************************************************************************
** QContEscuelas meta object code from reading C++ file 'IMP_ContEscuelas.h'
**
** Created: Fri Apr 12 21:35:25 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ContEscuelas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QContEscuelas::className() const
{
    return "QContEscuelas";
}

QMetaObject *QContEscuelas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QContEscuelas( "QContEscuelas", &QContEscuelas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QContEscuelas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContEscuelas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QContEscuelas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContEscuelas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QContEscuelas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ContEscuelas::staticMetaObject();
    static const QUMethod slot_0 = {"S_SelEscuela", 0, 0 };
    static const QUMethod slot_1 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_2 = {"S_Registrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SelEscuela()", &slot_0, QMetaData::Private },
	{ "S_Anexar()", &slot_1, QMetaData::Private },
	{ "S_Registrar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QContEscuelas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QContEscuelas.setMetaObject( metaObj );
    return metaObj;
}

void* QContEscuelas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QContEscuelas" ) )
	return this;
    return ContEscuelas::qt_cast( clname );
}

bool QContEscuelas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SelEscuela(); break;
    case 1: S_Anexar(); break;
    case 2: S_Registrar(); break;
    default:
	return ContEscuelas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QContEscuelas::qt_emit( int _id, QUObject* _o )
{
    return ContEscuelas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QContEscuelas::qt_property( int id, int f, QVariant* v)
{
    return ContEscuelas::qt_property( id, f, v);
}

bool QContEscuelas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
