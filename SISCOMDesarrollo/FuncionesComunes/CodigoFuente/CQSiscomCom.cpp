#include <CQSiscomCom.h>

#include <qstringlist.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qfile.h>
#include <stdio.h>
#include <qcombobox.h>
CQSiscomCom::CQSiscomCom(CSISCOMDatComunicaciones pSCDComDatos):
	      CSISCOMComunicaciones(pSCDComDatos)
{

}
CQSiscomCom::CQSiscomCom():CSISCOMComunicaciones()
{


}
CQSiscomCom::CQSiscomCom(int pintPComRN,
			const char *pchrPtrDirIpSvrRN,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword):
	      CSISCOMComunicaciones(pintPComRN,
			      	    pchrPtrDirIpSvrRN,
				    pchrPtrUsuario,
				    pchrPtrPassword)
{


	QSLRegistro.clear();

}
CQSiscomCom::~CQSiscomCom()
{
StcLtaRegComSISCOM *lSLRCSisDat=SLRComSisPtrPrim,
		   *lSLRCSisLibera;
	while(lSLRCSisDat)
	{
	   lSLRCSisLibera=lSLRCSisDat->LSRCSISCOMPtrSig;
	   free(lSLRCSisDat);
	   lSLRCSisDat=lSLRCSisLibera;
	}
}
void CQSiscomCom::EjecutaEnvioSvrSISCOM()
{
  EnviaInformacionAlSvrAlta();
  SLRComSisPtrPrim=SLRComSisPtrDat=ObtenRegistrosResAlta();
}
QStringList &CQSiscomCom::ObtenRegistroRespuesta()
{
int lintContador;
	QSLRegistro.clear();
	for(lintContador=0;
	    SLRComSisPtrDat &&
	    SLRComSisPtrDat->chrPtrRegistro[lintContador];
	    lintContador++)
	{
	QSLRegistro<<SLRComSisPtrDat->chrPtrRegistro[lintContador];
	free(SLRComSisPtrDat->chrPtrRegistro[lintContador]);
	}
	if(SLRComSisPtrDat)
	free(SLRComSisPtrDat->chrPtrRegistro);
	SLRComSisPtrDat=SLRComSisPtrDat->LSRCSISCOMPtrSig;
 return QSLRegistro;
}
QStringList &CQSiscomCom::ObtenRegistroRespuesta(int *pintPtrEsElUltimo) 
{
int lintContador;
	QSLRegistro.clear();
	for(lintContador=0;
	    SLRComSisPtrDat &&
	    SLRComSisPtrDat->chrPtrRegistro[lintContador];
	    lintContador++)
	{
	QSLRegistro<<SLRComSisPtrDat->chrPtrRegistro[lintContador];
	free(SLRComSisPtrDat->chrPtrRegistro[lintContador]);
	}
	if(SLRComSisPtrDat)
	free(SLRComSisPtrDat->chrPtrRegistro);
	SLRComSisPtrDat=SLRComSisPtrDat ?SLRComSisPtrDat->LSRCSISCOMPtrSig:0;
	*pintPtrEsElUltimo=SLRComSisPtrDat ? 0 :1 ;
 return QSLRegistro;
}
void CQSiscomCom::ObtenRegistroRespuesta(int *pintPtrEsElUltimo,
					 QStringList &pQSLRegistro) 
{
int lintContador;
	QSLRegistro.clear();
	for(lintContador=0;
	    SLRComSisPtrDat &&
	    SLRComSisPtrDat->chrPtrRegistro[lintContador];
	    lintContador++)
	{
	pQSLRegistro<<SLRComSisPtrDat->chrPtrRegistro[lintContador];
	free(SLRComSisPtrDat->chrPtrRegistro[lintContador]);
	}
	if(SLRComSisPtrDat)
	free(SLRComSisPtrDat->chrPtrRegistro);
	
	SLRComSisPtrDat=SLRComSisPtrDat ?SLRComSisPtrDat->LSRCSISCOMPtrSig:0;
	*pintPtrEsElUltimo=SLRComSisPtrDat ? 0 :1 ;
}
CQOGenericaServidorSiscom::CQOGenericaServidorSiscom():
			   CQSiscomCom()
{

	QPLRegistros.setAutoDelete(true);

}

