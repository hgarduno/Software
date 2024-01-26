#ifndef __ZSISCOMDESARROLLO4_H__
#define __ZSISCOMDESARROLLO4_H__
#include <stdio.h>

typedef void (*zSiscomAnalizaArgumentos)(int pintArgc,
					 char **pchrPtrArgv,
					 int *pintPtrPuerto,
					 char *pchrPtrDirIp);
class zSiscomDesarrollo4
{
public:
	zSiscomDesarrollo4();
	static void Log(const char *pchPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNoLinea,
			char *pchPtrFormato,
			...);
	static const char *ObtenCadenaSeparador(const char *pchrPtrCadena,
						char pchrSeparador);
	static const char *CadenaEntreSeparadores(
					const char *pchrPtrEntrada,
					char pchrSepInicio,
					char pchrSepFin,
					char *pchrPtrCadena);
	static void Servidor(zSiscomAnalizaArgumentos pzSiscomAnalizaArgumentos,
			     char **pchrPtrArgv,
			     int pintArgc,
			     char *pchrPtrDirIp,
			     int *pintPtrPuerto);
	static int CadenasPorSeparador(const char *pchrPtrCadena,
					char pchrSeparador,
					char ***pchrPtrCadenas);
	static int LeeLinea(FILE *pFlePtrArchivo,char *pchrPtrLinea);
	static void EliminaEspaciosInicio(char *pchrPtrCadena);
	static void LiberaCadenas(char **pchrPtrCadenas);

	static int LeeArchivo(const char *pchrPtrNombreArchivo,
			      char *pchrPtrBufferLinea,
			      char *pchrPtrArchivo);
	static void CadenaHastaDelimitador(const char *,char ,char *);
				
	

};

extern "C"
{
extern FILE *gPtrFleArchivoLog;
extern void *gzSiscomConexion;
};
#define LogSiscom(...) 								\
	zSiscomDesarrollo4::Log(__FILE__,__FUNCTION__,__LINE__,(char *)__VA_ARGS__)


#endif
