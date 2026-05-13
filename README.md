El presente proyecto consiste en el diseño e implementación de un Sistema Integral Interactivo desarrollado en lenguaje C++, diseñado específicamente para abordar desafíos lógicos y de procesamiento de datos en el ámbito académico. El aplicativo se estructura bajo el paradigma de la programación estructurada, priorizando la modularidad, la eficiencia y la experiencia del usuario.

Componentes Clave del Sistema:
Arquitectura de Control: Se ha implementado un motor de navegación basado en un ciclo do-while, garantizando que el usuario mantenga el control total del flujo del programa mediante un menú dinámico y validado.

Módulo de Aritmética Computacional: Incluye un procesador de operaciones básicas (suma, resta, multiplicación y división) con capas de validación lógica. Se ha implementado un control de excepciones manual para impedir la división por cero, asegurando la integridad del programa en tiempo de ejecución.

Módulo de Análisis Estadístico (Arreglos): Utiliza estructuras de almacenamiento unidimensionales para la gestión de calificaciones. El sistema realiza un procesamiento iterativo mediante acumuladores y contadores para extraer métricas críticas: promedio general, valores extremos (mínimo/máximo) y segmentación de rendimiento académico (aprobados/reprobados).

Persistencia de Datos (I/O): El sistema trasciende la memoria volátil mediante el uso de la biblioteca <fstream>, permitiendo la exportación de resultados a un archivo físico resultados.txt. Este archivo actúa como un registro histórico que documenta el autor, la marca de tiempo (timestamp) y los datos procesados.

Gestión de Versiones: El desarrollo fue administrado bajo un flujo de trabajo profesional en GitHub, cumpliendo con una estructura de directorios estandarizada y un historial de commits que evidencia el progreso incremental de la lógica de programación.
