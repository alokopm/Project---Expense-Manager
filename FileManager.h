#pragma once
#include<iostream>
#include <iomanip>
#include<fstream>
#include<vector>
#include <sstream>
#include"Transaction.h"
#include"ExpenseManager.h"
using namespace std;

class FileManager{
public:
    void saveTransactions(const ExpenseManager& em){
        ofstream file("transactions.csv");
        if (!file.is_open()) {
            return;
        }
        file << fixed << setprecision(2);
        const vector<Transaction>& list = em.getTransactions();
        file << "id,date,type,category,amount,description\n";
        for(const auto &t : list){
            file<<t.getId()<<','
                <<t.getDate()<<','
                <<t.getType()<<','
                <<t.getCategory()<<','
                <<t.getAmount()<<','
                <<t.getDescription()<<'\n';
        }
        file.close();
    }
    void loadTransactions(ExpenseManager &em){
        ifstream file("transactions.csv");
        if (!file.is_open()) {
            return;
        }
        string line;
        getline(file, line);                 
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);           
            string id, date, type, category, amount, description;
            getline(ss, id, ',');            
            getline(ss, date, ',');
            getline(ss, type, ',');
            getline(ss, category, ',');
            getline(ss, amount, ',');
            getline(ss, description);    
            Transaction t(stoi(id), date, type, category, stod(amount), description);
            em.addTransaction(t);
        }
    }
};