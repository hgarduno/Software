#include <IMP_Gimnasio.h>
#include <IMP_EdoRegGimnasio.h>
#include <IMP_EsEntrenadorContacto.h>
#include<SISCOMComunicaciones++.h>
#include <QSisSepomex.h>
#include <CQSisGimnasios.h>
#include <SisDirecciones.h>
#include <SisMedioComunicacion.h>
#include <SisPersonas.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QGimnasio *InstanciaGimnasio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGimnasio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGimnasio::QGimnasio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Gimnasio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrValNmbGimnasio("Si"),
				chrPtrEsEntrenador(0)
{
IniciaVariables();
ConectaSlots();
}

QGimnasio::~QGimnasio()
{

}

void QGimnasio::ConectaSlots()
{
	connect(QLEGimnasio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDireccion()));
	connect(QSSepomex,
		SIGNAL(SignalDireccion(SisDireccion *)),
		SLOT(SlotCapturoDireccion(SisDireccion *)));
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcionT,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoNombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistraGimnasio()));
}
void QGimnasio::SlotPasaFocoDireccion()
{
	QSSepomex->setFocus();
}
void QGimnasio::SlotPasaFocoNombre()
{
	SiscomPasaFocoControl(QLENombre);
}
void QGimnasio::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QGimnasio::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QGimnasio::SlotPasaFocoRegistrar()
{
	SiscomPasaFocoControl(QPBRegistra);

}
void QGimnasio::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcionT);
}
void QGimnasio::SlotCapturoDireccion(SisDireccion *pSisPtrDir)
{
	SisPtrDir=pSisPtrDir;
	QPBRegistra->setEnabled(true);
	SiscomPasaFocoControl(QLETelefono);
}
void QGimnasio::SlotRegistraGimnasio()
{
	RegistraGimnasio();
}

void QGimnasio::RegistraGimnasio()
{
CQSisOpGimnasio lCQSisOGimnasio(SisDatCom);
CQSisGimnasio *lCQSisPtrGim=new CQSisGimnasio("",SiscomObtenInformacionDelEdit(QLEGimnasio));
CQSisLstGimnasio lCQSLstGimnasio;
	lCQSisPtrGim->PonDireccion(SisPtrDir);
	lCQSisPtrGim->PonTelefono(new SisMedCom(
				"",
				"Telefono",
				SiscomObtenInformacionDelEdit(QLETelefono),
				SiscomObtenInformacionDelEdit(QLEDescripcionT)));
	lCQSisPtrGim->PonContacto(new SisPersona(
				SiscomObtenInformacionDelEdit(QLENombre),
				SiscomObtenInformacionDelEdit(QLEAPaterno),
				SiscomObtenInformacionDelEdit(QLEAMaterno),
				""));
	lCQSisPtrGim->PonValidaNombre(chrPtrValNmbGimnasio);
	if(!chrPtrEsEntrenador)
	chrPtrEsEntrenador=EsEntrenadorElContacto();	
	lCQSisPtrGim->PonEsEntrenadorContacto(chrPtrEsEntrenador);
	lCQSisOGimnasio.InsertaGimnasio(lCQSisPtrGim,&lCQSLstGimnasio);
	DespliegaEdoRegistro(&lCQSLstGimnasio);
}
const char *QGimnasio::EsEntrenadorElContacto()
{
QEsEntrenadorContacto lQEEContacto(SiscomObtenInformacionDelEdit(QLENombre),
				   SiscomObtenInformacionDelEdit(QLEAPaterno),
				   SiscomObtenInformacionDelEdit(QLEAMaterno));

	return lQEEContacto.ObtenSiEntrenador();
}
void QGimnasio::DespliegaEdoRegistro(CQSisLstGimnasio *pCQSLstGimnasio)
{

	if(pCQSLstGimnasio->count())
	{
		if(QString("ContactoRegistrado")==
		   pCQSLstGimnasio->at(0)->SRegistrosPro2["EdoValidacion"])
		 QMessageBox::information(this,
		 			  "Mensaje Del Sistema",
					  "Contacto ya registrado");
		else
		{
		    QEdoRegGimnasio lQERGimnasio(SiscomObtenInformacionDelEdit(QLEGimnasio),
		    				 pCQSLstGimnasio);
		    if(lQERGimnasio.ObtenSiLoRegistro())
		    {
			chrPtrValNmbGimnasio="No";
			RegistraGimnasio();
			chrPtrValNmbGimnasio="Si";
			chrPtrEsEntrenador=0;
		    }
		}
	}


}
void QGimnasio::IniciaVariables()
{
	if(SisDatCom)
	{
	QSSepomex->PonServidor(SisDatCom);
	QSSepomex->IniciaControl();
	}
	else
	printf("No se ha iniciado la comunicacion con el servidor\n");
	QPBRegistra->setEnabled(false);
	SiscomPasaFocoControl(QLEGimnasio);
}
