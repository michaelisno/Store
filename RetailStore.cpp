#include "RetailStore.h"
#include <iostream>

RetailStore::RetailStore(string name)
{
    Store::m_name = name;
}

void RetailStore::DisplayProducts()
{
    cout << "Welcome to " << m_name << "! List of Available Procuts: " << endl;

    for (int i = 0; i < m_products.size(); ++i) 
    {
        cout << (i + 1) << ": " << m_products[i].GetName() << " --- £" << m_products[i].GetPrice() << endl;
    }
}

bool RetailStore::BuyProduct(int index, User& user) 
{
    if (index < 1 || index > m_products.size()) 
    {
        cout << "Error: Invalid product index." << endl;
        return false;
    }

    Product& product = m_products[index - 1];

    if (user.GetMoney() >= product.GetPrice()) 
    {
        user.TakeMoney(product.GetPrice());
        user.AddToRetailInventory(product);

        cout << "You bought " << product.GetName() << " for £" << product.GetPrice() << endl;
        return true;
    }
    else 
    {
        cout << "Error: Not enough money to buy " << product.GetName() << endl;
        return false;
    }
}