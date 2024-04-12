/****************************************************************************
** QMaterialBodegaExpendio meta object code from reading C++ file 'IMP_MaterialBodegaExpendio.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_MaterialBodegaExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QMaterialBodegaExpendio::className() const
{
    return "QMaterialBodegaExpendio";
}

QMetaObject *QMaterialBodegaExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMaterialBodegaExpendio( "QMaterialBodegaExpendio", &QMaterialBodegaExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMaterialBodegaExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialBodegaExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMaterialBodegaExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialBodegaExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMaterialBodegaExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MaterialBodegaExpendio::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotExpendio", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotBodega", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionando", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotSelecciono", 1, param_slot_3 };
    static const QUMethod slot_4 = {"SlotPasaFocoAnexar", 0, 0 };
    static const QUMethod slot_5 = {"SlotAnexar", 0, 0 };
    static const QUMethod slot_6 = {"SlotRegistra", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "pintNFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintNColumn", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotSeleccionaProducto", 4, param_slot_7 };
    static const QUMethod slot_8 = {"SlotEliminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotExpendio(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotBodega(SiscomRegistro3*)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionando(SiscomRegistro3*)", &slot_2, QMetaData::Private },
	{ "SlotSelecciono(SiscomRegistro3*)", &slot_3, QMetaData::Private },
	{ "SlotPasaFocoAnexar()", &slot_4, QMetaData::Private },
	{ "SlotAnexar()", &slot_5, QMetaData::Private },
	{ "SlotRegistra()", &slot_6, QMetaData::Private },
	{ "SlotSeleccionaProducto(int,int,int,const QPoint&)", &slot_7, QMetaData::Private },
	{ "SlotEliminar()", &slot_8, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QMaterialBodegaExpendio", parentObject,
	slot_tbl, 9,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMaterialBodegaExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QMaterialBodegaExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMaterialBodegaExpendio" ) )
	return this;
    return MaterialBodegaExpendio::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QMaterialBodegaExpendio::SignalTerminar( QWidget* t0 )
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

bool QMaterialBodegaExpendio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotExpendio((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotBodega((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotSeleccionando((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotSelecciono((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotPasaFocoAnexar(); break;
    case 5: SlotAnexar(); break;
    case 6: SlotRegistra(); break;
    case 7: SlotSeleccionaProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 8: SlotEliminar(); break;
    default:
	return MaterialBodegaExpendio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMaterialBodegaExpendio::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return MaterialBodegaExpendio::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QMaterialBodegaExpendio::qt_property( int id, int f, QVariant* v)
{
    return MaterialBodegaExpendio::qt_property( id, f, v);
}

bool QMaterialBodegaExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
