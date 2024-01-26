#include <QtImpBeneficiosIntegrales.h>
#include <QtImpSeleccionaCredito.h>
#include <QtImpCapturaDatosEmpleo.h>
#include <QtImpCapturaDatosComplementarios.h>
#include <QtImpCapturaDireccionParticular.h>
#include <QtImpCapturaDatosGenerales.h>
#include <QtImpPosicionesBeneficios.h>
#include <QtImpCapturaDatosComunicacion.h>
#include <QtImpCapturaGeneralesContratoBeneficios.h>
#include <QtImpVolteaContrato.h>
#include <QtImpCapturaCentroTrabajo.h>
#include <QtImpCreditosBeneficiosIntegrales.h>
#include <zDireccion.h>
#include <zContratoBeneficios.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qtextedit.h>
#include <stdlib.h>
#include <stdio.h>
#include <qlineedit.h>
#include <qmessagebox.h>

QtImpCapturaDireccionParticular *gQtImpCapDirParticular;
QtImpCapturaDatosEmpleo *gQtCapDatEmpleo;
QtImpCapturaDatosGenerales *gQtCapDatGenerales;
QtImpCapturaDatosComplementarios *gQtCapDatComplementarios;
QtImpCapturaDatosComunicacion *gQtCapDatComunicacion;
QtImpCapturaGeneralesContratoBeneficios *gQtCapGenContraBeneficios;
QtImpCapturaCentroTrabajo *gQtCapCentroTrabajo;

