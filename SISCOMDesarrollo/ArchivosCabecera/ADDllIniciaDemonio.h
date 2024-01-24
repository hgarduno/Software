#ifndef __ADDLLINICIADEMONIO_H__
#define __ADDLLINICIADEMONIO_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
#include <libpq-fe.h>

int ADDllConexionBDYCopiaSHM(PARDEPURACION unsigned long *);
int ADDllGeneraArgumentos(PARDEPURACION int,unsigned long,char *,char ***);
#endif 
