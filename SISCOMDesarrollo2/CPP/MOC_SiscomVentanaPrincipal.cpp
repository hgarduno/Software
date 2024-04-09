/****************************************************************************
** SiscomVentanaPrincipal meta object code from reading C++ file 'SiscomVentanaPrincipal.h'
**
** Created: Mon Apr 1 17:42:13 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/SiscomVentanaPrincipal.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SiscomVentanaPrincipal::className() const
{
    return "SiscomVentanaPrincipal";
}

QMetaObject *SiscomVentanaPrincipal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SiscomVentanaPrincipal( "SiscomVentanaPrincipal", &SiscomVentanaPrincipal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SiscomVentanaPrincipal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomVentanaPrincipal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SiscomVentanaPrincipal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SiscomVentanaPrincipal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SiscomVentanaPrincipal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pSisQAOpcion", &static_QUType_ptr, "SiscomQAction", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotSelecciono", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pQWVentana", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotTerminar", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaVentana", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotActualizaMenu", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "SlotSelecciono(SiscomQAction*)", &slot_0, QMetaData::Private },
	{ "SlotTerminar(QWidget*)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaVentana(int)", &slot_2, QMetaData::Private },
	{ "SlotActualizaMenu(const QString&)", &slot_3, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"SiscomVentanaPrincipal", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SiscomVentanaPrincipal.setMetaObject( metaObj );
    return metaObj;
}

void* SiscomVentanaPrincipal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SiscomVentanaPrincipal" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool SiscomVentanaPrincipal::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotSelecciono((SiscomQAction*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotTerminar((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 2: SlotSeleccionaVentana((int)static_QUType_int.get(_o+1)); break;
    case 3: SlotActualizaMenu((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SiscomVentanaPrincipal::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SiscomVentanaPrincipal::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool SiscomVentanaPrincipal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
