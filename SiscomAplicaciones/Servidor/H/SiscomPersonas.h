/*! \file SiscomPersonas.h
 * \brief SISCOM Electronica <br>
 * Para poder utilizar las funciones de este archivo, se debera 	<br>
 * enlazar la biblioteca libSiscomAplicacionesSvr.so, que se encuentra	<br>
 * en el directorio $DIRLIBSISCOM2 					<br>
 *									<br>
 * 
 */

#ifndef __SISCOMPERSONAS_H__
#define __SISCOMPERSONAS_H__
#include <SiscomDesarrollo2.h>

/* Todas las rutinas de esta biblioteca			<br>
 * se tomara el hecho de que se procesedara a analizar		<br>
 * la informaciond e un solo registro				<br>
 * no se comptenpla por el momento realizar procesos		<br> 
 * de mas de un registro de envio				<br>
 *								<br>
 * 								<br>
 */

/*
 * En cuanto al manejo de errores se considera lo siguiente	<br>
 *								<br>
 * Se tomaran del 1 al 100  codigos de error en las 		<br>
 * bibliotecas de soporte y del 101 en adelante como		<br>
 * errores en los sistemas en los cuales se apliquen		<br>
 * la funciones de soporte					<br>
 *								<br>
 * Codigos de retorno establecidos:				<br>
 *								<br>
 * Datos personales invalidos 				1	<br>
 * Persona en normalizados 				2	<br>
 *								<br>
 * Verifica Password, password diferente 		3	<br>
 * Password Vacio			 		4	<br>
 * Firma ya registrada					5	<br>
 *								<br>
 *								<br>
 */				

/*!								<br>
 * Funcion que se encarga de proceso de normalizacion		<br>
 * de los datos de entrada en el nombre (Nombre, 		<br>
 * APaterno, AMaterno). Dicho proceso es cambiar		<br>
 * todos los caracteres de los datos a Mayusculas		<br>
 * asi como los caracteres marcados en 				<br>
 * SiscomCaracteresCambiados					<br>
 * La informacion que se envie del cliente al servidor 		<br>
 * para el proceso de normalizacion, se tomara de LCSiscomPro2Dat <br>
 * del pSAgsSiscom, los campos que se buscaran son Nombre, APaterno <br>
 * y AMaterno							<br>
 * Esta funcion requiere que previamente se haya		<br>
 * creado espacio para el argumento "SisNormalizado"		<br>
 * ya que en una variable con este nombre			<br>
 * dejara el resultado de la normalizacion.			<br>
 *								<br>
 * Es importante mencionar que el objetivo			<br>
 * de esta funcion sera, el de evitar que			<br>
 * se inserte en las tablas del sistema				<br>
 * informacion de datos personales que sea			<br>
 * igual o parecida, los clasicos casos 			<br>
 * son los errores al teclar que se suelen			<br>
 * cometer en el proceso de captuara de la			<br>
 * informacion asi como la omision de acentos			<br>
 * el caso de la n por ñ					<br>
 * \param pSAgsSiscom Argumento de operaciones			<br>
 */

void SiscomNormalizaPersona(SArgsSiscom *pSAgsSiscom);
/*!								<br>
 * Esta funcion creara argumentos temporales 			<br>
 * es decir que solo se deberan emplear para			<br>
 * el manejo de las funciones para el registro			<br>
 * de personas							<br>
 * Al final se debera contar con una ultima 			<br>
 * funcion que regrese la informacion almacena			<br>
 * da en los argumentos, a una estructura 			<br>
 * que se debera definir ya en el contexto 			<br>
 * de la aplicacion en la que se emplee 			<br>
 * la funcionalidad de esta biblioteca.				<br>
 *								<br>
 */

