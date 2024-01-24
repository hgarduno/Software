#include <GeneralBibliotecaSeguridad3.h>

#include <qwidgetfactory.h>
#include <qobjectlist.h>
#include <qobject.h>
#include <qvariant.h>

extern QFont gQFTipoLetra;
extern FILE *gPtrFleArchivoLog;
QSiscomPropiedadesBD::QSiscomPropiedadesBD(QString pQSIdPropiedadBD,
					   QString pQSNmbPropiedad,
					   QString pQSValorPropiedad):
			QSIdPropiedadBD(pQSIdPropiedadBD),
			QSNmbPropiedad(pQSNmbPropiedad),
			QSValorPropiedad(pQSValorPropiedad)
{

}
void QSiscomPropiedadesBD::PonValorPropiedad(QString pQSValorPropiedad)
{
	QSValorPropiedad=pQSValorPropiedad;
}
QString QSiscomPropiedadesBD::ObtenIdPropiedadBD()
{
	return QSIdPropiedadBD;
}
QString QSiscomPropiedadesBD::ObtenNombrePropiedad()
{
	return QSNmbPropiedad;
}
QString QSiscomPropiedadesBD::ObtenValorPropiedad()
{
	return QSValorPropiedad;
}
QSiscomObjetosSeguridad::QSiscomObjetosSeguridad(CSISCOMDatComunicaciones *pCSDCom,
						 QSiscomListaObjQ pQSLObjQDat,
						 QString pQSAplicacion,
						 QString pQSClase,
						 QString pQSNmbClase):
		CQOGenericaServidorSiscom(pCSDCom,
					  "libRNAltaGenericaSeguridad3SinAD.so",
					  "RNAltaGenericaSinAD",
					  4),
		QSLObjQ(pQSLObjQDat),
		QSAplicacion(pQSAplicacion),
		QSClase(pQSClase),
		QSNmbForma(pQSNmbClase)
{
	FiltraObjetos();
	

}
QSiscomObjetosSeguridad::QSiscomObjetosSeguridad(QSiscomListaObjQ pQSLObjQDat,
						 QString pQSAplicacion,
						 QString pQSClase,
						 QString pQSNmbClase,
						 const char *pchrPtrIdClase):
			QSLObjFiltrados(pQSLObjQDat),
			QSAplicacion(pQSAplicacion),
			QSClase(pQSClase),
			QSNmbForma(pQSNmbClase),
			chrPtrIdClase(pchrPtrIdClase)
{
	

}
QSiscomListaObjQ QSiscomObjetosSeguridad::ObtenObjetosFiltrados()
{
	return QSLObjFiltrados;
}
void QSiscomObjetosSeguridad::FiltraObjetos()
{
QSiscomObjetosQT *lQSObjQDat;

		AnexaRegistro("%s%s%s%s",
			      "RegistraPantalla",
			      (const char *)QSAplicacion,
			      (const char *)QSClase,
			      (const char *)QSNmbForma);
			      
		for(lQSObjQDat=QSLObjQ.first();
		    lQSObjQDat;
		    lQSObjQDat=QSLObjQ.next())
		  AnexaPropiedades(lQSObjQDat);
	       EjecutaEnvioSvrSISCOM();
	       ObtenRespuesta();
	       ConstruyeObjetosFiltrados();

QSiscomListaPropBD lQSListPropBD;
QSiscomPropiedadesBD *lQSPropBD;
}
int QSiscomObjetosSeguridad::EsElRegistroVacio(QStringList pQSLRegistro)
{

int lintNRegistros=0;
int lintContador;
	for(lintContador=0;lintContador<pQSLRegistro.size();lintContador++)
	 if(pQSLRegistro[lintContador].isEmpty())
	   lintNRegistros++;
	return lintNRegistros==pQSLRegistro.size();
	 
	

}
void QSiscomObjetosSeguridad::PonNombreForma(const char *pchrPtrNmbForma)
{
	QSNmbForma=pchrPtrNmbForma;
}
void QSiscomObjetosSeguridad::PonObjetosFiltrados(QSiscomListaObjQ pQSLObjetos)
{
	QSLObjFiltrados=pQSLObjetos;
}
QString QSiscomObjetosSeguridad::ObtenNombreForma()
{
	if(!(const char *)QSNmbForma)
	printf("QSiscomObjetosSeguridad::ObtenNombreForma:Valor Nulo\n");

	return QSNmbForma;
}
const char *QSiscomObjetosSeguridad::ObtenIdForma()
{
	if(!chrPtrIdClase)
	printf("QSiscomObjetosSeguridad::ObtenIdForma:Valor Nulo\n");

	return chrPtrIdClase;
}
void QSiscomObjetosSeguridad::ConstruyeObjetosFiltrados()
{
QStringList  lQSLRegistro;
QString lQSObjeto;
int lintEdoReg;
QSiscomObjetosQT *lQSObjQT;
	 while(!SiguienteRegistro(lQSLRegistro))
	{
	   
	    if(!lQSLRegistro[1].isEmpty())
	    {
	     lQSObjQT=new QSiscomObjetosQT;
	     lQSObjQT->PonNombreObjeto(lQSLRegistro[1]);
	     lQSObjQT->PonClaseQT(lQSLRegistro[0]);
	     lQSObjQT->PonIdObjeto(lQSLRegistro[2]);


	     while(!SiguienteRegistro(lQSLRegistro) &&
		   !EsElRegistroVacio(lQSLRegistro))
	     {
		lQSObjQT->AnexaPropiedad(lQSLRegistro[4],
					 (const char *)lQSLRegistro[3],
					 "valor");
	     }
		AsignaObjetoDePantallaABD(QSLObjQ,lQSObjQT);
	        QSLObjFiltrados.append(lQSObjQT);	
	     }
	   }
}
void QSiscomObjetosSeguridad::AsignaObjetoDePantallaABD(QSiscomListaObjQ pQSLObjPantalla,
							 QSiscomObjetosQT *pQSObjetosBD)
{
QSiscomObjetosQT *lQSObjPantalla;
QSiscomListaPropBD lQSListPropBD;
QSiscomPropiedadesBD *lQSPropiedadesBD;
		for(lQSObjPantalla=pQSLObjPantalla.first();
		    lQSObjPantalla;
		    lQSObjPantalla=pQSLObjPantalla.next())
			if(*lQSObjPantalla==pQSObjetosBD)
			    *pQSObjetosBD=lQSObjPantalla;
}
void QSiscomObjetosSeguridad::AnexaPropiedades(QSiscomObjetosQT *pQSObjQT)
{
QString lQSPropiedad;
QString lQSValor;
		while(!pQSObjQT->HayMasPropiedades())
		{
			lQSPropiedad=pQSObjQT->ObtenSiguientePropiedad();
		        lQSValor=pQSObjQT->ObtenValorPropiedad((const char *)lQSPropiedad);	
		AnexaRegistro("%s%s%s%s",
			      "",
			      "",
			      (const char *)lQSPropiedad,
			      (const char *)lQSValor);
		}
		

}
void QSiscomObjetosSeguridad::ConsultaObjetos(QWidget *pQWPantalla)
{


}
QSiscomArchivoUI::QSiscomArchivoUI( const char *pchrPtrNmbArchivo):
		QSNmbArchivo(pchrPtrNmbArchivo)
{
	LeeArchivo();
	

}
void QSiscomArchivoUI::LeeArchivo()
{

	if((QWPantalla=QWidgetFactory::create(QSNmbArchivo)))
	ObtenControles(QWPantalla);
}
QSiscomListaObjQ QSiscomArchivoUI::ObtenControlesArchivo()
{
	return QPLObjetos;
}
void QSiscomArchivoUI::ObtenControles(QWidget *pQWPantalla)
{
QObjectList *lQOLControles=pQWPantalla->queryList();
QObjectListIt lQOLIt(*lQOLControles);
QObject *lQOControl;
QSiscomObjetosQT *lQSObjetosQT;			
		QSClase=pQWPantalla->className();
		QSNmbForma=pQWPantalla->name(); 	
		 while((lQOControl=lQOLIt.current()))
		 {
		   lQSObjetosQT=new QSiscomObjetosQT;
		   lQSObjetosQT->PonNombreObjeto(lQOControl->name());
		   lQSObjetosQT->PonClaseQT(lQOControl->className());
		   lQSObjetosQT->PonControlPantalla(lQOControl);
						  
		   lQSObjetosQT->AnexaPropiedad(lQOControl->className(),
					       lQOControl->name()); 
		   QPLObjetos.append(lQSObjetosQT);
		  ++lQOLIt;
		 }
}
void QSiscomArchivoUI::ObtenControles(QWidget *pQWPantalla,
				      QSiscomListaObjQ &pQSObjetosQT)
{
QObjectList *lQOLControles=pQWPantalla->queryList();
QObjectListIt lQOLIt(*lQOLControles);
QObject *lQOControl;
QSiscomObjetosQT *lQSObjetosQT;			
		 while((lQOControl=lQOLIt.current()))
		 {
		   lQSObjetosQT=new QSiscomObjetosQT;
		   lQSObjetosQT->PonNombreObjeto(lQOControl->name());
		   lQSObjetosQT->PonClaseQT(lQOControl->className());
		   lQSObjetosQT->PonControlPantalla(lQOControl);
						  
		   lQSObjetosQT->AnexaPropiedad(lQOControl->className(),
					       lQOControl->name()); 
		   pQSObjetosQT.append(lQSObjetosQT);
		  ++lQOLIt;
		 }
}
void QSiscomArchivoUI::ImprimeObjetos(QSiscomListaObjQ pQSObjetosQT,
				      const char *pchrPtrNmbFuncion)
{
QSiscomObjetosQT *lQSObjQT;
QSiscomListaPropBD lQSLPBDDat;
QSiscomPropiedadesBD *lQSPBDObj;
	for(lQSObjQT=pQSObjetosQT.first();
	    lQSObjQT;
	    lQSObjQT=pQSObjetosQT.next())
	{
	   lQSLPBDDat=lQSObjQT->ObtenPropiedades();
	   printf("%s:%s\n",
		  (const char *)lQSObjQT->ObtenNombreObjeto(),
		  pchrPtrNmbFuncion); 
	   for(lQSPBDObj=lQSLPBDDat.first();
	       lQSPBDObj;
	       lQSPBDObj=lQSLPBDDat.next())
	    printf("\t%s [%s]\n",
		   (const char *)lQSPBDObj->ObtenNombrePropiedad(),
		   (const char *)lQSPBDObj->ObtenValorPropiedad());
	}

}
QString QSiscomArchivoUI::ObtenClase()
{
	return QSClase;
}
QString QSiscomArchivoUI::ObtenNmbForma()
{
	return QSNmbForma;
}

