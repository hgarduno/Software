create table HistorialExistencias(
		CveProducto varchar(25),
		Existencia numeric(10,2),
		IdExpendio integer references empresas(IdEmpresa),
		Fecha timestamp without time zone);
		
