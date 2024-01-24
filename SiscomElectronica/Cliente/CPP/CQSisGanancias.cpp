#include <CQSisGanancias.h>
CQSisGanando::CQSisGanando(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{


}

void CQSisGanando::GananciasPeriodo(const char *pchrPtrIdExpendio,
				   const char *pchrPtrFechaInicio,
				   const char *pchrPtrFechaFin,
				   SiscomRegistro3Lst *pSisReg3Resumen,
				   SiscomRegistro3Lst *pSisReg3GProducto,
				   SiscomRegistro3Lst *pSisReg3GFecha)
{
SiscomRegistro3Lst lSisReg3LstGanancias;
SiscomRegistro3 *lSisReg3Dato;
int lintContador;
SiscomEnvia("ConsultasSiscomElectronica2",
	    &lSisReg3LstGanancias,
	    "%s%s%s%s",
	    "Ganancias",
	    pchrPtrIdExpendio,
	    pchrPtrFechaInicio,
	    pchrPtrFechaFin);
 pSisReg3Resumen->clear();
 pSisReg3GProducto->clear();
 pSisReg3GFecha->clear();
 for(lSisReg3Dato=lSisReg3LstGanancias.first(),
     lintContador=0;
     lSisReg3Dato;
     lSisReg3Dato=lSisReg3LstGanancias.next(),
     lintContador++)
 { 
   if(!lintContador)
    (*pSisReg3Resumen) << lSisReg3Dato ;
   if(!((*lSisReg3Dato)["GananciaProducto"])[0])
    (*pSisReg3GProducto) << lSisReg3Dato ;
   if(!((*lSisReg3Dato)["GananciaFecha"])[0])
    (*pSisReg3GFecha) << lSisReg3Dato;
 }

}
