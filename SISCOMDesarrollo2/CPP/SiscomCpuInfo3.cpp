#include <SiscomCpuInfo3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
#include <stdlib.h>
SiscomCpuInfo::SiscomCpuInfo():
		FlePtrArchivo(0),
		intNumParametro(0)
{
   IniciaMemoriaCpuInfo();
   IniciaDatosCpu();
}
SiscomCpuInfo::SiscomCpuInfo(FILE *pFlePtrArchivo):
		FlePtrArchivo(pFlePtrArchivo),
		intCpuNum(0),
		intNumParametro(0)
{
   IniciaMemoriaCpuInfo();
 IniciaDatosCpu();
 LeeArchivo();
}
SiscomCpuInfo::SiscomCpuInfo(const char *pchrPtrArchivo):
		FlePtrArchivo(0),
		intCpuNum(0),
		intNumParametro(0)
{
   IniciaMemoriaCpuInfo();
   AbreArchivo(pchrPtrArchivo);
 IniciaDatosCpu();
 LeeArchivo();
}
SiscomCpuInfo::~SiscomCpuInfo()
{
if(FlePtrArchivo)
fclose(FlePtrArchivo);
}
int SiscomCpuInfo::CpusSistema()
{
  return intNumCpus;
}
void SiscomCpuInfo::CpuNum(int pintCpuNum)
{
	intCpuNum=pintCpuNum;
}
void SiscomCpuInfo::AbreArchivo(const char *pchrPtrArchivo)
{
  
  if(!(FlePtrArchivo=fopen(pchrPtrArchivo,"r")))
  SiscomEscribeLog3Qt("No se pudo abrir el archivo:%s",pchrPtrArchivo);


}
void SiscomCpuInfo::ParametroDato(const char *pchrPtrParametroDato,
				  char *pchrPtrParametro,
				  char *pchrPtrDato)
{
      while(*pchrPtrParametroDato!='=')
      {
	 *pchrPtrParametro=*pchrPtrParametroDato;
	 pchrPtrParametro++;
	 pchrPtrParametroDato++;
      }
      *pchrPtrParametro=0;
      *pchrPtrParametroDato++;
      while(*pchrPtrParametroDato)
      {
	 *pchrPtrDato=*pchrPtrParametroDato;
	 pchrPtrDato++;
	 pchrPtrParametroDato++;
      }
	*pchrPtrDato=0;
}
SiscomCpuInfo &SiscomCpuInfo::operator<<(const char *pchrPtrParametroDato)
{
char lchrArrParametro[128];
char lchrArrDato[1024];
ParametroDato(pchrPtrParametroDato,lchrArrParametro,lchrArrDato);
AsignaDatoParametro(lchrArrParametro,lchrArrDato);
return *this;
}
int SiscomCpuInfo::EsElUltimoParametro()
{
   return intNumParametro==29;
}
const char *SiscomCpuInfo::SiguienteParametro(char *pchrPtrParametro)
{
const char *lchrPtrDato=0;
      if((lchrPtrDato=chrArrValoresCpu[intCpuNum][intNumParametro]))
      strcpy(pchrPtrParametro,chrArrDatosCpu[intNumParametro]);
      intNumParametro++;
      return lchrPtrDato;
      
      
}
void SiscomCpuInfo::ObtenModeloFamilia(SiscomCpuInfo *pSisCpuInfo,
				       int *pintPtrCpuFamily,
				       int *pintPtrModel)
{
 SiscomEscribeLog3Qt("");
  *pintPtrCpuFamily=atoi((*pSisCpuInfo)["cpu family"]);
  *pintPtrModel=atoi((*pSisCpuInfo)["model"]);
  SiscomEscribeLog3Qt("CpuFamily=%d Model=%d",
  		       *pintPtrCpuFamily,
		       *pintPtrModel);
}
int SiscomCpuInfo::EsCpu_6_23(SiscomCpuInfo *pSisCpuInfo)
{
return !strcmp((*this)["vendor_id"],(*pSisCpuInfo)["vendor_id"])		&&
       !strcmp((*this)["cpu family"],(*pSisCpuInfo)["cpu family"]) 		&&
       !strcmp((*this)["model"],(*pSisCpuInfo)["model"])			&&
       !strcmp((*this)["model name"],(*pSisCpuInfo)["model name"])		&&
       !strcmp((*this)["stepping"],(*pSisCpuInfo)["stepping"])		 	&&
       !strcmp((*this)["cache size"],(*pSisCpuInfo)["cache size"])		&&
       !strcmp((*this)["physical id"],(*pSisCpuInfo)["physical id"])		&&
       !strcmp((*this)["siblings"],(*pSisCpuInfo)["siblings"])			&&
       !strcmp((*this)["cpu cores"],(*pSisCpuInfo)["cpu cores"])		&&
       !strcmp((*this)["apicid"],(*pSisCpuInfo)["apicid"])			&&
       !strcmp((*this)["initial apicid"],(*pSisCpuInfo)["initial apicid"])	&&
       !strcmp((*this)["fpu"],(*pSisCpuInfo)["fpu"])				&&
       !strcmp((*this)["fpu_exception"],(*pSisCpuInfo)["fpu_exception"])	&&
       !strcmp((*this)["cpuid level"],(*pSisCpuInfo)["cpuid level"])		&&
       !strcmp((*this)["wp"],(*pSisCpuInfo)["wp"])				&&
       !strcmp((*this)["flags"],(*pSisCpuInfo)["flags"])			&&
       !strcmp((*this)["clflush size"],(*pSisCpuInfo)["clflush size"])		&&
       !strcmp((*this)["cache_alignment"],(*pSisCpuInfo)["cache_alignment"])	&&
       !strcmp((*this)["address sizes"],(*pSisCpuInfo)["address sizes"]);

}
int SiscomCpuInfo::EsCpu_6_15(SiscomCpuInfo *pSisCpuInfo)
{
	return EsCpu_6_23(pSisCpuInfo);
}
int SiscomCpuInfo::EsCpu_6_7(SiscomCpuInfo *pSisCpuInfo)
{
SiscomEscribeLog3Qt("");
return !strcmp((*this)["vendor_id"],(*pSisCpuInfo)["vendor_id"])		&&
       !strcmp((*this)["cpu family"],(*pSisCpuInfo)["cpu family"]) 		&&
       !strcmp((*this)["model"],(*pSisCpuInfo)["model"])			&&
       !strcmp((*this)["model name"],(*pSisCpuInfo)["model name"])		&&
       !strcmp((*this)["stepping"],(*pSisCpuInfo)["stepping"])		 	&&
       !strcmp((*this)["cache size"],(*pSisCpuInfo)["cache size"])		&&
       !strcmp((*this)["fdiv_bug"],(*pSisCpuInfo)["fdiv_bug"])			&& 
       !strcmp((*this)["hlt_bug"],(*pSisCpuInfo)["hlt_bug"])			&&
       !strcmp((*this)["f00f_bug"],(*pSisCpuInfo)["f00f_bug"])			&&
       !strcmp((*this)["coma_bug"],(*pSisCpuInfo)["coma_bug"])			&&
       !strcmp((*this)["fpu"],(*pSisCpuInfo)["fpu"])				&&
       !strcmp((*this)["fpu_exception"],(*pSisCpuInfo)["fpu_exception"])	&&
       !strcmp((*this)["cpuid level"],(*pSisCpuInfo)["cpuid level"])		&&
       !strcmp((*this)["wp"],(*pSisCpuInfo)["wp"])				&&
       !strcmp((*this)["flags"],(*pSisCpuInfo)["flags"])			&&
       !strcmp((*this)["clflush size"],(*pSisCpuInfo)["clflush size"])		&&
       !strcmp((*this)["cache_alignment"],(*pSisCpuInfo)["cache_alignment"])	&&
       !strcmp((*this)["address sizes"],(*pSisCpuInfo)["address sizes"]);

}

