#include "Shoes.h"
#include "Factory.h"

int main()
{
	Factory* Adidas = new AdidasFactory();
	Shoes* adidasShoes = Adidas->CreateShoes();
	adidasShoes->Show();

	delete Adidas;
	delete adidasShoes;

	Factory* nikeFactory = new NikeFactory();
	Shoes* nikeShoes = nikeFactory->CreateShoes();
	nikeShoes->Show();

	delete nikeFactory;
	delete nikeShoes;

	Factory* liningFactory = new LiNingFactory();
	Shoes* liningShoes = liningFactory->CreateShoes();
	liningShoes->Show();

	delete liningFactory;
	delete liningShoes;
}
