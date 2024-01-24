

#include <IMP_ControladorSeguridad.h>
#include <IMP_Aplicaciones.h>
#include <IMP_ControlFormas.h>
#include <IMP_Perfiles.h>
#include <IMP_Usuarios.h>
#include <IMP_Firmas.h>
#include <IMP_ActualizaPantalla.h>

#include <SISCOMComunicaciones++.h>

#include <SoporteAplicacionSeguridad.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qlineedit.h>
#include <qdir.h>
#include <qcombobox.h>
#include <qtable.h>

CQSisControladorSeguridad::CQSisControladorSeguridad( QWidget* parent, const char* name, WFlags fl )
    : ControladorSeguridad( parent, name, fl ),
	CQSisCapApli(0),
	CQSisConFormas(0),
	CQSisConActualiza(0),
	CSisDatCom(0),
        CQSisActualiza(0)
{
	SlotIniciaComunicaciones();
	ConectaSlots();
}

CQSisControladorSeguridad::~CQSisControladorSeguridad()
{
}
void CQSisControladorSeguridad::ConectaSlots()
{
	connect(QPBCapAplicacion,
		SIGNAL(clicked()),
		SLOT(SlotCapturaAplicacion()));
	connect(QPBRegAplicacion,
		SIGNAL(clicked()),
		SLOT(SlotRegistraAplicacion()));
	connect(QPBCarAplicacion,
		SIGNAL(clicked()),
		SLOT(SlotCargaAplicacion()));
	connect(QPBIniCom,
		SIGNAL(clicked()),
		SLOT(SlotIniciaComunicaciones()));
	connect(QPBCreaPerfil,
		SIGNAL(clicked()),
		SLOT(SlotCargaPerfiles()));
	connect(QCBPerfiles,
		SIGNAL(highlighted(int)),
		SLOT(SlotMuestraDscPerfil(int)));
	connect(QCBPerfiles,
		SIGNAL(activated(int)),
		SLOT(SlotMuestraUsuariosXPerfil(int)));
	connect(QPBUsuarios,
		SIGNAL(clicked()),
		SLOT(SlotManejadorUsuarios()));
	connect(QPBCreaFirma,
		SIGNAL(clicked()),
		SLOT(SlotCapturaFirmas()));
	connect(QPBActualizaP,
		SIGNAL(clicked()),
		SLOT(S_ActualizaPantalla()));
	connect(QPBActAplicacion,
		SIGNAL(clicked()),
		SLOT(S_ActualizaAplicacion()));
		

}
void CQSisControladorSeguridad::S_ActualizaAplicacion()
{
  
	if(CQSisCapApli &&
	   !CQSisConActualiza)
	{	
	   printf("Cargando Los Archivos\n");
	   CargaArchivos();
	   CQSisConActualiza=new CQSisControlFormas(QSLArchivosUI,
						  CSisDatCom,
						  CQSisCapApli->ObtenNombreAplicacion());
	}
	else
	{
	QSiscomRegistraObjetos lQSRObjetosAct(CSisDatCom,
					      CQSisConActualiza->ObtenObjetos(),
					      CQSisCapApli->ObtenIdAplicacion().toLong(),
					      "ActualizaAplicacion");

	}





}
void CQSisControladorSeguridad::S_ActualizaPantalla()
{
CQSisActualizaPantalla *lCQSActualizaP=new CQSisActualizaPantalla(CSisDatCom);
	printf("Lllllllllllllllllllll\n");
	lCQSActualizaP->PonDirectorioQT(CQSisCapApli->ObtenDirectorioArchivosQt());
	lCQSActualizaP->PonNombreAplicacion(CQSisCapApli->ObtenNombreAplicacion());
	lCQSActualizaP->PonIdAplicacion(CQSisCapApli->ObtenIdAplicacion());
	lCQSActualizaP->show();
}
void CQSisControladorSeguridad::SlotCapturaFirmas()
{
CQSisFirmas *lCQSFirmas=new CQSisFirmas(CQSisCapApli->ObtenIdAplicacion().toLong(),
					ObtenIdPerfil(),
					CSisDatCom);
 

}
void CQSisControladorSeguridad::SlotMuestraUsuariosXPerfil(int )
{
	
	MuestraUsuariosXPerfil();
}
void CQSisControladorSeguridad::SlotManejadorUsuarios()
{
CQSisUsuarios *lCQSUsuarios=new CQSisUsuarios(CSisDatCom,
					  CQSisCapApli->ObtenIdAplicacion().toLong(),
					  (long )ObtenIdPerfil());

		 
					  
}
void CQSisControladorSeguridad::SlotMuestraDscPerfil(int pintNPerfil)
{
   QLEDscPerfil->setText((*CQPerfilesDat)[pintNPerfil]->ObtenDscPerfil());
   
}
void CQSisControladorSeguridad::SlotCargaPerfiles()
{
CQSisPerfiles *lQSPerfiles=new CQSisPerfiles((const char *)CQSisCapApli->ObtenIdAplicacion(),
					     (const char *)CQSisCapApli->ObtenNombreAplicacion(), 
					     CSisDatCom);
		connect(lQSPerfiles,
			SIGNAL(SignalRegistroPerfil(CQPerfiles *)),
			SLOT(SlotRegistroPerfiles(CQPerfiles *)));

}
void CQSisControladorSeguridad::SlotRegistroPerfiles(CQPerfiles *pCQPerfilesDat)
{
int lintCPerfiles=pCQPerfilesDat->CuantosPerfiles();
	QPBRegAplicacion->setEnabled(lintCPerfiles);
	if(lintCPerfiles)
	LlenaComboPerfiles(pCQPerfilesDat);
}
void CQSisControladorSeguridad::SlotIniciaComunicaciones()
{
	CSisDatCom=new CSISCOMDatComunicaciones(QLEPtoCom->text().toInt(),
						(const char *)QLEDirIpSvr->text(),
						(const char *)QLEUsuario->text(),
						(const char *)QLEPassword->text());
	/*QSiscomSeguridad3 *lQSSeguridad3=(QSiscomSeguridad3 *)this;
	lQSSeguridad3->AsignaControlesBDAPantalla(CSisDatCom); */
}
void CQSisControladorSeguridad::SlotCapturaAplicacion()
{
	if(!CQSisCapApli &&
	   CSisDatCom)
	{
	 CQSisCapApli=new CQSisAplicaciones(CSisDatCom);
	 connect(CQSisCapApli,
		 SIGNAL(SignalEstanRegLasPantallas(int)),
		 SLOT(SlotEstanRegLasPantallas(int)));
	 connect(CQSisCapApli,
	         SIGNAL(SignalConsultaAplicacion(int ,
                                      const QSiscomListaPantallasBD &,
				      CQPerfiles *)),
		 SLOT(SlotConsultaAplicacion(int ,
					     const QSiscomListaPantallasBD &,
					     CQPerfiles *)));

	 connect(QCBPantallas,
		 SIGNAL(highlighted(int )),
		 SLOT(SlotMuestraDatosPantalla(int)));
	
	}
}
void CQSisControladorSeguridad::SlotConsultaAplicacion(int pintEstanLasPantallas,
						       const QSiscomListaPantallasBD &pQSLPantallasBD,
						       CQPerfiles *pCQPerfilesDat)
{
	SlotLasPantallas(pQSLPantallasBD);
	QPBRegAplicacion->setEnabled(!pintEstanLasPantallas &&
				     pCQPerfilesDat->CuantosPerfiles());
	QPBCarAplicacion->setEnabled(pintEstanLasPantallas);
	if(pCQPerfilesDat->CuantosPerfiles())
	{
	LlenaComboPerfiles(pCQPerfilesDat);
	QCBPerfiles->setCurrentItem(0);
	//MuestraUsuariosXPerfil();
	}
	


} 
void CQSisControladorSeguridad::SlotMuestraDatosPantalla(int pintNPantalla)
{
QSiscomPantallaBD *lQSPantallaBD;
QSiscomPantallaConControlesBD *lQSPCControlesBD=QSLPantallasBD.at(pintNPantalla);
	lQSPantallaBD=lQSPCControlesBD->ObtenPantallaBD();
	QLEIdPantalla->setText(lQSPantallaBD->ObtenIdPantalla());
	QLEAPantalla->setText(lQSPantallaBD->ObtenArchivo());
}
void CQSisControladorSeguridad::MuestraPantallas()
{
QSiscomPantallaBD *lQSPantallaBD; 
QSiscomPantallaConControlesBD *lQSPCControlesBD;

   for(lQSPCControlesBD=QSLPantallasBD.first();
       lQSPCControlesBD;
       lQSPCControlesBD=QSLPantallasBD.next())
   {
      lQSPantallaBD=lQSPCControlesBD->ObtenPantallaBD();
      QCBPantallas->insertItem(lQSPantallaBD->ObtenNmbClase());
   }
}
void CQSisControladorSeguridad::LlenaComboPerfiles(CQPerfiles *pCQPerfilesDat)
{
QSiscomPerfilBD *lQSPerfilBD;
int lintContador=0;
	  CQPerfilesDat=pCQPerfilesDat;
	  QCBPerfiles->clear();
           while((lQSPerfilBD=(*pCQPerfilesDat)[lintContador++]))
		QCBPerfiles->insertItem(lQSPerfilBD->ObtenNmbPerfil());
	SlotMuestraDscPerfil(0);

}
void CQSisControladorSeguridad::SlotLasPantallas(const QSiscomListaPantallasBD &pQSLPantallasBD)
{
  QSLPantallasBD=pQSLPantallasBD;
	MuestraPantallas();

}
void CQSisControladorSeguridad::SlotEstanRegLasPantallas(int pintEstado)
{
	//QPBRegAplicacion->setEnabled(!pintEstado);
	//QPBCreaPerfil->setEnabled(pintEstado);
}
const char *CQSisControladorSeguridad::ObtenIdPerfilChar()
{
 int lintItemPerfil=QCBPerfiles->currentItem();
	return (*CQPerfilesDat)[lintItemPerfil]->ObtenIdPerfil();
}
QSiscomPerfilBD *CQSisControladorSeguridad::ObtenPerfil()
{
 int lintItemPerfil=QCBPerfiles->currentItem();
	return (*CQPerfilesDat)[lintItemPerfil];
}
int CQSisControladorSeguridad::ObtenIdPerfil()
{
 int lintItemPerfil=QCBPerfiles->currentItem();

	return QString((*CQPerfilesDat)[lintItemPerfil]->ObtenIdPerfil()).toInt();
}
void CQSisControladorSeguridad::SlotRegistraAplicacion()
{
	if(CQSisCapApli &&
	   !CQSisConFormas)
	{
	  printf("--dadafdafaf \n");
		CargaArchivos();
		CQSisConFormas=new CQSisControlFormas(QSLArchivosUI,
						  CSisDatCom,
						  CQSisCapApli->ObtenNombreAplicacion());
		
	}
	else
	{
	printf("Pues el esle\n");
	  QSiscomRegistraObjetos lQSRObjetos(CSisDatCom,
					     CQSisConFormas->ObtenObjetos(),
					     CQSisCapApli->ObtenIdAplicacion().toLong(),
					     ObtenIdPerfil());		
	}
}
void CQSisControladorSeguridad::CargaArchivos()
{
QDir lQDirTrabajo(CQSisCapApli->ObtenDirectorioArchivosQt());
QStringList lQSLArchivos;
int lintContador;
	if(lQDirTrabajo.exists())
	    lQSLArchivos=lQDirTrabajo.entryList("*.ui");	
for(lintContador=0;
    lintContador<lQSLArchivos.size();
	lintContador++)
{
	QSLArchivosUI << CQSisCapApli->ObtenDirectorioArchivosQt()+ 
			 "/"+ 
		         lQSLArchivos[lintContador];
}
}
void CQSisControladorSeguridad::ConsultaControlesXPerfil(QSiscomListaContXForma &pQSLContXForma)
{
QSiscomPantallaBD *lQSPantalla;
QSiscomPantallaConControlesBD *lQSPCControles;
QSiscomListaContXForma lQSLContXForma;
for(lQSPCControles=QSLPantallasBD.first();
    lQSPCControles;
    lQSPCControles=QSLPantallasBD.next())
{
 lQSPantalla=lQSPCControles->ObtenPantallaBD();
 QSiscomConsultaObjetos lQSCObjetos(CSisDatCom,
				   (const char *)CQSisCapApli->ObtenNombreAplicacion(),
				   lQSPantalla->ObtenNmbClase(),
				   (const char *)QCBPerfiles->currentText());
	lQSCObjetos.PonIdPantalla(lQSPantalla->ObtenIdPantalla());
	pQSLContXForma.append(lQSCObjetos.ObtenObjetosSeguridad());
}
}
void CQSisControladorSeguridad::SlotCargaAplicacion()
{
QSiscomListaContXForma lQSLContXForma;
	if(!CQMCFormas[ObtenIdPerfilChar()])
	{
	printf("0--------------\n");
	ConsultaControlesXPerfil(lQSLContXForma);
 	CQSisActualiza=new CQSisControlFormas(lQSLContXForma,
					  CSisDatCom,
					  CQSisCapApli->ObtenNombreAplicacion()); 
	CQMCFormas.AnexaPerfil(CQSisActualiza,
			      ObtenPerfil());
			      
	}
	else
           QSiscomRegistraObjetos lQSRObjetosAct(CSisDatCom,
						 CQMCFormas[ObtenIdPerfilChar()]->ObtenObjetos(),
						 CQSisCapApli->ObtenIdAplicacion().toLong(),
						 ObtenIdPerfil(),
						 "ActualizaObjetosDeLaAplicacion");
}
void CQSisControladorSeguridad::MuestraUsuariosXPerfil()
{
CQOperacionesUsuario lCQOUsuario(CSisDatCom);
CQUsuarios lCQUsuarios;
CQUsuario *lCQUsuario;	
int lintContador;
		lCQOUsuario.ConsultaUsuarios(CQSisCapApli->ObtenIdAplicacion().toLong(),
					     (long )ObtenIdPerfil(),
					     lCQUsuarios);	
		QTDatosU->setNumRows(0);
		for(lintContador=0;
		    (lCQUsuario=lCQUsuarios[lintContador]);
		    lintContador++)
		{
		   AnexarRegistroALaTabla(QTDatosU,
					  QStringList() <<
					  lCQUsuario->ObtenNombre() <<
					  lCQUsuario->ObtenFirma()); 
		}
}

CQManejadorControlFormas::CQManejadorControlFormas()
{

}

void CQManejadorControlFormas::AnexaPerfil(CQSisControlFormas *pCQSCFormas,
					   QSiscomPerfilBD *pQSPerfil)
{
	QSLPerfilesBD.append(pQSPerfil);
	QSCFormas.append(pCQSCFormas);

printf("Anexando:%s Contador:%d\n",
	pQSPerfil->ObtenNmbPerfil(),
	QSCFormas.count());
}
CQSisControlFormas *CQManejadorControlFormas::operator[](const char *pchrPtrIdPerfil)
{
int lintContador;
		for(lintContador=0;
		    lintContador<QSLPerfilesBD.count();
		    lintContador++)
		{
		     if((*QSLPerfilesBD.at(lintContador))==pchrPtrIdPerfil)
		     return QSCFormas.at(lintContador);
		}
	printf("No se encontro:%s %d Perfiles Registrados\n",
		 pchrPtrIdPerfil,
		 QSLPerfilesBD.count());
	return 0;	

}
