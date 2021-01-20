/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     triplet.hpp                                        =
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

#include <iostream>
#include <vector>

/*------------------------------------------------*/

/**
 * @brief      This class describes a triplet.
 */
class Triplet {
    
    private:
        // Attributes
        std::string x_;
        std::string y_;
        std::string z_;

    public:
        // Builders & Destroyer
        Triplet (void);
        Triplet (std::string x, std::string y, std::string z);
        ~Triplet (void);

        // Getters & Setters
        std::string get_X (void) const; 
        std::string get_Y (void) const;
        std::string get_Z (void) const;

        void set_X (std::string newX); 
        void set_Y (std::string newY);
        void set_Z (std::string newZ);

        // Methods
        int findElementPosition (std::vector<std::string> v, int letter);

        // Operator Overload
        Triplet& operator= (const Triplet& newTriplet);
};