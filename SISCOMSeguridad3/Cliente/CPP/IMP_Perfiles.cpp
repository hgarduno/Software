#include <IMP_Perfiles.h>
#include <IMP_PerfilReferencia.h>

#include <SISCOMComunicaciones++.h>
#include <SoporteAplicacionSeguridad.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
/*
	Se debe pasar la direccion de la consulta
	de los perfiles que se realiza, en la 
	forma de las aplicaciones 


*/

CQSisPerfiles::CQSisPerfiles(const char *pchrPtrIdAplicacion,
			     const char *pchrPtrNmbAplicacion,
			      CSISCOMDatComunicaciones *pCSisDatCom,
			      QWidget* parent, const char* name, WFlags fl )
    : Perfiles( parent, name, fl ),
      CSisDatCom(pCSisDatCom),
      chrPtrIdAplicacion(pchrPtrIdAplicacion),
      chrPtrNmbAplicacion(pchrPtrNmbAplicacion)
	
{
	MuestraCabecera();
	ConectaSlots();
	ConsultaPerfiles();
	show();
}

CQSisPerfiles::~CQSisPerfiles()
{
}
void CQSisPerfiles::ConectaSlots()
{
	connect(QPBRPerfil,
	        SIGNAL(clicked()),
		SLOT(SlotRegistraPerfil()));
}
void CQSisPerfiles::SlotRegistraPerfil()
{
const char *lchrPtrPerfilRef;
	if(CQPConsulta->CuantosPerfiles())
	lchrPtrPerfilRef=CapturaPerfilReferencia();
	else
	lchrPtrPerfilRef="";
	

   CQPerfiles lCQPerfilesReg(CSisDatCom,
			     new QSiscomPerfilBD("",
						 chrPtrIdAplicacion,
						 (const char *)QLENmbPerfil->text(),
						 (const char *)QLEDscPerfil->text()),
			     lchrPtrPerfilRef);
	ReConsultaPerfiles();
	emit SignalRegistroPerfil(CQPConsulta);	
}
const char *CQSisPerfiles::CapturaPerfilReferencia()
{
CQSisPerfilReferencia *lCQSPReferencia=new CQSisPerfilReferencia(CSisDatCom,
							         (const char *)QLENmbPerfil->text(),
								 chrPtrIdAplicacion);


	return lCQSPReferencia->ObtenPerfilReferencia();	
}
void CQSisPerfiles::MuestraCabecera()
{
	setCaption(caption() +
		   ":" +
		   chrPtrNmbAplicacion);
}
void CQSisPerfiles::ReConsultaPerfiles()
{
	delete CQPConsulta;
	ConsultaPerfiles();

}
void CQSisPerfiles::ConsultaPerfiles()
{
 	CQPConsulta=new CQPerfiles(CSisDatCom,
				   chrPtrIdAplicacion); 
	MuestraPerfiles();	


}
void CQSisPerfiles::MuestraPerfiles()
{
int lintContador=0;
QSiscomPerfilBD *lQSPerfilBD;
QTDatos->setNumRows(0);
	   while((lQSPerfilBD=(*CQPConsulta)[lintContador++]))
	   {
		AnexarRegistroALaTabla(QTDatos,
				       QStringList() <<
				       lQSPerfilBD->ObtenIdPerfil() <<
				       lQSPerfilBD->ObtenNmbPerfil() <<
				       lQSPerfilBD->ObtenDscPerfil() );
	   }
}
