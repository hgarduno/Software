#ifndef __SISCOMTIENDAS4_H__
#define __SISCOMTIENDAS4_H__
#include <SISCOMVentanaPrincipal3.h>
class CQSisPerfilVentas;
class CQSisPerfilPrincipal;
class CQSisEmpleado;
class QPedidos;
class QSisServidorMensajes;
/*
 *
 * La forma en la que se administraran los argumentos a las distintas
 * pantallas sera de la siguiente forma:
 *
 * Cada patantalla tendra una arreglo de apuntadores a caracteres
 * los cuales almacenaran la informacion de la siguiente forma
 *
 *
 *
 * En La posicion 0 del arreglo se almacenara una clase CQSisEmpresa
 * con el expendio, el argumento 1 se almacena una clase CQSiEmpleado
 * con la informacion del empleado que se ha firmado al sistema.
 *
 * Se apartaran las 10 primeras localidades, para informacion referente
 * a los argumentos de operacion de expendios, usuarios etc.
 *
 * En las siguientes posiciones se asignara la informacion de configuracion
 * que se cargara del archivo de configuracion por pantalla, esto es
 * en el archivo xml por cada pantalla
 *
 *
 * Martes 22 De Enero 2008
 *
 * Se asigna la posicion 9 del arreglo para copiar el IdAplicacion
 *
  * Actualizacion:
 *
 * 03 Abril 2008
 *
 * Se requerira realizar una adecuacion a esto, ya que al momento 
 * de cargar los argumentos, en la modificacion de la ventana principal
 * se pasa en la posicion cero la clase SisUsuarioSeg3 
 *
 * Por lo tanto el id del empleado se pasara en la posicion 1
*
 *
 */
class SiscomTiendas4:public SISCOMVentanaPrincipal
{
Q_OBJECT
public:
	SiscomTiendas4(QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags pWFlags=0);
private:
	void ObtenDatosComunicacion();
	void CargaFirmaUsuario();
	void CargaArgumentos();
	void CargaSistemaSeguridad();
	CQSisPerfilVentas *PerfilVentas();
	void PerfilPrincipal();
	void AsignaPerfilVentas(const char *);
	void *FuncionModuloDinamico(const char *);
	const char *ValidaVariableAmbiente(const char *,const char *);
	const char **ArgumentosPantalla(const char *);
	void CargaBibliotecaNivelesUtilizacion();
	void SiscomEsAutenticaLaClave();
	void SiscomEsValidaMacAddress();
	void SiscomCargaFlagMultiUsuario();
	void AsignaIdAplicacionModulos(const char *);
	void AsignaEmpleado(const char *);
	void customEvent(QCustomEvent *);
	void IniciaServidorMensajes();
private:
	int intPtoCom;
	const char *chrPtrDirIp;
	const char *chrPtrIdAplicacion;
	const char *chrPtrIdPerfil;
	void *vidANivelUtilizacion;
	int intSistemaMultiUsuario;
	QSisServidorMensajes *QSSvrMensajes;
	SiscomRegistrosPro2 *SRegistrosPro2Mensaje;
	QPedidos *QPedido;
	SiscomDatCom *SisDatCom;

};

#endif
