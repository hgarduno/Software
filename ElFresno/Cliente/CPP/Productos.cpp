#include <Productos.h>
#include <CQSiscomCom.h>
#include <qlineedit.h>
#include <qcombobox.h>

Producto::Producto(const char *pchrPtrClave,
		   const char *pchrPtrDescripcion):
		chrPtrClave(pchrPtrClave),
		chrPtrDescripcion(pchrPtrDescripcion),
		chrPtrEdoRegistro("0"),
		F_Producto(0)
{


}

void Producto::PonClave(const char *pchrPtrClave)
{
	chrPtrClave=pchrPtrClave;
}
void Producto::PonDescripcion(const char *pchrPtrDescripcion)
{
	chrPtrDescripcion=pchrPtrDescripcion;
}
void Producto::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
void Producto::PonFamilia(Familia *pF_Producto)
{
	F_Producto=pF_Producto;
}
void Producto::PonUnidad(Unidad *pU_Producto)
{
	U_Producto=pU_Producto;
}
void Producto::PonPrecio(int pintNumPrecio,
			  Precio *pPPrecio)
{
	if(!CQ_Precios.count())
	 CQ_Precios.append(pPPrecio);
	else
	{
	   PonPrecio(pintNumPrecio,
		     pPPrecio->ObtenPrecio());  
	}

}
void Producto::PonPrecio(int pintNumPrecio,
			 const char *pchrPtrPrecio)
{
Precio *lPPrecio=CQ_Precios.at(pintNumPrecio);

	if(lPPrecio)
	lPPrecio->PonPrecio(pchrPtrPrecio);
	else
	{
	  printf("Producto::PonPrecio:{No Se Han Iniciado Los Precios}\n");
	}
}
void Producto::AnexaPrecios(const CQPrecios &pCQPrecios)
{
	CQ_Precios=pCQPrecios;
}
void Producto::AnexaPrecio(int pintNPrecio,
			   Precio *pPrecio)
{
}
void Producto::AnexaPrecio(Precio *pPrecio)
{
	CQ_Precios.append(pPrecio);
}
const CQPrecios &Producto::ObtenPrecios()
{
	return CQ_Precios;
}
const char *Producto::ObtenClave()
{
	return chrPtrClave;
}

const char *Producto::ObtenDescripcion()
{
	return chrPtrDescripcion;
}

const char *Producto::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}

Unidad *Producto::ObtenUnidad()
{
	return U_Producto;
}
Familia *Producto::ObtenFamilia()
{
	return F_Producto;
}
CQProductos::CQProductos()
{

}
CQCtrProductos::CQCtrProductos(CSISCOMDatComunicaciones *pCSisDatCom,
			       CQCtrProductos::CtrProductos  pCQCOperacion,
			       CQProductos *pCQProductos,
			       const char *pchrPtrFamilia):
		CSisDatCom(pCSisDatCom),
		intNumParametros(6),
		chrPtrFormato("%s%s%s%s%s%s"),
		chrPtrFamilia(pchrPtrFamilia)
{
	switch(pCQCOperacion)
	{
	  case CQCtrProductos::Registrar:
		   RegistrarProductos(pCQProductos);
	  break;
	  case CQCtrProductos::ConsultarClavesYDescripciones:
		 ConsultaLasClavesYDescripciones(pCQProductos);
		 AsignaRespuestaProductos(pCQProductos);
	  break;
	}
}
CQCtrProductos::CQCtrProductos(CSISCOMDatComunicaciones *pCSisDatCom,
			       CQCtrProductos::CtrProductos  pCQCOperacion,
			       CQProductos *pCQProductos):
		CSisDatCom(pCSisDatCom),
		intNumParametros(6),
		chrPtrFormato("%s%s%s%s%s%s"),
		chrPtrFamilia(0)
{
	switch(pCQCOperacion)
	{
	  case CQCtrProductos::Registrar:
		   RegistrarProductos(pCQProductos);
	  break;
	  case CQCtrProductos::ConsultarClavesYDescripciones:
		 ConsultaLasClavesYDescripciones(pCQProductos);
		 AsignaRespuestaProductos(pCQProductos);
	  break;
	}
}
void CQCtrProductos::RegistrarProductos(CQProductos *pCQProductos)
{
Producto *lP_Producto;
Unidad *lU_Unidad;
Familia *lF_Familia;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   intNumParametros);
        CQOGSvrSiscom->AnexaRegistro(chrPtrFormato,
                                     "RegistraProductos",
                                     "",
                                     "",
                                     "",
                                     "",
                                     "");
	for(lP_Producto=pCQProductos->first();
	    lP_Producto;
	    lP_Producto=pCQProductos->next())
	{
	   lU_Unidad=lP_Producto->ObtenUnidad();
	   lF_Familia=lP_Producto->ObtenFamilia();
	   CQOGSvrSiscom->AnexaRegistro(chrPtrFormato,
					"",	
					lP_Producto->ObtenClave(),
					lP_Producto->ObtenDescripcion(),
					lU_Unidad->ObtenUnidad(),
					lF_Familia->ObtenIdFamilia(),
					lP_Producto->ObtenEdoRegistro());
						
	}
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrProductos::ConsultaLasClavesYDescripciones(CQProductos *pCQProductos)
{
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   2);
        CQOGSvrSiscom->AnexaRegistro("%s%s",
                                     "ConsultaClavesYDescripciones",
                                     "");
	if(chrPtrFamilia)
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "",
				     chrPtrFamilia);
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}

