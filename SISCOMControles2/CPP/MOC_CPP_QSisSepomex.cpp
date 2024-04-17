/****************************************************************************
** QSisSepomex meta object code from reading C++ file 'QSisSepomex.h'
**
** Created: Fri Apr 12 21:24:23 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QSisSepomex.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QSisSepomex::className() const
{
    return "QSisSepomex";
}

QMetaObject *QSisSepomex::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSisSepomex( "QSisSepomex", &QSisSepomex::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSisSepomex::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisSepomex", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSisSepomex::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSisSepomex", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSisSepomex::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"S_SeleccionoEstado", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoEstados", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoNumero", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoTipoAsentamientos", 0, 0 };
    static const QUMethod slot_4 = {"S_SeleccionoTipoAsentamiento", 0, 0 };
    static const QUMethod slot_5 = {"S_SeleccionoAsentamiento", 0, 0 };
    static const QUMethod slot_6 = {"S_SeleccionoCP", 0, 0 };
    static const QUMethod slot_7 = {"S_SeleccionoMunicipio", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"S_SeleccionoEstado", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"S_SeleccionoMunicipio", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"S_SeleccionoAsentamiento", 1, param_slot_10 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoEstado()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoEstados()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoNumero()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoTipoAsentamientos()", &slot_3, QMetaData::Private },
	{ "S_SeleccionoTipoAsentamiento()", &slot_4, QMetaData::Private },
	{ "S_SeleccionoAsentamiento()", &slot_5, QMetaData::Private },
	{ "S_SeleccionoCP()", &slot_6, QMetaData::Private },
	{ "S_SeleccionoMunicipio()", &slot_7, QMetaData::Private },
	{ "S_SeleccionoEstado(int)", &slot_8, QMetaData::Private },
	{ "S_SeleccionoMunicipio(int)", &slot_9, QMetaData::Private },
	{ "S_SeleccionoAsentamiento(int)", &slot_10, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SisDireccion", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalDireccion", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod signal_1 = {"SignalDireccion", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "SignalDireccion(SisDireccion*)", &signal_0, QMetaData::Private },
	{ "SignalDireccion(SiscomRegistro3*)", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSisSepomex", parentObject,
	slot_tbl, 11,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSisSepomex.setMetaObject( metaObj );
    return metaObj;
}

void* QSisSepomex::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSisSepomex" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalDireccion
void QSisSepomex::SignalDireccion( SisDireccion* t0 )
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

// SIGNAL SignalDireccion
void QSisSepomex::SignalDireccion( SiscomRegistro3* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QSisSepomex::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoEstado(); break;
    case 1: S_PasaFocoEstados(); break;
    case 2: S_PasaFocoNumero(); break;
    case 3: S_PasaFocoTipoAsentamientos(); break;
    case 4: S_SeleccionoTipoAsentamiento(); break;
    case 5: S_SeleccionoAsentamiento(); break;
    case 6: S_SeleccionoCP(); break;
    case 7: S_SeleccionoMunicipio(); break;
    case 8: S_SeleccionoEstado((int)static_QUType_int.get(_o+1)); break;
    case 9: S_SeleccionoMunicipio((int)static_QUType_int.get(_o+1)); break;
    case 10: S_SeleccionoAsentamiento((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSisSepomex::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalDireccion((SisDireccion*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalDireccion((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSisSepomex::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSisSepomex::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
