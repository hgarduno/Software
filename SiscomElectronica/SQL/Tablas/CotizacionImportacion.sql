create table CotizacionImportacion(IdCotizacionImportacion integer unique,
				   IdProveedor integer references Empresas(IdEmpresa),
				   Cotizacion varchar(255),
				   CostoDolar numeric(8,3),
				   PesoTotal  numeric(11,3),
				   ImporteCotizacion numeric(13,3));


create table DetalleCotizacionImportacion(NumeroProducto serial,
					  IdCotizacion integer 
					    references CotizacionImportacion(IdCotizacionImportacion),
					  CveProducto varchar(50) references Productos(CveProducto),
					  Cantidad numeric(11,3),
					  Precio numeric(11,3),
					  PesoTotal numeric(11,3),
					  Importe	numeric(11,3),
					  primary key(CveProducto));


create table TotalesCotizacionImportacion(IdCotizacion integer references CotizacionImportacion(IdCotizacionImportacion),
					  Peso numeric(12,4),
					  Importe numeric(12,4));
