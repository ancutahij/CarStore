#include"Tests.h"

void Test::addBasketTest()
{
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	
	Basket basket;
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car2);
	
	assert(basket.getAllBasket().size()== 3);

}

void Test::deleteBasketTest()
{
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };

	Basket basket;
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car2);

	assert(basket.getAllBasket().size() == 3);
	basket.deleteAll();
	assert(basket.getAllBasket().size() == 0);

	basket.addCarToBasket(car2);
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car2);
	basket.deleteCarBascket(car2);
	assert(basket.getAllBasket().size() == 1);

}
void Test::updateBasketTest()
{

	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };

	Basket basket;
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car1);
	basket.addCarToBasket(car2);

	basket.updateCarBasket(car1, car2);
	assert(basket.getAllBasket()[0] == car2);
}

void Test::populateBasketTest()
{
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "24gt5", "Agtg", "2gg4", "terrip" };
	std::vector<Car> v{ car1, car2, car3 };

	Basket basket;
	basket.populateRandom(3, v);
	assert(basket.getAllBasket().size() == 3);

	basket.populateRandom(2, v);
	assert(basket.getAllBasket().size() == 5);

	basket.deleteAll();
	assert(basket.getAllBasket().size() == 0);

}