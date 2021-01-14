/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     3dm.cpp                                            =
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
* @Last Modified time: 2021-01-13 19:47:11
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/3dm.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Problem3DM::Problem3DM (void) {
	x_.resize(0);
	y_.resize(0);
	z_.resize(0);
	triplets_.resize(0);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  file  The file
 */
Problem3DM::Problem3DM (FileHandler file) {
	std::pair<std::vector<std::vector<std::string>>, std::vector<Triplet>> data;
	data = file.read3DM(file.get_FileName());
	set_X(data.first[0]);
	set_Y(data.first[1]);
	set_Z(data.first[2]);
	set_Triplets(data.second);
}

/**
 * @brief      Destroys the object.
 */
Problem3DM::~Problem3DM (void) {
	x_.clear();
	y_.clear();
	z_.clear();
	triplets_.clear();
}

/**
 * @brief      Gets the x.
 *
 * @return     The x.
 */
std::vector<std::string> Problem3DM::get_X (void) const {
	return x_;
}

/**
 * @brief      Gets the y.
 *
 * @return     The y.
 */
std::vector<std::string> Problem3DM::get_Y (void) const {
	return y_;
}

/**
 * @brief      Gets the z.
 *
 * @return     The z.
 */
std::vector<std::string> Problem3DM::get_Z (void) const {
	return z_;
}

/**
 * @brief      Gets the triplets.
 *
 * @return     The triplets.
 */
std::vector<Triplet> Problem3DM::get_Triplets (void) const {
	return triplets_;
}

/**
 * @brief      Sets the x.
 *
 * @param[in]  newX  The new x
 */
void Problem3DM::set_X (std::vector<std::string> newX) {
	x_ = newX;
}

/**
 * @brief      Sets the y.
 *
 * @param[in]  newY  The new y
 */
void Problem3DM::set_Y (std::vector<std::string> newY) {
	y_ = newY;
}

/**
 * @brief      Sets the z.
 *
 * @param[in]  newZ  The new z
 */
void Problem3DM::set_Z (std::vector<std::string> newZ) {
	z_ = newZ;
}

/**
 * @brief      Sets the triplets.
 *
 * @param[in]  newTriplets  The new triplets
 */
void Problem3DM::set_Triplets (std::vector<Triplet> newTriplets) {
	triplets_ = newTriplets;
}

/**
 * @brief      Transform the 3DM problem solution into partition input data
 *
 * @return     The partition input data
 */
std::vector<int> Problem3DM::transformToPartition (void) {
	std::vector<int> sol;
	for (unsigned i = 0; i < get_Triplets().size(); i++) {
		int sum = 0;
		for (unsigned j = 0; j < get_Triplets()[i].get_X().length(); j++) {
			int tmp = get_Triplets()[i].get_X()[j];
			sum += tmp;
		}
		for (unsigned j = 0; j < get_Triplets()[i].get_Y().length(); j++) {
			int tmp = get_Triplets()[i].get_Y()[j];
			tmp *= 100;
			sum += tmp;
		}
		for (unsigned j = 0; j < get_Triplets()[i].get_Z().length(); j++) {
			int tmp = get_Triplets()[i].get_Z()[j];
			if (tmp < 0) {
				tmp *= -1;
			}
			tmp *= 10000;
			sum += tmp;
		}
		sol.push_back(sum);
	}
	return sol;
}

/**
 * @brief      Prints a data.
 */
void Problem3DM::printData (void) {
	std::cout << std::endl << "3DM Data: " << std::endl;
	std::cout << "\t Vector X: { ";
	for (unsigned i = 0; i < x_.size() - 1; i++) {
		std::cout << x_[i] << ", ";
	}
	std::cout << x_[x_.size() - 1] << " }" << std::endl;

	std::cout << "\t Vector Y: { ";
	for (unsigned i = 0; i < y_.size() - 1; i++) {
		std::cout << y_[i] << ", ";
	}
	std::cout << y_[y_.size() - 1] << " }" << std::endl;

	std::cout << "\t Vector Z: { ";
	for (unsigned i = 0; i < z_.size() - 1; i++) {
		std::cout << z_[i] << ", ";
	}
	std::cout << z_[z_.size() - 1] << " }" << std::endl;

	std::cout << "\t Triplets: [ ";
	for (unsigned i = 0; i < triplets_.size(); i++) {
		std::cout << "{ " << triplets_[i].get_X() << ", " << triplets_[i].get_Y() << ", " << triplets_[i].get_Z() << " } ";
	}
	std::cout << " ]";
}