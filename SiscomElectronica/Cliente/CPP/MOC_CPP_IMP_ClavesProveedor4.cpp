/****************************************************************************
** QClavesProveedor4 meta object code from reading C++ file 'IMP_ClavesProveedor4.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ClavesProveedor4.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClavesProveedor4::className() const
{
    return "QClavesProveedor4";
}

QMetaObject *QClavesProveedor4::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClavesProveedor4( "QClavesProveedor4", &QClavesProveedor4::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClavesProveedor4::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClavesProveedor4", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClavesProveedor4::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClavesProveedor4", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClavesProveedor4::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ClavesProveedor4::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotProveedor", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotFocoADescripcionP", 0, 0 };
    static const QUMethod slot_3 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_4 = {"SlotRegistra", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCapturandoClaveP", 1, param_slot_5 };
    static const QUMethod slot_6 = {"SlotCapturandoDescripcionP", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotClave", 4, param_slot_7 };
    static const QUMethod slot_8 = {"SlotActualizar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotProveedor(zSiscomRegistro*)", &slot_1, QMetaData::Private },
	{ "SlotFocoADescripcionP()", &slot_2, QMetaData::Private },
	{ "SlotAnexar()", &slot_3, QMetaData::Private },
	{ "SlotRegistra()", &slot_4, QMetaData::Private },
	{ "SlotCapturandoClaveP(const QString&)", &slot_5, QMetaData::Private },
	{ "SlotCapturandoDescripcionP()", &slot_6, QMetaData::Private },
	{ "SlotClave(int,int,int,const QPoint&)", &slot_7, QMetaData::Private },
	{ "SlotActualizar()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClavesProveedor4", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClavesProveedor4.setMetaObject( metaObj );
    return metaObj;
}

void* QClavesProveedor4::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClavesProveedor4" ) )
	return this;
    return ClavesProveedor4::qt_cast( clname );
}

bool QClavesProveedor4::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotFocoADescripcionP(); break;
    case 3: SlotAnexar(); break;
    case 4: SlotRegistra(); break;
    case 5: SlotCapturandoClaveP((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: SlotCapturandoDescripcionP(); break;
    case 7: SlotClave((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 8: SlotActualizar(); break;
    default:
	return ClavesProveedor4::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClavesProveedor4::qt_emit( int _id, QUObject* _o )
{
    return ClavesProveedor4::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QClavesProveedor4::qt_property( int id, int f, QVariant* v)
{
    return ClavesProveedor4::qt_property( id, f, v);
}

bool QClavesProveedor4::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
