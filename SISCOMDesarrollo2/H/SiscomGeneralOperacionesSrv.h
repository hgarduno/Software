#ifndef __SISCOMGENERALOPERACIONESSRV_H__
#define __SISCOMGENERALOPERACIONESSRV_H__
#include <SiscomInformacion.h>
#include <SiscomDatCom.h>
/*!
 * \brief Ejecuta operacion de envio y recepcion de informacion <br>
 * con el servidor
 *
 */
class SiscomGeneralOperacionesSrv
{
public:
	/*!
	 * \briefs Inicia el objeto conectandose al servidor  pSisDatCom <br>
	 * la informacion pSInformacionLst sera enviada, mediante una operacion<br> 
	 * de alta o consulta 
	 */
	SiscomGeneralOperacionesSrv(SiscomDatCom *pSisDatCom,
				    QPtrList<SiscomInformacion> *pSInformacionLst);
	/*!
	 * \brief (Fuera de Uso)<br>
	 * Envia la informacion de registros que fueron inicializados<br>
	 * en el constructor. En el servidor se debera ejecutar la operacion <br>
	 * pchrPtrOperacion.
	 * \param[in] pchrPtrOperacion Operacion que se debera ejecutar en el<br>
	 * el servidor 
	 */
	void SiscomEjecutaEnvio(const char *pchrPtrOperacion);
	/*!
	 * \brief Envia la informacion de registros que fueron inicializados<br>
	 * en el constructor. En el servidor se debera ejecutar la operacion <br>
	 * pchrPtrOperacion.
	 * \param[in] pchrPtrOperacion Operacion a ejecutarse en el servidor
	 */
	void SiscomEjecutaEnvio2(const char *pchrPtrOperacion);
	void SiscomEjecutaEnvioSubRegistros(const char *);
	void SiscomImprimeInformacion();
	operator const SiscomComunicaSrv *()
	{
		return SComunicaSrv;
	}
	const char *EstadoConexion();
private:
	SiscomDatCom *SDatCom;
	QPtrList<SiscomInformacion> *PtrInformacion;
	SiscomComunicaSrv *SComunicaSrv;
	const char *chrPtrEdoConexion;
};

#endif
