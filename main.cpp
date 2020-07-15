#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

void swap(Transaction* tr1, Transaction* tr2)
{ 
    string tmpStockCode = tr1->getStockCode();
    string tmpDescripton = tr1->getDescription();
    int tmpQuantity = tr1->getQuantity();

    tr1->setStockCode(tr2->getStockCode());
    tr1->setDescription(tr2->getDescription());
    tr1->setQuantity(tr2->getQuantity());

    tr2->setStockCode(tmpStockCode);
    tr2->setDescription(tmpDescripton);
    tr2->setQuantity(tmpQuantity);
} 

int main()
{
    LinkedList linkedList;
    ifstream theFile("OnlineRetail.csv");

    string  line, stockCode, description, invoiceDate, country, 
            invoiceNo, customerID, unitPrice;
    int quantity;
    char ch;
    time_t start,end;
    time (&start);

    theFile >> line; // Read first line

    while(getline(theFile, invoiceNo, ';')) // Read all lines
    {   
        getline(theFile, stockCode, ';');
        getline(theFile, description, ';');
        theFile >> quantity >> ch;
        getline(theFile, invoiceDate, ';');
        getline(theFile, unitPrice, ';');
        getline(theFile, customerID, ';');
        getline(theFile, country);
        linkedList.addTransaction(stockCode, description, quantity);
    }

    // Bubble Sort
    bool isThereAnySwap;
    Transaction* ptr;
    Transaction* ptr2 = NULL; 
    do
    { 
        isThereAnySwap = false; 
        ptr = linkedList.getFront(); 
  
        while (ptr->getNext() != ptr2) 
        { 
            if (ptr->getQuantity() < ptr->getNext()->getQuantity()) 
            {  
                isThereAnySwap = true;                 
                swap(ptr, ptr->getNext()); 
            } 
            ptr = ptr->getNext(); 
        } 
        ptr2 = ptr; 
    } 
    while (isThereAnySwap); 

    printf("Product (StockCode)\t\tDescription\t\t\t#TotalQuantity\n");
    Transaction* tmp = linkedList.getFront();
    for(int i=1;i<=10;i++) // Print top 10
    {
        cout << setw(2) << left << i << " - " << setw(20) << tmp->getStockCode() << " " << setw(40) << tmp->getDescription() << " " << setw(15) << tmp->getQuantity() << endl;
        tmp = tmp->getNext();
    }

    time (&end);
    double diff = difftime (end,start);
    cout << endl << "Total Elapsed Time: " << diff << " seconds" << endl;

    theFile.close();
    return 0;
}
