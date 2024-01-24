create table ProductoProveedorImportacion(
			IdCompraImportacion integer references CompraImportacion(IdCompraImportacion),
			IdProveedor integer references Empresas(IdEmpresa),
			cveproducto varchar(250) references Productos(CveProducto));

create table ProveedoresCompraImportacion(
        IdProveedor serial,
	IdCompraImportacion integer references CompraImportacion(IdCompraImportacion),
	IdEmpresa integer);
					