CQOGenericaServidorSiscom::CQOGenericaServidorSiscom(CSISCOMDatComunicaciones *pCSDCInfo,
						     const char *pchrPtrNmbDllSvr,
						     const char *pchrPtrNmbFunDllSvr,
						     int pintNCampos):
			CQSiscomCom(*pCSDCInfo),
			intNCampos(pintNCampos),
			intNRegistros(0),
			intPosRegistro(0)
{
	QPLRegistros.setAutoDelete(true);
	PonDatosDLLAltaServidor(intNCampos,
				pchrPtrNmbDllSvr,
				pchrPtrNmbFunDllSvr);
}
CQOGenericaServidorSiscom::~CQOGenericaServidorSiscom()
{
	QPLRegistros.clear();

}
void CQOGenericaServidorSiscom::ObtenRespuesta()
{
int lintEdoCns=0;
QStringList lQSLRegistro;
int lintContador;
int lintNCampos;
int lintPVez=1;
	while(!lintEdoCns)
	{
	  lQSLRegistro=ObtenRegistroRespuesta(&lintEdoCns);
	  if(lintPVez)
	  {
	   IniciaRegistroRespuesta(lQSLRegistro);
	   lintPVez=0;
	  }
	  else
	  AnexaRegistroRespuesta(lQSLRegistro);
	  intNRegistros++;
	}
}	
void CQOGenericaServidorSiscom::ColocaAlInicio()
{
	intPosRegistro=0;
}
void CQOGenericaServidorSiscom::IniciaRegistroRespuesta(QStringList pQSLRegistro)
{
int lintContador,
    lintNCampos=pQSLRegistro.size();
QStringList *lQSLCampo;
	intNCampos=lintNCampos;
	for(lintContador=0;
	    lintContador<lintNCampos;
	    lintContador++)
	 {
	     lQSLCampo=new QStringList;
	     lQSLCampo->append(pQSLRegistro[lintContador]);
	     QPLRegistros.append(lQSLCampo);
	 }
}
void CQOGenericaServidorSiscom::AnexaRegistroRespuesta(QStringList pQSLRegistro)
{
int lintContador,
    lintNCampos=QPLRegistros.count();
	for(lintContador=0;
	    lintContador<lintNCampos;
	    lintContador++)
	   ((QStringList *)QPLRegistros.at(lintContador))->append(pQSLRegistro[lintContador]);
}
void CQOGenericaServidorSiscom::ObtenRegistro(QStringList &pQSLRegistro)
{
int lintNCampos=QPLRegistros.count(),
	lintContador;
	pQSLRegistro.clear();
	for(lintContador=0;
	    lintContador<lintNCampos;
	    lintContador++)
	  pQSLRegistro << 
	 (*((QStringList *)QPLRegistros.at(lintContador)))[intPosRegistro];
}
void CQOGenericaServidorSiscom::ObtenCampoTodos(int pintNCampo,
						QStringList &pQSLCampo)
{
	pQSLCampo=(*((QStringList *)QPLRegistros.at(pintNCampo)));
}
QStringList CQOGenericaServidorSiscom::ObtenCampoTodos(int pintNCampo)
{
	return (*((QStringList *)QPLRegistros.at(pintNCampo)));
}
QString CQOGenericaServidorSiscom::ObtenCampo(int pintNCampo,int pintNRegistro)
{
	if(QPLRegistros.count() &&
	   QPLRegistros.at(pintNCampo))
	return (*((QStringList *)QPLRegistros.at(pintNCampo)))[pintNRegistro];
	else
	return QString();
}
int CQOGenericaServidorSiscom::SiguienteRegistro(int pintNCampo,
						 QStringList &pQSLRegistro)
{
	ObtenRegistro(pQSLRegistro);
	intPosRegistro++;
	return intPosRegistro==intNRegistros ? 1 : 0;
}
int CQOGenericaServidorSiscom::SiguienteRegistro(QStringList &pQSLRegistro)
{
	if(intPosRegistro<intNRegistros)
	ObtenRegistro(pQSLRegistro);
	intPosRegistro++;


	return intPosRegistro>intNRegistros ? 1 : 0;
}
void PasaFocoControl(QLineEdit *pQLEControl)
{
	pQLEControl->setFocus();
	pQLEControl->selectAll();

}
void PasaFocoControl(QWidget *pQLEControl)
{
	pQLEControl->setFocus();
}
void SISCOMAnexarRegistroALaTabla(int pintNFila,
			    QTable *pQTTabla,
			    QColor pQColor,
			    QStringList pQSLRegistro)
{
int lintContador;
int lintNCampos=pQSLRegistro.size();

	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	{
	pQTTabla->setItem(pintNFila,
			  lintContador,
			  new CQTableItemColor(pQTTabla,
					       QTableItem::Never,
					       pQSLRegistro[lintContador]));
	}
}
void SISCOMAnexarRegistroALaTabla(int pintNFila,
			    QTable *pQTTabla,
			    QStringList pQSLRegistro)
{
int lintContador;
int lintNCampos=pQSLRegistro.size();

	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	pQTTabla->setText(pintNFila,lintContador,pQSLRegistro[lintContador]);
}
void AnexarRegistroALaTabla(QTable *pQTTabla,
			    QStringList pQSLRegistro)
{
int lintNFilas=pQTTabla->numRows();
int lintContador;
int lintNCampos=pQSLRegistro.size();
	
	pQTTabla->setNumRows(lintNFilas+1);
	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	pQTTabla->setText(lintNFilas,lintContador,pQSLRegistro[lintContador]);
}

