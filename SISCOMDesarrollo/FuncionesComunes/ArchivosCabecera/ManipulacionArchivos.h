#ifndef __MANIPULACIONARCHIVOS_H__
#define __MANIPULACIONARCHIVOS_H__
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif	
void RegresaLinea(char *,FILE *);
void RemplazaCaracter(char ,char ,char *);
void QuitaEspaciosPrincipioOFinal(char *);
int ObtenCadenaConDelimitador(char *,char,char * ,int *);
int RegresaCadenas(char *,char ,char ***);
void LiberaMemoria(char **);
void QuitaEspacioPrincipioYFinal(char *);
void ObtenArchivos(char *,char ***);
void SISCOMObtenFechasDelRango(char *,char **,char **);
#ifdef __cplusplus
}
#endif	

#endif 
