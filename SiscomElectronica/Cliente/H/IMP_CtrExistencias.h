#ifndef __IMP_CTREXISTENCIAS_H__
#define __IMP_CTREXISTENCIAS_H__

#include <UIC_H_CtrExistencias.h>
#include <ProductosE.h>
#include <SiscomRegistros3.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTable;
class QPushButton;
class SiscomDatCom;
class QManProductos;

class QCtrExistencias : public CtrExistencias
{
    Q_OBJECT

public:
    QCtrExistencias(SiscomDatCom *,
    		    char **,
    		    QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCtrExistencias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QManProductos *QMProductos;
	QLineEdit *QLECProductos;
	ProductosE PProductos;
	SiscomRegistro3Lst SisReg3LstReporteExMinima;
	int intActivarAnexarProductos;
private:
	void IniciaVariables();
	void ConectaSlots();
	void MuestraProductos();
	void closeEvent(QCloseEvent *);
	void ReportePorExistenciaMinima();
	void ConsultaReportePorExistenciaMinima();
	void MuestraReportePorExistenciaMinima();

	void ConsultandoExistenciasProductos(const char *pchrPtrCveProducto);
	void ConsultaExistenciasProductos(const char *pchrPtrCveProducto);
	void MuestraExistenciasProductos();

	void ConsultandoExistenciasProductosPorCasiClave(const char *pchrPtrCveProducto);
	void ConsultaExistenciasProductosPorCasiClave(const char *pchrPtrCveProducto);

	void ConsultaExistenciasExpendio();
	void ConsultandoExistenciasExpendio();

	void ConsultandoPorcentajeExMinima(const char *pchrPtrPAlto,
					   const char *pchrPtrPBajo);
	void ConsultaPorcentajeExMinima(const char *pchrPtrPAlto,
					const char *pchrPtrPBajo);

	void ConsultandoProductosBodega();
	void ConsultaProductosBodega();

	void VeSiEliminaConsultaAnterior();

private slots:
	void S_SeleccionoProducto(ProductoE *);
	void S_NoEstaClave(const char *);
	void S_PorcentajeExistencia();
	void S_ExistenciaMinima();
	void S_ActivarAnexarProductos();
	void S_ExistenciasExpendio();
	void S_ProdsBodega();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCtrExistencias *InstanciaCtrExistencias(void *,
						   char **,
						   void *,
						   const char *,
						   int );
#endif 
