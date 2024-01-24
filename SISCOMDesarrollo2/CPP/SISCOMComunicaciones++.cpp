#include <SISCOMComunicaciones++.h>
#include <SiscomCampoPro2.h>
#include <SiscomComunicaSrv.h>
#include <SiscomDatCom.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


SiscomInformacion2::SiscomInformacion2():
		SiscomInformacion()
{
}
void SiscomInformacion2::SiscomAsignaInformacion()
{
	SiscomFormaRegistro();
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro();
}




SiscomInformacion2::~SiscomInformacion2()
{
}
void SiscomInformacion2::SiscomFormaRegistro()
{
}
void SiscomInformacion2::SiscomAnexaRegistro()
{
} 
void SiscomInformacion2::MuestraCampos(const char *pchrPtrRotulo,
				       SiscomRegistroPro2 pSRegistroPro2)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSRegistroPro2.SiscomObtenNumCampos();
	    lintContador++)
	 printf("%s:%s\n",
	 	pchrPtrRotulo,
	 	pSRegistroPro2[lintContador]->chrPtrNmbCampo);
}
const char *SiscomInformacion::operator[](const char *pchrPtrNmbCampo)
{
	 return SRegistrosPro2[pchrPtrNmbCampo];
}
void SiscomInformacion2::SiscomAnexaCampos(const SiscomInformacion &pSInformacion)
{
const char *lchrPtrDato;
SiscomRegistroPro2 lSRegistroPro2=(const SiscomRegistroPro2 &)pSInformacion;
int lintContador;
int lintNumCamposAnt=SRegistroPro2.SiscomObtenNumCampos();
	SRegistrosPro2Paso.SiscomIniciaObjeto();
	for(lintContador=0;
	    lintContador<lSRegistroPro2.SiscomObtenNumCampos();
	    lintContador++)
	  SRegistroPro2 << lSRegistroPro2[lintContador]->chrPtrNmbCampo;
	SRegistrosPro2Paso.PonRegistroPro2(&SRegistroPro2);
	for(lintContador=0;
	    lintContador<lintNumCamposAnt;
	    lintContador++)
	{
	   lchrPtrDato=SRegistroPro2[lintContador]->chrPtrDato ?
	   	       SRegistroPro2[lintContador]->chrPtrDato :
		       "";
	   SRegistrosPro2Paso <<
	   SiscomCampoPro2(SRegistroPro2[lintContador]->chrPtrNmbCampo,
	   		   lchrPtrDato);
	}
	for(lintContador=0;
	    lintContador<lSRegistroPro2.SiscomObtenNumCampos();
	    lintContador++)
	   SRegistrosPro2Paso <<
	   SiscomCampoPro2(lSRegistroPro2[lintContador]->chrPtrNmbCampo,
	   		   lSRegistroPro2[lintContador]->chrPtrDato);
	
	SRegistrosPro2Paso.SiscomAnexaRegistro();
	SRegistrosPro2=SRegistrosPro2Paso;
}

SiscomParametroConsulta::SiscomParametroConsulta(const char *pchrPtrParametro)
{
	SRegistroPro2 <<
	"Parametro" ;
	 SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	 SRegistrosPro2 << 
	 SiscomCampoPro2("Parametro",pchrPtrParametro);
	 SRegistrosPro2.SiscomAnexaRegistro();
}
SiscomParametrosConsulta::SiscomParametrosConsulta()
{


}

SiscomParametrosConsulta &SiscomParametrosConsulta::operator<<(SiscomParametroConsulta *pSParConsulta)
{
	append(pSParConsulta);

	return *this;

}

void SiscomPasaFocoControl(QLineEdit *pQLEControl)
{
	pQLEControl->setFocus();
	pQLEControl->selectAll();
}
void SiscomPasaFocoControl(QWidget *pQWControl)
{
	pQWControl->setFocus();
}
QLineEdit *SiscomColocaEditAlCombo(QComboBox *pQCBCombo,const char *pchrPtrName)
{
QLineEdit *lQLERegreso=new QLineEdit(pQCBCombo,pchrPtrName);

	pQCBCombo->setLineEdit(lQLERegreso);

	return lQLERegreso;

}
void SiscomAnexarRegistroALaTabla(int pintNFila,
			    QTable *pQTTabla,
			    QStringList pQSLRegistro)
{
int lintContador;
int lintNCampos=pQSLRegistro.size();

	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	pQTTabla->setText(pintNFila,lintContador,pQSLRegistro[lintContador]);
}
void SiscomAnexarRegistroALaTabla(int pintNFila,
			    QPixmap pQPIcono,
			    QTable *pQTTabla,
			    QStringList pQSLRegistro)
{
int lintContador;
int lintNCampos=pQSLRegistro.size();

	for(lintContador=0;lintContador<lintNCampos;lintContador++)
	{
	pQTTabla->setPixmap(pintNFila,0,pQPIcono);
	pQTTabla->setText(pintNFila,lintContador,pQSLRegistro[lintContador]);
	}
}
void SiscomAjustaColumnas(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numCols();
		lintContador++)
	  pQTDatos->adjustColumn(lintContador);

}
void SiscomAjustaFilas(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numRows();
		lintContador++)
	  pQTDatos->adjustRow(lintContador);

}
QMemArray<int> SiscomFilasSeleccionadas(QTable *pQTDatos)
{
int lintContador,
    lintNumFilas=pQTDatos->numRows();
int lintNumSeleccionadas=0;
QMemArray<int> lQMARegreso(lintNumFilas);
    for(lintContador=0;
        lintContador<lintNumFilas;
	lintContador++)
     if(pQTDatos->isRowSelected(lintContador))
      lQMARegreso[lintNumSeleccionadas++]=lintContador;

       lQMARegreso.resize(lintNumSeleccionadas);
   return lQMARegreso;
}
const char *SiscomObtenInformacionDelEdit(QLineEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "" :((const char *)pQLEControl->text());
}
const char *SiscomObtenInformacionDelEdit(QTextEdit *pQTEControl)
{
	return pQTEControl->text().isEmpty() ? "" :strdup((const char *)pQTEControl->text());
}

QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaCombo(
			QWidget *pQWParent,
			const char *pchrPtrNombre,
			const char *pchrPtrEtiqueta,
			const char *pchrPtrCombo,
			QComboBox **pQCBRegreso,
			QLabel **pQLRegreso)
{
QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,0,-1,pchrPtrNombre);

		return lQVBLEspacio;
}
QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaEdit(
			QWidget *pQWParent,
			const char *pchrPtrNombre,
			const char *pchrPtrEtiqueta,
			const char *pchrPtrEdit,
			QLineEdit **pQLERegreso,
			QLabel **pQLRegreso)
{
QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,0,-1,pchrPtrNombre);

		*pQLRegreso=new QLabel(pchrPtrEtiqueta,
				       pQWParent,
				       pchrPtrEtiqueta,
				       0);
		(*pQLRegreso)->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
		*pQLERegreso=new QLineEdit(pQWParent,pchrPtrEdit);
		lQVBLEspacio->addWidget(*pQLRegreso);
		lQVBLEspacio->addWidget(*pQLERegreso);

		return lQVBLEspacio;

}
QVBoxLayout *SiscomCreaEspacioVerticalEtiquetaTextEdit(
			QWidget *pQWParent,
			const char *pchrPtrNombre,
			const char *pchrPtrEtiqueta,
			const char *pchrPtrEdit,
			QTextEdit **pQTERegreso,
			QLabel **pQLRegreso)
{
QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,0,-1,pchrPtrNombre);

		*pQLRegreso=new QLabel(pchrPtrEtiqueta,
				       pQWParent,
				       pchrPtrEtiqueta,
				       0);
		(*pQLRegreso)->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
		*pQTERegreso=new QTextEdit(pQWParent,pchrPtrEdit);
		lQVBLEspacio->addWidget(*pQLRegreso);
		lQVBLEspacio->addWidget(*pQTERegreso);

		return lQVBLEspacio;

}
QVBoxLayout *SiscomCreaEspacioVerticalButton(QWidget *pQWParent,
					     const char *pchrPtrTexto,
					     const char *pchrPtrNombre,
					     QPushButton **pQPBBoton)
{
QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,0,-1,pchrPtrNombre);

		*pQPBBoton=new QPushButton(pchrPtrTexto,pQWParent,pchrPtrNombre);
		lQVBLEspacio->addWidget(*pQPBBoton);

		return lQVBLEspacio;




}

QVBoxLayout *SiscomCreaDisplayEtiqueta(
				QWidget *pQWParent,
				const char *pchrPtrNmbEtiqueta,
				const char *pchrPtrTextoEtiqueta,
				const char *pchrPtrNmbDisplay,
				int pintNumDigitos,
				QLCDNumber **pQLCDNDisplay,
				QLabel **pQLEtiqueta)
{
QVBoxLayout *lQLVLayout;
lQLVLayout=new QVBoxLayout(0,0,-1,"lQLVLayout");
*pQLEtiqueta=SiscomCreaEtiqueta(pQWParent,pchrPtrTextoEtiqueta,pchrPtrNmbEtiqueta);
*pQLCDNDisplay=new QLCDNumber(pQWParent,pchrPtrNmbDisplay);
lQLVLayout->addWidget(*pQLEtiqueta);
lQLVLayout->addWidget(*pQLCDNDisplay);
(*pQLCDNDisplay)->setNumDigits(pintNumDigitos);
return lQLVLayout;
}

