/****************************************************************************
** QCtrlUsuarios meta object code from reading C++ file 'QCtrlUsuarios.h'
**
** Created: Sun Feb 9 02:53:55 2020
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlUsuarios.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlUsuarios::className() const
{
    return "QCtrlUsuarios";
}

QMetaObject *QCtrlUsuarios::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlUsuarios( "QCtrlUsuarios", &QCtrlUsuarios::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlUsuarios::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlUsuarios", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlUsuarios::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlUsuarios", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlUsuarios::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoUsuario", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoUsuario(QIconViewItem*)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SisUsuarioSeg3", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalUsuario", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalUsuario(SisUsuarioSeg3*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlUsuarios", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlUsuarios.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlUsuarios::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlUsuarios" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalUsuario
void QCtrlUsuarios::SignalUsuario( SisUsuarioSeg3* t0 )
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

bool QCtrlUsuarios::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoUsuario((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlUsuarios::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalUsuario((SisUsuarioSeg3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlUsuarios::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlUsuarios::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES