#include <CSISCOMComunicaciones.h>
#include <stdio.h>


int main()
{
CSISCOMComunicaciones *lCSisCDat;

   lCSisCDat=new CSISCOMComunicaciones(1645,
				       "127.0.0.1",
				       "hgarduno",
				       "hgarduno");
  lCSisCDat->PonDatosDLLAltaServidor(6,
		  			"libRNDllEliminaProductos.so",
				     "RNDllEliminaProducto"); 
  /*
  lCSisCDat->AnexaRegistro(
				  "%s%s%s%s%s%s",
				  "PROD00",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
  lCSisCDat->AnexaRegistro(
				  "%s%s%s%s%s%s",
				  "PROD01",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
	*/
  lCSisCDat->AnexaRegistro(
				  "%s%s%s%s%s%s",
				  "PROD03",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");

  lCSisCDat->AnexaRegistro(
				  "%s%s%s%s%s%s",
				  "PROD05",
				  "GENERAL",
				  "",
			          "10",
				  "",
				  "");
  lCSisCDat->EnviaInformacionAlSvrAlta();
  int lintI;
  /*
  StcLtaRegComSISCOM *lSLRCSisPResR=lCSisCDat->ObtenRegistrosResAlta();
  while(lSLRCSisPResR)
  {
     for(lintI=0;lSLRCSisPResR->chrPtrRegistro[lintI];lintI++)
      printf("%s\t",lSLRCSisPResR->chrPtrRegistro[lintI]);
      printf("\n");
     lSLRCSisPResR=lSLRCSisPResR->LSRCSISCOMPtrSig;
  }
*/




}
