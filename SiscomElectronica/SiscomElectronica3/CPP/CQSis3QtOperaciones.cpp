#include <CQSis3QtOperaciones.h>
#include <SiscomRegistros3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomOperaciones3.h>
#include <CQSisSueldos.h>
#include <CQSisCursosDiaHora.h>
#include <CQSisCostoCurso.h>

#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros4.h>
CQSis3QtOperaciones::CQSis3QtOperaciones(SiscomDatCom *pSisDatCom):
			SiscomOperaciones3(pSisDatCom)
{

}
void CQSis3QtOperaciones::HistoricoCompras(
				const char *pchrPtrProducto,
				const char *pchrPtrIdExpendio,
				const char *pchrPtrFechaRefVentas,
				SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomRegistro3Lst lSRegistro3LstCns;

lSRegistro3LstCns 						<< 
new SiscomParametroConsulta3("HistoricoCompras")		<<
new SiscomParametroConsulta3(pchrPtrIdExpendio)			<<
new SiscomParametroConsulta3(pchrPtrProducto)			<<
new SiscomParametroConsulta3(pchrPtrFechaRefVentas);

	SiscomEnvia("ConsultasSiscomElectronica2",
				  &lSRegistro3LstCns,
				  pSRegistro3Lst); 

}

void CQSis3QtOperaciones::HistoricoCompras(
			  const char *pchrPtrPExisMinBajo,
			  const char *pchrPtrPExisMinAlto,
			  const char *pchrPtrExpendio,
			  const char *pchrPtrFechaRefVentas,
			  SiscomRegistro3Lst *pSRegistros3Lst)
{
SiscomRegistro3Lst lSRegistro3LstCns;

lSRegistro3LstCns 						<< 
new SiscomParametroConsulta3("HistoricoComprasExistenciaMinima")		<<
new SiscomParametroConsulta3(pchrPtrExpendio)			<<
new SiscomParametroConsulta3(pchrPtrPExisMinBajo)		<<
new SiscomParametroConsulta3(pchrPtrPExisMinAlto)		<<
new SiscomParametroConsulta3(pchrPtrFechaRefVentas);

	SiscomEnvia("ConsultasSiscomElectronica2",
				  &lSRegistro3LstCns,
				  pSRegistros3Lst);
}
void CQSis3QtOperaciones::RegistraSueldo(CQSisSueldo *pCQSSueldo)
{
SiscomRegistro3Lst lSReg3LstSueldo;
SiscomRegistro3Lst lSReg3LstResSueldo;
lSReg3LstSueldo << pCQSSueldo;
SiscomEnvia("RegistraSueldo",
	    &lSReg3LstSueldo,
	    &lSReg3LstResSueldo);
}

void CQSis3QtOperaciones::AlumnosExpendio(const char *pchrPtrIdExpendio,
					 SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomEscribeLog3Qt((char *)"%s",pchrPtrIdExpendio);
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSRegistro3Lst,
	    "%s%s",
	    "AlumnosExpendio",
	    pchrPtrIdExpendio);

}


void CQSis3QtOperaciones::MotivoInventario(const char *pchrPtrIdExpendio,
					 SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomEscribeLog3Qt("%s",pchrPtrIdExpendio);
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSRegistro3Lst,
	    "%s%s",
	    "MotivoInventario",
	    pchrPtrIdExpendio);

}
void CQSis3QtOperaciones::ReportePorExistenciaMinima(
			   const char *pchrPtrIdExpendio,
			   SiscomRegistro3Lst *pSisReg3LstReporte)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	   pSisReg3LstReporte,
	   "%s%s",
	   "ReportePorExistenciaMinima",
	   pchrPtrIdExpendio);
}

void CQSis3QtOperaciones::ExistenciasProductos(
			   const char *pchrPtrIdExpendio,
			   const char *pchrPtrCveProducto,
			   SiscomRegistro3Lst *pSisReg3LstReporte)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	   pSisReg3LstReporte,
	   "%s%s%s",
	   "ExistenciasProductos",
	   pchrPtrIdExpendio,
	   pchrPtrCveProducto);
}

