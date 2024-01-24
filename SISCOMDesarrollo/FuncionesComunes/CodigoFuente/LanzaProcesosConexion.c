#include <stdio.h>
#include <unistd.h>
int main(int pintArgc,char **pchrPtrArgv)
{
long pid;
int i;
	for(i=0;i<6;i++)
	 if((pid=fork())>0)
	 {
		printf("El pid del cliente %ld\n",pid);
	 }
	 else
	 if(!pid) 	 
	 {
	   if((execl("ClienteDeConexion.bin","ClienteDeConexion.bin",NULL))==-1)
	    printf("Error al cargar el cliente de conexion\n");
		   
	 }
		
for(i=0;i<3;i++)
wait(NULL);

		


}
