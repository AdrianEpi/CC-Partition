/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Partition Problem                                  =
    =            File name:     Partition.cpp                                      =
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
* @Date:   2020-12-24 09:02:38
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2021-01-13 15:13:16
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/Partition.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Partition::Partition (void) {
    set_Partitioned(false);
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  original  The original vector
 */
Partition::Partition (std::vector<int> original) {
    set_Original(original);
    set_Partitioned(false);
}

/**
 * @brief      Destroys the object.
 */
Partition::~Partition (void) {
}

/**
 * @brief      Gets the original vector.
 *
 * @return     The original vector.
 */
std::vector<int> Partition::get_Original (void) const {
    return original_;
}

/**
 * @brief      Gets the solution vector 1.
 *
 * @return     The solution vector 1.
 */
std::vector<int> Partition::get_V1 (void) const {
    return v1_;
}

/**
 * @brief      Gets the solution vector 2.
 *
 * @return     The solution vector 2.
 */
std::vector<int> Partition::get_V2 (void) const {
    return v2_;
}

/**
 * @brief      Gets if it's partitioned or not.
 *
 * @return     True if it's partitioned, false otherwise.
 */
bool Partition::get_Partitioned (void) const {
    return partitioned_;
}

/**
 * @brief      Sets the original vector.
 *
 * @param[in]  newOriginal  The new original vector
 */
void Partition::set_Original (std::vector<int> newOriginal) {
    original_ = newOriginal;
}

/**
 * @brief      Sets the solution vector 1.
 *
 * @param[in]  newV1  The new solution vector 1
 */
void Partition::set_V1 (std::vector<int> newV1) {
    v1_ = newV1;
}

/**
 * @brief      Sets the solution vector 2.
 *
 * @param[in]  newV2  The new solution vector 2
 */
void Partition::set_V2 (std::vector<int> newV2) {
    v2_ = newV2;
}

/**
 * @brief      Sets if it's partitioned or not.
 *
 * @param[in]  newPartitioned  Indicates the new partitioned flag
 */
void Partition::set_Partitioned (bool newPartitioned) {
    partitioned_ = newPartitioned;
}

/**
 * @brief      Prints the solution by console painting them in different colors.
 */
void Partition::printByConsole (void) {
    if (partitioned_) {
        std::vector<std::string> v;
        unsigned i = 0, j = 0;
        while (i < v1_.size() && j < v2_.size()) {
            std::string aux = "";
            if (v1_[i] <= v2_[j]) {
                aux = Color::writeCyan(std::to_string(v1_[i]));
                i++;
            }
            else {
                aux = Color::writeRed(std::to_string(v2_[j]));
                j++;
            }
            v.push_back(aux);
        }
        while (i < v1_.size()) {
            std::string aux = Color::writeCyan(std::to_string(v1_[i]));
            i++;
            v.push_back(aux);
        }
        while (j < v2_.size()) {
            std::string aux = Color::writeRed(std::to_string(v2_[j]));
            j++;
            v.push_back(aux);
        }

        std::cout << "Original Vector:" << std::endl << "\t[ ";
        for (unsigned i = 0; i < v.size() - 1; i++) {
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size() - 1] << " ]" << std::endl << std::endl;
        
        std::cout << "V1:" << std::endl << "\t{ ";
        for (unsigned i = 0; i < v1_.size() - 1; i++) {
            std::string aux = Color::writeCyan(std::to_string(v1_[i]));
            std::cout << aux << ", ";
        }
        std::string finalV1 = Color::writeCyan(std::to_string(v1_[v1_.size() - 1]));
        std::cout << finalV1 << " }" << std::endl << std::endl;

        std::cout << "V2:" << std::endl << "\t{ ";
        for (unsigned i = 0; i < v2_.size() - 1; i++) {
            std::string aux = Color::writeRed(std::to_string(v2_[i]));
            std::cout << aux << ", ";
        }
        std::string finalV2 = Color::writeRed(std::to_string(v2_[v2_.size() - 1]));
        std::cout << finalV2 << " }" << std::endl << std::endl;
    }
    else {
        std::cout << std::endl <<"Origial vector: [ ";
        for (unsigned i = 0; i < original_.size() - 1; i++) {
            std::cout << original_[i] << ", ";
        }
        std::cout << original_[original_.size() - 1] << " ]" << std::endl;
        std::cout << std::endl << "Sorry, there is not solution to the partition problem with that imput data." << std::endl;
    }
}

/**
 * @brief      Calculates the sum of the integers in the given vector.
 *
 * @param      v     The integers vector
 *
 * @return     The sum.
 */
int Partition::calculateSum (std::vector<int>& v) {
    int sum = 0;
    for (unsigned i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

/**
 * @brief      Determines if there is a subset of v with sum equal to given sum recursively
 *
 * @param[in]  v     The vector
 * @param[in]  n     The elements ammount 
 * @param[in]  sum   The sum
 *
 * @return     True if thete is subset sum, False otherwise.
 */
bool Partition::isSubsetSum(std::vector<int> v, int n, int sum) {
    // Base Cases
    if (sum == 0) {
        return true;
    }

    if (n == 0 && sum != 0) {
        return false;
    }
 
    // If last element is greater than sum, then ignore it
    if (v[n - 1] > sum) {
        return isSubsetSum(v, n - 1, sum);
    }
 
    /* 
        else, check if sum can be obtained by any of the following
        (a) including the last element
        (b) excluding the last element
    */
    return isSubsetSum(v, n - 1, sum) || isSubsetSum(v, n - 1, sum - v[n - 1]);
}

/**
 * @brief      Finds if there's a partition solution recursively.
 */
void Partition::findPartition(void) {
    sum_ = calculateSum(original_);
    // If sum_ is odd, there cannot be two subsets with equal sum_
    if (sum_ % 2 != 0) {
        set_Partitioned(false);
    }
    else {
        // Find if there is subset with sum_ equal to half of total sum_
        set_Partitioned(isSubsetSum(original_, original_.size(), sum_ / 2));
    }
    
}

/**
 * @brief      The problem solved using dynamic programming when the sum of the elements is not too big
 *
 * @return     True if it has solution, False otherwise.
 */
bool Partition::dynamicFindPartition(void) {
    sum_ = calculateSum(original_);

    // If sum is odd there can't be solution
    if (sum_ % 2 != 0) {
        return false;
    }
 
    bool table[sum_ / 2 + 1][original_.size() + 1];
 
    // Initialize top row as true
    for (unsigned i = 0; i <= original_.size(); i++) {
        table[0][i] = true;
    }
 
    // Initialize leftmost column, except table[0][0], as 0
    for (int i = 1; i <= sum_ / 2; i++) {
        table[i][0] = false;
    }
 
    // Fill the partition table in bottom up manner
    for (int i = 1; i <= sum_ / 2; i++) {
        for (unsigned j = 1; j <= original_.size(); j++) {
            table[i][j] = table[i][j - 1];
            if (i >= original_[j - 1])
                table[i][j] = table[i][j] || table[i - original_[j - 1]][j - 1];
        }
    }
 
    // Uncomment this part to print the dynamic programming table
    /*
    for (int i = 0; i <= sum_ / 2; i++) {
        for (unsigned j = 0; j <= original_.size(); j++) {
            std::cout << table[i][j];
        }
        std::cout << std::endl;
    } 
    */
    return table[sum_ / 2][original_.size()];
}

/**
 * @brief      Sorts the vector and solves the partition solution
 *
 * @return     True if it has solution, false otherwise
 */
bool Partition::sortAndSolve (void) {
    std::sort(original_.begin(), original_.begin() + original_.size());
    sum_ = calculateSum(original_) / 2;
    std::vector<int> emptyVector;
    set_Partitioned(findSolution(emptyVector, emptyVector, 0));
    return get_Partitioned();
}

/**
 * @brief      Finds the solution to the partition problem recursively.
 *
 * @param[in]  v1    The vector 1
 * @param[in]  v2    The vector 2
 * @param[in]  n     The position in the original vector
 *
 * @return     True if it finds solution, false otherwise
 */
bool Partition::findSolution (std::vector<int> v1, std::vector<int> v2, unsigned n) {
    if (n >= original_.size()) {
        if (calculateSum(v1) == calculateSum(v2)) {
            set_V1(v1);
            set_V2(v2);
            return true;
        }
        return false;
    }
    else {
        std::vector<int> vv1 = v1;
        vv1.push_back(original_[n]);
        std::vector<int> vv2 = v2;
        vv2.push_back(original_[n]);
        return findSolution(vv1, v2, n + 1) || findSolution(v1, vv2, n + 1);
    }
}