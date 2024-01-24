#include <IMP_Aplicaciones.h>
#include <SISCOMComunicaciones++.h>
#include <SoporteAplicacionSeguridad.h>
#include <CQSiscomCom.h>
#include <qfiledialog.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>


CQSisAplicaciones::CQSisAplicaciones(CSISCOMDatComunicaciones *pCSisDatCom,
				 QWidget* parent, const char* name, WFlags fl )
    : Aplicaciones( parent, name, fl ),
       CSisDatCom(pCSisDatCom),
       QSiscomSeguridad3((Aplicaciones *)this,
			  pCSisDatCom,
			  "SISCOMSeguridad3",
			  "seguridad",
			  getenv("RutaIconosSiscomSeguridad3")) 
     
{
	ConectaSlots();
	show();
}

CQSisAplicaciones::~CQSisAplicaciones()
{
}
void CQSisAplicaciones::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotVerificaIdentificador()));
	connect(QPBSDirectorio,
		SIGNAL(clicked()),
		SLOT(SlotSeleccionaDirectorio()));
	connect(QPBRAplicacion,
		SIGNAL(clicked()),
		SLOT(SlotRegistraAplicacion()));
		
}
void CQSisAplicaciones::SlotRegistraAplicacion()
{
CQAplicaciones lCQARegAplicacion(CSisDatCom,
						     (const char *)QLEIdentificador->text(),
						     (const char *)QLENombre->text(),
						     (const char *)QLEDescripcion->text(),
						     (const char *)QLERutaQQt->text());

SlotVerificaIdentificador();

}
void CQSisAplicaciones::SlotSeleccionaDirectorio()
{
QFileDialog *lQFDSelDirT=new QFileDialog(0,0,0);
            lQFDSelDirT->setMode(QFileDialog::Directory);
            lQFDSelDirT->exec();
            QLERutaQQt->setText(lQFDSelDirT->selectedFile());    
 
}
void CQSisAplicaciones::SlotVerificaIdentificador()
{
int lintEdoReg;
QString lQSIdAplicacion;
CQAplicaciones *lCQAplicacion=new CQAplicaciones(CSisDatCom,
						 (const char *)QLENombre->text());
		if((lintEdoReg=lCQAplicacion->LaAplicacionEstaRegistrada()))
		{
		   QLEDescripcion->setText(lCQAplicacion->ObtenDscAplicacion());
		   QLERutaQQt->setText(lCQAplicacion->ObtenDirArchivosQt());
		   lQSIdAplicacion=lCQAplicacion->ObtenIdAplicacion();
		    ConsultaRegistroDeLaAplicacion((const char *)lQSIdAplicacion);
		     emit SignalConsultaAplicacion(intEstanLasPantallas,
						   QSLPantallasBD,
						   CQPAplicacion);
		}	
	        else
		   lQSIdAplicacion=lCQAplicacion->ObtenIdAplicacion();
		
		QLEIdentificador->setText(lQSIdAplicacion);	
	      QPBRAplicacion->setEnabled(!lintEdoReg);
delete lCQAplicacion;
}
void CQSisAplicaciones::ConsultaRegistroDeLaAplicacion(const char *pchrPtrIdAplicacion)
{
	CQPAplicacion=new CQPerfiles(CSisDatCom,
				 pchrPtrIdAplicacion);
	if(CQPAplicacion->CuantosPerfiles()&&
	   (intEstanLasPantallas=VeSiLasPantallasEstanRegistradas(CSisDatCom,
					    pchrPtrIdAplicacion)))
	{
	QSCAplicacionBD=new QSiscomConsultaAplicacion(CSisDatCom,
						      pchrPtrIdAplicacion,
						      (const char *)ObtenNombreAplicacion());
	QSLPantallasBD=QSCAplicacionBD->ObtenPantallasBD();
	//QSLContXForma=QSCAplicacionBD->ObtenPantallasYControles();
	}

}
int CQSisAplicaciones::EstanLasPantallas()
{
	return intEstanLasPantallas;
}
QString CQSisAplicaciones::ObtenNombreAplicacion()
{
	return QLENombre->text();
}
QString CQSisAplicaciones::ObtenIdAplicacion()
{
	return QLEIdentificador->text();
}
QString CQSisAplicaciones::ObtenDirectorioArchivosQt()
{
	return QLERutaQQt->text();
}
