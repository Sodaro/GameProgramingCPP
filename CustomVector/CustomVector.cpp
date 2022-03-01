#include <iostream>
#include <vector>


template <typename T>
class coolVector
{
    typedef T* t_ptr;
    size_t count, capacity;

    t_ptr data;

    void grow_size()
    {
        size_t oldCapacity = capacity;
        capacity *= 2;
        t_ptr newData = new T[capacity];
        for (int i = 0; i < oldCapacity; i++)
        {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
    }

public:
    coolVector()
    {
        count = 0;
        capacity = 1;
        data = new T[capacity];
    }
    t_ptr begin() const
    {
        return &data[0];
    }
    t_ptr end() const
    { 
        return &(data[count]);
    }
    size_t size() const
    {
        return count;
    }
    void push_back(const T& element)
    {
        if (count == capacity)
        {
            grow_size();
        }
        count += 1;
        data[count - 1] = element;
    }
    void push_back(T&& element)
    {
        if (count == capacity)
        {
            grow_size();
        }
        count += 1;
        data[count - 1] = element;
    }
    T& pop_back()
    {
        if (count == 0)
            return *data;

        return data[--count];
    }
    T& operator[](int index) const
    {
        if (index >= count)
            return *data;

        return data[index];
    }
};

class test
{

public:
    int* x;
    int* y;
    test()
    {
        this->x = new int;
        this->y = new int;
    }
    test(int x, int y)
    {
        this->x = new int(x);
        this->y = new int(y);
    }
    test(const test& other)
    {
        //std::cout << "copy ctor" << std::endl;
        this->x = new int(*other.x);
        this->y = new int(*other.y);
    }
    test(test&& other)
    {
        //std::cout << "move ctor" << std::endl;
        x = other.x;
        y = other.y;
        other.x = other.y = nullptr;
    }

    test& operator = (const test& other)
    {
        //std::cout << "copy assignment" << std::endl;
        *this->x = *other.x;
        *this->y = *other.y;
        return *this;
    }
    test& operator = (test&& other)
    {
        //std::cout << "move assignment" << std::endl;
        this->x = other.x;
        this->y = other.y;
        other.x = other.y = nullptr;
        return *this;
    }
    ~test()
    {
        if (x != nullptr)
            delete x;

        if (y != nullptr)
            delete y;
    }
};
template <typename T>
void printArray(const coolVector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
}
template <typename T>

void printArrayV2(const coolVector<T>&vec)
{
    for (auto var : vec)
    {
        std::cout << var << ", ";
    }
}

int main()
{
    coolVector<int> intVec;
    coolVector<float> floatVec;
    coolVector<test> testVec;

    for (int i = 0; i < 10; i++)
    {
        intVec.push_back(i);
        floatVec.push_back((float)i / 10);
    }

    printArray(intVec);
    std::cout << std::endl;
    printArrayV2(intVec);
    std::cout << std::endl;
    
    while (intVec.size() > 0)
    {
        std::cout << intVec.pop_back() << ", ";
    }
    std::cout << std::endl;

    for (auto ptr = floatVec.end(); ptr > floatVec.begin(); ptr--)
    {
        std::cout << floatVec.pop_back() << ", ";
    }
    std::cout << std::endl;

    testVec.push_back(test(100, 300));
    std::cout << std::endl;
    testVec.push_back(test(200, 300));
    std::cout << std::endl;
    testVec.push_back(test(300, 300));
    std::cout << std::endl;
    testVec.push_back(test(400, 300));

    std::vector<test> noobvector;
    noobvector.push_back(test(100, 300));
    std::cout << std::endl;
    noobvector.push_back(test(200, 300));
    std::cout << std::endl;
    noobvector.push_back(test(300, 300));
    std::cout << std::endl;
    noobvector.push_back(test(400, 300));
}