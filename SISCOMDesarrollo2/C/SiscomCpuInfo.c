#include <SiscomCpuInfo.h>
#include <SiscomDesarrollo2.h>
#include <string.h>

char *gchrPtrCpuInfo[30]=
	{
	 "processor",
	 "vendor_id",
	 "cpu family",
	 "model",
	 "model name",
	 "stepping",
	 "cpu MHz",
	 "cache size",
	 "physical id",
	 "siblings",
	 "core id",
	 "cpu cores",
	 "apicid",
	 "initial apicid",
	 "fpu",
	 "fpu_exception",
	 "cpuid level",
	 "wp",
	 "flags",
	 "bogomips",
	 "clflush size",
	 "cache_alignment",
	 "address sizes",
	 "power management",
	 0
	};

void EliminaPrimerEspacio(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
  if(lchrPtrPaso &&
     *lchrPtrPaso)
  {
  lchrPtrPaso++;
  strcpy(pchrPtrCadena,lchrPtrPaso);
  }

}
void ObtenParametro(const char *pchrPtrParametro,
		    int *pintPtrCpuInfo)
{
int lintContador;

	for(lintContador=0;
	    gchrPtrCpuInfo[lintContador];
	    lintContador++)
	 if(!strcmp(gchrPtrCpuInfo[lintContador],
	 	    pchrPtrParametro))
	 {
	  *pintPtrCpuInfo=lintContador;
	  return ;
	 }

}
void ObtenInformacion(const char *pchrPtrLinea,
		      char *pchrPtrDato,
		      int *pintPtrCpuInfo)
{
char **lchrPtrCpuInfo;
char  lchrArrBuffer[1024];
     if(SiscomAnalizaCadenas(pchrPtrLinea,
     			  ':',
			  lchrArrBuffer,
			  &lchrPtrCpuInfo))
    {
	 SiscomEliminaCaracter('\t',lchrPtrCpuInfo[0]);
	 EliminaPrimerEspacio(lchrPtrCpuInfo[1]);
	 ObtenParametro(lchrPtrCpuInfo[0],pintPtrCpuInfo);
	 if(lchrPtrCpuInfo[1])
	 strcpy(pchrPtrDato,lchrPtrCpuInfo[1]);
	 else
	 pchrPtrDato[0]=0;
    }

}

int SiscomParametrosCpuInfo(FILE *pFlePtrArchivo,
		      StcSiscomCpuInfo *pzCpuInfo)
{
char lchrArrRenglon[1024];
char lchrArrDato[1024];
int lintCpuInfo;
int lintNCpus=0;
  while(!SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrRenglon))
  {
     if(lchrArrRenglon[0])
     {
     ObtenInformacion(lchrArrRenglon,
     		      lchrArrDato,
		      &lintCpuInfo);
     strcpy(pzCpuInfo->chrArrCpuInfo[lintCpuInfo],lchrArrDato);
     if(lintCpuInfo==22)
     {
     pzCpuInfo++;
     lintNCpus++;
     }
     }
  }
return lintNCpus;
}
