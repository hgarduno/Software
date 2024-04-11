/****************************************************************************
** QSelExpendios meta object code from reading C++ file 'IMP_SelExpendios.h'
**
** Created: Wed Apr 10 20:52:23 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SelExpendios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSelExpendios::className() const
{
    return "QSelExpendios";
}

QMetaObject *QSelExpendios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSelExpendios( "QSelExpendios", &QSelExpendios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSelExpendios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelExpendios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSelExpendios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSelExpendios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSelExpendios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SelExpendios::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoExpendio", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoExpendio(QIconViewItem*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSelExpendios", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSelExpendios.setMetaObject( metaObj );
    return metaObj;
}

void* QSelExpendios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSelExpendios" ) )
	return this;
    return SelExpendios::qt_cast( clname );
}

bool QSelExpendios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoExpendio((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return SelExpendios::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSelExpendios::qt_emit( int _id, QUObject* _o )
{
    return SelExpendios::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSelExpendios::qt_property( int id, int f, QVariant* v)
{
    return SelExpendios::qt_property( id, f, v);
}

bool QSelExpendios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
