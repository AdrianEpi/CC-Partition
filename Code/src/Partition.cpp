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
* @Last Modified time: 2021-01-04 10:18:26
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

void Partition::printByConsole (void) {

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
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

/**
 * @brief      Determines if there is a subset of v with sum equal to given sum
 *
 * @param[in]  v     The vector
 * @param[in]  n     The elements ammount 
 * @param[in]  sum   The sum
 *
 * @return     True if thete is subset sum, False otherwise.
 */
bool Partition::isSubsetSum(std::vector<int>& v, int n, int sum) {
    // Base Cases
    if (sum == 0)
        return true;

    if (n == 0 && sum != 0)
        return false;
 
    // If last element is greater than sum, then ignore it
    if (v[n - 1] > sum)
        return isSubsetSum(v, n - 1, sum);
 
    /* else, check if sum can be obtained by any of the following
        (a) including the last element
        (b) excluding the last element
    */
    return isSubsetSum(v, n - 1, sum) || isSubsetSum(v, n - 1, sum - v[n - 1]);
}

void Partition::findPartition(std::vector<int>& v) {
    // Calculate sum of the elements in array
    int sum = calculateSum(v);
 
    // If sum is odd, there cannot be two subsets with equal sum
    if (sum % 2 != 0) {
        set_Partitioned(false);
    }
    else {
        // Find if there is subset with sum equal to half of total sum
        set_Partitioned(isSubsetSum(v, v.size(), sum / 2));
    }
    
}

bool Partition::dynamicFindPartition(std::vector<int> v) {

 /*   int sum = calculateSum(v);
    int i, j;
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
   // return part[sum / 2][n];
}

