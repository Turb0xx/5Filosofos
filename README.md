# Problema de los Filósofos

Este proyecto es una implementación del clásico problema de los filósofos, que es un ejemplo fundamental de sincronización en la programación concurrente. En este escenario, varios filósofos se sientan a una mesa y alternan entre pensar y comer, utilizando tenedores compartidos. El objetivo es evitar la inanición y las condiciones de carrera.

## Descripción del Proyecto

El programa simula la actividad de cinco filósofos que piensan y comen. Cada filósofo necesita dos tenedores para comer, y los tenedores están representados como mutexes. Para evitar que un filósofo se quede sin comida, se implementa un mecanismo de bloqueo que garantiza que cada filósofo pueda tomar los tenedores de manera segura. Además, se utiliza un mutex adicional para proteger el acceso al contador de comidas de cada filósofo.

### Problemas Abordados

- **Inanición**: Asegurarse de que todos los filósofos tengan la oportunidad de comer.
- **Condiciones de carrera**: Evitar que múltiples hilos accedan y modifiquen el mismo recurso (contador de comidas) al mismo tiempo.

## Requisitos

Para compilar y ejecutar este proyecto, necesitarás:

- Un compilador de C++ (como g++, clang++, etc.)
- C++11 o superior para las características de hilos y mutexes.

## Compilación

Para compilar el programa, abre una terminal y navega al directorio donde se encuentra el archivo de código fuente. Luego, utiliza el siguiente comando:

```bash
g++ -std=c++11 -o filosofos filosofos.cpp -lpthread
