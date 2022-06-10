// Funciones:

// fopen (Abrir archivo).
// fwrite (Escribir archivo).
// rewind.
// fread (Lee el archivo).
// fclose (Cierra el archivo).

// ____________________________________________________________________________________________________________________________________________________________________

// Modos de apertura:

    //  rb -> read en binario.
    //  wb -> write en binario.
    //  w + b -> Crea un archivo vacio en binario, para poder escribir y leer.
    //  r + b -> Abre un archivo en binario, para poder escribir y leer.

// ____________________________________________________________________________________________________________________________________________________________________

// Formas de fwrite y fread:

    // fwrite:

        // size_t fwrite ( const void * restrict buffer, size_t size, size_t count, FILE * restrict stream ) ; 
        //		  fwrite (       fuentedeDatos         ,       size ,   count     ,      archivo           ) ; 

    // fread:

        // size_t fread  ( void * restrict buffer, size_t size, size_t count, FILE * restrict stream ) ; 
		//	      fread (      destinodeDatos   ,       size ,   count     ,      archivo           ) ; 

    // Size es el tamanio de lo que queres leer o escribir, y count es cuantas veces queres "trabajar" ese tamanio. Ejemplo: size: 50bytes, count: 2. Total: 100bytes.

// ____________________________________________________________________________________________________________________________________________________________________

