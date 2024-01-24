#include <IMP_Devoluciones.h>
#include<SISCOMComunicaciones++.h>

#include <CQSisOrVendidas.h>
#include <CQSisEmpresas.h>
#include <CQSisProductos.h>
#include <CQSisOpTiendas4.h>

#include <qlcdnumber.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
QDevoluciones *InstanciaDevoluciones(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QDevoluciones((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QDevoluciones::QDevoluciones(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Devoluciones(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QDevoluciones::~QDevoluciones()
{

}

void QDevoluciones::ConectaSlots()
{
	connect(QLENOrden,
		SIGNAL(returnPressed()),
		SLOT(SlotConsultaOrden()));
	connect(QTDatos,
		SIGNAL(currentChanged(int,int)),
		SLOT(SlotCambiaProducto(int,int)));
	connect(QPBDevuelve,
		SIGNAL(clicked()),
		SLOT(SlotDevuelve()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminar()));
}
void QDevoluciones::SlotEliminar()
{
	Eliminar();
}
void QDevoluciones::SlotAnexar()
{

	Anexar();

}
void QDevoluciones::SlotDevuelve()
{
	Devuelve();
}
void QDevoluciones::SlotCambiaProducto(int pintNProducto,
				       int)
{
MuestraDscProducto(pintNProducto);

}
void QDevoluciones::SlotConsultaOrden()
{
	ConsultandoOrden();
}
void QDevoluciones::IniciaVariables()
{

}
void QDevoluciones::ConsultandoOrden()
{
	ConsultaOrden();
	printf("QDevoluciones::ConsultandoOrden:%d\n",
		CQSLPCotiza.count());
	if(CQSLPCotiza.count())
	MuestraOrden();

}
void QDevoluciones::ConsultaOrden()
{
const char *lchrPtrNoOrden=SiscomObtenInformacionDelEdit(QLENOrden);
printf("QDevoluciones::ConsultaOrden:{%s}\n",
	lchrPtrNoOrden);
if(lchrPtrNoOrden[0])
{
CQSLPCotiza.clear();
CQSisOpOrdenes lCQSOOrdenes(SisDatCom);
		lCQSOOrdenes.Orden(
			lchrPtrNoOrden,
			new CQSisEmpresa("0",""),
			&CQSLPCotiza);
}
}
void QDevoluciones::MuestraOrden()
{
CQSisProdCotiza *lCQSPCotiza;
int lintNFilas=CQSLPCotiza.count()-1;
int lintContador;
	QTDatos->setNumRows(lintNFilas);
	for(lintContador=0,
	    lCQSPCotiza=CQSLPCotiza.first();
	    lintContador<lintNFilas;
	    lintContador++,
	    lCQSPCotiza=CQSLPCotiza.next())
	 SiscomAnexarRegistroALaTabla(
	 	lintContador,
		QTDatos,
		QStringList()						<<
		lCQSPCotiza->Producto()->SRegistrosPro2["Clave"]	<<
		lCQSPCotiza->SRegistrosPro2["Cantidad"]			<<
		lCQSPCotiza->SRegistrosPro2["Total"]);
QLCDNTotal->display(lCQSPCotiza->SRegistrosPro2["Total"]);
SiscomAjustaColumnas(QTDatos);
MuestraDscProducto(0);
}
void QDevoluciones::MuestraDscProducto(int pintNProducto)
{

QTEDsc->setText(CQSLPCotiza.at(pintNProducto)->Producto()->SRegistrosPro2["Dsc"]);

}
void QDevoluciones::Devuelve()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpTiendas4 lCQSOT4Devuelve(SisDatCom);
	lCQSOT4Devuelve.EjecutaDevolucion(&CQSLPCDevolver,
					  &lSRegistrosPro2);

	CQSLPCDevolver.clear();
	SiscomEliminaFilasTabla(QTDatos);
	SiscomEliminaFilasTabla(QTPADevolver);
}
void QDevoluciones::Anexar()
{
int lintNAnexar;
CQSisLstProdCotiza lCQSPCAnexar;
QMemArray<int> lQMAAnexar;
CQSisProdCotiza *lCQSPCotiza;
int lintContador;
lQMAAnexar=SiscomFilasSeleccionadas(QTDatos);
if(!(lintNAnexar=lQMAAnexar.count()))
QMessageBox::information(this,
			 "Aviso Del Sistema",
			 "No se ha seleccionado un producto");
else
{
	for(lintContador=0;
    	    lintContador<lintNAnexar;
    	    lintContador++)
	 CQSLPCDevolver << CQSLPCotiza.at(lQMAAnexar[lintContador]);
	lintNAnexar=CQSLPCDevolver.count();
	QTPADevolver->setNumRows(lintNAnexar);
	for(lintContador=0,
	    lCQSPCotiza=CQSLPCDevolver.first();
	    lintContador<lintNAnexar;
	    lintContador++,
	    lCQSPCotiza=CQSLPCDevolver.next())
	  SiscomAnexarRegistroALaTabla(
	  	lintContador,
		QTPADevolver,
		QStringList () 						<<
		lCQSPCotiza->Producto()->SRegistrosPro2["Clave"]	<<
		lCQSPCotiza->SRegistrosPro2["Cantidad"]			<<
		lCQSPCotiza->SRegistrosPro2["Total"]);
	TotalADevolver();
}
}

void QDevoluciones::TotalADevolver()
{
SiscomRegistrosPro2 *lSRegistrosPro2=0;
CQSisOpTiendas4 lCQSOT4TotalAD(SisDatCom);
	lCQSOT4TotalAD.CalculaTotalADevolver(&CQSLPCDevolver,
					     &lSRegistrosPro2);
	if(lSRegistrosPro2)
	QLCDNTotalD->display((*lSRegistrosPro2)["Importe"]);
}
void QDevoluciones::Eliminar()
{
QMemArray<int> lQMAAElimina=SiscomFilasSeleccionadas(QTPADevolver);
int lintNEliminar,
    lintContador;
if(!(lintNEliminar=lQMAAElimina.count()))
QMessageBox::information(this,
			 "Aviso Del Sistema",
			 "No se ha seleccionado un producto");
else
{

	QTPADevolver->removeRows(lQMAAElimina);
	for(lintContador=0;
	    lintContador<lintNEliminar;
	    lintContador++)
	 CQSLPCDevolver.remove(CQSLPCDevolver.at(lQMAAElimina[lintContador]));
	TotalADevolver();
}
}
void QDevoluciones::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
