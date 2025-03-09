#include <EstructurasSISCOM.h>
#include <string.h>
#include <stdio.h>
void LlenaEstructuraDeError(int pintNumError,int pintSiContinua,char *pchrPtrFuncion,char *pchrPtrErrorLogico,STRUCTError *pSTRUCTErrorPtrReg)
{

	pSTRUCTErrorPtrReg->intNumError=pintNumError;
	pSTRUCTErrorPtrReg->intSiContinua=pintSiContinua;
	strcpy(pSTRUCTErrorPtrReg->chrNmbFuncion,pchrPtrFuncion);
	strcpy(pSTRUCTErrorPtrReg->chrErrorLogico,pchrPtrErrorLogico);

}	
int SeDetectoError(STRUCTError pSTRUCTErrorErr)
{
 
  return pSTRUCTErrorErr.intNumError ? 1 : 0;	
}
int ImprimeSTRUCTProcesosYDll(STRUCTProcesosYDll pstcSTRUCTProcesosYDllDat)
{
	printf("[STRUCTProcesosYDll]\n");
	printf("{chrArrNombreProceso=%s,\n",pstcSTRUCTProcesosYDllDat.chrArrNombreProceso);
	printf("chrArrNombreDll=%s,\n",pstcSTRUCTProcesosYDllDat.chrArrNombreDll);
	printf("lngTipoDeMovimiento=%ld\n}\n",pstcSTRUCTProcesosYDllDat.lngTipoDeMovimiento);

}
