/****************************************************************************
** QContDeLasPracticas meta object code from reading C++ file 'IMP_ContDeLasPracticas.h'
**
** Created: Fri Apr 12 21:35:22 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ContDeLasPracticas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QContDeLasPracticas::className() const
{
    return "QContDeLasPracticas";
}

QMetaObject *QContDeLasPracticas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QContDeLasPracticas( "QContDeLasPracticas", &QContDeLasPracticas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QContDeLasPracticas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContDeLasPracticas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QContDeLasPracticas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContDeLasPracticas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QContDeLasPracticas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ContDeLasPracticas::staticMetaObject();
    static const QUMethod slot_0 = {"S_SelPractica", 0, 0 };
    static const QUMethod slot_1 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_2 = {"S_Registrar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SelPractica()", &slot_0, QMetaData::Private },
	{ "S_Anexar()", &slot_1, QMetaData::Private },
	{ "S_Registrar()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QContDeLasPracticas", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QContDeLasPracticas.setMetaObject( metaObj );
    return metaObj;
}

void* QContDeLasPracticas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QContDeLasPracticas" ) )
	return this;
    return ContDeLasPracticas::qt_cast( clname );
}

bool QContDeLasPracticas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SelPractica(); break;
    case 1: S_Anexar(); break;
    case 2: S_Registrar(); break;
    default:
	return ContDeLasPracticas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QContDeLasPracticas::qt_emit( int _id, QUObject* _o )
{
    return ContDeLasPracticas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QContDeLasPracticas::qt_property( int id, int f, QVariant* v)
{
    return ContDeLasPracticas::qt_property( id, f, v);
}

bool QContDeLasPracticas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
