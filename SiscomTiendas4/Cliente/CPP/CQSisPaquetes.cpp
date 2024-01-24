#include <CQSisPaquetes.h>
#include <string.h>
CQSisPaquete::CQSisPaquete(const char *pchrPtrIdPaquete,
			   const char *pchrPtrClave,
			   const char *pchrPtrDescripcion)
{

(*this) 						<< 
	new SiscomCampo3("IdPaquete",pchrPtrIdPaquete)	<<
	new SiscomCampo3("Clave",pchrPtrClave)		<<
	new SiscomCampo3("Descripcion",pchrPtrDescripcion);

}
CQSisPaqueteProducto::CQSisPaqueteProducto(const char *pchrPtrIdPaquete,
					   const char *pchrPtrIdProducto,
					   const char *pchrPtrCantidad)
{
(*this) 							<<
	new SiscomCampo3("IdPaquete",pchrPtrIdPaquete)		<<
	new SiscomCampo3("IdProducto",pchrPtrIdProducto)	<<
	new SiscomCampo3("Cantidad",pchrPtrCantidad)  ;

}
CQSisOpPaquetes::CQSisOpPaquetes(SiscomDatCom *pSisDatCom):
		   SiscomOperaciones3(pSisDatCom)
{


}

void CQSisOpPaquetes::RegistraPaquete(const char *pchrPtrClave,
				      const char *pchrPtrDescripcion,
				      char *pchrPtrIdPaquete)
{
SiscomRegistro3Lst lSReg3LstEnvio;
SiscomRegistro3Lst lSReg3LstRegreso;


lSReg3LstEnvio << new CQSisPaquete(pchrPtrIdPaquete,
				   pchrPtrClave,
				   pchrPtrDescripcion);
SiscomEnvia("RegistraPaquete",
	    &lSReg3LstEnvio,
	    &lSReg3LstRegreso);

strcpy(pchrPtrIdPaquete,
       lSReg3LstRegreso["IdPaquete"]);
}
void CQSisOpPaquetes::ProductosAlPaquete(
			const char *pchrPtrIdPaquete,
			SiscomRegistro3Lst *pSReg3Productos)
{
SiscomRegistro3Lst lSReg3LstRegreso;
SiscomEnvia("ProductosAlPaquete",
	    pSReg3Productos,
	    &lSReg3LstRegreso);


}
void CQSisOpPaquetes::Paquetes(SiscomRegistro3Lst *pSReg3LPaquetes)
{
SiscomEnvia("ConsultaTiendas4",
	    pSReg3LPaquetes,
	    "%s",
	    "PaquetesRegistrados");
}

void CQSisOpPaquetes::ProductosDelPaquete(const char *pchrPtrIdPaquete,
					  SiscomRegistro3Lst *pSReg3LProductos)
{
SiscomEnvia("ConsultaTiendas4",
	    pSReg3LProductos,
	    "%s%s",
	    "ProductosDelPaquete",
	    pchrPtrIdPaquete);

}
void CQSisOpPaquetes::EliminaProducto(const char *pchrPtrIdPaquete,
			      const char *pchrPtrIdProducto)
{
SiscomRegistro3Lst lSReg3LstResElimina;
SiscomRegistro3Lst lSReg3LstProductoPaq;
lSReg3LstProductoPaq	<<
new CQSisPaqueteProducto(pchrPtrIdPaquete,pchrPtrIdProducto,"");
SiscomEnvia("EliminaProductoPaquete",
	    &lSReg3LstProductoPaq,
	    &lSReg3LstResElimina);
}


void CQSisOpPaquetes::AnexarProducto(CQSisPaqueteProducto *pCQSisProdPaquete)
{
SiscomRegistro3Lst lSReg3LstResElimina;
SiscomRegistro3Lst lSReg3LstProductoPaq;
lSReg3LstProductoPaq	<<
pCQSisProdPaquete ;
SiscomEnvia("AnexarProductoPaquete",
	    &lSReg3LstProductoPaq,
	    &lSReg3LstResElimina);
}

void CQSisOpPaquetes::EliminaPaquete(const char *pchrPtrIdPaquete)
{
SiscomRegistro3Lst lSReg3LstResElimina;
SiscomRegistro3Lst lSReg3LstProductoPaq;
lSReg3LstProductoPaq	<<
new CQSisPaquete(pchrPtrIdPaquete,"","");
SiscomEnvia("EliminaPaquete",
	    &lSReg3LstProductoPaq,
	    &lSReg3LstResElimina);
}