int SiscomCpuInfo::EsCpu_6_28(SiscomCpuInfo *pSisCpuInfo)
{
SiscomEscribeLog3Qt("");
return !strcmp((*this)["vendor_id"],(*pSisCpuInfo)["vendor_id"])		&&
       !strcmp((*this)["cpu family"],(*pSisCpuInfo)["cpu family"]) 		&&
       !strcmp((*this)["model"],(*pSisCpuInfo)["model"])			&&
       !strcmp((*this)["model name"],(*pSisCpuInfo)["model name"])		&&
       !strcmp((*this)["stepping"],(*pSisCpuInfo)["stepping"])		 	&&
       !strcmp((*this)["cache size"],(*pSisCpuInfo)["cache size"])		&&
       !strcmp((*this)["fdiv_bug"],(*pSisCpuInfo)["fdiv_bug"])			&& 
       !strcmp((*this)["hlt_bug"],(*pSisCpuInfo)["hlt_bug"])			&&
       !strcmp((*this)["f00f_bug"],(*pSisCpuInfo)["f00f_bug"])			&&
       !strcmp((*this)["coma_bug"],(*pSisCpuInfo)["coma_bug"])			&&
       !strcmp((*this)["fpu"],(*pSisCpuInfo)["fpu"])				&&
       !strcmp((*this)["fpu_exception"],(*pSisCpuInfo)["fpu_exception"])	&&
       !strcmp((*this)["cpuid level"],(*pSisCpuInfo)["cpuid level"])		&&
       !strcmp((*this)["wp"],(*pSisCpuInfo)["wp"])				&&
       !strcmp((*this)["flags"],(*pSisCpuInfo)["flags"])			&&
       !strcmp((*this)["clflush size"],(*pSisCpuInfo)["clflush size"]);

}