void CQSis3QtOperaciones::ExistenciasProductosPorCasiClave(
			   const char *pchrPtrIdExpendio,
			   const char *pchrPtrCveProducto,
			   SiscomRegistro3Lst *pSisReg3LstReporte)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	   pSisReg3LstReporte,
	   "%s%s%s",
	   "ExistenciasProductosPorCasiClave",
	   pchrPtrIdExpendio,
	   pchrPtrCveProducto);
}
void CQSis3QtOperaciones::ProductosPorcentajeExistenciaMinima(
				const char *pchrPtrIdExpendio,
				const char *pchrPtrPBajo,
				const char *pchrPtrPAlto,
				SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	   pSisReg3LstRegreso,
	   "%s%s%s%s",
	   "ProductosPorcentajeExistenciaMinima",
	   pchrPtrIdExpendio,
	   pchrPtrPBajo,
	   pchrPtrPAlto);
}
							
void CQSis3QtOperaciones::ExistenciaProductoBodega(const char *pchrPtrIdExpendio,
						   SiscomRegistro3 *pSisReg3Bodega,
						   SiscomRegistro3 *pSisReg3Producto,
						   SiscomRegistro3Lst *pSisReg3LstBodegas)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstBodegas,
	    "%s%s%s%s",
	    "ExistenciaProductoBodega",
	    pchrPtrIdExpendio,
	    (*pSisReg3Bodega)["idbodega"],
	    (*pSisReg3Producto)["cveproducto"]);
}


void CQSis3QtOperaciones::ExistenciasProductosBodega(const char *pchrPtrIdExpendio,
					SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstRegreso,
	    "%s%s",
	    "ExistenciasProductosBodega",
	    pchrPtrIdExpendio);
}

void CQSis3QtOperaciones::ExistenciasExpendio(const char *pchrPtrIdExpendio,
						   SiscomRegistro3Lst *pSisReg3LstExExpendio)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstExExpendio,
	    "%s%s",
	    "ExistenciasExpendio",
	    pchrPtrIdExpendio);
}


void CQSis3QtOperaciones::TransfiereMaterialBodegaExpendio(
				SiscomRegistro3Lst *pSisReg3LstTransfiere,
				SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("TransfiereBodegaExpendio",
	    pSisReg3LstTransfiere,
	    pSisReg3LstRegreso);

}

void CQSis3QtOperaciones::InventarioBodegaSiscom(SiscomRegistro3 *pSisReg3ProdInvBod)
{
SiscomRegistro3Lst lSisReg3LstEnvioRespuesta;
SiscomRegistro3Lst lSisReg3LstRegreso;
lSisReg3LstEnvioRespuesta << pSisReg3ProdInvBod;
SiscomEnvia("InventarioBodega",&lSisReg3LstEnvioRespuesta,&lSisReg3LstRegreso); 
SiscomRegistro3LstContenido(&lSisReg3LstEnvioRespuesta);
SiscomRegistro3LstContenido(&lSisReg3LstRegreso); 
}


void CQSis3QtOperaciones::Clientes(const char *pchrPtrIdExpendio,
		      SiscomRegistro3Lst *pSisReg3LstClientes)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstClientes,
	    "%s%s",
	    "ClientesSiscom",
	    pchrPtrIdExpendio);
}
void CQSis3QtOperaciones::RegistraClienteFisica(SiscomRegistro3 *pSisReg3Cliente)
{
SiscomRegistro3Lst lSisReg3LstClientes;
SiscomRegistro3Lst lSisReg3LstRegreso;
lSisReg3LstClientes << pSisReg3Cliente;
SiscomEnvia("RegistraClienteFisica",
	    &lSisReg3LstClientes,
	    &lSisReg3LstRegreso);
}

void CQSis3QtOperaciones::RegistraClienteMoral(SiscomRegistro3 *pSisReg3Cliente)
{
SiscomRegistro3Lst lSisReg3LstClientes;
SiscomRegistro3Lst lSisReg3LstRegreso;
lSisReg3LstClientes << pSisReg3Cliente;

SiscomEnvia("RegistraClienteMoral",
	    &lSisReg3LstClientes,
	    &lSisReg3LstRegreso);
	    

}
void CQSis3QtOperaciones::OrdenesParaFacturar(SiscomRegistro3Lst *pSisReg3LstOrdenes,
					      SiscomRegistro3Lst *pSisReg3LstProductos,
					      SiscomRegistro3Lst *pSisReg3LstProductosO)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomRegistro3 *lSisReg3Regreso;
SiscomEnvia("OrdenesAFactuar",
	    pSisReg3LstOrdenes,
	    &lSisReg3LstRegreso);
