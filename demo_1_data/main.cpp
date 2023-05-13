


//use C++ array to create a list

//#include <iostream>
//#include <stdexcept>
//
//template <typename T>
//class MyArrayList {
//private:
//    T* data;
//    int capacity;  // 最大容量
//    int size;  // 元素个数
//
//public:
//    MyArrayList(int capacity_ = 10) : capacity(capacity_), size(0) {
//        if (capacity <= 0) {
//            throw std::invalid_argument("Capacity must be positive!");
//        }
//
//        data = new T[capacity];
//    }
//
//    ~MyArrayList() {
//        delete[] data;
//    }
//
//    void push_back(const T& value) {
//        if (size >= capacity) {
//            int new_capacity = capacity * 2;
//            T* new_data = new T[new_capacity];
//
//            for (int i = 0; i < size; ++i) {
//                new_data[i] = data[i];
//            }
//
//            delete[] data;
//            data = new_data;
//            capacity = new_capacity;
//        }
//
//        data[size++] = value;
//    }
//
//    void insert(int index, const T& value) {
//        if (index < 0 || index > size) {
//            throw std::out_of_range("Index out of range!");
//        }
//
//        if (size >= capacity) {
//            int new_capacity = capacity * 2;
//            T* new_data = new T[new_capacity];
//
//            for (int i = 0; i < size; ++i) {
//                new_data[i] = data[i];
//            }
//
//            delete[] data;
//            data = new_data;
//            capacity = new_capacity;
//        }
//
//        // 把 i ~size-1 的元素后移一位
//        for (int i = size - 1; i >= index; --i)
//            data[i + 1] = data[i];
//
//        data[index] = value;
//
//        size++;
//    }
//
//    void erase(int index) {
//        if (index < 0 || index >= size) {
//            throw std::out_of_range("Index out of range!");
//        }
//
//        // 把 index+1 到size -1的元素前移
//        for (int i = index + 1; i < size; ++i) {
//            data[i - 1] = data[i];
//        }
//
//        size--;
//    }
//
//    T& operator[](int index) {
//        if (index < 0 || index >= size) {
//            throw std::out_of_range("Index out of range!");
//        }
//
//        return data[index];
//    }
//
//    const T& operator[](int index) const {
//        if (index < 0 || index >= size) {
//            throw std::out_of_range("Index out of range!");
//        }
//
//        return data[index];
//    }
//
//    int get_size() const {
//        return size;
//    }
//
//    bool empty() const {
//        return size == 0;
//    }
//
//    void clear() {
//        size = 0;
//    }
//
//    void print(std::ostream& os = std::cout) const {
//        for (int i = 0; i < size; ++i) {
//            os << data[i] << " ";
//        }
//        os << std::endl;
//    }
//};
//
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const MyArrayList<T>& list) {
//    list.print(os);
//    return os;
//}
//
//int main() {
//    MyArrayList<int> list1;
//
//    for (int i = 0; i < 10; i++) {
//        list1.push_back(i);
//    }
//
//    std::cout << "list1: " << list1 << ", size: " << list1.get_size() << std::endl;
//
//    list1.insert(2, 10);
//    std::cout << "list1: " << list1 << ", size: " << list1.get_size() << std::endl;
//
//    list1.erase(5);
//    std::cout << "list1: " << list1 << ", size: " << list1.get_size() << std::endl;
//
//    try {
//        list1[-1] = 100;
//    }
//    catch (std::out_of_range& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//
//    MyArrayList<std::string> list2;
//
//    list2.push_back("hello");
//    list2.push_back("world");
//    list2.insert(1, "morning");
//
//    std::cout << "list2: " << list2 << ", size: " << list2.get_size() << std::endl;
//
//    list2.clear();
//    std::cout << "list2 is cleared!" << std::endl;
//
//    return 0;
//}

//demo by myself

#include<iostream>
#include"MyArrayList.h"
using namespace std;

int main()
{
    MyArrayList<int> intList; // 创建一个空的整数型线性表
    for (int i = 1; i <= 100; i++) { // 插入100个整数到线性表中
        intList.insert(i);
    }
    cout << "Length: " << intList.GetLength() << endl;
    cout << "Elem at index 99: " << intList.GetElement(99) << endl;
    cout << "Element 88's index: " << intList.LocateElement(88) << endl;
    cout << "Delete element at index 66: " << intList.DeleteElement(66) << endl;
    cout << "Length: " << intList.GetLength() << endl;
    
    intList.clear(); // 清空整数型线性表
    cout << "Length after clear(): " << intList.GetLength() << endl;

    MyArrayList<string> strList; // 创建一个空的字符串型线性表
    strList.insert("hello");
    strList.insert("world");
    strList.insert("!");
    cout << "Length: " << strList.GetLength() << endl;
    cout << "Elem at index 2: " << strList.GetElement(2) << endl;
    cout << "Element \"world\"'s index: " << strList.LocateElement("world") << endl;
    cout << "Delete element at index 1: " << strList.DeleteElement(1) << endl;
    cout << "Length: " << strList.GetLength() << endl;
    strList.clear(); // 清空字符串型线性表
    cout << "Length after clear(): " << strList.GetLength() << endl;

    return 0;
}