int SiscomCpuInfo::EsCpu_6_14(SiscomCpuInfo *pSisCpuInfo)
{
SiscomEscribeLog3Qt("");
return !strcmp((*this)["vendor_id"],(*pSisCpuInfo)["vendor_id"])		&&
       !strcmp((*this)["cpu family"],(*pSisCpuInfo)["cpu family"]) 		&&
       !strcmp((*this)["model"],(*pSisCpuInfo)["model"])			&&
       !strcmp((*this)["model name"],(*pSisCpuInfo)["model name"])		&&
       !strcmp((*this)["stepping"],(*pSisCpuInfo)["stepping"])		 	&&
       !strcmp((*this)["cache size"],(*pSisCpuInfo)["cache size"])		&&
       !strcmp((*this)["fdiv_bug"],(*pSisCpuInfo)["fdiv_bug"])			&& 
       !strcmp((*this)["hlt_bug"],(*pSisCpuInfo)["hlt_bug"])			&&
       !strcmp((*this)["f00f_bug"],(*pSisCpuInfo)["f00f_bug"])			&&
       !strcmp((*this)["coma_bug"],(*pSisCpuInfo)["coma_bug"])			&&
       !strcmp((*this)["fpu"],(*pSisCpuInfo)["fpu"])				&&
       !strcmp((*this)["fpu_exception"],(*pSisCpuInfo)["fpu_exception"])	&&
       !strcmp((*this)["cpuid level"],(*pSisCpuInfo)["cpuid level"])		&&
       !strcmp((*this)["wp"],(*pSisCpuInfo)["wp"])				&&
       !strcmp((*this)["flags"],(*pSisCpuInfo)["flags"])			&&
       !strcmp((*this)["clflush size"],(*pSisCpuInfo)["clflush size"]);

}

int SiscomCpuInfo::EsCpu_15_2(SiscomCpuInfo *pSisCpuInfo)
{
return EsCpu_15_4(pSisCpuInfo);
}

int SiscomCpuInfo::EsCpu_15_6(SiscomCpuInfo *pSisCpuInfo)
{
return EsCpu_15_4(pSisCpuInfo);
}

