/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     Partition.hpp                                      =
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

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>

/*------------------------------------------------*/

class Partition {

    private:
        // Attributes
        std::vector<int> original_;     // The vector with all the numbers
        std::vector<int> v1_;           // The first vector of the solution
        std::vector<int> v2_;           // The second vector of the solution
        bool partitioned_;

    public:
        // Builders & Destroyer
        Partition (void);
        Partition (std::vector<int> original);
        ~Partition (void);

        // Getters & Setters
        std::vector<int> get_Original (void) const;
        std::vector<int> get_V1 (void) const;
        std::vector<int> get_V2 (void) const;
        bool get_Partitioned (void) const;

        void set_Original (std::vector<int> newOriginal);
        void set_V1 (std::vector<int> newV1);
        void set_V2 (std::vector<int> newV2);
        void set_Partitioned (bool newPartitioned);

        // Methods
        void printByConsole (void);
        int calculateSum (std::vector<int>& v);
        bool isSubsetSum(std::vector<int>& v, int n, int sum);
        void findPartition(std::vector<int>& v);
        bool dynamicFindPartition(std::vector<int> v);

};