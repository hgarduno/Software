insert into TiposPersona values(0,'Administradores','Administradores');
insert into TiposPersona values(1,'Ventas','Ventas');



insert into Menus values(0,'QAProveedores','QtImpProveedores');
--insert into Menus values(1,'QACapturaProductos','QtImpCapturaProductos');
insert into Menus values(1,'QAMantenimientoProductos','QtImpMantenimientoProductos');
insert into Menus values(2,'QAActualizaStock','QtImpActualizaStock');
insert into Menus values(3,'QARegistroCompras','QtImpRegistroCompras');
insert into Menus values(4,'QATransferenciaAlmacen','QtImpTransferenciaAlmacen');
insert into Menus values(5,'QAPuntoDeVenta','QtImpPuntoDeVenta');
insert into Menus values(6,'QARepPreciosProducto','QtImpRepPreciosProducto');
insert into Menus values(7,'QARepListaPreciosComprador','QtImpRepListaPreciosComprador');
insert into Menus values(8,'QARepStockProveedorCosto','QtImpRepStockProveedorCosto');
insert into Menus values(9,'QARepStockTienda','QtImpRepStockTienda');
insert into Menus values(10,'QARepExistenciaProveedor','QtImpRepExistenciaProveedor');
insert into Menus values(11,'QASoporteCompras','QtImpSoporteCompras');
insert into Menus values(12,'QASoporteVentas','QtImpSoporteVentas');
insert into Menus values(13,'QASoporteTransferencias','QtImpSoporteTransferencias');
insert into Menus values(14,'QARegistroInventario','QtImpRegistroInventario');
insert into Menus values(15,'QADiferenciasInventario','QtImpDiferenciasInventario');
insert into Menus values(16,'QARegistroLibro','QtImpRegistroLibro');
insert into Menus values(17,'QAPagosDocumentosPagar','QtImpPagosDocumentosPagar');


insert into Menus values(-1,'QPopupTiendas');
insert into Menus values(-2,'QPopupReportes');
insert into Menus values(-3,'QPopupInventarios');
insert into Menus values(-4,'QPopupCuentas');



insert into PropiedadesMenu values(0,'text');
insert into PropiedadesMenu values(1,'visible');
insert into PropiedadesMenu values(2,'enabled');


insert into PopupMenu values(-1);
insert into PopupMenu values(-2);
insert into PopupMenu values(-3);
insert into PopupMenu values(-4);

insert into PopupMenuMenu values(-1,0);
insert into PopupMenuMenu values(-1,1);
insert into PopupMenuMenu values(-1,2);
insert into PopupMenuMenu values(-1,3);
insert into PopupMenuMenu values(-1,4);
insert into PopupMenuMenu values(-1,5);
insert into PopupMenuMenu values(-1,7);
insert into PopupMenuMenu values(-1,8);

insert into PopupMenuMenu values(-2,6);
insert into PopupMenuMenu values(-2,9);
insert into PopupMenuMenu values(-2,10);
insert into PopupMenuMenu values(-2,11);
insert into PopupMenuMenu values(-2,12);
insert into PopupMenuMenu values(-2,13);

insert into PopupMenuMenu values(-3,14);
insert into PopupMenuMenu values(-3,15);

insert into PopupMenuMenu values(-4,16);
insert into PopupMenuMenu values(-4,17);

insert into MenusPropiedades values(-1,0,0,'Tienda');
insert into MenusPropiedades values(-1,0,1,'true');
insert into MenusPropiedades values(-1,0,2,'true');
insert into MenusPropiedades values(-2,0,0,'Reportes');
insert into MenusPropiedades values(-2,0,1,'true');
insert into MenusPropiedades values(-2,0,2,'true');
insert into MenusPropiedades values(-3,0,0,'Inventarios');
insert into MenusPropiedades values(-3,0,1,'true');
insert into MenusPropiedades values(-3,0,2,'true');
insert into MenusPropiedades values(-4,0,0,'Cuentas');
insert into MenusPropiedades values(-4,0,1,'true');

insert into MenusPropiedades values(0,0,0,'Proveedores');
insert into MenusPropiedades values(0,0,1,'true');
insert into MenusPropiedades values(0,0,2,'true');
insert into MenusPropiedades values(1,0,0,'Productos');
insert into MenusPropiedades values(1,0,1,'true');
insert into MenusPropiedades values(1,0,2,'true');
insert into MenusPropiedades values(2,0,0,'Mantenimiento Stock');
insert into MenusPropiedades values(2,0,1,'true');
insert into MenusPropiedades values(2,0,2,'true');
insert into MenusPropiedades values(3,0,0,'Compras');
insert into MenusPropiedades values(3,0,1,'true');
insert into MenusPropiedades values(3,0,2,'true');
insert into MenusPropiedades values(4,0,0,'Transferencias');
insert into MenusPropiedades values(4,0,1,'true');
insert into MenusPropiedades values(4,0,2,'true');
insert into MenusPropiedades values(5,0,0,'Punto de Venta');
insert into MenusPropiedades values(5,0,1,'true');
insert into MenusPropiedades values(5,0,2,'true');
insert into MenusPropiedades values(6,0,0,'Biblia Por Tienda');
insert into MenusPropiedades values(6,0,1,'true');
insert into MenusPropiedades values(6,0,2,'true');
insert into MenusPropiedades values(7,0,0,'Lista de Precios Compradores');
insert into MenusPropiedades values(7,0,1,'true');
insert into MenusPropiedades values(7,0,2,'true');
insert into MenusPropiedades values(8,0,0,'Stock Por Proveedor');
insert into MenusPropiedades values(8,0,1,'true');
insert into MenusPropiedades values(8,0,2,'true');
insert into MenusPropiedades values(9,0,0,'Reporte Stock Por Tienda');
insert into MenusPropiedades values(9,0,1,'true');
insert into MenusPropiedades values(9,0,2,'true');
insert into MenusPropiedades values(10,0,0,'Existencia por Proveedor');
insert into MenusPropiedades values(10,0,1,'true');
insert into MenusPropiedades values(10,0,2,'true');
insert into MenusPropiedades values(11,0,0,'Soporte Compras');
insert into MenusPropiedades values(11,0,1,'true');
insert into MenusPropiedades values(11,0,2,'true');
insert into MenusPropiedades values(12,0,0,'Soporte Ventas');
insert into MenusPropiedades values(12,0,1,'true');
insert into MenusPropiedades values(12,0,2,'true');
insert into MenusPropiedades values(13,0,0,'Soporte Transferencias');
insert into MenusPropiedades values(13,0,1,'true');
insert into MenusPropiedades values(13,0,2,'true');
insert into MenusPropiedades values(14,0,0,'Programacion Inventario en una Tienda');
insert into MenusPropiedades values(14,0,1,'true');
insert into MenusPropiedades values(14,0,2,'true');
insert into MenusPropiedades values(15,0,0,'Diferencias Inventorias');
insert into MenusPropiedades values(15,0,1,'true');
insert into MenusPropiedades values(15,0,2,'true');
insert into MenusPropiedades values(16,0,0,'Registro Libro');
insert into MenusPropiedades values(16,0,1,'true');
insert into MenusPropiedades values(16,0,2,'true');
insert into MenusPropiedades values(17,0,0,'Registro de Pagos ');
insert into MenusPropiedades values(17,0,1,'true');
insert into MenusPropiedades values(17,0,2,'true');
