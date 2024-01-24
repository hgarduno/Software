create table DescripcionCompraImportacion(IdCompraImportacion integer references 
					  CompraImportacion(IdCompraImportacion),
					  Descripcion text);
