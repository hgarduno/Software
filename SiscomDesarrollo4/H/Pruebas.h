#ifndef __PRUEBAS_H__
#define __PRUEBAS_H__

void PruebaFechaLocal();
void PruebaArchivoIni(char **pchrPtrArgv);

void PruebaSiscomProtocoloComunicaciones(char **pchrPtrArgv);
void PruebaSiscomLeeProtocoloComunicaciones(char **pchrPtrArgv);

void PruebaSiscomInformacionModulo(char *pchrPtrBuffer,
				   SiscomRegistroProL *pSiscomProLPtrAct);
void PruebaSiscomCargaModulo(char **pchrPtrArgv);
void PruebaEnvioSql(char **pchrPtrArgv);
#endif


