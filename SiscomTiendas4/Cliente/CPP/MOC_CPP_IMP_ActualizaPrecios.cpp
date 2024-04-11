/****************************************************************************
** QActualizaPrecios meta object code from reading C++ file 'IMP_ActualizaPrecios.h'
**
** Created: Thu Apr 11 20:30:21 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaPrecios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaPrecios::className() const
{
    return "QActualizaPrecios";
}

QMetaObject *QActualizaPrecios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaPrecios( "QActualizaPrecios", &QActualizaPrecios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaPrecios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaPrecios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaPrecios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaPrecios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaPrecios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaPrecios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "CQSisFamilia", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFamilia", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotConsulta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFamilia(CQSisFamilia*)", &slot_0, QMetaData::Private },
	{ "SlotConsulta()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QActualizaPrecios", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaPrecios.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaPrecios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaPrecios" ) )
	return this;
    return ActualizaPrecios::qt_cast( clname );
}

bool QActualizaPrecios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFamilia((CQSisFamilia*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotConsulta(); break;
    default:
	return ActualizaPrecios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActualizaPrecios::qt_emit( int _id, QUObject* _o )
{
    return ActualizaPrecios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QActualizaPrecios::qt_property( int id, int f, QVariant* v)
{
    return ActualizaPrecios::qt_property( id, f, v);
}

bool QActualizaPrecios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
