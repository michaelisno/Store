#include "ServiceStore.h"
#include <iostream>

ServiceStore::ServiceStore(string name)
{
    Store::m_name = name;
}

void ServiceStore::DisplayProducts() 
{
    cout << "Welcome to " << m_name << "! Here are the services we offer:" << endl;

    for (int i = 0; i < m_products.size(); ++i)
    {
        cout << (i + 1) << ": " << m_products[i].GetName() << " - £" << m_products[i].GetPrice() << endl;
    }
}

bool ServiceStore::BuyProduct(int index, User& user) 
{
    if (index < 1 || index > m_products.size()) 
    {
        cout << "Error: Invalid service index." << endl;
        return false;
    }

    Product& service = m_products[index - 1];

    if (user.GetMoney() >= service.GetPrice()) 
    {
        user.TakeMoney(service.GetPrice());
        user.AddToServiceInventory(service);

        cout << "You purchased the " << service.GetName() << " service for £" << service.GetPrice() << endl;
        return true;
    }
    else 
    {
        cout << "Error: Not enough money to purchase the " << service.GetName() << " service." << endl;
        return false;
    }
}