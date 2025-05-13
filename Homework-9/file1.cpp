
////task1
//#include <iostream>
//#include <vector>
//
//// Auxiliary comparison function
//template<typename T>
//bool isLess(const T& a, const T& b) 
//{
//    return a < b;
//}
//
//// Bubble sort
//template<typename T>
//void bubbleSort(std::vector<T>& vec) 
//{
//    for (std::size_t i = 0; i < vec.size(); ++i) 
//    {
//        for (std::size_t j = 0; j < vec.size() - 1 - i; ++j) 
//        {
//            if (isLess(vec[j + 1], vec[j])) 
//            {
//                std::swap(vec[j], vec[j + 1]);
//            }
//        }
//    }
//}
//
//// Selection sort
//template<typename T>
//void selectionSort(std::vector<T>& vec) 
//{
//    for (std::size_t i = 0; i < vec.size(); ++i) 
//    {
//        std::size_t minIndex = i;
//        for (std::size_t j = i + 1; j < vec.size(); ++j) 
//        {
//            if (isLess(vec[j], vec[minIndex])) 
//            {
//                minIndex = j;
//            }
//        }
//        if (minIndex != i) {
//            std::swap(vec[i], vec[minIndex]);
//        }
//    }
//}
//
//// Insertion sort
//template<typename T>
//void insertionSort(std::vector<T>& vec) 
//{
//    for (std::size_t i = 1; i < vec.size(); ++i) 
//    {
//        T key = vec[i];
//        std::size_t j = i;
//        while (j > 0 && isLess(key, vec[j - 1])) 
//        {
//            vec[j] = vec[j - 1];
//            --j;
//        }
//        vec[j] = key;
//    }
//}
//
//// Template vector sorting function
//template<typename T>
//void sortVector(std::vector<T>& vec) 
//{
//    int method = 10 % 3;  // Selecting a sorting method
//
//    switch (method) 
//    {
//    case 0:
//        bubbleSort(vec);
//        break;
//    case 1:
//        selectionSort(vec);
//        break;
//    case 2:
//        insertionSort(vec);
//        break;
//    }
//}
//
//
//int main() 
//{
//    std::vector<int> data = { 5, 3, 8, 1, 4 };
//
//    std::cout << "Before sorting: ";
//    for (const auto& val : data)
//        std::cout << val << " ";
//    std::cout << std::endl;
//
//    sortVector(data);
//
//    std::cout << "After sorting: ";
//    for (const auto& val : data)
//        std::cout << val << " ";
//    std::cout << std::endl;
//
//    return 0;
//}

//task 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>



struct Date 
{
    int year = 0;
    int month = 0;
    int day = 0;
};

struct Student 
{
    std::string lastName;
    std::string firstName;
    std::string middleName;
    Date birthDate{};
    int grades[5] = { 0 };
};

//Comparing last names
bool compareStudents(const Student& a, const Student& b) 
{
    if (a.lastName != b.lastName)
        return a.lastName < b.lastName;
    if (a.firstName != b.firstName)
        return a.firstName < b.firstName;
    return a.middleName < b.middleName;
}

// --- bubble sorting ---
void bubbleSort(std::vector<Student>& v) 
{
    for (size_t i = 0; i < v.size(); ++i) 
    {
        for (size_t j = 0; j < v.size() - 1 - i; ++j) 
        {
            if (compareStudents(v[j + 1], v[j])) 
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

// --- Selection sorting ---
void selectionSort(std::vector<Student>& v) 
{
    for (size_t i = 0; i < v.size(); ++i) 
    {
        size_t minIdx = i;
        for (size_t j = i + 1; j < v.size(); ++j) 
        {
            if (compareStudents(v[j], v[minIdx])) 
            {
                minIdx = j;
            }
        }
        std::swap(v[i], v[minIdx]);
    }
}

// --- Insertion sorting ---
void insertionSort(std::vector<Student>& v) 
{
    for (size_t i = 1; i < v.size(); ++i) 
    {
        Student key = v[i];
        size_t j = i;
        while (j > 0 && compareStudents(key, v[j - 1])) 
        {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = key;
    }
}


int main() 
{
    std::ifstream input("input.txt");
    if (!input) 
    {
        std::cerr << "Unable to open file input.txt\n";
        return 1;
    }

    int n;
    input >> n;

    std::vector<Student> students(n);

    for (int i = 0; i < n; ++i) 
    {
        Student& s = students[i];
        input >> s.lastName >> s.firstName >> s.middleName;
        input >> s.birthDate.year >> s.birthDate.month >> s.birthDate.day;
        for (int j = 0; j < 5; ++j) 
        {
            input >> s.grades[j];
        }
    }

    // Select sorting by 10%3 rule
    switch (10 % 3) 
    {
    case 0:
        bubbleSort(students);
        break;
    case 1:
        selectionSort(students);
        break;
    case 2:
        insertionSort(students);
        break;
    }

    std::ofstream output("output.txt");
    if (!output) 
    {
        std::cerr << "Unable to open file output.txt\n";
        return 1;
    }

    for (const Student& s : students) 
    {
        output << s.lastName << " " << s.firstName << " " << s.middleName << " ";
        output << s.birthDate.year << " " << s.birthDate.month << " " << s.birthDate.day << " ";
        for (int grade : s.grades) 
        {
            output << grade << " ";
        }
        output << "\n";
    }

    return 0;
}
