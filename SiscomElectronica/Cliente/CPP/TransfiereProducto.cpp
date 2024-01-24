#include <ProductosE.h>
#include <TransfiereProducto.h>
RegProductoTransfiere::RegProductoTransfiere(ProductoE *pProducto,
					    const char *pchrPtrIdMatriz,
					    const char *pchrPtrIdExpendio,
					    const char *pchrPtrIdEmpleado)
{

	SRegistroPro2				<<
	"CveProducto"				<<
	"Cantidad"				<<
	"IdMatriz"				<<
	"IdExpendio"				<<
	"IdEmpleado"				<<
	"Existencia"				<<
	"EdoConexion";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 								<<
	SiscomCampoPro2("CveProducto",pProducto->SRegistrosPro2["CveProducto"])	<<
	SiscomCampoPro2("Cantidad",pProducto->SRegistrosPro2["Cantidad"])	<<
	SiscomCampoPro2("IdMatriz",pchrPtrIdMatriz)				<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)				<<
	SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado)				<<
	SiscomCampoPro2("Existencia","")					<<
	SiscomCampoPro2("EdoConexion","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
RegProductoTransfiere::RegProductoTransfiere(const char *pchrPtrCveProducto,
					       const char *pchrPtrCantidad,
					       const char *pchrPtrIdMatriz,
					       const char *pchrPtrIdExpendio,
					       const char *pchrPtrIdEmpleado)
{
	SRegistroPro2	<<
	"CveProducto"	<<
	"Cantidad"	<<
	"IdMatriz"	<<
	"IdExpendio"	<<
	"IdEmpleado";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 						<<
	SiscomCampoPro2("CveProducto",pchrPtrCveProducto)	<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad)		<<
	SiscomCampoPro2("IdMatriz",pchrPtrIdMatriz)		<<
	SiscomCampoPro2("IdExpendio",pchrPtrIdExpendio)		<<
	SiscomCampoPro2("IdEmpleado",pchrPtrIdEmpleado);
	SRegistrosPro2.SiscomAnexaRegistro();
}

RegsProductoTransfiere::RegsProductoTransfiere()
{

}
RegsProductoTransfiere &RegsProductoTransfiere::operator<<(RegProductoTransfiere *pRegPTransfiere)
{
	append(pRegPTransfiere);
	return *this;
}
RegProductoTransfiere *RegsProductoTransfiere::operator[](SiscomRegistrosPro2 *pSisRegPro2Producto)
{
RegProductoTransfiere *lRegProdTransfiere;
for(lRegProdTransfiere=first();
    lRegProdTransfiere;
    lRegProdTransfiere=next())
{
    if(!strcmp((*lRegProdTransfiere)["CveProducto"],
    	       (*pSisRegPro2Producto)["CveProducto"]))
     return lRegProdTransfiere;
}
return 0;
}
OpTransfiereProductos::OpTransfiereProductos(SiscomDatCom *pSisDatCom):
	SisDatCom(pSisDatCom)
{


}
void OpTransfiereProductos::EjecutaTransferencia(RegsProductoTransfiere &pRegsProdTransfiere)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pRegsProdTransfiere);
		lSGenOp.SiscomEjecutaEnvio("TransfiereProductos");
		AnalizaRegresoEnvio((const SiscomComunicaSrv *)lSGenOp);
}

void OpTransfiereProductos::ValidaExistencia(RegsProductoTransfiere &pRegsProdTransfiere)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pRegsProdTransfiere);
		lSGenOp.SiscomEjecutaEnvio("ValidaExistencia");
		AnalizaRegresoEnvio((const SiscomComunicaSrv *)lSGenOp);
}

void OpTransfiereProductos::AnalizaRegresoEnvio(const SiscomComunicaSrv *pSComunicaSrv)
{
SisRegs2NoAlcanza=new SiscomRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
 	chrPtrEdoEnvio=!strcmp((*SisRegs2NoAlcanza)["EdoConexion"],"Conexion Exitosa") ?
		        0 : (*SisRegs2NoAlcanza)["EdoConexion"];

delete pSComunicaSrv;
}
const char *OpTransfiereProductos::ObtenEdoEnvio()
{
	return chrPtrEdoEnvio;

}
SiscomRegistrosPro2 *OpTransfiereProductos::ProductosNoAlcanza()
{
  return SisRegs2NoAlcanza;
}
int OpTransfiereProductos::NoAlcanza()
{
   return !strcmp(chrPtrEdoEnvio,"No Alcanza");
}