for(lSisReg3Regreso=lSisReg3LstRegreso.first();
    lSisReg3Regreso;
    lSisReg3Regreso=lSisReg3LstRegreso.next())
{
   if(!strcmp((*lSisReg3Regreso)["Dato"],"ProductosAFacturar"))
    (*pSisReg3LstProductos) << lSisReg3Regreso;
   if(!strcmp((*lSisReg3Regreso)["Dato"],"ProductosOrden"))
    (*pSisReg3LstProductosO) << lSisReg3Regreso;



}
}

void CQSis3QtOperaciones::SincronizaExpendio(const char *pchrPtrIdExpendio,
					     const char *pchrPtrOperacion,
					     SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstRegreso,
	    "%s%s",
	    "SincronizaExpendio",
	    pchrPtrIdExpendio,
	    pchrPtrOperacion);
}

void CQSis3QtOperaciones::Cursos(SiscomRegistro3Lst *pSisReg3LstCursos)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstCursos,
	    "%s",
	    "Cursos");

}

void CQSis3QtOperaciones::FechasCursos(const char *pchrPtrIdCurso,
				 SiscomRegistro3Lst *pSisReg3LstCursos)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstCursos,
	    "%s%s%s",
	    "FechasCursos",
	    "",
	    pchrPtrIdCurso);

}


void CQSis3QtOperaciones::FechasCostosCursos(const char *pchrPtrIdExpendio,
					const char *pchrPtrIdCurso,
					SiscomRegistro4 *pSisReg4InfoCursos)
{

SiscomEnvia2("FechasCostosCursos",
	    pSisReg4InfoCursos,
	    "%s[IdExpendio] %s[IdCurso] ",
	    pchrPtrIdExpendio,
	    pchrPtrIdCurso);
}


void CQSis3QtOperaciones::CostosCurso(const char *pchrPtrIdExpendio,
				      SiscomRegistro3 *pSisReg3FechaCurso,
				      SiscomRegistro3Lst *pSisReg3LstCostosCurso)
{
pSisReg3LstCostosCurso->clear();
SiscomEnvia2("CostosCurso",
	     pSisReg3LstCostosCurso,
	    "%s[IdExpendio] %s[IdCurso] %s[Fecha] %s[IdProgramacion] ",
	    pchrPtrIdExpendio,
	    (*pSisReg3FechaCurso)["idcurso"],
	    (*pSisReg3FechaCurso)["fecha"],
	    (*pSisReg3FechaCurso)["idprogramacion"]);
}

void CQSis3QtOperaciones::CostosCurso(const char *pchrPtrIdProgramacion,
				      const char *pchrPtrIdCurso,
				      SiscomRegistro3Lst *pSisReg3LstCostosCurso)
{
pSisReg3LstCostosCurso->clear();
SiscomEnvia2("CostosCurso",
	     pSisReg3LstCostosCurso,
	    "%s[IdExpendio] %s[IdCurso] %s[Fecha] %s[IdProgramacion] ",
	    "",
	    pchrPtrIdCurso,
	    "",
	    pchrPtrIdProgramacion);
}

/* Miercoles 11 de Diciembre del 2013 
 * Se debera revisar, si es necesario saber donde se vendio cada
 * curso, en que expendio. Al dia de hoy todo se centraliza en la
 * matriz.
 */
void CQSis3QtOperaciones::VentasCursos(const char *pchrPtrFecha,
				       SiscomRegistro3Lst *pSisReg3LstInfoCursos)
{
SiscomEnvia2("VentasCursos",
	    pSisReg3LstInfoCursos,
	    "%s[IdProgramacionCurso] ",
	    pchrPtrFecha);
}


void CQSis3QtOperaciones::AlumnosInscritosCurso(const char *pchrPtrIdCurso,
						const char *pchrPtrFecha,
						SiscomRegistro3Lst *pSisReg3LstAlumnosInscritos)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstAlumnosInscritos,
	    "%s%s%s%s",
	    "AlumnosInscritosCurso",
	    "",
	    pchrPtrIdCurso,
	    pchrPtrFecha);
}

void CQSis3QtOperaciones::DisponibilidadCursos(
			 	const char *pchrPtrFecha,
				SiscomRegistro3Lst *pSisReg3LstDisponibilidadC)
{

SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstDisponibilidadC,
	    "%s%s%s",
	    "DisponibilidadCursos",
	    "",
	    pchrPtrFecha);
}

