# Act 2.3 - Actividad Integral estructura de datos lineales
## Correcciones de la actividad

- Lectura Archivo (10/10)

- Ordenar Datos (15/20): Quicksort no es un método eficiente para listas enlazas. Demora demasiado (-5)

- Busqueda Informacion (14/20): La búsqueda no es eficiente pues al buscar la posición de la ip final se vuelve a recorrer la lista y luego para imprimir los resultados otra vez. (-5) 
La búsqueda binaria implementada en la lista enlazada resulta menos eficiente que la secuencial (-1)

- Despliega Ascendente (10/20): El despliegue es demasiado ineficiente pues en lugar de ser lineal lo hacen de manera cudrática, ya que el getAt recorre la lista hasta llegar al indice especificado (-10) 
No es necesario dos fors, uno para imprimir en pantalla y otro para el archivo, se pudo realizar en uno solo (-0)

- Documento reflexión (14/20): Por qué si sabian que no era eficiente la búsqueda binaria en listas enlazadas, 
porqué decidieron implementarla? Además la complidad de la implementación que hicieron no es O(n) (-3)
La complejidad de quicksort no es nlogn en listas enlazadas (-3)

- Lineamientos (8/10): En el main claramente se debió usar un do while en lugar del while (-2)
