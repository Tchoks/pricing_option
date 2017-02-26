// pricing_option.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "European.h"
#include "ExerciseType.h"
#include "OptionType.h"

#include <chrono>
#include <ctime>
#include <iostream>

int main() {

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	European european(100.0, 90.0, 1.10, 0.90, 4.0, 50, OptionType::OptionType::PUT, ExerciseType::ExerciseType::EUROPEAN);
	std::double_t price = european.getPrice();
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "prob up: " << european.getProbUp() << std::endl;
	std::cout << "rate: " << european.getRate() << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Steps: " << european.getSteps() << std::endl;
	std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;
	system("pause");

    return 0;
}

