#include "stdafx.h"
#include "European.h"


European::European()
{
}

European::European(const std::double_t & spot, const std::double_t & strike, const std::double_t & up, const std::double_t & down, const std::double_t & rate, const int & steps, const OptionType::OptionType & type, const ExerciseType::ExerciseType & exercise)
	: Option(spot, strike, up, down, rate, steps, type, exercise) {}

std::double_t European::getProbUp() {
	return (getRate() - getDown()) / (getUp() - getDown());
}

std::double_t European::getProbDown()
{
	return std::double_t(1 - getProbUp());
}

std::double_t European::getPrice() {
	//pay_off = new Matrix<std::double_t>(getSteps() + 1, getSteps() + 1, 0.0);
	//pay_off = getPayOff();
	pay_off = new std::double_t *[getSteps() + 1];
	for (int i = 0; i < getSteps() + 1; i++) {
		pay_off[i] = new std::double_t[getSteps() + 1];
		for (int j = 0; j < getSteps() + 1; j++) {
			pay_off[i][j] = getPayOff()[i][j];
		}
	}
	//std::memcpy(pay_off, getPayOff(), sizeof(getPayOff()));
	for (int j = getSteps() - 1; j >=0; j--) {
		for (int i = 0; i < j + 1; i++) {
			pay_off[j][i] = (1 / getRate()) * (getProbUp() * pay_off[j + 1][i] + getProbDown() * pay_off[j + 1][i + 1]);
			//pay_off->value(j, i) = (1 / getRate()) * (getProbUp() * pay_off->value(j+1, i) + getProbDown() * pay_off->value(j + 1, i +1));

		}
	}
	setPayOff(pay_off);
	return /*pay_off[0][0]*/std::double_t(getPremiun());
}


European::~European(){
}
