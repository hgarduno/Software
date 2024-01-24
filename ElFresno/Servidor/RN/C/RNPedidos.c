#include <RNPedidos.h>
#include <RNVentas.h>
#include <RNVarios.h>

typedef struct ConsultaLosPedidos
{
	int (*EsConsulta)(char **,char *);
	void (*ConsultaLosPedidos)(int,
				   const char *,
				   const char *,
				   StcLtaRegComSISCOM **,
				   int *);
	void (*EjecutaFormateoRespuesta)(int,
					 const char *,
					 int ,
					 StcLtaRegComSISCOM *,
					 StcLtaRegComSISCOM **,
					 int *);
}StcConsultaPedidos;


StcConsultaPedidos gSCPedidos[]={ {EsConsultaPedidosSinAutorizarDelDia,
			           PedidosSinAutorizarDelDia,
				   RespuestaPedidosSinAutorizacionDelDia,
				   },
				   {EsConsultaPedidosDelVehiculo,
				    PedidosDelVehiculo,
				    RespuestaPedidosDelVehiculo
				   },
				   {EsAsignacionDelVehiculo,
				    AsignaVehiculoAlPedido,
				    RespuestaAsignaVehiculoAlPedido
				   },
				   {EsConsultaDetalleDelPedido,
				    DetalleDelPedido,
				    RespuestaDetalleDelPedido
				   },
				   {EsActualizaFechaEntrega,
				    ActualizaFechaEntrega,
				    RespuestaFechaEntrega
				  }
				};
const char *gchrPtrCadConsultaPedidos="							\
				select	a.NumPedido,					\
		      		a.idCliente,						\
				a.idVendedor,						\
				a.idChofer,						\
				a.idAutorizo,						\
				a.idEmpresa,						\
				a.idVehiculo,						\
				a.FechaRegistro,					\
				a.FechaEntrega,						\
				a.Importe,						\
				b.idEdoPedido,						\
				b.FechaHoraEdo,						\
				c.Nombre,						\
				c.APaterno,						\
				c.AMaterno,						\
				c.RFC,							\
				c.idPersona,						\
				c.TipoPersona,						\
				d.NmbTipoPrecio,					\
				e.Placas,						\
      				e.DscVehiculo,						\
				f.Nombre,						\
				f.APaterno,						\
				f.AMaterno,						\
				f.RFC,							\
				f.idPersona,						\
				f.TipoPersona,						\
				g.Nombre,						\
				g.APaterno,						\
				g.AMaterno,						\
				g.RFC,							\
				g.idPersona,						\
				g.TipoPersona,						\
				h.Nombre,						\
				h.APaterno,						\
				h.AMaterno,						\
				h.RFC,							\
				h.idPersona,						\
				h.TipoPersona,						\
				i.Nombre,						\
				i.APaterno,						\
				i.AMaterno,						\
				i.RFC,							\
				i.idPersona,						\
				i.TipoPersona,						\
				a.FormaDePago,						\
				a.contactocliente					\
			from	Pedidos as a						\
				inner join EstadoDelPedido as b using(NumPedido)	\
				inner join Personas as c on(a.idCliente=c.idPersona)	\
				inner join FormaPago as d using(NumPedido)		\
				left outer join Vehiculos as e using(idVehiculo)	\
      				left outer join Personas as f on(idChofer=f.idPersona)  \
				left outer join Personas as g on(idAutorizo=g.idPersona) \
				left outer join Personas as h on(idpersonarevisochofer=h.idPersona) \
				left outer join Personas as i on(idVendedor=i.idPersona)  ";

int gintNumConsultasPedidos=5;
const char *ObtenIdClientePedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_IdClientePedidos];
}
const char *ObtenFirmaVendedorPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_FirmaVendedorPedidos];
}


const char *ObtenImporteTotalPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_ImporteTotalPedidos];
}


const char *ObtenProductoPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_ProductoPedidos];
}


const char *ObtenCantidadPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_CantidadPedidos];
}


const char *ObtenImportePedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_ImportePedidos];
}


const char *ObtenTipoPrecioPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_TipoPrecioPedidos];
}
const char *ObtenContactoClientePedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_ContactoCliente];
}
const char *ObtenFechaEntregaPedidos(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Pedidos_FechaEntrega];
}

