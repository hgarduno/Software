#ifndef __SISCOMINFORMACION_H__
#define __SISCOMINFORMACION_H__

extern "C"{
#include <SiscomDesarrollo2.h>
};
#include <SiscomRegistrosPro2.h>
#include <SiscomRegistroPro2.h>
#include <qptrlist.h>

/*!
 * \sa
 * \brief Permite construir una interfaz con la informacion del  <br>
 *        protocolo de una forma mas simple.
 *
 */
class SiscomInformacion
{
public:
	/*!
	 * \brief Constructor de la Clase
	 * <br>
	 */
	SiscomInformacion();
	/*!
	 * \brief  Destructor de la clase
	 * <br>
	 */
	~SiscomInformacion();
	/*!
	 * \brief Se sobre carga el operador para obtener  <br>
	 *  una referencia al objeto SRegistrosPro2
	 */
	operator SiscomRegistrosPro2 &()
	{
	   return SRegistrosPro2;
	}
/*
	operator const SiscomRegistrosPro2 &()
	{
	   return SRegistrosPro2;
	}	
*/
	/*!
	 * \brief Se sobre carga el operador para obtener <br>
	 * una referencia al objeto SRegistroPro2
	 */
	operator const SiscomRegistroPro2 &()
	{
	   return SRegistroPro2;
	}
	/*!
	 * \brief Se sobre carga el operador para obten la direccion <br>
	 * del apuntador que contiene la estructura con los campos 
	 * <br>
	 */
	operator const SCampoSiscomPro2 *()
	{
		return (const SCampoSiscomPro2 *)SRegistrosPro2;
	}
	/*!
	 * \brief Actualiza el campo pchrPtrNmbCampo del registro actual <br>
	 * con el valor pchrPtrDato 
	 * <br>
	 * \param[in] pchrPtrNmbCampo Campo que se requiere actualizar
	 * \param[in] pchrPtrDato informacion que se copiara al campo <br>
	 *  pchrPtrNmbCampo
	 */
	void SiscomActualizaCampo(const char *pchrPtrNmbCampo,
				  const char *pchrPtrDato);

	/*!
	 * \brief Se sobre carga el operador para obtener la informacion <br>
	 *  del campo pchrPtrNmbCampo del registro actual <br>
	 *  \param [in] pchrPtrNmbCampo Campo del caul se requiere conocer <br>
	 *  la informacion <br>
	 */
	const char *operator[](const char *pchrPtrNmbCampo);

	

	/*!
	 * Campos que conformaran el registro
	 */
	SiscomRegistroPro2 SRegistroPro2;
	/*!
	 * Registros 
	 */
	SiscomRegistrosPro2 SRegistrosPro2;
	/*!
	 * Variable de paso
	 */

	SiscomRegistrosPro2 SRegistrosPro2Paso;


};

typedef QPtrList<SiscomInformacion> SiscomInformacionLst;
#endif 
