#include <ProductosE.h>
#include <SiscomDesarrollo3Qt++.h>
FILE *gPtrFleArchivoLog3Qt;
FILE *gPtrFleArchivoLog;


void EliminaEspaciosCampos(char **pchrPtrCampos)
{
     while(*pchrPtrCampos)
     {
	SiscomDesarrollo3Qt::EliminaEspaciosInicio(*pchrPtrCampos);
	SiscomDesarrollo3Qt::EliminaEspaciosFinal(*pchrPtrCampos);
	pchrPtrCampos++;
     }
}
void AgregaLeyendaSinArmar(const char *pchrPtrDsc,
			   char *pchrPtrSalida)
{
strcpy(pchrPtrSalida,pchrPtrDsc);
strcat(pchrPtrSalida," ");
strcat(pchrPtrSalida,"(Sin Armar)");
}
ProductoE *FormaProducto(const char *pchrPtrCadena)
{
char **lchrPtrCampos;
char lchrArrDsc[1024];
SiscomDesarrollo3Qt::CadenasPorSeparador(pchrPtrCadena,
					 '|',
					 &lchrPtrCampos);
EliminaEspaciosCampos(lchrPtrCampos);
AgregaLeyendaSinArmar(lchrPtrCampos[1],lchrArrDsc);
SiscomEscribeLog3Qt("(%s) (%s)",lchrPtrCampos[0],lchrArrDsc);
return new ProductoE(lchrPtrCampos[0],
		     lchrArrDsc,
		     "0",
		     "1");

}
void LeeProductos(FILE *pPtrFleArchivo,
		 ProductosE *pProductos)
{
char lchrArrLinea[256];
   while(!SiscomDesarrollo3Qt::LeeLinea(pPtrFleArchivo,lchrArrLinea))
   {
	(*pProductos) << FormaProducto(lchrArrLinea);
   }

}
void RegistraProductos(int pintPuerto,
			const char *pchrPtrDirIp,
			ProductosE *pProductosE)
{
SiscomEscribeLog3Qt("Enviando Productos:(%d,%s)",pintPuerto,pchrPtrDirIp);
ConsultaProductosE lCnsProdReg(new SiscomDatCom(pintPuerto,pchrPtrDirIp));
lCnsProdReg.RegistraProductos(*pProductosE);

}
int main(int pintArgc,
	 char **pchrPtrArgv)
{
FILE *lPtrFleArchivo;
ProductosE lProductos;
gPtrFleArchivoLog3Qt=stdout;
gPtrFleArchivoLog=stdout;

SiscomEscribeLog3Qt("");
if((lPtrFleArchivo=fopen(pchrPtrArgv[1],"r")))
{
   SiscomEscribeLog3Qt("Abriendo:%s",pchrPtrArgv[1]);
   LeeProductos(lPtrFleArchivo,&lProductos);
   RegistraProductos(atoi(pchrPtrArgv[2]),pchrPtrArgv[3],&lProductos);
}

}
