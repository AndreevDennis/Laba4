//
//  main.cpp
//  Laba4
//
//  Created by Денис Андреев on 6/13/19.
//  Copyright © 2019 Денис Андреев. All rights reserved.
//



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myfunction(int i) {  // function:
    cout << ' ' << i;
}

template <typename ItemType>
class myVector {
private:
    int vect_size;
    int max_size;
    ItemType* array;
public:
    class Iterator;
    myVector() {
        max_size = 10;
        array = new ItemType[max_size];
        vect_size = 0;
    }
    void clear() {
        delete[] array;
        vect_size = 0;
    }
    
    void push_back(ItemType element_to_add) {
        array[vect_size] = element_to_add;
        vect_size++;
    }
    void push_front(ItemType element_to_add) {
        ItemType * arr = new ItemType[vect_size + 1];
        for (int i = 0; i < 1; i++)
        {
            arr[i] = element_to_add;
            for (int j = 1; j <= getSize(); j++)
            {
                arr[j] = array[j-1];
            }
        }
        array = arr;
        vect_size++;
    }
    
    
    void pop_back() {
        vect_size--;
    }
    
    int getSize() {
        return vect_size;
    }
    
    ItemType operator[](int i) {
        return array[i];
        
    }
    Iterator begin() {
        return array;
    }
    Iterator end() {
        return array + getSize();
    }
    class Iterator {
        ItemType* cur;
    public:
        Iterator(ItemType* first) : cur(first){}
        ItemType& operator+ (int n) { return *(cur + n); }
        ItemType& operator- (int n) { return *(cur - n); }
        
        ItemType& operator++ (int) { return *cur++; }
        ItemType& operator-- (int) { return *cur--; }
        ItemType& operator++ () { return *++cur; }
        ItemType& operator-- () { return *--cur; }
        
        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }
        ItemType& operator* () { return*cur; }
    };
};

int main()
{
    setlocale(LC_ALL, "ru");
    
    myVector<int> mv;
    mv.push_back(2);
    mv.push_back(223);
    mv.push_back(34);
    mv.push_back(298);
    vector<int>v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    
    for_each(v.begin(), v.end(), myfunction);
    cout << endl;
    for_each(mv.begin(), mv.end(), myfunction);
    
    /*for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.pop_back();
     cout << "===============================================================" << endl;
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.clear();
     cout << "===============================================================" << endl;
     mv.push_back(34);
     mv.push_back(124);
     mv.push_back(53);
     mv.push_back(1);
     mv.push_back(8);
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.pop_back();
     cout << "===============================================================" << endl;
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.push_front(6661);
     cout << "===============================================================" << endl;
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.push_back(333);
     cout << "===============================================================" << endl;
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     mv.pop_back();
     cout << "===============================================================" << endl;
     for (int i = 0; i < mv.getSize(); i++)
     {
     cout << mv[i] << endl;
     }
     cout << "===============================================================" << endl;
     for (myVector<int>::Iterator it = mv.begin(); it != mv.end(); ++it)
     {
     cout << ' ' << *it << endl;
     }*/
    
    return 0;
}
