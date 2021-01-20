/*
* @Author: Adrian Epifanio
* @Date:   2021-01-14 18:19:12
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-20 10:45:47
*/
#include "../include/bitNumber.hpp"

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
	for (unsigned i = 0; i < number_.size(); i++) {
		if (number_[i] == 1) {
			int tmp = 1;
			for (unsigned j = 0; j < (number_.size() - (i + 1)); j++) {
				tmp *= 2;
			}
			number += tmp;
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
	number_.at((((numberPos - 1) * get_NumberAmmount() * get_BitAmmount()) + (get_BitAmmount() * (position)) - 1)) = bit;
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