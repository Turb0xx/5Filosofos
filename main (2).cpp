#include <iostream> 
#include <thread> //Para manejar hilos 
#include <mutex>//Para usar mutexes para la sincronización
#include <vector>//Para usar vector
#include <chrono>//Para manejar tiempos
#include <random>//Para generar números aleatorios

using namespace std;

//Constantes
const int NUM_FILOSOFOS = 5; //Numero de filosofos
const int TIEMPO_PENSANDO_MAX = 2000; //Tiempo maximo que un filosofo puede pensar (milisegundos)
const int TIEMPO_COMIENDO_MAX = 1000; //Tiempo máximo que un filósofo puede comer (milisegundos)

//Arreglo de mutexes para representar los tenedores
mutex tenedores[NUM_FILOSOFOS]; 
//Contador de comidas para cada filosofo
int comidas[NUM_FILOSOFOS]; 
//Mutex para proteger el acceso a los contadores de comidas
mutex mutex_comidas[NUM_FILOSOFOS];

//Función que simula la actividad de un filosofo
void filosofo(int id) 
{
//Generador y distribuciones aleatorias para simular el tiempo de pensar y comer
    default_random_engine generator;
    uniform_int_distribution<int> pensar_dist(0, TIEMPO_PENSANDO_MAX);
    uniform_int_distribution<int> comer_dist(0, TIEMPO_COMIENDO_MAX);

    while (true) 
    {
        //Simular el tiempo que el filósofo pasa pensando
        cout<< "Filosofo " <<id + 1<< " esta pensando." <<endl;
        this_thread::sleep_for(chrono::milliseconds(pensar_dist(generator)));

        //Intentar tomar los tenedores
        cout<< "Filosofo " << id + 1 << " esta esperando por un tenedor." <<endl;

    //Toma el tenedor izquierdo 
        tenedores[id].lock();
    //Toma el tenedor derecho 
        tenedores[(id + 1) % NUM_FILOSOFOS].lock();

    //Comer
cout<< "Filosofo " << id + 1 << " esta comiendo." <<endl;

    //Proteger el acceso al contador de comidas con un mutex
        mutex_comidas[id].lock(); //Bloquear el mutex correspondiente al filosofo
        comidas[id]++; //Incrementar el contador de comidas
        mutex_comidas[id].unlock(); //Desbloquear el mutex

this_thread::sleep_for(chrono::milliseconds(comer_dist(generator)));

        //Dejar los tenedores
        tenedores[(id + 1) % NUM_FILOSOFOS].unlock();              //Dejar el tenedor derecho
        tenedores[id].unlock(); //Dejar el tenedor izquierdo
    }
}

int main() 
{
    vector<thread> filosofos; //Vector para almacenar los hilos de los filósofos

    //Inicializar contadores de comidas a 0
    for (int i = 0; i < NUM_FILOSOFOS; i++) {
        comidas[i] = 0;
    }

    // Crear hilos para cada filósofo
    for (int i = 0; i < NUM_FILOSOFOS; i++)
    {
        filosofos.push_back(thread(filosofo, i)); //Crear un hilo para cada filosofo
    }

    //Dejar que los filosofos coman durante un tiempo 
    this_thread::sleep_for(chrono::seconds(10));

    //Terminar la simulación
    for (auto& f : filosofos) 
    {
        f.detach(); //Desvincular hilos para que puedan seguir ejecutandose
    }

    //Mostrar estadisticas finales de cuántas veces comio cada filosofo
    cout<< "\nEstadisticas finales:\n";
    for (int i = 0; i < NUM_FILOSOFOS; i++) 
    {
    cout<< "Filosofo " << i + 1 << " comio " << comidas[i] << " veces." <<endl;
    }

    return 0; 
}