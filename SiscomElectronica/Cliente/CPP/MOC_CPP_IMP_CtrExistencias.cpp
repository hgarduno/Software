/****************************************************************************
** QCtrExistencias meta object code from reading C++ file 'IMP_CtrExistencias.h'
**
** Created: Fri Apr 12 21:36:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CtrExistencias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrExistencias::className() const
{
    return "QCtrExistencias";
}

QMetaObject *QCtrExistencias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrExistencias( "QCtrExistencias", &QCtrExistencias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrExistencias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExistencias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrExistencias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExistencias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrExistencias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CtrExistencias::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_NoEstaClave", 1, param_slot_1 };
    static const QUMethod slot_2 = {"S_PorcentajeExistencia", 0, 0 };
    static const QUMethod slot_3 = {"S_ExistenciaMinima", 0, 0 };
    static const QUMethod slot_4 = {"S_ActivarAnexarProductos", 0, 0 };
    static const QUMethod slot_5 = {"S_ExistenciasExpendio", 0, 0 };
    static const QUMethod slot_6 = {"S_ProdsBodega", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoProducto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_NoEstaClave(const char*)", &slot_1, QMetaData::Private },
	{ "S_PorcentajeExistencia()", &slot_2, QMetaData::Private },
	{ "S_ExistenciaMinima()", &slot_3, QMetaData::Private },
	{ "S_ActivarAnexarProductos()", &slot_4, QMetaData::Private },
	{ "S_ExistenciasExpendio()", &slot_5, QMetaData::Private },
	{ "S_ProdsBodega()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrExistencias", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrExistencias.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrExistencias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrExistencias" ) )
	return this;
    return CtrExistencias::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QCtrExistencias::SignalTerminar( QWidget* t0 )
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

bool QCtrExistencias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_NoEstaClave((const char*)static_QUType_charstar.get(_o+1)); break;
    case 2: S_PorcentajeExistencia(); break;
    case 3: S_ExistenciaMinima(); break;
    case 4: S_ActivarAnexarProductos(); break;
    case 5: S_ExistenciasExpendio(); break;
    case 6: S_ProdsBodega(); break;
    default:
	return CtrExistencias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrExistencias::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CtrExistencias::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrExistencias::qt_property( int id, int f, QVariant* v)
{
    return CtrExistencias::qt_property( id, f, v);
}

bool QCtrExistencias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