QSiscomObjetosQT::QSiscomObjetosQT():
		intPropiedad(0)
{

}
void QSiscomObjetosQT::PonControlPantalla(QObject *pQOControl)
{
	QOControlPantalla=pQOControl;
}
int QSiscomObjetosQT::operator==(QSiscomObjetosQT *pQSObjQTDat)
{
	return pQSObjQTDat->ObtenNombreObjeto()==ObtenNombreObjeto();
}
int QSiscomObjetosQT::operator==(QObject *pQOControl)
{
	return ObtenNombreObjeto()==pQOControl->name();
}
QObject *QSiscomObjetosQT::ObtenControlPantalla()
{
	return QOControlPantalla;
}
void QSiscomObjetosQT::ActualizaPropiedad(const char *pchrPtrNmbPropiedad,
					  QString pQSValorPropiedad)
{
QSiscomPropiedadesBD *lQSPropBD;

		for(lQSPropBD=QSLPropBD.first();
		    lQSPropBD;
		    lQSPropBD=QSLPropBD.next())
		{
		   if(lQSPropBD->ObtenNombrePropiedad()==pchrPtrNmbPropiedad)
		   {
		       	lQSPropBD->PonValorPropiedad(pQSValorPropiedad);	 
		   } 
		}
}
const QSiscomObjetosQT &QSiscomObjetosQT::operator=(QSiscomObjetosQT *pQSObjQTDat)
{
QSiscomListaPropBD lQSListPropBD=ObtenPropiedades();
QSiscomPropiedadesBD *lQSPropBD;
QString lQSValorPantalla;
		for(lQSPropBD=lQSListPropBD.first();
		    lQSPropBD;
		    lQSPropBD=lQSListPropBD.next())
		{
			lQSValorPantalla=pQSObjQTDat->ObtenControlPantalla()->property((const char *)lQSPropBD->ObtenNombrePropiedad()).toString();
		        ActualizaPropiedad((const char *)lQSPropBD->ObtenNombrePropiedad(),
					   lQSValorPantalla);	 
		}
	return *this;
}
QSiscomObjetosQT *QSiscomObjetosQT::CopiaObjeto(const char *pchrPtrNombre)
{
QSiscomObjetosQT *lQSObjeto=new QSiscomObjetosQT;

	printf("QSiscomObjetosQT::CopiaObjeto->%s\n",pchrPtrNombre);
	 lQSObjeto->PonPropiedades(ObtenPropiedades());
	 lQSObjeto->PonNombreObjeto(pchrPtrNombre);
	 lQSObjeto->ActualizaPropiedad("name",pchrPtrNombre);
	 lQSObjeto->PonIdObjeto(ObtenIdObjeto());
	 lQSObjeto->PonClaseQT(ObtenClaseQT());
	
	return lQSObjeto;
}
void QSiscomObjetosQT::PonPropiedades(QSiscomListaPropBD pQSLPropiedades)
{
	QSLPropBD=pQSLPropiedades;
}
QSiscomListaPropBD QSiscomObjetosQT::ObtenPropiedades()
{
	return QSLPropBD;
}
QString QSiscomObjetosQT::ObtenNombreObjeto()
{
	return QSNmbObjeto;
}
QString QSiscomObjetosQT::ObtenIdObjeto()
{
	return QSIdObjeto;
}
int QSiscomObjetosQT::HayMasPropiedades()
{
	return intPropiedad>=QSLPropBD.count();
}
void QSiscomObjetosQT::AnexaPropiedad(const char *pchrPtrPropiedad,
				      QString pQSValor)
{
	QSLPropBD.append(new QSiscomPropiedadesBD("",pchrPtrPropiedad,pQSValor));
}
void QSiscomObjetosQT::AnexaPropiedad(QString pQSIdPropiedadBD,
					const char *pchrPtrPropiedad,
				      QString pQSValor)
{
	QSLPropBD.append(new QSiscomPropiedadesBD(pQSIdPropiedadBD,pchrPtrPropiedad,pQSValor));
}
QString QSiscomObjetosQT::ObtenValorPropiedad(const char *pchrPtrNmbPropiedad)
{
int lintContador,
    lintNPropiedades=QSLPropBD.count();
	for(lintContador=0;lintContador<lintNPropiedades;lintContador++)
	{
		if(((QSiscomPropiedadesBD *)QSLPropBD.at(lintContador))->ObtenNombrePropiedad()==pchrPtrNmbPropiedad)
		return ((QSiscomPropiedadesBD *)QSLPropBD.at(lintContador))->ObtenValorPropiedad();
	}
 return "";
}
QString QSiscomObjetosQT::ObtenSiguientePropiedad()
{
	return ((QSiscomPropiedadesBD *)QSLPropBD.at(intPropiedad++))->ObtenNombrePropiedad();
}
QString QSiscomObjetosQT::ObtenClaseQT()
{
	return QSClaseQT;
}
void QSiscomObjetosQT::PonNombreObjeto(QString pQSNmbObjeto)
{
	QSNmbObjeto=pQSNmbObjeto;
}
void QSiscomObjetosQT::PonClaseQT(QString pQSClaseQT)
{
	QSClaseQT=pQSClaseQT;
}
void QSiscomObjetosQT::PonIdObjeto(QString pQSIdObjeto)
{
	QSIdObjeto=pQSIdObjeto;
}
QSiscomSeguridad3::QSiscomSeguridad3(QWidget *pQWPantalla):
		   chrPtrNmbClase(pQWPantalla->className())
{
printf("Cargando El Sistema De Seguridad Version 3\nPara la Pantalla %s \n",
		pQWPantalla->className());

	QSiscomArchivoUI::ObtenControles(pQWPantalla,
					 QSLObjQPantalla);
	/*
	QSiscomArchivoUI::ImprimeObjetos(QSLObjQPantalla,

					 "QSiscomSeguridad2::QSiscomSeguridad3");
	QSiscomArchivoUI::ImprimeObjetos(QSLObjQBaseDatos,
					 "QSiscomSeguridad2::QSiscomSeguridad3");
					 */
/*
	ObtenControlesBD(pQWPantalla->className());
	AsignaPropiedadesBDAPantalla();

*/


}
QSiscomSeguridad3::QSiscomSeguridad3(QWidget *pQWPantalla,
				     CSISCOMDatComunicaciones *pCSisDatCom,
				     const char *pchrPtrAplicacion,
				     const char *pchrPtrFirma,
				     const char *pchrPtrRutaIconos):
				     CSisDatCom(pCSisDatCom),
				     chrPtrFirma(pchrPtrFirma),
				     chrPtrAplicacion(pchrPtrAplicacion),
				     chrPtrRutaIconos(pchrPtrRutaIconos)
{

	printf("Cargando El Sistema De Seguridad Version 3\nPara la Pantalla %s \nAplicacion:%s\nPerfil:%s\n",
		pQWPantalla->className(),
		pchrPtrAplicacion,
		pchrPtrFirma);

	QSiscomArchivoUI::ObtenControles(pQWPantalla,
					 QSLObjQPantalla);

	/*
	QSiscomArchivoUI::ImprimeObjetos(QSLObjQPantalla,
					 "QSiscomSeguridad2::QSiscomSeguridad3");
	*/
	ObtenControlesBD(pQWPantalla->className());
	/*
	QSiscomArchivoUI::ImprimeObjetos(QSLObjQBaseDatos,
					 "QSiscomSeguridad2::QSiscomSeguridad3");
					 */
	AsignaPropiedadesBDAPantalla();	
}
QSiscomSeguridad3::QSiscomSeguridad3(const QObjectList &pQOLControles,
				     CSISCOMDatComunicaciones *pCSisDatCom,
				     const QStringList &pQSLPropBloqueadas,
				     const char *pchrPtrAplicacion,
				     const char *pchrPtrNmbPantalla):
				   CSisDatCom(pCSisDatCom),
		   QSLBloqueaPropiedades(pQSLPropBloqueadas)
{
QSiscomConsultaObjetos lQSCnsObjetos(pCSisDatCom,
				     pQOLControles,
				     pchrPtrAplicacion,
				     pchrPtrNmbPantalla);
QSLObjQBaseDatos=lQSCnsObjetos.ObtenObjetosDeLaForma();

AsignaControlesBDAPantalla(pQOLControles);
}

