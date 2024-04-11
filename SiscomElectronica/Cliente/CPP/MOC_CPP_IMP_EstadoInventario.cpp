/****************************************************************************
** QEstadoInventario meta object code from reading C++ file 'IMP_EstadoInventario.h'
**
** Created: Wed Apr 10 21:12:27 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_EstadoInventario.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QEstadoInventario::className() const
{
    return "QEstadoInventario";
}

QMetaObject *QEstadoInventario::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QEstadoInventario( "QEstadoInventario", &QEstadoInventario::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QEstadoInventario::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEstadoInventario", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QEstadoInventario::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEstadoInventario", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QEstadoInventario::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EstadoInventario::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QEstadoInventario", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QEstadoInventario.setMetaObject( metaObj );
    return metaObj;
}

void* QEstadoInventario::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QEstadoInventario" ) )
	return this;
    return EstadoInventario::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QEstadoInventario::SignalTerminar( QWidget* t0 )
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

bool QEstadoInventario::qt_invoke( int _id, QUObject* _o )
{
    return EstadoInventario::qt_invoke(_id,_o);
}

bool QEstadoInventario::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return EstadoInventario::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QEstadoInventario::qt_property( int id, int f, QVariant* v)
{
    return EstadoInventario::qt_property( id, f, v);
}

bool QEstadoInventario::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
