#include <SqlContratosBeneficios.h>
#include <SqlDirecciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <SiscomDesarrolloMacros.h>
#include <stdio.h>
int SqlCreditosBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrSql[1024],lchrArrBuffer[1024];
sprintf(lchrArrSql,
"select a.idventa,								\n\
        a.idcliente,								\n\
	b.total,								\n\
	c.pagototal,								\n\
	c.pagoquincenal,							\n\
	e.nombre as plazo,							\n\
	f.tasa,									\n\
	f.tasa*100 as porcentajetasa,						\n\
	g.*,									\n\
	g.apaterno || ' ' || g.nombre as completo				\n\
from ventas as a inner join							\n\
     importeventa as b using(idventa) inner join				\n\
     ventacredito as c using(idventa) inner join				\n\
     financiadoras as d using(idfinanciadora) inner join			\n\
     plazos as e using(idplazo)  inner join					\n\
     tasainteres as f on (e.idplazo=f.idplazo  and				\n\
     			  c.idfinanciadora=f.idfinanciadora) inner join		\n\
     personas as g on g.idpersona=a.idcliente					\n\
where idcliente in (select idcliente						\n\
		    from ventas as a inner join					\n\
		    ventacredito using(idventa)					\n\
		     where idtipoventa =2 and idfinanciadora=4) and		\n\
	idtipoventa=2");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			      "CreditosBeneficios%",
			      lchrArrSql);
}
int SqlRegistraContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
lSisRegProLPtrDat=SiscomObtenArgumentoPrimOperaciones("ProductosContratoBeneficios",pSiscomOpePtrDat); 
SiscomAgregaArgumentoInsercionSql("SqlInsertaContratoBeneficios",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaContratoBeneficios",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToContratosBeneficios);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaContratoBeneficios",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToTransporteContratosBeneficios);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaContratoBeneficios",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToEstadoContratosBeneficios);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaContratoBeneficios",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToObservacionContratosBeneficios);

SiscomAgregaSentenciasSqlRegistros("SqlInsertaContratoBeneficios",
				   lchrArrBuffer,
				   lchrArrSql,
				   lSisRegProLPtrDat,
				   pSiscomOpePtrDat,
				   InsertToDetalleContratoBeneficios);
SiscomReplicaMaquinaLocal("SqlInsertaContratoBeneficios", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlConsultaContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
    lchrArrSql[512];
sprintf(lchrArrSql,
"                               \n\
select t.*, et.idestado         \n\
from transferencias as t inner join     \n\
estadotransferencia as et using(idtransferencia)    \n\
where et.idestado='1'");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "ContratosBeneficios%",
                 lchrArrSql);
}

int SqlConsultaInformacionContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
    char lchrArrSqlDetalleContratoBeneficios[1024],
         lchrArrSqlProductosContratoBeneficios[1024],
         lchrArrBuffer[1024];
    SqlDetalleContratoBeneficios(pSiscomOpePtrDat,lchrArrSqlDetalleContratoBeneficios);
    SqlProductosContratoBeneficios(pSiscomOpePtrDat,lchrArrSqlProductosContratoBeneficios);
    SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "DetalleContratoBeneficios%ProductosContratoBeneficios%",
                  lchrArrSqlDetalleContratoBeneficios,
                  lchrArrSqlProductosContratoBeneficios);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"DetalleContratoBeneficios",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ProductosContratoBeneficios",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}

int SqlDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat,
            char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "select t.*,                    \n\
     tr.*, ti.nombre as tienda, al.nombre as almacenista, ch.nombre as chofer, \n\
     ca.nombre as camion, ca.placas, ot.*   \n\
     from transferencias as t inner join    \n\
     tiendas as ti using(idtienda) inner join   \n\
     transportetransferencia as tr using(idtransferencia) inner join    \n\
     camiones as ca using(idcamion) inner join      \n\
     personas al on(al.idpersona = idalmacenista) inner join       \n\
     personas ch on(ch.idpersona = idchofer) inner join         \n\
     observaciontransferencia as ot using(idtransferencia) inner join      \n\
     estadotransferencia as est using(idtransferencia)      \n\
     where idtransferencia='%s'",
    SiscomCampoAsociadoEntradaOperacion("Envio",
                            "IdContratoBeneficios",
                        pSiscomOpePtrDat));
    
    LogSiscom("SqlConsulta: %s",pchrPtrSql);
}

int SqlProductosContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat,
            char *pchrPtrSql)
{
sprintf(pchrPtrSql,
    "select *                           \n\
     from productos inner join                  \n\
          productocodigobarras using(idproducto) inner join     \n\
     detalletransferencia using(idproducto)     \n\
     where idtransferencia='%s'",
    SiscomCampoAsociadoEntradaOperacion("Envio",
                            "IdContratoBeneficios",
                        pSiscomOpePtrDat));

    LogSiscom("SqlConsulta %s",pchrPtrSql);
}

int SqlActualizaEstadoContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;

SiscomAgregaArgumentoInsercionSql("SqlActualizaContratoBeneficios",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);
    
SiscomReplicaMaquinaLocal("SqlActualizaContratoBeneficios", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

int SqlRecibeContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512],
    lchrArrSqlProductosContratoBeneficios[1024];
SiscomRegistroProL *lSisRegProLPtrDat;
SqlProductosContratoBeneficios(pSiscomOpePtrDat,lchrArrSqlProductosContratoBeneficios);

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                  pSiscomOpePtrDat,
                 "ProductosContratoBeneficios%",
                  lchrArrSqlProductosContratoBeneficios);

SiscomRegistrosAsociadosLog(lchrArrBuffer,"ProductosContratoBeneficios",pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);

lSisRegProLPtrDat = SiscomObtenArgumentoPrimOperaciones("ProductosContratoBeneficios",pSiscomOpePtrDat);

SiscomAgregaArgumentoInsercionSql("SqlRecibeContratoBeneficios",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomReplicaMaquinaLocal("SqlRecibeContratoBeneficios", lchrArrBuffer, 0, pSiscomOpePtrDat);
}

void InsertToContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ContratosBeneficios values(%s,%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdContratoBeneficios",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdTienda",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdAlmacenista",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void InsertToTransporteContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into TransporteContratoBeneficios values(%s,%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdContratoBeneficios",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdChofer",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdCamion",pSiscomRegProLPtrEnt));
}

void InsertToEstadoContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into EstadoContratoBeneficios values(%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdContratoBeneficios",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void InsertToObservacionContratosBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ObservacionContratoBeneficios values(%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdContratoBeneficios",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("ObservacionGeneral",pSiscomRegProLPtrEnt));
}

void InsertToDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleContratoBeneficios values(%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdContratoBeneficios",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrEnt));
}

void InsertToComentarioDetalleContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
		      	  SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      	  char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleContratoBeneficios values(%s,%s,%s);",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdContratoBeneficios",pSiscomOpePtrDatos),
	SiscomObtenCampoRegistroProLChar("idproducto",pSiscomRegProLPtrEnt),
	SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrEnt));
}

void InsertToEstadoContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDatos,
              SiscomRegistroProL *pSiscomRegProLPtrEnt,
              char *pchrPtrSql)
{
    sprintf(pchrPtrSql,
    "insert into ContratosBeneficios values(%s,%s,'%s');",
     SiscomObtenCampoRegistroProLChar("IdContratoBeneficios",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrEnt),
     SiscomObtenCampoRegistroProLChar("Fecha",pSiscomRegProLPtrEnt));
}

