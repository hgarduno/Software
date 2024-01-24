#ifndef __SISCOMREGISTROSPRO2_H__
#define __SISCOMREGISTROSPRO2_H__
extern "C"{
#include <SiscomDesarrollo2.h>
};
#include <SiscomRegistroPro2.h>
#include <SiscomCampoPro2.h>
#include <stdlib.h>
#include <string.h>
class SiscomComunicaSrv;
class SiscomCampoPro2;
/*!
 * \sa
 * \brief Manipula la informacion que se envia del servidor <br>
 *        a la interfaz
 *
 */
class SiscomRegistrosPro2
{
public:
	/*!
	 * Constructor de la clase 
	 * \brief Constructor de la clase se usa para poder manipular<br>
	 * 	  la informacion que se recibe del servidor
	 *        <br>
	 * \param[in] pintNRegistros numero de registros recibidos
	 * \param pLCSiscomPro2 Lista con la informacion recibida
	 *
	 */
	SiscomRegistrosPro2(int pintNRegistros,LCamposSiscomPro2 *pLCSiscomPro2);
	/*!
	 * \brief Se sobre carga el constructor de la clase para poder obtener<br>
	 *        la informacion a partir de la conexion del cliente
	 *        <br>
	 * \param pSComunicaSrv
	 *
	 */
	SiscomRegistrosPro2(SiscomComunicaSrv *pSComunicaSrv);
	/*! 
	 * \brief Se sobre carga el constructor
	 *        <br>
	 * \param pSRegistroPro2 Informacion del registro
	 *
	 */
	SiscomRegistrosPro2(SiscomRegistroPro2 *pSRegistroPro2);
	/*!
	 * \brief Se sobre carga el constructor
	 * <br>
	 */
	SiscomRegistrosPro2();
	/*! 
	 * \brief Destructor de la clase
	 * <br>
	 */
	~SiscomRegistrosPro2();
	/*!
	 * \brief Inicia los campos del registro con pSRegistroPro2
	 * <br>
	 */
	void PonRegistroPro2(SiscomRegistroPro2 *pSRegistroPro2);
	/*!
	 * \brief Se sobre carga el operador para anexar el campo pSCampoPro2
	 * <br>
	 * \param pSRegistroPro2 Campo a anexar 
	 */
	SiscomRegistrosPro2 &operator<<(SiscomCampoPro2 pSCampoPro2);
	/*!
	 * \brief Se sobre carga el operador poara poder agregar pSCamposSiscomPro2
	 * <br>
	 * \param pSCamposSiscomPro2 Campos a anexar
	 */
	SiscomRegistrosPro2 &operator<<(const SCampoSiscomPro2 *pSCamposSiscomPro2);
	/*!
	 * \brief Operador para saber si pSRegistrosPro2 es igual al registro  <br>
	 *        actual
	 * <br>
	 */
	SiscomRegistrosPro2 &operator=(SiscomRegistrosPro2 &pSRegistrosPro2);
	/*!
	 * \brief Se sobre carga el operador para poder obtener de la<br>
	 *        clase la informacion de cada uno de los campos en<br>
	 *        el formato de la estructura
	 *        <br>
	 */
	operator const SCampoSiscomPro2 *()
	{
	 SCampoSiscomPro2 *lSCSiscomPro2;
	 int lintTamano;
	 lintTamano=sizeof(SCampoSiscomPro2)*LCSiscomPro2Act->SCSiscomPro2->intNumCampos;
	 lSCSiscomPro2=(SCampoSiscomPro2 *)malloc(lintTamano);
	 memcpy(lSCSiscomPro2,LCSiscomPro2Act->SCSiscomPro2,lintTamano);
	 //return LCSiscomPro2Act->SCSiscomPro2;
	 return lSCSiscomPro2;
	}
	/*!
	 * \brief Operador para obtener la informacion del campo <br>
	 *        pchrPtrNmbCampo
	 *        <br>
	 * \param pchrPtrNmbCampo Nombre del campo
	 *
	 */
	const char *operator[](const char *pchrPtrNmbCampo);
	/*!
	 * \brief siguiente registro 
	 *        <br>
	 */
	void operator++();
	/*!
	 * \brief Numero de registros
	 *        <br>
	 *
	 */
	int SiscomObtenNumRegistros();
	/*!
	 * \brief Apuntador al primer nodo de la lista <br>
	 *        simplemente ligada.
	 *        <br>
	 */
	LCamposSiscomPro2 *SiscomObtenRegistros();
	/*!
	 * \brief Se anexa la informacion del registro <br>
	 *        Internamente se anexa un nodo en la lista<br>
	 *        simplemente ligada
	 *        <br>
	 */
	void SiscomAnexaRegistro();
	/*!
	 * \brief Anexa un nodo a la lista simplemente ligada <br>
	 *        la informacion pSRegistrosPro2 se anexara a la  <br>
	 *        lista simplemente ligada
	 *        <br>
	 * \param pSRegistrosPro2 Informacion que se anexara a la <br>
	 *        lista simplemente ligada
	 */
	void SiscomAnexaRegistro(SiscomRegistrosPro2 pSRegistrosPro2);
	/*!
	 * \brief Regresa 1 cuando se ha llegada a la direccion del <br>
	 *        ultimo registro en otro caso regresa 0 
	 *        <br>
	 */
	int SiscomEsElUltimoRegistro();
	/*!
	 * \brief Con el objetivo de poder enviar entre el servidor y <br>
	 *        el cliente bloques de informacion con formatos diferentes<br>
	 *        se anexo esta funcion que regresa 1 si en el registro actual <br>
	 *        contienen los campos "Fin" y "Registro", en caso de que los <br>
	 *        campos no esten presentes regresa 0 
	 *        <br>
	 */
	int SiscomEsFinRegistro();
	/*!
	 * \brief Regresa 1 si phcrPtrNmbCampo esta contenido en el registro<br>
	 *        actual
	 *        <br>
	 * \param pchrPtrNmbCampo nombre del campo 
	 */

	int SiscomEsElCampo(const char *pchrPtrNmbCampo);
	/*!
	 * \brief Actualiza el contenido de pchrPtrNmbCampo <br>
	 *        con el valor de pchrPtrDato del registro actual
	 *        <br>
	 * \param pchrPtrNmbCampo nombre del campo a actualizar
	 * \param pchrPtrDato Contenido de la informacion con la <br>
	 *        que se actualizara el campo
	 */
	void SiscomActualizaCampo(const char *pchrPtrNmbCampo,const char *pchrPtrDato);
	/*! 
	 * \brief Coloca el apuntador de la lista simplemente ligada al <br>
	 *        primer nodo.
	 */
	void SiscomColocaPrimerRegistro();
	/*!
	 * \brief Inicia las variables del objeto.
	 */
	void SiscomIniciaObjeto();
	/*!
	 * \brief Regresa un apuntador a SiscomRegistroPro2 con la informacion<br>
	 * actual
	 */
	SiscomRegistroPro2 *SiscomObtenRegistroPro2();
	/*!
	 * \brief Imprime el contenido de la lista simplemente ligada <br>
	 * al archivo log de la aplicacion
	 * <br>
	 */
	void SiscomImprimeContenido();

private:
	int intNumRegistros; 
	LCamposSiscomPro2 *LCSiscomPro2Prim;
        LCamposSiscomPro2 *LCSiscomPro2Act;
	SiscomRegistroPro2 *SRegistroPro2;
	SCampoSiscomPro2 *SCSiscomPro2;
	SiscomComunicaSrv *SComunicaSrv;
	int intModoLibera;

	int intLibera;

};

#endif
