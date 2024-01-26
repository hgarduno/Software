create table Compras(IdCompra integer unique,
		     IdEmpresa integer references Empresas(IdEmpresa),
		     IdTipoDocumento integer references TipoDocumentos(IdTipoDocumento),
		     IdConceptosExistencias integer references ConceptosExistencias(IdConceptosExistencias),
		     SerieFactura  varchar(25),
		     Folio 	integer,
		     Fecha date);

create table ImporteCompra(IdCompra integer references Compras(IdCompra) unique,
			   Subtotal numeric(12,2),
			   Iva numeric(12,2),
			   Total numeric(12,2));

create table EstatusCompra(IdCompra integer references Compras(IdCompra),
			   IdEstatus integer references Estatus(IdEstatus));

create table DetalleCompras(IdCompra integer references Compras(IdCompra),
			    IdProducto integer references Productos(IdProducto),
			    Serie	varchar(128),
			    cantidad integer,
			    PrecioCompra numeric(12,2),
			    IvaCompra	numeric(12,2),
			    Total	numeric(12,2));


