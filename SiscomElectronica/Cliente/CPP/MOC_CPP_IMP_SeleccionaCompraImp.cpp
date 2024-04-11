/****************************************************************************
** QSeleccionaCompraImp meta object code from reading C++ file 'IMP_SeleccionaCompraImp.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_SeleccionaCompraImp.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSeleccionaCompraImp::className() const
{
    return "QSeleccionaCompraImp";
}

QMetaObject *QSeleccionaCompraImp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSeleccionaCompraImp( "QSeleccionaCompraImp", &QSeleccionaCompraImp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSeleccionaCompraImp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaCompraImp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSeleccionaCompraImp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSeleccionaCompraImp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSeleccionaCompraImp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = SeleccionaCompraImp::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSelecciono", 4, param_slot_0 };
    static const QUMethod slot_1 = {"SlotAceptar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciono(int,int,int,const QPoint&)", &slot_0, QMetaData::Private },
	{ "SlotAceptar()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSeleccionaCompraImp", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSeleccionaCompraImp.setMetaObject( metaObj );
    return metaObj;
}

void* QSeleccionaCompraImp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSeleccionaCompraImp" ) )
	return this;
    return SeleccionaCompraImp::qt_cast( clname );
}

bool QSeleccionaCompraImp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciono((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 1: SlotAceptar(); break;
    default:
	return SeleccionaCompraImp::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSeleccionaCompraImp::qt_emit( int _id, QUObject* _o )
{
    return SeleccionaCompraImp::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSeleccionaCompraImp::qt_property( int id, int f, QVariant* v)
{
    return SeleccionaCompraImp::qt_property( id, f, v);
}

bool QSeleccionaCompraImp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
