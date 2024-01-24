#include <SiscomCreaModuloValidacionCpuInfo.h>
#include <SiscomCpuInfo3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <stdio.h>
SiscomCreaModuloValidacionCpuInfo::SiscomCreaModuloValidacionCpuInfo(
				const char *pchrPtrDirTrabajo,
				const char *pchrPtrMaquina,
				const char *pchrPtrCpuInfo):
				chrPtrDirTrabajo(pchrPtrDirTrabajo),
				chrPtrMaquina(pchrPtrMaquina),
				chrPtrCpuInfo(pchrPtrCpuInfo)
{
CreaMakefile();
CpuInfoCPP();
CpuInfoH();
UtilizacionCPP();
UtilizacionH();
}

void SiscomCreaModuloValidacionCpuInfo::CreaMakefile()
{
FILE *lFlePtrMakefile;
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/%s",
	chrPtrDirTrabajo,
	"Makefile");
lFlePtrMakefile=fopen(lchrArrArchivo,"w");
fprintf(lFlePtrMakefile,
"include $(DIRDesarrolloHGE)/SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk		  \n"
"OpCompilacion=-c $(DEBUG) $(OpCSiscom)								  \n"
"OpModulos=-shared $(DEBUG) $(OpCSiscom)							  \n"
"Include=	-I $(QTDIR)/include								\\\n"
"		-I H										\\\n"
"		-I $(DIRLIBSISCOM2)/H								  \n"
"												  \n"
"												  \n"
"Archivos_O_SisUtilizacion%s=O/SiscomCpuInfo%s.o						\\\n"
"			     O/UtilizacionSiscom%s.o			 	  		  \n"
"												  \n"
"Bibliotecas=	-L$(QTDIR)/lib									\\\n"
"		-L$(DIRLIBSISCOM2)								\\\n"
"		-lSiscomComunicaciones++							\\\n"
"		-lSiscomDesarrollo2								\\\n"
"		-lqt-mt										  \n"
"												  \n"
"all:SO/libSiscomVentasUtilizacion%s.so								  \n"
"												  \n"
"												  \n"
"SO/libSiscomVentasUtilizacion%s.so:$(Archivos_O_SisUtilizacion%s)				  \n"
"	@echo Generando $@									  \n"
"	@$(CXX) $(OpModulos)									\\\n"
"	-o $@											\\\n"
"	$(Archivos_O_SisUtilizacion%s)								\\\n"
"	$(Bibliotecas)",
	chrPtrMaquina,
	chrPtrMaquina,
	chrPtrMaquina,
	chrPtrMaquina,
	chrPtrMaquina,
	chrPtrMaquina,
	chrPtrMaquina);
fclose(lFlePtrMakefile);
}
void SiscomCreaModuloValidacionCpuInfo::CpuInfoH()
{
FILE *lFlePtrCpuInfo;
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/H/SiscomCpuInfo%s.h",
	chrPtrDirTrabajo,
	chrPtrMaquina);
lFlePtrCpuInfo=fopen(lchrArrArchivo,"w");
fprintf(lFlePtrCpuInfo,
"#ifndef __SISCOMCPUINFO%s_H__			\n"
"#define __SISCOMCPUINFO%s_H__			\n"
"#include <SiscomCpuInfo3.h>			\n"
"class SiscomCpuInfo%s:public SiscomCpuInfo\n"
"{						\n"
"private:					\n"
"	void AsignaCpuInfo();			\n"
"public:					\n"
"	SiscomCpuInfo%s();			\n"
"};						\n"
"extern \"C\" SiscomCpuInfo%s *CpuInfo();	\n"
"#endif						\n",
CambiaMayusculas((char *)chrPtrMaquina),
CambiaMayusculas((char *)chrPtrMaquina),
chrPtrMaquina,
chrPtrMaquina,
chrPtrMaquina);
fclose(lFlePtrCpuInfo);

}
void SiscomCreaModuloValidacionCpuInfo::CpuInfoCPP()
{
FILE *lFlePtrCpuInfo;
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/CPP/SiscomCpuInfo%s.cpp",
	chrPtrDirTrabajo,
	chrPtrMaquina);
lFlePtrCpuInfo=fopen(lchrArrArchivo,"w");
fprintf(lFlePtrCpuInfo,
"#include <SiscomCpuInfo%s.h>		\n"
"SiscomCpuInfo%s *CpuInfo()		\n"
"{					\n"
"return new SiscomCpuInfo%s();		\n"
"}					\n"
"SiscomCpuInfo%s::SiscomCpuInfo%s()	\n"
"{					\n"
"NumCpus(2);				\n"
"CpuNum(0);				\n"
"AsignaCpuInfo();			\n"
"}					\n",
chrPtrMaquina,
chrPtrMaquina,
chrPtrMaquina,
chrPtrMaquina,
chrPtrMaquina);
CreaCpuInfo(lFlePtrCpuInfo,CpuInfo());
fclose(lFlePtrCpuInfo);
}
void SiscomCreaModuloValidacionCpuInfo::CreaCpuInfo(FILE *pFlePtrArchivo,
						    SiscomCpuInfo *pSisCpuInfo)
{
const char *lchrPtrDato;
char lchrArrParametro[128];

fprintf(pFlePtrArchivo,
"void SiscomCpuInfo%s::AsignaCpuInfo()			\n"
"{							\n",
chrPtrMaquina);
while(!pSisCpuInfo->EsElUltimoParametro())
{
if(lchrPtrDato=pSisCpuInfo->SiguienteParametro(lchrArrParametro))
{
fprintf(pFlePtrArchivo,
"(*this) <<\"%s=%s\";					\n",
lchrArrParametro,
lchrPtrDato);
}
}
fprintf(pFlePtrArchivo,"}				\n");
	
}
SiscomCpuInfo *SiscomCreaModuloValidacionCpuInfo::CpuInfo()
{
SiscomEscribeLog3Qt("%s",chrPtrCpuInfo);
  return new SiscomCpuInfo(chrPtrCpuInfo);
}

void SiscomCreaModuloValidacionCpuInfo::UtilizacionCPP()
{
FILE *lFlePtrUtilizacion;
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/CPP/UtilizacionSiscom%s.cpp",
	chrPtrDirTrabajo,
	chrPtrMaquina);
lFlePtrUtilizacion=fopen(lchrArrArchivo,"w");

fclose(lFlePtrUtilizacion);
}
void SiscomCreaModuloValidacionCpuInfo::UtilizacionH()
{
FILE *lFlePtrUtilizacion;
char lchrArrArchivo[256];
sprintf(lchrArrArchivo,
	"%s/H/UtilizacionSiscom%s.h",
	chrPtrDirTrabajo,
	chrPtrMaquina);
lFlePtrUtilizacion=fopen(lchrArrArchivo,"w");

fclose(lFlePtrUtilizacion);
}
char *SiscomCreaModuloValidacionCpuInfo::CambiaMayusculas(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
return pchrPtrCadena;
}