void AnexarRegistroALaTabla(QTable *pQTTabla,
			    QPixmap *pQPIcono,
			    QStringList pQSLRegistro)
{
int lintNFilas=pQTTabla->numRows();
int lintContador;
int lintNCampos=pQSLRegistro.size();
	pQTTabla->setNumRows(lintNFilas+1);
	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	{
	pQTTabla->setPixmap(lintNFilas,0,*pQPIcono);
	pQTTabla->setText(lintNFilas,lintContador,pQSLRegistro[lintContador]);
	}
}
void AnexarRegistroALaTabla(QTable *pQTTabla,
			    int pintFilaIni,
			    QStringList pQSLRegistro)
{
int lintNFilas=pQTTabla->numRows();
int lintContador;
int lintNCampos=pQSLRegistro.size();
	pQTTabla->setNumRows(lintNFilas+1);
	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	pQTTabla->setText(lintNFilas,lintContador,pQSLRegistro[lintContador]);
}
void CreaListaDeCadenas(QStringList &pQSLLista,
			const char *pchrPtrFormato,...)
{
va_list lVLArg;
char *lchrPtrArgumento;
	va_start(lVLArg,pchrPtrFormato);
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato++=='%')	
		switch(*pchrPtrFormato)
		{
		  case 's':
			   pQSLLista << va_arg(lVLArg,char *);
		  break;
		}
	    *pchrPtrFormato++;
	}
	 va_end(lVLArg);
}
void EliminaFilasTabla(QTable *pQTDatos)
{
int lintNFilas=pQTDatos->numRows();
int lintContador;
  for(lintContador=0;lintContador<=lintNFilas;lintContador++)
   pQTDatos->removeRow(lintContador);
  pQTDatos->setNumRows(0);
}
void LlenaTablaQSiscomCom(CQSiscomCom *pCQSComDat,
			  QTable *pQTDatos)
{
int lintEsElUltimo=0;

	while(!lintEsElUltimo)
		AnexarRegistroALaTabla(pQTDatos,
				       pCQSComDat->ObtenRegistroRespuesta(&lintEsElUltimo));

}
void LeeArchivoApiQT(const char *pchrPtrNmbArchivo,
		char **pchrPtrArchivo)
{
   QFile lQFArchivo(pchrPtrNmbArchivo);
   int lintContador=0;
   *pchrPtrArchivo=(char *)malloc(lQFArchivo.size()+2);
    lQFArchivo.open( IO_ReadOnly); 
      while((int )((*pchrPtrArchivo)[lintContador++]=lQFArchivo.getch())!=-1);
      (*pchrPtrArchivo)[lintContador-1]=0;
  lQFArchivo.close();
}
void HabilitaDesHabilitaControles(const char *pchrPtrFormato,
				...)
{
va_list lVLArg;
QWidget *lQWControl;
char lchrArrEstado[2];
	va_start(lVLArg,pchrPtrFormato);
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato++=='%')	
		switch(*pchrPtrFormato)
		{
		  case 'W':
			lQWControl=(QWidget *)va_arg(lVLArg,QLineEdit *);	   
			*pchrPtrFormato++;
			sprintf(lchrArrEstado,"%c",*pchrPtrFormato);
			lQWControl->setEnabled(atoi(lchrArrEstado));
		  break;
		}
		*pchrPtrFormato++;
	}
	 va_end(lVLArg);

}
void HabilitaDesHabilitaControles(QObject *pQOPtrControles,
					  int pintEstado,
					  const char *pchrPtrTipoControl)
{
QObjectList *lQOPtrControles = pQOPtrControles->queryList(pchrPtrTipoControl);
QObjectListIt lQOIterator( *lQOPtrControles ); 
QWidget *lQWPtrControl;

	while((lQWPtrControl=(QWidget *)lQOIterator.current()))
	{
	 lQWPtrControl->setEnabled(pintEstado);
	 ++lQOIterator;
	}

	delete lQOPtrControles;

}
CQSiscomCom *IniciaConsultaAlServidor(const char *pchrPtrNmbBServidor,
				      const char *pchrPtrNmbBFuncion,
				      int pintNumCampos,
				      CSISCOMDatComunicaciones *pCSDatComInfo)
{
CQSiscomCom *lCQSCInfo=new CQSiscomCom(*pCSDatComInfo);

	lCQSCInfo->PonDatosDLLAltaServidor(pintNumCampos,
					   pchrPtrNmbBServidor,
					   pchrPtrNmbBFuncion);
	return lCQSCInfo;
}

