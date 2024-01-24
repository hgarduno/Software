#ifndef __PACIENTES_H__
#define __PACIENTES_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPPaciente();
SiscomOperaciones2 *OPBuscaPersonas();
SiscomOperaciones2 *OPBuscaPersonasSimilares();
SiscomOperaciones2 *OPActualizaPersonales();
void RegistraPaciente(SArgsSiscom *);
/*
 * Para ejecutar el controlador de errores se requiere
 * que hay una funcion despues del error, en el
 * caso de los pacientes similares, se tomo la siguiente
 * funcionm a RegistraPaciente, pero en el caso
 * de que no existan pacientes similares no se genera
 * un error, y el programa intenta registrar al paciente
 * pero como no se genero informacion para este proceso
 * entonces el cliente se queda pegado esperando la respues
 * y el Servidor AD se queda esperando el envio 
 *
 */
void PacientesSimilares(SArgsSiscom *);


SiscomOperaciones2 *OPPacientesRegistrados();

#endif
