
//task1
#include <iostream>
#include <vector>

// Auxiliary comparison function
template<typename T>
bool isLess(const T& a, const T& b) 
{
    return a < b;
}

// Bubble sort
template<typename T>
void bubbleSort(std::vector<T>& vec) 
{
    for (std::size_t i = 0; i < vec.size(); ++i) 
    {
        for (std::size_t j = 0; j < vec.size() - 1 - i; ++j) 
        {
            if (isLess(vec[j + 1], vec[j])) 
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Selection sort
template<typename T>
void selectionSort(std::vector<T>& vec) 
{
    for (std::size_t i = 0; i < vec.size(); ++i) 
    {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < vec.size(); ++j) 
        {
            if (isLess(vec[j], vec[minIndex])) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(vec[i], vec[minIndex]);
        }
    }
}

// Insertion sort
template<typename T>
void insertionSort(std::vector<T>& vec) 
{
    for (std::size_t i = 1; i < vec.size(); ++i) 
    {
        T key = vec[i];
        std::size_t j = i;
        while (j > 0 && isLess(key, vec[j - 1])) 
        {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

// Template vector sorting function
template<typename T>
void sortVector(std::vector<T>& vec) 
{
    int method = 10 % 3;  // Выбор метода сортировки

    switch (method) 
    {
    case 0:
        bubbleSort(vec);
        break;
    case 1:
        selectionSort(vec);
        break;
    case 2:
        insertionSort(vec);
        break;
    }
}


int main() 
{
    std::vector<int> data = { 5, 3, 8, 1, 4 };

    std::cout << "Before sorting: ";
    for (const auto& val : data)
        std::cout << val << " ";
    std::cout << std::endl;

    sortVector(data);

    std::cout << "After sorting: ";
    for (const auto& val : data)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
