#include <iostream>

using namespace std;

class Device;
class Sound;
class TV;

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class TurnOnCommand : public Command
{
private:
    Device &device;

public:
    TurnOnCommand(Device &dev);

    void execute() override;
};

class TurnOffCommand : public Command
{
private:
    Device &device;

public:
    TurnOffCommand(Device &dev);

    void execute() override;
};

class AdjustVolumeCommand : public Command
{
private:
    Sound &sound;

public:
    AdjustVolumeCommand(Sound &s);

    void execute() override;
};

class ChangeChannelCommand : public Command
{
private:
    TV &tv;

public:
    ChangeChannelCommand(TV &t);

    void execute() override;
};

class Device
{
public:
    virtual ~Device() {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class TV : public Device
{
public:
    void turnOn() override
    {
        cout << "TV is now on" << endl;
    }

    void turnOff() override
    {
        cout << "TV is now off" << endl;
    }

    void changeChannel()
    {
        cout << "Channel changed" << endl;
    }
};

class Sound : public Device
{
public:
    void turnOn() override
    {
        cout << "Sound is now on" << endl;
    }

    void turnOff() override
    {
        cout << "Sound is now off" << endl;
    }

    void adjustVolume()
    {
        cout << "Volume adjusted" << endl;
    }
};

class RemoteControl
{
private:
    Command *command;

public:
    RemoteControl() : command(nullptr) {}

    void setCommand(Command *cmd)
    {
        command = cmd;
    }

    void pressButton()
    {
        if (command)
            command->execute();
    }
};

TurnOnCommand::TurnOnCommand(Device &dev) : device(dev) {}

void TurnOnCommand::execute()
{
    device.turnOn();
}

TurnOffCommand::TurnOffCommand(Device &dev) : device(dev) {}

void TurnOffCommand::execute()
{
    device.turnOff();
}

AdjustVolumeCommand::AdjustVolumeCommand(Sound &s) : sound(s) {}

void AdjustVolumeCommand::execute()
{
    sound.adjustVolume();
}

ChangeChannelCommand::ChangeChannelCommand(TV &t) : tv(t) {}

void ChangeChannelCommand::execute()
{
    tv.changeChannel();
}

int main()
{

    TV tv;
    Sound sound;

    TurnOnCommand turnOnTVCommand(tv);
    TurnOffCommand turnOffTVCommand(tv);
    AdjustVolumeCommand adjustVolumeSoundCommand(sound);
    ChangeChannelCommand changeChannelTVCommand(tv);

    RemoteControl remote;

    remote.setCommand(&turnOnTVCommand);
    remote.pressButton();

    remote.setCommand(&adjustVolumeSoundCommand);
    remote.pressButton();

    remote.setCommand(&changeChannelTVCommand);
    remote.pressButton();

    remote.setCommand(&turnOffTVCommand);
    remote.pressButton();

    return 0;
}
