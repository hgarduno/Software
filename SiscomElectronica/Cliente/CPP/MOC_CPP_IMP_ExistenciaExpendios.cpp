/****************************************************************************
** QExistenciaExpendios meta object code from reading C++ file 'IMP_ExistenciaExpendios.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ExistenciaExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QExistenciaExpendios::className() const
{
    return "QExistenciaExpendios";
}

QMetaObject *QExistenciaExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QExistenciaExpendios( "QExistenciaExpendios", &QExistenciaExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QExistenciaExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExistenciaExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QExistenciaExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QExistenciaExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QExistenciaExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ExistenciaExpendios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotActualizar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotActualizar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QExistenciaExpendios", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QExistenciaExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QExistenciaExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QExistenciaExpendios" ) )
	return this;
    return ExistenciaExpendios::qt_cast( clname );
}

bool QExistenciaExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotActualizar(); break;
    default:
	return ExistenciaExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QExistenciaExpendios::qt_emit( int _id, QUObject* _o )
{
    return ExistenciaExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QExistenciaExpendios::qt_property( int id, int f, QVariant* v)
{
    return ExistenciaExpendios::qt_property( id, f, v);
}

bool QExistenciaExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
