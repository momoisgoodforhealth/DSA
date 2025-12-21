#include <iostream>
#include <vector>
using namespace std;

class MyHashMap{
    vector<int> mapArray;

    public:
    MyHashMap(){
        mapArray = vector<int>(1000001,-1);
    }
    void Put(int key, int value) {
        mapArray[key] = value;
    }

    int Get(int key) {
        return mapArray[key];
    }

    void Remove(int key) {
        mapArray[key] = -1;
    }
};