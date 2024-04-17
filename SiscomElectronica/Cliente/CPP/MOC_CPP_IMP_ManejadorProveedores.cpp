/****************************************************************************
** QManejadorProveedores meta object code from reading C++ file 'IMP_ManejadorProveedores.h'
**
** Created: Fri Apr 12 21:35:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ManejadorProveedores.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QManejadorProveedores::className() const
{
    return "QManejadorProveedores";
}

QMetaObject *QManejadorProveedores::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QManejadorProveedores( "QManejadorProveedores", &QManejadorProveedores::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QManejadorProveedores::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProveedores", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QManejadorProveedores::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QManejadorProveedores", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QManejadorProveedores::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ManejadorProveedores::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoRFC", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoCalle", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoNumero", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoCP", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoColonia", 0, 0 };
    static const QUMethod slot_5 = {"S_PasaFocoMunicipio", 0, 0 };
    static const QUMethod slot_6 = {"S_PasaFocoEstado", 0, 0 };
    static const QUMethod slot_7 = {"S_PasaFocoAnexarDireccion", 0, 0 };
    static const QUMethod slot_8 = {"S_AnexarDireccion", 0, 0 };
    static const QUMethod slot_9 = {"S_AnexarTelefono", 0, 0 };
    static const QUMethod slot_10 = {"S_AnexarContacto", 0, 0 };
    static const QUMethod slot_11 = {"S_RegistrarProveedor", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoRFC()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoCalle()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoNumero()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoCP()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoColonia()", &slot_4, QMetaData::Private },
	{ "S_PasaFocoMunicipio()", &slot_5, QMetaData::Private },
	{ "S_PasaFocoEstado()", &slot_6, QMetaData::Private },
	{ "S_PasaFocoAnexarDireccion()", &slot_7, QMetaData::Private },
	{ "S_AnexarDireccion()", &slot_8, QMetaData::Private },
	{ "S_AnexarTelefono()", &slot_9, QMetaData::Private },
	{ "S_AnexarContacto()", &slot_10, QMetaData::Private },
	{ "S_RegistrarProveedor()", &slot_11, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QManejadorProveedores", parentObject,
	slot_tbl, 12,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QManejadorProveedores.setMetaObject( metaObj );
    return metaObj;
}

void* QManejadorProveedores::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QManejadorProveedores" ) )
	return this;
    return ManejadorProveedores::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QManejadorProveedores::SignalTerminar( QWidget* t0 )
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

bool QManejadorProveedores::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoRFC(); break;
    case 1: S_PasaFocoCalle(); break;
    case 2: S_PasaFocoNumero(); break;
    case 3: S_PasaFocoCP(); break;
    case 4: S_PasaFocoColonia(); break;
    case 5: S_PasaFocoMunicipio(); break;
    case 6: S_PasaFocoEstado(); break;
    case 7: S_PasaFocoAnexarDireccion(); break;
    case 8: S_AnexarDireccion(); break;
    case 9: S_AnexarTelefono(); break;
    case 10: S_AnexarContacto(); break;
    case 11: S_RegistrarProveedor(); break;
    default:
	return ManejadorProveedores::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QManejadorProveedores::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ManejadorProveedores::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QManejadorProveedores::qt_property( int id, int f, QVariant* v)
{
    return ManejadorProveedores::qt_property( id, f, v);
}

bool QManejadorProveedores::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
