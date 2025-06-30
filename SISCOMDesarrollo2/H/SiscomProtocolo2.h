/*! \file SiscomProtocolo2.h
	 *  \brief SISCOM Electronica.
	 *  	   Archivo desarrolloado por Heli Garduno Esquivel 2007
	 *
	 *  	   Archivo que contiene el prototipo de  funciones que se utilizan para
	 *  	   manipular el protocolo de comunicaciones SISCOM2 
	 */


	#ifndef __SISCOMPROTOCOLO2_H__
	#define __SISCOMPROTOCOLO2_H__
	#include <stdio.h>

	/*! \sa 
	 *  \brief Estructura que contiene la informacion de los 
	 *         campos del protocolo de comunicaciones
	 *
	 */

	typedef struct CamposProtocolo2
	{
		char *chrPtrNmbCampo;
		/*!< Nombre del campo 
		 *
		 */

		char *chrPtrNoCampo;
		/*!< Numero del campo 
		 *
		 */


		char *chrPtrDato;
		/*!< Dato que se envia en el protocolo 
		 *
		 */


		int intNumCampos;
		/*!< Numero de campos que contiene el registo 
		 *
		 *
		 */

	}SCampoSiscomPro2;

	/*! \sa
	 *  \brief Lista ligada con los campos y registros enviados
	 *         en el proceso de comunicaciones.
	 */ 

	typedef struct LCamposProtocolo2
	{
		SCampoSiscomPro2 *SCSiscomPro2;
		/*!< Campos del Registro
		 *
		 */
		struct LCamposProtocolo2 *SCP2PtrSig;
		/*!< Apuntador al siguiente elemento de lista 
		 *
		 */
		struct LCamposProtocolo2 *SCP2PtrAnt;
		/*!< Apuntador al elemento anterior de la lista
		 *   actualmente no se usa
		 */
	}LCamposSiscomPro2;

	typedef struct SiscomPro2Agrupados
	{
		char *chrPtrCampo;
		LCamposSiscomPro2 *LCSiscomPro2Prim;
		LCamposSiscomPro2 *LCSiscomPro2Act;
		struct SiscomPro2Agrupados *LCSiscomPro2AgrupaS;
	}LCamposSiscomPro2Agrupados;

	/*! \fn void SiscomCopiaDatosProtocoloCharChar(LCamposSiscomPro2 *pLCSiscomPro2,
	 *				       int pintNRegistros,
	 *				       const char *pchrPtrNmbCampo,
	 *				       char ***pchrPtrRegreso)
	 *	\brief Funcion que tiene como objetivo copiar la informacion de la
	 *	       lista pLCSiscomPro2, a una matriz de apuntadores a caracteres
	 *	       lo que permitira que el manejo de la informacion de la lista
	 *	       se pueda realizar mediante una simple indexacion.
	 *	\param pLCSiscomPro2 Lista con la informacion que se envio por el socket
	 *	\param pintNRegistros El Numero de registros leidos
	 *	\param pchrPtrNmbCampo Campo del registro que se desea copiar
	 *	\param pchrPtrRegreso Matriz de apuntadores a caracteres con los datos del campo
	 *	\example SiscomProtocolo2.c Aqui se colocara un ejemplo de como se podra utilizar la funcion
	 */

	void SiscomCopiaDatosProtocoloCharChar(LCamposSiscomPro2 *,
					       int ,
					       const char *,
					       char ***);


	/*! \fn void SiscomAsignaDatosCampoAlCampo(char **pchrPtrCampos,SCampoSiscomPro2 *pSCSiscomPro2);
	 *
	 *   \brief  Funcion que inicia los campos de la estructura pSCSiscomPro2, con la
	 *           informacion de la variable pchrPtrCampos
	 *   \param  pchrPtrCampos Los nombres de los campos, que se asignaran a la estructura
	 *           pSCSiscomPro2 [in] , el ultimo elemento de la matriz debe contener Nulo
	 *
	 *   \param  pSCSiscomPro2 [out] Estructura iniciada con la informacion de pchrPtrCampos
	 *
	 *
	 */
	void SiscomAsignaDatosCampoAlCampo(char **,SCampoSiscomPro2 *);



	/*! \fn void SiscomInformacionServidor(int pintPto,
	 *			      const char *pchrPtrDirIpSvr,
	 *			      const char *pchrPtrOperacion,
	 *			      int pintNRegistros,
	 *			      LCamposSiscomPro2 *pLCSiscomPro2,
	 *			      char **pchrPtrEdoConexion,
	 *			      int *pintPtrSocket);
	 * \brief Envia la informacion almacenada en \a pLCSiscomPro2Dat, al puerto \a pintPto, de
	 *        la direccion \a pchrPtrDirIpSvr, con el numero de registros \a pintNRegistros.
	 *        La funcion regresa en \a pchrPtrEdoConexion el estado de la conexion y en 
	 *        \a pintPtrSocket el descriptor del socket si la conexion fue exitosa.
	 * \param pintPto Puerto de comunicaciones 
	 * \param pchrPtrDirIpSvr Direccion Ip
	 * \param pchrPtrOperacion Operacion que debera ejecutar el servidor
	 * \param pintNRegistros Numero de registros que se enviaran
	 * \param pLCSiscomPro2 Lista con la informacion que se enviara al Servidor
	 * \param[out] pchrPtrEdoConexion Cada con la descripcion del error, en caso que 
	 *        se haya generado.
	 * \param[out] pintPtrSocket 
	 */

	void SiscomInformacionServidor(int pintPto,
				      const char *pchrPtrDirIpSvr,
				      const char *pchrPtrOperacion,
				      int pintNRegistros,
				      LCamposSiscomPro2 *pLCSiscomPro2,
				      char **pchrPtrEdoConexion,
				      int *pintPtrSocket);

	void SiscomInformacionServidorNoBloqueante(int pintPto,
				      const char *pchrPtrDirIpSvr,
				      const char *pchrPtrOperacion,
				      int pintNRegistros,
				      LCamposSiscomPro2 *pLCSiscomPro2,
				      int pintNTiempo,
				      char **pchrPtrEdoConexion,
				      int *pintPtrSocket);

	/*! \fn void SiscomLeeRegistroProtocolo2(int pintSocket,
	 *			SCampoSiscomPro2 **pSCSiscomPro2);
	 *  \brief  Funcion para leer la informacion de pintSocket, los datos son 
	 *          almacenados en pSCSiscomPro2 
	 *  \param pintSocket Socket de comunicaciones del cual se leera la
	 *             informacion.
	 *  \param[out] pSCSiscomPro2 Registro formado de la informacion que
	 *                  se leyo del socket.
	 */
	void SiscomLeeRegistroProtocolo2(int pintSocket,
				SCampoSiscomPro2 **pSCSiscomPro2);


	/*! \fn int SiscomLeeOperacion(int pintSocket, char **pchrPtrOperacion);
	 *  \brief Funcion que guarda en pchrPtrOperacion el nombre de la operacion 
	 *         que se envia por pintSocket.
	 *  \param pintSocket Socket de comunicacion 
	 *  \param[out] pchrPtrOperacion Operacion que se lee de pintSocket
	 *
	 */
	int SiscomLeeOperacion(int pintSocket, char **pchrPtrOperacion);

	/*! \fn int SiscomLeeNumeroRegistros(int pintSocket,int *pintPtrNRegistros);
	 *   \brief Funcion para leer el numero de registros que se enviaran a traves
	 *          de pintSocket.
	 *   \param pintSocket Socket de comunicacion.
	 *   \param[out] pintPtrNRegistros El numero de registros enviados por pintSocket
	 */
	int SiscomLeeNumeroRegistros(int pintSocket,int *pintPtrNRegistros);

	/*! \fn void SiscomCreaNodoLCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
	 *			       LCamposSiscomPro2 **pLCSiscomPro2);
	 *  \brief Funcion para crear el  nodo pLCSiscomPro2 con la informacion 
	 *         pSCSiscomPro2
	 *  \param pSCSiscomPro2 Nodo que se agregara a la lista.
	 *  \param[out] Informacion del registro 
	 */
	void SiscomCreaNodoLCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
				       LCamposSiscomPro2 **pLCSiscomPro2);
	/*! \fn void SiscomCreaListaCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
	 *			       LCamposSiscomPro2 **pLCSiscomPro2Prim,
	 *			       LCamposSiscomPro2 **pLCSiscomPro2Actual);
	 *  \brief Funcion que agrega el nodo pSCSiscomPro2 a la lista pLCSiscomPro2Prim
	 *  \param pSCSiscomPro2 Informacion que se debera agregar a la lista.
	 *  \param[out] pLCSiscomPro2Prim Apuntador a el primer nodo de la lista.
	 *  \param[out] pLCSisocmPro2Act Apuntador a el nodo actual de la lista
	 */
	void SiscomCreaListaCamposPro2(SCampoSiscomPro2 *pSCSiscomPro2,
				       LCamposSiscomPro2 **pLCSiscomPro2Prim,
				       LCamposSiscomPro2 **pLCSiscomPro2Actual);
	/*! \fn void SiscomLiberaListaCamposPro2(LCamposSiscomPro2 *pLCSiscomPro2Dat);
	 *  \brief Funcion para liberar la memeoria asignada a cada uno de los registros
	 *         de la lista simplemente ligada, esta funcion a su vez libera cada campo
	 *  \param pLCSiscomPro2Dat Apuntador a el primer nodo de la lista simplemente 
	 *         ligada
	 */
	void SiscomLiberaListaCamposPro2(LCamposSiscomPro2 *pLCSiscomPro2Dat);

	/*! \fn void SiscomAnexaCampoProtocolo2(const char *pchrPtrNmbCampo,
	 *				int *pintPtrNoCampo,
	 *				const char *pchrPtrCampo,
	 *				char **pchrPtrCadena);
	 *  \brief  Funcion para agregar un campo del protocolo, el formato que entrega esta
	 *          funcion es el siguiente:
	 *
	 *	%s%s%s   Nombre del campo, Numero de Campo, Campo
	 *
	 *
	 * \param[in] pchrPtrNmbCampo Nombre del campo.
	 * \param[out] pintPtrNoCampo Nuemro del campo, y a la salida de la funcion se 
	 *             incrementa el numero del campo.
	 * \param[in] pchrPtrCampo Informacion que se copiara al registro.
	 * \param[out] pchrPtrCadena Registro formateado 
	 *
	 */
	void SiscomAnexaCampoProtocolo2(const char *pchrPtrNmbCampo,
					int *pintPtrNoCampo,
					const char *pchrPtrCampo,
					char **pchrPtrCadena);

	/*!
	 *
	 * \fn void SiscomFormaRegistroIniEnvio(const char *pchrPtrOperacion,
	 *				        char **pchrPtrCadena);
	 *
	 * \brief Funcion para formar el encabezado del protocolo.
	 * \param[in] pchrPtrOperacion Operacion.
	 * \param[out] pchrPtrCadena Encabezado formateado.
	 *
	 */
	void SiscomFormaRegistroIniEnvio(const char *pchrPtrOperacion,
					 char **pchrPtrCadena);
	/*!
	 *
	 * \n void SiscomIniciaRegistro(SCampoSiscomPro2 *pSCSiscomPro2,
	 *			  int *pintPtrNCampos,
	 *			  const char *pchrPtrFormato,
	 *			  ...);
	 * \brief Funcion   Para iniciar los nombres de los campos de un registro 
	 * \param[out] pSCSiscomPro Estructura con los campos
	 * \param[out] pintPtrNCampos Numero de campos asignados.
	 * \param[int] pchrPtrFormato  "%s%s%s" Campos que se asignaran a la estructura 
	 *             cada %s representara el nombre del campo en la lista de argumentos.
	 *
	 */
	void SiscomIniciaRegistro(SCampoSiscomPro2 *,
				  int *,
				  const char *,
				  ...);

	char *AgregandoCampoAlRegistroPorEnviar(
				char *pchrPtrFormato,
				const char *pchrPtrCampo,
				SCampoSiscomPro2 *pSCSiscomPro2);

	void SiscomEnviaRegistroConFormato(int pintSocket,
					   SCampoSiscomPro2 *pSCSiscomPro2Buffer,
					   char *pchrPtrFormato,
					   ...);
	/*!
	 *\fn void SiscomAsignaDatoCampo(const char *pchrPtrNmbCampo,
	 *			   int pintNCampos,
	 *			   char *pchrPtrDato,
	 *			   SCampoSiscomPro2 *pSCSiscomPro2);
	 * \brief Funcion para asingar pchrPtrNmbCampo, con la informacion pchrPtrDat al
	 *        consecutivo de la estructura pSCSiscomPro2 
	 *        En pintNCampos se pasan el numero de campos 
	 * \param[in] pchrPtrNmbCampo Nombre del campo que se anexara a la estructura de datos.
	 * \param[in] pintNCampos Numero de campos que se copiaran en la estructura.
	 * \param[out] pSCSiscomPro2 Estructura con los campos.
	 *
	 */

	void SiscomAsignaDatoCampo(const char *,
				   int,
				   char *,
				   SCampoSiscomPro2 *);

	/*!
	 * \fn void SiscomAsignaDatoCampo2(const char *pchrPtrNmbCampo,
	 *			    const char *pchrPtrDato,
	 *			    LCamposSiscomPro2 *pLCSiscomPro2Dat);
	 * \brief Copia pchrPtrDato en el campo pchrPtrNmbCampo del nodo actual
	 *        de la lista pLCSiscomPro2Dat.
	 * \param[in] pchrPtrNmbCampo Nombre del campo.
	 * \param[in] pchrPtrDato Informacion que se copiara al nodo actual de la lista
	 * \param[out] pLCSiscomPro2Dat Nodo actual de la lista, al cual se copiara la 
	 *             informacion.
	 */



	void SiscomAsignaDatoCampo2(const char *,
				    const char *,
				    LCamposSiscomPro2 *);



	void SiscomAsignaDatoCampo2A(const char *,
				    const char *,
				    SCampoSiscomPro2 *);

				    
	void SiscomEnviaAlServidor(int,
				   int,
				   const char *,
				   LCamposSiscomPro2 *);
	int SiscomVeSiHayDatosParaLeer(int,
				       int);

	int SiscomVeSiHayDatosParaEscribir(int ,
				      int );
	int SiscomConectateServidor(int ,const char *,char **);
	/* Tepotzotlan Mexico a 24 de agosto del 2017
	 * se agrega la funcion, para eliminar el error de
	 * tiempo excesivo en la conexion, cuando un servidor
	 * no esta disponible
	 *
	 */
	int SiscomConectateClienteNoBloqueante(const char *pchrPtrDirIpSvr,
				   int pintPuerto,
				   int pintTiempo,
				   char **pchrPtrEdoConexion);

	const char *SiscomObtenDatoDelRegistro(SCampoSiscomPro2 *,
					       const char *,
					       int );
	void SiscomAnexaRegistroPro2(LCamposSiscomPro2 **,
				     LCamposSiscomPro2 **,
				     int *,
				     const char *,
				     ...);

	void SiscomLeeInformacionProtocolo(int,
					   int ,
					   LCamposSiscomPro2 **);

	/*!
	 * Esta funcion lee la informacion de pintSocket, y nos regresa en pLCSiscomPro2
	 * el primer Nodo de la lista con la informacion, y en pLCSiscomPro2Ultimo, nos
	 * almacena el ultimo nodo de la lista
	 *
	 */
	void SiscomLeeInformacionProtocoloUltimoRegistro(int pintSocket,
					   int pintPtrNRegistros,
					   LCamposSiscomPro2 **pLCSiscomPro2,
					   LCamposSiscomPro2 **pLCSiscomPro2Ultimo);
	/*!
	 * Esta  Funcion se escribe una ves que se ha detectado la necesidad de poder <br>
	 * enviar informacion de configuracion, o datos adicionales que son necesario en<br>
	 * el servidor para cada una de las operaciones que se realizar, por ejemplo en <br>
	 * el sistema de las SISCOMElectronica, se requiere realizar operaciones entre de <br>
	 * base de datos en los expendios, para indicar esto se envia como parte de los datos
	 * de consulta o de insercion el Id del expendio, con lo que en la operacion se envia<br> 
	 * informacion del expendio y de la consulta, al realizar esta estrategia se observo>br>
	 * que al requerir mas informacion de configuracion por ejemplo el usuario, o algun otro dato se complicaba el manejo de la informacion, por tal motivo la siguiente funcion<br>
	 * nos permitira separar en dos bloques los datos, por una lado la informacion de configuracion<br> 
	 * y por otro los datos.
	 * Funcion que lee la informacion que se envia a traves de pintSocket <br>
	 * la funcion leera pintNRegistros. La funcion permite leer la informacion<br>
	 * de la siguiente forma: <br>
	 * Se tendra una capa de informacion que sera leida mientras exista el campo<br>
	 * pchrPtrCampoConfig, la informacion de este campo se almacenara en pLCSiscomPro2DatConfig, una ves que se haya leido toda la informacion que contenga el campo <br>
	 * pchrPtrCampoConfig, se continuara la lectura de la informacion y se almacenara<br>
	 * en pLCSiscomPro2Dat.<br>
	 * <br>
	 * \param[in] pintSocket Socket de comunicacion
	 * \param[in] pintNRegistros Registros que se recibiran
	 * \param[in] pchrPtrCampoConfig Campo que se tomara para el bloque de configuracion
	 * \param[out] pLCSiscomPro2DatConfig Informacion del bloque de configuracion
	 * \param[out] pLCSiscomPro2Dat Informacion del bloque de datos
	 */
	void SiscomLeeInformacionProtocolo2(int pintSocket,
					    int pintNRegistros,
					    const char *pchrPtrCampoConfig,
					    LCamposSiscomPro2 **pLCSiscomPro2DatConfig,
					    LCamposSiscomPro2 **pLCSiscomPro2Dat);
	const char *SiscomObtenDato(LCamposSiscomPro2 *,
				    const char *);
	/* Lunes 17 de Septiembre del 2012 
	 * Se agrega la funcion para obtener el dato a Flot
	 */
	float SiscomObtenDatoFloat(LCamposSiscomPro2 *,const char *);
	int SiscomObtenDatoInt(LCamposSiscomPro2 *,const char *);

	const char *SiscomObtenNombreCampo(LCamposSiscomPro2 *);
	void SiscomImprimeContenidoProtocolo(const char *,FILE *,LCamposSiscomPro2 *);
	void SiscomImprimeContenidoProtocolo2(const char *,LCamposSiscomPro2 *);
	void SiscomImprimeContenidoProtocolo2A(const char *,const char *,int,LCamposSiscomPro2 *);
	void SiscomImprimeContenidoProtocoloRegistroPorRegistro(const char *,LCamposSiscomPro2 *);
	void SiscomImprimeContenidoRegistro(const char *,FILE *,SCampoSiscomPro2 *);
	void SiscomMuestraContenidoRegistro(const char *,FILE *,SCampoSiscomPro2 *);

	void SiscomCopiaCampos(SCampoSiscomPro2 *,SCampoSiscomPro2 **);

	void SiscomSumaListas(LCamposSiscomPro2 *,
			      LCamposSiscomPro2 *);



	int SiscomComparaNombreCampo(const char *pchrPtrNmbCampo,
				     const char *pchrPtrNmbCampo1);
	void SiscomSumaListaCampos(LCamposSiscomPro2 **pLCSiscomPro2Uno,
				   LCamposSiscomPro2 *pLCSiscomPro2Dos);


	int SiscomEstaElCampo(LCamposSiscomPro2 *,const char *);


	void SiscomSumaCamposAB_R(const char *pchrPtrCampoA,
			      const char *pchrPtrCampoB,
			      const char *pchrPtrCampoRes,
			      LCamposSiscomPro2 *pLCSiscomPro2Dat);


	float SiscomObtenCampoAFloat(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				     const char *pchrPtrNmbCampo);

	void SiscomAsignaDatoCampoFloat2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 const char *pchrPtrCampo,
					 float pfltDato);

	void SiscomAsignaDatoCampoInt2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 const char *pchrPtrCampo,
					 int pintDato);
	void SiscomAgrupaListaPorCampoPro2(const char *pchrPtrCampos,
				  LCamposSiscomPro2 *pLCSiscomPro2Dat,
				  LCamposSiscomPro2Agrupados **pLCSiscomPro2Agrupa);

	void SiscomCreaListaCamposPro2Agrupados(
			const char *pchrPtrCampo,
			LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaPrim,
			LCamposSiscomPro2Agrupados **pLCSiscomPro2AgrupaAct);

	void SiscomAsignaMemoriaCPro2Agrupa(
			const char *pchrPtrCampo,
			LCamposSiscomPro2Agrupados **pLCSiscomPro2Agrupa);

	int SiscomComparaCampo(LCamposSiscomPro2 *pLCSiscomPro2Uno,
			       LCamposSiscomPro2 *pLCSiscomPro2Dos,
			       const char *pchrPtrCampos);

	int SiscomComparaCampo2(LCamposSiscomPro2 *pLCSiscomPro2Uno,
			       LCamposSiscomPro2 *pLCSiscomPro2Dos,
			       const char *pchrPtrCampoUno,
			       const char *pchrPtrCampoDos);
	int SiscomComparaCampoChar(const char *pchrPtrCampo,
				   const char *pchrPtrCadena,
				   LCamposSiscomPro2 *pLCSiscomPro2Dat);
	int SiscomComparaNCaracteresCampoChar(const char *pchrPtrCampo,
				   const char *pchrPtrCadena,
				   int pintNCaracteres,
				   LCamposSiscomPro2 *pLCSiscomPro2Dat);


	const char *SiscomBuscaSubCadenaCampo(const char *pchrPtrCampo,
					      const char *pchrPtrCadena,
					      LCamposSiscomPro2 *pLCSiscomPro2Dat);
	const char *SiscomBuscaSubCadenaCampo(const char *pchrPtrCampo,
					      const char *pchrPtrCadena,
					      LCamposSiscomPro2 *pLCSiscomPro2Dat);
	LCamposSiscomPro2 *SiscomUltimoRegistro(LCamposSiscomPro2 *pLCSiscomPro2Dat);

	void SiscomEnviaVersionProtocolo(int pintSocket);
	void SiscomFormaCadenaVersion(int pintVersion,
				      int pintSubVersion,
				      char *pchrPtrCadenaVersion);
	int SiscomVersionProtocolo(int pintSocket);

	void SiscomImprimeContenidoProtocoloVertical(const char *pchrPtrArchivo,
					       const char *pchrPtrFuncion,
					       int pintNoLinea,
					    LCamposSiscomPro2 *pLCSiscomPro2);

	void SiscomInformacionServidorConRespuesta(
				int pintPtoCom,
				const char *pchrPtrDirIpSvr,
				const char *pchrPtrOperacion,
				int pintNRegistros,
				LCamposSiscomPro2 *pLCSiscomPro2,
				char **pchrPtrEdoConexion,
				int *pintPtrSocket,
				LCamposSiscomPro2 **pLCSiscomPro2Reg,
				int *pintPtrNRespuesta);

	void EliminaCaracteresNoValidosCampos(char **pchrPtrCampos);
	/* Tepotzotlan Lunes 16 de Noviembre del 2016 
	 * Se agregara una nueva funcion para mostrar el contenido del protocolo
	 * de una forma que en el caso de los Registros con un gran numero de 
	 * campos se puedan visualizar 
	 */

