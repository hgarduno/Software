#ifndef __DEMONIOSOCKETS_H__
#define __DEMONIOSOCKETS_H__
#include <EstructurasSISCOM.h>
#include <stdio.h>
int SISCOMLeeArgumentosDemonioSockets(int,char **,int *,char *,int *,char *,char *,char *,int *,char *,STRUCTError *);
int SISCOMAtiendeClientes(char *,char **,int ,STRUCTError *);
int SISCOMCargaDllYEjecutaFunciones(int,unsigned long,int,char *,char *,char *,char *,char ***);
int SISCOMCreaArgumentosSinDLL(char *,int ,int,char *,char ***);
int SISCOMIniciaSHM(unsigned long *,char *,char *);
int SISCOMModoDeUsoDemonio();
void SISCOMInstalaManejadorDeSenales(int);
void SISCOMCreaArchivoPid();
void AlmacenaPid(int ,int);
FILE *ReDireccionaSalidaEstandar(int pintPuerto);
#endif 