SISCOMGlobales::SISCOMGlobales()
{

}
SISCOMCampoEnvio::SISCOMCampoEnvio(const char *pchrPtrNombre,
				   const char *pchrPtrContenido):
		chrPtrNombre(pchrPtrNombre),
		chrPtrContenido(pchrPtrContenido)
{

}
const char *SISCOMCampoEnvio::ObtenNombre()
{
	return chrPtrNombre;
}
const char *SISCOMCampoEnvio::ObtenContenido()
{
	return chrPtrContenido;
}
void SISCOMCampoEnvio::PonContenido(const char *pchrPtrContenido)
{
	chrPtrContenido=pchrPtrContenido;
}
SISCOMRegistroEnvio::SISCOMRegistroEnvio()
{


}

char **SISCOMRegistroEnvio::ObtenRegistro()
{
char **lchrPtrRegistro;
int lintContador;
	lchrPtrRegistro=(char **)malloc(sizeof(char *)*
					(count()+1));
	for(lintContador=0;
	    lintContador<count();
	    lintContador++)
	 lchrPtrRegistro[lintContador]=(char *)at(lintContador)->ObtenContenido();
	lchrPtrRegistro[lintContador]=0;
	return lchrPtrRegistro;	
}
SISCOMCampoEnvio *SISCOMRegistroEnvio::operator[](const char *pchrPtrCampo)
{
SISCOMCampoEnvio *lSIS_CEnvio;
	for(lSIS_CEnvio=first();
	    lSIS_CEnvio;
	    lSIS_CEnvio=next())
	 if(!strcmp(lSIS_CEnvio->ObtenNombre(),
		    pchrPtrCampo))
	   return lSIS_CEnvio;

return 0;
	
}
void SISCOMRegistroEnvio::LimpiaRegistro()
{
SISCOMCampoEnvio *lSIS_CEnvio;
	for(lSIS_CEnvio=first();
	    lSIS_CEnvio;
	    lSIS_CEnvio=next())
	    lSIS_CEnvio->PonContenido("");
}
SISCOMRegistroEnvio &SISCOMRegistroEnvio::operator<<(SISCOMCampoEnvio *pSIS_CEnvio)
{
	append(pSIS_CEnvio);
	return *this;
}	