int SiscomCpuInfo::EsCpu_15_4(SiscomCpuInfo *pSisCpuInfo)
{
SiscomEscribeLog3Qt("Revisarrrrrrrrrrr solo para que pueda probar");
/*
return !strcmp((*this)["vendor_id"],(*pSisCpuInfo)["vendor_id"])		&&
       !strcmp((*this)["cpu family"],(*pSisCpuInfo)["cpu family"]) 		&&
       !strcmp((*this)["model"],(*pSisCpuInfo)["model"])			&&
       !strcmp((*this)["model name"],(*pSisCpuInfo)["model name"])		&&
       !strcmp((*this)["stepping"],(*pSisCpuInfo)["stepping"])		 	&&
       !strcmp((*this)["fpu"],(*pSisCpuInfo)["fpu"])				&&
       !strcmp((*this)["fpu_exception"],(*pSisCpuInfo)["fpu_exception"])	&&
       !strcmp((*this)["cpuid level"],(*pSisCpuInfo)["cpuid level"])		&&
       !strcmp((*this)["wp"],(*pSisCpuInfo)["wp"])				&&
       !strcmp((*this)["flags"],(*pSisCpuInfo)["flags"])			&&
       !strcmp((*this)["clflush size"],(*pSisCpuInfo)["clflush size"]);
       */
return 1;

}
int SiscomCpuInfo::EsCpu_42_6(SiscomCpuInfo *pSisCpuInfo)
{
return EsCpu_15_4(pSisCpuInfo);
}
int SiscomCpuInfo::operator==(SiscomCpuInfo *pSisCpuInfo)
{
int lintCpuFamily;
int lintModel;
ObtenModeloFamilia(pSisCpuInfo,&lintCpuFamily,&lintModel);
if(lintCpuFamily==6 &&
lintModel==23)
return EsCpu_6_23(pSisCpuInfo);
else
if(lintCpuFamily==6 &&
lintModel==7)
return EsCpu_6_7(pSisCpuInfo);
else
if(lintCpuFamily==6 &&
lintModel==13)
return EsCpu_6_7(pSisCpuInfo);
else
if(lintCpuFamily==6 &&
lintModel==28)
return EsCpu_6_28(pSisCpuInfo);
else
if(lintCpuFamily==6 &&
lintModel==14)
return EsCpu_6_14(pSisCpuInfo);
else
if(lintCpuFamily==15 &&
lintModel==4)
return EsCpu_15_4(pSisCpuInfo);
if(lintCpuFamily==6 &&
lintModel==15)
return EsCpu_6_15(pSisCpuInfo);

if(lintCpuFamily==15 &&
lintModel==2)
return EsCpu_15_2(pSisCpuInfo);

if(lintCpuFamily==6 &&
lintModel==42)
return EsCpu_15_6(pSisCpuInfo);
if(lintCpuFamily==42 &&
lintModel==6)
return EsCpu_42_6(pSisCpuInfo);

return 1;
SiscomEscribeLog3Qt("El Cpu:%d y familia:%d No estan considerados",
	    lintModel,
	    lintCpuFamily);
}
const char *SiscomCpuInfo::operator[](int pintNDatoCpu)
{
return chrArrDatosCpu[pintNDatoCpu];
}
const char *SiscomCpuInfo::operator[](const char *pchrPtrNmbParametro)
{
int lintNumParametro=ObtenNumeroParametro(pchrPtrNmbParametro);
if(lintNumParametro>=0 && chrArrValoresCpu[intCpuNum][lintNumParametro])
return chrArrValoresCpu[intCpuNum][lintNumParametro];
else
SiscomEscribeLog3Qt("Parametro Nulo:%s NumParametro=%d Cpu=%d",
		pchrPtrNmbParametro,
		lintNumParametro,
		intCpuNum);
}
int SiscomCpuInfo::ObtenNumeroParametro(const char *pchrPtrNmbParametro)
{
int lintContador;
for(lintContador=0;
lintContador<29;
    lintContador++)
{
/*
 SiscomEscribeLog3Qt("Buscando %s en %d %s ",pchrPtrNmbParametro,lintContador,chrArrDatosCpu[lintContador]);
 */
if(chrArrDatosCpu[lintContador] &&
   !strcmp(chrArrDatosCpu[lintContador],pchrPtrNmbParametro))
 return lintContador;
}
 SiscomEscribeLog3Qt("Parametro:%s No Encontrado",pchrPtrNmbParametro);
return -1;
}
int SiscomCpuInfo::LeeLinea(char *pchrPtrLinea)
{
	while((*pchrPtrLinea=getc(FlePtrArchivo))!='\n')
	{
		if(*pchrPtrLinea==EOF)
		break;
		else
		pchrPtrLinea++;

	}
    if(*pchrPtrLinea==EOF)
    {
    *pchrPtrLinea=0;
    return 0;
    }
    if(*pchrPtrLinea=='\n')
    *pchrPtrLinea=0;
    return 1;
}
void SiscomCpuInfo::LeeArchivo()
{
char lchrArrLinea[1024];
char lchrArrParametro[128];
char lchrArrDato[1024];
	
	while(LeeLinea(lchrArrLinea))
	{
	  if(lchrArrLinea[0])
	  {
	  NombreParametroDato(lchrArrLinea,
	  		      lchrArrParametro,
			      lchrArrDato);
	  EliminaTabulador(lchrArrParametro);
	  ObtenNumeroCpu(lchrArrParametro,lchrArrDato);
	  AsignaDatoParametro(lchrArrParametro,lchrArrDato);
	  }
	}
}
void SiscomCpuInfo::ObtenNumeroCpu(const char *pchrPtrParametro,
				   const char *pchrPtrDato)
{
	if(!strcmp(pchrPtrParametro,
		   "processor"))
	{
	intCpuNum=atoi(pchrPtrDato);	
	intNumCpus=intCpuNum+1;
	}

}
		
