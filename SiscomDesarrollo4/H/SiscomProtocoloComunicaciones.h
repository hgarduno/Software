#ifndef __SISCOMPROTOCOLOCOMUNICACIONES__
#define __SISCOMPROTOCOLOCOMUNICACIONES__
/* Miercoles 25 de Abril 2012
 * A cada campo se le podra asociar subregistros
 * Del tipo SiscomRegistroProL 
 */
typedef struct SiscomCampo
{
const char *chrPtrNmbCampo;
char *chrPtrDato;
int intNCampos;

struct SiscomCampo *SiscomCamProLPtrSig;
struct SiscomCampo *SiscomCamProLPtrAnt;

struct SiscomCampo *SiscomCamProLPtrActual;
/* Miercoles 25 de Abril 2012
 * el campo vidPtrSubRegistros 
 * almacenara la direccion de la lista
 * simplemente ligada SiscomRegistroProL 
 * en el caso de que al campo en cuestion 
 * se le tenga asociados subregistros
 */
const void *vidPtrSubPrim;
const void *vidPtrSubAct;

/* Lunes 22 de diciembre
 * Se agrega este apuntador, para poder recorrer 
 * los registros del campo asociado
 */
const void *vidPtrIterador;
}SiscomCampoProL;

typedef struct SiscomRegistro
{
/* Jueves 26 de Abril del 2012
 * Para saber el numero de registros 
 * en la lista, este valor se almacenara
 * en el primer nodo de la lista
 */
int intNRegistros;
SiscomCampoProL *SiscomCamProLPtrDato;
struct SiscomRegistro *SiscomRegProLPtrSig;
struct SiscomRegistro *SiscomRegProLPtrAnt;

}SiscomRegistroProL;

void SiscomAsignaCampo(const char *pchrPtrCampo,
		       const char *pchrPtrDato,
		       SiscomRegistroProL *pSiscomRegProLPtrDato);
void SiscomActualizaCampoAsociado(const char *pchrPtrCampo,
				  const char *pchrPtrAsociado,
				  const char *pchrPtrValor,
				  SiscomRegistroProL *pSisRegProLPtrDato);
int SiscomMemoriaNodoCampoPro(const char *pchrPtrNmbCampo,
			  const char *pchrPtrDato,
			  SiscomCampoProL **pSiscomCamProLPtrDat);

int SiscomMemoriaNodoCampoPro2(const char *pchrPtrNmbCampo,
			  const char *pchrPtrDato,
			  SiscomCampoProL **pSiscomCamProLPtrDat);

int SiscomNodoCampoPro2(const char *pchrPtrNmbCampo,
			const char *pchrPtrDato,
			SiscomCampoProL **pSiscomCamProLPtrPrim,
			SiscomCampoProL **pSiscomCamProLPtrAct);
int SiscomNodoCampoPro(const char *pchrPtrNmbCampo,
			   const char *pchrPtrDato,
			   SiscomCampoProL **pSiscomCamProLPtrPrim,
			   SiscomCampoProL **pSiscomCamProLPtrAct);
SiscomCampoProL *SiscomFormaRegistro(char **pchrPtrCampos,
			SiscomCampoProL **pSiscomCamProLPtrPrim,
			SiscomCampoProL **pSiscomCamProLPtrAct);

int SiscomAgregaCampo(const char *pchrPtrNmbCampo,
		      const char *pchrPtrDato,
		      SiscomCampoProL **pSiscomCamProLPtrPrim,
		      SiscomCampoProL **pSiscomCamProLPtrAct);

int SiscomAgregaCampoRegistro(const char *pchrPtrNmbCampo,
			 const char *pchrPtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato);

int SiscomAgregaCampoRegistros(const char *pchrPtrNmbCampo,
			       const char *pchrPtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrDato);
int SiscomMemoriaRegistroPro(
		      const SiscomCampoProL *pSiscomCamProLPtrDat,
		      SiscomRegistroProL **pSiscomRegProLPtrDat);

int SiscomNodoRegistroPro(const SiscomCampoProL *pSiscomCamProLPtrDat,
			  SiscomRegistroProL **pSiscomRegProLPtrPrim,
			  SiscomRegistroProL **pSiscomRegProLPtrAct);

SiscomCampoProL *SiscomFormaCamposFormato(const char *pchrPtrFormato,
					  char *pchrPtrBuffer);

int SiscomAnexaRegistroPro(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrAct,
			   char *pchrPtrBuffer,
			   const char *pchrPtrFormato,
			   ...);
/*
int SiscomAnexaRegistroPro2(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrAct,
			   SiscomRegistroProL *pSiscomRegProLDato);
*/
int SiscomAnexaRegistroPro3(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			    SiscomRegistroProL **pSiscomRegProLPtrAct);
SiscomCampoProL *SiscomObtenCampoRegistroProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomRegProLPtrDat);
const char *SiscomObtenCampoRegistroProLChar(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat);

const char *SiscomCampoProLCharNulo(const char *pchrPtrNmbCampo,
				    SiscomRegistroProL *pSiscomRegProLPtrDat);

int SiscomCampoRegistroProLCharEsVacio(const char *pchrPtrNmbCampo,
				       SiscomRegistroProL *pSiscomRegProLPtrDato);
int SiscomObtenCampoRegistroProLInt(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat);

float SiscomObtenCampoRegistroProLFloat(const char *pchrPtrNmbCampo,
					     SiscomRegistroProL *pSiscomRegProLPtrDat);
SiscomRegistroProL *SiscomObtenRegistrosCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct);

						
SiscomRegistroProL *SiscomObtenRegistroActualCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct);

SiscomRegistroProL *SiscomObtenRegistroPrimCampoProL(
			const char *pchrPtrNmbCampo,
			SiscomRegistroProL *pSiscomProLPtrAct);
int SiscomAnexaRegistrosAlCampo(const char *pchrPtrNmbCampo,
				SiscomRegistroProL *pSiscomRegProLPtrDat,
				char *pchrPtrBuffer,
				const char *pchrPtrFormato,
				...);

int SiscomRegistrosAlCampo(
		const char *pchrPtrNmbCampo,
		const SiscomRegistroProL *pSiscomRegProLPtrPrim,
		const SiscomRegistroProL *pSiscomRegProLPtrAct,
		SiscomRegistroProL *pSiscomRegProLPtrDat);
int SiscomEnviaCadenaSocket(int pintSocket,
			    const char *pchrPtrCadena);

int SiscomEnviaIntSocket(int pintSocket,
			 int pintCerosIzquierda,
			 int pintEnvio);
int SiscomEnviaRegistrosSocket(int pintSocket,
			       char *pchrPtrBuffer,
				const SiscomRegistroProL *pSiscomRegProLPtrDat);

int SiscomEnviaRegistrosSocketSinFinal(int pintSocket,
			       char *pchrPtrBuffer,
			       const SiscomRegistroProL *pSiscomRegProLPtrDat);
int SiscomEnviaRegistrosAsociadosSocket(int pintSocket,
					char *pchrPtrBuffer,
					const SiscomRegistroProL *pSiscomRegProLPtrDat);

int SiscomLeeCaracteresSocket(int pintSocket,
			      int pintNCaracteres,
			      char *pchrPtrBuffer);

int SiscomLeeCaracteresSocketInt(int pintSocket,
				 int pintNCaracteres,
				 char *pchrPtrBuffer);

int SiscomLeeRegistroSocket(int pintSocket,
			    int pintNCampos,
			    char *pchrPtrBuffer,
			    SiscomCampoProL **pSiscomCamProLPtrReg);
int SiscomLeeRegistrosSocket(int pintSocket,
			     char *pchrPtrBuffer,
			     SiscomRegistroProL **pSiscomRegProLPtrDat,
			     SiscomRegistroProL **pSiscomRegProLPtrAct);

int SiscomLeeCampoDatoSocket(int pintSocket,
			     char *pchrPtrBuffer,
			     char **pchrPtrNmbCampo,
			     char **pchrPtrCampo);

int SiscomLeeInformacionCampoSocket(int pintSocket,
			    char *pchrPtrBuffer);

int SiscomConectateCliente(const char *pchrPtrDirIp,
  			   int pintPuerto,
			   char **pchrPtrEdoConexion);

int SiscomConectateClienteNoBloqueante(const char *pchrPtrDirIpSvr,
  			   int pintPuerto,
			   int pintTiempo,
			   char **pchrPtrEdoConexion);

int SiscomConectateClienteNoBloqueante4(const char *pchrPtrDirIpSvr,
  			   int pintPuerto,
			   int pintTiempo,
			   char **pchrPtrEdoConexion);
int SiscomComparaCadenaCampoRegistroProL(const char *pchrPtrCadena,
					 const char *pchrPtrCampo,
					 SiscomRegistroProL *pSiscomRegProLPtrDat);

const char *SiscomBuscaCadenaCampoRegistroProL(const char *pchrPtrCadena,
					       const char *pchrPtrCampo,
					       SiscomRegistroProL *pSiscomRegProLPtrDat);

int SiscomComparaCampoRegistrosProL(const char *pchrPtrCampo,
				    SiscomRegistroProL *pSiscomRegProLPtrUno,
				    SiscomRegistroProL *pSiscomRegProLPtrDos);

int SiscomComparaCampoRegistrosProL2(const char *pchrPtrCampoUno,
				     const char *pchrPtrCampoDos,
				    SiscomRegistroProL *pSiscomRegProLPtrUno,
				    SiscomRegistroProL *pSiscomRegProLPtrDos);

SiscomRegistroProL *SiscomSiguienteNodoRegistroProL(SiscomRegistroProL *pSiscomRegProLPtrDat);
int SiscomRegistrosConCampoIguales(const char *pchrPtrCampo,
				   SiscomRegistroProL *pSiscomRegProLPtrA,
				   SiscomRegistroProL *pSiscomRegProLPtrB);

void SiscomActualizaCampoAsignaMemoria(char *pchrPtrDato,
			  SiscomCampoProL *pSiscomCampoProLDat);
void SiscomActualizaCampo(char *pchrPtrDato,
			  SiscomCampoProL *pSiscomCmpProLDat);
void SiscomActualizaCampo2(const char *pchrPtrCampo,
			   char *pchrPtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomActualizaCampoAsignaMemoria2(const char *pchrPtrCampo,
			   char *pchrPtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato);
			  
void SiscomActualizaCampoRegistro(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);
/*Domingo 11 de enero 2015 
 * Busca el campo pchrPtrCampo, de pSiscomRegProLPtrDato y 
 * le asigna el valor pchrPtrValo, asignando memoria dinamica
 * al campo, la actualizacion del campo solo se realiza en 
 * el registro actual apuntado por pSiscomRegProLPtrDato, no 
 * se recorre la lista
 */
void SiscomActualizaCampoRegistroActual(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomActualizaCampoFloatRegistro(const char *pchrPtrCampo,
			  const char *pchrPtrFormato,
			  float pfltValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomActualizaCampoFloatRegistroActual(const char *pchrPtrCampo,
			  const char *pchrPtrFormato,
			  float pfltDato,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomActualizaCampoIntRegistroActual(const char *pchrPtrCampo,
			  int pintDato,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);
void SiscomActualizaCampoAsignaMemoriaRegistro(const char *pchrPtrCampo,
			  char *pchrPtrValor,
			  SiscomRegistroProL *pSiscomRegProLPtrDato);
void SiscomIdUnicoRegistros(const char *pchrPtrCampo,
			    SiscomRegistroProL *pSiscomRegProLPtrDato);
/* Lunes 22 de diciembre del 2014
 * Obtiene los registros asociados de pchrPtrAsociado, en el 
 * registro actual pSiscomRegProLPtrActual y de los registros 
 * regresa el campo pchrPtrCampo, del primer registro asociado
 *
 * Esta funcion es util, cuando sabemos que el campo asociado solo
 * tiene un registro
 */
const char *SiscomAsociadoPrimerCampo(const char *pchrPtrAsociado,
				const char *pchrPtrCampo,
				SiscomRegistroProL *pSiscomRegProLPtrActual);

const char *SiscomBuscaDatoRegistros(const char *pchrPtrAsociado,
				     const char *pchrPtrCampo,
				     const char *pchrPtrCadena,
				     const char *pchrPtrCampoRegreso,
				     SiscomRegistroProL *pSiscomRegProLPtrDatos);

int SiscomBuscaDatoRegistrosInt(const char *pchrPtrAsociado,
				     const char *pchrPtrCampo,
				     const char *pchrPtrCadena,
				     const char *pchrPtrCampoRegreso,
				     SiscomRegistroProL *pSiscomRegProLPtrDatos);
SiscomRegistroProL *SiscomRegistrosAsociadosCampo(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomMultiplicaCamposACampo(const char *pchrPtrCampoA,
				  const char *pchrPtrCampoB,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomSumaCamposACampo(const char *pchrPtrCampoA,
				  const char *pchrPtrCampoB,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomSumaCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato);
void SiscomMultiplicaCamposACampoRegistros(const char *pchrPtrCampoA,
					   const char *pchrPtrCampoB,
					   const char *pchrPtrResultado,
					   const char *pchrPtrFormato,
					   SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomMultiplicaCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomDivideCampoPorDato(const char *pchrPtrCampo,
				  float pfltDato,
				  const char *pchrPtrResultado,
				  const char *pchrPtrCadenaFormato,
				  SiscomRegistroProL *pSiscomRegProLPtrDato);

float SiscomObtenSumatoriaRegistros(const char *pchrPtrCampo,
				    SiscomRegistroProL *pSiscomRegProLPtrDato);

void SiscomAsignaFechaHoraCampo(const char *pchrPtrCampo,
			   SiscomRegistroProL *pSiscomRegProLPtrDato);
void SiscomAsignaFechaCampo(const char *pchrPtrCampo,
			   SiscomRegistroProL *pSiscomRegProLPtrDato);

SiscomRegistroProL *SiscomContadorRegistrosProL(const char *pchrPtrCampo,
                SiscomRegistroProL *pSiscomRegProLPtrDat);

void SiscomEliminaNodoPro(SiscomRegistroProL *pSisRegProLPtrLista,
                SiscomRegistroProL *pSisRegProLPtrElimina);

int SiscomEnviaRegistroSocket(int pintSocket,
			      char *pchrPtrBuffer,
			      const SiscomRegistroProL *pSiscomRegProLPtrDat);
int SiscomVersionProtocolo4(int pintSocket);
int SiscomEstaElCampo4(const char *pchrPtrCampo,
		      SiscomRegistroProL *pSiscomRegProLPtrDat);
void SiscomCambiaAMayusculas(const char *pchrPtrCampo,SiscomRegistroProL *pSiscomRegProLPtrDat);
		
void SiscomEliminaEspaciosFinalCampo(const char *pchrPtrCampo,
				     SiscomRegistroProL  *pSiscomRegProLPtrDato);

void SiscomAgrupaPorCampo(const char *pchrPtrCampo,
			  const char *pchrPtrNombreAsociado,
			  char **pchrPtrCamposRegistroAgrupado,
			  char **pchrPtrCamposRegistros,
			  SiscomRegistroProL *pSiscomRegProLPtrEntrada,
			  SiscomRegistroProL **pSiscomRegProLPtrPrimAgrupado,
			  SiscomRegistroProL **pSiscomRegProLPtrActAgrupadao);
SiscomRegistroProL *SiscomBuscaRegistroLista(const char *pchrPtrCampo,
					     const char *pchrPtrValor,
					     SiscomRegistroProL *pSiscomRegProLPtrLista);

void SiscomOrdenaRegistroProL(const char *pchrPtrCampo,
			      SiscomRegistroProL *pSiscomRegProLPtrEntrada,
			      SiscomRegistroProL **pSiscomRegProLPtrSalPrim,
			      SiscomRegistroProL **pSiscomRegProLPtrSalAct);


/* Siscom Zacatenco 
 * 24 Julio del 2024
 * 
 * No hay una rutina con el ultimo campo  del registro ....
 *
 */

SiscomCampoProL *SiscomUltimoCampoRegistro(SiscomRegistroProL *pSisRegProLPtrDato);
SiscomRegistroProL *SiscomUltimoNodoLista(SiscomRegistroProL *pSiscomRegProLPtrDato);

int SiscomAgregaCampoRegistro2(const char *pchrPtrNmbCampo,
			 const char *pchrPtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato);
#endif