void RegistraTipoDePago(char **pchrPtrRegistro,
			const char *pchrPtrIdPedido,
			int *pintPtrNRegistros,
			StcLtaRegComSISCOM **pSLRCSisDatPrim,
			StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into FormaPago values(%s,'%s');",
			pchrPtrIdPedido,
			ObtenTipoPrecioPedidos(pchrPtrRegistro));		

}


void AnexaDetallePedido(char **pchrPtrRegistro,
		        const char *pchrPtrIdPedido,	
			  int *pintPtrNRegistros,
			  StcLtaRegComSISCOM **pSLRCSisDatPrim,
			  StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into DetallePedido values(%s,'%s',%s,%s,'%s');",
			pchrPtrIdPedido,
			ObtenProductoPedidos(pchrPtrRegistro),
		        ObtenCantidadPedidos(pchrPtrRegistro),
			ObtenImportePedidos(pchrPtrRegistro),
			ObtenTipoPrecioPedidos(pchrPtrRegistro));		
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "update existencias 				\
			        set existencia=existencia-%s 		\
			 where CveProducto='%s' and 			\
			       idExpendio=(select idEmpresa from matriz);",
		        ObtenCantidadPedidos(pchrPtrRegistro),
			ObtenProductoPedidos(pchrPtrRegistro));

}

StcLtaRegComSISCOM *GeneraRespuestaPedidos(int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatPrim,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);

	return lSLRCSisDatPrim;

}
void RegistraPedido(char **pchrPtrRegistro,
		    const char *pchrPtrIdVendedor,
		    int *pintPtrNRegistros,
		    StcLtaRegComSISCOM **pSLRCSisPrim,
		    StcLtaRegComSISCOM **pSLRCSisActual,
		    char *pchrPtrIdPedido)
{
char lchrArrBuffer[256];
char lchrArrFechaHoraActual[35];	
	SISCOMImprimeContenidoRegistro(pchrPtrRegistro,"<<RegistraPedido>>");
	sprintf(pchrPtrIdPedido,
		"%ld",
		SISCOMObtenNumeroUnico());
	SISCOMObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraActual);
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisPrim,
		pSLRCSisActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into Pedidos(idCliente,idVendedor,NumPedido,FechaRegistro,Importe,FechaEntrega,contactocliente) values(%s,%s,%s,'%s',%s,'%s','%s')",
		ObtenIdClientePedidos(pchrPtrRegistro),
		pchrPtrIdVendedor,
		pchrPtrIdPedido,
		lchrArrFechaHoraActual,
		ObtenImporteTotalPedidos(pchrPtrRegistro),
		ObtenFechaEntregaPedidos(pchrPtrRegistro),
		ObtenContactoClientePedidos(pchrPtrRegistro));
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisPrim,
		pSLRCSisActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into EstadoDelPedido values(%s,%s,'%s')",
		pchrPtrIdPedido,
		"1",
		lchrArrFechaHoraActual);

/*
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisPrim,
		pSLRCSisActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"update existencia 					\
		 set Existencia=Existencia-%s          			\
		 where CveProducto=%s and 				\
		       IdExpendio=(select idempresa from matriz)",
		  ObtenProductoPedidos(pchrPtrRegistro),
		  ObtenCantidadPedidos(pchrPtrRegistro));

 */

}

