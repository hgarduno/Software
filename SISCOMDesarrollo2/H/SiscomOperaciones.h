#ifndef __SISCOMOPERACIONES_H__
#define __SISCOMOPERACIONES_H__
#include <SiscomInformacion.h>
class SiscomDatCom;
/*! 
 * \brief Clase encargada del intercambio de informacion <br>
 *        entre el cliente y el servidor de la aplicacion
 *
 */
class SiscomOperaciones
{
public:
	/*!
	 * \brief  Constructor de la clase inicia el proceso de comunicacion <br>
	 *         entre pSisDatCom, enviando pSInformacionLst 
	 * <br>
	 * \param pSisDatCom informacion de conexion entre el cliente y el <br>
	 *        servidor 
	 * \param pSInformacionLst Registros que se enviaran al servidor
	 */
	SiscomOperaciones(SiscomDatCom *pSisDatCom,
			  QPtrList<SiscomInformacion> *pSInformacionLst);

	/*!
	 * \brief Inicia el proceso de comunicacion con el servidor especificado <br>
	 *  en pSisDatCom
	 *  <br>
	 *  \param pSisDatCom Servidor con el que se intercambiara informacion
	 */
	SiscomOperaciones(SiscomDatCom *pSisDatCom);
	/*!
	 * \brief Destructor de la clase
	 * <br>
	 */

	virtual ~SiscomOperaciones();	
	/*!
	 * \brief Envia un peticion de actualizacion al servidor <br>
	 * la cual esta identificada por pchrPtrOperacion
	 * <br>
	 * \param pchrPtrOperacion Operacion que debera de ejecutarse <br>
	 * en el servidor de la aplicacion
	 */
	void SiscomActualiza(const char *pchrPtrOperacion);
	/*! 
	 * \brief Envia una peticion de actualizacion al servidr <br>
	 * la cual esta definida en pchrPtrOperacion, el servidor debera <br>
	 * procesar la informacion que se envia en pSInformacionLst
	 * <br>
	 * \param pchrPtrOperacion Operacion que debera ejecutar el servidor<br>
	 * de la aplicacion
	 * \para pSInformacionLst Informacion que se enviara para ser procesada<br>
	 * por el servidor
	 */
	void SiscomActualiza(const char *pchrPtrOperacion,
			     SiscomInformacionLst *pSInformacionLst);
	/*! 
	 * \brief Envia una peticion de actualizacion al servidor <br>
	 * la cual esta definida en pchrPtrOperacion
	 * <br>
	 * \param pchrPtrOperacion Operacion que se debera ejecutar 
	 */
	void SiscomActualiza2(const char *pchrPtrOperacion);
	/*!
	 * \brief Se envia la informacion al servidor, el cual debera ejecutar <br>
	 * la operacion pchrPtrOperacion, en este caso se envia pSInformacionLstDat <br>
	 * \param[in] pchrPtrOperacion Operacion que se ejecutara en el servidor 
	 * \param[in] pSInformacionLstDat Registros que se enviar al servidor
	 */
	void SiscomActualiza2(const char *pchrPtrOperacion,
			      SiscomInformacionLst *pSInformacionLstDat);
	/*! 
	 * \brief Se envia la informacion al servidor, el cual debera ejecutar <br>
	 * la operacion pchrPtrOperacion, los registros que se enviaran previamente<br>
	 * se pasaron mediante la funcion SiscomPonParametrosConsulta.<br>
	 * \param[in] pchrPtrOperacion Operacion que debera ejecutar el servidor
	 * \param[out] pSRegistrosPro2 Registros con la informacion que respondera <br>
	 * el servidor, en la mayoria de los casos representara el estado de la eje<br>
	 * cucion de la operacion en el servidor, para que en la interfaz se pueda <br>
	 * ejecutar codigo dependiendo de la informacion que en esta variable se 
	 * regresa<br>
	 */
	void SiscomActualiza2(const char *,SiscomRegistrosPro2 **pSRegistrosPro2);

	void SiscomActualizaSubRegistros(const char *,SiscomInformacionLst *);
	void SiscomActualiza2SubRegistros(const char *,SiscomRegistrosPro2 **);
	void SiscomConsulta(const char *,QPtrList<SiscomInformacion> *);
	void SiscomConsulta(const char *,SiscomRegistrosPro2 **);
	void SiscomPonParametrosConsulta(QPtrList<SiscomInformacion> *);
private:
	SiscomDatCom *SisDatCom;
	QPtrList<SiscomInformacion> *QPLSiscomInfo;
private:
	virtual void SiscomGeneraRegistros(const SiscomComunicaSrv *,
					   QPtrList<SiscomInformacion> *);

	virtual void SiscomGeneraRegistrosActualiza(const SiscomComunicaSrv *,
					   QPtrList<SiscomInformacion> *);
		void SiscomGeneraRegistrosActualiza(const SiscomComunicaSrv *,
						    SiscomRegistrosPro2 **);
};



#endif
