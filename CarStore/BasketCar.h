#pragma once
#include"Domain.h"
#include <algorithm>
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock
#include<vector>
class Basket
{
	std::vector<Car> m_basket;
public:
	Basket() = default;
	void addCarToBasket(const Car&);
	void deleteAll();
	void deleteCarBascket(const Car&);
	void updateCarBasket(const Car&, const Car&);
	void populateRandom( int nrTimes, std::vector<Car> allCars);
	const std::vector<Car>& getAllBasket() const;
};