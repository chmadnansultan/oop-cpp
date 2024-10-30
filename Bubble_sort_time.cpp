#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
class Bubble_sort
{
private:
    int *array;
    int size;

public:
    void setvalues(int n)
    {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = i + 2;
        } 
        std::cout << std::endl;
    }
    void bubble_sort()
    {
        int temp;
        bool iteration = false;
        for (int i = 1; i < size; i++)
        {
            iteration = true;

            for (int j = 0; j < size - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    iteration = false;
                }
            }
            if (iteration == true)
            {
                cout << "Array is sorted " << endl;
                return;
            }
        }
    }
    void random_number(int n)
    {
        size = n;
        array = new int[size];
        int num;
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            num = (rand() % 10 + 1);
            array[i] = num;
        }
    }
    void print()
    {
        cout << "value are : ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << "   ";
        }
        cout << "----------------------------------\n";
    }
    ~Bubble_sort()
    {
        delete[] array;
    }
};

int main()
{

    Bubble_sort obj_1, obj_2;
    int n = 5;

    obj_1.setvalues(n);
    std::cout << "Simple Array is:" << std::endl;
    obj_1.print();

    auto start = std::chrono::steady_clock::now();
    obj_1.bubble_sort();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    float ms = elapsed_seconds.count() * 1000;
    std::cout << "Sorting took " << ms << " ms" << std::endl;

   obj_2.random_number(n);

    std::cout << "Array of random numbers before sort:" << std::endl;
    obj_2.print();

    start = std::chrono::steady_clock::now();

    obj_2.bubble_sort();
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;

    ms = elapsed_seconds.count() * 1000;

    std::cout << "Array of random numbers after sort:" << std::endl;
    obj_2.print();

    std::cout << "Sorting took " << ms << " ms" << std::endl;

    return 0;
}