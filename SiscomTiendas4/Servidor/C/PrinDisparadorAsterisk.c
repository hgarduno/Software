#include <DisparadorAsterisk.h>
FILE *gPtrFleArchivoLog;
int main(int pintArgc,
	 char **pchrPtrArgv)
{

gPtrFleArchivoLog=stdout;
EnviaNumero(atoi(pchrPtrArgv[1]),pchrPtrArgv[2],pchrPtrArgv[3]);

}
