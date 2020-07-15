#include "Transaction.h"
class LinkedList
{
private:
    Transaction* front;
public:
    LinkedList()
    {
        front = NULL;
    }

    Transaction* getFront()
    {
        return this->front;
    }

    void addTransaction(string stockCode, string description, int quantity)
    {
        if(front == NULL) // List is empty
        {
            Transaction* newTransaction = new Transaction(stockCode, description, quantity);
            front = newTransaction;
        }
        else if(front->getStockCode() == stockCode) // Front is same
            front->addQuantity(quantity);
        else if(front->getStockCode() > stockCode) // Insertion to front is needed
        {
            Transaction* newTransaction = new Transaction(stockCode, description, quantity);
            newTransaction->setNext(front);
            front = newTransaction;
        }
        else
        {
            Transaction* tmp = front;
            // Find the right place
            while( (tmp->getNext() != NULL) && (tmp->getNext()->getStockCode() < stockCode) ) // 
                tmp = tmp->getNext();
            if( (tmp->getNext() != NULL) && (tmp->getNext()->getStockCode() == stockCode) ) // Already Exists 
                tmp->getNext()->addQuantity(quantity);
            else
            {
                Transaction* newTransaction = new Transaction(stockCode, description, quantity);
                newTransaction->setNext(tmp->getNext());
                tmp->setNext(newTransaction);
            }
        }
    }

    ~LinkedList()
    {
        Transaction* tmp;
        while(front->getNext() != NULL)
        {
            tmp = front->getNext();
            delete front;
            front = tmp;
        }
        delete front;
    }
};
