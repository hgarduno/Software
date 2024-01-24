#ifndef __IMP_ACTUALIZAPRECIOS_H__
#define __IMP_ACTUALIZAPRECIOS_H__

#include <UIC_H_ActualizaPrecios.h>
#include <TiposPrecios.h>
#include <Personas.h>
#include <Productos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QComboBox;
class CSISCOMDatComunicaciones;

/*! 
 *  \class QActualizaPrecios
 *  \brief Ventana para actualizar los precios de los productos
 *         que se venden en El Fresno
 *
 *
 *  \author	Heli Garduno Esquivel
 *  \version	1.0
 *  \date	2008
 */
class QActualizaPrecios : public ActualizaPrecios
{
    Q_OBJECT

public:
    /*! Botones que puede Seleccionar el usuario
     *
     */
    enum BTN_Botones
    {
	Aceptar
    };
    /*! Constructor de la clase
     *
     * \param pCSisDatCom Informacion de comunicaciones con el servidor
     * \param pProducto   Producto al cual se le asignara el precio
     * \param pchrPtrPrecio Precio al que se vendera el producto
     * \param parent	Sistema Qt
     * \param name	Nombre del Widget
     * \param modal	Es modal
     * \param fl
     */
    QActualizaPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
		      Producto *pProducto,
		      const char *pchrPtrPrecio,
		      QWidget* parent = 0,
		      const char* name = 0,
		      bool modal = FALSE, 
		      WFlags fl = 0 );
     /*! Destructor de la clase
      *
      */
    ~QActualizaPrecios();
    /*! Regresa la seleccion del usuario
     *
     */
    BTN_Botones ObtenSeleccion();
private:
	CSISCOMDatComunicaciones *CSisDatCom; 
	Producto *PProducto;
	CQTiposPrecios CQ_TiposPrecios;
	CQ_Personas CQPersonas;
	const char *chrPtrPrecio;
	BTN_Botones BTN_Seleccion;
	CQPrecios CQPPrecios;
private:
	/*! Realiza las conexiones a los objetos para 
	 * las senales de los controles 
	 */
	void ConectaSlots();
	void IniciaVariables();
	void LlenaComboTiposPrecios();
	void MuestraYAsignaPrecios();
	void AnexaPrecio(CQ_Persona *);
private slots:
	void S_SeleccionaCliente();
	void S_Aceptar();
	void S_SeleccionaPublicoEnGeneral();
};

#endif 
