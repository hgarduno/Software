/****************************************************************************
** QCtrlMedComunicacion meta object code from reading C++ file 'QCtrlMedComunicacion.h'
**
** Created: Fri Apr 12 21:36:28 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlMedComunicacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlMedComunicacion::className() const
{
    return "QCtrlMedComunicacion";
}

QMetaObject *QCtrlMedComunicacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlMedComunicacion( "QCtrlMedComunicacion", &QCtrlMedComunicacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlMedComunicacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlMedComunicacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlMedComunicacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlMedComunicacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlMedComunicacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"S_SeleccionoMedComunicacion", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "S_SeleccionoMedComunicacion(QIconViewItem*)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SisMedCom", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalMedComunicacion", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalMedComunicacion(SisMedCom*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlMedComunicacion", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlMedComunicacion.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlMedComunicacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlMedComunicacion" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalMedComunicacion
void QCtrlMedComunicacion::SignalMedComunicacion( SisMedCom* t0 )
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

bool QCtrlMedComunicacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_SeleccionoMedComunicacion((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlMedComunicacion::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalMedComunicacion((SisMedCom*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlMedComunicacion::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlMedComunicacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
