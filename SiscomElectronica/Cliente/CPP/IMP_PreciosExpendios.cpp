#include <IMP_PreciosExpendios.h>
#include <IMP_SelExpendios.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zSiscomElectronica.h>
#include <zPreciosExpendio.h>
#include <zEmpresa.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
QPreciosExpendios *InstanciaPreciosExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPreciosExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPreciosExpendios::QPreciosExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PreciosExpendios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),

				chrPtrArgumentos(pchrPtrArgumentos),
				intYaSeIniciaron(0)
{
IniciaVariables();
ConectaSlots();
}

QPreciosExpendios::~QPreciosExpendios()
{

}

void QPreciosExpendios::ConectaSlots()
{
connect(QPBExpendioO,SIGNAL(clicked()),SLOT(SlotExpendioO()));
connect(QPBExpendioD,SIGNAL(clicked()),SLOT(SlotExpendioD()));
/*connect(QPBConsultaPrecios,SIGNAL(clicked()),SLOT(SlotConsultaPrecios())); */
connect(QPBConsultaPrecios,SIGNAL(clicked()),SLOT(SlotConsulta2Precios()));
}
void QPreciosExpendios::SlotConsulta2Precios()
{
  if(!intYaSeIniciaron) 
  IniciaExpendios();
  ConsultandoPrecios2();
}
void QPreciosExpendios::SlotConsultaPrecios()
{
ConsultandoPrecios();

}
void QPreciosExpendios::SlotExpendioO()
{
QSelExpendios lQSelExpendios(SisDatCom);
EmpNExpendioO=lQSelExpendios.ObtenExpendio();
QLEExpendioO->setText((*EmpNExpendioO)["RazonSocial"]);
}

void QPreciosExpendios::SlotExpendioD()
{
QSelExpendios lQSelExpendios(SisDatCom);
EmpNExpendioD=lQSelExpendios.ObtenExpendio();
QLEExpendioD->setText((*EmpNExpendioD)["RazonSocial"]);
}
void QPreciosExpendios::IniciaVariables()
{

}
void QPreciosExpendios::ConsultandoPrecios()
{
IniciaPreciosExpendios();
ConsultaPrecios();
MuestraPrecios();
}
void QPreciosExpendios::ConsultaPrecios()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"PreciosExpendios");
lzSisElectronica.PreciosExpendios((*EmpNExpendioO)["IdEmpresa"],
				  (*EmpNExpendioD)["IdEmpresa"],
				  &zPreciosExps);
}
void QPreciosExpendios::MuestraPrecios()
{
QTPreciosE->setNumRows(zPreciosExps.Precios((*EmpNExpendioO)["IdEmpresa"])->Precios()->NNodos());
MuestraPreciosExpendioOrigen();
MuestraPreciosExpendioDestino();


}

zEmpresa *QPreciosExpendios::Expendio(EmpresaN *pEmpresaN)
{

return new zEmpresa((*pEmpresaN)["IdEmpresa"],
		    (*pEmpresaN)["RazonSocial"]);

}
zPreciosExpendio *QPreciosExpendios::Precios(zEmpresa *pzEmpExpendio)
{
 return new zPreciosExpendio(pzEmpExpendio);
}
void QPreciosExpendios::IniciaExpendios()
{
  zEmpExpO=Expendio(EmpNExpendioO);
  zEmpExpD=Expendio(EmpNExpendioD);
  SiscomRegistroLog2(zEmpExpO);
  intYaSeIniciaron=1;
}
void QPreciosExpendios::IniciaPreciosExpendios()
{
    zPreciosExps.AgregaExpendio(Precios(Expendio(EmpNExpendioO)));
    zPreciosExps.AgregaExpendio(Precios(Expendio(EmpNExpendioD)));
}
void QPreciosExpendios::MuestraPreciosExpendioOrigen()
{
   MuestraPreciosExpendio(0,0,zPreciosExps.Precios((*EmpNExpendioO)["IdEmpresa"])->Precios());
}
void QPreciosExpendios::MuestraPreciosExpendioDestino()
{

   MuestraPreciosExpendio(0,2,zPreciosExps.Precios((*EmpNExpendioD)["IdEmpresa"])->Precios());
}
void QPreciosExpendios::MuestraPreciosExpendio(int pintFila,
					       int pintColumna,
					       zSiscomRegistros *pzSisRegsPrecios)
{
zSiscomRegistro *lzSisRegPrecio;
int lintContador=0;
for(lzSisRegPrecio=pzSisRegsPrecios->Primer();
    lzSisRegPrecio;
    lzSisRegPrecio=pzSisRegsPrecios->Siguiente())
{
   QTPreciosE->setText(pintFila,pintColumna,(const char *)(*lzSisRegPrecio)["cveproducto"]);
   QTPreciosE->setText(pintFila,pintColumna+1,(const char *)(*lzSisRegPrecio)["precio"]);
   pintFila++; 
}


}

void QPreciosExpendios::ConsultandoPrecios2()
{
ConsultaPrecios2();
MuestraPrecios2();
}
void QPreciosExpendios::ConsultaPrecios2()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"Precios2Productos");
lzSisElectronica.Precios2Productos(zEmpExpO,zEmpExpD,&zPrecios2Prods);
}
void QPreciosExpendios::MuestraPrecios2()
{

}