void MuestraTexto(QLineEdit *pQLEControl,
		  QString pQSTexto)
{
	pQLEControl->setText(pQSTexto);
	pQLEControl->selectAll();

}
void ColocaCheckBoxALaTabla(QTable *pQTDatos,
			    int pintFila,
			    int pintColumna,
			    QString pQSTexto,
			    int pintEstado)
{
QCheckTableItem *lQCTItem=new QCheckTableItem(pQTDatos,
					      pQSTexto);
		    lQCTItem->setChecked(pintEstado);
		    pQTDatos->setItem(pintFila,
				      pintColumna,
				      lQCTItem);

}
QLineEdit *ColocaLineEditAlCombo(QComboBox *pQCBControl,
				 const char *pchrPtrName)
{
QLineEdit *lQLEControl=new QLineEdit(pQCBControl,pchrPtrName);
	pQCBControl->setLineEdit(lQLEControl);
	return lQLEControl;
}

void EliminaFilasTabla2(QTable *pQTDatos)
{
int lintContador,
    lintNFilas=pQTDatos->numRows(),
    lintConABorrar=0;
QMemArray<int> lQMACols(lintNFilas);
	for(lintContador=0;
	    lintContador<lintNFilas;
	    lintContador++)
	 if(pQTDatos->isRowSelected(lintContador))
	  lQMACols[lintConABorrar++]=lintContador;

	lQMACols.resize(lintConABorrar);
	pQTDatos->removeRows(lQMACols);
}
void MuestraContenidoRegistro(QStringList pQSLRegistro,
			      const char *pchrPtrFuncion)
{
char **lchrPtrRegistro;
int lintContador,
    lintNCadenas=pQSLRegistro.size();
	lchrPtrRegistro=(char **)malloc(sizeof(char *)*(lintNCadenas+1));
	for(lintContador=0;lintContador<lintNCadenas;lintContador++)
        lchrPtrRegistro[lintContador]=(char *)(const char *)pQSLRegistro[lintContador];
	lchrPtrRegistro[lintContador]=0;
	SISCOMImprimeContenidoRegistro(lchrPtrRegistro,pchrPtrFuncion);
}

int SISCOMEsElRegistroVacio(QStringList pQSLRegistro)
{
int lintContador;
int lintNVacios=0;
int lintNCampos=pQSLRegistro.size(); 
        for(lintContador=0;          
            lintContador<lintNCampos;
            lintContador++)
         if(pQSLRegistro[lintContador].isEmpty())
          lintNVacios++;             
        return lintNVacios==lintNCampos;

}
const char *SISCOMObtenInformacionDelEdit(QLineEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "" : strdup((const char *)pQLEControl->text());
}
const char *SISCOMObtenInformacionDelEdit(QTextEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "" : strdup((const char *)pQLEControl->text());
}

