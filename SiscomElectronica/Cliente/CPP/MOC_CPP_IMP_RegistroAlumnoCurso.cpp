/****************************************************************************
** QRegistroAlumnoCurso meta object code from reading C++ file 'IMP_RegistroAlumnoCurso.h'
**
** Created: Thu Apr 11 21:40:01 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_RegistroAlumnoCurso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QRegistroAlumnoCurso::className() const
{
    return "QRegistroAlumnoCurso";
}

QMetaObject *QRegistroAlumnoCurso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegistroAlumnoCurso( "QRegistroAlumnoCurso", &QRegistroAlumnoCurso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegistroAlumnoCurso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumnoCurso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegistroAlumnoCurso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegistroAlumnoCurso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegistroAlumnoCurso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = RegistroAlumnoCurso::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_0 = {"SlotCurso", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"SlotSeleccionaHorarioCurso", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_2 = {"SlotSeleccionaCostoCurso", 4, param_slot_2 };
    static const QUMethod slot_3 = {"SlotFocoAAPaterno", 0, 0 };
    static const QUMethod slot_4 = {"SlotFocoAAMaterno", 0, 0 };
    static const QUMethod slot_5 = {"SlotFocoAEscuela", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAGrupo", 0, 0 };
    static const QUMethod slot_7 = {"SlotFocoABoleta", 0, 0 };
    static const QUMethod slot_8 = {"SlotFocoACorreo", 0, 0 };
    static const QUMethod slot_9 = {"SlotFocoAReCorreo", 0, 0 };
    static const QUMethod slot_10 = {"SlotFocoACelular", 0, 0 };
    static const QUMethod slot_11 = {"SlotFocoATCasa", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_12 = {"SlotEscuelas", 1, param_slot_12 };
    static const QUMethod slot_13 = {"SlotFocoARegistrar", 0, 0 };
    static const QUMethod slot_14 = {"SlotRegistra", 0, 0 };
    static const QUMethod slot_15 = {"SlotDisponibilidadCursos", 0, 0 };
    static const QUMethod slot_16 = {"SlotImprimeComprobante", 0, 0 };
    static const QUMethod slot_17 = {"SlotInscribeOAlumno", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "SlotCurso(SiscomRegistro3*)", &slot_0, QMetaData::Private },
	{ "SlotSeleccionaHorarioCurso(int,int,int,const QPoint&)", &slot_1, QMetaData::Private },
	{ "SlotSeleccionaCostoCurso(int,int,int,const QPoint&)", &slot_2, QMetaData::Private },
	{ "SlotFocoAAPaterno()", &slot_3, QMetaData::Private },
	{ "SlotFocoAAMaterno()", &slot_4, QMetaData::Private },
	{ "SlotFocoAEscuela()", &slot_5, QMetaData::Private },
	{ "SlotFocoAGrupo()", &slot_6, QMetaData::Private },
	{ "SlotFocoABoleta()", &slot_7, QMetaData::Private },
	{ "SlotFocoACorreo()", &slot_8, QMetaData::Private },
	{ "SlotFocoAReCorreo()", &slot_9, QMetaData::Private },
	{ "SlotFocoACelular()", &slot_10, QMetaData::Private },
	{ "SlotFocoATCasa()", &slot_11, QMetaData::Private },
	{ "SlotEscuelas(SiscomRegistro3*)", &slot_12, QMetaData::Private },
	{ "SlotFocoARegistrar()", &slot_13, QMetaData::Private },
	{ "SlotRegistra()", &slot_14, QMetaData::Private },
	{ "SlotDisponibilidadCursos()", &slot_15, QMetaData::Private },
	{ "SlotImprimeComprobante()", &slot_16, QMetaData::Private },
	{ "SlotInscribeOAlumno()", &slot_17, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QRegistroAlumnoCurso", parentObject,
	slot_tbl, 18,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegistroAlumnoCurso.setMetaObject( metaObj );
    return metaObj;
}

void* QRegistroAlumnoCurso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegistroAlumnoCurso" ) )
	return this;
    return RegistroAlumnoCurso::qt_cast( clname );
}

bool QRegistroAlumnoCurso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 1: SlotSeleccionaHorarioCurso((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: SlotSeleccionaCostoCurso((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: SlotFocoAAPaterno(); break;
    case 4: SlotFocoAAMaterno(); break;
    case 5: SlotFocoAEscuela(); break;
    case 6: SlotFocoAGrupo(); break;
    case 7: SlotFocoABoleta(); break;
    case 8: SlotFocoACorreo(); break;
    case 9: SlotFocoAReCorreo(); break;
    case 10: SlotFocoACelular(); break;
    case 11: SlotFocoATCasa(); break;
    case 12: SlotEscuelas((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 13: SlotFocoARegistrar(); break;
    case 14: SlotRegistra(); break;
    case 15: SlotDisponibilidadCursos(); break;
    case 16: SlotImprimeComprobante(); break;
    case 17: SlotInscribeOAlumno(); break;
    default:
	return RegistroAlumnoCurso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRegistroAlumnoCurso::qt_emit( int _id, QUObject* _o )
{
    return RegistroAlumnoCurso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegistroAlumnoCurso::qt_property( int id, int f, QVariant* v)
{
    return RegistroAlumnoCurso::qt_property( id, f, v);
}

bool QRegistroAlumnoCurso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