void SqlGeneralesContratoBeneficios(SiscomOperaciones *pSiscomOpePtrDat,
				    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *				\n\
	 from generalescontratobeneficios	\n\
	 where idventa=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDat));
}
void SqlDatosCasa(SiscomOperaciones *pSiscomOpePtrDat,
				    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *						\n\
	 from datoscasa as a inner join				\n\
	      tipoviviendas as b using(idtipovivienda)		\n\
	 where iddireccion=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdDireccion",pSiscomOpePtrDat));
}
void SqlDatosNacimiento(SiscomOperaciones *pSiscomOpePtrDat,
			char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 						\n\
	 from datosnacimiento as a inner join			\n\
	      otrosdatospersonales as b using(idpersona)	\n\
	 where idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));
}
void SqlIdentificacion(SiscomOperaciones *pSiscomOpePtrDat,
			char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select *		\n\
	 from identificacion 	\n\
	 where idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));
}
void SqlConsultaTelefonosCliente(SiscomOperaciones *pSiscomOpePtrDat,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 					\n\
	 from telefonos inner join 			\n\
	      telefonocliente using(idtelefono) 	\n\
	 where idcliente=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));
}
void SqlConsultaCorreoCliente(SiscomOperaciones *pSiscomOpePtrDat,
			      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 					\n\
	 from correos inner join 			\n\
	      correocliente using(idcorreo) 		\n\
	 where idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));
}
int SqlEmpleo(SiscomOperaciones *pSiscomOpePtrDat,
	      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"										\n\
	select a.idempleo,								\n\
	       a.idpersona as idpersonaempleo,						\n\
       	       b.idempresa,								\n\
       	       b.razonsocial,								\n\
       	       c.idpersona as idjefe,							\n\
       	       d.*,									\n\
       	       e.*,									\n\
       	       f.*,									\n\
	       g.giro,									\n\
	       i.*,									\n\
	       k.*,									\n\
	       m.*,									\n\
	       e.sueldo+f.monto as totalingresos					\n\
	from empleo as a left outer join empresas as b using(idempresa) left outer join	\n\
     	     jefes as c using(idempleo) left outer join 				\n\
     	     personas as d on c.idpersona=d.idpersona left outer join			\n\
     	     datosempleo as e using(idempleo) inner join				\n\
     	     otrosingresos as f on a.idpersona=f.idpersona left outer join 		\n\
	     empresagiro as g using(idempresa) left outer join				\n\
	     direccionesempresa as h using(idempresa) left outer join			\n\
	     direcciones as i using(iddireccion) left outer join  			\n\
	     telefonosempresa as j using(idempresa) left outer join			\n\
	     telefonos as k using(idtelefono) left outer join				\n\
	     correoempresa as l using(idempresa) left outer join			\n\
	     correos as m using(idcorreo)						\n\
	where a.idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));

LogSiscom("%s",pchrPtrSql);
}
int SqlReferenciasPersonales(SiscomOperaciones *pSiscomOpePtrDat,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"									\n\
select a.idreferencia,								\n\
	a.idpersona as idcliente,						\n\
	b.idpersona as idpersonareferencia,					\n\
	b.parentesco,								\n\
	c.nombre,								\n\
	c.apaterno,								\n\
	c.amaterno,								\n\
	c.rfc,									\n\
	e.*,									\n\
	g.*									\n\
from referenciapersonal  as a inner join 					\n\
     personareferencia as b using(idreferencia) inner join 			\n\
     personas as c on  b.idpersona=c.idpersona inner join			\n\
     direccionesreferencia as d on a.idreferencia=d.idreferencia and 		\n\
     				   b.idpersona=d.idpersona inner join		\n\
     direcciones as  e using(iddireccion) inner join				\n\
     telefonoreferencia as f on a.idreferencia=f.idreferencia and 		\n\
     				b.idpersona=f.idpersona inner join		\n\
     telefonos as g  using(idtelefono)						\n\
where a.idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDat));
}
int SqlCentroTrabajo(SiscomOperaciones *pSiscomOpePtrDato,
		     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select * 			\n\
	 from centrotrabajo		\n\
	 where idpersona=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCliente",pSiscomOpePtrDato));
}
int SqlInformacionContratoBeneficiosIntegrales(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[4196],
      lchrArrGeneralesContrato[256],
      lchrArrDatosCasa[256],
      lchrArrDatosNacimiento[256],
      lchrArrIdentificacion[256],
      lchrArrTelefonosCliente[256],
      lchrArrCorreosCliente[256],
      lchrArrEmpleo[2048],
      lchrArrReferenciasPersonales[2048],
      lchrArrCentroTrabajo[256];
SqlGeneralesContratoBeneficios(pSiscomOpePtrDat,lchrArrGeneralesContrato);
SqlDatosCasa(pSiscomOpePtrDat,lchrArrDatosCasa);
SqlDatosNacimiento(pSiscomOpePtrDat,lchrArrDatosNacimiento);
SqlIdentificacion(pSiscomOpePtrDat,lchrArrIdentificacion);
SqlConsultaTelefonosCliente(pSiscomOpePtrDat,lchrArrTelefonosCliente);
SqlConsultaCorreoCliente(pSiscomOpePtrDat,lchrArrCorreosCliente);
SqlEmpleo(pSiscomOpePtrDat,lchrArrEmpleo);
SqlReferenciasPersonales(pSiscomOpePtrDat,lchrArrReferenciasPersonales);
SqlCentroTrabajo(pSiscomOpePtrDat,lchrArrCentroTrabajo);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      pSiscomOpePtrDat,
			     "GeneralesContrato%DatosCasa%DatosNacimiento%Identificacion%TelefonosCliente%CorreosCliente%Empleo%ReferenciasPersonales%CentroTrabajo%",
			     lchrArrGeneralesContrato,
			     lchrArrDatosCasa,
			     lchrArrDatosNacimiento,
			     lchrArrIdentificacion,
			     lchrArrTelefonosCliente,
			     lchrArrCorreosCliente,
			     lchrArrEmpleo,
			     lchrArrReferenciasPersonales,
			     lchrArrCentroTrabajo);
}



