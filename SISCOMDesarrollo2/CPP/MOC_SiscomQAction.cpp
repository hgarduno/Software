/****************************************************************************
** SiscomQAction meta object code from reading C++ file 'SiscomQAction.h'
**
** Created: Mon Apr 1 17:42:14 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomQAction.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomQAction::className() const
{
    return "SiscomQAction";
}

QMetaObject *SiscomQAction::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomQAction( "SiscomQAction", &SiscomQAction::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomQAction::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomQAction", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomQAction::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomQAction", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomQAction::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QAction::staticMetaObject();
    static const QUMethod slot_0 = {"SlotSelecciono", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciono()", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SiscomQAction", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalSelecciono", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalSelecciono(SiscomQAction*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"SiscomQAction", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomQAction.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomQAction::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomQAction" ) )
	return this;
    return QAction::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalSelecciono
void SiscomQAction::SignalSelecciono( SiscomQAction* t0 )
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

bool SiscomQAction::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciono(); break;
    default:
	return QAction::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SiscomQAction::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalSelecciono((SiscomQAction*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QAction::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool SiscomQAction::qt_property( int id, int f, QVariant* v)
{
    return QAction::qt_property( id, f, v);
}

bool SiscomQAction::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
