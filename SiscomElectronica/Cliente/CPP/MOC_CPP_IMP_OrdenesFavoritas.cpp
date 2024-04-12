/****************************************************************************
** QOrdenesFavoritas meta object code from reading C++ file 'IMP_OrdenesFavoritas.h'
**
** Created: Thu Apr 11 21:40:02 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenesFavoritas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenesFavoritas::className() const
{
    return "QOrdenesFavoritas";
}

QMetaObject *QOrdenesFavoritas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenesFavoritas( "QOrdenesFavoritas", &QOrdenesFavoritas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenesFavoritas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesFavoritas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenesFavoritas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesFavoritas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenesFavoritas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenesFavoritas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSelOrden", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "zOrdenVenta", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionoOrden", 1, param_slot_1 };
    static const QUMethod slot_2 = {"SlotRegistraFavoritas", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QtSisBotonOrden", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotOrden", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QtSisBotonOrden", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotMarcaParaEliminar", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotCapturandoFavorita", 0, 0 };
    static const QUMethod slot_6 = {"SlotAsignaOrdenFavorita", 0, 0 };
    static const QUMethod slot_7 = {"SlotEliminaOrden", 0, 0 };
    static const QUMethod slot_8 = {"SlotAgregaOrdenFavorita", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelOrden()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionoOrden(zOrdenVenta*)", &slot_1, QMetaData::Private },
	{ "SlotRegistraFavoritas()", &slot_2, QMetaData::Private },
	{ "SlotOrden(QtSisBotonOrden*)", &slot_3, QMetaData::Private },
	{ "SlotMarcaParaEliminar(QtSisBotonOrden*)", &slot_4, QMetaData::Private },
	{ "SlotCapturandoFavorita()", &slot_5, QMetaData::Private },
	{ "SlotAsignaOrdenFavorita()", &slot_6, QMetaData::Private },
	{ "SlotEliminaOrden()", &slot_7, QMetaData::Private },
	{ "SlotAgregaOrdenFavorita()", &slot_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenesFavoritas", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenesFavoritas.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenesFavoritas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenesFavoritas" ) )
	return this;
    return OrdenesFavoritas::qt_cast( clname );
}

bool QOrdenesFavoritas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelOrden(); break;
    case 1: SlotSeleccionoOrden((zOrdenVenta*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotRegistraFavoritas(); break;
    case 3: SlotOrden((QtSisBotonOrden*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotMarcaParaEliminar((QtSisBotonOrden*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotCapturandoFavorita(); break;
    case 6: SlotAsignaOrdenFavorita(); break;
    case 7: SlotEliminaOrden(); break;
    case 8: SlotAgregaOrdenFavorita(); break;
    default:
	return OrdenesFavoritas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenesFavoritas::qt_emit( int _id, QUObject* _o )
{
    return OrdenesFavoritas::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QOrdenesFavoritas::qt_property( int id, int f, QVariant* v)
{
    return OrdenesFavoritas::qt_property( id, f, v);
}

bool QOrdenesFavoritas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