void SiscomCpuInfo::AsignaDatoParametro(const char *pchrPtrParametro,
					const char *pchrPtrDato)
{
int lintNumParametro;
	if((lintNumParametro=ObtenNumeroParametro(pchrPtrParametro))!=-1)
	 chrArrValoresCpu[intCpuNum][lintNumParametro]=strdup(pchrPtrDato);
	 else
	 SiscomEscribeLog3Qt("No se encontro el parametro:%s",pchrPtrParametro);
}
void SiscomCpuInfo::EliminaTabulador(char *pchrPtrDato)
{
	while(*pchrPtrDato &&
	      *pchrPtrDato!='\t')
	 pchrPtrDato++;
	*pchrPtrDato=0;
}
void SiscomCpuInfo::NombreParametroDato(const char *pchrPtrLinea,
					char *pchrPtrNmbParametro,
					char *pchrPtrDato)
{
     while(*pchrPtrLinea!=':')
     {
      *pchrPtrNmbParametro=*pchrPtrLinea;
      pchrPtrNmbParametro++;
      pchrPtrLinea++;
     }
      *pchrPtrNmbParametro=0;
      pchrPtrLinea++;
      if(*pchrPtrLinea)
      pchrPtrLinea++;
     while(*pchrPtrLinea)
     {
	*pchrPtrDato=*pchrPtrLinea;
	pchrPtrLinea++;
	pchrPtrDato++;
     }
     *pchrPtrDato=0;
}
void SiscomCpuInfo::IniciaMemoriaCpuInfo()
{
int lintContador;
     chrArrValoresCpu=(const char ***)malloc(sizeof(const char **)*10);
for(lintContador=0;
    lintContador<10;
    lintContador++)
  chrArrValoresCpu[lintContador]=(const char **)malloc(sizeof(const char *)*32);

}
void SiscomCpuInfo::NumCpus(int pintNumCpus)
{
intNumCpus=pintNumCpus; 
}
void SiscomCpuInfo::IniciaDatosCpu()
{
chrArrDatosCpu[processor]=strdup("processor");
chrArrDatosCpu[vendor_id]=strdup("vendor_id");
chrArrDatosCpu[cpu_family]=strdup("cpu family");
chrArrDatosCpu[model]=strdup("model");
chrArrDatosCpu[model_name]=strdup("model name");
chrArrDatosCpu[stepping]=strdup("stepping");
chrArrDatosCpu[cpu_MHz]=strdup("cpu MHz");
chrArrDatosCpu[cache_size]=strdup("cache size");
chrArrDatosCpu[physical_id]=strdup("physical id");
chrArrDatosCpu[siblings]=strdup("siblings");
chrArrDatosCpu[core_id]=strdup("core id");
chrArrDatosCpu[cpu_cores]=strdup("cpu cores");
chrArrDatosCpu[apicid]=strdup("apicid");
chrArrDatosCpu[initial_apicid]=strdup("initial apicid");
chrArrDatosCpu[fpu]=strdup("fpu");
chrArrDatosCpu[fpu_exception]=strdup("fpu_exception");
chrArrDatosCpu[cpuid_level]=strdup("cpuid level");
chrArrDatosCpu[wp]=strdup("wp");
chrArrDatosCpu[flags]=strdup("flags");
chrArrDatosCpu[bogomips]=strdup("bogomips");
chrArrDatosCpu[clflush_size]=strdup("clflush size");
chrArrDatosCpu[cache_alignment]=strdup("cache_alignment");
chrArrDatosCpu[address_sizes]=strdup("address sizes");
chrArrDatosCpu[power_management]=strdup("power management");
chrArrDatosCpu[fdiv_bug]=strdup("fdiv_bug");
chrArrDatosCpu[hlt_bug]=strdup("hlt_bug");
chrArrDatosCpu[f00f_bug]=strdup("f00f_bug");
chrArrDatosCpu[coma_bug]=strdup("coma_bug");
chrArrDatosCpu[29]=0;
}