bool QSiscomSeguridad3::RegistraUsuarioYFirma(CSISCOMDatComunicaciones *pCSisDatCom,
					      const char *pchrPtrAplicacion,
					      const char *pchrPtrPerfil,
					      const char *pchrPtrNombre,
					      const char *pchrPtrAPaterno,
					      const char *pchrPtrAMaterno,
					      const char *pchrPtrFirma,
					      const char *pchrPtrPassword,
					      const char *pchrPtrCPassword)
{

CQOGenericaServidorSiscom lCQOGSvrSiscom(pCSisDatCom,
					 "libRNConsultaGenericaSeguridad3.so",
					 "RNConsultaGenerica",
					 10);
			lCQOGSvrSiscom.AnexaRegistro("%s%s%s%s%s%s%s%s%s%s",
						     "RegistraUsuarioDeUnaAplicacion",
						     pchrPtrAplicacion,
						     pchrPtrPerfil,	
						     pchrPtrNombre,
						     pchrPtrAPaterno,
						     pchrPtrAPaterno,
						     pchrPtrAMaterno,
						     pchrPtrFirma,
						     pchrPtrPassword,
						     pchrPtrCPassword);
			lCQOGSvrSiscom.EjecutaEnvioSvrSISCOM();
			lCQOGSvrSiscom.ObtenRespuesta();
		return lCQOGSvrSiscom.ObtenCampo(0,0).toInt();

}
bool QSiscomSeguridad3::ValidaUsuario(CSISCOMDatComunicaciones *pCSisDatCom,
				      const char *pchrPtrAplicacion)
{
CQOGenericaServidorSiscom lCQOGSvrSiscom(pCSisDatCom,
					 "libRNConsultaGenericaSeguridad3.so",
					 "RNConsultaGenerica",
					 4);
			lCQOGSvrSiscom.AnexaRegistro("%s%s%s%s",
						     "ValidaFirma",
						     pCSisDatCom->ObtenUsuario(),
						     pCSisDatCom->ObtenPassword(),
						     pchrPtrAplicacion);
			lCQOGSvrSiscom.EjecutaEnvioSvrSISCOM();
			lCQOGSvrSiscom.ObtenRespuesta();
		return lCQOGSvrSiscom.ObtenCampo(0,0).toInt();

}
bool QSiscomSeguridad3::ValidaUsuario(CSISCOMDatComunicaciones *pCSisDatCom,
				      const char *pchrPtrAplicacion,
				      char *pchrPtrIdAplicacion)
{
CQOGenericaServidorSiscom lCQOGSvrSiscom(pCSisDatCom,
					 "libRNConsultaGenericaSeguridad3.so",
					 "RNConsultaGenerica",
					 4);
			lCQOGSvrSiscom.AnexaRegistro("%s%s%s%s",
						     "ValidaFirma",
						     pCSisDatCom->ObtenUsuario(),
						     pCSisDatCom->ObtenPassword(),
						     pchrPtrAplicacion);
			lCQOGSvrSiscom.EjecutaEnvioSvrSISCOM();
			lCQOGSvrSiscom.ObtenRespuesta();
			strcpy(pchrPtrIdAplicacion,(const char *)lCQOGSvrSiscom.ObtenCampo(1,0));
		return lCQOGSvrSiscom.ObtenCampo(0,0).toInt();

}
long QSiscomSeguridad3::ElUsuarioTieneElPerfil(CSISCOMDatComunicaciones *pCSisDatCom,
				      const char *pchrPtrAplicacion,
				      const char *pchrPtrPerfil)
{
CQOGenericaServidorSiscom lCQOGSvrSiscom(pCSisDatCom,
					 "libRNConsultaGenericaSeguridad3.so",
					 "RNConsultaGenerica",
					 4);
			lCQOGSvrSiscom.AnexaRegistro("%s%s%s%s",
						     "ValidaPerfil",
						     pCSisDatCom->ObtenUsuario(),
						     pchrPtrAplicacion,
						     pchrPtrPerfil);
			lCQOGSvrSiscom.EjecutaEnvioSvrSISCOM();
			lCQOGSvrSiscom.ObtenRespuesta();
		return lCQOGSvrSiscom.ObtenCampo(0,0).toLong();

}
CQPerfiles *QSiscomSeguridad3::ObtenPerfilesDeLaAplicacion(CSISCOMDatComunicaciones *pCSisDatCom)
{
CQPerfiles *lCQPerfiles=new CQPerfiles(pCSisDatCom,
		       pCSisDatCom->ObtenIdAplicacion());

	return lCQPerfiles;
}
void QSiscomSeguridad3::AsignaControlesBDAPantalla(const QObjectList &pQOLControles)
{
QSiscomObjetosQT *lQSObjQT,
		 *lQSObjQTBase;
QSiscomListaPropBD lQSLPBDDat;
QSiscomPropiedadesBD *lQSPBDObj;
QObjectListIt lQOLIDat(pQOLControles);
QObject *lQOControl;
	    while((lQOControl=lQOLIDat.current()))
	    {
            	for(lQSObjQTBase=QSLObjQBaseDatos.first();
			lQSObjQTBase;
			lQSObjQTBase=QSLObjQBaseDatos.next())
		    if(*lQSObjQTBase==lQOControl)
		    AsignaPropiedadesBDAlObjeto(lQSObjQTBase,lQOControl);
	       ++lQOLIDat;
	     }

}
void QSiscomSeguridad3::AsignaControlesBDAPantalla(CSISCOMDatComunicaciones *pCSisDatCom)
{
	CSisDatCom=pCSisDatCom;	
	ObtenControlesBD(chrPtrNmbClase);
	AsignaPropiedadesBDAPantalla();

}
void QSiscomSeguridad3::AsignaControlesBDAPantalla(CSISCOMDatComunicaciones *pCSisDatCom,
						   const char *pchrPtrAplicacion,
						   const char *pchrPtrUsuario,
						   const char *pchrPtrRutaIconos)
{
	chrPtrRutaIconos=pchrPtrRutaIconos;
	chrPtrAplicacion=pchrPtrAplicacion;
	chrPtrFirma=pchrPtrUsuario;
	CSisDatCom=pCSisDatCom;	
	ObtenControlesBD(chrPtrNmbClase);
	AsignaPropiedadesBDAPantalla();

}
void QSiscomSeguridad3::ObtenControlesBD(const char *pchrPtrPantalla)
{
QSiscomConsultaObjetos *lQSCnsObj=new QSiscomConsultaObjetos(CSisDatCom,
							     chrPtrAplicacion,
							     pchrPtrPantalla,
							     "",
							     chrPtrFirma);
QSLObjQBaseDatos=lQSCnsObj->ObtenObjetosDeLaForma();
delete lQSCnsObj;
}
void QSiscomSeguridad3::AsignaPropiedadesBDAPantalla()
{
QSiscomObjetosQT *lQSObjQT,
		 *lQSObjQTBase;
QSiscomListaPropBD lQSLPBDDat;
QSiscomPropiedadesBD *lQSPBDObj;
	for(lQSObjQT=QSLObjQPantalla.first();
	    lQSObjQT;
	    lQSObjQT=QSLObjQPantalla.next())
	{
	    for(lQSObjQTBase=QSLObjQBaseDatos.first();
		lQSObjQTBase;
		lQSObjQTBase=QSLObjQBaseDatos.next())
	    {
		if(*lQSObjQT==lQSObjQTBase)
		  AsignaPropiedadesBDAlObjeto(lQSObjQTBase,lQSObjQT);
	    } 
	}



}
int QSiscomSeguridad3::ValidaPropiedadesBloqueadas(const char *pchrPtrPropiedad)
{
int lintContador;
	for(lintContador=0;
	    lintContador<QSLBloqueaPropiedades.size();
	    lintContador++)
	 if(QSLBloqueaPropiedades[lintContador]==pchrPtrPropiedad)
	 return 0;

	return 1; 


}
void QSiscomSeguridad3::AsignaPropiedadesBDAlObjeto(QSiscomObjetosQT *pQSObjQTBDatos,
						    QObject *pQOControl)
{
QSiscomPropiedadesBD *lQSPropBDDat;
QSiscomListaPropBD lQSLPropBD=pQSObjQTBDatos->ObtenPropiedades();
QString lQSNmbPropiedad;
	
	for(lQSPropBDDat=lQSLPropBD.first();
	    lQSPropBDDat;
	    lQSPropBDDat=lQSLPropBD.next())
	if((lQSNmbPropiedad=lQSPropBDDat->ObtenNombrePropiedad())!="name" &&
	    lQSNmbPropiedad!="iconSet"  && 
	    ValidaPropiedadesBloqueadas((const char *)lQSNmbPropiedad))
        {
	     	     pQOControl->setProperty((const char *)lQSPropBDDat->ObtenNombrePropiedad(),
				     lQSPropBDDat->ObtenValorPropiedad());
	}
	else	
	if(lQSNmbPropiedad=="iconSet")
	{
	  if(chrPtrRutaIconos)
	  pQOControl->setProperty(lQSNmbPropiedad,
				  QIconSet(QPixmap(QString(chrPtrRutaIconos) +
					  "/"	 	   +
					  lQSPropBDDat->ObtenValorPropiedad())));
	}
}
void QSiscomSeguridad3::AsignaPropiedadesBDAlObjeto(QSiscomObjetosQT *pQSObjQTBDatos,
						    QSiscomObjetosQT *pQSObjQTPantalla)
{
QObject *lQOControl=pQSObjQTPantalla->ObtenControlPantalla();
QSiscomPropiedadesBD *lQSPropBDDat;
QSiscomListaPropBD lQSLPropBD=pQSObjQTBDatos->ObtenPropiedades();
QString lQSNmbPropiedad;
	for(lQSPropBDDat=lQSLPropBD.first();
	    lQSPropBDDat;
	    lQSPropBDDat=lQSLPropBD.next())
	if((lQSNmbPropiedad=lQSPropBDDat->ObtenNombrePropiedad())!="name" &&
	    lQSNmbPropiedad!="iconSet" &&
	    lQSNmbPropiedad!="font")
        {
	     lQOControl->setProperty((const char *)lQSPropBDDat->ObtenNombrePropiedad(),
				     lQSPropBDDat->ObtenValorPropiedad());
	}
	else	
	{
	if(lQSNmbPropiedad=="iconSet")
	{
	  if(chrPtrRutaIconos)
	  lQOControl->setProperty(lQSNmbPropiedad,
				  QIconSet(QPixmap(QString(chrPtrRutaIconos) +
					  "/"	 	   +
					  lQSPropBDDat->ObtenValorPropiedad())));
	}
	if(lQSNmbPropiedad=="font")
	 lQOControl->setProperty(lQSNmbPropiedad,
			 	 gQFTipoLetra); 
	}
}

