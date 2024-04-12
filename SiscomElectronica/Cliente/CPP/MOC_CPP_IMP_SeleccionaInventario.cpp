/****************************************************************************
** QSeleccionaInventario meta object code from reading C++ file 'IMP_SeleccionaInventario.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeleccionaInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeleccionaInventario::className() const
{
    return "QSeleccionaInventario";
}

QMetaObject *QSeleccionaInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeleccionaInventario( "QSeleccionaInventario", &QSeleccionaInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeleccionaInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeleccionaInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeleccionaInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaInventario::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionaInventario", 4, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionaInventario(int,int,int,const QPoint&)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeleccionaInventario", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeleccionaInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QSeleccionaInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeleccionaInventario" ) )
	return this;
    return SeleccionaInventario::qt_cast( clname );
}

bool QSeleccionaInventario::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionaInventario((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return SeleccionaInventario::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeleccionaInventario::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaInventario::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSeleccionaInventario::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaInventario::qt_property( id, f, v);
}

bool QSeleccionaInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
