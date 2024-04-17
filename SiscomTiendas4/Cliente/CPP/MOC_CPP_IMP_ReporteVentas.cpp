/****************************************************************************
** QReporteVentas meta object code from reading C++ file 'IMP_ReporteVentas.h'
**
** Created: Fri Apr 12 21:36:43 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ReporteVentas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QReporteVentas::className() const
{
    return "QReporteVentas";
}

QMetaObject *QReporteVentas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QReporteVentas( "QReporteVentas", &QReporteVentas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QReporteVentas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QReporteVentas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QReporteVentas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QReporteVentas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ReporteVentas::staticMetaObject();
    static const QUMethod slot_0 = {"SlotEjecuta", 0, 0 };
    static const QUMethod slot_1 = {"SlotPasaFocoFechaFin", 0, 0 };
    static const QUMethod slot_2 = {"SlotPasaFocoEjecuta", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotEjecuta()", &slot_0, QMetaData::Private },
	{ "SlotPasaFocoFechaFin()", &slot_1, QMetaData::Private },
	{ "SlotPasaFocoEjecuta()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QReporteVentas", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QReporteVentas.setMetaObject( metaObj );
    return metaObj;
}

void* QReporteVentas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QReporteVentas" ) )
	return this;
    return ReporteVentas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QReporteVentas::SignalTerminar( QWidget* t0 )
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

bool QReporteVentas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotEjecuta(); break;
    case 1: SlotPasaFocoFechaFin(); break;
    case 2: SlotPasaFocoEjecuta(); break;
    default:
	return ReporteVentas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QReporteVentas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ReporteVentas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QReporteVentas::qt_property( int id, int f, QVariant* v)
{
    return ReporteVentas::qt_property( id, f, v);
}

bool QReporteVentas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
