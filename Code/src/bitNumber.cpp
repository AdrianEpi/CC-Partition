/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     bitNumber.cpp                                      =
    =            Author:        Francisco Javier Arocas Herrera                    =
    =                           Oscar Hernández Díaz                               =
    =                           Gabriel Melián Hernández                           =
    =                           Adrián Epifanio Rodríguez Hernández                =
    =            Date:          24/12/2020                                         =
    =            Subject:       Computational Complexity                           =
    =            Language:      C++                                                =
    =            Email:         alu0100819786@ull.edu.es                           =
    =                           alu0100906813@ull.edu.es                           =
    =                           alu0101127163@ull.edu.es                           =
    =                           alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Francisco Javier Arocas
 * 		   Oscar Hernández
 * 		   Gabriel Melián
 * 		   Adrian Epifanio Rodríguez
* @Date:   2020-12-27 12:02:38
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-20 21:10:41
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/bitNumber.hpp"
/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
BitNumber::BitNumber (void) {
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  num         The number
 * @param[in]  bitAmmount  The bit ammount
 */
BitNumber::BitNumber (int num, int bitAmmount) {
	set_NumberAmmount(3);
	set_BitAmmount(3);
	set_SetAmmount(3);
	number_ = std::vector<bool> (get_NumberAmmount() * get_BitAmmount() * get_SetAmmount(), false);
	long int tmp = 0;
	bool overflow = false;
	while (num != 0) {
		tmp = num / 2;
		if (num % 2 == 0) {
			overflow = false;
		}
		else {
			overflow = true;
		}
		number_.insert(number_.begin(), overflow);
		num = tmp;
	}
	while (number_.size() < bitAmmount) {
		number_.insert(number_.begin(), 0);
	}
}

/**
 * @brief      Destroys the object.
 */
BitNumber::~BitNumber (void) {
	number_.clear();
}

/**
 * @brief      Gets the bit ammount.
 *
 * @return     The bit ammount.
 */
int BitNumber::get_BitAmmount (void) const {
	return bitAmmount_;
}

/**
 * @brief      Gets the number ammount.
 *
 * @return     The number ammount.
 */
int BitNumber::get_NumberAmmount (void) const {
	return numberAmmount_;
}

/**
 * @brief      Gets the set ammount.
 *
 * @return     The set ammount.
 */
int BitNumber::get_SetAmmount (void) const {
	return setAmmount_;
}

/**
 * @brief      Gets the number.
 *
 * @return     The number.
 */
std::vector<bool> BitNumber::get_Number (void) const {
	return number_;
}	

/**
 * @brief      Sets the bit ammount.
 *
 * @param[in]  newBitAmmount  The new bit ammount
 */
void BitNumber::set_BitAmmount (int newBitAmmount) {
	bitAmmount_ = newBitAmmount;
}

/**
 * @brief      Sets the number ammount.
 *
 * @param[in]  newNumberAmmount  The new number ammount
 */
void BitNumber::set_NumberAmmount (int newNumberAmmount) {
	numberAmmount_ = newNumberAmmount;
}

/**
 * @brief      Sets the set ammount.
 *
 * @param[in]  newSetAmmount  The new set ammount
 */
void BitNumber::set_SetAmmount (int newSetAmmount) {
	setAmmount_ = newSetAmmount;
}

/**
 * @brief      Sets the number.
 *
 * @param[in]  newNumber  The new number
 */
void BitNumber::set_Number (std::vector<bool> newNumber) {
	number_ = newNumber;
}

/**
 * @brief      Returns an integer representation of the object.
 *
 * @return     Integer representation of the object.
 */
int BitNumber::toInt (void) {
	int number = 0;
	for (int i = number_.size() - 1; i >= 2; i--) {
		if (number_[i] == 1) {
			number += pow(2, number_.size() - i -1);
		}
	}
	return number;
}

/**
 * @brief      Writes a bit into it's position.
 *
 * @param[in]  position   The position
 * @param[in]  numberPos  The number position (1, 2, 3)
 * @param[in]  bit        The bit
 */
void BitNumber::writeBit (int position, int numberPos, bool bit) {
	number_.at((((numberPos - 1) * get_NumberAmmount() * get_BitAmmount()) + (get_BitAmmount() * (position)) + 1)) = bit;
}

/**
 * @brief      Prints a number.
 */
void BitNumber::printNumber (void) {
	std::string representation = "";
	for (unsigned i = 2; i < number_.size(); i++) {
		if (number_[i] == true) {
			representation += "1";
		}
		else {
			representation += "0";
		}
		if ((i - 1) % 3 == 0 )
			representation += " ";
		if ((i - 1) % 9 == 0 )
			representation += "|";
	}
	std::cout << "Number: " << representation << std::endl;
}

/**
 * @brief      Addition operator.
 *
 * @param[in]  number  The number
 *
 * @return     The result of the addition
 */
BitNumber BitNumber::operator+ (const BitNumber& number) {
	BitNumber sum(get_BitAmmount(), get_NumberAmmount());
	bool overflow = false, bit = false;
	std::vector<bool> tmpNumber;
	for (int i = sum.get_Number().size() - 1; i >= 0; i--) {
		bit = number_.at(i) ^ number.get_Number().at(i) ^ overflow;
		overflow = ((number_.at(i) & number.get_Number().at(i)) | (number.get_Number().at(i) & overflow) | (number_.at(i) & overflow));
		tmpNumber = sum.get_Number();
		tmpNumber.at(i) = bit;
		sum.set_Number(tmpNumber);
	}	
	return sum;
}