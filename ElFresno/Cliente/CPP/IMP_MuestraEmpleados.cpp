#include <IMP_MuestraEmpleados.h>
#include <GeneralBibliotecaSeguridad3.h>
#include <CQSiscomCom.h>
#include <Personas.h>


#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QMuestraEmpleados::QMuestraEmpleados(CQ_Personas *pCQPersonas,
				     QWidget* parent,
				     const char* name,
				     bool modal,
				     WFlags fl )
    : MuestraEmpleados( parent, name, modal, fl ),
    CQPersonas(pCQPersonas)
{
	MuestraDatos();
	ConectaSlots();
	exec();
}

QMuestraEmpleados::~QMuestraEmpleados()
{
}
void QMuestraEmpleados::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
}
void QMuestraEmpleados::S_Cancelar()
{
	BTN_Opcion=SISCOMGlobales::Cancelar;
	done(1);
}
void QMuestraEmpleados::S_Aceptar()
{
	BTN_Opcion=SISCOMGlobales::Aceptar;
	done(1);
}
void QMuestraEmpleados::MuestraDatos()
{
CQ_Persona *lCQPersona;
int lintContador;
	QTDatos->setNumRows(CQPersonas->count());
	for(lCQPersona=CQPersonas->first(),
	    lintContador=0;
	    lCQPersona;
	    lCQPersona=CQPersonas->next(),
	    lintContador++)
	{
	  SISCOMAnexarRegistroALaTabla(lintContador,
	  			       QTDatos,
				       QStringList () <<
				       QString(lCQPersona->ObtenNombre()) +
				       " "				  +
				       lCQPersona->ObtenAPaterno()        +
				       " "				  +
				       lCQPersona->ObtenAMaterno() <<
				       (lCQPersona->ObtenPerfil() ?
				        lCQPersona->ObtenPerfil()->ObtenNmbPerfil() :
					"")			   <<
				       (lCQPersona->ObtenFirma() ? 
				       lCQPersona->ObtenFirma()->ObtenFirma():""));
	}

}
SISCOMGlobales::BTN_Captura QMuestraEmpleados::ObtenBoton()
{
	return BTN_Opcion;
}
CQ_Personas *QMuestraEmpleados::ObtenEmpleados()
{
CQ_Personas *lCQPersonas=new CQ_Personas;
int lintContador;
	for(lintContador=0;
	    lintContador<QTDatos->numRows();
	    lintContador++)
	{
	   if(QTDatos->isRowSelected(lintContador))
	       (*lCQPersonas)<< CQPersonas->at(lintContador);   
	}
return lCQPersonas;	
}