void CQSis3QtOperaciones::Servicios(SiscomRegistro3Lst *pSisReg3LstServicios)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstServicios,
	    "%s%s%s",
	    "ServiciosSiscom",
	    "",
	    "Todos");
}
SiscomRegistro3 *CQSis3QtOperaciones::RegistraAlumnoServicioHoraEntrada(
					const char *pchrPtrIdExpendio,
					SiscomRegistro3 *pSisReg3Servicio,
					SiscomRegistro3 *pSisReg3Alumno,
					const char *pchrPtrComentarios)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia2(
  "RegistraAlumnoServicio",
  &lSisReg3LstRegreso,
  "%s[IdRegistroServicio] %s[IdExpendio] %s[IdServicio] %s[IdAlumno] %s[Comentarios] %s[HoraEntrada] ",
  "",
  pchrPtrIdExpendio,
  (*pSisReg3Servicio)["idservicio"],
  (*pSisReg3Alumno)["idpersona"],
  pchrPtrComentarios,
  "");
if(lSisReg3LstRegreso.count())
return lSisReg3LstRegreso.at(0);
else
return 0;
}

void CQSis3QtOperaciones::ServiciosSinRegistroSalida(
				const char *pchrPtrIdExpendio,
				const char *pchrPtrFecha,
				SiscomRegistro3Lst *pSisReg3LstAlumnos)
{
SiscomEnvia2(
	"AlumnosServiciosSinRegistroSalida",
	pSisReg3LstAlumnos,
	"%s[IdExpendio] %s[Fecha] ",
	pchrPtrIdExpendio,
	pchrPtrFecha);
}

void CQSis3QtOperaciones::RegistraSalidaAlumno(const char *pchrPtrIdExpendio,
					       const char *pchrPtrIdServicio)
{
SiscomRegistro3Lst lSisReg3LstRegreso;
SiscomEnvia2("RegistraSalidaAlumnoServicio",
	      &lSisReg3LstRegreso,
	     "%s[IdExpendio] %s[IdServicio] %s[HoraSalida] ",
	     pchrPtrIdExpendio,
	     pchrPtrIdServicio,
	     "");
}


void CQSis3QtOperaciones::ProductosEnMatrizNoExpendio(
				const char *pchrPtrIdExpendio,
				SiscomRegistro3Lst *pSisReg3LstProductos)
{
SiscomEnvia2("ProductosEnMatrizNoExpendio",
	      pSisReg3LstProductos,
	     "%s[IdExpendio] ",
	     pchrPtrIdExpendio);
}

void CQSis3QtOperaciones::SincronizaProductosExpendio(
				const char *pchrPtrIdExpendio,
				SiscomRegistro3Lst *pSisReg3LstEdoRegistro)
{
SiscomEnvia2("SincronizaProductosAlExpendio",
	     pSisReg3LstEdoRegistro,
	     "%s[IdExpendio] ",
	     pchrPtrIdExpendio);
}
void CQSis3QtOperaciones::ExplicacionPromocion(SiscomRegistro3Lst *pSisReg3LstExPromocion)
{
SiscomEnvia2("ExplicacionPromocion",
	     pSisReg3LstExPromocion,
	     "%s[IdExpendio] ",
	     "");

}
void CQSis3QtOperaciones::OrigenCompra(SiscomRegistro3Lst *pSisReg3LstExPromocion)
{
SiscomEnvia("OrigenCompra",
	     pSisReg3LstExPromocion,
	     "%s",
	     "");
SiscomRegistro3LstContenido(pSisReg3LstExPromocion);
pSisReg3LstExPromocion->first();
}

void CQSis3QtOperaciones::CursosProgramados(SiscomRegistro3Lst *pSisReg3LstCursos)
{
SiscomEnvia("ConsultasSiscomElectronica2",
	    pSisReg3LstCursos,
	    "%s%s%s",
	    "CursosProgramados",
	    "",
	    "");

}
void CQSis3QtOperaciones::EstadisticasSemanalesVentas(const char *pchrPtrIdExpendio,
						      const char *pchrPtrAno,
						       const char *pchrPtrIdEscuela,
						       SiscomRegistro4 *pSisReg4Regreso)
{
const char *lchrPtrIdEscuela=pchrPtrIdEscuela ? pchrPtrIdEscuela :"";
SiscomEnvia2("Ano",
	    pSisReg4Regreso,
	    "%s[IdExpendio] %s[Ano] %s[IdEscuela] ",
	    pchrPtrIdExpendio,
	    pchrPtrAno,
	    pchrPtrIdEscuela);
}

