#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Product.h"

using namespace std;

class Store
{
protected:
    string m_name;

    vector<Product> m_products;

public:
    Store() : m_name("Unknown Store") {}

    void AddProduct(Product product) { m_products.push_back(product); }

    string GetName() const { return m_name; }

    virtual void DisplayProducts() = 0;
    virtual bool BuyProduct(int index, User& user) = 0;
};