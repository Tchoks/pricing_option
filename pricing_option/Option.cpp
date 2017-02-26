#include "stdafx.h"
#include "Option.h"
#include "Matrix.h"

#include <math.h>
#include <algorithm>



Option::Option() {
}


Option::Option(const std::double_t & spot, const std::double_t & strike, const std::double_t & up, const std::double_t & down, const std::double_t & rate, const int& steps, const OptionType::OptionType & type, const ExerciseType::ExerciseType & exercise) : spot(spot), strike(strike), up(up), down(down), steps(steps), type(type), exercise(exercise){
	this->rate = 1 + (rate / 100) / 12;
	this->prob_up = (rate - down) / (up - down);
	this->prob_down = 1 - prob_up;
	stock_price = new std::double_t *[steps + 1];
	for (int i = 0; i < steps + 1; i++) {
		stock_price[i] = new std::double_t[steps + 1];
		for (int j = 0; j < steps + 1; j++) {
			stock_price[i][j] = 0;
		}
	}

	pay_off = new std::double_t *[steps + 1];
	for (int i = 0; i < steps + 1; i++) {
		pay_off[i] = new std::double_t[steps + 1];
		for (int j = 0; j < steps + 1; j++) {
			pay_off[i][j] = 0;
		}
	}


	//stock_price = new Matrix<double>(steps + 1, steps + 1, 0.0);
	//pay_off = new Matrix<double>(steps + 1, steps + 1, 0.0);
	//stock_price(steps + 1, std::vector<std::double_t>(steps + 1, 0));
	/*stock_price.resize(steps + 1);
	for (int i =  0; i < steps + 1; i++) {
		stock_price.resize(steps + 1);
	}
	*/
	//for each(stock_price.begin(), stock_price.end(), [](std::vector<std::double_t>& v) {v.resize(steps + 1)};
	//stock_price(steps + 1, std::vector<std::double_t>(steps + 1));
}


Option::Option(const Option & opt) : spot(opt.spot), strike(opt.strike), up(opt.up), down(opt.down)
, steps(opt.steps), type(opt.type), exercise(opt.exercise) {
	rate = 1 + (opt.rate / 100) / 12;
	stock_price = opt.stock_price;
	pay_off = opt.pay_off;
}

std::double_t** Option::getStockPrice() {
	//stock_price->value(0, 0) = spot;
	stock_price[0][0] = spot;
	for (int i = 1; i < steps + 1; i++) {
		for (int j = 0; j < i + 1 ; j++) {
			stock_price[i][j] = spot*std::pow(up, i-j)*std::pow(down, j);
			//std::cout <<stock_price[i][j] << std::endl;
			//stock_price->value(i, j) = spot * std::pow(up, i - j) * std::pow(down, j);
		}
	}
	return stock_price;
	//return stock_price;
}

void Option::setStockPrice(std::double_t** stock) {
	std::memcpy(stock_price, stock, sizeof(stock));
	//stock_price = stock;
}

std::double_t** Option::getPayOff() {
	for (int i = 0; i < steps + 1; i++) {
		if (type == OptionType::CALL) {
			pay_off[steps][i] = std::max(getStockPrice()[steps][i] - strike, 0.0);
			//std::cout << pay_off[steps][i] << std::endl;
			//pay_off->value(steps, i) = std::max(stock_price->value(steps, i) - strike, 0.0);
		}
		else pay_off[steps][i] = std::max(strike - getStockPrice()[steps][i], 0.0);//pay_off->value(steps, i) = std::max(strike - stock_price->value(steps, i), 0.0);
	}
	return pay_off;
	//return pay_off;
}

void Option::setPayOff(std::double_t** off) {
	std::memcpy(pay_off, off, sizeof(off));
	//pay_off = off;
}

std::double_t Option::getPremiun()
{
	return std::double_t(/*pay_off->value(0, 0)*/ pay_off[0][0]);
}


std::double_t Option::getProbUp(){
	return std::double_t(prob_up);
}

std::double_t Option::getProbDown()
{
	return std::double_t(prob_down);
}

std::double_t Option::getUp()
{
	return std::double_t(up);
}

std::double_t Option::getDown()
{
	return std::double_t(down);
}

std::double_t Option::getStrike() {
	return strike;
}

int Option::getSteps() {
	return int(steps);
}

std::double_t Option::getRate() {
	return std::double_t(rate);
}

Option::~Option() {
	for (int i = 0; i < steps + 1; ++i) {
		delete[] stock_price[i];
	}
	delete[] stock_price;

	for (int i = 0; i < steps + 1; ++i) {
		delete[] pay_off[i];
	}
	delete[] pay_off;
}
