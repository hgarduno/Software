/****************************************************************************
** QCtrlFechaHora meta object code from reading C++ file 'QCtrlFechaHora.h'
**
** Created: Thu Apr 11 21:36:53 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/QCtrlFechaHora.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCtrlFechaHora::className() const
{
    return "QCtrlFechaHora";
}

QMetaObject *QCtrlFechaHora::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCtrlFechaHora( "QCtrlFechaHora", &QCtrlFechaHora::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCtrlFechaHora::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlFechaHora", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCtrlFechaHora::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCtrlFechaHora", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCtrlFechaHora::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"S_PasaFocoDia", 0, 0 };
    static const QUMethod slot_1 = {"S_PasaFocoMes", 0, 0 };
    static const QUMethod slot_2 = {"S_PasaFocoAno", 0, 0 };
    static const QUMethod slot_3 = {"S_PasaFocoHora", 0, 0 };
    static const QUMethod slot_4 = {"S_PasaFocoMinuto", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"S_CambioElA_o", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"S_CambioElMes", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"S_CambioElDia", 1, param_slot_7 };
    static const QUMethod slot_8 = {"S_EnterMinuto", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "S_PasaFocoDia()", &slot_0, QMetaData::Private },
	{ "S_PasaFocoMes()", &slot_1, QMetaData::Private },
	{ "S_PasaFocoAno()", &slot_2, QMetaData::Private },
	{ "S_PasaFocoHora()", &slot_3, QMetaData::Private },
	{ "S_PasaFocoMinuto()", &slot_4, QMetaData::Private },
	{ "S_CambioElA_o(const QString&)", &slot_5, QMetaData::Private },
	{ "S_CambioElMes(const QString&)", &slot_6, QMetaData::Private },
	{ "S_CambioElDia(const QString&)", &slot_7, QMetaData::Private },
	{ "S_EnterMinuto()", &slot_8, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"Signal_EnterMinuto", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "Signal_EnterMinuto()", &signal_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCtrlFechaHora", parentObject,
	slot_tbl, 9,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCtrlFechaHora.setMetaObject( metaObj );
    return metaObj;
}

void* QCtrlFechaHora::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCtrlFechaHora" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL Signal_EnterMinuto
void QCtrlFechaHora::Signal_EnterMinuto()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QCtrlFechaHora::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: S_PasaFocoDia(); break;
    case 1: S_PasaFocoMes(); break;
    case 2: S_PasaFocoAno(); break;
    case 3: S_PasaFocoHora(); break;
    case 4: S_PasaFocoMinuto(); break;
    case 5: S_CambioElA_o((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: S_CambioElMes((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: S_CambioElDia((const QString&)static_QUType_QString.get(_o+1)); break;
    case 8: S_EnterMinuto(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCtrlFechaHora::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Signal_EnterMinuto(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCtrlFechaHora::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QCtrlFechaHora::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
