/****************************************************************************
** QProgramandoCurso meta object code from reading C++ file 'IMP_ProgramandoCurso.h'
**
** Created: Fri Apr 12 21:26:09 2024
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../H/IMP_ProgramandoCurso.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QProgramandoCurso::className() const
{
    return "QProgramandoCurso";
}

QMetaObject *QProgramandoCurso::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProgramandoCurso( "QProgramandoCurso", &QProgramandoCurso::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProgramandoCurso::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgramandoCurso", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProgramandoCurso::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgramandoCurso", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProgramandoCurso::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = ProgramandoCurso::staticMetaObject();
    static const QUMethod slot_0 = {"SlotAgregaProgramacion", 0, 0 };
    static const QUMethod slot_1 = {"SlotHabilitaProgramacionCursos", 0, 0 };
    static const QUMethod slot_2 = {"SlotHabilitaCursos", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_3 = {"SlotProgramacionCurso", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "SiscomRegistro3", QUParameter::In }
    };
    static const QUMethod slot_4 = {"SlotCurso", 1, param_slot_4 };
    static const QUMethod slot_5 = {"SlotCapturoFecha", 0, 0 };
    static const QUMethod slot_6 = {"SlotFocoAHoraInicioFin", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "pchrPtrHoraInicio", &static_QUType_charstar, 0, QUParameter::In },
	{ "pchrPtrHoraFin", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"SlotCapturoRangoHora", 2, param_slot_7 };
    static const QUMethod slot_8 = {"SlotRegistraFecha", 0, 0 };
    static const QUMethod slot_9 = {"SlotRegistraProgramacionCurso", 0, 0 };
    static const QUMethod slot_10 = {"SlotEliminaHorariosSeleccionados", 0, 0 };
    static const QUMethod slot_11 = {"SlotConsultaCursosPorFecha", 0, 0 };
    static const QUMethod slot_12 = {"SlotSeSeleccionoAlgo", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "pintFila", &static_QUType_int, 0, QUParameter::In },
	{ "pintColumna", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_13 = {"SlotSeleccionandoCurso", 4, param_slot_13 };
    static const QMetaData slot_tbl[] = {
	{ "SlotAgregaProgramacion()", &slot_0, QMetaData::Private },
	{ "SlotHabilitaProgramacionCursos()", &slot_1, QMetaData::Private },
	{ "SlotHabilitaCursos()", &slot_2, QMetaData::Private },
	{ "SlotProgramacionCurso(SiscomRegistro3*)", &slot_3, QMetaData::Private },
	{ "SlotCurso(SiscomRegistro3*)", &slot_4, QMetaData::Private },
	{ "SlotCapturoFecha()", &slot_5, QMetaData::Private },
	{ "SlotFocoAHoraInicioFin()", &slot_6, QMetaData::Private },
	{ "SlotCapturoRangoHora(char*,char*)", &slot_7, QMetaData::Private },
	{ "SlotRegistraFecha()", &slot_8, QMetaData::Private },
	{ "SlotRegistraProgramacionCurso()", &slot_9, QMetaData::Private },
	{ "SlotEliminaHorariosSeleccionados()", &slot_10, QMetaData::Private },
	{ "SlotConsultaCursosPorFecha()", &slot_11, QMetaData::Private },
	{ "SlotSeSeleccionoAlgo()", &slot_12, QMetaData::Private },
	{ "SlotSeleccionandoCurso(int,int,int,const QPoint&)", &slot_13, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProgramandoCurso", parentObject,
	slot_tbl, 14,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProgramandoCurso.setMetaObject( metaObj );
    return metaObj;
}

void* QProgramandoCurso::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProgramandoCurso" ) )
	return this;
    return ProgramandoCurso::qt_cast( clname );
}

bool QProgramandoCurso::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: SlotAgregaProgramacion(); break;
    case 1: SlotHabilitaProgramacionCursos(); break;
    case 2: SlotHabilitaCursos(); break;
    case 3: SlotProgramacionCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 4: SlotCurso((SiscomRegistro3*)static_QUType_ptr.get(_o+1)); break;
    case 5: SlotCapturoFecha(); break;
    case 6: SlotFocoAHoraInicioFin(); break;
    case 7: SlotCapturoRangoHora((char*)static_QUType_charstar.get(_o+1),(char*)static_QUType_charstar.get(_o+2)); break;
    case 8: SlotRegistraFecha(); break;
    case 9: SlotRegistraProgramacionCurso(); break;
    case 10: SlotEliminaHorariosSeleccionados(); break;
    case 11: SlotConsultaCursosPorFecha(); break;
    case 12: SlotSeSeleccionoAlgo(); break;
    case 13: SlotSeleccionandoCurso((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    default:
	return ProgramandoCurso::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProgramandoCurso::qt_emit( int _id, QUObject* _o )
{
    return ProgramandoCurso::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProgramandoCurso::qt_property( int id, int f, QVariant* v)
{
    return ProgramandoCurso::qt_property( id, f, v);
}

bool QProgramandoCurso::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
