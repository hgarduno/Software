#include <IMP_EmpleadosExpendio.h>
	#include <IMP_SelExpendios.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qtable.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
QEmpleadosExpendio *InstanciaEmpleadosExpendio(void *pSisDatCom,
					       char **pchrPtrArgumentos,
					       void *pQWParent,
					       const char *pchrPtrName,
					       int pintWFlags)
{
	return new QEmpleadosExpendio(
			(SiscomDatCom *)pSisDatCom,
			pchrPtrArgumentos,
			(QWidget *)pQWParent,
			pchrPtrName,
			pintWFlags);
}
QEmpleadosExpendio::QEmpleadosExpendio(SiscomDatCom *pSisDatCom,
				      char **pchrPtrArgumentos,
					QWidget* parent,
					const char* name,
					WFlags fl )
    : EmpleadosExpendio( parent, name, fl ),
      SisDatCom(pSisDatCom)
{
	ConsultaUsuariosSeguridad3();
	ConsultaExpendios();
	ConectaSlots();
	
}

QEmpleadosExpendio::~QEmpleadosExpendio()
{
}
void QEmpleadosExpendio::ConectaSlots()
{
	connect(QPBValEmpleado,
		SIGNAL(clicked()),
		SLOT(S_ValidaEmpleado()));
	connect(QPBAsignaEmpleado,
		SIGNAL(clicked()),
		SLOT(S_AsignaEmpleado()));
	connect(QIVExpendios,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));

}
void QEmpleadosExpendio::S_SeleccionoExpendio(QIconViewItem *pQIVItem)
{

	Expendio=((QIconVExpendio *)pQIVItem)->ObtenExpendio();

}
void QEmpleadosExpendio::S_AsignaEmpleado()
{
	if(PFirma &&
	   Expendio )
	AsignaEmpleadoExpendio(SisDatCom,
			       PFirma->SRegistrosPro2["IdPersona"],
			       Expendio->SRegistrosPro2["IdEmpresa"]);

			       

}
void QEmpleadosExpendio::S_ValidaEmpleado()
{
char lchrArrFirma[128];
Personas lPersonas;
ConsultaPersonas lCnsPersonas;
int lintNumFila;
lintNumFila=ObtenFirmaAValidar(lchrArrFirma);
if((PFirma=lCnsPersonas.ObtenDatosFirma(SisDatCom,lchrArrFirma)))
	QTDatos->setText(lintNumFila,2,PFirma->SRegistrosPro2["IdPersona"]);
}

int QEmpleadosExpendio::ObtenFirmaAValidar(char *pchrPtrFirma)
{
int lintContador,
    lintNumFilas=QTDatos->numRows();
    	for(lintContador=0;
	    lintContador<lintNumFilas;
	    lintContador++)
	   if(QTDatos->isRowSelected(lintContador))
	   {
	    strcpy(pchrPtrFirma,
	    	   (const char *)QTDatos->text(lintContador,1));
	     return lintContador;
	   }

}
void QEmpleadosExpendio::ConsultaUsuariosSeguridad3()
{
ConsultaPersonas lCnsPersonas;
	lCnsPersonas.ConsultaUsuariosSeguridad3(SisDatCom,
						PPersonas);
Persona *lPersona;
int lintContador;
	QTDatos->setNumRows(PPersonas.count());
	for(lintContador=0,
	    lPersona=PPersonas.first();
	    lPersona;
	    lintContador++,
	    lPersona=PPersonas.next())
	SiscomAnexarRegistroALaTabla(lintContador,
				     QTDatos,
				     QStringList ()   <<
				     QString(lPersona->SRegistrosPro2["Nombre"]) +
				     " "					 +
				     lPersona->SRegistrosPro2["APaterno"]	 +
				     " "				 +
				     lPersona->SRegistrosPro2["AMaterno"] <<
				     lPersona->SRegistrosPro2["Firma"]);

	
}
void QEmpleadosExpendio::ConsultaExpendios()
{
ConsultaEmpresasN lCnsExpendios(SisDatCom,"Expendios",Expendios);

EmpresaN *lEmpresa;
	for(lEmpresa=Expendios.first();
	    lEmpresa;
	    lEmpresa=Expendios.next())
	  QIVExpendios->insertItem(new QIconVExpendio(lEmpresa,QIVExpendios));

}
void QEmpleadosExpendio::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