int EsConsultaDetalleDelPedido(char **pchrPtrRegistro,
				 char *pchrPtrConsulta)
{
	if(!strcmp(pchrPtrRegistro[0],
		   "DetalleDelPedido"))
	{
	  sprintf(pchrPtrConsulta,
		  "select  a.idCliente, 						\
		          b.*, 								\
			  c.idPrecio,   						\
			  c.Precio,							\
			  d.Nombre,							\
			  d.APaterno,							\
			  d.AMaterno							\
		   from	pedidos as a 							\
			inner join detallepedido as b using(NumPedido) 			\
			inner join precios as c on (a.idCliente=c.idPersona and		\
						    b.NmbTipoPrecio=c.NmbTipoPrecio and \
						    b.CveProducto=c.CveProducto)	\
			inner join personas as d on(a.idCliente=d.idPersona)		\
		   where numPedido=%s",
		   pchrPtrRegistro[1]);

	  return 1;
	}
	return 0;
}
int EsConsultaPedidosDelVehiculo(char **pchrPtrRegistro,
				 char *pchrPtrConsulta)
{
	if(!strcmp(pchrPtrRegistro[0],"ObtenPedidosDelVehiculo"))
	{
	  
		sprintf(pchrPtrConsulta,
		    "%s where a.idVehiculo=%s and 		\
			      b.idEdoPedido in(2,3,4) and	\
			      a.FechaRegistro::date>='%s' and 	\
			      a.FechaRegistro::date<='%s'	\
		     order by a.NumPedido ",
		    gchrPtrCadConsultaPedidos,
		     pchrPtrRegistro[1],
		     pchrPtrRegistro[2],
		     pchrPtrRegistro[3]);
	return 1;
	}
	return 0;
}
int EsAsignacionDelVehiculo(char **pchrPtrRegistro,
			    char *pchrPtrConsulta)
{
	if(!strcmp(pchrPtrRegistro[0],
		       "AsignaVehiculoAlPedido"))
	{
	  sprintf(pchrPtrConsulta,
		  "update Pedidos 		\
			  set idVehiculo=%s,    \
			      idChofer=%s 	\
		   where NumPedido=%s",
		  pchrPtrRegistro[1],
		  pchrPtrRegistro[3],
		  pchrPtrRegistro[2]);
	  return 1;
	}
	return 0;
}
int EsConsultaPedidosSinAutorizarDelDia(char **pchrPtrRegistro,
					char *pchrPtrCadConsulta)
{
char lchrArrFechaHoy[25];
	if(!pchrPtrRegistro[0][0] &&
	       pchrPtrRegistro[1][0] )
	{
	    if(!pchrPtrRegistro[2][0] &&
	       !pchrPtrRegistro[3][0] )
	    {
	    SISCOMObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
	      sprintf(pchrPtrCadConsulta,
		      "%s where b.idEdoPedido= %s  and					\
			        cast(a.FechaRegistro as date)='%s'  \
			order by a.FechaRegistro",
			gchrPtrCadConsultaPedidos,
			pchrPtrRegistro[1],
			lchrArrFechaHoy);
	   }
	   else
           {
	      sprintf(pchrPtrCadConsulta,
		      "%s where b.idEdoPedido= %s  and					\
			        cast(a.FechaRegistro as date)>='%s' and			\
				cast(a.FechaRegistro as date)<='%s' \
			order by a.NumPedido",
			gchrPtrCadConsultaPedidos,
			pchrPtrRegistro[1],
			pchrPtrRegistro[2],
			pchrPtrRegistro[3]);
	   }
		return 1;
	}

	return 0;

}
void AsignaVehiculoAlPedido(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrCadConsulta,
			       StcLtaRegComSISCOM **pSLRCSisPedidos,
			       int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisActual=0;
int lintNRegistros=0;
char lchrArrBuffer[256];

		SISCOMAnexaRegistroFormateandoParaEnvio(
				&lSLRCSisPrim,
				&lSLRCSisActual,
				&lintNRegistros,
				lchrArrBuffer,
				"%s",
				pchrPtrCadConsulta); 
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisPrim,
                                      pSLRCSisPedidos,
                                      pintPtrNRegistros);

}
void RespuestaAsignaVehiculoAlPedido(int pintPtoComAD,
					   const char *pchrPtrDirIpSvr,
					   int pintNRegistrosDat,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   StcLtaRegComSISCOM **pSLRCSisRespuesta,
					   int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(pSLRCSisRespuesta,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);
}
void DetalleDelPedido(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrCadConsulta,
			       StcLtaRegComSISCOM **pSLRCSisPedidos,
			       int *pintPtrNRegistros)
{

	*pSLRCSisPedidos=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(pintPtoComAD,
					pchrPtrDirIpSvr,
					pchrPtrCadConsulta,
					pintPtrNRegistros);

}
void PedidosDelVehiculo(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrCadConsulta,
			       StcLtaRegComSISCOM **pSLRCSisPedidos,
			       int *pintPtrNRegistros)
{

	*pSLRCSisPedidos=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(pintPtoComAD,
					pchrPtrDirIpSvr,
					pchrPtrCadConsulta,
					pintPtrNRegistros);

}
void RespuestaPedidosDelVehiculo(int pintPtoComAD,
					   const char *pchrPtrDirIpSvr,
					   int pintNRegistrosDat,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   StcLtaRegComSISCOM **pSLRCSisRespuesta,
					   int *pintPtrNRegistros)
{

	*pSLRCSisRespuesta=pSLRCSisDat;
	*pintPtrNRegistros=pintNRegistrosDat;

}
void RespuestaDetalleDelPedido(int pintPtoComAD,
					   const char *pchrPtrDirIpSvr,
					   int pintNRegistrosDat,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   StcLtaRegComSISCOM **pSLRCSisRespuesta,
					   int *pintPtrNRegistros)
{
	*pSLRCSisRespuesta=pSLRCSisDat;
	*pintPtrNRegistros=pintNRegistrosDat;

}



