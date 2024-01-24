#ifndef __RNPERSONAS_H__
#define __RNPERSONAS_H__

const char *ObtenNombre(char **);
const char *ObtenAPaterno(char **);
const char *ObtenAMaterno(char **);
const char *ObtenRFC(char **);
const char *ObtenTipoPersona(char **);
const char *ObtenIdPersona(char **);
const char *ObtenEdoRegistroGenerales(char **);

const char *ObtenCalle(char **);
const char *ObtenNumero(char **);
const char *ObtenCP(char **);
const char *ObtenColonia(char **);
const char *ObtenMunicipio(char **);
const char *ObtenEstado(char **);

const char *ObtenTelefono(char **);
const char *ObtenCorreoElectronico(char **);
const char *ObtenApodo(char **);
const char *ObtenFirma(char **);

const char *ObtenPerfil(char **);
const char *ObtenNmbTipoPersona(char **);
const char *ObtenDscTipoPersona(char **);

#define RN_Persona_Nombre 		1
#define RN_Persona_APaterno 		2
#define RN_Persona_AMaterno 		3
#define RN_Persona_RFC			4
#define RN_Persona_IdPersona 		5
#define RN_Persona_TipoPersona 		6
#define RN_Persona_EdoRegistroPersona	7
#define RN_Persona_Calle		8
#define RN_Persona_Numero		9
#define RN_Persona_CP			10	
#define RN_Persona_Colonia		11
#define RN_Persona_Municipio		12
#define RN_Persona_Estado		13
#define RN_Persona_Referencias		14
#define RN_Persona_Telefono		16
#define RN_Persona_CorreoElectronico	19
#define RN_Persona_Apodo		21
#define RN_Persona_Firma		25
#define RN_Persona_Perfil		26
#define RN_Persona_NmbTipoPersona	27
#define RN_Persona_DscTipoPersona	28


#endif