/*    La manera en la que se deberan formar los datos a enviar sera la siguiente 
      idAplicacion
      NmbPantalla
      idPerfil       Para el primer caso se debe asignar a un perfil por default
      NmbArchivo
      idControl
      idPropiedad
      ValorPropiedad
      
      
      
*/
QSiscomRegistraObjetos::QSiscomRegistraObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
					       QSiscomListaContXForma pQSLContXForma,
					       long plngIdAplicacion,
					       int pintIdPerfil):
		        CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNAltaGenericaSeguridad3.so",
						  "RNAltaGenerica",
					          8),
			QSLContXForma(pQSLContXForma),
			lngIdAplicacion(plngIdAplicacion),
			intIdPerfil(pintIdPerfil)



{
	FormaRegistrosRegistro("RegistraObjetosDeLaAplicacion");
	EjecutaEnvioSvrSISCOM();

}

QSiscomRegistraObjetos::QSiscomRegistraObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
					       QSiscomListaContXForma pQSLContXForma,
					       long plngIdAplicacion,
					       int pintIdPerfil,
					       const char *pchrPtrCadRegistro):
		        CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNAltaGenericaSeguridad3.so",
						  "RNAltaGenerica",
					          8),
			QSLContXForma(pQSLContXForma),
			lngIdAplicacion(plngIdAplicacion),
			intIdPerfil(pintIdPerfil)