void PedidosSinAutorizarDelDia(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrCadConsulta,
			       StcLtaRegComSISCOM **pSLRCSisPedidos,
			       int *pintPtrNRegistros)
{

	*pSLRCSisPedidos=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(pintPtoComAD,
					pchrPtrDirIpSvr,
					pchrPtrCadConsulta,
					pintPtrNRegistros);

}
void RespuestaPedidosSinAutorizacionDelDia(int pintPtoComAD,
					   const char *pchrPtrDirIpSvr,
					   int pintNRegistrosDat,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   StcLtaRegComSISCOM **pSLRCSisRespuesta,
					   int *pintPtrNRegistros)
{

	*pSLRCSisRespuesta=pSLRCSisDat;
	*pintPtrNRegistros=pintNRegistrosDat;

}
void SeleccionaYEjecutaConsultaPedidos(int pintPtoComAD,
				       const char *pchrPtrDirIpSvr,
				       char **pchrPtrParametros,
				       StcLtaRegComSISCOM **pSLRCSisPedidos,
				       int *pintPtrNRegistros)
{
char lchrArrConsulta[2048];
int lintContador,
    lintNRegistrosReg;
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
	for(lintContador=0;lintContador<gintNumConsultasPedidos;lintContador++)
	if(gSCPedidos[lintContador].EsConsulta(pchrPtrParametros,lchrArrConsulta))
	{
	  gSCPedidos[lintContador].ConsultaLosPedidos(pintPtoComAD,
						   pchrPtrDirIpSvr,
						   lchrArrConsulta,
						   &lSLRCSisRegreso,
						   &lintNRegistrosReg);
	  gSCPedidos[lintContador].EjecutaFormateoRespuesta(pintPtoComAD,
							    pchrPtrDirIpSvr,
							    lintNRegistrosReg,
							    lSLRCSisRegreso,
							    pSLRCSisPedidos,
							    pintPtrNRegistros);
	}



}	
StcLtaRegComSISCOM *ConsultaPedidos(int pintPtoComAD,
				    const char *pchrPtrDirIpSvr,
				    StcLtaRegComSISCOM *pSLRCSisDat,
				    int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPedidos=0;
char **lchrPtrParametros;
char lchrArrCondicionBusqueda[2048];

		SISCOMCopiaACharCharDeComunicaciones(pSLRCSisDat,
						    1,
						    &lchrPtrParametros);
		SISCOMImprimeContenidoRegistro(lchrPtrParametros,"ConsultaPedidos:Parametros");
		SeleccionaYEjecutaConsultaPedidos(pintPtoComAD,
						  pchrPtrDirIpSvr,
						  lchrPtrParametros,
						  &lSLRCSisPedidos,
						  pintPtrNRegistros);
		return lSLRCSisPedidos;
					   

}
/*
StcLtaRegComSISCOM *ActualizaRegistraFechaEntregaPedido(int pintPtoComAD,
					 const char *pchrPtrDirIpSvr,
					 StcLtaRegComSISCOM *pSLRCSisDat,
					 int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
char lchrArrIdPedido[12];
const char *lchrPtrNumPedido;
*pintPtrNRegistros=0;

	SISCOMImprimeContenidoCom2(stdout,
				   "ActualizaRegistraFechaPedido",
				   '|',
				   '\n',
				   pSLRCSisDat);
	
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisDatPrim,
			&lSLRCSisDatActual,
			&lintNRegistros,
			lchrArrBuffer,
			"update pedidos set FechaEntrega='%s' where NumPedido=%s;",
			pSLRCSisDat->chrPtrRegistro[1],
			pSLRCSisDat->chrPtrRegistro[0]);
	}
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  lSLRCSisDatPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaPedidos(pintPtrNRegistros);

}
*/
StcLtaRegComSISCOM *ActualizaPedido(int pintPtoComAD,
					 const char *pchrPtrDirIpSvr,
					 StcLtaRegComSISCOM *pSLRCSisDat,
					 int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
char lchrArrIdPedido[12];
const char *lchrPtrNumPedido;
*pintPtrNRegistros=0;

	SISCOMImprimeContenidoCom2(stdout,
				   "ActualizaPedido",
				   '|',
				   '\n',
				   pSLRCSisDat);
	
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	   if(!lintContador)
	   {
	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisDatPrim,
			&lSLRCSisDatActual,
			&lintNRegistros,
			lchrArrBuffer,
			"delete from detallepedido where numPedido=%s;",
			pSLRCSisDat->chrPtrRegistro[1]);
	    lchrPtrNumPedido=pSLRCSisDat->chrPtrRegistro[1];
	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisDatPrim,
			&lSLRCSisDatActual,
			&lintNRegistros,
			lchrArrBuffer,
			"update pedidos set importe=%s \
			 where NumPedido=%s",
			 ObtenImporteTotalPedidos(pSLRCSisDat->chrPtrRegistro),
			 lchrPtrNumPedido);
	   }
	   else
	   {

	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisDatPrim,
			&lSLRCSisDatActual,
			&lintNRegistros,
			lchrArrBuffer,
			"insert into detallepedido values(%s,'%s',%s,%s,'%s');",
			lchrPtrNumPedido,
			ObtenProductoPedidos(pSLRCSisDat->chrPtrRegistro),
			ObtenCantidadPedidos(pSLRCSisDat->chrPtrRegistro),
			ObtenImportePedidos(pSLRCSisDat->chrPtrRegistro),
			ObtenTipoPrecioPedidos(pSLRCSisDat->chrPtrRegistro));
	     
	   }
			


				      	
	}
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  lSLRCSisDatPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaPedidos(pintPtrNRegistros);

}

