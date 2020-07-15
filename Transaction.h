#include<iostream>
using namespace std;
class Transaction
{

private:
    string stockCode;
    string description;
    int quantity;
    Transaction* next;

public:
    Transaction(string stockCode, string description, int quantity)
    {
        this->stockCode = stockCode;
        this->description = description;
        this->quantity = quantity;
        this->next = NULL;
    }

    string getStockCode()
    {
        return this->stockCode;
    }
    void setStockCode(string stockCode)
    {
        this->stockCode = stockCode;
    }

    string getDescription()
    {
        return this->description;
    }
    void setDescription(string description)
    {
        this->description = description;
    }

    int getQuantity()
    {
        return this->quantity;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    void addQuantity(int addQuantity)
    {
        this->quantity = this->quantity + addQuantity;
    }

    Transaction* getNext()
    {
        return this->next;
    }
    void setNext(Transaction* nextTransaction)
    {
        this->next = nextTransaction;
    }
};
