#include <CQSisKits.h>
#include <ProductosE.h>
CQSisKitsOp::CQSisKitsOp(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}
const char *CQSisKitsOp::RegistraKit(ProductoE *pProductoE,
			      const char *pchrPtrIdTipoProducto)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomRegistro3 *lSisReg3Respuesta;
SiscomEnvia2("RegistraTipoProducto",
		&lSisReg3LstRespuesta,
		"%s[CveProducto] %s[IdTipoProducto] %s[IdProducto]",
		(*pProductoE)["CveProducto"],
		pchrPtrIdTipoProducto,
		"");
SiscomRegistro3LstContenido(&lSisReg3LstRespuesta);
if((lSisReg3Respuesta=lSisReg3LstRespuesta.first()))
{
    return (*lSisReg3Respuesta)["IdProducto"];
}
else
return 0;
}
