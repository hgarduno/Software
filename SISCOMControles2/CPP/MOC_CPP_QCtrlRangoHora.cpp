/****************************************************************************
** QCtrlRangoHora meta object code from reading C++ file 'QCtrlRangoHora.h'
**
** Created: Fri Apr 12 21:24:20 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlRangoHora.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlRangoHora::className() const
{
    return "QCtrlRangoHora";
}

QMetaObject *QCtrlRangoHora::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlRangoHora( "QCtrlRangoHora", &QCtrlRangoHora::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlRangoHora::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlRangoHora", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlRangoHora::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlRangoHora", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlRangoHora::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoMinuto", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoHoraFin", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoMinutoFin", 0, 0 };
    static const QUMethod slot_3 = {"S_CapturoRangoHora", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoMinuto()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoHoraFin()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoMinutoFin()", &slot_2, QMetaData::Private },
	{ "S_CapturoRangoHora()", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "pchrPtrHoraInicio", &static_QUType_charstar, 0, QUParameter::In },
	{ "pchrPtrHoraFin", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalCapturoRangoHora", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCapturoRangoHora(char*,char*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlRangoHora", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlRangoHora.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlRangoHora::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlRangoHora" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalCapturoRangoHora
void QCtrlRangoHora::SignalCapturoRangoHora( char* t0, char* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_charstar.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    activate_signal( clist, o );
}

bool QCtrlRangoHora::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoMinuto(); break;
    case 1: S_PasaFocoHoraFin(); break;
    case 2: S_PasaFocoMinutoFin(); break;
    case 3: S_CapturoRangoHora(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlRangoHora::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCapturoRangoHora((char*)static_QUType_charstar.get(_o+1),(char*)static_QUType_charstar.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlRangoHora::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlRangoHora::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
