create table if not exists PesoProducto(CveProducto varchar(50) unique ,Peso numeric(6,2));

--- Miercoles 6 Febrero 2019 



create table if not exists Importaciones(IdImportacion integer unique,
				 	 IdEmpresa integer references Empresas(IdEmpresa),
					 Fecha timestamp without time zone,
					 Descripcion text);


-- El Precio es en dolares 
--  
create table if not exists CotizacionImportacion(
				IdCotizacionImportacion  integer unique,
				IdImportacion integer references Importaciones(IdImportacion),
				CveProducto varchar(50) references Productos(cveproducto),
				Cantidad float,
				Precio float ,
				primary key(IdCotizacionImportacion,IdImportacion));

create table if not exists 
		DescripcionCotizacionImportacion(
		IdCotizacionImportacion integer references CotizacionImportacion(IdCotizacionImportacion),
		Descripcion text);




