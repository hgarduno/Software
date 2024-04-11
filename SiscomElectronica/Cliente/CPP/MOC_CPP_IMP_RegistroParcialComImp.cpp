/****************************************************************************
** QRegistroParcialComImp meta object code from reading C++ file 'IMP_RegistroParcialComImp.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroParcialComImp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroParcialComImp::className() const
{
    return "QRegistroParcialComImp";
}

QMetaObject *QRegistroParcialComImp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroParcialComImp( "QRegistroParcialComImp", &QRegistroParcialComImp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroParcialComImp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroParcialComImp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroParcialComImp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroParcialComImp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroParcialComImp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QtRegistroParcialComImp::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistroProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistroProductos()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroParcialComImp", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroParcialComImp.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroParcialComImp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroParcialComImp" ) )
	return this;
    return QtRegistroParcialComImp::qt_cast( clname );
}

bool QRegistroParcialComImp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistroProductos(); break;
    default:
	return QtRegistroParcialComImp::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroParcialComImp::qt_emit( int _id, QUObject* _o )
{
    return QtRegistroParcialComImp::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroParcialComImp::qt_property( int id, int f, QVariant* v)
{
    return QtRegistroParcialComImp::qt_property( id, f, v);
}

bool QRegistroParcialComImp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
