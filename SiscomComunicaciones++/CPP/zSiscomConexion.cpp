#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
zSiscomConexion::zSiscomConexion():intSeDebeConectar(1)
{

}
zSiscomConexion::zSiscomConexion(const char *pchrPtrArchivo,
				 const char *pchrPtrModo):intSeDebeConectar(0)
{
FILE *lFlePtrArchivo;
  if((lFlePtrArchivo=fopen(pchrPtrArchivo,pchrPtrModo)))
	intSocket=fileno(lFlePtrArchivo);
  else
  {
	LogSiscom("NO   Asignando el socket ....");

  }

}
zSiscomConexion::zSiscomConexion(const char *pchrPtrDirIp,
				 int pintPuerto):
				 chrPtrDirIp(pchrPtrDirIp),
				 intPuerto(pintPuerto),
				 intSeDebeConectar(1)
				 
{

}

int zSiscomConexion::Conectate()
{
struct sockaddr_in lSocAddrInCon;
memset(&lSocAddrInCon,sizeof(struct sockaddr_in),0);
	if((intSocket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
	     chrPtrEdoConexion=(char *)strerror(errno); 

	}
	else
	{
	  lSocAddrInCon.sin_family=AF_INET;
	  lSocAddrInCon.sin_port=htons(intPuerto);
	  lSocAddrInCon.sin_addr.s_addr=inet_addr(chrPtrDirIp);
	  if((connect(intSocket,
		      (struct sockaddr *)&lSocAddrInCon,
		       sizeof(struct sockaddr_in)))<0)
	  {
	     chrPtrEdoConexion=(char *)strerror(errno); 
	  }
	}

return errno;
}
int zSiscomConexion::Socket()
{
 return intSocket;
}
void zSiscomConexion::Puerto(int pintPuerto)
{
intPuerto=pintPuerto;
}
int zSiscomConexion::Puerto()
{
 return intPuerto;
}
void zSiscomConexion::DireccionIp(const char *pchrPtrDirIp)
{
	chrPtrDirIp=pchrPtrDirIp;
}
const char *zSiscomConexion::DireccionIp()
{
  return chrPtrDirIp;
}

void zSiscomConexion::AsignaMemoriaCadena(int pintNBytes)
{
     chrPtrCadena=(char *)malloc(pintNBytes);
}
char *zSiscomConexion::Cadena()
{
  return chrPtrCadena;
}
void zSiscomConexion::Cadena(char *pchrPtrCadena)
{
    chrPtrCadena=pchrPtrCadena;
}
int zSiscomConexion::SeDebeConectar()
{
    return intSeDebeConectar;
}
