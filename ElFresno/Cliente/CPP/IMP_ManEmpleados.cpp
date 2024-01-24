#include <IMP_ManEmpleados.h>
#include<SISCOMComunicaciones++.h>
#include <CQSiscomCom.h>
#include <CQSisObjetosFresno.h>
#include <qmessagebox.h>
QManEmpleados *InstanciaManEmpleados(void *pSisDatCom,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManEmpleados((CSISCOMDatComunicaciones *)pSisDatCom,	
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManEmpleados::QManEmpleados(CSISCOMDatComunicaciones *pSisDatCom, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManEmpleados(pQWParent,pchrPtrName,pWFlags)
{
SisDatCom=new SiscomDatCom(2645,
			   "127.0.0.1");
IniciaVariables();
ConectaSlots();
}

QManEmpleados::~QManEmpleados()
{

}

void QManEmpleados::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionando(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(selectionChanged()),
		SLOT(SlotCambioFila()));
	connect(QPBBorra,
		SIGNAL(clicked()),
		SLOT(SlotBorra()));
}
void QManEmpleados::SlotBorra()
{
char lchrArrNombre[120];
if(CQSPFresno)
{
CQSisObjetosFresno::NombreCompleto(CQSPFresno,lchrArrNombre);
switch(QMessageBox::information(this,
			 "Aviso Del Sistema",
			 QString().sprintf("Se Borrara de la base de datos a %s",
			 lchrArrNombre),
			 "Aceptar",
			 "Cancelar"))
{
case 0:
	BorraEmpleado();
	ConsultandoEmpleados();
break;
case 1:
	printf("Cancelar\n");
break;

}
}
else
{

}
}
void QManEmpleados::SlotCambioFila()
{
printf("Se Cambio la fila:\n");
}
void QManEmpleados::SlotSeleccionando(int pintNFila,
				      int,
				      int,
				      const QPoint &)
{
if(pintNFila!=-1)
{
QTDatos->selectRow(pintNFila);
CQSPFresno=CQSLPFresnoLst.at(pintNFila);
}

}
void QManEmpleados::BorraEmpleado()
{
CQSisPersFresnoO lCQSPersFresnoO(SisDatCom);
lCQSPersFresnoO.Borra(CQSPFresno);
}
void QManEmpleados::IniciaVariables()
{
ConsultandoEmpleados();
}
void QManEmpleados::ConsultandoEmpleados()
{
EliminaConsultaAnterior();
ConsultaEmpleados();
MuestraEmpleados();
}
void QManEmpleados::ConsultaEmpleados()
{
CQSisPersFresnoO lCQSPerFresno(SisDatCom);
lCQSPerFresno.Empleados(&CQSLPFresnoLst);
}
void QManEmpleados::MuestraEmpleados()
{
int lintContador;
CQSisPersFresno *lCQSPersFresno;
char lchrArrNombre[120];
QTDatos->setNumRows(CQSLPFresnoLst.count());
for(lintContador=0,
    lCQSPersFresno=CQSLPFresnoLst.first();
    lCQSPersFresno;
    lCQSPersFresno=CQSLPFresnoLst.next(),
    lintContador++)
{
CQSisObjetosFresno::NombreCompleto(lCQSPersFresno,lchrArrNombre);
SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList () 	<<
		lchrArrNombre	<<
		(*lCQSPersFresno)["TipoPersona"]);
}
SiscomAjustaColumnas(QTDatos);
}

void QManEmpleados::EliminaConsultaAnterior()
{
  CQSLPFresnoLst.setAutoDelete(true);
  CQSLPFresnoLst.clear();
  CQSLPFresnoLst.setAutoDelete(true);
}