{
	FormaRegistrosRegistro(pchrPtrCadRegistro);
	EjecutaEnvioSvrSISCOM();

}
QSiscomRegistraObjetos::QSiscomRegistraObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
					       QSiscomListaContXForma pQSLContXForma,
					       long plngIdAplicacion,
					       const char *pchrPtrCadRegistro):
		        CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNAltaGenericaSeguridad3.so",
						  "RNAltaGenerica",
					          8),
			QSLContXForma(pQSLContXForma),
			lngIdAplicacion(plngIdAplicacion),
			intIdPerfil(0)
			



{
	FormaRegistrosRegistro(pchrPtrCadRegistro);
	EjecutaEnvioSvrSISCOM();

}


void QSiscomRegistraObjetos::FormaRegistrosRegistro(const char *pchrPtrCadRegistro)
{
int lintContador;
int lintNFormas=QSLContXForma.count();
QSiscomObjetosSeguridad *lQSisObjSeguridad;
QSiscomListaObjQ lQSLObjCont;
QSiscomObjetosQT *lQSObjQtDat;
QSiscomPropiedadesBD *lQSPropXObj;
QSiscomListaPropBD lQSLPropiedades;
const char *lchrPtrValorPropiedad;
const char *lchrPtrAlgo;
printf("El perfil:%d\n",intIdPerfil);
	AnexaRegistro("%s%s%s%s%s%s%s%s",
		      pchrPtrCadRegistro,
		      "",	
		      "",	
		      "",	
		      "",	
		      "",	
		      "",	
		      "");
	AnexaRegistro("%s%s%s%s%s%s%s%s",
		      (const char *)QString().sprintf("%ld",lngIdAplicacion),
		      "",
		      "",
		      "",
                      "",
                      "",
                      "",
                      "");
		      
		
	  for(lQSisObjSeguridad=QSLContXForma.first();
	      lQSisObjSeguridad;
	      lQSisObjSeguridad=QSLContXForma.next())
	  {
	  /*
		printf("QSiscomRegistraObjetos::FormaRegistrosRegistro:AnexaRegistro:%s,%s\n",
				 (const char *)lQSisObjSeguridad->ObtenIdForma() ,
				 (const char *)lQSisObjSeguridad->ObtenNombreForma() );
	
	*/		
	        AnexaRegistro("%s%s%s%s%s%s%s%s",
			      "",
				!strcmp(pchrPtrCadRegistro,
					"ActualizaObjetosDeLaAplicacion") ? 
				 (const char *)lQSisObjSeguridad->ObtenIdForma() :
				 (const char *)lQSisObjSeguridad->ObtenNombreForma() ,
			      (const char *)QString().sprintf("%d",intIdPerfil),		
			      "Falta El Archivo",		
			      "",		
			      "",		
			      "",		
			      "");
		lQSLObjCont=lQSisObjSeguridad->ObtenObjetosFiltrados();
		for(lQSObjQtDat=lQSLObjCont.first();
		    lQSObjQtDat;
		    lQSObjQtDat=lQSLObjCont.next())
		{
		   lQSLPropiedades=lQSObjQtDat->ObtenPropiedades(); 
		   /*
		printf("QSiscomRegistraObjetos::FormaRegistrosRegistro:AnexaRegistro:[IdObjeto %s,%s,%s]\n",
			      (const char *)lQSObjQtDat->ObtenNombreObjeto(),
			      (const char *)lQSObjQtDat->ObtenIdObjeto(),
			      (const char *)lQSObjQtDat->ObtenClaseQT());
			      */
		AnexaRegistro("%s%s%s%s%s%s%s%s",
			      "",
			      "",
			      "",		
			      "",		
			      (lchrPtrAlgo=(const char *)lQSObjQtDat->ObtenIdObjeto()) ? lchrPtrAlgo: "Nulo" ,		
			      "",		
			      "",		
			      "");

		  for(lQSPropXObj=lQSLPropiedades.first();
		      lQSPropXObj;
		      lQSPropXObj=lQSLPropiedades.next())
		  {
/*
		printf("QSiscomRegistraObjetos::FormaRegistrosRegistro:AnexaRegistro:Propiedades[%s,%s]\n",
			      (const char *)lQSPropXObj->ObtenIdPropiedadBD(),		
			      (const char *)lQSPropXObj->ObtenValorPropiedad());
*/
		   AnexaRegistro("%s%s%s%s%s%s%s%s",
			      "",
			      "",
			      "",		
			      "",		
			      "",		
			      (const char *)lQSPropXObj->ObtenIdPropiedadBD(),		
			      (lchrPtrValorPropiedad=(const char *)lQSPropXObj->ObtenValorPropiedad()) ? 
			       lchrPtrValorPropiedad:"Nulo",		
			      "");
		    
		}
	     	 
		 	printf("Se asigno \n"); 
		AnexaRegistro("%s%s%s%s%s%s%s%s",
			      "",
			      "",
			      "",		
			      "",		
			      "",		
			      "",
			      "",
			      "");
		
	     }	
			
		AnexaRegistro("%s%s%s%s%s%s%s%s",
			      "",
			      "",
			      "",		
			      "",		
			      "",		
			      "",
			      "",
			      "");

	  }
		

}

