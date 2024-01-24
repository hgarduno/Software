#ifndef __IMP_MANEJADORPRODUCTOS_H__
#define __IMP_MANEJADORPRODUCTOS_H__

#include <UIC_H_ManejadorProductos.h>
#include <ProductosE.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class SiscomDatCom;
class ManFamilias;
class ManUnidades;
class Unidad;
class Familia;

class QManejadorProductos : public ManejadorProductos
{
    Q_OBJECT
public:
    QManejadorProductos(SiscomDatCom *,char **, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QManejadorProductos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ManFamilias *MFamilias;
	ManUnidades *MUnidades;
	Familia *FFamilia;
	Unidad *UUnidad;
	QLineEdit *QLECUnidades;
	QLineEdit *QLECFamilias;
	ProductosE PProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void MuestraCaracteres(const QString &pQStrTexto,QLineEdit *pQLENCaracteres);
	int CaracteresCadena(const QString &,int );
	void HabilitandoAnexar();
	void AnexandoProducto();
private slots:
	void S_ModificaProductos();
	void S_PasaFocoUnidades();
	void S_PasaFocoDescripcion();
	void S_PasaFocoProducto();
	void S_PasaFocoAnexarProducto();
	void S_SeleccionoUnidad(Unidad *);
	void S_SeleccionoFamilia(Familia *);
	void S_AnexarProducto();
	void S_RegistraProductos();
	void S_EliminarDeLaLista();
	void S_CambiaEliminaClave();
	void S_CapturandoDescripcion();
	void S_CapturandoClave(const QString &);
signals:
	void SignalTerminar(QWidget *);
};

extern "C" QManejadorProductos *InstanciaManejadorProductos(void *,
							    char **,
							    void *,
							    const char *,
							    int);
#endif 
