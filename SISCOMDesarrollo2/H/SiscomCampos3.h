#ifndef __SISCOMCAMPOS3_H__
#define __SISCOMCAMPOS3_H__
#include <qptrlist.h>
/*! 
 * \brief Se inicia la nueva version para el manejo del intercambio de <br>
 * informacion entre las GUI's y el servidor SISCOM, a lo largo de la utili<br>
 * zacion de la version 2 el formato del protocolo ha sido de mucha utilidad <br>
 * por lo que este no sufrira alteraciones, el principal cambio que se realizara<br>
 * sera el hecho de manejar todo con objetos, y no se utilizaran listas, ni las <br>
 * funciones de manipulacion de los campos SiscomProtocolo2.h, todo se realizar<br>
 * a partir de los objetos de QT para simplificar las clases, el envio de la <br>
 * informacion se realizara directamente al en el socket, y no de una lista simplemente <br> 
 * ligada o un buffer  de caracteres, una vez que se tenga toda la informacion<br>
 * que se debera enviar esta se escribira registro por registro en el socket
 *
 * SiscomCampo3 Almacenara la informacion de un campo 
 *
 */

class SiscomCampo3
{
public:
	/*! 
	 * \brief Constructor de la clase, se nombrara pchrPtrNmbCampo y se copiara<br>
	 * la informacion pchrPtrDato como contenido.
	 * La informacion del pchrPtrNmbCampo y pchrPtrDato se asingaran a <br>
	 * variables de la clase mediante strdup.
	 *
	 * \param[in] pchrPtrNmbCampo Nombre del campo
	 * \param[in] pchrPtrDato Dato que se almacenara 
	 */
	SiscomCampo3(const char *pchrPtrNmbCampo,const char *pchrPtrDato);
	~SiscomCampo3();
	/*!
	 * \brief Se sobre carga el operador para obtener la informacion <br>
	 * del campo pchrPtrNmbCampo
	 * \param[in] pchrPtrNmbCampo Nombre del campo del cual se necesita tener <br>
	 *  la informacion
	 */
	int operator==(const char *pchrPtrNmbCampo);
	/*!
	 */
	int operator==(SiscomCampo3 *);
	/*!
	 * \brief Obtiene la informacion almacenada para el campo
	 */
	const char *SiscomDato();
	/*!
	 * \brief  Obtiene el Nombre del campo 
	 */
	const char *SiscomNmbCampo();
	/*!
	 * \brief Actualiza la informacion del campo con pchrPtrDato.
	 * \param[in] pchrPtrDato
	 */
	void SiscomActualizaCampo(const char *pchrPtrDato);
private:
	const char *chrPtrNmbCampo;
	const char *chrPtrDato;
};
/*!
 * \brief Lista para almacenar cada una de los campos que formara el registro <br>
 */
class SiscomCampo3Lst:public QPtrList<SiscomCampo3>
{
public:	
	/*!
	 * \brief Constructor de la clase
	 */
	SiscomCampo3Lst();
	~SiscomCampo3Lst();
	/*!
	 * \brief Se sobre carga el operador, el cual permite anexar el Campo <br>
	 * pSCampo3
	 * \param[in] pSCampo3 Campo que se anexara
	 */
	SiscomCampo3Lst &operator<<(SiscomCampo3 *pSCampo3);
	/*!
	 * \brief Se sobre carga el operador, el cual regresara el contenido del <br>
	 * campo pchrPtrNmbCampo
	 */
	const char *operator[](const char *pchrPtrNmbCampo);
	/*!
	 * \brief Se sobre carga el operador, el cual regresara el contenido del <br>
	 * numero de campo pintNCampo
	 */
	const char *operator[](int pintNCampo);

	int operator==(const char *pchrPtrRegistro);

	SiscomCampo3 *Campo3(const char *pchrPtrNmbCampo);

	/*!
	 * \brief Actualiza el contenido del campo pchrPtrNmbCampo, con la informacion <br>
	 * almacenada en pchrPtrDato
	 * \param[in] pchrPtrNmbCampo Campo a actualizar 
	 * \param[in] pchrPtrDato Informacion para actualizar
	 */
	void SiscomActualizaCampo(const char *pchrPtrNmbCampo,const char *pchrPtrDato);


};

#endif
