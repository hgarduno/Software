#include <IMP_SalidaMaterial.h>
#include<SiscomDesarrollo3Qt++.h>

#include <CQSisOpeMotivosSalidas.h>
#include <CQSisOpeSalidaProductos.h>
#include <CQSisDatosMotivosSalidas.h>
#include <CQSisProductos4.h>

#include <CotizaDispositivos.h>

#include <qcombobox.h>
#include <qlcdnumber.h>
QSalidaMaterial *InstanciaSalidaMaterial(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QSalidaMaterial((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QSalidaMaterial::QSalidaMaterial(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				SalidaMaterial(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QSalidaMaterial::~QSalidaMaterial()
{

}

void QSalidaMaterial::ConectaSlots()
{
connect(QCBMotivos,
	SIGNAL(activated(int)),
	SLOT(SlotSeleccionoMotivo(int)));
connect(QMProductos,
	SIGNAL(SignalProducto(ProductoE *)),
	SLOT(SlotSeleccionoProducto(ProductoE *)));
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoProductos()));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexar()));
connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistrar()));
}
void QSalidaMaterial::SlotRegistrar()
{
EnviaSalida();
CQSProductos->SiscomLimpia();
QTDatos->setNumRows(0);
QCBMotivos->setEnabled(true);
SiscomDesarrollo3Qt::FocoAControl(QLECMotivos);
delete(CQSProductos);
CQSProductos=new CQSisProducto4(chrPtrArgumentos[0]);
}
void QSalidaMaterial::SlotAnexar()
{
CQSProductos->AgregaProducto(ProdSeleccionado);
SiscomDesarrollo3Qt::FocoAControl(QLECantidad);
MuestraProductos();
}
void QSalidaMaterial::SlotPasaFocoProductos()
{
SiscomDesarrollo3Qt::FocoAControl(QLECProductos);
}
void QSalidaMaterial::SlotSeleccionoProducto(ProductoE *pProductoE)
{
ProdSeleccionado=pProductoE;
ProdSeleccionado->SiscomActualizaCampo("Cantidad",
			SiscomDesarrollo3Qt::InformacionEdit(QLECantidad));
VerificaExistencia();
}
void QSalidaMaterial::SlotSeleccionoMotivo(int pintMotivo)
{
    if(pintMotivo!=-1)
    {
    SisReg3Motivo=CQSMSalidas.RegistroSubGrupo(pintMotivo,0,0);
    SiscomContenidoRegistro3(SisReg3Motivo);
    SiscomDesarrollo3Qt::FocoAControl(QLECantidad);
    QCBMotivos->setEnabled(false);
    CQSProductos->MotivoSalida(SisReg3Motivo);
    }
}
void QSalidaMaterial::IniciaVariables()
{
QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
QLECMotivos=SiscomColocaEditAlCombo(QCBMotivos,"QLECMotivos");
QMProductos=new QManProductos(SisDatCom,
			      chrPtrArgumentos[0],
			      QCBProductos,
				      QLECProductos,
				      QLEDescripcion,
				      this,
				      "QMProductos");

    ConsultandoMotivos();
    CQSProductos=new CQSisProducto4(chrPtrArgumentos[0]);
    SiscomDesarrollo3Qt::PasaFocoControl(QLECMotivos);
}
void QSalidaMaterial::ConsultandoMotivos()
{
ConsultaMotivos();
MuestraMotivos();
}

void QSalidaMaterial::ConsultaMotivos()
{
CQSisOpeMotivosSalidas lCQSOMSalidas(SisDatCom);
lCQSOMSalidas.Motivos(new CQSisDatosMotivosSalidas(chrPtrArgumentos[0]),
		      &CQSMSalidas);
}

void QSalidaMaterial::MuestraMotivos()
{
SiscomDesarrollo3Qt::Registros4PrincipalAlCombo(
			"descripcion",
			QCBMotivos,
			&CQSMSalidas);
}

void QSalidaMaterial::MuestraProductos()
{
const char *lchrPtrCampos[]={"Clave","Cantidad",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(
		       lchrPtrCampos,
		       QTDatos,
		       CQSProductos->RegistrosSubGrupo(0,2));
}

void QSalidaMaterial::EnviaSalida()
{
CQSisOpeSalidaProductos lCQSOSProductos(SisDatCom);
lCQSOSProductos.RegistraSalidaProductos(CQSProductos);
}

void QSalidaMaterial::VerificaExistencia()
{
ProductosE lProductos;
int lintSePuedeVender;
	lProductos <<
	new ProductoE((*ProdSeleccionado)["CveProducto"],
		      "",
		      "",
		      "",
		      "",
		      "DEFAULT",
		      SiscomDesarrollo3Qt::InformacionEdit(QLECantidad),
		      "",
		      "",
		      chrPtrArgumentos[0]);
		      

CotizaDispositivosE lCotDispo(SisDatCom,
			     lProductos);

QLCDNExistencia->display((*lProductos.at(0))["Existencia"]);
QLCDNExistenciaBodega->display((*lProductos.at(0))["ExisBodega"]);
QPBAnexar->setEnabled((lintSePuedeVender=!strcmp(lProductos.at(0)->SRegistrosPro2["SePuedeVender"],"Si")));
if(!lintSePuedeVender)
SiscomDesarrollo3Qt::FocoAControl(QLECantidad);
else
SiscomDesarrollo3Qt::FocoAControl(QPBAnexar);
}