void SiscomRestaCamposAB_R(const char *pchrPtrCampoA,
		      const char *pchrPtrCampoB,
		      const char *pchrPtrCampoRes,
		      LCamposSiscomPro2 *pLCSiscomPro2Dat);
	#define SiscomContenidoProtocoloVertical(pLCSiscomPro2Dat) 		\
		SiscomImprimeContenidoProtocoloVertical(__FILE__,		\
							__FUNCTION__,		\
							__LINE__,		\
							pLCSiscomPro2Dat);
	#define SiscomContenidoProtocolo(pLCSiscomPro2Dat) 	\
		SiscomImprimeContenidoProtocolo2A(		\
				__FILE__,			\
				__FUNCTION__,			\
				__LINE__,			\
				pLCSiscomPro2Dat)		\

	#define SiscomContenidoAgrupadosPro2(pLCSiscomPro2AgrupaD) 		\
	{									\
	LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaD;			\
	lLCSiscomPro2AgrupaD=pLCSiscomPro2AgrupaD;				\
	for(;									\
	    lLCSiscomPro2AgrupaD;						\
	    lLCSiscomPro2AgrupaD=lLCSiscomPro2AgrupaD->LCSiscomPro2AgrupaS)	\
	{									\
	SiscomLog("Campo:%s",lLCSiscomPro2AgrupaD->chrPtrCampo);		\
	SiscomContenidoProtocolo(lLCSiscomPro2AgrupaD->LCSiscomPro2Prim);	\
	}									\
	}					
	#endif