void CQCtrProductos::AsignaRespuestaProductos(CQProductos *pCQProductos)
{
Producto *lP_Producto;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==8)
	{
	 lP_Producto=new Producto((const char *)QSLRegistro[2],
				  (const char *)QSLRegistro[3]);
	 lP_Producto->PonUnidad(new Unidad((const char *)QSLRegistro[1],
					   (const char *)QSLRegistro[4],
					   (const char *)QSLRegistro[5]));
	 lP_Producto->PonFamilia(new Familia((const char *)QSLRegistro[0],
					     (const char *)QSLRegistro[6],
					     (const char *)QSLRegistro[7]));
	  pCQProductos->append(lP_Producto);
	}
}

CQSeleccionaProducto::CQSeleccionaProducto(CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   QLineEdit *pQLECProductos,
					   QLineEdit *pQLEDescripcion,
					   QLineEdit *pQLEAbreviatura,
					   QComboBox *pQCBProductos):
				QObject(pQWParent,pchrPtrName),
				CSisDatCom(pCSisDatCom),
				QLECProductos(pQLECProductos),
				QLEDescripcion(pQLEDescripcion),
				QLEAbreviatura(pQLEAbreviatura),
				QCBProductos(pQCBProductos)
{
	LlenaComboProductos();
	ConectaSlots();
}
CQSeleccionaProducto::CQSeleccionaProducto(CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   QLineEdit *pQLECProductos,
					   QLineEdit *pQLEDescripcion,
					   QLineEdit *pQLEAbreviatura,
					   QComboBox *pQCBProductos,
					   const char *pchrPtrFamilia):
				QObject(pQWParent,pchrPtrName),
				CSisDatCom(pCSisDatCom),
				QLECProductos(pQLECProductos),
				QLEDescripcion(pQLEDescripcion),
				QLEAbreviatura(pQLEAbreviatura),
				QCBProductos(pQCBProductos)
{
	LlenaComboProductos(pchrPtrFamilia);
	ConectaSlots();
}
void CQSeleccionaProducto::ConectaSlots()
{
	connect(QCBProductos,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoProducto(int)));
	connect(QCBProductos,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoProducto(int)));
	connect(QLECProductos,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoProducto()));
}
void CQSeleccionaProducto::S_SeleccionoProducto(int pintNProducto)
{
	MuestraInformacion(pintNProducto);
	emit Signal_SProducto(CQ_Productos.at(pintNProducto));	
}
void CQSeleccionaProducto::S_SeleccionoProducto()
{
	MuestraInformacion(QCBProductos->currentItem());
	emit Signal_SProducto(CQ_Productos.at(QCBProductos->currentItem()));	
}
void CQSeleccionaProducto::MuestraInformacion(int pintNProducto)
{
Unidad *lU_Unidad=CQ_Productos.at(pintNProducto)->ObtenUnidad();
	QLEDescripcion->setText(CQ_Productos.at(pintNProducto)->ObtenDescripcion());
	QLEAbreviatura->setText(lU_Unidad->ObtenAbreviatura());


}
void CQSeleccionaProducto::S_SeleccionandoProducto(int pintNProducto)
{
	MuestraInformacion(pintNProducto);
}
void CQSeleccionaProducto::LlenaComboProductos()
{
Producto *lP_Producto;
CQCtrProductos lCQCProductos(CSisDatCom,
			     CQCtrProductos::ConsultarClavesYDescripciones,
			     &CQ_Productos);
	for(lP_Producto=CQ_Productos.first();
	    lP_Producto;
	    lP_Producto=CQ_Productos.next())
	QCBProductos->insertItem(lP_Producto->ObtenClave());
	
}
void CQSeleccionaProducto::LlenaComboProductos(const char *pchrPtrFamilia)
{
Producto *lP_Producto;
CQCtrProductos lCQCProductos(CSisDatCom,
			     CQCtrProductos::ConsultarClavesYDescripciones,
			     &CQ_Productos,
			     pchrPtrFamilia);
	for(lP_Producto=CQ_Productos.first();
	    lP_Producto;
	    lP_Producto=CQ_Productos.next())
	QCBProductos->insertItem(lP_Producto->ObtenClave());
	
}
