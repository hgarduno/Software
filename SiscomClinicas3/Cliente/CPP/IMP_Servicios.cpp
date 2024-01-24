#include <IMP_Servicios.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include<CQSisServicios.h>
#include <qpushbutton.h>
QServicios *InstanciaServicios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QServicios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QServicios::QServicios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Servicios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QServicios::~QServicios()
{

}

void QServicios::ConectaSlots()
{
	connect(QLEClave,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
}
void QServicios::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QServicios::SlotPasaFocoRegistrar()
{
	SiscomPasaFocoControl(QPBRegistra);
}
void QServicios::SlotRegistrar()
{
	Registra();
	ServiciosRegistrados();
}
void QServicios::IniciaVariables()
{
SiscomPasaFocoControl(QLEClave);
SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
ServiciosRegistrados();
}
void QServicios::Registra()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpServicio lCQOServicio(SisDatCom);
lCQOServicio.Servicio(Servicio(),
		       &lSRegistrosPro2);
}
CQSisServicio *QServicios::Servicio()
{
return new CQSisServicio(
		"",
		SiscomObtenInformacionDelEdit(QLEClave),
		SiscomObtenInformacionDelEdit(QLEDescripcion),
		chrPtrArgumentos[10],
		SUSeg3Firmado->SRegistrosPro2["IdPersona"]);
}
void QServicios::ServiciosRegistrados()
{
CQSisOpServicio lCQSOServicio(SisDatCom);
lCQSOServicio.Servicio(chrPtrArgumentos[11],
		       SUSeg3Firmado->SRegistrosPro2["IdPersona"],
		       &CQSLServicios);
MuestraServicios();
}
void QServicios::MuestraServicios()
{
int lintContador=0;
CQSisServicio *lCQSServicio;
QTDatos->setNumRows(CQSLServicios.count());

for(lCQSServicio=CQSLServicios.first(),
    lintContador=0;
    lCQSServicio;
    lCQSServicio=CQSLServicios.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(lintContador,
			     QTDatos,
			     QStringList() << 
			     lCQSServicio->SRegistrosPro2["Clave"] <<
			     lCQSServicio->SRegistrosPro2["Descripcion"]);

SiscomAjustaColumnas(QTDatos);
}
