#include <iostream>
#include <memory>

using namespace std;

class House
{
public:
	string foundation;
	string walls;
	string roof;

	void show()
	{
		cout << "Foundation: " << foundation << endl;
		cout << "Walls: " << walls << endl;
		cout << "Roof: " << roof << endl;
	}
};

class HouseBuilder
{
public:
	virtual void BuildFoundation() = 0;
	virtual void BuildWalls() = 0;
	virtual void BuildRoof() = 0;
	virtual unique_ptr<House> GetHouse() = 0;
	virtual ~HouseBuilder() {}
};

class WoodenHouseBuilder : public HouseBuilder
{
private:
	unique_ptr<House> house;
public:
	WoodenHouseBuilder()
	{
		house = make_unique<House>();
	}
	void BuildFoundation() override
	{
		house->foundation = "Ä¾µØ»ù";
	}
	void BuildWalls() override
	{
		house->walls = "Ä¾Ç½";
	}
	void BuildRoof() override
	{
		house->roof = "Ä¾ÎÝ¶¥";
	}
	unique_ptr<House> GetHouse() override
	{
		return move(house);
	}

};

class BrickHouseBuilder : public HouseBuilder
{
private:
	unique_ptr<House> house;
public:
	BrickHouseBuilder()
	{
		house = make_unique<House>();
	}
	void BuildFoundation() override
	{
		house->foundation = "×©µØ»ù";
	}
	void BuildWalls() override
	{
		house->walls = "×©Ç½";
	}
	void BuildRoof() override
	{
		house->roof = "×©ÎÝ¶¥";
	}
	unique_ptr<House> GetHouse() override
	{
		return move(house);
	}
};

class HouseDirector
{
private:
	unique_ptr<HouseBuilder> builder;
public:
	HouseDirector(unique_ptr<HouseBuilder> b)
	{
		builder = move(b);
	}
	shared_ptr<House> build()
	{
		builder->BuildFoundation();
		builder->BuildWalls();
		builder->BuildRoof();
		return builder->GetHouse();
	}
};

int main()
{
	HouseDirector woodenDirector(make_unique<WoodenHouseBuilder>());
	HouseDirector brickDirector(make_unique<BrickHouseBuilder>());
	auto woodenHouse = woodenDirector.build();
	woodenHouse->show();
	auto brickHouse = brickDirector.build();
	brickHouse->show();

	getchar();
	return 0;
}
