/****************************************************************************
** QSelOrden meta object code from reading C++ file 'IMP_SelOrden.h'
**
** Created: Wed Apr 10 21:11:00 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SelOrden.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSelOrden::className() const
{
    return "QSelOrden";
}

QMetaObject *QSelOrden::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSelOrden( "QSelOrden", &QSelOrden::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSelOrden::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelOrden", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSelOrden::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelOrden", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSelOrden::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SelOrden::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionaOrden", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_SeleccionoOrden", 1, param_slot_1 };
    static const QUMethod slot_2 = {"S_Cancelar", 0, 0 };
    static const QUMethod slot_3 = {"S_Aceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionaOrden(QIconViewItem*)", &slot_0, QMetaData::Private },
	{ "S_SeleccionoOrden(QIconViewItem*)", &slot_1, QMetaData::Private },
	{ "S_Cancelar()", &slot_2, QMetaData::Private },
	{ "S_Aceptar()", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSelOrden", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSelOrden.setMetaObject( metaObj );
    return metaObj;
}

void* QSelOrden::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSelOrden" ) )
	return this;
    return SelOrden::qt_cast( clname );
}

bool QSelOrden::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionaOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_SeleccionoOrden((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: S_Cancelar(); break;
    case 3: S_Aceptar(); break;
    default:
	return SelOrden::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSelOrden::qt_emit( int _id, QUObject* _o )
{
    return SelOrden::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSelOrden::qt_property( int id, int f, QVariant* v)
{
    return SelOrden::qt_property( id, f, v);
}

bool QSelOrden::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
