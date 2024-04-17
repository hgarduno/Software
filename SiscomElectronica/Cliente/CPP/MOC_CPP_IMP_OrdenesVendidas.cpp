/****************************************************************************
** QOrdenesVendidas meta object code from reading C++ file 'IMP_OrdenesVendidas.h'
**
** Created: Fri Apr 12 21:36:20 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenesVendidas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenesVendidas::className() const
{
    return "QOrdenesVendidas";
}

QMetaObject *QOrdenesVendidas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenesVendidas( "QOrdenesVendidas", &QOrdenesVendidas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenesVendidas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesVendidas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenesVendidas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenesVendidas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenesVendidas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenesVendidas::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoAnexarOrden", 0, 0 };
    static const QUMethod slot_1 = {"S_AnexarOrden", 0, 0 };
    static const QUMethod slot_2 = {"S_NuevaOrden", 0, 0 };
    static const QUMethod slot_3 = {"S_OrdenesPorFecha", 0, 0 };
    static const QUMethod slot_4 = {"S_Facturacion", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoAnexarOrden()", &slot_0, QMetaData::Private },
	{ "S_AnexarOrden()", &slot_1, QMetaData::Private },
	{ "S_NuevaOrden()", &slot_2, QMetaData::Private },
	{ "S_OrdenesPorFecha()", &slot_3, QMetaData::Private },
	{ "S_Facturacion()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenesVendidas", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenesVendidas.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenesVendidas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenesVendidas" ) )
	return this;
    return OrdenesVendidas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QOrdenesVendidas::SignalTerminar( QWidget* t0 )
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

bool QOrdenesVendidas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoAnexarOrden(); break;
    case 1: S_AnexarOrden(); break;
    case 2: S_NuevaOrden(); break;
    case 3: S_OrdenesPorFecha(); break;
    case 4: S_Facturacion(); break;
    default:
	return OrdenesVendidas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QOrdenesVendidas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return OrdenesVendidas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QOrdenesVendidas::qt_property( int id, int f, QVariant* v)
{
    return OrdenesVendidas::qt_property( id, f, v);
}

bool QOrdenesVendidas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
