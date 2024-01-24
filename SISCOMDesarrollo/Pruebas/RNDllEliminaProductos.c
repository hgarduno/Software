#include <FuncionesComunes.h>
void EnviaAlServidorAD(int,const char *,int,StcLtaRegComSISCOM *);
void FormaCadenasInsercion(StcLtaRegComSISCOM *,StcLtaRegComSISCOM **);
int RNDllEliminaProducto(int pintSCliente,
			 int pintTuberia[],
			 int pintPtoCom,
			 char *pchrPtrDirIPSvrAD)
{
int lintNCampos,
    lintNRegistros,
    lintI;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPResR=0;
	SISCOMObtenRespuestaSVR(pintSCliente,
				&lintNCampos,
				&lintNRegistros,
				&lSLRCSisPrim);
	FormaCadenasInsercion(lSLRCSisPrim,&lSLRCSisPResR);
	EnviaAlServidorAD(pintPtoCom,pchrPtrDirIPSvrAD,lintNRegistros,lSLRCSisPResR);


}
void FormaCadenasInsercion(StcLtaRegComSISCOM *pSLRCSisDat,
			   StcLtaRegComSISCOM **pSLRCSisDatReg)
{
StcLtaRegComSISCOM *lSLRCSisPrim=pSLRCSisDat;
StcLtaRegComSISCOM *lSLRCSisActualIns=0;
char lchrArrCadEliminar[1024];
	while(lSLRCSisPrim)
	{
	   sprintf(lchrArrCadEliminar,
		   "delete 				\
		    from compra				\
		    where chrCveProducto='%s';		\
		    delete				\
		    from productos			\
		    where chrCveProducto='%s';		\
		    delete				\
		    from PreciosVentaExistencia 	\
		    where chrCveProducto='%s';		\
		    delete				\
		    from ProductoYProveedor		\
		    where chrCveProducto='%s';		\
		    delete				\
		    from inventario			\
		    where chrCveProducto='%s';",
		   lSLRCSisPrim->chrPtrRegistro[0],
		   lSLRCSisPrim->chrPtrRegistro[0],
		   lSLRCSisPrim->chrPtrRegistro[0],
		   lSLRCSisPrim->chrPtrRegistro[0],
		   lSLRCSisPrim->chrPtrRegistro[0]);
	   SISCOMAnexaRegistroLEnvio(pSLRCSisDatReg,
			   	     &lSLRCSisActualIns,
				     2,
				     "%s%s",
				     lchrArrCadEliminar,
				     "");
	    lSLRCSisPrim=lSLRCSisPrim->LSRCSISCOMPtrSig;
	}


}
void EnviaAlServidorAD(int pintPtoCom,
		      const char *pchrPtrDirIpSvrAD,
		      int pintNRegistros,
		      StcLtaRegComSISCOM *pSLRCSisDat)
{

char **lchrPtrDatosCom;
int lintSocket;
	SISCOMFormaDatosProtocoloInfoUsuario("hgarduno","hgarduno",&lchrPtrDatosCom);

	SISCOMFormaDatosProtocoloInfoUsuario("hgarduno","hgarduno",&lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoServidor(pintPtoCom,
				              (char *)pchrPtrDirIpSvrAD,
					      "libADDllEliminaProductos.so",
					      "ADDllEliminaProductos",
					      &lchrPtrDatosCom);
	SISCOMEnviaInfAlServidor(lchrPtrDatosCom,
			         pintNRegistros,
				 pSLRCSisDat,
				 &lintSocket);
				 
}
