#include <CfrmFirmaUsuario2.h>

#include <GeneralBibliotecaSeguridad3.h>
#include <CQSiscomCom.h>
#include <qfontdialog.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qfile.h>
#include <qmessagebox.h>

CfrmFirmaUsuario2::CfrmFirmaUsuario2(const char *pchrPtrNmbAplicacion,
				      QWidget* parent,
				      const char* name, 
				      bool modal, 
				      WFlags fl )
    : frmFirmaUsuario2( parent, name, modal, fl ),
    intLeyoArchivo(0),
    chrPtrNmbAplicacion(pchrPtrNmbAplicacion)
{
   LeeArchivoUsuarios();
   IniciaConfiguracion();
   ConectaSlots();
   exec();
   
}

CfrmFirmaUsuario2::~CfrmFirmaUsuario2()
{
}
void CfrmFirmaUsuario2::PonNombreAplicacion(const char *pchrPtrNmbAplicacion)
{
	chrPtrNmbAplicacion=pchrPtrNmbAplicacion;
}
void CfrmFirmaUsuario2::ConectaSlots()
{
	connect(QLEComboUsuarios,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPassword()));
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDirServidor()));
	connect(QLEComboServidores,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPtoCom()));
	connect(QLEPtoCom,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoTipoLetra()));
	connect(QPBSeleccionaL,
		SIGNAL(clicked()),
		SLOT(SlotTipoLetra()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	
}
void CfrmFirmaUsuario2::closeEvent(QCloseEvent *)
{
	QMessageBox::information(this,
				 getenv("Aplicacion"),
				 "Imposible Cerrar La Ventana");

}
void CfrmFirmaUsuario2::SlotAceptar()
{
CQSisUsuario *lCQSUsuario;
char lchrArrIdAplicacion[20];
   CSisDatCom=new CSISCOMDatComunicaciones(QLEPtoCom->text().toInt(),
		   			   (const char *)QLEComboServidores->text(),
					   (const char *)QLEComboUsuarios->text(),
					   (const char *)QLEPassword->text());
	if(QSiscomSeguridad3::ValidaUsuario(CSisDatCom,
					 chrPtrNmbAplicacion,
					 lchrArrIdAplicacion))
	{
	  lCQSUsuario=CQSUsuarios[CSisDatCom->ObtenUsuario()];
	  if(lCQSUsuario)
	 gQFTipoLetra.fromString(lCQSUsuario->ObtenTipoLetra());
	  chrPtrIdAplicacion=strdup(lchrArrIdAplicacion);
	  CSisDatCom->PonIdAplicacion(chrPtrIdAplicacion);
	 done(1);
	}
	else
	{
	 switch( QMessageBox::warning(this,"SISCOM Tiendas",
				      "Usuario o Password Incorrecto",
				      "Aceptar",
				      "Cancelar",
				      	0,
					0,
					1 ) )
	 {
		     case 0: 
			     PasaFocoControl(QLEComboUsuarios);
		     break;
		     case 1: 
		     break;
	  }
	}
	
}
CSISCOMDatComunicaciones *CfrmFirmaUsuario2::ObtenDatosDeComunicaciones()
{
	EscribeArchivo();
	return CSisDatCom;
}
void CfrmFirmaUsuario2::SlotPasaFocoTipoLetra()
{
	QPBSeleccionaL->setEnabled(true);
	PasaFocoControl(QPBSeleccionaL);
	ValidaServidor();
}
void CfrmFirmaUsuario2::ValidaServidor()
{
CQSisServidor *lCQSServidor;
	if(!CQSServidores.count())
	 CQSServidores << new CQSisServidor((const char *)QLEComboServidores->text(),
			 		    QLEPtoCom->text().toInt());
	else
	{
	    lCQSServidor=new CQSisServidor((const char *)QLEComboServidores->text(),
			    		    QLEPtoCom->text().toInt());
	    if(!(CQSServidores==lCQSServidor))
	      CQSServidores << lCQSServidor;
	}
}
void CfrmFirmaUsuario2::SlotTipoLetra()
{
bool lblRegreso;
	  QFTipoLetra=QFontDialog::getFont(&lblRegreso);
	printf("%s\n",(const char *)QFTipoLetra.toString()); 
	QPBAceptar->setEnabled(true);
	PasaFocoControl(QPBAceptar);
	ValidaUsuario();
}
void CfrmFirmaUsuario2::ValidaUsuario()
{
CQSisUsuario *lCQSUsuario;
		printf("CfrmFirmaUsuario2::ValidaUsuario:%s \n",(const char *)QFTipoLetra.toString());
	if(!CQSUsuarios.count())
	 CQSUsuarios << new CQSisUsuario((const char *)QLEComboUsuarios->text(),
						(const char *)QFTipoLetra.toString(),
						QFTipoLetra.pointSize(),
						QFTipoLetra.bold());
		else
		{
			lCQSUsuario=new CQSisUsuario((const char *)QLEComboUsuarios->text(),
						(const char *)QFTipoLetra.toString(),
					QFTipoLetra.pointSize(),
					QFTipoLetra.bold());
		if(!(CQSUsuarios==lCQSUsuario))
		 CQSUsuarios << lCQSUsuario;
	}
}
void CfrmFirmaUsuario2::SlotPasaFocoPtoCom()
{
CQSisServidor *lCQSServidor;
	if((lCQSServidor=CQSServidores[QCBSvrRN->currentItem()]))
	 QLEPtoCom->setText(QString().sprintf("%d",lCQSServidor->ObtenPtoCom()));
	QLEPtoCom->setEnabled(true);
	PasaFocoControl(QLEPtoCom);
}
void CfrmFirmaUsuario2::SlotPasaFocoPassword()
{
	QLEPassword->setEnabled(true);
	PasaFocoControl(QLEPassword);
}
void CfrmFirmaUsuario2::SlotPasaFocoDirServidor()
{
	QCBSvrRN->setEnabled(true);
	PasaFocoControl(QLEComboServidores);
}
void CfrmFirmaUsuario2::IniciaConfiguracion()
{
	QLEComboUsuarios=ColocaLineEditAlCombo(QCBUsuarios,"QLEComboUsuarios");
	QLEComboServidores=ColocaLineEditAlCombo(QCBSvrRN,"QLEComboServidores");
	PasaFocoControl(QLEComboUsuarios);
}
void CfrmFirmaUsuario2::MuestraServidores()
{
CQSisServidor *lCQSServidor;
	CQSLArchivoConf.ObtenServidores(CQSServidores);
	for(lCQSServidor=CQSServidores.first();
	    lCQSServidor;
	    lCQSServidor=CQSServidores.next())
	  QCBSvrRN->insertItem(lCQSServidor->ObtenDirIpSvr());
}
void CfrmFirmaUsuario2::MuestraUsuarios()
{
CQSisUsuario *lCQUsuario;

	CQSLArchivoConf.ObtenUsuarios(CQSUsuarios);
	for(lCQUsuario=CQSUsuarios.first();
	    lCQUsuario;
	    lCQUsuario=CQSUsuarios.next())
	 QCBUsuarios->insertItem(lCQUsuario->ObtenFirma());


}
void CfrmFirmaUsuario2::MuestraContenido()
{
	MuestraServidores();
	MuestraUsuarios();
}
void CfrmFirmaUsuario2::LeeArchivoUsuarios()
{
QFile lQFArchConf(QString().sprintf("%s/.ConfiguracionSiscom.xml",getenv("HOME")));

    if(lQFArchConf.exists())
    {
	intLeyoArchivo=1;
	QXmlInputSource lQXISource(&lQFArchConf);
	QXmlSimpleReader lQXSReader;
	lQXSReader.setContentHandler(&CQSLArchivoConf);
	lQXSReader.parse(lQXISource);
	MuestraContenido();
	HabilitaDesHabilitaControles("%W1%W1",
				     QPBSeleccionaL,
				     QPBAceptar);
    }
}
void CfrmFirmaUsuario2::EscribeArchivo()
{
QString lQSArchivo,
	lQSPaso;
QFile lQFEscribe(QString().sprintf("%s/.ConfiguracionSiscom.xml",getenv("HOME")));
      lQFEscribe.open(IO_WriteOnly);
QTextStream lQTSEscribe(&lQFEscribe);
CQSisServidor *lCQSServidor;
CQSisUsuario *lCQSUsuario;

       	lQSArchivo=QString().sprintf("<Siscom Sistema=\"%s\">\n",chrPtrNmbAplicacion); 
	for(lCQSServidor=CQSServidores.first();
	    lCQSServidor;
	    lCQSServidor=CQSServidores.next())
	{
	CreaServidor("SISCOM Tiendas",
		     lCQSServidor->ObtenDirIpSvr(),
		     lCQSServidor->ObtenPtoCom(),
		     lQSPaso);
	lQSArchivo+=lQSPaso+"\n";
	}
	for(lCQSUsuario=CQSUsuarios.first();
	    lCQSUsuario;
	    lCQSUsuario=CQSUsuarios.next())
	{
	CreaUsuario(lCQSUsuario->ObtenFirma(),
		    lCQSUsuario->ObtenTipoLetra(),
		    lCQSUsuario->ObtenTamanoLetra(),
		    lCQSUsuario->ObtenNegrita(),
		    lQSPaso);
	lQSArchivo+=lQSPaso + "\n";
	}
	lQSArchivo+=QString("\n</Siscom>");
	lQTSEscribe << lQSArchivo;
     lQFEscribe.close();

}
void CfrmFirmaUsuario2::CreaServidor(const char *pchrPtrNombreSvr,
				      const char *pchrPtrDirIpSvr,
				      int pintPtoCom,
				      QString &pQSDatos)
{
	pQSDatos=QString("\t<Servidor Nombre=\"") + pchrPtrNombreSvr   + "\">" +
		 "\n\t\t"  +
		 "<Direccion Dato=\"" + pchrPtrDirIpSvr   + "\"/>" +
		 "\n\t\t"  +
		 "<Puerto Dato=\""    + QString().sprintf("%d",pintPtoCom) + "\"/>" + 
		 "\n\t" +
		 "</Servidor>";
}
void CfrmFirmaUsuario2::CreaUsuario(const char *pchrPtrUsuario,
				    const char *pchrPtrTipoLetra,
				    int pintTamanoLetra,
				    int pintNegrita,
				    QString &pQSUsuario)
{
	printf("CfrmFirmaUsuario2::CreaUsuario:%s\n",pchrPtrTipoLetra);
	pQSUsuario=QString("\t<Usuario Firma=\"") + pchrPtrUsuario           + "\">"  +
		   "\n\t\t"                                                           +
		   "<Letra Tipo=\""           + pchrPtrTipoLetra         + "\">"  +
		   "\n\t\t\t"							      +
		   "<Tamano Dato=\""        + QString().sprintf("%d",pintTamanoLetra) + "\"/>" +
		   "\n\t\t\t"							      +
		   "<Negrita Dato=\""       + QString().sprintf("%d",pintNegrita)     + "\"/>" +
		   "\n\t\t"							      +
		   "</Letra>"                                                     +
		   "\n\t"							      +
		   "</Usuario>" ;
}
const char *CfrmFirmaUsuario2::ObtenIdAplicacion()
{
	return chrPtrIdAplicacion;
}
CQSisServidor::CQSisServidor(const char *pchrPtrDirIpSvr,
			     int pintPtoCom):
	         chrPtrDirIpSvr(pchrPtrDirIpSvr),
		 intPtoCom(pintPtoCom)
{

}
const char *CQSisServidor::ObtenDirIpSvr()
{
	return chrPtrDirIpSvr;
}
int CQSisServidor::ObtenPtoCom()
{
	return intPtoCom;
}
CQSisServidores::CQSisServidores()
{

}
const CQSisServidores &CQSisServidores::operator<<(CQSisServidor *pCQSServidor)
{
	append(pCQSServidor);
	return *this;
}
bool CQSisServidores::operator==(CQSisServidor *pCQSServidor)
{
CQSisServidor *lCQSServidor;

		for(lCQSServidor=first();
		    lCQSServidor;
		    lCQSServidor=next())
	         if(!strcmp(pCQSServidor->ObtenDirIpSvr(),
			    lCQSServidor->ObtenDirIpSvr())  &&
		     pCQSServidor->ObtenPtoCom()==lCQSServidor->ObtenPtoCom())
		   return true;

	return false;
}
CQSisServidor *CQSisServidores::operator[](int pintNumServidor)
{
	return  at(pintNumServidor);
}
CQSisUsuario::CQSisUsuario(const char *pchrPtrFirma,
			   const char *pchrPtrTipoLetra,
			   int pintTamano,
			   int pintNegrita):
		chrPtrFirma(pchrPtrFirma),
		chrPtrTipoLetra(pchrPtrTipoLetra),
		intTamano(pintTamano),
		intNegrita(pintNegrita)
{
printf("CQSisUsuario::CQSisUsuario:%s:%x\n",chrPtrTipoLetra,this);
}
const char *CQSisUsuario::ObtenFirma()
{
	return chrPtrFirma;
}
const char *CQSisUsuario::ObtenTipoLetra()
{
printf("CQSisUsuario::ObtenTipoLetra:%s:%x\n",chrPtrTipoLetra,this);
	return chrPtrTipoLetra;
}
int CQSisUsuario::ObtenTamanoLetra()
{
	return intTamano;
}
int CQSisUsuario::ObtenNegrita()
{
	return intNegrita;
}
CQSisUsuarios::CQSisUsuarios()
{
}
const CQSisUsuarios &CQSisUsuarios::operator<<(CQSisUsuario *pCQSUsuario)
{
	append(pCQSUsuario);
	return *this;
}
CQSisUsuario *CQSisUsuarios::operator[](int pintNum)
{
	return at(pintNum);
}
CQSisUsuario *CQSisUsuarios::operator[](const char *pchrPtrFirma)
{
int lintContador;
	for(lintContador=0;lintContador<count();lintContador++)
	{
	   if(!strcmp(at(lintContador)->ObtenFirma(),pchrPtrFirma))
	   return at(lintContador);
	}
	return 0;
}
bool CQSisUsuarios::operator==(CQSisUsuario *pCQSUsuario)
{
CQSisUsuario *lCQSUsuario;
	for(lCQSUsuario=first();
	    lCQSUsuario;
	    lCQSUsuario=next())
	if(!strcmp(lCQSUsuario->ObtenFirma(),
		   pCQSUsuario->ObtenFirma()))
	 return true;
	return false;
}
CQSisLeeArchivoConf::CQSisLeeArchivoConf()
{
}
bool CQSisLeeArchivoConf::startDocument()
{
	return true;
}
bool CQSisLeeArchivoConf::startElement(const QString &,
				       const QString &,
				       const QString &pQSNmbEtiqueta,
				       const QXmlAttributes &pQXMLADatos)
{
	if(pQSNmbEtiqueta=="Siscom")
	 chrPtrSistema=strdup((const char *)pQXMLADatos.value(0));
	if(pQSNmbEtiqueta=="Servidor")
	 chrPtrServidor=strdup((const char *)pQXMLADatos.value(0));
	if(pQSNmbEtiqueta=="Direccion")
	 chrPtrDireccion=strdup((const char *)pQXMLADatos.value(0));
	if(pQSNmbEtiqueta=="Puerto")
	 intPuerto=pQXMLADatos.value(0).toInt();
	if(pQSNmbEtiqueta=="Usuario")
	 chrPtrUsuario=strdup((const char *)pQXMLADatos.value(0));
	if(pQSNmbEtiqueta=="Letra")
	 chrPtrTipoLetra=strdup((const char *)pQXMLADatos.value(0));
	if(pQSNmbEtiqueta=="Tamano")
	 intTamano=pQXMLADatos.value(0).toInt();
	if(pQSNmbEtiqueta=="Negrita")
	 intNegrita=pQXMLADatos.value(0).toInt();

	return true;
}

bool CQSisLeeArchivoConf::endElement(const QString &,
				     const QString &,
				     const QString &pQSNmbEtiqueta)
{
	if(pQSNmbEtiqueta=="Servidor")
	 CQSServidores << new CQSisServidor(chrPtrDireccion,
			 		    intPuerto);
	if(pQSNmbEtiqueta=="Usuario")
	CQSUsuarios << new CQSisUsuario(chrPtrUsuario,
			                chrPtrTipoLetra,
					intTamano,
					intNegrita);
					
	return true;
}
void CQSisLeeArchivoConf::ObtenUsuarios(CQSisUsuarios &pCQSUsuarios)
{
	pCQSUsuarios=CQSUsuarios;
}
void CQSisLeeArchivoConf::ObtenServidores(CQSisServidores &pCQSServidores)
{
	pCQSServidores=CQSServidores;
}
