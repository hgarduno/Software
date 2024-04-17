/****************************************************************************
** QCtrlFamilias meta object code from reading C++ file 'QCtrlFamilias.h'
**
** Created: Fri Apr 12 21:36:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlFamilias.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlFamilias::className() const
{
    return "QCtrlFamilias";
}

QMetaObject *QCtrlFamilias::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlFamilias( "QCtrlFamilias", &QCtrlFamilias::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlFamilias::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlFamilias", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlFamilias::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlFamilias", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlFamilias::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotFamilia", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotCambiandoFamilia", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "SlotFamilia(int)", &slot_0, QMetaData::Private },
	{ "SlotCambiandoFamilia(const QString&)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "CQSisFamilia", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalFamilia", 1, param_signal_0 };
    static const QUMethod signal_1 = {"SignalCambiandoFamilia", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalFamilia(CQSisFamilia*)", &signal_0, QMetaData::Private },
	{ "SignalCambiandoFamilia()", &signal_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlFamilias", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlFamilias.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlFamilias::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlFamilias" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalFamilia
void QCtrlFamilias::SignalFamilia( CQSisFamilia* t0 )
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

// SIGNAL SignalCambiandoFamilia
void QCtrlFamilias::SignalCambiandoFamilia()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QCtrlFamilias::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotFamilia((int)static_QUType_int.get(_o+1)); break;
    case 1: SlotCambiandoFamilia((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlFamilias::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalFamilia((CQSisFamilia*)static_QUType_ptr.get(_o+1)); break;
    case 1: SignalCambiandoFamilia(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlFamilias::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlFamilias::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
