/****************************************************************************
** QRegistroEmpleados meta object code from reading C++ file 'IMP_RegistroEmpleados.h'
**
** Created: Wed Apr 10 21:12:03 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroEmpleados.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroEmpleados::className() const
{
    return "QRegistroEmpleados";
}

QMetaObject *QRegistroEmpleados::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroEmpleados( "QRegistroEmpleados", &QRegistroEmpleados::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroEmpleados::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpleados", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroEmpleados::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroEmpleados", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroEmpleados::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroEmpleados::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoNombre", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoAPaterno", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoAMaterno", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoCalle", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoNumero", 0, 0 };
    static const QUMethod slot_5 = {"S_PasaFocoCP", 0, 0 };
    static const QUMethod slot_6 = {"S_PasaFocoColonia", 0, 0 };
    static const QUMethod slot_7 = {"S_PasaFocoMunicipio", 0, 0 };
    static const QUMethod slot_8 = {"S_PasaFocoEstado", 0, 0 };
    static const QUMethod slot_9 = {"S_PasaFocoAnexarTelefono", 0, 0 };
    static const QUMethod slot_10 = {"S_AnexarTelefono", 0, 0 };
    static const QUMethod slot_11 = {"S_RegistraEmpleado", 0, 0 };
    static const QUMethod slot_12 = {"S_Expendio", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoNombre()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoAPaterno()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoAMaterno()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoCalle()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoNumero()", &slot_4, QMetaData::Private },
	{ "S_PasaFocoCP()", &slot_5, QMetaData::Private },
	{ "S_PasaFocoColonia()", &slot_6, QMetaData::Private },
	{ "S_PasaFocoMunicipio()", &slot_7, QMetaData::Private },
	{ "S_PasaFocoEstado()", &slot_8, QMetaData::Private },
	{ "S_PasaFocoAnexarTelefono()", &slot_9, QMetaData::Private },
	{ "S_AnexarTelefono()", &slot_10, QMetaData::Private },
	{ "S_RegistraEmpleado()", &slot_11, QMetaData::Private },
	{ "S_Expendio()", &slot_12, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroEmpleados", parentObject,
	slot_tbl, 13,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroEmpleados.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroEmpleados::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroEmpleados" ) )
	return this;
    return RegistroEmpleados::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QRegistroEmpleados::SignalTerminar( QWidget* t0 )
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

bool QRegistroEmpleados::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoNombre(); break;
    case 1: S_PasaFocoAPaterno(); break;
    case 2: S_PasaFocoAMaterno(); break;
    case 3: S_PasaFocoCalle(); break;
    case 4: S_PasaFocoNumero(); break;
    case 5: S_PasaFocoCP(); break;
    case 6: S_PasaFocoColonia(); break;
    case 7: S_PasaFocoMunicipio(); break;
    case 8: S_PasaFocoEstado(); break;
    case 9: S_PasaFocoAnexarTelefono(); break;
    case 10: S_AnexarTelefono(); break;
    case 11: S_RegistraEmpleado(); break;
    case 12: S_Expendio(); break;
    default:
	return RegistroEmpleados::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroEmpleados::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return RegistroEmpleados::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QRegistroEmpleados::qt_property( int id, int f, QVariant* v)
{
    return RegistroEmpleados::qt_property( id, f, v);
}

bool QRegistroEmpleados::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
