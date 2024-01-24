#ifndef __RNVEHICULOS_H__
#define __RNVEHICULOS_H__
#include <FuncionesComunes.h>
#include <RNComunFresno.h>
#include <RNVarios.h>


#define RN_Vehiculo_IdVehiculo			1
#define RN_Vehiculo_Placas			2
#define RN_Vehiculo_Descripcion			3
#define RN_Vehiculo_EdoRegistro			4

const char *ObtenIdVehiculo(char **);
const char *ObtenPlacas(char **);
const char *ObtenDescripcionVehiculo(char **);
const char *ObtenEdoRegistroVehiculo(char **);

StcLtaRegComSISCOM *RegistraVehiculos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaVehiculos(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaVehiculos(int *);

int EsConsultaTodosLosVehiculos(char **,char *);
void ConsultaTodosLosVehiculos(int,const char *,const char *,StcLtaRegComSISCOM **,int *);
void RespondeTodosLosVehiculos(int,const char *,int ,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **,int *);


#endif
