#include "Shoes.h"
#include "Factory.h"

int main()
{
	Factory factory;

	Shoes* pNiKe = factory.CreateShoes(NIKE);
	pNiKe->Show();

	Shoes* pAdidas = factory.CreateShoes(ADIDASI);
	pAdidas->Show();

	Shoes* pLiNing = factory.CreateShoes(LINING);
	pLiNing->Show();

	delete pNiKe;
	delete pAdidas;
	delete pLiNing;

	pNiKe = nullptr;
	pAdidas = nullptr;
	pLiNing = nullptr;
}