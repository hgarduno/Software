#ifndef __SISCOMDATCOM_H__
#define __SISCOMDATCOM_H__


/*! \class SiscomDatCom
 *  \brief Clase que mantine los datos de conexion entre el cliente
 *  	   y el servidor de la aplicacion
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date ????
 */

class SiscomDatCom
{
public:
	/*! Constructor de la clase 
	 * \param pintPtoCom Puerto de comunicaciones con en el que atiende
	 * 	             peticiones el servidor
	 * \param pchrPtrDirIpSvr Direccion en la cual esta atendiendo peticiones
	 *                        el servidor
	 */
	SiscomDatCom(int pintPtoCom,const char *pchrPtrDirIpSvr);
	SiscomDatCom(int pintPtoCom,
		     const char *pchrPtrDirIpSvr,
		     const char *pchrPtrDescripcion);
	/*! Funcion que regresa el puerto de comunicaciones con el servidor
	 */
	int SiscomObtenPuertoCom();
	/*! Funcion que regresa la direccion ip del servidor de 
	 * la aplicacion
	 */
	void SiscomDescripcionServidor(const char *pchrPtrDescServidor);
	const char *SiscomObtenDireccionIp();
	const char *SiscomDescripcionServidor();
	
private:
	/*! Puerto de comunicaciones */
	int intPtoCom; 
	/*! Direccion ip del servidor de la aplicacion */
	const char *chrPtrDirIpSvr;  
	const char *chrPtrDescServidor;
};

#endif 
