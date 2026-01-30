#include <QtManejadorOrden.h>
#include <IMP_SeleccionaOrden.h>
#include <IMP_ManejadorOrden.h>
#include <IMP_FormaPago.h>
#include <IMP_ComoPago.h>

#include <zConexionExpendio.h>


#include <zExistenciaExpendio.h>

#include <qtextedit.h>
QtManejadorOrden::QtManejadorOrden(ManejadorOrden *pManOrden,
				   QManejadorOrden *pQManOrden):
				   ManOrden(pManOrden),
				   QManOrden(pQManOrden)
{

}

int QtManejadorOrden::SeleccionandoOrden()
{
  return SeleccionaOrden();
}

int QtManejadorOrden::SeleccionaOrden()
{
QSeleccionaOrden lQSelOrden(QManOrden->Orden()->Expendio(),QManOrden->Parent());
lQSelOrden.exec();
if(lQSelOrden.Aceptar())
{
lQSelOrden.Orden()->Expendio(QManOrden->Orden()->Expendio());
zOrdVenta=lQSelOrden.Orden();
return 1;
}
else
return 0;

}

void QtManejadorOrden::ComoSePaga()
{
  FormaPago();
}

void QtManejadorOrden::FormaPago()
{


}

zOrdenVenta *QtManejadorOrden::Orden()
{
  return zOrdVenta;
}
void QtManejadorOrden::ExistenciaExpendios(zExistenciaExpendios *pzExisExpendios)
{
    zExisExpendios=pzExisExpendios;
}
zExistenciaExpendios *QtManejadorOrden::EsEx()
{
   return zExisExpendios;
}
void QtManejadorOrden::MuestraExistenciaExpendio(zExistenciaExpendio *pzExExpendio)
{
QString lQSFila;
zSiscomRegistros *lzSisRegsExpendios=pzExExpendio->AsociadosDelCampo("Expendio");
zSiscomRegistro *lzSisRegExpendio; 
QString lQSTabla("<table >\n\
  <caption>Mi Primera Tabla</caption>\n\
  <thead>\n\
    <tr>\n\
      <th>Expendio</th>\n\
      <th>Existencia</th>\n\
      <th>Precio</th>\n\
      <th>Bodega</th>\n\
      <th>Existencia Bodega</th>\n\
    </tr>\n\
  </thead>\n\
  <tbody>");

for(lzSisRegExpendio=lzSisRegsExpendios->Primer();
    lzSisRegExpendio;
    lzSisRegExpendio=lzSisRegsExpendios->Siguiente())
{
 LogSiscom("%s\t%s\t%s\t%s\t%s",
 	  (const char *)(*lzSisRegExpendio)["razonsocial"],
 	  (const char *)(*lzSisRegExpendio)["existencia"],
 	  (const char *)(*lzSisRegExpendio)["precio"],
 	  (const char *)(*lzSisRegExpendio)["bodega"],
 	  (const char *)(*lzSisRegExpendio)["existenciab"]);
   lQSFila+="<tr>";

   lQSFila+="<td>";
   lQSFila+=(const char *)(*lzSisRegExpendio)["razonsocial"];
   lQSFila+="</td>";

   lQSFila+="<td>";
   lQSFila+=(const char *)(*lzSisRegExpendio)["existencia"];
   lQSFila+="</td>";

   lQSFila+="<td>";
   lQSFila+=(const char *)(*lzSisRegExpendio)["precio"];
   lQSFila+="</td>";

   lQSFila+="<td>";
   lQSFila+=(const char *)(*lzSisRegExpendio)["bodega"];
   lQSFila+="</td>";

   lQSFila+="<td>";
   lQSFila+=(const char *)(*lzSisRegExpendio)["existenciab"];
   lQSFila+="</td>";

   lQSFila+="</tr>";
   lQSTabla+=lQSFila;
   lQSFila="";
}
lQSFila="";
lQSFila="</tbody> </table>";
lQSTabla+=lQSFila;
TextoCliente()->setText(lQSTabla);
}
void QtManejadorOrden::MuestraExistenciaExpendios()
{
 zExistenciaExpendio *lzExExpendio;
 for(lzExExpendio=(zExistenciaExpendio *)EsEx()->Primer();
     lzExExpendio;
     lzExExpendio=(zExistenciaExpendio *)EsEx()->Siguiente())
 {
   SiscomRegistroLog2(lzExExpendio);
   MuestraExistenciaExpendio(lzExExpendio);
 }
}

QTextEdit *QtManejadorOrden::TextoCliente()
{
    return QTEClienteA;
}
void QtManejadorOrden::TextoCliente(QTextEdit *pQTECliente)
{
	QTEClienteA=pQTECliente;
}
