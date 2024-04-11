/****************************************************************************
** QProveedoresCompraImportacion meta object code from reading C++ file 'IMP_ProveedoresCompraImportacion.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProveedoresCompraImportacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProveedoresCompraImportacion::className() const
{
    return "QProveedoresCompraImportacion";
}

QMetaObject *QProveedoresCompraImportacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProveedoresCompraImportacion( "QProveedoresCompraImportacion", &QProveedoresCompraImportacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProveedoresCompraImportacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProveedoresCompraImportacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProveedoresCompraImportacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProveedoresCompraImportacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProveedoresCompraImportacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProveedoresCompraImportacion::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProveedor", 4, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProveedor(int,int,int,const QPoint&)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProveedoresCompraImportacion", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProveedoresCompraImportacion.setMetaObject( metaObj );
    return metaObj;
}

void* QProveedoresCompraImportacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProveedoresCompraImportacion" ) )
	return this;
    return ProveedoresCompraImportacion::qt_cast( clname );
}

bool QProveedoresCompraImportacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProveedor((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ProveedoresCompraImportacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProveedoresCompraImportacion::qt_emit( int _id, QUObject* _o )
{
    return ProveedoresCompraImportacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProveedoresCompraImportacion::qt_property( int id, int f, QVariant* v)
{
    return ProveedoresCompraImportacion::qt_property( id, f, v);
}

bool QProveedoresCompraImportacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
