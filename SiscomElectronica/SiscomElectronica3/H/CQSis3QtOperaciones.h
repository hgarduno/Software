#ifndef __CQSIS3QTOPERACIONES_H__ 
#define __CQSIS3QTOPERACIONES_H__
#include <SiscomOperaciones3.h>
class SiscomRegistro3Lst;
class SiscomDatCom;
class CQSisSueldo;
class CQSisImprimeTicket;
class CQSisCliente;
class CQSisCursosDiaHora;
class CQSisCostoCurso;
class CQSisPedidoMaterial;
/*!
 * \brief Operaciones que se deberan ejecutar
 *
 */
class CQSis3QtOperaciones:public SiscomOperaciones3 
{
public:
	/*!
	 * \brief Constructor de la clase, se conectara al servidor <br>
	 * pSisDatCom
	 * \param pSisDatCom Datos de comunicacion con el servidor
	 */
	CQSis3QtOperaciones(SiscomDatCom *pSisDatCom);
	/*!
	 * \brief Ejecuta la consulta del historico de compras  <br>
	 * del producto pchrPtrProducto, en el expendio pchrPtrExpendio<br>
	 * la informacion resultante se regresa en pSRegistro3Lst
	 * \param[in] pchrPtrProducto Clave del producto 
	 * \param[in] pchrPtrExpendio Id del expendio
	 * \param[out] pSRegistro3Lst Resultado de la consulta
	 */
	void HistoricoCompras(const char *pchrPtrProducto,
			      const char *pchrPtrExpendio,
			      const char *pchrPtrFechaRefVentas,
			      SiscomRegistro3Lst *pSRegistro3Lst);
	/*!
	 * Ejecuta la consulta de los productos cuyo porcentaje de  <br>
	 * existencia minimo sea mayor o igual pchrPtrPExisMinBajo <br>
	 * y el porcentaje de existencia minima alto sea menor     <br>
	 * pchrPtrPExisMinAlto, y que correspondan al expendio     <br>
	 * pchrPtrExpendio
	 * \param[in] pchrPtrPExisMinBajo Porcentaje de existencia <br>
	 * minimo bajo
	 * \param[in] pchrPtrPExisMinAlto Porcentaje de existencia <br>
	 * minimo alto.
	 * \param[in] pchrPtrExpendio Expendio
	 * \param[out] pSRegsitros3Lst Resultado de la consulta
	 */
	void HistoricoCompras(const char *pchrPtrPExisMinBajo,
			      const char *pchrPtrPExisMinAlto,
			      const char *pchrPtrExpendio,
			      const char *pchrPtrFechaRefVentas,
			      SiscomRegistro3Lst *pSRegistros3Lst);

	void RegistraSueldo(CQSisSueldo *pCQSSueldo);

	void AlumnosExpendio(const char *pchrPtrIdExpendio,
			     SiscomRegistro3Lst *pSRegistro3Lst);

	void MotivoInventario(const char *pchrPtrIdExpendio,
			       SiscomRegistro3Lst *pSRegistro3Lst);
	void ReportePorExistenciaMinima(const char *pchrPtrIdExpendio,
					SiscomRegistro3Lst *pSisReg3LstReporte);
	void ExistenciasProductos(const char *pchrPtrIdExpendio,
				  const char *pchrPtrCveProducto,
				  SiscomRegistro3Lst *pSisReg3LstReporte);
	void ExistenciasProductosPorCasiClave(const char *pchrPtrIdExpendio,
				  const char *pchrPtrCveProducto,
				  SiscomRegistro3Lst *pSisReg3LstReporte);
	void ExistenciaProductoBodega(const char *pchrPtrIdExpendio,
				      SiscomRegistro3 *pSisReg3Bodega,
				      SiscomRegistro3 *pSisReg3Producto,
				      SiscomRegistro3Lst *pSisReg3LstProducto);
	/*
	 * Este reporte se integra al de las existencias minimas, para poder 
	 * tener la informacion de los productos, que se pueden transferir de la
	 * bodega al expendio
	 *
	 */
	void ExistenciasProductosBodega(const char *pchrPtrIdExpendio,
					SiscomRegistro3Lst *pSisReg3LstRegreso);
	void TransfiereMaterialBodegaExpendio(SiscomRegistro3Lst *pSisReg3LstTrans,
					      SiscomRegistro3Lst *pSisReg3LstRegreso);
	void InventarioBodegaSiscom(SiscomRegistro3 *pSisReg3ProdInvBod);
	void Clientes(const char *pchrPtrIdExpendio,
		      SiscomRegistro3Lst *pSisReg3LstClientes);
	void RegistraClienteFisica(SiscomRegistro3 *pSisReg3Cliente);
	void RegistraClienteMoral(SiscomRegistro3 *pSisReg3Cliente);
	void OrdenesParaFacturar(SiscomRegistro3Lst *pSisReg3LstOrdenes,
				SiscomRegistro3Lst *pSisReg3LstProductos,
				SiscomRegistro3Lst *pSisReg3LstProductosO);
	void SincronizaExpendio(const char *pchrPtrIdExpendio,
				const char *pchrPtrOperacion,
				SiscomRegistro3Lst *pSisReg3LstRegreso);