QLabel *SiscomCreaEtiqueta(QWidget *pQWParent,
			   const char *pchrPtrDato,
			   const char *pchrPtrNombre)
{
QLabel *lQLEtiqueta;
lQLEtiqueta=new QLabel(pchrPtrDato,
		       pQWParent,
		       pchrPtrNombre,
		       0);
lQLEtiqueta->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
return lQLEtiqueta;
}
QTable *SiscomCreaTabla(QWidget *pQWParent,
			const char *pchrPtrName,
			int pintNFilas,
			const QStringList &pQSLNombres)
{
int lintContador;
QTable *lQTDatos;
lQTDatos=new QTable(pintNFilas,pQSLNombres.count(),pQWParent,pchrPtrName);
for(lintContador=0;
    lintContador < (int )pQSLNombres.count();
    lintContador++)
 lQTDatos->horizontalHeader()->setLabel(lintContador,pQSLNombres[lintContador]);
 return lQTDatos;
}
/*
 *
SiscomOperaciones::SiscomOperaciones(SiscomDatCom *pSisDatCom,
				     QPtrList<SiscomInformacion> *pQPLSiscomInfo):
		SisDatCom(pSisDatCom),
		QPLSiscomInfo(pQPLSiscomInfo)
{


}
SiscomOperaciones::SiscomOperaciones(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
SiscomOperaciones::~SiscomOperaciones()
{

}

void SiscomOperaciones::SiscomActualiza(const char *pchrPtrOperacion)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio(pchrPtrOperacion);
}
void SiscomOperaciones::SiscomActualiza(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}

void SiscomOperaciones::SiscomActualiza2(const char *pchrPtrOperacion)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
}

void SiscomOperaciones::SiscomActualiza2(
			const char *pchrPtrOperacion,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSRegistrosPro2);
}
void SiscomOperaciones::SiscomActualiza2(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}
void SiscomOperaciones::SiscomActualizaSubRegistros(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvioSubRegistros(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}
void SiscomOperaciones::SiscomActualiza2SubRegistros(
			const char *pchrPtrOperacion,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvioSubRegistros(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSRegistrosPro2);
}
void SiscomOperaciones::SiscomConsulta(const char *pchrPtrOperacion,
				       SiscomRegistrosPro2 **pSRegistrosPro2)
{
	SiscomActualiza2SubRegistros(pchrPtrOperacion,
				     pSRegistrosPro2);
}
void SiscomOperaciones::SiscomConsulta(const char *pchrPtrOperacion,
				       QPtrList<SiscomInformacion> *pQPLSiscomInfo)
{
printf("SiscomOperaciones::SiscomConsulta\n");
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistros((const SiscomComunicaSrv *)lSGenOp,pQPLSiscomInfo);
}
void SiscomOperaciones::SiscomPonParametrosConsulta(
					QPtrList<SiscomInformacion> *pQPtrInformacion)
{
	QPLSiscomInfo=pQPtrInformacion;
}
void SiscomOperaciones::SiscomGeneraRegistros(const SiscomComunicaSrv *,
					      QPtrList<SiscomInformacion> *)
{
SiscomInformacion *lSInformacion;
}
void SiscomOperaciones::SiscomGeneraRegistrosActualiza(const SiscomComunicaSrv *,
					      QPtrList<SiscomInformacion> *)
{

}
void SiscomOperaciones::SiscomGeneraRegistrosActualiza(
			const SiscomComunicaSrv *pSComunicaSrv,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
	*pSRegistrosPro2=new SiscomRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

}

*/

SiscomArgumentosPantalla::SiscomArgumentosPantalla()
{

}

QSisHEspacio::QSisHEspacio(QWidget *pQWParent,
			   int pintMargen,
			   int pintEspacio,
			   const char *pchrPtrName):
		QHBoxLayout(pQWParent,pintMargen,pintEspacio,pchrPtrName)
{

}
QSisHEspacio &QSisHEspacio::operator+=(QVBoxLayout *pQVBEspacio)
{
	addItem(pQVBEspacio);
	return *this;
}
void SiscomArgumentosConsulta(SiscomParametrosConsulta *pSPConsulta,
			      char *pzCadenaFormato,
			      ...)
{
va_list lzArgumentos;
char *lzCadenaFormato=pzCadenaFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
        va_start(lzArgumentos,pzCadenaFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
				(*pSPConsulta) << 
				   new SiscomParametroConsulta(lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
}
void SiscomEliminaFilasTabla(QTable *pQTDatos)
{
QMemArray<int> lQMAFilas(pQTDatos->numRows());
int lintContador;
int lintNFilas=pQTDatos->numRows();
	for(lintContador=0;
	    lintContador<lintNFilas;
	    lintContador++)
	 lQMAFilas[lintContador]=lintContador;
pQTDatos->removeRows(lQMAFilas);
}
void SiscomEliminaFilasTabla(QTable *pQTDatos,
			     int pintInicio,
			     int pintFin)
{


}


CQSisLstMenu::CQSisLstMenu()
{

}
CQSisLstMenu &CQSisLstMenu::operator<<(QAction *pQAMenu)
{
	append(pQAMenu);
	return *this;
}

QAction *CQSisLstMenu::operator[](const char *pchrPtrNmbMenu)
{
QAction *lQAContador;
	for(lQAContador=first();
	    lQAContador;
	    lQAContador=next())
	if(!strcmp(lQAContador->name(),pchrPtrNmbMenu))
	 return lQAContador;
printf("CQSisLstMenu::operator[]: NO se encontro{%s}\n",
	pchrPtrNmbMenu);
  return 0;
}
