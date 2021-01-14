/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     main.cpp                                           =
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
* @Date:   2020-12-24 09:01:33
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-13 15:12:25
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/FileHandler.hpp"
#include "../include/Chrono.hpp"
#include "../include/3dm.hpp"

/*------------------------------------------------*/


/**
 * @brief      Main function
 *
 * @return     0 if program finished correctly.
 */
int main (void) {
    // Normal partition input
    Chrono timer;
	FileHandler newFile;
	std::vector<int> v = newFile.readNormal("../inputs/example.txt");
	Partition newPartition(v);
    timer.startChrono();
	newPartition.set_Partitioned(newPartition.sortAndSolve());
	timer.stopChrono();
    newPartition.printByConsole();
    std::cout << std::endl << "Elapsed time: " << timer.get_MilliSeconds(7) << " milli-seconds." << std::endl;
    
    // 3DM partition input
    Chrono timer2;
    FileHandler file("../inputs/example3dm.3dm");
    Problem3DM problem3dm(file);
    timer2.startChrono();
    Partition newPartition2(problem3dm.transformToPartition());
    newPartition2.set_Partitioned(newPartition2.sortAndSolve());
    timer2.stopChrono();
    newPartition2.printByConsole();
    problem3dm.printData();
    std::cout << std::endl << std::endl << "Elapsed time: " << timer2.get_MilliSeconds(7) << " milli-seconds." << std::endl;

    return 0;
}