#pragma once
#include <iostream>
#include "Option.h"
#include "OptionType.h"
#include "ExerciseType.h"

class European : public Option
{
	public:

		European();

		European(const std::double_t& spot, const std::double_t& strike, const std::double_t& up, const std::double_t& down,
			const std::double_t& rate, const int& steps, const OptionType::OptionType& type, const ExerciseType::ExerciseType& exercise);

		std::double_t getPrice();

		std::double_t getProbUp();

		std::double_t getProbDown();

		~European();


    private:
		//Matrix<std::double_t> *pay_off;
		std::double_t **pay_off;

};

