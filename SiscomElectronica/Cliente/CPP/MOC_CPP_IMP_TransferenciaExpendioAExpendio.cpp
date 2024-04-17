/****************************************************************************
** QTransferenciaExpendioAExpendio meta object code from reading C++ file 'IMP_TransferenciaExpendioAExpendio.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_TransferenciaExpendioAExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QTransferenciaExpendioAExpendio::className() const
{
    return "QTransferenciaExpendioAExpendio";
}

QMetaObject *QTransferenciaExpendioAExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTransferenciaExpendioAExpendio( "QTransferenciaExpendioAExpendio", &QTransferenciaExpendioAExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTransferenciaExpendioAExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciaExpendioAExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTransferenciaExpendioAExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTransferenciaExpendioAExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTransferenciaExpendioAExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TransferenciaExpendioAExpendio::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pSiscomReg3ExpOrigen", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotExpendioO", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pSiscomReg3ExpDestino", &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotExpendioD", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "pzSisRegProducto", &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProducto", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotCapturoCantidad", 0, 0 };
    static const QUMethod slot_4 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_5 = {"SlotRegistrar", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotSeleccionaProducto", 4, param_slot_6 };
    static const QUMethod slot_7 = {"SlotEliminaProducto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotExpendioO(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotExpendioD(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotCapturoCantidad()", &slot_3, QMetaData::Private },
	{ "SlotAnexar()", &slot_4, QMetaData::Private },
	{ "SlotRegistrar()", &slot_5, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_6, QMetaData::Private },
	{ "SlotEliminaProducto()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QTransferenciaExpendioAExpendio", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTransferenciaExpendioAExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QTransferenciaExpendioAExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTransferenciaExpendioAExpendio" ) )
	return this;
    return TransferenciaExpendioAExpendio::qt_cast( clname );
}

bool QTransferenciaExpendioAExpendio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotExpendioO((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotExpendioD((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotCapturoCantidad(); break;
    case 4: SlotAnexar(); break;
    case 5: SlotRegistrar(); break;
    case 6: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 7: SlotEliminaProducto(); break;
    default:
	return TransferenciaExpendioAExpendio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTransferenciaExpendioAExpendio::qt_emit( int _id, QUObject* _o )
{
    return TransferenciaExpendioAExpendio::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTransferenciaExpendioAExpendio::qt_property( int id, int f, QVariant* v)
{
    return TransferenciaExpendioAExpendio::qt_property( id, f, v);
}

bool QTransferenciaExpendioAExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
