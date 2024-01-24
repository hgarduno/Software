#include <IMP_OrdenesPorFecha.h>
#include<SISCOMComunicaciones++.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
QOrdenesPorFecha::QOrdenesPorFecha(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				OrdenesPorFecha(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QOrdenesPorFecha::~QOrdenesPorFecha()
{

}

void QOrdenesPorFecha::ConectaSlots()
{
	connect(QPBSOrdenes,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaOrdenes()));

}
void QOrdenesPorFecha::S_SeleccionaOrdenes()
{
QMemArray<int> lQMAOrdenes=SiscomFilasSeleccionadas(QTDatos);
int lintContador;
	for(lintContador=0;
	    lintContador<lQMAOrdenes.count();
	    lintContador++)
	   GOrdenSel << GOrden.at(lQMAOrdenes[lintContador]);

	done(1);
}
void QOrdenesPorFecha::IniciaVariables()
{
	ConsultaPorRangoFechas(chrPtrArgumentos[5],
			       chrPtrArgumentos[6],
			       &GOrden);
	MuestraInformacion(GOrden);
}
void QOrdenesPorFecha::MuestraInformacion(GeneralesOrden pGOrden)
{

GeneralOrden *lGOrden;
int lintContador;
Persona *lPCliente;
	QTDatos->setNumRows(pGOrden.count()-1);

	for(lintContador=0,
	    lGOrden=pGOrden.first();
	    lintContador<pGOrden.count()-1;
	    lintContador++,
	    lGOrden=pGOrden.next())
	 {
	 lPCliente=lGOrden->ObtenCliente();
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() 				<<
				      lGOrden->SRegistrosPro2["IdOrden"] 	<<
				      lGOrden->SRegistrosPro2["ImporteO"]	<<
				      lGOrden->SRegistrosPro2["ImporteIVA"]	<<
				      lGOrden->SRegistrosPro2["Fecha"]		<<
				      QString(lPCliente->SRegistrosPro2["Nombre"])+
				      " "					  +
				      lPCliente->SRegistrosPro2["APaterno"]       +
				      " "					  +
				      lPCliente->SRegistrosPro2["AMaterno"]);
	}
	QLCDTotal->display(lGOrden->SRegistrosPro2["ImporteO"]);
	QLCDTotIVA->display(lGOrden->SRegistrosPro2["ImporteIVA"]);
}
void QOrdenesPorFecha::ConsultaPorRangoFechas(const char *pchrPtrFechaIni,
					      const char *pchrPtrFechaFin,
					      GeneralesOrden *pGOrden)
{
SiscomParametrosConsulta lSPConsulta;

	lSPConsulta << 
	new SiscomParametroConsulta("OrdenesPorFecha")		<<
	new SiscomParametroConsulta(chrPtrArgumentos[0]) 	<<
	new SiscomParametroConsulta(pchrPtrFechaIni)	  	<<
	new SiscomParametroConsulta(pchrPtrFechaFin);
OpGeneralesOrden lOGenOrden(SisDatCom,
			   (SiscomParametrosConsulta *)&lSPConsulta);

	lOGenOrden.SiscomConsulta("ConsultaControladorOrdenes",
				  (QPtrList<SiscomInformacion>* )pGOrden);
}

void QOrdenesPorFecha::ObtenOrdenesSeleccionadas(GeneralesOrden &pGOrdenes)
{
	pGOrdenes=GOrdenSel;
}
