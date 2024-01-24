create table ProveedoresCompraImportacion(
        IdProveedor serial,
	IdCompraImportacion integer references CompraImportacion(IdCompraImportacion),
	IdEmpresa integer);
					