QSiscomConsultaObjetos::QSiscomConsultaObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
					       const char *pchrPtrNmbAplicacion,
					       const char *pchrPtrNmbForma,
					       const char *pchrPtrNmbPerfil):
			CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNConsultaGenericaSeguridad3.so",
						  "RNConsultaGenerica",
						   4),
			chrPtrAplicacion(pchrPtrNmbAplicacion),
			chrPtrClase(pchrPtrNmbForma),
			chrPtrPerfil(pchrPtrNmbPerfil),
		        chrPtrIdPantalla(0)	
{
	AnexaRegistro("%s%s%s%s",
		      "ConsultaObjetosDeLaForma",
		      pchrPtrNmbAplicacion,
		      pchrPtrNmbPerfil,
		      pchrPtrNmbForma);
	EjecutaEnvioSvrSISCOM(); 
	ObtenRespuesta();
	CreaListaDeObjetos();
	
		      

}
QSiscomConsultaObjetos::QSiscomConsultaObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
					       const char *pchrPtrNmbAplicacion,
					       const char *pchrPtrNmbForma,
					       const char *pchrPtrNmbPerfil,
					       const char *pchrPtrFirma):
			CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNConsultaGenericaSeguridad3.so",
						  "RNConsultaGenerica",
						   5),
			chrPtrAplicacion(pchrPtrNmbAplicacion),
			chrPtrClase(pchrPtrNmbForma),
			chrPtrPerfil(pchrPtrNmbPerfil),
		        chrPtrIdPantalla(0)	
{
	AnexaRegistro("%s%s%s%s%s",
		      "ConsultaObjetosDeLaForma",
		      pchrPtrNmbAplicacion,
		      pchrPtrNmbPerfil,
		      pchrPtrNmbForma,
		      pchrPtrFirma);
	EjecutaEnvioSvrSISCOM(); 	
	ObtenRespuesta();
	CreaListaDeObjetos();
}
QSiscomConsultaObjetos::QSiscomConsultaObjetos(CSISCOMDatComunicaciones *pCSisDatCom,
						const QObjectList &pQOLControles,
					       const char *pchrPtrAplicacion,
					       const char *pchrPtrPantalla):
				            CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNConsultaGenericaSeguridad3.so",
						  "RNConsultaGenerica",
						   5)
{
QObjectListIt lQOLIDat(pQOLControles);
QObject *lQOControl;
		AnexaRegistro("%s%s%s%s%s",
			      "ConsultaObjetosXNombre",
			       pchrPtrAplicacion,
			       "",
			       pCSisDatCom->ObtenUsuario(),
			       pchrPtrPantalla);
		 while((lQOControl=lQOLIDat.current()))
		 {
		 AnexaRegistro("%s%s%s%s%s",
			       "",
			       "",
			       "",
			       "",
			       lQOControl->name());
		  ++lQOLIDat;
		}
		EjecutaEnvioSvrSISCOM();
		ObtenRespuesta();
		CreaListaDeObjetos();
}
									
					       
QSiscomConsultaObjetos::QSiscomConsultaObjetos(CSISCOMDatComunicaciones *pCSisDatCom):
			CQOGenericaServidorSiscom(pCSisDatCom,
						  "libRNConsultaGenericaSeguridad3.so",
						  "RNConsultaGenerica",
						   2),
		        chrPtrIdPantalla(0)	
{
	AnexaRegistro("%s%s",
		      "ConsultaObjetosEnBD",
		      "Nada");
	EjecutaEnvioSvrSISCOM(); 
	ObtenRespuesta();
	CreaListaDeObjetos();
	
		      

}
/* Para generalizar esta clase y que pueda leer de cualquier lado la informacion 
   de los objetos se debera hacer que se cree una lista de objetos del tipo Registro
   para que en este caso se lean de servidor, pero que pueda ser que se lean 
  del disco o socket directo etc.
*/
void QSiscomConsultaObjetos::PonIdPantalla(const char *pchrPtrIdPantalla)
{
	chrPtrIdPantalla=pchrPtrIdPantalla;
}
void QSiscomConsultaObjetos::CreaListaDeObjetos()
{
QStringList lQSLRegistro;
	SiguienteRegistro(lQSLRegistro);
	/*
	printf("%s %s %s %s %s %s %s %s %s %s\n",
		(const char *)lQSLRegistro[0],
		(const char *)lQSLRegistro[1],
		(const char *)lQSLRegistro[2],
		(const char *)lQSLRegistro[3],
		(const char *)lQSLRegistro[4],
		(const char *)lQSLRegistro[5],
		(const char *)lQSLRegistro[6],
		(const char *)lQSLRegistro[7],
		(const char *)lQSLRegistro[8],
		(const char *)lQSLRegistro[9]);
	*/
		while(!SiguienteRegistro(lQSLRegistro))
		    QPLContXForma.append(CreaObjeto(lQSLRegistro));
}

