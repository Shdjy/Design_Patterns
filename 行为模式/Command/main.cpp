#include <iostream>

using namespace std;
//Ω” ’’ﬂ
class Light
{
public:
	void turnOn()
	{
		cout << "Light is on" << endl;
	}
	void turnOff()
	{
		cout << "Light is off" << endl;
	}
};

class Command
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class TurnOnCommand : public Command
{
private:
	Light* light;
public:
	TurnOnCommand(Light* light)
	{
		this->light = light;
	}
	void execute()
	{
		light->turnOn();
	}
	void undo()
	{
		light->turnOff();
	}
};

class TurnOffCommand : public Command
{
private:
	Light* light;
public:
	TurnOffCommand(Light* light)
	{
		this->light = light;
	}
	void execute()
	{
		light->turnOff();
	}
	void undo()
	{
		light->turnOn();
	}
};

int main()
{
	Light light;
	TurnOnCommand turnOn(&light);
	TurnOffCommand turnOff(&light);

	turnOn.execute();
	turnOff.execute();

	turnOn.undo();
	turnOff.undo();

	getchar();
	return 0;
}