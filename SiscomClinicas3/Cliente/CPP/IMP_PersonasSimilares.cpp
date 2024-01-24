#include <IMP_PersonasSimilares.h>
#include<SISCOMComunicaciones++.h>
QPersonasSimilares::QPersonasSimilares(
				    SiscomRegistrosPro2 *pSRegistroPro2,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				PersonasSimilares(pQWParent,
						  pchrPtrName,
						  pbModal,
						  pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SRegistrosPro2(pSRegistroPro2),
				chrPtrIdPersona(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QPersonasSimilares::~QPersonasSimilares()
{

}

void QPersonasSimilares::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotPersona(int,int,int,const QPoint &)));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));

}
void QPersonasSimilares::SlotCancelar()
{
	chrPtrIdPersona=0;
	done(1);
}
void QPersonasSimilares::SlotPersona(int pintNPersona,
				     int,
				     int,
				     const QPoint &)
{
	if(pintNPersona!=-1)
	{
	chrPtrIdPersona=strdup((const char *)QTDatos->text(pintNPersona,3));
	done(1);
	}

}
const char *QPersonasSimilares::IdPersona()
{
	return chrPtrIdPersona;
}
void QPersonasSimilares::IniciaVariables()
{
MuestraPersonas();
}
void QPersonasSimilares::MuestraPersonas()
{
int lintContador;

QTDatos->setNumRows(SRegistrosPro2->SiscomObtenNumRegistros());
for(lintContador=0;
    !SRegistrosPro2->SiscomEsElUltimoRegistro();
    lintContador++,
    ++(*SRegistrosPro2))
SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList() 			<< 
		(*SRegistrosPro2)["nombre"] 	<<
		(*SRegistrosPro2)["apaterno"]	<<
		(*SRegistrosPro2)["amaterno"]	<<
		(*SRegistrosPro2)["idpersona"]);
}
