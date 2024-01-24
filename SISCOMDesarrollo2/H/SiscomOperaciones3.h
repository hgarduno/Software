#ifndef __SISCOMOPERACIONES3_H__
#define __SISCOMOPERACIONES3_H__
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro4;
/*!
 * \brief SiscomOperaciones3, permite realizar las operaciones de intercambio de <br>
 * informacion entre el cliente y el servidor de las aplicaciones. <br>
 * Esta clase realizara la conexion con el servidor, y podra enviar la informacion<br>
 * almacenada en una variable del tipo SiscomRegistro3Lst <br>
 * 							  <br>
 *
 * El resultado de la operacion se almacenara en una variable del tipo 
 * SiscomRegistro3Lst <br>
 * El protocolo de envio se construye de la siguiente forma: <br>
 * 000001 --> Numero de registros que se envian en 6 posiciones rellenado con 0 a la izquierda <br>
 * 0009Operacion0000 --> Tamano de la operacion en 4 digitos, Operacion 0 en 4 digitos<br>
 * lo anterior se envia por cada registro.
 *
 */
class SiscomOperaciones3
{
public:
	SiscomOperaciones3();
	/*!
	 * \brief  Constructor de la clase 
	 * \param[in]  Datos de conexion con el servidor
	 */
	SiscomOperaciones3(SiscomDatCom *pSisDatCom); 
	/*!
	 * \brief Destructor de la clase 
	 *
	 */
	~SiscomOperaciones3();
	/*!
	 * \brief  Envia  pSRegistro3Lst al servidor SiscomDatCom el cual ejecutara <br>
	 * la operacion pchrPtrOperacion.j
	 * \param[in] pchrPtrOperacion Operacion que debera ejecutar el servidor
	 * \param[in] pSRegistro3Lst Informacion que se envia al servidor
	 * \param[in] pSRegistro3LstRes Informacion que el servidor envio al cliente
	 */
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3Lst,
			 SiscomRegistro3Lst *pSRegistro3LstRes);
	/*!
	 * \brief  Envia  pSRegistro3Lst al servidor SiscomDatCom el cual ejecutara <br>
	 * la operacion pchrPtrOperacion.
	 * \param[in] pchrPtrOperacion Operacion que debera ejecutar el servidor
	 * \param[in] pSRegistro3LstRes Informacion que el servidor envio al cliente <br>
	 * 	      para este caso el registro ya tiene los campos que se actualizaran
	 * 	      esto lo realiza el servidor, por tal motivo la respuesta se almacena
	 * 	      en el mismo parametro
	 */
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3LstRes);
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3LstRes,
			 SiscomRegistro4 *pSisReg4Regreso);

	/*!
	 * Se envia la informacion que se formara mediante un registro <br>
	 * SiscomParametroConsulta3, con los datos que se pasen en <br>
	 * pchrPtrFormato, de la siguiente forma:<br>
	 * "%s%s%s", donde cada %s se sera el dato que se copie al campo <br>
	 * Parametro de SiscomParametroConsulta3, la operacion que ejecutar <br>
	 * el servidor pchrPtrOperacion, en pSRegistro3LstRes, se obtendra <br>
	 * la informacion que el servidor envie
	 * \param pchrPtrOperacion Operacion que ejecutar el servidor
	 * \param pSRegistro3LstRes respuesta
	 * \param pchrPtrFormato Informacion que se copiara a la<br>
	 *        lista SiscomParametroConsulta3 
	 */
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3LstRes,
			 const char *pchrPtrFormato,
			 ...);
	void SiscomEnvia2(const char *pchrPtrOperacion,
			  SiscomRegistro4 *pSisReg4Regreso,
			  const char *pchrPtrFormato,
			  ...);
	
	void SiscomEnvia2(const char *pchrPtrOperacion,
			  SiscomRegistro3Lst  *pSisReg3LstRegreso,
			  const char *pchrPtrFormato,
			  ...);

	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro4 *pSisReg4Regreso,
			 const char *pchrPtrFormato,
			 ...);
	/*!
	 * Se envia pSisReg3Envio, de manera interna esta funcion 		<br>
	 * forma la lista SiscomRegistro3Lst, el servidor ejecutara 		<br>
	 * pchrPtrOperacion, si se pasa diferente de null en el parametro 	<br>
	 * pSisReg3Respuesta, entonces la funcion leera del servidor la inf	<br>
	 * la respuesta y la almacenera en pSisReg3Respuesta
	 * \param pchrPtrOperacion Operacion que ejecuta el servidor
	 * \param pSisReg3Envio  Registro que se envia al servidor
	 * \param pSisReg3Respuesta Respuesta que se envia del servidor <br>
	 *        al cliente
	 */
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3 *pSisReg3Envio,
			 SiscomRegistro3Lst *pSisReg3Respuesta);

	void SiscomEnvia(const  char *pchrPtrOperacion,
			 SiscomRegistro3 *pSisReg3Conf,
			 SiscomRegistro4 *pSisReg4Info,
			 SiscomRegistro4 *pSisReg4Res);
	void SiscomEnvia(const char *pchrPtrOperacion,
			 SiscomRegistro3 *pSisReg3Envio,
			 SiscomRegistro3LstLst *pSisReg3LstLstReg);


	/*!
	 * Funcion que se desarrollo para el manejo de la informacion <br>
	 * del protocolo en un buffer, esto para integrar a las aplicaciones <br>
	 * la utilizacion del portapapeles, la informacion que las aplicaciones
	 * copien debera estar basado en el protocolo para su mejor manejo
	 *
	 * Copia pchrPtrOperacion y cada uno de los registros de pSRegistros3Lst
	 * y se armara el protocolo pero en lugar de enviarse por el socket
	 * se copiara a pchrPtrProtocolo
	 */
	void SiscomCopiaProtocoloCadena(const char *pchrPtrOperacion,
					SiscomRegistro3Lst *pSRegistro3Lst,
					char *pchrPtrProtocolo);
	void SiscomFormaRegistrosCadena(const char *pchrPtrCadena,
					SiscomRegistro3Lst *pSisReg3LstRegreso);
	/*
	 * Para simplificar los casos de lectura de la respuesta 
	 * en los cuales se deben varias condiciones, se leera 
	 * primero el nombre de la respuesta y despues el registro,
	 * esto de forma separada, por lo cual se escribe las siguientes
	 * 2 funciones
	 */
	void SiscomObtenNombreRespuesta(char **pchrPtrRespuesta,int *pintPtrNRegistros);
	void SiscomObtenRespuesta(int pintNRegistros,SiscomRegistro3Lst *);
	void SiscomObtenRespuesta(int pintNRegistros,SiscomRegistro4 *);

