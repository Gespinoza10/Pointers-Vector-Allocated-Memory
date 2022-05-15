/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Gerardo Espinoza
//May 13, 2022
//Programming assignment #4

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
//structure to use for this program
struct ItemStruct{
    string ProductId;
    int NumSold;
    };
//function prototypes
void readDailySales(ifstream &, string &, int &);
void linearSearch(vector <ItemStruct*> &,const string &, int);
void writeOutput(ofstream &, vector <ItemStruct*> &, int total);

int main()
{   //open to read data
    ifstream inFile;
    inFile.open("DailySales.txt");
    //open file to write output
    ofstream outFile;
    outFile.open("SummaryDailySales.txt");
    //check reading file was opened successfully
    if(!outFile){
        cout<<"There was an error opening SummaryDailySales.txt! ";
        return 0;
    }
    //check our output file was opened successfully
    if(!inFile){
        cout<<"There was an error opening DailySales.txt! ";
        return 0;
    }
    
    //variables that will hold input data
    string productID;
    int numSold;
    int totalSold=0;
    //vector datatype=ItemStruct<-*pointer
    vector <ItemStruct*> productVec; 
    
    while(!inFile.eof()){   //loop until the end of file
    //function, read our product id and number sold
    readDailySales(inFile, productID, numSold);
    //function, search vector for the same product id, and allocate memory
    linearSearch(productVec, productID, numSold);
    
    }
    //function, to write the ouput to a file
    writeOutput(outFile, productVec, totalSold);
    //close input file
    inFile.close();
    //close output file
    outFile.close();
}
//function definitions
void readDailySales(ifstream &inFile,string &productID, int &numSold){
    inFile>>productID>>numSold;
    
}

void linearSearch(vector <ItemStruct*> &vector,const string &productID, int numSold){
    
    bool found = false;
    
    for(int index=0; index < vector.size(); index++){
        
        if(vector.at(index)->ProductId == productID){
            vector.at(index)->NumSold += numSold;
            
            found = true;
            break;
        }
    }
    
    if(found == false){
        ItemStruct* itemInfoPtr = new ItemStruct;
        
        itemInfoPtr->ProductId = productID;
        itemInfoPtr->NumSold = numSold;
        
        vector.push_back(itemInfoPtr);
    }
}

void writeOutput(ofstream &outFile, vector <ItemStruct*> &vector, int total){
    int totalSold=0;
    
    int ProductIdFormat=9, numSoldFormat=6, totalFormat=9, totalSoldFormat=6;
    
    outFile<<left<<setw(9)<<"Prod ID  # Sold"<<endl;
    outFile<<"-------  ------"<<endl;
    
    for(int index=0; index < vector.size(); index++){
        
        if(vector.at(index)->NumSold != 0){
            
            totalSold += vector[index]->NumSold;
            
            outFile<<left<<setw(ProductIdFormat)<<vector[index]->ProductId<<right<<setw(numSoldFormat)<<vector[index]->NumSold<<endl;
        }
        
        delete vector.at(index);
        vector.at(index) = nullptr;
    }
    
outFile<<"---------------"<<endl;   
outFile<<left<<setw(totalFormat)<<"Total"<<setw(totalSoldFormat)<<right<<totalSold;

    
}