StcLtaRegComSISCOM *RegistraPedidos(int pintPtoComAD,
					 const char *pchrPtrDirIpSvr,
					 StcLtaRegComSISCOM *pSLRCSisDat,
					 int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
char lchrArrIdPedido[12];
const char *lchrPtrIdVendedor;
*pintPtrNRegistros=0;

	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraPedidos",
				   '|',
				   '\n',
				   pSLRCSisDat);
	
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
		if(!lintContador)
		RegistraPedido(pSLRCSisDat->chrPtrRegistro,
			       ObtenFirmaVendedorPedidos(pSLRCSisDat->chrPtrRegistro),
			       &lintNRegistros,
			       &lSLRCSisDatPrim,
			       &lSLRCSisDatActual,
			       lchrArrIdPedido);
		else
		{
		if(lintContador==1)
		RegistraTipoDePago(pSLRCSisDat->chrPtrRegistro,
				   lchrArrIdPedido,
				   &lintNRegistros,
				   &lSLRCSisDatPrim,
				   &lSLRCSisDatActual);	
	 	AnexaDetallePedido(pSLRCSisDat->chrPtrRegistro,
				   lchrArrIdPedido,
				     &lintNRegistros,
				     &lSLRCSisDatPrim,
				     &lSLRCSisDatActual);
		}
				      	
	}
	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraPedido",
				   '|',
				   '\n',
				   lSLRCSisDatPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaPedidos(pintPtrNRegistros);

}
int EsActualizaFechaEntrega(char **pchrPtrParametros,char *pchrPtrConsulta)
{
	if(!strcmp(pchrPtrParametros[0],
		   "ActualizaFechaEntrega"))
	{
	sprintf(pchrPtrConsulta,
		"update Pedidos set FechaEntrega='%s' where NumPedido=%s",
		 pchrPtrParametros[2],
		 pchrPtrParametros[1]);
	return 1;
	}
	else
	return 0;
}
void ActualizaFechaEntrega(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrCadConsulta,
			       StcLtaRegComSISCOM **pSLRCSisPedidos,
			       int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisActual=0;
int lintNRegistros=0;
char lchrArrBuffer[256];

		SISCOMAnexaRegistroFormateandoParaEnvio(
				&lSLRCSisPrim,
				&lSLRCSisActual,
				&lintNRegistros,
				lchrArrBuffer,
				"%s",
				pchrPtrCadConsulta); 
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisPrim,
                                      pSLRCSisPedidos,
                                      pintPtrNRegistros);

}
void RespuestaFechaEntrega(int pintPtoComAD,
					   const char *pchrPtrDirIpSvr,
					   int pintNRegistrosDat,
					   StcLtaRegComSISCOM *pSLRCSisDat,
					   StcLtaRegComSISCOM **pSLRCSisRespuesta,
					   int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(pSLRCSisRespuesta,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);
}
int EsActualizaImportePedido(char **pchrPtrParametros,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisDatRegistros,
			    int *pintPtrNRegistros)
{
char lchrArrFechaHoraActual[25];
StcLtaRegComSISCOM *lSLRCSisDatActual=0;
char lchrArrBuffer[128];
long llngIdEdoPedido;
int lintNRegistros=0;
	*pintPtrNRegistros=0;
	if(!strcmp(pchrPtrParametros[0],
		   "ActualizaImportePedido"))
	{
		llngIdEdoPedido=-atol(pchrPtrParametros[2]);
		SISCOMObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraActual);
		SISCOMAnexaRegistroFormateandoParaEnvio(
				pSLRCSisDatRegistros,
				&lSLRCSisDatActual,
				pintPtrNRegistros,
				lchrArrBuffer,
				"insert into EstadoDelPedido values(%s,%s,'%s');",
				pchrPtrParametros[1],
				pchrPtrParametros[3],
				lchrArrFechaHoraActual);
		SISCOMAnexaRegistroFormateandoParaEnvio(
				pSLRCSisDatRegistros,
				&lSLRCSisDatActual,
				pintPtrNRegistros,
				lchrArrBuffer,
				"update EstadoDelPedido set idEdoPedido=%ld \
				 where NumPedido=%s and idEdoPedido=%s",
				 llngIdEdoPedido,
				 pchrPtrParametros[1],
				 pchrPtrParametros[2]);
		return 1;
	}
	else
	return 0;
}
int EsAutorizacionRevisionChofer(char **pchrPtrParametros)
{

		return (pchrPtrParametros[2][0]=='1' &&
		       pchrPtrParametros[3][0]=='2' )||
		       pchrPtrParametros[2][0]=='5'&&
		       pchrPtrParametros[3][0]=='6' ;

}
int EsActualizaEstadoPedido(char **pchrPtrParametros,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisDatRegistros,
			    int *pintPtrNRegistros)
{
char lchrArrFechaHoraActual[25];
StcLtaRegComSISCOM *lSLRCSisDatActual=0;
char lchrArrBuffer[128];
long llngIdEdoPedido;
int lintNRegistros=0;
	*pintPtrNRegistros=0;
	if(!strcmp(pchrPtrParametros[0],
		   "ActualizaEstadoPedido"))
	{
		llngIdEdoPedido=-atol(pchrPtrParametros[2]);
		SISCOMObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraActual);
		SISCOMAnexaRegistroFormateandoParaEnvio(
				pSLRCSisDatRegistros,
				&lSLRCSisDatActual,
				pintPtrNRegistros,
				lchrArrBuffer,
				"insert into EstadoDelPedido values(%s,%s,'%s');",
				pchrPtrParametros[1],
				pchrPtrParametros[3],
				lchrArrFechaHoraActual);
		SISCOMAnexaRegistroFormateandoParaEnvio(
				pSLRCSisDatRegistros,
				&lSLRCSisDatActual,
				pintPtrNRegistros,
				lchrArrBuffer,
				"update EstadoDelPedido set idEdoPedido=%ld \
				 where NumPedido=%s and idEdoPedido=%s",
				 llngIdEdoPedido,
				 pchrPtrParametros[1],
				 pchrPtrParametros[2]);
		if(EsAutorizacionRevisionChofer(pchrPtrParametros))
		SISCOMAnexaRegistroFormateandoParaEnvio(
				pSLRCSisDatRegistros,
				&lSLRCSisDatActual,
				pintPtrNRegistros,
				lchrArrBuffer,
				"update pedidos set %s=%s \
				 where NumPedido=%s",
				 pchrPtrParametros[2][0]=='1' &&
				 pchrPtrParametros[3][0]=='2' ?
				 "idautorizo" : "idPersonaRevisoChofer",
				 pchrPtrParametros[4],
				 pchrPtrParametros[1]);

/* idPersonaRevisoChofer */





		return 1;

	}
	else
	return 0;
}
int EsActualizaFormaPago(char **pchrPtrParametros,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisDatRegistros,
			    int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatActual=0;
char lchrArrBuffer[128];
		if(!strcmp(pchrPtrParametros[0],
			   "ActualizaFormaPago"))
		{
		  *pintPtrNRegistros=0;
		  SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatRegistros,
			&lSLRCSisDatActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"update Pedidos set FormaDePago='%s' \
		         where NumPedido=%s;",
			pchrPtrParametros[2],
			pchrPtrParametros[1]);
		   if(strcmp(pchrPtrParametros[2],"Contado"))
			SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatRegistros,
			&lSLRCSisDatActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into cuentasporcobrar values(%s,'%s',%s);",
			pchrPtrParametros[1],
			pchrPtrParametros[3],
			pchrPtrParametros[4]);
			
			
		  
			  
		  return 1;
		}
		else
		{

		  return 0;
		}
	

}
void ActualizaEstadoPedido(int pintPtoComAD,
			   const char *pchrPtrDirIpSvr,
			   const char *pchrPtrConsulta,
			   StcLtaRegComSISCOM *pSLRCSisDat,
			   int pintNRegistros,
			   StcLtaRegComSISCOM **pSLRCSisRegreso,
			   int *pintPtrNRegreso)
{
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      pintNRegistros,
                                      pSLRCSisDat,
                                      pSLRCSisRegreso,
                                      pintPtrNRegreso);


}
void RespuestaActualizaEstadoPedido(int pintPtoComAD,
				    const char *pchrPtrDirIpSvr,
				    int pintNRegEntrada,
				    StcLtaRegComSISCOM *pSLRCSisDatEntrada,
				    StcLtaRegComSISCOM **pSLRCSisDatSalida,
				    int *pintPtrNRegSalida)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegSalida=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(pSLRCSisDatSalida,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegSalida,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);


}
StcLtaRegComSISCOM *OperacionesPedidos(int pintPtoComAD,
				    const char *pchrPtrDirIpSvr,
				    StcLtaRegComSISCOM *pSLRCSisDat,
				    int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRespuesta=0;
StcOperacionesAlSistemaSISCOM lSOASSiscom[]={{
					      EsActualizaEstadoPedido,
					      ActualizaEstadoPedido,
					      RespuestaActualizaEstadoPedido
					     },
					     {
					      EsActualizaImportePedido,
					      ActualizaEstadoPedido,
					      RespuestaActualizaEstadoPedido
					     },
					     {
					      EsActualizaFormaPago,
					      ActualizaEstadoPedido,
					      RespuestaActualizaEstadoPedido
					     }
					    };
SISCOMImprimeContenidoCom2(stdout,
			   "OperacionesPedidos",
			   '|',
			   '\n',
			   pSLRCSisDat);
		SISCOMSeleccionaYEjecutaOperacionAlSistema(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lSOASSiscom,
				3,
				pSLRCSisDat,
				&lSLRCSisRespuesta,
				pintPtrNRegistros);
		return lSLRCSisRespuesta;
}
