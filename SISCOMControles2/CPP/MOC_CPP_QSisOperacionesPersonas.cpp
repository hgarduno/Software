/****************************************************************************
** QSisOperacionesPersonas meta object code from reading C++ file 'QSisOperacionesPersonas.h'
**
** Created: Wed Jan 31 10:35:16 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QSisOperacionesPersonas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSisOperacionesPersonas::className() const
{
    return "QSisOperacionesPersonas";
}

QMetaObject *QSisOperacionesPersonas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSisOperacionesPersonas( "QSisOperacionesPersonas", &QSisOperacionesPersonas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSisOperacionesPersonas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisOperacionesPersonas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSisOperacionesPersonas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisOperacionesPersonas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSisOperacionesPersonas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoOperacion", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoOperacion(QIconViewItem*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSisOperacionesPersonas", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSisOperacionesPersonas.setMetaObject( metaObj );
    return metaObj;
}

void* QSisOperacionesPersonas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSisOperacionesPersonas" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QSisOperacionesPersonas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoOperacion((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSisOperacionesPersonas::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSisOperacionesPersonas::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSisOperacionesPersonas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
