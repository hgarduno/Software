create table ProductoExpendioNoSincronizado(
		IdExpendio integer references empresas(idempresa),
		CveProducto varchar(25) references Productos(cveProducto));

create table Cancelacion(IdCancelacion integer primary key,
			 Fecha timestamp without time zone);


create table Cancelaciones(IdCancelacion integer references Cancelacion(IdCancelacion),
			   IdVenta integer);

				
