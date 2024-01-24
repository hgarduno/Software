#include <QtSisImprimeFacturaCliente.h>
#include <QtSisPuntoImpresion.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpainter.h>
QtSisImprimeFacturaCliente::QtSisImprimeFacturaCliente(QtSisImprimeFactura *pQtSisImpFactura):QtSisImpFactura(pQtSisImpFactura)
{


}
void QtSisImprimeFacturaCliente::Dibuja(QPainter *pQPDibuja)
{
/*
	DibujaNombre(pQPDibuja);
*/
}
/*
 * Las coordenas de impresion se pasan desde el borde de la
 * hoja, la rutina ajusta al margen de impresion
 *
 */
void QtSisImprimeFacturaCliente::DibujaNombre(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
char lchrArrNombre[256];
SiscomEscribeLog3Qt("La posicion (%d,%d) (%d,%d)",
		    pintXmm,
		    pintYmm,
		    pintX1mm,
		    pintY1mm);
sprintf(lchrArrNombre,
        "%s %s %s",
	(*SisReg3Cliente)["nombre"],
	(*SisReg3Cliente)["apaterno"],
	(*SisReg3Cliente)["amaterno"]);
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Nombre",
				     lchrArrNombre,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrArrNombre);
}

void QtSisImprimeFacturaCliente::DibujaCalle(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrCalle=(*SisReg3Cliente)["calle"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Calle",
				     lchrPtrCalle,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrCalle);
}

void QtSisImprimeFacturaCliente::DibujaColonia(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrColonia=(*SisReg3Cliente)["colonia"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Colonia",
				     lchrPtrColonia,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrColonia);
}


void QtSisImprimeFacturaCliente::DibujaCP(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrCP=(*SisReg3Cliente)["cp"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "CP",
				     lchrPtrCP,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrCP);
}

void QtSisImprimeFacturaCliente::DibujaMunicipio(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrMunicipio=(*SisReg3Cliente)["municipio"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Municipio",
				     lchrPtrMunicipio,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrMunicipio);
}



void QtSisImprimeFacturaCliente::DibujaEstado(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrEstado=(*SisReg3Cliente)["estado"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Estado",
				     lchrPtrEstado,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrEstado);
}


void QtSisImprimeFacturaCliente::DibujaColoniaCP(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
char lchrArrColoniaCP[256];
sprintf(lchrArrColoniaCP,"%s %s",
	(*SisReg3Cliente)["colonia"],
	(*SisReg3Cliente)["cp"]);
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "ColoniaCP",
				     lchrArrColoniaCP,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrArrColoniaCP);
}


void QtSisImprimeFacturaCliente::DibujaMunicipioEstado(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
char lchrArrMunicipioEstado[512];
sprintf(lchrArrMunicipioEstado,"%s %s",
	(*SisReg3Cliente)["municipio"],
	(*SisReg3Cliente)["estado"]);
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "MunicipioEdo",
				     lchrArrMunicipioEstado,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrArrMunicipioEstado);
}
void QtSisImprimeFacturaCliente::DibujaRFC(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrRFC=(*SisReg3Cliente)["rfc"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "RFC",
				     lchrPtrRFC,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrRFC);
}
void QtSisImprimeFacturaCliente::DibujaTelefono(int pintXmm,
					      int pintYmm,
					      int pintX1mm,
					      int pintY1mm,
					      QPainter *pQPDibuja)
{
QtSisPuntoImpresion *lQtSisPtoImp;
const char *lchrPtrTelefono=(*SisReg3Cliente)["telefono"];
lQtSisPtoImp=new QtSisPuntoImpresion(QtSisImpFactura,
				     "Telefono",
				     lchrPtrTelefono,
				     pintXmm,
				     pintYmm,
				     pintX1mm,
				     pintY1mm);
pQPDibuja->drawText(lQtSisPtoImp->Xpx(),
		    lQtSisPtoImp->Ypx(),
		    lchrPtrTelefono);
}

void QtSisImprimeFacturaCliente::Cliente(SiscomRegistro3 *pSisReg3Cliente)
{
 SisReg3Cliente=pSisReg3Cliente;
}
void QtSisImprimeFacturaCliente::PuntoInicio(int pintXmm,
					     int pintYmm)
{
intXmm=pintXmm;
intYmm=pintYmm;
intXpx=QtSisImpFactura->MMAPixeles(intXmm);
intYpx=QtSisImpFactura->MMAPixeles(intYmm);
}
void QtSisImprimeFacturaCliente::PuntoFin(int pintX1mm,
					  int pintY1mm)
{
intX1mm=pintX1mm;
intY1mm=pintY1mm;
intX1px=QtSisImpFactura->MMAPixeles(pintX1mm);
intY1px=QtSisImpFactura->MMAPixeles(pintY1mm);
}