QSiscomObjetosQT *QSiscomConsultaObjetos::CreaObjeto(QStringList &pQSLRegistro)
{
const char *lchrPtrClase=(const char *)pQSLRegistro[8];
QSiscomObjetosQT *lQSObjQT=new QSiscomObjetosQT;
const char *lchrPtrNmbObjeto;
	
		do
		{
		    if(pQSLRegistro[9]=="name")
		    {
		    lchrPtrNmbObjeto=(const char *)pQSLRegistro[7];
	            lQSObjQT->PonNombreObjeto(pQSLRegistro[7]);
		    lQSObjQT->PonIdObjeto(pQSLRegistro[0]);
		    lQSObjQT->PonClaseQT(pQSLRegistro[8]);
		    }

		    lQSObjQT->AnexaPropiedad(pQSLRegistro[1],
					     (const char *)pQSLRegistro[9],
					     pQSLRegistro[7]);
		}while(!SiguienteRegistro(pQSLRegistro) &&
		        pQSLRegistro[9]!="IniciaControl");
	return lQSObjQT;
}
QSiscomListaObjQ QSiscomConsultaObjetos::ObtenObjetosDeLaForma()
{
		return QPLContXForma;
}					       
QSiscomObjetosSeguridad *QSiscomConsultaObjetos::ObtenObjetosSeguridad()
{
	return new QSiscomObjetosSeguridad(QPLContXForma,
				       chrPtrAplicacion,
				       "Clase",
				       chrPtrClase,
				       chrPtrIdPantalla); 
				       		

}
QSiscomPerfilBD::QSiscomPerfilBD(const char *pchrPtrIdPerfil,
				 const char *pchrPtrIdAplicacion,
				 const char *pchrPtrNmbPerfil,
				 const char *pchrPtrDscPerfil):
				chrPtrIdPerfil(pchrPtrIdPerfil),	
				chrPtrIdAplicacion(pchrPtrIdAplicacion),
				chrPtrNmbPerfil(pchrPtrNmbPerfil),
				chrPtrDscPerfil(pchrPtrDscPerfil)
{

}
const char *QSiscomPerfilBD::ObtenIdPerfil()
{
	return chrPtrIdPerfil;
}
int QSiscomPerfilBD::operator==(const char *pchrPtrIdPerfil)
{
	printf("strcmp(\"%s\",\"%s\");\n",chrPtrIdPerfil,pchrPtrIdPerfil);
	return !strcmp(chrPtrIdPerfil,pchrPtrIdPerfil);
}
const char *QSiscomPerfilBD::ObtenIdAplicacion()
{
	return chrPtrIdAplicacion;
}
const char *QSiscomPerfilBD::ObtenNmbPerfil()
{
	return chrPtrNmbPerfil;
}
const char *QSiscomPerfilBD::ObtenDscPerfil()
{
	return chrPtrDscPerfil;
}
QSiscomPantallaBD::QSiscomPantallaBD(const char *pchrPtrIdAplicacion,
				     const char *pchrPtrIdPantalla,
				     const char *pchrPtrNmbClase,
				     const char *pchrPtrNmbArchivo):
			chrPtrIdPantalla(pchrPtrIdPantalla),
		        chrPtrIdAplicacion(pchrPtrIdAplicacion),
			chrPtrNmbClase(pchrPtrNmbClase),
			chrPtrArchivo(pchrPtrNmbArchivo)
{


}
const char *QSiscomPantallaBD::ObtenIdPantalla()
{
	return chrPtrIdPantalla;
}
const char *QSiscomPantallaBD::ObtenNmbClase()
{
	return chrPtrNmbClase;
}
const char *QSiscomPantallaBD::ObtenArchivo()
{
	return chrPtrArchivo;
}
const char *QSiscomPantallaBD::ObtenIdAplicacion()
{
	return chrPtrIdAplicacion;
}

