#include <IMP_ManDatPersonales.h>
#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisPersonas.h>
QManDatPersonales *InstanciaManDatPersonales(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManDatPersonales((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManDatPersonales::QManDatPersonales(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManDatPersonales(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QManDatPersonales::~QManDatPersonales()
{

}

void QManDatPersonales::ConectaSlots()
{
	connect(QPBBPersonas,
		SIGNAL(clicked()),
		SLOT(SlotSeleccionaPersonas()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoPersona(int,int,int,const QPoint &)));
	connect(QPBActualiza,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoActualizar()));
}
void QManDatPersonales::SlotPasaFocoAPaterno()
{
SiscomPasaFocoControl(QLEAPaterno);
}
void QManDatPersonales::SlotPasaFocoAMaterno()
{
SiscomPasaFocoControl(QLEAMaterno);
}
void QManDatPersonales::SlotPasaFocoActualizar()
{
SiscomPasaFocoControl(QPBActualiza);
}
void QManDatPersonales::SlotActualiza()
{
Actualiza();
}
void QManDatPersonales::SlotSeleccionandoPersona(
			  int pintNPersona,
			  int,
			  int,
			  const QPoint &)
{
if(pintNPersona!=-1)
 MuestraRegistroTrabajo(pintNPersona);
}
void QManDatPersonales::SlotSeleccionaPersonas()
{
	ObtenPersonas();
	MuestraPersonas();
	if(CQSLBPersona.count()==1)
	MuestraRegistroTrabajo(0);
SiscomPasaFocoControl(QLENombre);
}
void QManDatPersonales::MuestraRegistroTrabajo(int pintNRegistro)
{
CQSisBuscaPersona *lCQSBPersona=CQSLBPersona.at(pintNRegistro);
QLEPersonaM->setText(QString((*lCQSBPersona)["Nombre"])		+
			     " "				+
			     (*lCQSBPersona)["APaterno"]	+
			     " "				+
			     (*lCQSBPersona)["AMaterno"]);
QLENombre->setText((*lCQSBPersona)["Nombre"]);
QLEAPaterno->setText((*lCQSBPersona)["APaterno"]);
QLEAMaterno->setText((*lCQSBPersona)["AMaterno"]);
QLEIdPersona->setText((*lCQSBPersona)["IdPersona"]);
}
void QManDatPersonales::MuestraPersonas()
{
CQSisBuscaPersona *lCQSBPersona;
int lintContador;
QTDatos->setNumRows(CQSLBPersona.count());
for(lintContador=0,
    lCQSBPersona=CQSLBPersona.first();
    lCQSBPersona;
    lintContador++,
    lCQSBPersona=CQSLBPersona.next())
SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList () 		  	<<
		(*lCQSBPersona)["Nombre"] 	<<
		(*lCQSBPersona)["APaterno"]	<<
		(*lCQSBPersona)["AMaterno"]	<<
		(*lCQSBPersona)["IdPersona"]);
SiscomAjustaColumnas(QTDatos);
}
void QManDatPersonales::ObtenPersonas()
{
CQSisBuscaPersona *lCQSBPersona;
QBuscaPersonas lQBPersonas(SisDatCom,
			   chrPtrArgumentos);
EliminaPersonasAnterior();
if(lQBPersonas.SeSeleccionaronPersonas())
lQBPersonas.PersonasSeleccionadas(&CQSLBPersona);
else
if((lCQSBPersona=lQBPersonas.PersonaSeleccionada()))
CQSLBPersona << lCQSBPersona;

}
void QManDatPersonales::IniciaVariables()
{
}
void QManDatPersonales::EliminaPersonasAnterior()
{
CQSLBPersona.setAutoDelete(true);
CQSLBPersona.clear();
CQSLBPersona.setAutoDelete(false);
}
void QManDatPersonales::Actualiza()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpPersona lCQSOPersona(SisDatCom);
lCQSOPersona.ActualizaNombre(	
		new CQSisPersona(
			SiscomObtenInformacionDelEdit(QLEIdPersona),
			SiscomObtenInformacionDelEdit(QLENombre),
			SiscomObtenInformacionDelEdit(QLEAPaterno),
			SiscomObtenInformacionDelEdit(QLEAMaterno),
			"",
			"",
			"",
			"",
			""),
		&lSRegistrosPro2);
}