SISCOMOperacionesEnvio::SISCOMOperacionesEnvio(CSISCOMDatComunicaciones *pCSisDatCom,
					   QStringList pQSLArgumentos,
					   const char *pchrPtrServidor,
					   const char *pchrPtrFuncion,
					   const char *pchrPtrOperacion):
		CSisDatCom(pCSisDatCom),
	        chrPtrServidor(pchrPtrServidor),
		chrPtrFuncion(pchrPtrFuncion),
		chrPtrOperacion(pchrPtrOperacion),
		QSLArgumentos(pQSLArgumentos)
{
}
void SISCOMOperacionesEnvio::SISCOMEjecutaEnvio()
{
	SISCOMIniciaRegistroEnvio();
	IniciaComunicacion(chrPtrServidor,chrPtrFuncion,chrPtrOperacion);
	EnviaParametrosOperacion(QSLArgumentos);
	SISCOMRegistrosEnvio();
	EnviaInformacion();


}
void SISCOMOperacionesEnvio::SISCOMPonRegistroEnvio(const SISCOMRegistroEnvio &pSISCOMRegEnvio)
{
	SISCOMRegEnvio=pSISCOMRegEnvio;
}
CQOGenericaServidorSiscom *SISCOMOperacionesEnvio::SISCOMObtenOperacionServidor()
{
	return CQOGSvrSiscom;
}
void SISCOMOperacionesEnvio::IniciaComunicacion(const char *pchrPtrServicio,
					      const char *pchrPtrFuncion,
					      const char *pchrPtrOperacion)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                            pchrPtrServicio,
                                            pchrPtrFuncion,
                                            SISCOMRegEnvio.count());
	if(SISCOMRegEnvio["Servicio"])
	{
	  SISCOMRegEnvio["Servicio"]->PonContenido(pchrPtrOperacion);
	  AnexaRegistro();
	}
	else
	printf("SISCOMOPeracionEnvio::IniciaComunicacion:El Registro No Tiene Un Campo \"Servicio\"\n");
}
void SISCOMOperacionesEnvio::SISCOMAnexaRegistro(const SISCOMRegistroEnvio &pSISCOMRegEnvio)
{
	SISCOMRegEnvio=pSISCOMRegEnvio;
	AnexaRegistro();

}
void SISCOMOperacionesEnvio::SISCOMAnexaRegistroVacio()
{
	AnexaRegistroVacio();
}
void SISCOMOperacionesEnvio::AnexaRegistro()
{
	CQOGSvrSiscom->AnexaRegistro(SISCOMRegEnvio.ObtenRegistro());
	SISCOMRegEnvio.LimpiaRegistro();
}
void SISCOMOperacionesEnvio::AnexaRegistroVacio()
{
	SISCOMRegEnvio.LimpiaRegistro();
	AnexaRegistro();
}
void SISCOMOperacionesEnvio::EnviaParametrosOperacion(QStringList pQSLArgumentos)
{
int lintContador;
	if(SISCOMRegEnvio["ParametrosOperacion"])
	{
        for(lintContador=0;
            lintContador<pQSLArgumentos.size();
            lintContador++)
        {
         SISCOMRegEnvio["ParametrosOperacion"]->PonContenido(
                        (const char *)pQSLArgumentos[lintContador]
                        );
         AnexaRegistro();
        }
        AnexaRegistroVacio();
	}
	else
	printf("SISCOMOPeracionEnvio::EnviaParametrosOperacion:El Registro No Tiene Un Campo \"ParametrosOperacion\"\n");
	

}
void SISCOMOperacionesEnvio::EnviaInformacion()
{
 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}

CQTableItemColor::CQTableItemColor(QTable *pQTable,
				   EditType pQEType,
				   const QString &pQTexto):
	  QTableItem(pQTable,pQEType,pQTexto)
{

}

void CQTableItemColor::paint(QPainter *pQPainter,
			     const QColorGroup &pQCGDato,
			     const QRect &pQRArea,
			     bool pbSelect)
{

	QColorGroup g(pQCGDato);

	g.setColor(QColorGroup::Base,blue);
	QTableItem::paint(pQPainter,
			  g,
			  pQRArea,
			  pbSelect);
}

