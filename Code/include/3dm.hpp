/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     3dm.hpp                                            =
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
#include "triplet.hpp"
#include "FileHandler.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*------------------------------------------------*/

/**
 * @brief      This class describes a 3DM problem.
 */
class Problem3DM {
    private:
        // Attributes
        std::vector<std::string> x_;
        std::vector<std::string> y_;
        std::vector<std::string> z_;
        std::vector<Triplet> triplets_;

    public:
        // Builders & Destroyer
        Problem3DM (void);
        Problem3DM (FileHandler file);
        ~Problem3DM (void);

        // Getters & Setters
        std::vector<std::string> get_X (void) const;
        std::vector<std::string> get_Y (void) const;
        std::vector<std::string> get_Z (void) const;
        std::vector<Triplet> get_Triplets (void) const;

        void set_X (std::vector<std::string> newX);
        void set_Y (std::vector<std::string> newY);
        void set_Z (std::vector<std::string> newZ);
        void set_Triplets (std::vector<Triplet> newTriplets);

        // Methods
        std::vector<int> transformToPartition (void);
        void printData (void);

};