private:
	int intSocket;
	SiscomDatCom *SisDatCom;
	const char *chrPtrEdoConexion;
private:
	void ConectaServidor();
	void EnviaNumeroRegistros(int);
	void NumeroRegistros(int ,char *);
	void EnviaCadena(const char *);
	void InicioRegistro(const char *,char **);
	void AnexaCampoProtocolo2(const char *,
				  int *,
				  const char *,
				  char **);
	void AnexaDatoCampo(const char *,char **);
	void NumeroCamposAlProtocolo(int,char *);
	/*
	 * Con la integracion del nuevo dato SiscomRegistro4Lst 
	 * ahora se requiere enviar el numero total de registros
	 * del dato,esto debera incluir el numero de registros
	 * principales mas el numero de subregistros de cada sub
	 * registro, para lo que sobrecarga esta funcion para 
	 * enviar por fuera el numero de registros y no desde
	 * la funcion original
	 *
	 */
	void EnviaRegistros(int,
			 const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3Lst);
	void EnviaRegistros(const char *pchrPtrOperacion,
			 SiscomRegistro3Lst *pSRegistro3Lst);
	void ObtenRespuesta(SiscomRegistro3Lst *);
	void ObtenRespuesta(SiscomRegistro3LstLst *);
	void ObtenRespuesta(SiscomRegistro4 *);	
	void LeeDato(int ,char *);
	void LeeDato(int ,int *);
	void LeeDato(int,char **);
	char *LeeDato(const char *,int,char *);
	char *LeeDato(const char *,int,int *);
	char *LeeDato(const char *,int,char **);
	void ObtenNombreRespuesta(char **);
	char *ObtenNombreRespuesta(const char *pchrPtrCadena,char **);
			

	void ObtenCampoProtocolo(int *,char **,char **);
	char *ObtenCampoProtocolo(const char *,int *,char **,char **);
	void EnviaVersionProtocolo();
};


#endif
