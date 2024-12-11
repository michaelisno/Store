#include "User.h"
#include <iostream>

User::User(string name, int money)
{
    m_name = name;
    m_money = money;
}

void User::AddToRetailInventory(Product product) 
{
    m_retailInventory.push_back(product);
}

void User::AddToServiceInventory(Product service)
{
    m_serviceInventory.push_back(service);
}

void User::DisplayInventory()
{
    if (m_retailInventory.size() != 0 || m_serviceInventory.size() != 0)
    {
        cout << endl << "You're Leaving With:" << endl;
    }

    if (m_retailInventory.size() != 0)
    {
        cout << "Retail: " << endl;
        for (Product product : m_retailInventory)
        {
            cout << "- " << product.GetName() << endl;
        }
    }

    if (m_serviceInventory.size() != 0)
    {
        cout << endl << "Services: " << endl;
        for (Product product : m_serviceInventory)
        {
            cout << "- " << product.GetName() << endl;
        }
    }
}