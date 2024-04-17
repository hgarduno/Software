/****************************************************************************
** QCotizaImportacion meta object code from reading C++ file 'IMP_CotizaImportacion.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_CotizaImportacion.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QCotizaImportacion::className() const
{
    return "QCotizaImportacion";
}

QMetaObject *QCotizaImportacion::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCotizaImportacion( "QCotizaImportacion", &QCotizaImportacion::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCotizaImportacion::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaImportacion", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCotizaImportacion::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCotizaImportacion", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCotizaImportacion::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CotizaImportacion::staticMetaObject();
    static const QUMethod slot_0 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_1 = {"SlotFocoAProveedor", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotProveedor", 1, param_slot_2 };
    static const QUMethod slot_3 = {"SlotConsulta", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "zSiscomRegistro", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotProducto", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"SlotCapturandoCantidad", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"SlotCapturandoPrecio", 1, param_slot_6 };
    static const QUMethod slot_7 = {"SlotFocoAPrecio", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoAAnexar", 0, 0 };
    static const QUMethod slot_9 = {"SlotAnexar", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_10 = {"SlotSeleccionoProducto", 4, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_11 = {"SlotSeleccionandoProducto", 4, param_slot_11 };
    static const QUMethod slot_12 = {"SlotCambioLaSeleccion", 0, 0 };
    static const QUMethod slot_13 = {"SlotEliminar", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotRegistra()", &slot_0, QMetaData::Private },
	{ "SlotFocoAProveedor()", &slot_1, QMetaData::Private },
	{ "SlotProveedor(zSiscomRegistro*)", &slot_2, QMetaData::Private },
	{ "SlotConsulta()", &slot_3, QMetaData::Private },
	{ "SlotProducto(zSiscomRegistro*)", &slot_4, QMetaData::Private },
	{ "SlotCapturandoCantidad(const QString&)", &slot_5, QMetaData::Private },
	{ "SlotCapturandoPrecio(const QString&)", &slot_6, QMetaData::Private },
	{ "SlotFocoAPrecio()", &slot_7, QMetaData::Private },
	{ "SlotFocoAAnexar()", &slot_8, QMetaData::Private },
	{ "SlotAnexar()", &slot_9, QMetaData::Private },
	{ "SlotSeleccionoProducto(int,int,int,const QPoint&)", &slot_10, QMetaData::Private },
	{ "SlotSeleccionandoProducto(int,int,int,const QPoint&)", &slot_11, QMetaData::Private },
	{ "SlotCambioLaSeleccion()", &slot_12, QMetaData::Private },
	{ "SlotEliminar()", &slot_13, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCotizaImportacion", parentObject,
	slot_tbl, 14,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCotizaImportacion.setMetaObject( metaObj );
    return metaObj;
}

void* QCotizaImportacion::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCotizaImportacion" ) )
	return this;
    return CotizaImportacion::qt_cast( clname );
}

bool QCotizaImportacion::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotRegistra(); break;
    case 1: SlotFocoAProveedor(); break;
    case 2: SlotProveedor((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 3: SlotConsulta(); break;
    case 4: SlotProducto((zSiscomRegistro*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotCapturandoCantidad((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: SlotCapturandoPrecio((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: SlotFocoAPrecio(); break;
    case 8: SlotFocoAAnexar(); break;
    case 9: SlotAnexar(); break;
    case 10: SlotSeleccionoProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 11: SlotSeleccionandoProducto((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 12: SlotCambioLaSeleccion(); break;
    case 13: SlotEliminar(); break;
    default:
	return CotizaImportacion::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCotizaImportacion::qt_emit( int _id, QUObject* _o )
{
    return CotizaImportacion::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCotizaImportacion::qt_property( int id, int f, QVariant* v)
{
    return CotizaImportacion::qt_property( id, f, v);
}

bool QCotizaImportacion::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
