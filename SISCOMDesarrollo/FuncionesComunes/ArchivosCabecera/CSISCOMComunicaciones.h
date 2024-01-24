#ifndef __CSISCOMCOMUNICACIONES_H__
#define __CSISCOMCOMUNICACIONES_H__
extern "C"{
#include <FuncionesComunes.h>
};

/*!	\class CSISCOMDatComunicaciones
 * 	\brief Clase que contine la informacion de los datos
 * 	de conexion entre la aplicacion cliente y el servidor
 * 	
 */
 
class CSISCOMDatComunicaciones
{
	public:
		/*! Constructor de la clase
		 */
		
		CSISCOMDatComunicaciones();

		/*! Constructor de la clase
		 * \param int pintPtoCom Puerto del servidor
		 * \param const char *pchrPtrDirIpSvr Direccion del servidor
		 * \param const char *pchrPtrUsuario Usuario 
		 * \param const char *pchrPtrPassword Password
		 */
		CSISCOMDatComunicaciones(int,const char *,const char *,const char *);
		/*! Regresa el puerto de comunicaciones 
		 */
		int ObtenPtoCom();
		/*! Regresa la direccion Ip del servidor
		 */
		const char *ObtenDirIpSvr();
		/*! Regresa el Usuario 
		 */

		const char *ObtenUsuario();
		/*! Regresa el password
		 */
		const char *ObtenPassword();
		const char *ObtenIdAplicacion();
		void PonPtoCom(int);
		void PonDirIpSvr(const char *);
		void PonUsuario(const char *);
		void PonPassword(const char *);
		void PonIdAplicacion(const char *);

		
	private:
		int intPtoCom;
		const char *chrPtrDirIpSvr;
		const char *chrPtrUsuario;
		const char *chrPtrPassword;
		const char *chrPtrIdAplicacion;
		

	private:
};
class CSISCOMComunicaciones
{

	public:
		CSISCOMComunicaciones();
		CSISCOMComunicaciones(int ,
				      const char *,
				      const char *,
				      const char *);
		CSISCOMComunicaciones(CSISCOMDatComunicaciones);
		~CSISCOMComunicaciones();	
		
		void PonDatosDLLAltaServidor(int,const char *,const char *);

		void PonDatosDLLAltaServidor(const char *,const char *);
		void IniciaCamposAEnviar(int );
		void AnexaCampo(int ,const char *);
		void AnexaRegistro();
		void  AnexaRegistro(const char *,...);
		void AnexaRegistro(char **);
		void EnviaInformacionAlSvrAlta();
		StcLtaRegComSISCOM *ObtenRegistrosEnviados();
		StcLtaRegComSISCOM *ObtenRegistrosResAlta();
		
		

	private:
		const char *chrPtrDLLServidorAlta;
		const char *chrPtrDLLFuncionAlta;
		CSISCOMDatComunicaciones CSDComInfo;
		char **chrPtrDatProtocolo;
		StcLtaRegComSISCOM *SLRCSisPrim;
		StcLtaRegComSISCOM *SLRCSisActual;
		StcLtaRegComSISCOM *SLCRCSisPrimReg;
		int intNCampos;
		int intNRegistros;
		int intSocketCom;
		int intNRegResAlta;
		int intNCamResAlta;

		char **chrPtrCamposEnviar;
	private:
		void FormaProtocoloEncabezado();

};


#endif
