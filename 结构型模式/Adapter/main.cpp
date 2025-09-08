//������ģʽ����һ����Ľӿ�ת���ɿͻ�ϣ������һ���ӿڣ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ���������������һ������
#include <iostream>
#include <memory.h>

using namespace std;

class Foreigner
{
public:
	virtual string speak() = 0;
	void ShowResult(string msg)
	{
		cout << "chinese:" << msg << endl;
	}
};

class American : public Foreigner
{
public:
	string speak()
	{
		return "Hello!";
	}
};

class French : public Foreigner
{
public:
	string speak()
	{
		return "Bonjour!";
	}
};

class Chinese
{
public:
	void Recvive(string msg)
	{
		cout << msg << endl;
	}
	string SendMsg()
	{
		return "���!";
	}
};

class Translator
{
protected:
	Foreigner* m_foreigner;
	Chinese m_chinese;
public:
	Translator(Foreigner* foreigner) :m_foreigner(foreigner)
	{
	}
	virtual void TransToForeign() = 0;
	virtual void TransToChinese() = 0;
	~Translator()
	{
		//delete m_foreigner;
	}
};

class AmericanTranslator : public Translator
{
public:
	using Translator::Translator;
	void TransToForeign()
	{
		string msg = m_chinese.SendMsg();
		m_foreigner->ShowResult("message to American: "+ msg);
	}
	void TransToChinese()
	{
		string msg = m_foreigner->speak();
		m_chinese.Recvive("message from American:" + msg);
	}
};

class FrenchTranslator : public Translator
{
public:
	using Translator::Translator;
	void TransToForeign()
	{
		string msg = m_chinese.SendMsg();
		m_foreigner->ShowResult("message to French: " + msg);
	}
	void TransToChinese()
	{
		string msg = m_foreigner->speak();
		m_chinese.Recvive("message from French: " + msg);
	}
};

int main()
{
	Foreigner* american = new American();
	Foreigner* french = new French();
	Translator* translator = new AmericanTranslator(american);
	translator->TransToForeign();
	translator->TransToChinese();
	translator = new FrenchTranslator(french);
	translator->TransToForeign();
	translator->TransToChinese();
	delete translator;
	delete american;
	delete french;

	getchar();
	return 0;
}