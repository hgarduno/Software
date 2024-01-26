#include <QtBaseMedidas.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresion.h>
#include <qpaintdevicemetrics.h>
#include <qpainter.h>
#include <qprinter.h>
QtBaseMedidas::QtBaseMedidas(QWidget *pQWParent,
			     const char *pchrPtrName):
			     intPaginas(0)
{
}
QtBaseMedidas::~QtBaseMedidas()
{
   delete QPaintDeviceMedidas;
}
void QtBaseMedidas::Painter(QPainter *pQPPainter)
{
   QPainterDibuja=pQPPainter; 
}
void QtBaseMedidas::InicializaMedidas()
{
 if(QPainterDibuja)
 QPaintDeviceMedidas=new QPaintDeviceMetrics(QPainterDibuja->device());
}
int QtBaseMedidas::MMx(int pintMMx)
{
return ((pintMMx+intMargenX)/25.4)*QPaintDeviceMedidas->logicalDpiY();
}

int QtBaseMedidas::MMy(int pintMMy)
{
return ((pintMMy-intMargenY)/25.4)*QPaintDeviceMedidas->logicalDpiY();
}
int QtBaseMedidas::MM(int pintMMx)
{
return ((pintMMx)/25.4)*QPaintDeviceMedidas->logicalDpiX();
}
void QtBaseMedidas::MargenX(int pintMargenX)
{
intMargenX=pintMargenX;
}
void QtBaseMedidas::MargenY(int pintMargenY)
{
intMargenY=pintMargenY;
}
int QtBaseMedidas::Texto(zSiscomRegistro *pzSisRegInfoTexto,
			  zImpresion *pzImpresion)
{
const char *lchrPtrCampo;

lchrPtrCampo=(const char *)(*pzSisRegInfoTexto)["campo"];
  return Texto(pzSisRegInfoTexto->CampoInt("x"),
  	pzSisRegInfoTexto->CampoInt("y"),
	pzSisRegInfoTexto->CampoInt("anchox"),
	pzSisRegInfoTexto->CampoInt("anchoy"),
	(*pzImpresion)[lchrPtrCampo]);
}
int QtBaseMedidas::Texto(int pintDesplazamientoY,
			  zSiscomRegistros *pzSisRegsCampos,
			  zSiscomRegistro *pzSisRegRegistro)
{
zSiscomRegistro *lzSisRegCampo;
for(lzSisRegCampo=pzSisRegsCampos->Primer();
    lzSisRegCampo;
    lzSisRegCampo=pzSisRegsCampos->Siguiente())
{
 if((*pzSisRegRegistro)[(const char *)lzSisRegCampo->Campo("campo")])
  Texto(lzSisRegCampo->CampoInt("x"),
  	lzSisRegCampo->CampoInt("y")+pintDesplazamientoY,
	lzSisRegCampo->CampoInt("anchox"),
	lzSisRegCampo->CampoInt("anchoy"),
	(const char *)(*pzSisRegRegistro)[(const char *)lzSisRegCampo->Campo("campo")]);
}
return SePoneNumeroPagina(pintDesplazamientoY);
}
int QtBaseMedidas::TextoXY(int pintDesplazamientoX,
			    int pintDesplazamientoY,
			  zSiscomRegistros *pzSisRegsCampos,
			  zSiscomRegistro *pzSisRegRegistro)
{
zSiscomRegistro *lzSisRegCampo;
for(lzSisRegCampo=pzSisRegsCampos->Primer();
    lzSisRegCampo;
    lzSisRegCampo=pzSisRegsCampos->Siguiente())
{
 if((*pzSisRegRegistro)[(const char *)lzSisRegCampo->Campo("campo")])
  Texto(lzSisRegCampo->CampoInt("x")+pintDesplazamientoX,
  	lzSisRegCampo->CampoInt("y")+pintDesplazamientoY,
	lzSisRegCampo->CampoInt("anchox"),
	lzSisRegCampo->CampoInt("anchoy"),
	(const char *)(*pzSisRegRegistro)[(const char *)lzSisRegCampo->Campo("campo")]);
}
return SePoneNumeroPagina(pintDesplazamientoY);
}

int QtBaseMedidas::Texto(int pintDesplazamientoY,
			  zSiscomRegistros *pzSisRegsPosiciones,
			  const char *pchrPtrCampo,
			  const char *pchrPtrDato,
			  const char *pchrPtrCadena)
{
zSiscomRegistro *lzSisRegCampo;
if((lzSisRegCampo=pzSisRegsPosiciones->PorCampoDato(pchrPtrCampo,
						    (const unsigned char *)pchrPtrDato)))
return  Texto(lzSisRegCampo->CampoInt("x"),
  	lzSisRegCampo->CampoInt("y")+pintDesplazamientoY,
	lzSisRegCampo->CampoInt("anchox"),
	lzSisRegCampo->CampoInt("anchoy"),
	pchrPtrCadena);
return 0;
}
int QtBaseMedidas::Texto(int pintX,
			  int pintY,
			  int pintEspacioDisponibleX,
			  int pintEspacioDisponibleY,
			  const char *pchrPtrTexto)
{


char *lchrPtrTexto;
int lintAnchoTexto,lintSiEntro=1,lintIntentos=0;

if(pchrPtrTexto)
{
lchrPtrTexto=strdup(pchrPtrTexto);
do
{
QPainterDibuja->setFont(QFLetra);
lintAnchoTexto=QPainterDibuja->fontMetrics().width(lchrPtrTexto);
if(MMx(pintEspacioDisponibleX)>lintAnchoTexto)
{
      QPainterDibuja->drawText(MMx(pintX),MMy(pintY),lchrPtrTexto);
      lintSiEntro=1;
}
else
{
TextoConUnCaracterMenos(lchrPtrTexto);
lintSiEntro=0;
}
lintIntentos++;
}while(!lintSiEntro && 
	lintIntentos<25);
}
return SePoneNumeroPagina(pintY);
}
int QtBaseMedidas::SePoneNumeroPagina(int pintY)
{
if(pintY>=225)
return EsDispositivoExterno();
else
return 0;
}
void QtBaseMedidas::TextoConUnCaracterMenos(char *pchrPtrTexto)
{
int lintTamano=strlen(pchrPtrTexto);
*(pchrPtrTexto+lintTamano-1)=0;
}
void QtBaseMedidas::Letra(const QFont &pQFLetra)
{
    QFLetra=pQFLetra;
}
int QtBaseMedidas::EsDispositivoExterno()
{
  if(QPainterDibuja)
  return QPainterDibuja->device()->isExtDev();
  else
  return 0;
}
void QtBaseMedidas::NumeroPagina(int *pintPtrY)
{
char lchrArrPagina[128];
    intPaginas++;
    sprintf(lchrArrPagina,"Pagina %d",intPaginas);
    Texto(90,270,300,20,lchrArrPagina);
    ((QPrinter *)QPainterDibuja->device())->newPage();
}
