#include "TestEvaluator.hpp"
#include <iostream>
#include <string>

// Declaración de la clase Television
class Television
{
public:
    Television() : encendida(false), canal(1), volumen(10) {}

    void encenderApagar();
    bool estaEncendida() const;
    void cambiarCanal(int nuevoCanal);
    int obtenerCanal() const;
    void ajustarVolumen(int nuevoVolumen);
    int obtenerVolumen() const;

private:
    bool encendida;
    int canal;
    int volumen;
};

// Implementación de los métodos de Television
void Television::encenderApagar()
{
    encendida = !encendida;
}

bool Television::estaEncendida() const
{
    return encendida;
}

void Television::cambiarCanal(int nuevoCanal)
{
    if (encendida && nuevoCanal >= 1 && nuevoCanal <= 100)
    {
        canal = nuevoCanal;
    }
}

int Television::obtenerCanal() const
{
    return canal;
}

void Television::ajustarVolumen(int nuevoVolumen)
{
    if (encendida && nuevoVolumen >= 0 && nuevoVolumen <= 100)
    {
        volumen = nuevoVolumen;
    }
}

int Television::obtenerVolumen() const
{
    return volumen;
}

// Funciones de prueba individuales

void testEncenderApagarTelevision(TestEvaluator &te)
{
    Television tv;
    tv.encenderApagar();
    te.evaluate("Encender televisión", tv.estaEncendida() == true);

    tv.encenderApagar();
    te.evaluate("Apagar televisión", tv.estaEncendida() == false);
}

void testCambiarCanalCuandoEncendida(TestEvaluator &te)
{
    Television tv;
    tv.encenderApagar(); // Encender la TV
    tv.cambiarCanal(5);
    te.evaluate("Cambiar al canal 5 cuando está encendida", tv.obtenerCanal() == 5);
}

void testCambiarCanalCuandoApagada(TestEvaluator &te)
{
    Television tv;
    tv.encenderApagar(); // Encender y luego apagar la TV
    tv.cambiarCanal(5);
    tv.encenderApagar(); // Apagar la TV
    tv.cambiarCanal(10);
    te.evaluate("No cambia de canal si está apagada", tv.obtenerCanal() == 5);
}

void testAjustarVolumenCuandoEncendida(TestEvaluator &te)
{
    Television tv;
    tv.encenderApagar(); // Encender la TV
    tv.ajustarVolumen(25);
    te.evaluate("Ajustar volumen a 25 cuando está encendida", tv.obtenerVolumen() == 25);
}

void testAjustarVolumenCuandoApagada(TestEvaluator &te)
{
    Television tv;
    tv.encenderApagar(); // Encender y luego apagar la TV
    tv.ajustarVolumen(25);
    tv.encenderApagar(); // Apagar la TV
    tv.ajustarVolumen(50);
    te.evaluate("No cambia volumen si está apagada", tv.obtenerVolumen() == 25);
}

// Función para ejecutar todas las pruebas
void ejecutarPruebasTelevision(TestEvaluator &te)
{
    te.title("Test de la clase Television");

    testEncenderApagarTelevision(te);
    testCambiarCanalCuandoEncendida(te);
    testCambiarCanalCuandoApagada(te);
    testAjustarVolumenCuandoEncendida(te);
    testAjustarVolumenCuandoApagada(te);
}

int main()
{
    TestEvaluator te;
    ejecutarPruebasTelevision(te);
    te.summary();
    return 0;
}
