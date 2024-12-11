#pragma once
#include <string>

using namespace std;

class Product {
private:
    string m_name;
    float m_price;
    int m_uniqueId;

public:
    Product(string name, float price, int uniqueId);

    string GetName() const { return m_name; }
    float GetPrice() const { return m_price; }
    int GetUniqueId() const { return m_uniqueId; }
};
