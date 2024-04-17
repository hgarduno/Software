/****************************************************************************
** QMaterialAExpendio meta object code from reading C++ file 'IMP_MaterialAExpendio.h'
**
** Created: Fri Apr 12 21:35:52 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_MaterialAExpendio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QMaterialAExpendio::className() const
{
    return "QMaterialAExpendio";
}

QMetaObject *QMaterialAExpendio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMaterialAExpendio( "QMaterialAExpendio", &QMaterialAExpendio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMaterialAExpendio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialAExpendio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMaterialAExpendio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMaterialAExpendio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMaterialAExpendio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MaterialAExpendio::staticMetaObject();
    static const QUMethod slot_0 = {"S_SeleccionaExpendio", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "ProductoE", QUParameter::In }
    };
    static const QUMethod slot_1 = {"S_Producto", 1, param_slot_1 };
    static const QUMethod slot_2 = {"S_PasaFocoAnexar", 0, 0 };
    static const QUMethod slot_3 = {"S_Anexar", 0, 0 };
    static const QUMethod slot_4 = {"S_RegistraEnvio", 0, 0 };
    static const QUMethod slot_5 = {"S_Eliminar", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_Producto", 4, param_slot_6 };
    static const QUMethod slot_7 = {"S_CambiaCantidad", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionaExpendio()", &slot_0, QMetaData::Private },
	{ "S_Producto(ProductoE*)", &slot_1, QMetaData::Private },
	{ "S_PasaFocoAnexar()", &slot_2, QMetaData::Private },
	{ "S_Anexar()", &slot_3, QMetaData::Private },
	{ "S_RegistraEnvio()", &slot_4, QMetaData::Private },
	{ "S_Eliminar()", &slot_5, QMetaData::Private },
	{ "S_Producto(int,int,int,const QPoint&)", &slot_6, QMetaData::Private },
	{ "S_CambiaCantidad()", &slot_7, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QMaterialAExpendio", parentObject,
	slot_tbl, 8,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMaterialAExpendio.setMetaObject( metaObj );
    return metaObj;
}

void* QMaterialAExpendio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMaterialAExpendio" ) )
	return this;
    return MaterialAExpendio::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QMaterialAExpendio::SignalTerminar( QWidget* t0 )
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

bool QMaterialAExpendio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionaExpendio(); break;
    case 1: S_Producto((ProductoE*)static_QUType_ptr.get(_o+1)); break;
    case 2: S_PasaFocoAnexar(); break;
    case 3: S_Anexar(); break;
    case 4: S_RegistraEnvio(); break;
    case 5: S_Eliminar(); break;
    case 6: S_Producto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 7: S_CambiaCantidad(); break;
    default:
	return MaterialAExpendio::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMaterialAExpendio::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return MaterialAExpendio::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QMaterialAExpendio::qt_property( int id, int f, QVariant* v)
{
    return MaterialAExpendio::qt_property( id, f, v);
}

bool QMaterialAExpendio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