/*! 
 * Como convencion para la utilizacion de 			<br>
 * los argumentos de las funciones que aqui 			<br>
 * se desarrollen, se debera incluir como 			<br>
 * parte del nombre el prefijo SisXXXX				<br>
 * esto nos indicara que es un argumento 			<br>
 * dentro del contexto de las funciones				<br>
 * de soporte para las aplicaciones y				<br>
 * no de la aplicacion a desarrollar				<br>
 *								<br>
 */

void SiscomArgumentosPersona(SArgsSiscom *);
void SiscomArgumentosPersonaMoral(SArgsSiscom *pSAgsSiscom);
/*!
 * Esta funcion se encarga de realizar 			<br>
 * la validacion que tiene que ver con los		<br>
 * datos, en cuanto a que se viene el nombre		<br>
 * y el apellido paterno, como regla general		<br>
 * un nombre que contenga el Nombre es decir		<br>
 * diferente de vacio y el APellido Paterno		<br>
 * tambien diferente de vacio				<br>
 *							<br>
 * Para esta funcion se requiere que en el		<br>
 * los datos de entrada del protocolo se		<br>
 * envien los siguientes campos:			<br>
 *							<br>
 * Nombre y APaterno					<br>
 *							<br>
 * Si no se cumple la condicion de que			<br>
 * la informacion de los campos de nombre		<br>
 * y apellido paterno sea vacia o falte			<br>
 * alguna de ellas el codigo de retorno sera		<br>
 * 1, con lo que intCodigoRetorno=1			<br>
 *							<br>
 */

void SiscomValidaNombreVacio(SArgsSiscom *);


/*!							<br>
 * SiscomPrsonaEnNormalizados, funcion que se		<br>
 * encargara de ver si la informacion que se		<br>
 * normalizo a la entrada del proceso ya se		<br>
 * encuentra registrada en la tabla persona		<br>
 * normalizada, si ya se encuentra la informacion	<br>
 * en esta tabla se generara el error no 2		<br>
 *							<br>
 * Como parte de los datos de entrada de esta		<br>
 * fucion se requerira un argumento con nombre		<br>
 * SisNormalizado.					<br>
 *							<br>
 * Una de la consideraciones importantes para		<br>
 * esta funcion es el hecho de enviar en las		<br>
 * variables del Argumento SArgsSiscom, los		<br>
 * datos de conexion del servidor de acceso		<br>
 * a datos de la aplicacion, ya que tomara 		<br>
 * esta informacion para realizar la consulta		<br>
 *
 *
 */

void SiscomPersonaEnNormalizados(SArgsSiscom *);
/*!							<br>
 *							<br>
 * Copia al campo IdPersona el Identificador		<br>
 * que se genera					<br>
 *							<br>
 */		
void SiscomGeneraIdPersona(SArgsSiscom *);

/*
 *
 */
void SiscomBusquedaPersonas(SArgsSiscom *);

/*!									<br>
 *									<br>
 * Se buscaran con los datos de nombre, apellido paterno, apellido	<br>
 * materno en la tabla de personas normalizadas, para localizar 	<br>
 * las ocurrencias de estos datos, si se encuentran registros		<br>
 * que correspondan a la informacion se genera el codigo de 		<br>
 * error 6, con lo que sera util enviar los registros similares		<br>
 * a la interfaz							<br>
 *
 */

void SiscomPersonasSimilares(SArgsSiscom *);

/*!
 *
 *
 */
void SiscomActualizaNombre(SArgsSiscom *);
/*!
 *
 *
 */
SiscomOperaciones2 SiscomObtenTipoBusquedaPersona(SArgsSiscom *);

/*
 * Jueves 1 De Septiembre del 2011
 * Despues de probar esta funcion en el sistema de electronica
 * la pase al soporte para aplicaciones
 *
 */
void SiscomDescartaRegistrosSimilares(SArgsSiscom *pSAgsSiscom);

/* Viernes 16 de Octubre del 2015 
 * Queretaro 
 * Se agrega el soporte para el manejo de las personas Morales
 *
 */

void SiscomNormalizaRazonSocial(SArgsSiscom *pSAgsSiscom);
#endif
