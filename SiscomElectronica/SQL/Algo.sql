select a.*,
               c.idtipoproducto,
               b.importe as importeorden, 
               d.existencia,
               a.edoventa as idtipoorden,
               f.nombre as escuela,
               f.idescuela,
               h.*,
               i.*,
               k.telefono as telefonotra,
               k.sereflejo,
               k.observaciones
        from ventas as a  left outer join 
             cotizacion as j using(idventa) left outer join
             pagotransferencia as k using(idventa)  left outer join
             importeorden as b using(idventa) left outer join
             productoportipoproducto as c using(cveproducto) inner join
             existencias as d using(cveproducto) inner join
             escuelaorden as e using(idventa)    inner join 
             escuelas as f using(idescuela)      inner join
             ordencliente as g using(idventa)    inner join
             personas as h using(idpersona)      left outer join
             telefonos as i on (h.idpersona=i.idpersona and 
                                i.departamenteo='Celular')
            where a.idventa in ( select idventa 
                              from datospedido
                              where fechaentrega::date>='2024-04-11' and 
                                    fechaentrega::date<='2024-04-11')
        order by a.fechahora desc,
                 a.idconsecutivo asc

