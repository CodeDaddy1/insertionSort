#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

void insertionSort(std::vector<int> & array){
    int n = array.size();

    for(int i = 1; i < n; ++i){
        int current = array[i];
        int j = i -1;

        while(j >= 0 && array[j] > current){
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = current;
    }
}

int main(){

auto start_time = std::chrono::high_resolution_clock::now();

const int arraySize = 10000;
std::vector<int> nonSortedArray;

std::srand(std::time(0));

for(int i = 0; i < arraySize; ++i){
    nonSortedArray.push_back(std::rand() % 100);
}

 std::cout << "Generated non-sorted array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << nonSortedArray[i] << ", ";
    }



std::cout << std::endl;
std::cout << std::endl;


insertionSort(nonSortedArray);

std::cout << "Sorted array: " << std::endl;
    for(int num : nonSortedArray){
        std::cout << num << " ";
    }
std::cout << std::endl;
std::cout << std::endl;

auto end_time = std::chrono::high_resolution_clock::now();

auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

// Display the runtime in microseconds
std::cout << "Runtime: " << duration.count() << " microseconds" << std::endl;

    return 0;
}