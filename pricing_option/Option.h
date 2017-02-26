#pragma once
#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "ExerciseType.h"
#include "OptionType.h"

class Option
{
	public:
		Option();

		Option(const std::double_t& spot, const std::double_t& strike, const std::double_t& up, const std::double_t& down,
			const std::double_t& rate, const int& steps, const OptionType::OptionType& type, const ExerciseType::ExerciseType& exercise);

		Option(const Option& opt);

		//virtual Matrix<std::double_t>* getStockPrice();
		virtual std::double_t** getStockPrice();

		//virtual void setStockPrice(Matrix<std::double_t> * stock);

		virtual void setStockPrice(std::double_t** stock);

		//virtual Matrix<std::double_t>* getPayOff();

		virtual std::double_t** getPayOff();

		//virtual void setPayOff(Matrix<std::double_t>* off);

		virtual void setPayOff(std::double_t** off);

		virtual std::double_t getPremiun();

		virtual std::double_t getProbUp() = 0;

		virtual std::double_t getProbDown() = 0;

		virtual std::double_t getUp();

		virtual std::double_t getDown();

		virtual std::double_t getStrike();

		virtual int getSteps();

		virtual std::double_t getRate();

		virtual ~Option();
		
	private:
		std::double_t spot;
		std::double_t strike;
		std::double_t up;
		std::double_t down;
		std::double_t rate;
		std::double_t prob_up;
		std::double_t prob_down;
		int steps;
		OptionType::OptionType type;
		ExerciseType::ExerciseType exercise;
		std::double_t **stock_price;
		std::double_t **pay_off;
		//Matrix<std::double_t> *stock_price;
		//Matrix<std::double_t> *pay_off;
		//std::vector<std::vector<std::double_t>> stock_price;
		//std::vector<std::vector<std::double_t>> pay_off;

};

