/****************************************************************************
** QCtrlPerfiles meta object code from reading C++ file 'QCtrlPerfiles.h'
**
** Created: Sun Feb 9 02:53:52 2020
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlPerfiles.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlPerfiles::className() const
{
    return "QCtrlPerfiles";
}

QMetaObject *QCtrlPerfiles::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlPerfiles( "QCtrlPerfiles", &QCtrlPerfiles::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlPerfiles::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPerfiles", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlPerfiles::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlPerfiles", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlPerfiles::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoPerfil", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoPerfil(QIconViewItem*)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "PerfilSeguridadProt2", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalPerfil", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalPerfil(PerfilSeguridadProt2*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlPerfiles", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlPerfiles.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlPerfiles::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlPerfiles" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalPerfil
void QCtrlPerfiles::SignalPerfil( PerfilSeguridadProt2* t0 )
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

bool QCtrlPerfiles::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoPerfil((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlPerfiles::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalPerfil((PerfilSeguridadProt2*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlPerfiles::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlPerfiles::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES