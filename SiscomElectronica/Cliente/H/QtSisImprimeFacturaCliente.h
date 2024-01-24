#ifndef __QTSISIMPRIMEFACTURACLIENTE_H__
#define __QTSISIMPRIMEFACTURACLIENTE_H__
#include <QtSisImprimeFactura.h>
class QPainter;
class SiscomRegistro3;
class QtSisImprimeFacturaCliente
{
public:
	QtSisImprimeFacturaCliente(QtSisImprimeFactura *);
	void Cliente(SiscomRegistro3 *pSisReg3Cliente);

	void PuntoInicio(int pintXmm,int pintYmm);
	void PuntoFin(int pintX1mm,int pintY1mm);
	void Dibuja(QPainter *);
	
	void DibujaNombre(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);


	void DibujaCalle(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);


	void DibujaColonia(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);

	void DibujaCP(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);

	void DibujaMunicipio(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);

	void DibujaEstado(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);


	void DibujaRFC(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);
	void DibujaTelefono(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);

	void DibujaColoniaCP(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);

	void DibujaMunicipioEstado(int pintXmm,
			  int pintYmm,
			  int pintX1mm,
			  int pintY1mm,
			  QPainter *pQPDibuja);


private:
private:
	int intXmm;
	int intYmm;
	int intY1mm;
	int intX1mm;

	int intXpx;
	int intYpx;
	int intX1px;
	int intY1px;

	SiscomRegistro3 *SisReg3Cliente;

	QtSisImprimeFactura *QtSisImpFactura;
};
#endif
