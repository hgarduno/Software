#ifndef __SISCOMFUNCIONESCOMUNES_H__
#define __SISCOMFUNCIONESCOMUNES_H__
#include <stdio.h>
void SiscomFechaLocal(char *pchrPtrFecha);

int SiscomLeeLineaArchivo(FILE *pFlePtrArchivo,
			  char *pchrPtrLinea);
void SiscomEliminaCaracterCadena(char pchrCaracter,
				 char *pchrPtrCadena,
				 char *pchrPtrBuffer);

const char *SiscomObtenDatoValido(const char *pchrPtrDato);


/* Martes 20 de Noviembre del 2012
 * Para continuar con el desarrollo de esta version ,desarrolle el programa
 * ManejandoRedes con esta version, por lo que se agregaron las siguientes
 * funciones
 *
 */


int SiscomEjecutaComando(const char *pchrPtrComando,char ***pchrPtrSalida);
void SiscomAgregaCadenaArreglo(int pintNCadenas,
			       char *pchrPtrCadena,
			       char ***pchrPtrArreglo);

void SiscomCambiaCaracter(char pchrCaracter,
			  char pchrPorCaracter,
			  char *pchrPtrCadena);
void SiscomCadenasLog(const char *pchrPtrArchivo,
			     const char *pchrPtrFuncion,
			     int pintNLinea,
			     char **pchrPtrCadenas);

FILE *SiscomEscribeLineaArchivo(const char *pchrPtrArchivo,
			  FILE *pFlePtrArchivo,
			  const char *pchrPtrLinea);

void SiscomAMayusculas(char *pchrPtrCadena);


void SiscomObtenNumeroUnicoChar(char *pchrPtrUnico);
long SiscomObtenNumeroUnico();
void SiscomObtenHoraActualChar(char *pchrPtrHora);
void SiscomObtenHoraActual(int *pintPtrHora,
                           int *pintPtrMinuto,
                           int *pintPtrSegundo);
void SiscomObtenFechaHoraActualAAAADDMM(char *pchrPtrFechaConHora);
void SiscomObtenFechaHoyCharAAAADDMM(char *pchrPtrFecha);
int SiscomObtenFechaHoyINT(int *pintPtrDia,
                           int *pintPtrMes,
                           int *pintPtrAno);

void SiscomCopiaOtraCadena(int pintNCadena,
		     const char *pchrPtrCadena,
		     char ***pchrPtrCadenas);

int SiscomAnalizaCadenas(const char *pchrPtrCadena,
		   char pchrSeparador,
		   char *pchrPtrBuffer,
		   char ***pchrPtrRegreso);

/* 16 de Agosto de 2015
Las siguientes funciones son necesarias para el algoritmo de conversion
de double -> letra (Array).
*/
void SiscomALetra(double lfltDato,
            char **pchrArrALetraPtr);

void ALUnidades(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

void ALDecenas(char *pchrArrNumeroLetra,
               char *pchrArrNumero);

void ALCentenas(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

void ALMillares(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

void ALMillones(char *pchrArrNumeroLetra,
                char *pchrArrNumero);

int generaLLaveProducto(const char *nombre,
                        const char *modelo);

int SiscomGeneraIdProducto(const char *, const char *);

void SiscomLiberaCadenas(char **pchrPtrCadenas);
void SiscomEliminaEspaciosFinal(const char *pchrPtrCadena);
void SiscomEliminaEspaciosInicio4(char *pchrPtrBuffer,char *pchrPtrCadena);


int SiscomRemplazandoCaracteres(unsigned const char *pchrPtrCadena,
			        unsigned const char *pchrPtrCaracteres,
				unsigned const char *pchrPtrCambio,
				unsigned char *pchrPtrSalida);
void SiscomNumeroCaracterACambiar(int pintNCaracter,
			    unsigned char *pchrPtrCaracteres);

void SiscomNumeroCaracterRemplazar(int pintNCaracter,
				   unsigned char pchrCaracter,
				   unsigned char *pchrPtrCaracteres);


int SiscomEsHoyLaFecha(const char *pchrPtrFecha);

#endif
