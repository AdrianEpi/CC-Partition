/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     triplet.cpp                                        =
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
* @Date:   2020-12-27 09:02:38
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-13 12:56:11
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/triplet.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Triplet::Triplet (void) {
	set_X("");
	set_Y("");
	set_Z("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  x     The x element
 * @param[in]  y     The y element
 * @param[in]  z     The z element
 */
Triplet::Triplet (std::string x, std::string y, std::string z) {
	set_X(x);
	set_Y(y);
	set_Z(z);
}

/**
 * @brief      Destroys the object.
 */
Triplet::~Triplet (void) {
}

/**
 * @brief      Gets the x.
 *
 * @return     The x.
 */
std::string Triplet::get_X (void) const {
	return x_;
} 

/**
 * @brief      Gets the y.
 *
 * @return     The y.
 */
std::string Triplet::get_Y (void) const {
	return y_;
}

/**
 * @brief      Gets the z.
 *
 * @return     The z.
 */
std::string Triplet::get_Z (void) const {
	return z_;
}

/**
 * @brief      Sets the x.
 *
 * @param[in]  newX  The new x
 */
void Triplet::set_X (std::string newX) {
	x_ = newX;
} 

/**
 * @brief      Sets the y.
 *
 * @param[in]  newY  The new y
 */
void Triplet::set_Y (std::string newY) {
	y_ = newY;
}

/**
 * @brief      Sets the z.
 *
 * @param[in]  newZ  The new z
 */
void Triplet::set_Z (std::string newZ) {
	z_ = newZ;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newTriplet  The new triplet
 *
 * @return     The result of the assignment
 */
Triplet& Triplet::operator= (const Triplet& newTriplet) {
	this -> set_X(newTriplet.get_X());
	this -> set_Y(newTriplet.get_Y());
	this -> set_Z(newTriplet.get_Z());
	return *this;
}