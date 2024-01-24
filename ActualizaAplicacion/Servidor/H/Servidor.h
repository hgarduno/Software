#ifndef __SERVIDOR_H__
#define __SERVIDOR_H__
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>

int IniciaServidorComunicaciones(int);
void ProcesaInformacion(int);

extern int errno;

#endif
