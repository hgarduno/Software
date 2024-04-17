/****************************************************************************
** QOrdenCompra meta object code from reading C++ file 'IMP_OrdenCompra.h'
**
** Created: Fri Apr 12 21:36:23 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_OrdenCompra.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QOrdenCompra::className() const
{
    return "QOrdenCompra";
}

QMetaObject *QOrdenCompra::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QOrdenCompra( "QOrdenCompra", &QOrdenCompra::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QOrdenCompra::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompra", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QOrdenCompra::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QOrdenCompra", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QOrdenCompra::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = OrdenCompra::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalTerminar", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalTerminar(QWidget*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QOrdenCompra", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QOrdenCompra.setMetaObject( metaObj );
    return metaObj;
}

void* QOrdenCompra::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QOrdenCompra" ) )
	return this;
    return OrdenCompra::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalTerminar
void QOrdenCompra::SignalTerminar( QWidget* t0 )
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

bool QOrdenCompra::qt_invoke( int _id, QUObject* _o )
{
    return OrdenCompra::qt_invoke(_id,_o);
}

bool QOrdenCompra::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return OrdenCompra::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QOrdenCompra::qt_property( int id, int f, QVariant* v)
{
    return OrdenCompra::qt_property( id, f, v);
}

bool QOrdenCompra::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
