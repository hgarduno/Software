/****************************************************************************
** QClientes meta object code from reading C++ file 'IMP_Clientes.h'
**
** Created: Fri Apr 12 21:36:07 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_Clientes.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QClientes::className() const
{
    return "QClientes";
}

QMetaObject *QClientes::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClientes( "QClientes", &QClientes::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClientes::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientes", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClientes::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClientes", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClientes::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Clientes::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoRFC", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoCalle", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoNo", 0, 0 };
    static const QUMethod slot_5 = {"S_PasaFocoCP", 0, 0 };
    static const QUMethod slot_6 = {"S_PasaFocoColonia", 0, 0 };
    static const QUMethod slot_7 = {"S_PasaFocoMunicipio", 0, 0 };
    static const QUMethod slot_8 = {"S_PasaFocoEstado", 0, 0 };
    static const QUMethod slot_9 = {"S_PasaFocoTelefono", 0, 0 };
    static const QUMethod slot_10 = {"S_PasaFocoDescripcion", 0, 0 };
    static const QUMethod slot_11 = {"S_PasaFocoAnexarTelefono", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_12 = {"S_CambioPestana", 1, param_slot_12 };
    static const QUMethod slot_13 = {"S_AnexarDireccion", 0, 0 };
    static const QUMethod slot_14 = {"S_SiguienteDireccion", 0, 0 };
    static const QUMethod slot_15 = {"S_DireccionAnterior", 0, 0 };
    static const QUMethod slot_16 = {"S_ModificarDireccion", 0, 0 };
    static const QUMethod slot_17 = {"S_EliminarDireccion", 0, 0 };
    static const QUMethod slot_18 = {"S_AnexarTelefono", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_19 = {"S_SeleccionaTelefono", 1, param_slot_19 };
    static const QUMethod slot_20 = {"S_EliminaTelefono", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoAPaterno()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAMaterno()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoRFC()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoCalle()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoNo()", &slot_4, QMetaData::Private },
	{ "S_PasaFocoCP()", &slot_5, QMetaData::Private },
	{ "S_PasaFocoColonia()", &slot_6, QMetaData::Private },
	{ "S_PasaFocoMunicipio()", &slot_7, QMetaData::Private },
	{ "S_PasaFocoEstado()", &slot_8, QMetaData::Private },
	{ "S_PasaFocoTelefono()", &slot_9, QMetaData::Private },
	{ "S_PasaFocoDescripcion()", &slot_10, QMetaData::Private },
	{ "S_PasaFocoAnexarTelefono()", &slot_11, QMetaData::Private },
	{ "S_CambioPestana(QWidget*)", &slot_12, QMetaData::Private },
	{ "S_AnexarDireccion()", &slot_13, QMetaData::Private },
	{ "S_SiguienteDireccion()", &slot_14, QMetaData::Private },
	{ "S_DireccionAnterior()", &slot_15, QMetaData::Private },
	{ "S_ModificarDireccion()", &slot_16, QMetaData::Private },
	{ "S_EliminarDireccion()", &slot_17, QMetaData::Private },
	{ "S_AnexarTelefono()", &slot_18, QMetaData::Private },
	{ "S_SeleccionaTelefono(QListViewItem*)", &slot_19, QMetaData::Private },
	{ "S_EliminaTelefono()", &slot_20, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClientes", parentObject,
	slot_tbl, 21,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClientes.setMetaObject( metaObj );
    return metaObj;
}

void* QClientes::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClientes" ) )
	return this;
    return Clientes::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QClientes::SignalTerminar( QWidget* t0 )
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

bool QClientes::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoAPaterno(); break;
    case 1: S_PasaFocoAMaterno(); break;
    case 2: S_PasaFocoRFC(); break;
    case 3: S_PasaFocoCalle(); break;
    case 4: S_PasaFocoNo(); break;
    case 5: S_PasaFocoCP(); break;
    case 6: S_PasaFocoColonia(); break;
    case 7: S_PasaFocoMunicipio(); break;
    case 8: S_PasaFocoEstado(); break;
    case 9: S_PasaFocoTelefono(); break;
    case 10: S_PasaFocoDescripcion(); break;
    case 11: S_PasaFocoAnexarTelefono(); break;
    case 12: S_CambioPestana((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 13: S_AnexarDireccion(); break;
    case 14: S_SiguienteDireccion(); break;
    case 15: S_DireccionAnterior(); break;
    case 16: S_ModificarDireccion(); break;
    case 17: S_EliminarDireccion(); break;
    case 18: S_AnexarTelefono(); break;
    case 19: S_SeleccionaTelefono((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 20: S_EliminaTelefono(); break;
    default:
	return Clientes::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClientes::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return Clientes::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QClientes::qt_property( int id, int f, QVariant* v)
{
    return Clientes::qt_property( id, f, v);
}

bool QClientes::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
