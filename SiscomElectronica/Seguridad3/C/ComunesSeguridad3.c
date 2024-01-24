#include <ComunesSeguridad3.h>
#include <stdio.h>
#include <stdlib.h>
int SePuedeRegistrarUsuario(StcSiscomOpciones **pStcSisPtrOpciones)
{
StcSiscomOpciones lStcSisOpciones;
char *lchrPtrOpciones[]={"DirIp",
			 "Puerto",
			 "Nombre",
			 "APaterno",
			 "AMaterno",
			 "Firma",
			 "Password",
			 "Aplicacion",
			 "Perfil",
			 "IdExpendio",
			 0};
  if(SiscomEstaLaOpcion("RegistraUsuario",*pStcSisPtrOpciones))
  {
         if(SiscomLineaComandosCompleta(lchrPtrOpciones,*pStcSisPtrOpciones,&lStcSisOpciones))
	 return 1;
	 else
	 {
	  printf("									\n"
	   "	-RegistraUsuario							\n"
	   "		-DirIp Direccion Sistema Siscom Electronica			\n"
	   "		-Puerto Puerto Sistema Siscom electronica			\n"
	   "		-Nombre 							\n"
	   "		-APaterno							\n"
	   "		-AMaterno							\n"
	   "		-Firma								\n"
	   "		-Password							\n"
	   "		-Aplicacion							\n"
	   "		-Perfil								\n"
	   "		-IdExpendio 							\n"
	   "		   	-IdExpendio se pasa el identificador sin el		\n"
	   "				    signo negativo, el servidor agrega		\n"
	   "				    el - para el registro			\n"
           "					\n");
	   exit(0);
	 }
  }
}
int SePuedeActualizarPerfil(StcSiscomOpciones **pStcSisPtrOpciones)
{
StcSiscomOpciones lStcSisOpciones;
char *lchrPtrOpciones[]={"Archivo",
			 0};
  if(SiscomEstaLaOpcion("ActualizaPerfil",*pStcSisPtrOpciones))
  {
         if(SiscomLineaComandosCompleta(lchrPtrOpciones,*pStcSisPtrOpciones,&lStcSisOpciones))
	 return 1;
	 else
	 {
	  printf("									\n"
	   "	-ActualizaPerfil							\n"
	   "		-Archivo							\n"
           "					\n");

	   exit(0);
	 }
  }
}

int SeConsultaPerfiles(StcSiscomOpciones **pStcSisPtrOpciones)
{
StcSiscomOpciones lStcSisOpciones;
char *lchrPtrOpciones[]={"DirIp",
			 "Puerto",
			 0};
  if(SiscomEstaLaOpcion("ConsultaPerfiles",*pStcSisPtrOpciones))
  {
         if(SiscomLineaComandosCompleta(lchrPtrOpciones,*pStcSisPtrOpciones,&lStcSisOpciones))
	 return 1;
	 else
	 {
	  printf("									\n"
	   "	-ConsultaPerfiles							\n"
	   "		-DirIp								\n"
           "		-Puerto								\n");

	   exit(0);
	 }
  }
}

