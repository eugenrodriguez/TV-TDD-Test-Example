#include "TestEvaluator.hpp"
#include <iostream>
#include <string>

class Television
{
public:
    Television() : on(false), channel(1), volume(10) {}

    void turnOnTurnOff();
    bool isOn() const;
    void changeChannel(int newChannel);
    int getChannel() const;
    void setVolume(int newVolume);
    int getVolume() const;

private:
    bool on;
    int channel;
    int volume;
};

void Television::turnOnTurnOff()
{
    on = !on;
}

bool Television::isOn() const
{
    return on;
}

void Television::changeChannel(int newChannel)
{
    if (on && newChannel >= 1 && newChannel <= 100)
    {
        channel = newChannel;
    }
}

int Television::getChannel() const
{
    return channel;
}

void Television::setVolume(int newVolume)
{
    if (on && newVolume >= 0 && newVolume <= 100)
    {
        volume = newVolume;
    }
}

int Television::getVolume() const
{
    return volume;
}

void testTurnOnTurnOffTV(TestEvaluator &te)
{
    Television tv;
    tv.turnOnTurnOff();
    te.evaluate("Encender televisión", tv.isOn() == true);

    tv.turnOnTurnOff();
    te.evaluate("Apagar televisión", tv.isOn() == false);
}

void testChangeChannelWhenOn(TestEvaluator &te)
{
    Television tv;
    tv.turnOnTurnOff();
    tv.changeChannel(5);
    te.evaluate("Cambiar al canal 5 cuando está encendida", tv.getChannel() == 5);
}

void testChangeChannelWhenOff(TestEvaluator &te)
{
    Television tv;
    tv.turnOnTurnOff();
    tv.changeChannel(5);
    tv.turnOnTurnOff();
    tv.changeChannel(10);
    te.evaluate("No cambia de canal si está apagada", tv.getChannel() == 5);
}

void testSetVolumeWhenOn(TestEvaluator &te)
{
    Television tv;
    tv.turnOnTurnOff();
    tv.setVolume(25);
    te.evaluate("Ajustar volumen a 25 cuando está encendida", tv.getVolume() == 25);
}

void testSetVolumeWhenOff(TestEvaluator &te)
{
    Television tv;
    tv.turnOnTurnOff();
    tv.setVolume(25);
    tv.turnOnTurnOff();
    tv.setVolume(50);
    te.evaluate("No cambia volumen si está apagada", tv.getVolume() == 25);
}

void executeTVTest(TestEvaluator &te)
{
    te.title("Test de la clase Television");

    testTurnOnTurnOffTV(te);
    testChangeChannelWhenOn(te);
    testChangeChannelWhenOff(te);
    testSetVolumeWhenOn(te);
    testSetVolumeWhenOff(te);
}

int main()
{
    TestEvaluator te;
    executeTVTest(te);
    te.summary();
    return 0;
}
