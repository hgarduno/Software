/****************************************************************************
** QManejadorProductos meta object code from reading C++ file 'IMP_ManejadorProductos.h'
**
** Created: Wed Apr 10 21:11:47 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorProductos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorProductos::className() const
{
    return "QManejadorProductos";
}

QMetaObject *QManejadorProductos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorProductos( "QManejadorProductos", &QManejadorProductos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorProductos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProductos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorProductos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProductos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorProductos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorProductos::staticMetaObject();
    static const QUMethod slot_0 = {"S_ModificaProductos", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoUnidades", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoProducto", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoAnexarProducto", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "Unidad", QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_SeleccionoUnidad", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "Familia", QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_SeleccionoFamilia", 1, param_slot_6 };
    static const QUMethod slot_7 = {"S_AnexarProducto", 0, 0 };
    static const QUMethod slot_8 = {"S_RegistraProductos", 0, 0 };
    static const QUMethod slot_9 = {"S_EliminarDeLaLista", 0, 0 };
    static const QUMethod slot_10 = {"S_CambiaEliminaClave", 0, 0 };
    static const QUMethod slot_11 = {"S_CapturandoDescripcion", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"S_CapturandoClave", 1, param_slot_12 };
    static const QMetaData slot_tbl[] = {
	{ "S_ModificaProductos()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoUnidades()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoDescripcion()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoProducto()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoAnexarProducto()", &slot_4, QMetaData::Private },
	{ "S_SeleccionoUnidad(Unidad*)", &slot_5, QMetaData::Private },
	{ "S_SeleccionoFamilia(Familia*)", &slot_6, QMetaData::Private },
	{ "S_AnexarProducto()", &slot_7, QMetaData::Private },
	{ "S_RegistraProductos()", &slot_8, QMetaData::Private },
	{ "S_EliminarDeLaLista()", &slot_9, QMetaData::Private },
	{ "S_CambiaEliminaClave()", &slot_10, QMetaData::Private },
	{ "S_CapturandoDescripcion()", &slot_11, QMetaData::Private },
	{ "S_CapturandoClave(const QString&)", &slot_12, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorProductos", parentObject,
	slot_tbl, 13,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorProductos.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorProductos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorProductos" ) )
	return this;
    return ManejadorProductos::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QManejadorProductos::SignalTerminar( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QManejadorProductos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_ModificaProductos(); break;
    case 1: S_PasaFocoUnidades(); break;
    case 2: S_PasaFocoDescripcion(); break;
    case 3: S_PasaFocoProducto(); break;
    case 4: S_PasaFocoAnexarProducto(); break;
    case 5: S_SeleccionoUnidad((Unidad*)static_QUType_ptr.get(_o+1)); break;
    case 6: S_SeleccionoFamilia((Familia*)static_QUType_ptr.get(_o+1)); break;
    case 7: S_AnexarProducto(); break;
    case 8: S_RegistraProductos(); break;
    case 9: S_EliminarDeLaLista(); break;
    case 10: S_CambiaEliminaClave(); break;
    case 11: S_CapturandoDescripcion(); break;
    case 12: S_CapturandoClave((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return ManejadorProductos::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorProductos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ManejadorProductos::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QManejadorProductos::qt_property( int id, int f, QVariant* v)
{
    return ManejadorProductos::qt_property( id, f, v);
}

bool QManejadorProductos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
