#include <IMP_ResultadoClientes.h>
#include <Personas.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QResultadoClientes::QResultadoClientes(CQ_Personas *pCQPersonas,
				        QWidget* parent, const char* name, bool modal, WFlags fl )
    : ResultadoClientes( parent, name, modal, fl ),
	CQPersonas(pCQPersonas)
	
{
	if(pCQPersonas->count()>1)
	{
	MuestraClientes();
	ConectaSlots();
	exec();
	}
	else
	BTN_Seleccion=QResultadoClientes::SeleccionarTodo;
}

QResultadoClientes::~QResultadoClientes()
{
}

void QResultadoClientes::MuestraClientes()
{
CQ_Persona *lP_Persona;
QString lQSPersona;
	for(lP_Persona=CQPersonas->first();
	    lP_Persona;
	    lP_Persona=CQPersonas->next())
	{
	lQSPersona=QString(lP_Persona->ObtenNombre()) +
		   " "			     +
		   lP_Persona->ObtenAPaterno() +
		   " "			       +
		   lP_Persona->ObtenAMaterno();	
	AnexarRegistroALaTabla(QTDatos,
			       QStringList() << lQSPersona);
	}
}
QResultadoClientes::BTN_Botones QResultadoClientes::ObtenSeleccion()
{
	return BTN_Seleccion;
}
void QResultadoClientes::ConectaSlots()
{
	connect(QPBSTodos,
		SIGNAL(clicked()),
		SLOT(S_SeleccionarTodos()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));
}
void QResultadoClientes::S_SeleccionarTodos()
{
	BTN_Seleccion=QResultadoClientes::SeleccionarTodo;
	done(1);
}
void QResultadoClientes::S_Cancelar()
{

	BTN_Seleccion=QResultadoClientes::Cancelar;
	done(1);
}
