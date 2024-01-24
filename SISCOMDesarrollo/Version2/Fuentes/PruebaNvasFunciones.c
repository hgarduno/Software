#include <FuncionesComunes.h>
#include <stdlib.h>
void PruebaConsulta();
void PruebaAlta();
void PruebaAlta2();
void GeneraRegistroCotiza(char *,char *,char ***);
int main()
{
PruebaConsulta();
PruebaAlta();
PruebaAlta2();

}
void PruebaAlta2()
{
char **lchrPtrDatosCom,
	**lchrPtrReg,
	**lchrPtrRegistro;
int lintSCliente;
int lintNCampos,
    lintNRegistros,
    lintI,
    lintJ;
StcLtaRegComSISCOM *lSLRCSisUlt=0,
	           *lSLRCSisAct=0;
	SISCOMFormaDatosProtocoloInfoUsuario("hgarduno","hgarduno",&lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoServidor(1645,
					      "127.0.0.1",
					      "libRNDllAltaCotizaProductosSISCOM.so",
					      "RNDllRealizaAltaCotizaProductosSISCOM",
					      &lchrPtrDatosCom);
	SISCOMAnexaRegistroLEnvio(&lSLRCSisUlt,
				  &lSLRCSisAct,
				   6,
				  "%s%s%s%s%s%s",
				  "PROD00",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	SISCOMAnexaRegistroLEnvio(&lSLRCSisUlt,
				  &lSLRCSisAct,
				   6,
				  "%s%s%s%s%s%s",
				  "PROD01",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	SISCOMAnexaRegistroLEnvio(&lSLRCSisUlt,
				  &lSLRCSisAct,
				   6,
				  "%s%s%s%s%s%s",
				  "PROD02",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	SISCOMAnexaRegistroLEnvio(&lSLRCSisUlt,
				  &lSLRCSisAct,
				   6,
				  "%s%s%s%s%s%s",
				  "PROD03",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	SISCOMAnexaRegistroLEnvio(&lSLRCSisUlt,
				  &lSLRCSisAct,
				   6,
				  "%s%s%s%s%s%s",
				  "PROD04",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	SISCOMEnviaInfAlServidor(lchrPtrDatosCom,
				 5,
				 lSLRCSisUlt,
				 &lintSCliente);
	SISCOMObtenInfoDelRegistro(lintSCliente,
				   &lintNCampos,
				   &lintNRegistros);

	printf("Las datos reg %d %d\n",lintNCampos,lintNRegistros);
	for(lintJ=0;lintJ<lintNRegistros;lintJ++)
	{
	SISCOMObtenRegistro(lintSCliente,
		            lintNCampos,
			    &lchrPtrReg);
	for(lintI=0;lintI<lintNCampos;lintI++)
	printf("%s\t",lchrPtrReg[lintI]);
	printf("\n");
	}


}
void PruebaAlta()
{
char **lchrPtrDatosCom,
	**lchrPtrReg,
	**lchrPtrRegistro;
int lintSCliente;
int lintNCampos,
    lintNRegistros,
    lintI,
    lintJ;
StcLtaRegComSISCOM *lSLRCSisUlt=0,
	           *lSLRCSisAct=0,
	           *lSLRCSisPRes=0,
	           *lSLRCSisPResR=0;
	SISCOMFormaDatosProtocoloInfoUsuario("hgarduno","hgarduno",&lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoServidor(1645,
					      "127.0.0.1",
					      "libRNDllAltaCotizaProductosSISCOM.so",
					      "RNDllRealizaAltaCotizaProductosSISCOM",
					      &lchrPtrDatosCom);
	GeneraRegistroCotiza("PROD00","10",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);
	GeneraRegistroCotiza("PROD01","20",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);
	GeneraRegistroCotiza("PROD02","30",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);
	GeneraRegistroCotiza("PROD03","30",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);
	GeneraRegistroCotiza("PROD04","30",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);
	GeneraRegistroCotiza("PROD05","30",&lchrPtrRegistro);
	SISCOMCreaListaRegCom(lchrPtrRegistro,&lSLRCSisUlt,&lSLRCSisAct);

	SISCOMEnviaInfAlServidor(lchrPtrDatosCom,
				 6,
				 lSLRCSisUlt,
				 &lintSCliente);
	SISCOMObtenRespuestaSVR(lintSCliente,
				&lintNCampos,
				&lintNRegistros,
				&lSLRCSisPRes);
	lSLRCSisPResR=lSLRCSisPRes;
	while(lSLRCSisPResR)
	{
	    for(lintI=0;lSLRCSisPResR->chrPtrRegistro[lintI];lintI++)
	     printf("%s\t",lSLRCSisPResR->chrPtrRegistro[lintI]);
	    printf("\n");
	   lSLRCSisPResR=lSLRCSisPResR->LSRCSISCOMPtrSig;
	}
	


}
void GeneraRegistroCotiza(char *pchrPtrCveProducto,
			  char *pchrPtrCantidad,
			  char ***pchrPtrRegistro)
{

  *pchrPtrRegistro=(char **)malloc(sizeof(char *)*7);
  (*pchrPtrRegistro)[0]=(char *)strdup(pchrPtrCveProducto);
  (*pchrPtrRegistro)[1]=(char *)strdup("GENERAL");
  (*pchrPtrRegistro)[2]=(char *)strdup("");
  (*pchrPtrRegistro)[3]=(char *)strdup(pchrPtrCantidad);
  (*pchrPtrRegistro)[4]=(char *)strdup("");
  (*pchrPtrRegistro)[5]=(char *)strdup("");
  (*pchrPtrRegistro)[6]=0;

}
void PruebaConsulta()
{
char **lchrPtrDatosCom;
int lintSCliente;
char **lchrPtrReg;
int lintNCampos,
    lintNRegistros,
    lintI;
	SISCOMFormaDatosProtocoloInfoUsuario("hgarduno","hgarduno",&lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoServidor(1645,
					      "127.0.0.1",
					      "libRNDllConsultas.so",
					      "RNDllCNSIdentificaConsulta",
					      &lchrPtrDatosCom);
	SISCOMFormaDatosProtocoloInfoModuloCNS("libRNDllConsultasComprasSISCOM.so",
					       "RNDllCNSConsultaComprasSISCOM",
					       "XComprasSISCOM",
					       &lchrPtrDatosCom);
	SISCOMEjecutaConsultaSvrReglasDelNegocio(lchrPtrDatosCom,
						 "PROD00",
						 &lintSCliente);
	SISCOMObtenInfoDelRegistro(lintSCliente,
				   &lintNCampos,
				   &lintNRegistros);
	
	SISCOMObtenRegistro(lintSCliente,
		            lintNCampos,
			    &lchrPtrReg);
	printf("Las datos reg %d %d\n",lintNCampos,lintNRegistros);
	for(lintI=0;lintI<lintNCampos;lintI++)
	printf("%s\t",lchrPtrReg[lintI]);
	printf("\n");
				


}
