/****************************************************************************
** QCierraApartado meta object code from reading C++ file 'IMP_CierraApartado.h'
**
** Created: Wed Apr 10 20:52:40 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CierraApartado.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCierraApartado::className() const
{
    return "QCierraApartado";
}

QMetaObject *QCierraApartado::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCierraApartado( "QCierraApartado", &QCierraApartado::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCierraApartado::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierraApartado", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCierraApartado::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCierraApartado", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCierraApartado::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CierraApartado::staticMetaObject();
    static const QUMethod slot_0 = {"SlotConsulta", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaApartado", 4, param_slot_1 };
    static const QUMethod slot_2 = {"SlotPagar", 0, 0 };
    static const QUMethod slot_3 = {"SlotCancelar", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAFechaFin", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAConsulta", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_6 = {"closeEvent", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "SlotConsulta()", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaApartado(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotPagar()", &slot_2, QMetaData::Private },
	{ "SlotCancelar()", &slot_3, QMetaData::Private },
	{ "SlotFocoAFechaFin()", &slot_4, QMetaData::Private },
	{ "SlotFocoAConsulta()", &slot_5, QMetaData::Private },
	{ "closeEvent(QCloseEvent*)", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalPagar", 1, param_signal_0 };
    static const QUMethod signal_1 = {"SignalCancelar", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalPagar(zSiscomRegistro*)", &signal_0, QMetaData::Private },
	{ "SignalCancelar()", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCierraApartado", parentObject,
	slot_tbl, 7,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCierraApartado.setMetaObject( metaObj );
    return metaObj;
}

void* QCierraApartado::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCierraApartado" ) )
	return this;
    return CierraApartado::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalPagar
void QCierraApartado::SignalPagar( zSiscomRegistro* t0 )
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

// SIGNAL SignalCancelar
void QCierraApartado::SignalCancelar()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QCierraApartado::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotConsulta(); break;
    case 1: SlotSeleccionaApartado((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotPagar(); break;
    case 3: SlotCancelar(); break;
    case 4: SlotFocoAFechaFin(); break;
    case 5: SlotFocoAConsulta(); break;
    case 6: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CierraApartado::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCierraApartado::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalPagar((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalCancelar(); break;
    default:
	return CierraApartado::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCierraApartado::qt_property( int id, int f, QVariant* v)
{
    return CierraApartado::qt_property( id, f, v);
}

bool QCierraApartado::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
