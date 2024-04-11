/****************************************************************************
** QRegistroProductosSiscom meta object code from reading C++ file 'IMP_RegistroProductosSiscom.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroProductosSiscom.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroProductosSiscom::className() const
{
    return "QRegistroProductosSiscom";
}

QMetaObject *QRegistroProductosSiscom::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroProductosSiscom( "QRegistroProductosSiscom", &QRegistroProductosSiscom::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroProductosSiscom::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroProductosSiscom", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroProductosSiscom::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroProductosSiscom", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroProductosSiscom::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroProductosSiscom::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSeleccionoProducto", 1, param_slot_0 };
    static const QUMethod slot_1 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_2 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotCapturandoCantidad", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotExpendio", 0, 0 };
    static const QUMethod slot_5 = {"SlotBodega", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSeleccionoProducto(zSiscomRegistro*)", &slot_0, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_1, QMetaData::Private },
	{ "SlotRegistrar()", &slot_2, QMetaData::Private },
	{ "SlotCapturandoCantidad(const QString&)", &slot_3, QMetaData::Private },
	{ "SlotExpendio()", &slot_4, QMetaData::Private },
	{ "SlotBodega()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroProductosSiscom", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroProductosSiscom.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroProductosSiscom::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroProductosSiscom" ) )
	return this;
    return RegistroProductosSiscom::qt_cast( clname );
}

bool QRegistroProductosSiscom::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSeleccionoProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotFocoARegistrar(); break;
    case 2: SlotRegistrar(); break;
    case 3: SlotCapturandoCantidad((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: SlotExpendio(); break;
    case 5: SlotBodega(); break;
    default:
	return RegistroProductosSiscom::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroProductosSiscom::qt_emit( int _id, QUObject* _o )
{
    return RegistroProductosSiscom::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroProductosSiscom::qt_property( int id, int f, QVariant* v)
{
    return RegistroProductosSiscom::qt_property( id, f, v);
}

bool QRegistroProductosSiscom::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
