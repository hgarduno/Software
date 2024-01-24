alter table estadospedidocliente drop column fecha;
alter table pedidocliente add column fecha timestamp without time zone;

alter table direccionentrega drop constraint direccionentrega_pkey;
alter table direccionentrega drop constraint direccionentrega_idventa_fkey ;
alter table estadospedidocliente drop constraint estadospedidocliente_idventa_fkey;


alter table direcciones add column iddireccion integer ;
