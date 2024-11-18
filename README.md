# Problema de los Filosofos

Este proyecto es una implementacion del clasico problema de los filosofos, que es un ejemplo fundamental de sincronizacion en la programacion concurrente. En este escenario, varios filosofos se sientan a una mesa y alternan entre pensar y comer, utilizando tenedores compartidos. El objetivo es evitar la inanición y las condiciones de carrera.

## Descripcion del Proyecto

El programa simula la actividad de cinco filosofos que piensan y comen. Cada filosofo necesita dos tenedores para comer, y los tenedores estan representados como mutexes. Para evitar que un filosofo se quede sin comida, se implementa un mecanismo de bloqueo que garantiza que cada filosofo pueda tomar los tenedores de manera segura. Ademas, se utiliza un mutex adicional para proteger el acceso al contador de comidas de cada filosofo.

### Problemas Abordados

- **Inanicion**: Asegurarse de que todos los filosofos tengan la oportunidad de comer.
- **Condiciones de carrera**: Evitar que multiples hilos accedan y modifiquen el mismo recurso (contador de comidas) al mismo tiempo.

## Requisitos

Para compilar y ejecutar se necesita:

- Un compilador de C++ 
- C++11 o superior para las características de hilos y mutexes.

## Compilación

Para compilar el programa, abre una terminal y navega al directorio donde se encuentra el archivo de código fuente. Luego, utiliza el siguiente comando:

```bash
g++ -std=c++11 -o filosofos filosofos.cpp -lpthread
