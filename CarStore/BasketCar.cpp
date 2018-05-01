#include"BasketCar.h"
#pragma warning (disable : 4244)

//Add a new car to the basket
void Basket::addCarToBasket(const Car& c)
{
	m_basket.push_back(c);
}

/*
	Delete the entire list.
*/
void Basket::deleteAll()
{
	m_basket.clear();
}

/*
	If a car is deleted from original list(repositoru), the car will be also deleted from the basket(no matter how many times it occurs)
*/
void Basket::deleteCarBascket(const Car& c)
{
	auto it = std::find(m_basket.begin(), m_basket.end(), c);
	while ( it != m_basket.end())
	{
		m_basket.erase(it);
		it = std::find(m_basket.begin(), m_basket.end(), c);
	}
}

/*
	Return the current car's basket.
*/
const std::vector<Car>& Basket::getAllBasket() const
{
	return m_basket;
}

/*
	If a car is modified, the modification is reflected also in basket.
*/
void Basket::updateCarBasket(const Car& car, const Car& newCar)
{
	auto it = std::find(m_basket.begin(), m_basket.end(), car);
	while (it != m_basket.end())
	{
		const int pos = std::distance(m_basket.begin(), it);
		m_basket[pos] = newCar;
		it = std::find(m_basket.begin(), m_basket.end(), car);
	}
}
/*
	Populate randomly a vector
*/
void Basket::populateRandom(int nrTimes, std::vector<Car> allCars)
{
	std::shuffle(allCars.begin(), allCars.end(), std::default_random_engine(std::random_device{}())); 
	while (nrTimes>0 && allCars.size() > 0)
	{
		m_basket.push_back(allCars.back());
		allCars.pop_back();
		nrTimes--;
	}
}