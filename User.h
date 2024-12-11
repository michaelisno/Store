#pragma once
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

class User 
{
private:
    string m_name;
    float m_money;

    vector<Product> m_retailInventory;
    vector<Product> m_serviceInventory;

public:
    User(string name, int money);

    string GetName() const { return m_name; }

    float GetMoney() const { return m_money; }
    void DisplayInventory();

    void TakeMoney(float amount) { m_money -= amount; }
    void AddToRetailInventory(Product product);
    void AddToServiceInventory(Product service);

};