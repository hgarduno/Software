/****************************************************************************
** QActualizaExpendio meta object code from reading C++ file 'IMP_ActualizaExpendio.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ActualizaExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QActualizaExpendio::className() const
{
    return "QActualizaExpendio";
}

QMetaObject *QActualizaExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActualizaExpendio( "QActualizaExpendio", &QActualizaExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActualizaExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActualizaExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActualizaExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActualizaExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ActualizaExpendio::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionaExpendio", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotProductos", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaExpendio(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotProductos()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QActualizaExpendio", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActualizaExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QActualizaExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActualizaExpendio" ) )
	return this;
    return ActualizaExpendio::qt_cast( clname );
}

bool QActualizaExpendio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaExpendio((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotProductos(); break;
    default:
	return ActualizaExpendio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActualizaExpendio::qt_emit( int _id, QUObject* _o )
{
    return ActualizaExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QActualizaExpendio::qt_property( int id, int f, QVariant* v)
{
    return ActualizaExpendio::qt_property( id, f, v);
}

bool QActualizaExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
