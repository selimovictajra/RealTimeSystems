#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

int maxSize = 10;
std::vector<std::string> students;

bool FindManually(std::string name)
{
    for (int i = 0; i < maxSize; i++)
        if (students[i] == name)
            return true;
    return false;
}

bool FindAutomatically(std::string name)
{
    return (std::find(students.begin(), students.end(), name) != students.end());
}

int main()
{
    maxSize = 1000000;
    int noOfRepetitions = 100;

    for (int i = 0; i < maxSize; i++)
        students.push_back("Name " + std::to_string(i));

    std::string indexToFind = std::to_string(int(maxSize - 1));

    for (int j = 0; j < 2; j++)
    {
        std::cout << (j == 0 ? "FindManually (ms)" : "FindAutomatically (ms)") << std::endl;

        for (int i = 0; i < noOfRepetitions; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();

            if (j == 0)
                FindManually("Name " + indexToFind);
            else
                FindAutomatically("Name " + indexToFind);

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

            std::cout << duration << " ";
        }

        std::cout << std::endl;
    }

    system("pause>0");
}
