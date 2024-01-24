#include <IMP_ReporteExistencias.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisOpTiendas4.h>
#include <QCtrlProductos.h>
#include <QCtrlFamilias.h>

#include <qpushbutton.h>
QReporteExistencias *InstanciaReporteExistencias(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QReporteExistencias((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QReporteExistencias::QReporteExistencias(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ReporteExistencias(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QReporteExistencias::~QReporteExistencias()
{

}

void QReporteExistencias::ConectaSlots()
{
	connect(QPBTodos,
		SIGNAL(clicked()),
		SLOT(SlotTodos()));

}
void QReporteExistencias::SlotTodos()
{
ConsultandoTodosLosProductos();
}
void QReporteExistencias::IniciaVariables()
{
	QCtrProductos->PonServidor(SisDatCom);
	QCtrProductos->IniciaControl();
	QCtrFamilias->PonServidor(SisDatCom);
	QCtrFamilias->IniciaControl();
}
void QReporteExistencias::ConsultaTodosLosProductos()
{
CQSisOpTiendas4 lCQSOTiendas(SisDatCom);
	lCQSOTiendas.ExistenciaProductos(&CQSLPCotiza);

}
void QReporteExistencias::ConsultandoTodosLosProductos()
{
	ConsultaTodosLosProductos();
	MuestraProductos();
}
void QReporteExistencias::MuestraProductos()
{
int lintContador;
CQSisProdCotiza *lCQSPCotiza;
QTDatos->setNumRows(CQSLPCotiza.count());
for(lCQSPCotiza=CQSLPCotiza.first(),
    lintContador=0;
    lCQSPCotiza;
    lCQSPCotiza=CQSLPCotiza.next(),
    lintContador++)
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTDatos,
	QStringList() <<
	lCQSPCotiza->Producto()->SRegistrosPro2["Clave"] <<
	lCQSPCotiza->SRegistrosPro2["Existencia"]	 <<
	lCQSPCotiza->SRegistrosPro2["ExiMinima"]);
}

void QReporteExistencias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
