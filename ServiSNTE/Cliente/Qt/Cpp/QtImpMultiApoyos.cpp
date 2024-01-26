#include <QtImpMultiApoyos.h>

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
#include <qtable.h>
#include <qtextedit.h>
#include <stdlib.h>
#include <stdio.h>
#include <qlineedit.h>
#include <qmessagebox.h>
QtImpMultiApoyos::QtImpMultiApoyos(	QWidget *pQWParent,
					const char *pchrPtrName):
					MultiApoyos(pQWParent,pchrPtrName)
{

Conexion((zSiscomConexion *)gzSiscomConexion);
ConectaSlots();
IniciaVariables();

}
void QtImpMultiApoyos::Conexion(zSiscomConexion *pzSiscomConexion)
{
   zSisConexion=pzSiscomConexion;
}
void QtImpMultiApoyos::ConectaSlots()
{
/*	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QTCreditos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaCredito(int,int,int,const QPoint &)));*/
}
void QtImpMultiApoyos::IniciaVariables()
{
	Formato();

}
void QtImpMultiApoyos::Formato()
{
chrPtrFormato=strdup("\n\
<font size=\"3\" color=\"Black\">\n\
<table cellspacing=\"1\" border=\"1\">\n\
<tr aling =\"center\" >\n\
	<td colspan=\"8\" bgcolor=\"lightblue\"> \n\
		<b><h1 align =\"center\">MULTI-APOYOS DE CAPITAL</h1></b>\n\
	</td>\n\
</tr>\n\
<tr aling =\"center\" >\n\
	<td colspan=\"5\" rowspan=\"3\" bgcolor=\"lightblue\"> \n\
	<font size=\"2\">\n\
		<p>Requisitos:</p>\n\
		<ul><pre>1.SOLICITUD DE CONTRATO.						 5.COMPROBANTE CURP Y/0 R.F.C. </pre></ul>\n\
		<ul><pre>2.IDENTIFICACION OFICIAL VIGENTE CON FIRMA.		 6.ULTIMOS 2 RECIBOS DE NOMINA.</pre></ul>\n\
		<ul><pre>3.EDAD ENTRE 24 y 60 AÑOS.						7.ANTIGUEDAD MINIMA DE 2 AÑOS.</pre></ul>\n\
		<ul><pre>4.COMPROBANTE DE DOMICILIO </pre></ul>\n\
	</font>\n\
	</td>\n\
	<td bgcolor=\"lightblue\">\n\
		 LOTE No.\n\
	</td>\n\
	<td colspan=\"2\">\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\" align =\"center\" bgcolor=\"lightblue\">\n\
		LUGAR Y FECHA DE ELABORACION\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"3\">\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\">\n\
	<font size=\"2\">\n\
		<p>LA PRESENTE CARATULA DE CRETIDO FORMA PARTE DEL CONTRATO DE APERTURA DE CREDITO SIMPLE OTORGADO POR MULTI-APOYO CAPILA S.A. DE C.V. SOFOM E.N.R.</p>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		IMPORTE SOLICITADO:$ %s.00\n\
	</td>\n\
	<td colspan=\"4\">\n\
		(%s M.N.)\n\
	</td>\n\
	<td colspan=\"3\">\n\
		PLAZO: %s \n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		<p>DATOS GENERALES DEL SOLICITANTE</p>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\">\n\
		NOMBRE (APELLIDO PATERNO, MATERNO Y NOMBRE(S))<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		R.F.C.<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		CURP <br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"3\">\n\
		ENTIDAD FEDERATIVA DE NACIMIENTO<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		PAIS DE NACIMIENTO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		GENERO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		ESTADO CIVIL<br>\n\
		%s\n\
	</td>\n\
	<td>\n\
		EDAD<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		FECHA DE NACIMIENTO (DIA,MES,AÑO)<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		IDENTIFICACION DE PRESENTA<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		NO. DE IDENTIFICACION<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"3\">\n\
		OCUPACION<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"4\">\n\
		<pre>¿DESEMPEÑA O HA DESEMPEÑADO EN LOS DOS ULTIMOS AÑOS FUNCION </pre>\n\
		<pre> PUBLICA DE ALTA JERARQUIA EN MEXICO O EN EL EXTRANJERO?</pre>\n\
		<pre>SI %s		¿QUE CARGO? %s		NO %s </pre>\n\
		<pre>FECHA EN QUE DEJO EL CARGO %s		     </pre>\n\
	</td>\n\
	<td colspan=\"4\">\n\
		<pre>¿USTED ES FAMILIAR DE UNA PERSONA QUE DESEMPEÑA O HAYA DESEMPEÑADO EN LOS DOS ULTIMOS AÑOS </pre>\n\
		<pre>FUNCION PUBLICA DE ALTA JERARQUIA EN MEXICO O EN EL EXTRANJERO?i</pre>\n\
		<pre>SI %s		¿QUE CARGO? %s		NO %s </pre>\n\
		<pre>FECHA EN QUE DEJO EL CARGO %s		      </pre>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		<p>DOMICILIO PARTICULAR</p>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		CALLE<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		NO. EXT.<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		NO INT<br>\n\
		%s\n\
	</td>\n\
	<td>\n\
		COLONIA<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		CODIGO POSTAL<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"2\">\n\
		DELEGACION O MUNICIPIO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		CIUDAD O POBLACION<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		ENTIDAD FEDERATIVA (ESTADO)<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		PAIS<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"6\">\n\
		TIPO DE VIVIENDA<br>\n\
		<pre>PROPIA %s RENTADA %s HIPOTECADA %s FAMILIAR %s OTRA %s</pre>\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TELEFONO PARTICULAR<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"2\">\n\
		TIEMPO DE RESIDIR<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TELEFONO CELULAR<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		CORREO ELECTRONICO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TELEFONO PARA DEJAR RECADO<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		<p>DATOS DEL EMPLEO ACTUAL</p>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		NOMBRE DE LA EMPRESA<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		ANTIGUEDAD<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"3\">\n\
		PUESTO ACTUAL<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=4>\n\
		ACTIVIDAD O GIRO DE LA EMPRESA<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		NOMBRE DEL JEFE DIRECTO<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		<p>DOMICILIO DEL EMPLEO ACTUAL</p>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		CALLE Y NUMERO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		COLONIA<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"3\">\n\
		CODIGO POSTAL<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		DELEGACION O MUNICIPIO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		CIUDAD O POBLACION<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"3\">\n\
		ENTIDAD FEDERATIVA<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td>\n\
		PAIS<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"4\">\n\
		TELEFONO<br>\n\
		<pre>%s		ext. %s</pre>\n\
	</td>\n\
	<td colspan=\"3\">\n\
		CORREO ELECTRONICO<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		INGRESOS MENSUALES\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=1>\n\
		SUELDO<br>\n\
		$ %s\n\
	</td>\n\
	<td colspan=\"7\">\n\
		FRECUENCIA DE PAGO INDICADA EN SU RECIBO DE NOMINA<br>\n\
		SEMANAL %s CATORCENAL %s QUINCENAL %s MENSUAL %s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=1>\n\
		OTROS INGRESOS<br>\n\
		$ %s\n\
	</td>\n\
	<td colspan=\"5\">\n\
		ESPECIFIQUE LA FUENTE DE OTROS INGRESOS<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TOTAL DE INGRESOS<br>\n\
		$ %s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" bgcolor=\"lightblue\">\n\
	<font size=\"4\">\n\
		REFERENCIAS PERSONALES (DE DOS FAMILIARES Y DE UN NO FAMILIAR)\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=1>\n\
		NOMBRE COMPLETO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"5\">\n\
		DOMICILIO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TELEFONO (CON LADA)<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=1>\n\
		NOMBRE COMPLETO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"5\">\n\
		DOMICILIO<br>\n\
		%s\n\
	</td>\n\
	<td colspan=\"2\">\n\
		TELEFONO (CON LADA)<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=1>\n\
		NOMBRE COMPLETO<br>\n\
		 %s\n\
	</td>\n\
	<td colspan=\"5\">\n\
		DOMICILIO<br>\n\
		%s\n\
	</td>\n\
	<td >\n\
		TEL (CON LADA)<br>\n\
		%s\n\
	</td>\n\
	<td>\n\
		PARENTESCO<br>\n\
		%s\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\" >\n\
	<font size=\"2\">\n\
		<pre>-INCUMPLIR TUS OBLIGACIONES DE PAGO TE PUEDE GENERAR COMISIONES E INTERESES MORATORIOS</pre>\n\
		<pre>-CONTRATAR CREDITOS POR ARRIBA DE TU CAPACIDAD DE PAGO PUEDE AFECTAR TU HISTORIAL CREDITICIO</pre>\n\
		<pre>-UNIDAD ESPECIALIZADA DE ATENCION DE USUARIOS \"UNE\": AV. RIO SAN JOAQUIN No. 529 PISO 2 COL. FRANCISCO I. MADERO CIUDAD DE MEXICO, C.P. 1148 TEL. (55) 5203-2020 o 01 800 890-5882</pre>\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr align=\"center\">\n\
	<td colspan=\"4\">\n\
		<font size =\"2\">Tasa de Interes Fija Anual del 42.6%	, CAT Promedio 35.8% Tasa de interes promedio ponderada  </font><br>\n\
		<br><br><br><br><br><br>\n\
		____________________________________________________<br>\n\
		FIRMA DE ACEPTACION DEL PRESENTE CONTRATO\n\
	</td>\n\
	<td colspan=\"4\">\n\
		<font size =\"2\"><p align=\"left\">POR ESTE CONDUCTO AUTORIZO EXPRESAMENTE A MULTIAPOYOS DE CAPITAL S.A. DE C.V., SOFOM, E.N.R., PARA QUE POR CONDUCTO DE SUS FUNCIONARIOS FACULTADOS LLEVE A CABO INVESTIGACIONES SOBRE MI COMPORTAMIENTO CREDITICIO ANTE LAS SOCIEDADES DE INFORMACION CREDITICIO QUE ESTIME CONVENIENTE. ASI MISMO, DECLARO QUE CONOZCO LA NATURALEZA Y ALCANCE DE LA INFORMACION QUE SE SOLICITARA, DEL USO QUE MULTI-APOYOS DE CAPITAL DE S.A DE C.V., SOFOM E.N.R. HARA DE TAL INFORMACION Y QUE PODRA REALIZAR CONSULTAS PERIODICAS DE MI HISTORIAL DE CREDITO, CONSINTIENDO QUE ESTA AUTORIZACION SE ENCUENTRE VIGENTE POR UN PERIODO DE TRES AÑOS CONTADOS A PARTIR DE LA FECHA DE EXPEDICION Y EN TODO CASO DURANTE EL TIEMPO QUE MANTENGAMOS RELACION JURIDICA. ESTOY CONCIENTE Y ACEPTO QUE ESTE DOCUMENTO QUEDE BAJO PROPIEDAD DE MULTI-APOYOS DE CAPITAL, S.A. DE C.V., SOFOM, E.N.R.   </p></font><br>\n\
		____________________________________________________<br>\n\
		FIRMA DEL SOLICITANTE (ACREDITADO) DE ACEPTACION DE CONSULTA DE BURO DE CREDITO.\n\
	</td>\n\
</tr>\n\	
<tr>\n\
	<td colspan=\"8\" align=\"right\">\n\
	<font size=\"1\">\n\
		Version 06/16\n\
	</font>\n\
	</td>\n\
</tr>\n\
<tr>\n\
	<td colspan=\"8\" align=\"center\">\n\
	<font size=\"3\">\n\
		<pre>REGISTRO DE CONTRATO DE ADHESION RECA No. 13842-439-025422/01-01211-0616	TELEFONO CONDUSEF 01 800 999 8080 o 53 400 999</pre>\n\
	</font>\n\
	</td>\n\
</tr>\n\
</table>\n\
</font>");
 
chrPtrSalida=(char *)malloc(strlen(chrPtrFormato)+1024);
sprintf(chrPtrSalida,chrPtrFormato,
	"1234",
	"12/02/16 MXDF",
	"importe",
	"monto",
	"plazo",
	"nombre",
	"rfc",
	"curp",
	"entidad",
	"pais",
	"GEN",
	"ESTC",
	"EDAD",
	"FECHAN",
	"ife  ",
	"12123",
	"OCUPACION",
	"X",
	" CARGO ",
	"  ",
	"FECHA",
	"x",
	"cargo ",
	"  ",
	"fecha",
	"calle",
	"ext",
	"int",
	"col",
	"cp",
	"deleg",
	"ciudad",
	"estado",
	"pais",
	"P ",
	"R ",
	"H ",
	"F ",
	"otra ",
	"tel part",
	"tiempoR",
	"Tel cel",
	"email",
	"tel recados",
	"empresa ",
	"antiguedad",
	"puesto act",
	"giro",
	"nombre jefe",
	"calle#",
	"col",
	"cp",
	"del o mun",
	"ciud o pob",
	" estado",
	"pais",
	"tel",
	"ext",
	"email",
	"sueld",
	"s",
	"c",
	"q ",
	"m ",
	"otros$ ",
	"fuente",
	"total",
	"nombre1",
	"dom1",
	"tel1",
	"nom2",
	"dom2",
	"tel2",
	"nom3",
	"dom3",
	"tel3",
	"parent");
QTEFormato->setText(chrPtrSalida);
}
void QtImpMultiApoyos::SlotSeleccionaCredito(int pintNCredito,
							      int,
							      int,
							      const QPoint &)
{
	/*QTCreditos->selectRow(pintNCredito);
	zSiscomQt3::Foco(QPBAceptar);
	intCreditoSeleccionado=pintNCredito;*/

}
void QtImpMultiApoyos::SlotCancelar()
{
   /*intAceptar=0;
   done(0);*/
}
int QtImpMultiApoyos::Consultando()
{
/*	if(Consulta())
	{
	Muestra();
	return 1;
	}
	else
	{
	return 0;
	}*/
}

int QtImpMultiApoyos::Consulta()
{
/* zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"MultiApoyos");
 if((zSisRegCredsBeneficios=lzSisOpeServiSNTE.MultiApoyos()))
 return 1;
 else
 return 0;*/
}
void QtImpMultiApoyos::Muestra()
{
/*char *lchrPtrCampos[]={"total",
		 	"pagototal",
			"pagoquincenal",
			"plazo",
			"porcentajetasa",
			"completo",
			"rfc",
			0};
zSisRegsCreditos=zSisRegCredsBeneficios->AsociadosDelCampo("CreditosBeneficios");
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsCreditos,	
			QTCreditos);
}
zSiscomRegistro *QtImpMultiApoyos::Credito()
{
	return zSisCredito;
}
int QtImpMultiApoyos::Aceptar()
{
	return intAceptar;*/
}
