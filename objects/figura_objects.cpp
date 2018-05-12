#include "../geometry/geo.cpp"


// Arreglos con la ruta de los archivos de textura
char tile1_dif [] = { 'a','\0'};


// Figuras texturisadas
figura BigTable( coord_BigTable, quads_BigTable, trng_BigTable, n_vertex_BigTable, t_vertex_BigTable, tile1_dif);

// Figuras con color sOlido
//figura toilet( coord_toilet, quads_toilet, trng_toilet, n_vertex_toilet);
//figura chair( coord_chair, quads_chair, trng_chair, n_vertex_chair);
//figura sink( coord_sink, quads_sink, trng_sink, n_vertex_sink);
