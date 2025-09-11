#include <iostream>
#include <memory.h>

using namespace std;

class Mediator;

class Control
{
public:
	Control(Mediator* mediator)
	{
		this->mediator = mediator;
	}
	virtual void Send(string message) = 0;
	virtual void Receive(string message) = 0;
	virtual ~Control() {}
protected:
	Mediator* mediator;
};

class Mediator
{
public:
	virtual void Notify(Control* control, string message) = 0;
	virtual ~Mediator() {}
};

class Button : public Control
{
public:
	Button(Mediator* mediator) : Control(mediator) {}
	void Send(string message)
	{
		cout << "Button: " << message << endl;
		mediator->Notify(this, message);
	}
	void Receive(string message)
	{
		cout << "Button received: " << message << endl;
	}
};

class TextBox : public Control
{
public:
	TextBox(Mediator* mediator) : Control(mediator) {}
	void Send(string message)
	{
		cout << "TextBox: " << message << endl;
		mediator->Notify(this, message);
	}
	void Receive(string message)
	{
		cout << "TextBox received: " << message << endl;
	}
};

class ConcreteMediator : public Mediator
{
private:
	Button* button;
	TextBox* textBox;
public:
	ConcreteMediator() {}
	void SetButton(Button* button) { this->button = button; }
	void SetTextBox(TextBox* textBox) { this->textBox = textBox; }
	void Notify(Control* control, string message)
	{
		if (control == button)
		{
			textBox->Receive(message);
		}
		else if (control == textBox)
		{
			button->Receive(message);
		}
	}
};

int main()
{
	ConcreteMediator mediator;

	Button buttont(&mediator);
	TextBox textbox(&mediator);
	mediator.SetButton(&buttont);
	mediator.SetTextBox(&textbox);

	buttont.Send("Hello");
	textbox.Send("World");

	getchar();
	return 0;
}