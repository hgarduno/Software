#include <IMP_DatosClienteF.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QDatosClienteF *InstanciaDatosClienteF(void *pSDatCom,
				      char **pchrPtrArgumentos,
				      void *pQWParent,
				      const char *pchrPtrName,
				      int pintFlags)
{
	return new QDatosClienteF((SiscomDatCom *)pSDatCom,
				  pchrPtrArgumentos,
				  (QWidget *)pQWParent,
				  pchrPtrName,
				  pintFlags);
}

QDatosClienteF::QDatosClienteF(SiscomDatCom *pSisDatCom,
			       char **pchrPtrArgumentos,
			       QWidget* parent,
			       const char* name,
			       WFlags fl )
    : DatosClienteF( parent, name, fl ),
      SisDatCom(pSisDatCom),
      chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConsultaDatosRegistrados();
	ConectaSlots();
}
QDatosClienteF::~QDatosClienteF()
{
}
void QDatosClienteF::IniciaVariables()
{
DatoClienteF *lDClienteF=new DatoClienteF("","","","","","",chrPtrArgumentos[0],"");

	DatClienteFrec << lDClienteF;
	
	SiscomPasaFocoControl(QLELInferior);
}
void QDatosClienteF::ConectaSlots()
{
	connect(QLELInferior,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoLimSuperior()));
	connect(QLELSuperior,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescuento()));
	connect(QLEDescuento,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(S_Actualiza()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_Eliminar()));
}
void QDatosClienteF::S_Eliminar()
{
	ModificaRegistros("Elimina");
}
void QDatosClienteF::ModificaRegistros(const char *pchrPtrOperacion)
{
DatosClienteFrec lDatCliFrec;
DatoClienteF *lDatCli;
int lintContador;
int lintNumFilas=QTDatos->numRows();
	for(lintContador=0;
	    lintContador<lintNumFilas;
	    lintContador++)
	if(QTDatos->isRowSelected(lintContador))
	{
	  lDatCli=DatClienteFrec.at(lintContador);
	  lDatCli->SiscomActualizaCampo("EdoRegistro",pchrPtrOperacion);
	  lDatCli->SiscomActualizaCampo("LimiteInferior",QTDatos->text(lintContador,0));
	  lDatCli->SiscomActualizaCampo("LimiteSuperior",QTDatos->text(lintContador,1));
	  lDatCli->SiscomActualizaCampo("Descuento",QTDatos->text(lintContador,2));
	  lDatCli->SiscomActualizaCampo("NumDias",(const char *)QLENumDias->text());
	  lDatCliFrec << lDatCli;
	}
	
	OperacionesDatosClienteFrec lOpClienteFrec(SisDatCom,
					   lDatCliFrec);
		lOpClienteFrec.RegistraDatos();
	ConsultaDatosRegistrados();

}
void QDatosClienteF::S_Actualiza()
{
 ModificaRegistros("Actualiza");
}
void QDatosClienteF::S_PasaFocoNumDias()
{
	SiscomPasaFocoControl(QLENumDias);
}
void QDatosClienteF::S_PasaFocoLimSuperior()
{
	SiscomPasaFocoControl(QLELSuperior);
}
void QDatosClienteF::S_PasaFocoDescuento()
{
	SiscomPasaFocoControl(QLEDescuento);
}
void QDatosClienteF::S_PasaFocoAnexar()
{
	SiscomPasaFocoControl(QPBAnexar);
}
void QDatosClienteF::S_Anexar()
{
int lintNumFilas=QTDatos->numRows();
int lintContador;
	DatClienteFrec << new DatoClienteF("",
					   (const char *)QLENumDias->text(),
					   (const char *)QLELInferior->text(),
					   (const char *)QLELSuperior->text(),
					   (const char *)QLEDescuento->text(),
					   chrPtrArgumentos[1],
					   chrPtrArgumentos[0],
					   "");
	QTDatos->setNumRows(lintNumFilas+1);
	SiscomAnexarRegistroALaTabla(lintNumFilas,
				     QTDatos,
				     QStringList () <<
				     QLELInferior->text () <<
				     QLELSuperior->text()  <<
				     QLEDescuento->text());
				     
}
void QDatosClienteF::S_Registrar()
{
OperacionesDatosClienteFrec lOpClienteFrec(SisDatCom,
					   DatClienteFrec);
	
		lOpClienteFrec.RegistraDatos();
	DatClienteFrec.clear();
	QTDatos->setNumRows(0);
	ConsultaDatosRegistrados();
}
void QDatosClienteF::ConsultaDatosRegistrados()
{

OperacionesDatosClienteFrec lOpClienteFrec(SisDatCom,DatClienteFrec);
	lOpClienteFrec.ConsultaDatos(DatClienteFrec);
DatoClienteF *lDatCliente;
int lintContador;
int lintNumRegistros;
	lintNumRegistros=DatClienteFrec.count();
	if(lintNumRegistros)
	{
	QTDatos->setNumRows(lintNumRegistros);
	lDatCliente=DatClienteFrec.first();
	QLENumDias->setText(lDatCliente->SRegistrosPro2["NumDias"]);
	for( lintContador=0;
	    lDatCliente;
	    lDatCliente=DatClienteFrec.next(),
	    lintContador++)
	SiscomAnexarRegistroALaTabla(lintContador,
				      QTDatos,
				      QStringList()                <<
				      lDatCliente->SRegistrosPro2["LimiteInferior"] <<
				      lDatCliente->SRegistrosPro2["LimiteSuperior"] <<
				      lDatCliente->SRegistrosPro2["Descuento"]);
	}



}
void QDatosClienteF::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
