/****************************************************************************
** QCtrExistenciasMinimas meta object code from reading C++ file 'IMP_CtrExistenciasMinimas.h'
**
** Created: Fri Apr 12 21:36:04 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CtrExistenciasMinimas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrExistenciasMinimas::className() const
{
    return "QCtrExistenciasMinimas";
}

QMetaObject *QCtrExistenciasMinimas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrExistenciasMinimas( "QCtrExistenciasMinimas", &QCtrExistenciasMinimas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrExistenciasMinimas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExistenciasMinimas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrExistenciasMinimas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrExistenciasMinimas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrExistenciasMinimas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CtrExistenciasMinimas::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoProducto", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_NoEstaClave", 1, param_slot_1 };
    static const QUMethod slot_2 = {"S_AsignarExistenciaALaLista", 0, 0 };
    static const QUMethod slot_3 = {"S_ActualizarExistencias", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoAsignaEMinima", 0, 0 };
    static const QUMethod slot_5 = {"S_PasaFocoActualizaEMinima", 0, 0 };
    static const QUMethod slot_6 = {"S_Eliminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoProducto(ProductoE*)", &slot_0, QMetaData::Private },
	{ "S_NoEstaClave(const char*)", &slot_1, QMetaData::Private },
	{ "S_AsignarExistenciaALaLista()", &slot_2, QMetaData::Private },
	{ "S_ActualizarExistencias()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoAsignaEMinima()", &slot_4, QMetaData::Private },
	{ "S_PasaFocoActualizaEMinima()", &slot_5, QMetaData::Private },
	{ "S_Eliminar()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrExistenciasMinimas", parentObject,
	slot_tbl, 7,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrExistenciasMinimas.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrExistenciasMinimas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrExistenciasMinimas" ) )
	return this;
    return CtrExistenciasMinimas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QCtrExistenciasMinimas::SignalTerminar( QWidget* t0 )
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

bool QCtrExistenciasMinimas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoProducto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 1: S_NoEstaClave((const char*)static_QUType_charstar.get(_o+1)); break;
    case 2: S_AsignarExistenciaALaLista(); break;
    case 3: S_ActualizarExistencias(); break;
    case 4: S_PasaFocoAsignaEMinima(); break;
    case 5: S_PasaFocoActualizaEMinima(); break;
    case 6: S_Eliminar(); break;
    default:
	return CtrExistenciasMinimas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrExistenciasMinimas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CtrExistenciasMinimas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrExistenciasMinimas::qt_property( int id, int f, QVariant* v)
{
    return CtrExistenciasMinimas::qt_property( id, f, v);
}

bool QCtrExistenciasMinimas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