QtImpBeneficiosIntegrales::QtImpBeneficiosIntegrales(QWidget *pQWParent,
				     const char *pchrPtrName):
				     BeneficiosIntegrales(pQWParent,pchrPtrName),
				     zConBeneficios(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();

}
void QtImpBeneficiosIntegrales::IniciaVariables()
{
  memset(RegPosiciones,0,sizeof(Registro)*400); 
  Formato();
  chrPtrFormatoDatos=(char *)malloc(strlen(chrPtrFormato)+1024);
  CargandoPosiciones();
}
void QtImpBeneficiosIntegrales::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpBeneficiosIntegrales::ConectaSlots()
{
  connect(QPBSelCredito,
  	  SIGNAL(clicked()),
	  SLOT(SlotSeleccionaCredito()));
  connect(QPBCapDatEmpleo,
  	  SIGNAL(clicked()),
	  SLOT(SlotCapturaDatosEmpleo()));
  connect(QPBCapDirParticular,
  	  SIGNAL(clicked()),
	  SLOT(SlotCapturaDireccionParticular()));
  connect(QPBCapDatComplementarios,
  	  SIGNAL(clicked()),
	  SLOT(SlotCapturaDatosComplementarios()));
  connect(QPBImprimir,
    	 SIGNAL(clicked()),
    	 SLOT(SlotImprimeContrato()));
  connect(QPBImprimeAArchivo,
  	  SIGNAL(clicked()),
	  SLOT(SlotImprimeContratoAArchivo()));
   connect(QPBGeneralesContrato,
   	   SIGNAL(clicked()),
	   SLOT(SlotGeneralesContrato()));
   connect(QPBPosBeneficios,
   	   SIGNAL(clicked()),
	   SLOT(SlotPosicionesBeneficios()));
   connect(QPBGenerales,
   	   SIGNAL(clicked()),
	   SLOT(SlotCapturaDatosGenerales()));
   connect(QPBComunicacion,
   	   SIGNAL(clicked()),
	   SLOT(SlotCapturaDatosComunicacion()));
   connect(QPBImprimeFrente,
   	    SIGNAL(clicked()),
	    SLOT(SlotImprimeFrente()));
   connect(QPBImprimeAtras,
   	    SIGNAL(clicked()),
	    SLOT(SlotImprimeAtras()));
   connect(QPBCapDatCentroTrabajo,
   	   SIGNAL(clicked()),
	   SLOT(SlotCentroTrabajo()));
  connect(QPBCreditos,
  	  SIGNAL(clicked()),
	  SLOT(SlotCreditosBeneficiosIntegrales()));
}
void QtImpBeneficiosIntegrales::SlotCreditosBeneficiosIntegrales()
{
QtImpCreditosBeneficiosIntegrales lQtImpCredsBensIntegrales;
if(lQtImpCredsBensIntegrales.Aceptar())
{
	
}
}
void QtImpBeneficiosIntegrales::SlotCentroTrabajo()
{
  if(zConBeneficios)
  {
  gQtCapCentroTrabajo=new QtImpCapturaCentroTrabajo(zConBeneficios); 
  if(gQtCapCentroTrabajo->Aceptar())
   MuestraDatos(); 
  }
  else
  QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::SlotImprimeFrente()
{
QtImprimeBeneficiosIntegrales impresion;
    impresion.MargenArriba(QLEArriba->text().toInt());
    impresion.MargenIzquierda(QLEIzquierda->text().toInt());
    impresion.MargenAbajo(QLEAbajo->text().toInt());
    impresion.MargenDerecha(QLEDerecha->text().toInt());
    impresion.Inicia();
    impresion.AsignaPosiciones(RegPosiciones);
    impresion.ImprimeFrente( zConBeneficios );

}
void QtImpBeneficiosIntegrales::SlotImprimeAtras()
{
QtImprimeBeneficiosIntegrales impresion;
    impresion.MargenArriba(QLEArriba->text().toInt());
    impresion.MargenIzquierda(QLEIzquierda->text().toInt());
    impresion.MargenAbajo(QLEAbajo->text().toInt());
    impresion.MargenDerecha(QLEDerecha->text().toInt());
    impresion.Inicia();
    impresion.AsignaPosiciones(RegPosiciones);
    impresion.ImprimeAtras( zConBeneficios );


}
void QtImpBeneficiosIntegrales::SlotGeneralesContrato()
{
  if(zConBeneficios)
  {
  gQtCapGenContraBeneficios=new QtImpCapturaGeneralesContratoBeneficios(zConBeneficios); 
  if(gQtCapGenContraBeneficios->Aceptar())
   MuestraDatos(); 
  }
  else
  QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");
}
void QtImpBeneficiosIntegrales::SlotCapturaDatosComunicacion()
{
if(zConBeneficios)
{
gQtCapDatComunicacion=new QtImpCapturaDatosComunicacion(zConBeneficios);
if(gQtCapDatComunicacion->Aceptar())
 MuestraDatos();
}
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");
}
void QtImpBeneficiosIntegrales::SlotImprimeContratoAArchivo()
{
if(zConBeneficios)
ImprimeContratoAArchivo();    
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::SlotCapturaDatosGenerales()
{
if(zConBeneficios)
{
  gQtCapDatGenerales=new QtImpCapturaDatosGenerales(zConBeneficios);
  if(gQtCapDatGenerales->Aceptar())
  MuestraDatos();
}
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::SlotPosicionesBeneficios()
{
   CargandoPosiciones(); 
}
void QtImpBeneficiosIntegrales::SlotCapturaDireccionParticular()
{
if(zConBeneficios)
{
 gQtImpCapDirParticular=new QtImpCapturaDireccionParticular(zConBeneficios);
  if(gQtImpCapDirParticular->Aceptar())
   MuestraDatos();
}
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

   
}
void QtImpBeneficiosIntegrales::SlotCapturaDatosEmpleo()
{
if(zConBeneficios)
{
  gQtCapDatEmpleo=new QtImpCapturaDatosEmpleo(zConBeneficios);
  if(gQtCapDatEmpleo->Aceptar())
   MuestraDatos();
}
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::SlotCapturaDatosComplementarios()
{
if(zConBeneficios)
{
   gQtCapDatComplementarios=new QtImpCapturaDatosComplementarios(zConBeneficios);
   if(gQtCapDatComplementarios->Aceptar())
   MuestraDatos();
}
else
QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::SlotSeleccionaCredito()
{
QtImpSeleccionaCredito *lQtImpSelCredito;
lQtImpSelCredito=new QtImpSeleccionaCredito;
if(lQtImpSelCredito->Aceptar()) 
{
    zConBeneficios=new zContratoBeneficios(lQtImpSelCredito->Cliente());
    zConBeneficios->Credito(lQtImpSelCredito->Credito());
    zConBeneficios->DireccionParticular(lQtImpSelCredito->Direccion());
    CompletaContratoBeneficios();
    MuestraDatos();
}
}
void QtImpBeneficiosIntegrales::SlotImprimeContrato()
{
    //EnviaDatosALogSiscom();
    //EnviaProductosLog();
    if(zConBeneficios)
    imprimeContrato();
    else
    QMessageBox::information(this,"Aviso Sistema","Se debe seleccionar Un Contrato");

}
void QtImpBeneficiosIntegrales::Formato()
{
chrPtrFormato=strdup("\n\
<font size=\"4\" color=\"Black\">\n\
<table cellspacing=\"1\">\n\
<tr align=\"center\" >\n\
	<td colspan=\"8\" >\n\
			<b><h1>Beneficios Integrales BSA, S.A. DE C.V. SOFOM, E.N.R </h1></b>\n\
	</td>\n\
</tr>\n\
<tr align=\"left\" bgcolor=\"lightgray\">\n\
	<td > \n\
		<b>Requisitos</b> \n\
	</td>\n\
	<td colspan=\"9\">\n\
		Lugar y Fecha de Elaboracion \n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td rows=\"3\" colspan=\"1\" bgcolor=\"lightgray\">\n\
		<ul>\n\
		    <small>\n\
			<li><small>1.- Solicitud</small></li>\n\
			<li><small>2.- Identificacion Oficial Vigente</small></li>\n\
			<li><small>3.- Comprobante de domicilio</small></li>\n\
			<li><small>4.- Ultimo recibo de nomina </small></li>\n\
			<li><small>5.- Cedula de identificacion fiscal</small></li>\n\
		   </small>\n\
		</ul>\n\
	</td>\n\
	<td bgcolor=\"lightgray\" rowspan=\"2\" colspan=\"9\">\n\
		 %s a  %s \n\
	</td>\n\
</tr>\n\
\n\
<tr>\n\
	<td colspan=\"5\">\n\
	</td>\n\
<tr>\n\
	       <td colspan=\"5\" bgcolor=\"lightgray\">Importe Solicitado $%s Importe con Letra %s</td> \n\
	       <td colspan=\"2\" bgcolor=\"lightgray\">Pago Quincenal %s</td> \n\
	       <td colspan=\"1\" bgcolor=\"lightgray\" colspan=\"8\">Plazo: %s</td> \n\
</tr>\n\
<tr>\n\
<tr>\n\
	<td colspan=\"9\">\n\
	</td>\n\
<tr>\n\
	<td colspan=\"9\">\n\
		<small>Los 2 primeros meses del palzo contemplan la gestion del descuento por nomina en la empresa, por lo que durante\n\
		este periodo solo se generaran intereses ordinarios\n\
	</td>\n\
</tr>\n\
<tr>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"7\" align=\"center\">\n\
		<b>Datos Generales del Solicitante</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"8\" >\n\
		<small><b>Nombre</b> (Apellido Paterno, Materno y Nombre (s))</b></small>\n\
	</td>\n\
</tr>\n\
\n\
<tr>\n\
	<td colspan=\"8\" >\n\
	 %s %s %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\" >\n\
	<td>\n\
		<b><small>R.F.C. Con Homoclave</small></b>\n\
	</td>\n\
	<td colspan=\"2\">\n\
		<b><small>CURP</small></b>\n\
	</td>\n\
	<td colspan=\"2\">\n\
		<b><small>Entidad Federativa de Nacimiento</small></b>\n\
	</td>\n\
</tr>\n\
<tr >\n\
	<td>\n\
		%s\n\
	</td>\n\
	<td>\n\
		%s	\n\
	</td>\n\
	<td>\n\
	       %s\n\
	</td>\n\
	<td>\n\
		%s \n\
	</td>	\n\
</tr>\n\
\n\
<tr bgcolor=\"lightgray\" >\n\
	<td>\n\
		<b><small>Pais de Nacimiento</small></b>\n\
	</td>\n\
	<td>\n\
		<b><small>Genero</small></b>\n\
	</td>\n\
\n\
	<td>\n\
	 	<b><small>Estado Civil	</small></b>\n\
	</td>\n\
\n\
	<td>\n\
		<b><small>Edad	</small></b>\n\
	</td>\n\
	\n\
	<td colspan=\"4\">\n\
		<b><small>Fecha Nacimiento (Ano-Dia-Mes)</b></small>\n\
	</td>\n\
\n\
</tr>\n\
<tr>\n\
	<td>\n\
		%s\n\
	</td>\n\
	<td>\n\
		%s\n\
	</td>\n\
	<td>\n\
		%s\n\
	</td>\n\
	<td>\n\
		%s\n\
	</td>\n\
	\n\
	<td colspan=\"2\">\n\
		%s\n\
	</td>\n\
    \n\
</tr>\n\
\n\
<tr bgcolor=\"lightgray\">\n\
		<td>\n\
						<small><b>Identificacion</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
						<small><b>No Identificacion</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
			<small><b>Ocupacion</b></small>\n\
		</td>\n\
		<td colspan=\"3\">\n\
			<small><b>Nacionalidad</b></small>\n\
		</td>\n\
</tr>\n\
<tr>\n\
		<td>\n\
			%s\n\
		</td>\n\
		<td colspan=\"2\">\n\
			%s\n\
		</td>\n\
		<td colspan=\"2\">\n\
			%s\n\
		</td>\n\
		<td colspan=\"3\">\n\
			%s\n\
		</td>\n\
	\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Domicilio Particular</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"2\">\n\
						<small><b>Calle</b><small> \n\
					</td>\n\
					<td>\n\
						<small><b>No. Ext</b><small>\n\
					</td>\n\
					<td colspan=\"1\">\n\
						<small><b>No. Int</b><small>\n\
					</td>\n\
					<td colspan=\"2\">\n\
						<small><b>Colonia</b><small>\n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Codigo Posta</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
				 	<td colspan=\"2\">\n\
					%s                     \n\
					</td>\n\
					<td>\n\
						%s\n\
					</td>\n\
					<td colspan=\"1\">\n\
					%s\n\
					</td>\n\
					<td colspan=\"2\">\n\
						%s\n\
					</td>\n\
					<td colspan=\"3\">\n\
						%s\n\
					</td>\n\
\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
		<td colspan=\"1\">\n\
			<small><b>Delegacion Municipio</b></small>\n\
		</td>\n\
		<td colspan=\"3\">\n\
	        		<small><b>Ciudad o Poblacion</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
		<small><b>Entidad Federativa</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
			<small><b>Pais</b></small>\n\
		</td>\n\
</tr>\n\
<tr>\n\
		<td colspan=\"1\">\n\
			%s\n\
		</td>\n\
		<td colspan=\"3\">\n\
			%s\n\
		</td>\n\
		<td colspan=\"2\">\n\
			%s\n\
		</td>\n\
		<td colspan=\"2\">\n\
			%s\n\
		</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
		<td  rowspan=\"1\" colspan=\"4\">\n\
			 <small> <b> Tipo Vivienda  </b><small>\n\
		</td>\n\
			\n\
			<th rowspan=\"1\" colspan=\"4\">\n\
			 <small><b> \n\
			 	Telefono Particular Con Lada \n\
			</b></small>\n\
		</th>\n\
</tr>\n\
<tr>\n\
	<td><small><b>Propia      %s</b></small></td>			\n\
	<td><small><b>Rentada  %s</b></small></td>			\n\
	<td></td>					\n\
	<td></td>					\n\
	<td><small><b> %s </b></small> </td>		\n\
</tr>\n\
<tr>\n\
	<td><small><b>Hipotecada %s</b></small></td>	\n\
	<td><small><b>Familiar %s</b></small></td>	\n\
	<td><small><b>Otro %s</b></small></td>	\n\
</tr>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
		<td colspan=\"1\">\n\
			<small><b>Tiempo de residir</b></small>\n\
		</td>\n\
		<td>\n\
			<small><b>Telefono Celular</b></small>\n\
		</td>\n\
		<td colspan=\"3\">\n\
			<small><b>Correo Electronico</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
			<small><b>Telefono Para dejar recado</b></small>\n\
		</td>\n\
</tr>\n\
<tr>\n\
		<td colspan=\"1\">\n\
			<small><b>%s</b></small>\n\
		</td>\n\
		<td>\n\
			<small><b>%s</b></small>\n\
		</td>\n\
		<td colspan=\"3\">\n\
			<small><b>%s</b></small>\n\
		</td>\n\
		<td colspan=\"2\">\n\
			<small><b>%s</b></small>\n\
		</td>\n\
</tr>\n\
\n\
\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Datos del Empleo Actual</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"4\">\n\
						<small><b>Nombre de la Empresa</b><small> \n\
					</td>\n\
					<td colspan=\"2\">\n\
						<small><b>Antiguedad</b><small>\n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Puesto Actual</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"4\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"2\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"5\">\n\
						<small><b>Actividad o Giro de la Empresa</b><small> \n\
					</td>\n\
					<td colspan=\"4\">\n\
						<small><b>Nombre del Jefe Directo</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"5\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"4\" >\n\
	 %s %s %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Domicilio del Empleo Actual</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"3\">\n\
						<small><b>Calle y Numero Ext/Int</b><small> \n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Colonia</b><small>\n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Codigo Postal</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"3\">\n\
						<small><b>Delegacion o Municipio</b><small> \n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Ciudad o Poblacion</b><small>\n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Entidad Federativa (Estado)</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"3\">\n\
						<small><b>Pais</b><small> \n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Telefono Extension</b><small>\n\
					</td>\n\
					<td colspan=\"3\">\n\
						<small><b>Correo Electronico</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s Extension %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Para ser Llenado por la Empresa</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Importe del Credito Autorizado</b>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"9\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"7\" align=\"center\" >\n\
		<b>Periodo Para el Computo de Intereses</b>\n\
	</td>\n\
	<td colspan=\"2\" align=\"center\" >\n\
		<b>Plazo</b>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"7\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"2\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Ingresos Mensuales</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"3\">\n\
						<small><b>Sueldo</b><small> \n\
					</td>\n\
					<td colspan=\"6\">\n\
						<small><b>Frecuencia de Pago Indicada en su recibo de Nomina</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"6\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
				 	<td colspan=\"2\">\n\
						<small><b>Otros Ingresos</b><small> \n\
					</td>\n\
					<td colspan=\"5\">\n\
						<small><b>Especifique Fuente de Otros Ingresos</b><small>\n\
					</td>\n\
					<td colspan=\"2\">\n\
						<small><b>Total de Ingresos</b><small>\n\
					</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"2\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"5\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"2\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<b>Datos Complementarios</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<small><b>Productos y/o Servicios</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"9\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>Origen de los Recursos a Operar</b><small>\n\
	</td>\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>Destino de los Recursos a Operar</b><small>\n\
	</td>\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>Monto de Operación (estimado mensual)</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>Numero de Operaciones (Estimado Mensual)</b><small>\n\
	</td>\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>Frecuencia transaccional (estimado mensual)</b><small>\n\
	</td>\n\
	<td colspan=\"3\" align=\"center\" >\n\
		<small><b>¿Realizará pagos en efectivo? </b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"3\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<small><b>En caso de utilizar dinero en efectivo, especificar los motivos y monto estimado mensual</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"9\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<small><b>¿Desempeña actualmente o desempeño durante el año inmediato anterior algun cargo publico destacado a nivel deferal,estatal,municipal o distrital en Mexico o en algun pais extranjero?</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"9\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
		<small><b>En caso positivo especifique</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"9\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"5\" align=\"center\" >\n\
		<small><b>Dependencia:</b><small>\n\
	</td>\n\
	<td colspan=\"4\" align=\"center\" >\n\
		<small><b>Puesto:</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"5\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"4\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"5\" align=\"center\" >\n\
		<small><b>Principales Funciones:</b><small>\n\
	</td>\n\
	<td colspan=\"4\" align=\"center\" >\n\
		<small><b>Periodo de Ejercicio:</b><small>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"5\" >\n\
	 %s\n\
	</td>\n\
	<td colspan=\"4\" >\n\
	 %s\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
	 <b>Referencias Personales (De Dos Familiares y de Uno No Familiar) </b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"3\" align=\"center\" >\n\
	 <b>Nombre Completo</b>\n\
	</td>\n\
	<td colspan=\"5\" align=\"center\" >\n\
	 <b>Domicilio</b>\n\
	</td>\n\
	<td colspan=\"1\" align=\"center\" >\n\
	 <b>Telefono con lada</b>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"5\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"1\">\n\
	 <b>%s</b>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"5\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"1\">\n\
	 <b>%s</b>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"5\">\n\
	 <b>%s</b>\n\
	</td>\n\
	<td colspan=\"1\">\n\
	 <b>%s</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"9\" align=\"center\" >\n\
	 <b>Este formato sera evidencia de la entrevista personal a que se refiere</b>\n\
	</td>\n\
</tr>\n\
<tr bgcolor=\"lightgray\">\n\
	<td colspan=\"2\" align=\"center\" > \n\
	<b> Centro de Trabajo </b>\n\
	</td>\n\
	<td colspan=\"2\" align=\"center\"> \n\
	<b> Clave Presupuestasl </b> \n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"2\">%s</td>\n\
	<td colspan=\"2\">%s</td>\n\
</tr>\n\
</table>\n\
</font>");
QTEFormato->setText(chrPtrFormato);
}
void QtImpBeneficiosIntegrales::MuestraDatos()
{
sprintf(chrPtrFormatoDatos,
	chrPtrFormato,
	zConBeneficios->Lugar(),
	zConBeneficios->Fecha(),
	zConBeneficios->Importe(),
	zConBeneficios->ImporteLetra(),
	zConBeneficios->PagoQuincenal(),
	zConBeneficios->Plazo(),
	zConBeneficios->APaterno(),
	zConBeneficios->AMaterno(),
	zConBeneficios->Nombre(),
	zConBeneficios->RFC(),
	zConBeneficios->CURP(),
	//(const char *)"-Otra Cosa-",
	"",
	zConBeneficios->EstadoNacimiento(),
	zConBeneficios->PaisNacimiento(),
	zConBeneficios->Genero(),
	zConBeneficios->EstadoCivil(),
	zConBeneficios->Edad(),
	zConBeneficios->FechaNacimiento(),
	zConBeneficios->Identificacion(),
	zConBeneficios->NoIdentificacion(),
	zConBeneficios->Ocupacion(),
	zConBeneficios->Nacionalidad(),
	zConBeneficios->Calle(),
	zConBeneficios->NumExterior(),
	zConBeneficios->NumInterior(),
	zConBeneficios->Colonia(),
	zConBeneficios->CodigoPostal(),
	zConBeneficios->Delegacion(),
	(const char *)"-Ciudad o Poblacion-",
	zConBeneficios->Estado(),
	zConBeneficios->PaisNacimiento(),
	zConBeneficios->TipoViviendaPropia(),
	zConBeneficios->TipoViviendaRentada(),
	zConBeneficios->TelefonoParticular(),
	zConBeneficios->TipoViviendaHipotecada(),
	zConBeneficios->TipoViviendaFamiliar(),
	(const char *)"[Explique otro]",
	zConBeneficios->TiempoResidir(),
	zConBeneficios->TelefonoCelular(),
	zConBeneficios->CorreoElectronico(),
	zConBeneficios->TelefonoRecados(),
	zConBeneficios->Empresa(),
	zConBeneficios->Antiguedad(),
	zConBeneficios->Puesto(),
	zConBeneficios->Giro(),
	zConBeneficios->NombreJefe(),
	zConBeneficios->APaternoJefe(),
	zConBeneficios->AMaternoJefe(),
	zConBeneficios->CalleEmpleo(),
	FormaNumeroDireccion(),
	zConBeneficios->ColoniaEmpleo(),
	zConBeneficios->CodigoPostalEmpleo(),
	zConBeneficios->DelegacionEmpleo(),
	zConBeneficios->DelegacionEmpleo(),
	zConBeneficios->EstadoEmpleo(),
	(const char *)"Mexico",
	zConBeneficios->TelefonoEmpleo(),
	zConBeneficios->ExtensionEmpleo(),
	zConBeneficios->CorreoEmpleo(),
	(const char *)"Importe del Credito Autorizado",
	(const char *)"Periodo para el computo de intereses",
	(const char *)"Plazo",
	zConBeneficios->Sueldo(),
	zConBeneficios->FrecuenciaPago(),
	zConBeneficios->OtrosIngresosMonto(),
	zConBeneficios->OtrosIngresosDescripcion(),
	/*
	(const char *)"Total Ingresos",
	*/
	zConBeneficios->TotalIngresos(),
	(const char *)"Productos y o Servicios",
	(const char *)"Origen de los recursos a Operar",
	(const char *)"Destino de los recursos a Operar",
	(const char *)"Monto de la Operacion",
	(const char *)"Numero de Operacones ",
	(const char *)"Frecuencia Transaccional",
	(const char *)"Se realizaran Pagos en Efectivo",
	(const char *)"Especificacion dinero en Efectivo",
	(const char *)"Desempeño de cargo si o no",
	(const char *)"En caso positivo especificar",
	(const char *)"Dependencia",
	(const char *)"Puesto",
	(const char *)"Principales Funciones",
	(const char *)"Periodo de Ejercicio",
	zConBeneficios->NombreReferencia(0),
	zConBeneficios->DomicilioReferencia(0),
	zConBeneficios->TelefonoReferencia(0),
	zConBeneficios->NombreReferencia(1),
	zConBeneficios->DomicilioReferencia(1),
	zConBeneficios->TelefonoReferencia(1),
	zConBeneficios->NombreReferencia(2),
	zConBeneficios->DomicilioReferencia(2),
	zConBeneficios->TelefonoReferencia(2),
	zConBeneficios->CentroTrabajo2(),
	zConBeneficios->ClavePresupuestal());
QTEFormato->setText(chrPtrFormatoDatos); 
}

const char *QtImpBeneficiosIntegrales::Direccion(const char *pchrPtrCampo,
						      zDireccion *pzDireccion)
{
   return pzDireccion ? (const char *)(*pzDireccion)[pchrPtrCampo] : (const char *)"";
}

void QtImpBeneficiosIntegrales::imprimeContrato()
{
QtImprimeBeneficiosIntegrales impresion;
QtImpVolteaContrato *lQtImpVolteaContrato=new QtImpVolteaContrato(&impresion,zConBeneficios);
    impresion.MargenArriba(QLEArriba->text().toInt());
    impresion.MargenIzquierda(QLEIzquierda->text().toInt());
    impresion.MargenAbajo(QLEAbajo->text().toInt());
    impresion.MargenDerecha(QLEDerecha->text().toInt());
    impresion.Inicia();
    impresion.AsignaPosiciones(RegPosiciones);
    impresion.imprimir( zConBeneficios );
    lQtImpVolteaContrato->Ejecuta();
    impresion.imprimir( zConBeneficios );
}

void QtImpBeneficiosIntegrales::ImprimeContratoAArchivo()
{
    QtImprimeBeneficiosIntegrales impresion;
    impresion.MargenArriba(QLEArriba->text().toInt());
    impresion.MargenIzquierda(QLEIzquierda->text().toInt());
    impresion.MargenAbajo(QLEAbajo->text().toInt());
    impresion.MargenDerecha(QLEDerecha->text().toInt());
    impresion.Inicia();
    impresion.AsignaPosiciones(RegPosiciones);
    impresion.ImprimeAArchivo("ServiSNTEFrente.ps", zConBeneficios );
    impresion.ImprimeAArchivo("ServiSNTEAtras.ps", zConBeneficios );
}
void QtImpBeneficiosIntegrales::MuestraPosiciones()
{
int lintContador=0;
Registro *lRegDatos=RegPosiciones;
LogSiscom("Iniciando");
while(lRegDatos->valor)
{
    LogSiscom("%d.- %s (%d,%d)",
    		lintContador,
		lRegDatos->valor,
		lRegDatos->x,
		lRegDatos->y);
   lRegDatos++;
   lintContador++;

}
LogSiscom("Terminando");
}
void QtImpBeneficiosIntegrales::CargaPosicionesArchivo()
{
FILE *lFlePtrArchivo;
char lchrArrArchivo[256];
char lchrArrLinea[256];
char **lchrPtrDatos;
Registro *lRegPosiciones=RegPosiciones;
sprintf(lchrArrArchivo,"%s/ServiSNTE.Beneficios.Integrales",getenv("HOME"));

if((lFlePtrArchivo=fopen(lchrArrArchivo,"r")))
{
   while(!zSiscomDesarrollo4::LeeLinea(lFlePtrArchivo,lchrArrLinea))
   {
	if(LineaValida(lchrArrLinea))
	{
	 //LogSiscom("%s",lchrArrLinea);
	 if(EsFinContrato(lchrArrLinea,lRegPosiciones))
	 {

	 }
	 else
	 if(!FinPagina(lchrArrLinea,lRegPosiciones))
	 {
	 zSiscomDesarrollo4::CadenasPorSeparador(lchrArrLinea,',',&lchrPtrDatos);
	 lRegPosiciones->x=atoi(*(lchrPtrDatos+0));
	 lRegPosiciones->y=atoi(*(lchrPtrDatos+1));
	 lRegPosiciones->valor=strdup(*(lchrPtrDatos+2));
	 zSiscomDesarrollo4::LiberaCadenas(lchrPtrDatos);
	 }
	 lRegPosiciones++;
	}
   }
fclose(lFlePtrArchivo);
}
else
LogSiscom("El Archivo %s No existe",lchrArrArchivo);
}
int QtImpBeneficiosIntegrales::FinPagina(const char *pchrPtrLinea,Registro *pRegistro)
{
	if(!strcmp(pchrPtrLinea,"FinPagina"))
	{
	 pRegistro->valor=strdup("FinPagina");
	 return 1;
	}
	else
	return 0;
}
int QtImpBeneficiosIntegrales::EsFinContrato(const char *pchrPtrLinea,
					     Registro *pRegistro)
{
     if(!strcmp(pchrPtrLinea,"FinContrato"))
     {
	pRegistro->valor=strdup("FinContrato");
	return 1;
     }
     else
     return 0;
}
int QtImpBeneficiosIntegrales::LineaValida(const char *pchrPtrLinea)
{
char *lchrPtrLinea=(char *)pchrPtrLinea;
    if(*lchrPtrLinea)
    {
    	zSiscomDesarrollo4::EliminaEspaciosInicio(lchrPtrLinea);
	if(*lchrPtrLinea!='#')
	return 1;
	else
	return 0;
    }
    else
    return 0;
}
void QtImpBeneficiosIntegrales::CargandoPosiciones()
{
	CargaPosicionesArchivo();
}
void QtImpBeneficiosIntegrales::CompletaContratoBeneficios()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ConsultaContratoBeneficios");
lzOpeServiSNTE.CompletaContratoBeneficiosIntegrales(zConBeneficios);
}
const char *QtImpBeneficiosIntegrales::FormaNumeroDireccion()
{
 char lchrArrNumero[128];
 const char *lchrPtrNumeroExterior=zConBeneficios->NumExteriorEmpleo(),
 	    *lchrPtrNumeroInterior=zConBeneficios->NumInteriorEmpleo();
	if(*lchrPtrNumeroExterior && 
	   *lchrPtrNumeroInterior)
	{
	sprintf(lchrArrNumero,"Numero %s Interior %s",lchrPtrNumeroExterior,lchrPtrNumeroInterior);
	return strdup(lchrArrNumero);
	}
	else
	if(*lchrPtrNumeroExterior && 
	   !*lchrPtrNumeroInterior)
	  return lchrPtrNumeroExterior;
	else
	if(!*lchrPtrNumeroExterior &&
	    *lchrPtrNumeroInterior)
	    return lchrPtrNumeroInterior;
	else
	return "";
}
