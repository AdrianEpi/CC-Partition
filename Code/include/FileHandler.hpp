/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     FileHandler.hpp                                    =
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
#include "Color.hpp"
#include "Partition.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>
#include <fstream>

/*------------------------------------------------*/

/**
 * @brief      This class describes a file handler, it reads and writes data into files.
 */
class FileHandler {

    private:
        // Attributes
        std::string fileName_;

    public:
        // Builders & Destroyer
        FileHandler (void);
        FileHandler (std::string fileName);
        ~FileHandler (void);

        // Getter & Setter
        std::string get_FileName (void) const;
        void set_FileName (std::string newFileName);

        // Methods
        std::vector<int> read (std::string fileName);
        std::ostream& write (std::ostream& os, Partition& partition);

};