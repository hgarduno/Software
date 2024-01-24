#include <IMP_CtrExpendios.h>
#include <IMP_RegistraExpendios.h>
#include <IMP_Compras.h>
#include <IMP_Ventas.h>
#include <IMP_VentasExpendio.h>
#include <IMP_VentasFechaCorte.h>

#include <Empresas.h>
#include <CorteExistencia.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QCtrExpendios *InstanciaCtrExpendios(void *pCSisDatCom,
				      void *pQWParent,
				      const char *pchrPtrName,
				      int pintWFlags)
{
	return new QCtrExpendios((CSISCOMDatComunicaciones *)pCSisDatCom,
				 (QWidget *)pQWParent,
				 pchrPtrName,
				 pintWFlags);
}
QCtrExpendios::QCtrExpendios(CSISCOMDatComunicaciones *pCSisDatCom,
				QWidget* parent, 
				const char* name,
				WFlags fl )
    : CtrExpendios( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
	QWParent(parent),
	QSiscomSeguridad3((QCtrExpendios *)this,
			  pCSisDatCom,
			  getenv("Aplicacion"),
			  pCSisDatCom->ObtenUsuario(),
			  ""),
	E_Matriz(0),
	E_Expendio(0)
{
	SisDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),CSisDatCom->ObtenDirIpSvr());
	ConectaSlots();
	ConsultaMatriz();
	ConsultaExpendios();
}

QCtrExpendios::~QCtrExpendios()
{
}
void QCtrExpendios::ConsultaMatriz()
{
CQEmpresas lCQERegreso;
//Empresa *lE_Matriz;
CQCtrEmpresas lCQCMatriz(CSisDatCom,
			 QStringList() <<
			 QString("ConsultaEmpresas") <<
			 "Matriz",
			 &lCQERegreso);
E_Matriz=lCQERegreso.at(0);
	QPBMMatriz->setEnabled(!E_Matriz);
}
void QCtrExpendios::ConectaSlots()
{

	connect(QPBRExpendio,
		SIGNAL(clicked()),
		SLOT(S_RegistraExpendio()));
	connect(QPBRCompra,
		SIGNAL(clicked()),
		SLOT(S_RegistraCompraDelExpendio()));
	connect(QIVExpendios,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
	connect(QPBRealizaVentas,
		SIGNAL(clicked()),
		SLOT(S_IniciaVentasExpendio()));
	connect(QPBMMatriz,
		SIGNAL(clicked()),
		SLOT(S_MarcaMatriz()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(S_Actualizar()));
	connect(QPBVentasExpendio,
		SIGNAL(clicked()),
		SLOT(S_VentasExpendio()));
	connect(QPBFFechaCorte,
		SIGNAL(clicked()),
		SLOT(S_FijaFechaCorte()));
	connect(QPBVentasFechaCorte,
		SIGNAL(clicked()),
		SLOT(S_VentasFechaCorte()));


}
void QCtrExpendios::S_VentasFechaCorte()
{
QVentasFechaCorte *lQVenFechaCorte=new QVentasFechaCorte(CSisDatCom,
						         E_Expendio,
							 QWParent);

}
void QCtrExpendios::S_FijaFechaCorte()
{
if(ValidaSeleccionExpendio())
{
OpCorteExistencia lOpCExistencia(SisDatCom);
		lOpCExistencia.FijaFechaCorte(E_Expendio->ObtenIdEmpresa());
}
}
int QCtrExpendios::ValidaSeleccionExpendio()
{
	if(E_Expendio)
	 return 1;
	else
	{
	QMessageBox::information(this,
				 "Aviso",
				 "Se debe seleccionar un Expendio");	
	 return 0;
	}
}
void QCtrExpendios::S_VentasExpendio()
{

if(ValidaSeleccionExpendio())
QVentasExpendio *lQVExpendio=new QVentasExpendio(CSisDatCom,
						 E_Expendio,
					         QWParent,
						 "lQVExpendio");
}
void QCtrExpendios::S_Actualizar()
{
	QIVExpendios->clear();
	CQ_Empresas.clear();
	ConsultaExpendios();

}
void QCtrExpendios::S_MarcaMatriz()
{
CQEmpresas lCQRegreso;
	
	if(E_Expendio)
	CQCtrEmpresas lCQCRMatriz(CSisDatCom,
				  QStringList() <<
				  "RegistraMatriz" <<
				  E_Expendio->ObtenIdEmpresa(),
				  &lCQRegreso);
	 
}
void QCtrExpendios::S_IniciaVentasExpendio()
{
if(ValidaSeleccionExpendio())
{
QVentas *lQVentas=new QVentas(CSisDatCom,QWParent,"lQVentas",0);
	lQVentas->PonExpendio(E_Expendio);
	lQVentas->show();
}
}
void QCtrExpendios::S_SeleccionoExpendio(QIconViewItem *pQIVIExpendio)
{
	if(pQIVIExpendio)
	{
	E_Expendio=((QIconViewItemExpendio *)pQIVIExpendio)->ObtenEmpresa();
	QPBRealizaVentas->setEnabled(E_Matriz &&strcmp(E_Expendio->ObtenRazonSocial() ,
					    E_Matriz->ObtenRazonSocial()));
	}

}
void QCtrExpendios::S_RegistraCompraDelExpendio()
{
if(ValidaSeleccionExpendio())
{
QCompras *lQCompras=new QCompras(CSisDatCom,
				 QWParent);
		lQCompras->PonExpendio(E_Expendio);
		lQCompras->show();
}
}
void QCtrExpendios::S_RegistraExpendio()
{
	QRExpendios=new QRegistraExpendios(CSisDatCom,
					   QWParent);
	QRExpendios->PonEsExpendio("1");
	connect(QRExpendios,
		SIGNAL(Signal_EjecutoRegistro()),
		SLOT(S_RegistroElExpendio()));

	QRExpendios->show();
					  
					
}
void QCtrExpendios::S_RegistroElExpendio()
{
	delete QRExpendios;
}
void QCtrExpendios::ConsultaExpendios()
{
CQCtrEmpresas lCQCEmpresas(CSisDatCom,
			   QStringList() <<
			    QString("ConsultaEmpresas") <<
			    "Expendios",
			    &CQ_Empresas);
Empresa *lE_Empresa;
QIconViewItemExpendio *lQIVExpendio;
	for(lE_Empresa=CQ_Empresas.first();
	    lE_Empresa;
	    lE_Empresa=CQ_Empresas.next())
	{
	  lQIVExpendio=new QIconViewItemExpendio(lE_Empresa,QIVExpendios);
/*
	  lQIVExpendio->setSelectable(E_Matriz && strcmp(lE_Empresa->ObtenRazonSocial(),
					      E_Matriz->ObtenRazonSocial()));
*/
	  QIVExpendios->insertItem(lQIVExpendio);
	}
}
QIconViewItemExpendio::QIconViewItemExpendio(Empresa *pEmpresa,
					     QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		E_Empresa(pEmpresa)
{

	MuestraDatosGenerales();

}
void QIconViewItemExpendio::MuestraDatosGenerales()
{
	setText(E_Empresa->ObtenRazonSocial());

}
Empresa *QIconViewItemExpendio::ObtenEmpresa()
{
	return E_Empresa;
}
