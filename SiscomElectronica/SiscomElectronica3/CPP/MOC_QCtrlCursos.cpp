/****************************************************************************
** QCtrlCursos meta object code from reading C++ file 'QCtrlCursos.h'
**
** Created: Thu Apr 11 21:37:54 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlCursos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlCursos::className() const
{
    return "QCtrlCursos";
}

QMetaObject *QCtrlCursos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlCursos( "QCtrlCursos", &QCtrlCursos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlCursos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCursos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlCursos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlCursos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlCursos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCurso", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCurso(int)", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod signal_0 = {"SignalCurso", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "SignalCurso(SiscomRegistro3*)", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlCursos", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlCursos.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlCursos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlCursos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL SignalCurso
void QCtrlCursos::SignalCurso( SiscomRegistro3* t0 )
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

bool QCtrlCursos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCurso((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlCursos::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: SignalCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlCursos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlCursos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