	void ExistenciasExpendio(const char *pchrPtrIdExpendio,
				 SiscomRegistro3Lst *pSisReg3LstProducto);
	void ProductosPorcentajeExistenciaMinima(const char *pchrPtrIdExpendio,
						 const char *pchrPtrBajo,
						 const char *pchrPtrAlgo,
						 SiscomRegistro3Lst *pSisReg3LstRegreso);
	void Cursos(SiscomRegistro3Lst *pSisReg3LstCursos);
	void FechasCostosCursos(const char *pchrPtrIdExpendio,
			  const char *pchrPtrIdCurso,
			  SiscomRegistro4 *pSisReg4FechasCurso);
	void FechasCursos(const char *pchrPtrIdCurso,
			 SiscomRegistro3Lst *pSisReg3LstFechasCursos);
	void CostosCurso(const char *pchrPtrIdExpendio,
			  SiscomRegistro3 *pSisReg3FechaCurso,
			  SiscomRegistro3Lst *pSisReg3LstCostoCurso);
	void CostosCurso(const char *pchrPtrIdProgramacion,
			 const char *pchrPtrIdCurso,
			  SiscomRegistro3Lst *pSisReg3LstCostoCurso);
			  
	void AlumnosInscritosCurso(const char *pchrPtrIdCurso,
				   const char *pchrPtrFecha,
				   SiscomRegistro3Lst *pSisReg3LstAlumnosInscritos);
	void DisponibilidadCursos(const char *pchrPtrFecha,
				  SiscomRegistro3Lst *pSisReg3LstCursos);
	void VentasCursos(const char *pchrPtrFecha,
			  SiscomRegistro3Lst *pSisReg3LstVentasCursos);
	void Servicios(SiscomRegistro3Lst *pSisReg3LstServicios);
	SiscomRegistro3 *RegistraAlumnoServicioHoraEntrada(const char *pchrPtrIdExpendio,
				    SiscomRegistro3 *pSisReg3Servicio,
				    SiscomRegistro3 *pSisReg3Alumno,
				    const char *pchrPtrComentarios);

	void ServiciosSinRegistroSalida(const char *pchrPtrFecha,
					       const char *pchrPtrIdExpendio,
					       SiscomRegistro3Lst *pSisReg3LstAlumnos);
	
	void RegistraSalidaAlumno(const char *pchrPtrIdExpendio,
				  const char *pchrPtrIdServicio);

	
	void ProductosEnMatrizNoExpendio(const char *pchrPtrIdExpendioR,
					 SiscomRegistro3Lst *pSisReg3LstProductos);	
	void SincronizaProductosExpendio(const char *pchrPtrIdExpendioR,
					 SiscomRegistro3Lst *pSisReg3LstProductos);	
	
	void CursosProgramados(SiscomRegistro3Lst *pSisReg3LstCursosProgs);
	void ExplicacionPromocion(SiscomRegistro3Lst *pSisReg3LstExPromocion);
	void OrigenCompra(SiscomRegistro3Lst *pSisReg3LstExPromocion);
	void EstadisticasSemanalesVentas(const char *pchrPtrIdExpendio,
					 const char *pchrPtrAno,
					 const char *pchrPtrIdEscuela,
					 SiscomRegistro4 *pSisReg4Regreso);
	void RegistraProgramacionCursos(const char *pchrPtrIdExpendio,
					const char *pchrPtrProgramacion);

	void CursosProgramadosFechaRegistro(const char *pchrPtrFechaInicio,
					    const char *pchrPtrHoraInicio,
					    const char *pchrPtrHoraFin,
					    const char *pchrPtrIdCurso,
					    const char *pchrPtrIdProgramacion,
					    const char *pchrPtrCurso,
					    CQSisCursosDiaHora *pCQSisCuDiaHora);
	void CursosProgramados(const char *pchrPtrFechaInicio,
			       CQSisCursosDiaHora *pCQSisCuDiaHora);
				
	void ProgramaCurso(const char *pchrPtrIdProgramacion,
			   const char *pchrPtrIdCurso,
			   const char *pchrPtrFechaInicio);
	void CostosCurso(CQSisCostoCurso *pCQSCsCurso);

	void ReEnviaTransferencia(SiscomRegistro3 *pSiscomRegProTra);
	void ImprimePedido(const char *);
	void ClavesProveedor(const char *pchrPtrCveProducto,
			     SiscomRegistro4 *pSisReg4Claves);
	void ActualizaClaveProveedor(const char *pchrPtrIdExpendio,
				     const char *pchrPtrIdProveedor,
				     const char *pchrPtrCveProveedor,
				     const char *pchrPtrCveProducto);
	private:
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SisReg3LstEnvio;
	SiscomRegistro3Lst SisReg3LstRegreso;
};

#endif
