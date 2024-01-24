drop table DetalleCompraImportacion;
drop table CompraImportacion;
create table CompraImportacion(IdCompraImportacion integer unique,
			       IdEmpresa integer references Empresas(IdEmpresa),
			       Fecha date,
			       NumeroFactura varchar(25),
			       ImporteFactura numeric(10,3),
			       CostoEnvioDolares numeric(10,3),
			       CostoDolar numeric(8,3),
			       CostoAdministrativo numeric(10,3),
			       PonderacionCostoAdministrativo numeric(10,3),
			       NumeroPartidas integer,
			       PesoCompra numeric(10,3),
			       primary key(IdEmpresa,Fecha));
create table DetalleCompraImportacion(IdCompraImportacion integer references CompraImportacion(IdCompraImportacion),
			       	      IdConsecutivo serial,
				      CveProducto varchar(50) references productos(cveproducto), 
				      cantidad int,
				      CostoUnitario numeric(10,5));
