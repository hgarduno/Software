/****************************************************************************
** QContPracticas meta object code from reading C++ file 'IMP_ContPracticas.h'
**
** Created: Fri Apr 12 21:35:27 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ContPracticas.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QContPracticas::className() const
{
    return "QContPracticas";
}

QMetaObject *QContPracticas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QContPracticas( "QContPracticas", &QContPracticas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QContPracticas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContPracticas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QContPracticas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QContPracticas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QContPracticas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ContPracticas::staticMetaObject();
    static const QUMethod slot_0 = {"S_ContEscuelas", 0, 0 };
    static const QUMethod slot_1 = {"S_ContMaterias", 0, 0 };
    static const QUMethod slot_2 = {"S_SelLasPracticas", 0, 0 };
    static const QUMethod slot_3 = {"S_MaterialPracticas", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_ContEscuelas()", &slot_0, QMetaData::Private },
	{ "S_ContMaterias()", &slot_1, QMetaData::Private },
	{ "S_SelLasPracticas()", &slot_2, QMetaData::Private },
	{ "S_MaterialPracticas()", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QContPracticas", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QContPracticas.setMetaObject( metaObj );
    return metaObj;
}

void* QContPracticas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QContPracticas" ) )
	return this;
    return ContPracticas::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QContPracticas::SignalTerminar( QWidget* t0 )
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

bool QContPracticas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_ContEscuelas(); break;
    case 1: S_ContMaterias(); break;
    case 2: S_SelLasPracticas(); break;
    case 3: S_MaterialPracticas(); break;
    default:
	return ContPracticas::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QContPracticas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return ContPracticas::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QContPracticas::qt_property( int id, int f, QVariant* v)
{
    return ContPracticas::qt_property( id, f, v);
}

bool QContPracticas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
