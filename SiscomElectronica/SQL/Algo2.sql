--SELECT  a.cveProducto,                                          
--        c.DscProducto,                                          
--	b.Existencia,                                           
--	d.exbodegas,
--	a.Precio                                                
--from precios as a                                       
--     left outer join existencias as b using (cveProducto)    
--     inner join productos as c using(CveProducto) 
--     inner join existenciaexpendiobodegas as d on (a.CveProducto=d.cveproducto and 
--                                                   b.idexpendio=d.idexpendio)
--where NmbTipoPrecio='DEFAULT' and 
--      b.idExpendio=-1165857915          and 
--      a.CveProducto in('74LS00')
--

SELECT  a.cveProducto,                                          
        c.DscProducto,                                          
	        b.Existencia,                                           
		        d.exbodegas,                                            
			        a.Precio                                                
				        from precios as a                                       
					        left outer join existencias as b using (cveProducto)    
						        inner join productos as c using(CveProducto)            
							        inner join existenciaexpendiobodegas as d on            
								                    (a.CveProducto=d.cveproducto and            
										                         b.idexpendio=d.idexpendio) where NmbTipoPrecio='DEFAULT' and 
													                        idExpendio=-1165857915          and 
																                       a.CveProducto in('74LS00')


