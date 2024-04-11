/****************************************************************************
** QHistorialTransferencias meta object code from reading C++ file 'IMP_HistorialTransferencias.h'
**
** Created: Wed Apr 10 20:52:39 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_HistorialTransferencias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QHistorialTransferencias::className() const
{
    return "QHistorialTransferencias";
}

QMetaObject *QHistorialTransferencias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHistorialTransferencias( "QHistorialTransferencias", &QHistorialTransferencias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHistorialTransferencias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHistorialTransferencias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHistorialTransferencias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHistorialTransferencias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHistorialTransferencias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = HistorialTransferencias::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoFechaFin", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoEjecuta", 0, 0 };
    static const QUMethod slot_2 = {"S_Consulta", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_3 = {"S_SeleccionaTransferencia", 4, param_slot_3 };
    static const QUMethod slot_4 = {"S_ReEnviaTransferencia", 0, 0 };
    static const QUMethod slot_5 = {"S_SeleccionaExpendio", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoFechaFin()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoEjecuta()", &slot_1, QMetaData::Private },
	{ "S_Consulta()", &slot_2, QMetaData::Private },
	{ "S_SeleccionaTransferencia(int,int,int,const QPoint&)", &slot_3, QMetaData::Private },
	{ "S_ReEnviaTransferencia()", &slot_4, QMetaData::Private },
	{ "S_SeleccionaExpendio()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QHistorialTransferencias", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHistorialTransferencias.setMetaObject( metaObj );
    return metaObj;
}

void* QHistorialTransferencias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHistorialTransferencias" ) )
	return this;
    return HistorialTransferencias::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QHistorialTransferencias::SignalTerminar( QWidget* t0 )
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

bool QHistorialTransferencias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoFechaFin(); break;
    case 1: S_PasaFocoEjecuta(); break;
    case 2: S_Consulta(); break;
    case 3: S_SeleccionaTransferencia((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: S_ReEnviaTransferencia(); break;
    case 5: S_SeleccionaExpendio(); break;
    default:
	return HistorialTransferencias::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QHistorialTransferencias::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return HistorialTransferencias::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QHistorialTransferencias::qt_property( int id, int f, QVariant* v)
{
    return HistorialTransferencias::qt_property( id, f, v);
}

bool QHistorialTransferencias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