QSiscomPantallaConControlesBD::QSiscomPantallaConControlesBD(QSiscomPantallaBD *pQSPantallaBD):
			       QSPantallaBD(pQSPantallaBD)
{


}
QSiscomPantallaBD *QSiscomPantallaConControlesBD::ObtenPantallaBD()
{
	return QSPantallaBD;
}
QSiscomConsultaAplicacion::QSiscomConsultaAplicacion(CSISCOMDatComunicaciones *pCSisDatCom,
						     const char *pchrPtrIdAplicacion,
						     const char *pchrPtrNmbAplicacion): 
			       CQOGenericaServidorSiscom(pCSisDatCom,
							 "libRNConsultaGenericaSeguridad3.so",
							 "RNConsultaGenerica",
							 2),
				chrPtrIdAplicacion(pchrPtrIdAplicacion),
				CSDatCom(pCSisDatCom),
				chrPtrNmbAplicacion(pchrPtrNmbAplicacion)
{
	AnexaRegistro("%s%s",
		      "ConsultaPantallasAplicacion",
		      pchrPtrIdAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
	ConsultaPantallasBD();
}
QSiscomPantallaBD *QSiscomConsultaAplicacion::operator[](long plngIdPantalla)
{

}
QSiscomPantallaBD *QSiscomConsultaAplicacion::operator[](int pintNumPantalla)
{
	return ((QSiscomPantallaConControlesBD *)QSLPantallasBD.at(pintNumPantalla))->ObtenPantallaBD();
}
void QSiscomConsultaAplicacion::ConsultaPantallasBD()
{
QStringList lQSLRegistro;
QSiscomPantallaBD *lQSPantallaBD;
QSiscomConsultaObjetos *lQSCnsObj;
	while(!SiguienteRegistro(lQSLRegistro))
	{
	  printf("%s %s %s\n",
		(const char *)lQSLRegistro[0],
		(const char *)lQSLRegistro[1],
		(const char *)lQSLRegistro[2]);

	  	
	  lQSPantallaBD=new QSiscomPantallaBD(chrPtrIdAplicacion,
					      (const char *)lQSLRegistro[0],
					      (const char *)lQSLRegistro[1],
					      (const char *)lQSLRegistro[2]);
	/*	
	  En este punto se debe considerar que la consulta de la aplicacion,
	  implica solamente las pantallas, y los perfiles.
	  En una consulta posterior, se debe realizar la consulta de los objetos
	  de la aplicacion, ya que se haya seleccionado el perfil.
	 */
	  lQSCnsObj=new QSiscomConsultaObjetos(CSDatCom,
					       chrPtrNmbAplicacion,
					       lQSLRegistro[1],
					       ""); 

	  lQSCnsObj->PonIdPantalla((const char *)lQSLRegistro[0]);
	  //QSLContXForma.append(lQSCnsObj->ObtenObjetosSeguridad()); 
	  QSLPantallasBD.append(new QSiscomPantallaConControlesBD(lQSPantallaBD));
	}
}
const QSiscomListaPantallasBD &QSiscomConsultaAplicacion::ObtenPantallasBD()
{

	return QSLPantallasBD;
}
/*
const QSiscomListaContXForma &QSiscomConsultaAplicacion::ObtenPantallasYControles()
{
	return QSLContXForma;
} */



CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       QSiscomPerfilBD *pQSPerfilBD,
		       const char *pchrPtrIdPerfilRef):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNAltaGenericaSeguridad3.so",
				       "RNAltaGenerica",
					6),
		chrPtrIdPerfilRef(pchrPtrIdPerfilRef)
				       
{
	QSLPerfilesBD.append(pQSPerfilBD);
	CreaRegistrosEnvio();
	EjecutaEnvioSvrSISCOM();
}
CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       const char *pchrPtrIdAplicacion,
		       int ):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNConsultaGenericaSeguridad3.so",
				       "RNConsultaGenerica",
					2)
{
	AnexaRegistro("%s%s",
		      "ObtenPerfilesAplicacionConPantallas",
		      pchrPtrIdAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
	GeneraListaPerfiles();

}
		
CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       const char *pchrPtrIdAplicacion):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNConsultaGenericaSeguridad3.so",
				       "RNConsultaGenerica",
					2),
	      chrPtrIdAplicacion(pchrPtrIdAplicacion)
	     	
{
	AnexaRegistro("%s%s",
		      "ObtenPerfilesAplicacion",
		      pchrPtrIdAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
	GeneraListaPerfiles();
}
CQPerfiles::~CQPerfiles()
{
	QSLPerfilesBD.clear();

}
QSiscomPerfilBD *CQPerfiles::operator[](int pintNRegistro)
{
	return QSLPerfilesBD.at(pintNRegistro);
}
QSiscomPerfilBD *CQPerfiles::operator[](const char *pchrPtrNmbPerfil)
{
 QSiscomPerfilBD *lQSPerfil;
	for(lQSPerfil=QSLPerfilesBD.first();
	    lQSPerfil;
	    lQSPerfil=QSLPerfilesBD.next())
	if(!strcmp(lQSPerfil->ObtenNmbPerfil(),pchrPtrNmbPerfil))
	 return lQSPerfil; 

	return 0;
}
void CQPerfiles::CreaRegistroEnvio(QSiscomPerfilBD *pQSPerfilBD)
{
	AnexaRegistro("%s%s%s%s%s%s",
		      "RegistraPerfiles",
		      pQSPerfilBD->ObtenIdPerfil(),
		      pQSPerfilBD->ObtenIdAplicacion(),
		      pQSPerfilBD->ObtenNmbPerfil(),
		      pQSPerfilBD->ObtenDscPerfil(),
		      chrPtrIdPerfilRef);
}
void CQPerfiles::CreaRegistrosEnvio()
{
int lintContador,
    lintNPerfiles=QSLPerfilesBD.count();
	for(lintContador=0;lintContador<lintNPerfiles;lintContador++)
	 CreaRegistroEnvio(QSLPerfilesBD.at(lintContador));

}
void CQPerfiles::GeneraListaPerfiles()
{
QStringList lQSLRegistro;
	while(!SiguienteRegistro(lQSLRegistro) &&
	       lQSLRegistro.size())
	   QSLPerfilesBD.append(new QSiscomPerfilBD((const char *)lQSLRegistro[0],
						      (const char *)lQSLRegistro[1],
						      (const char *)lQSLRegistro[2],
						      (const char *)lQSLRegistro[3]));
}
int CQPerfiles::CuantosPerfiles()
{
	return QSLPerfilesBD.count();
}

