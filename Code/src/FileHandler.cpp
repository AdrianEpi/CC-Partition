/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     FileHandler.cpp                                    =
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
* @Date:   2020-12-24 09:02:04
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-04 10:06:26
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/FileHandler.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
FileHandler::FileHandler (void) {
	set_FileName("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  fileName  The file name
 */
FileHandler::FileHandler (std::string fileName) {
	set_FileName(fileName);
}

/**
 * @brief      Destroys the object.
 */
FileHandler::~FileHandler (void) {
}

/**
 * @brief      Gets the file name.
 *
 * @return     The file name.
 */
std::string FileHandler::get_FileName (void) const {
	return fileName_;
}

/**
 * @brief      Sets the file name.
 *
 * @param[in]  newFileName  The new file name
 */
void FileHandler::set_FileName (std::string newFileName) {
	fileName_ = newFileName;
}

/**
 * @brief      Reads the numbers from file and stores them in a vector
 *
 * @param[in]  fileName  The file name
 *
 * @return     The vector with the numbers
 */
std::vector<int> FileHandler::read (std::string fileName) {
	std::ifstream input(fileName, std::ios::in);
	std::vector<int> originalVector;
	if (input.fail()) {
		std::cout << std::endl << Color::writeRed("Error, couldn't open read file.") << std::endl;
		exit(1);
	}
	else {
		int numAmmount = 0;
		input >> numAmmount;
		for (int i = 0; i < numAmmount; i++) {
			int aux = 0;
			input >> aux;
			originalVector.push_back(aux);
		}
		input.close();
	}
	return originalVector;
}

/**
 * @brief      Saves the partition solution in file
 *
 * @param      os         The output stream
 * @param      partition  The partition
 *
 * @return     The output stream
 */
std::ostream& FileHandler::write (std::ostream& os, Partition& partition) {
	if (partition.get_Partitioned()) {
		/*partition.printByConsole();

		os << "Original Vector:" << std::endl << "\t[ ";
		for (int i = 0; i < partition.get_OriginalVector().size() - 1; i++) {
			os << partition.get_OriginalVector()[i] << ", ";
		}
		os << partition.get_OriginalVector()[partition.get_OriginalVector().size() - 1] << " ]" << std::endl << std::endl;
		
		os << "V1:" << std::endl << "\t{ ";
		for (int i = 0; i < partition.get_V1().size() - 1; i++) {
			os << partition.get_V1()[i] << ", ";
		}
		os << partition.get_V1()[partition.get_V1().size() - 1] << " }" << std::endl << std::endl;

		os << "V2:" << std::endl << "\t{ ";
		for (int i = 0; i < partition.get_V2().size() - 1; i++) {
			os << partition.get_V2()[i] << ", ";
		}
		os << partition.get_V2()[partition.get_V2().size() - 1] << " }" << std::endl << std::endl;
	*/
	}
	else {
		std::cout << std::endl << "The array cannot be partitioned into equal sum sets." << std::endl;
		os << std::endl << "The array cannot be partitioned into equal sum sets." << std::endl;
	}
	return os;
}

