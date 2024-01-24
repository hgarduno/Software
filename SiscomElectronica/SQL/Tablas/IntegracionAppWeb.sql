create table PreciosSucursal(cveproducto	varchar(25),
			     idpersona		integer,
			     idempresa		integer references empresas(idempresa),
			     nmbtipoprecio	varchar(25),
			     precio		numeric(10,2),
			     idexpendio		integer references empresas(idempresa),
			     primary key(CveProducto,idpersona,nmbtipoprecio),
			     foreign key(CveProducto,idpersona,nmbtipoprecio) references Precios(CveProducto,IdPersona,nmbtipoprecio));

