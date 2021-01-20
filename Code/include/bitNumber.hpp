/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     bitNumber.hpp                                      =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <vector>
#include <iostream>
#include <cmath>

/*------------------------------------------------*/

/**
 * @brief      This class describes a number representated by a bit vector.
 */
class BitNumber {

	private:
		// Attributes
		int bitAmmount_;
		int numberAmmount_;
		int setAmmount_;
		std::vector<bool> number_;

	public:
		// Builders & destroyer
		BitNumber (void);
		BitNumber (int number, int bitAmmount);
		~BitNumber (void);

		// Getters & Setters
		int get_BitAmmount (void) const;
		int get_NumberAmmount (void) const;
		int get_SetAmmount (void) const;
		std::vector<bool> get_Number (void) const;

		void set_BitAmmount (int newBitAmmount);
		void set_NumberAmmount (int newNumberAmmount);
		void set_SetAmmount (int newSetAmmount);
		void set_Number (std::vector<bool> newNumber);

		// Methods
		int toInt (void);
		void writeBit (int position, int numberPos, bool bit);
		void printNumber (void);

		// Operators Overload
		BitNumber operator+ (const BitNumber& number);

};