void CQSis3QtOperaciones::RegistraProgramacionCursos(const char *pchrPtrIdExpendio,
						     const char *pchrPtrDscProgramacion)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia2("RegistraProgramacionCursos",
	     &lSisReg4Regreso,
	     "%s [IdExpendio] %s [DscProgramacion] %s [IdProgramacion] ",
	     pchrPtrIdExpendio,
	     pchrPtrDscProgramacion,
	     "");
}


void CQSis3QtOperaciones::CursosProgramadosFechaRegistro(
					const char *pchrPtrFechaInicio,
					const char *pchrPtrHoraInicio,
					const char *pchrPtrHoraFin,
					const char *pchrPtrIdCurso,
					const char *pchrPtrIdProgramacion,
					const char *pchrPtrCurso,
					CQSisCursosDiaHora *pCQSisCuDiaHora)
{
pCQSisCuDiaHora->SiscomLimpia();
SiscomEnvia2("CursosProgramadosFechaRegistro",
	      (SiscomRegistro4 *)pCQSisCuDiaHora,
	      "%s [FechaInicio] %s [HoraInicio] %s [HoraFin] %s [IdCurso] %s [IdProgramacion] %s [Curso] ",
	      pchrPtrFechaInicio,
	      pchrPtrHoraInicio,
	      pchrPtrHoraFin,
	      pchrPtrIdCurso,
	      pchrPtrIdProgramacion,
	      pchrPtrCurso);
}

void CQSis3QtOperaciones::CursosProgramados(const char *pchrPtrFechaInicio,
					    CQSisCursosDiaHora *pCQSisCuDiaHora)
{
pCQSisCuDiaHora->SiscomLimpia();
SiscomEnvia2("ConsultaCursosProgramados",
	     (SiscomRegistro4 *)pCQSisCuDiaHora,
	     "%s [FechaInicio] ",
	     pchrPtrFechaInicio);
}
void CQSis3QtOperaciones::ProgramaCurso(const char *pchrPtrIdProgramacion,
					const char *pchrPtrIdCurso,
					const char *pchrPtrFechaInicio)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia2("ProgramandoCurso",
	      &lSisReg4Regreso,
	      "%s [IdProgramacion] %s [IdCurso] %s [FechaInicio] ",
	      pchrPtrIdProgramacion,
	      pchrPtrIdCurso,
	      pchrPtrFechaInicio);
}
void CQSis3QtOperaciones::CostosCurso(CQSisCostoCurso *pCQSCsCurso)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
SiscomEnvia("RegistraCostosCurso",pCQSCsCurso,&lSisReg3LstRespuesta);
}

void CQSis3QtOperaciones::ReEnviaTransferencia(SiscomRegistro3 *pSiscomRegProTra)
{
SiscomRegistro3Lst lSisReg3LstRespuesta;
   SiscomEnvia("ReEnviaTransferencia",
   		pSiscomRegProTra,
		&lSisReg3LstRespuesta);
}

void CQSis3QtOperaciones::ImprimePedido(const char *pchrPtrIdPedido)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia2("ImprimePedido",
	      &lSisReg4Regreso,
	      "%s [IdPedido] ",
	      pchrPtrIdPedido);
}
void CQSis3QtOperaciones::ClavesProveedor(const char *pchrPtrCveProducto,
					  SiscomRegistro4 *pSisReg4Claves)
{
SiscomEnvia2("ClavesProveedor",
	      pSisReg4Claves,
	      "%s [CveProducto] ",
	      pchrPtrCveProducto);
}

void CQSis3QtOperaciones::ActualizaClaveProveedor(const char *pchrPtrIdExpendio,
						  const char *pchrPtrIdProveedor,
						  const char *pchrPtrClaveProveedor,
						  const char *pchrPtrCveProducto)
{
SiscomRegistro4 lSisReg4Regreso;
SiscomEnvia2("ActualizaClaveProveedor",
	     &lSisReg4Regreso,
	     "%s [IdExpendio] %s [IdProveedor] %s [ClaveProveedor] %s [CveProducto]",
	     pchrPtrIdExpendio,
	     pchrPtrIdProveedor,
	     pchrPtrClaveProveedor,
	     pchrPtrCveProducto);
}
