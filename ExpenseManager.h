#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include"Transaction.h"

using namespace std;

class ExpenseManager{
private:
    vector<Transaction> transactions;
public: 
    void addTransaction(const Transaction& transaction){
        transactions.push_back(transaction);
    }
    void viewTransactions() const{
        for(const Transaction& t : transactions){
            t.display();
        }
    }
    void deleteTransaction(int id){
        int i= 0;
        for(const Transaction &t : transactions){
            if(t.getId()==id){
                break;
            }else{
                i++;
            }
        }
        if(i<transactions.size()){
            transactions.erase(transactions.begin()+i);
            cout<<"Transaction deleted successfully.\n";
        }else{
            cout<<"Transaction not found.\n";
        }
    }
    void searchTransaction(int id) const{
        for(const auto &t : transactions){
            if(t.getId()==id){
                t.display();
                return;
            }
        }
        cout<<"Transaction not found!!\n";
    }
    bool checkDuplicate(int id)const{
        for(const auto &t : transactions){
            if(t.getId() == id){
                return false;
            }
        }
        return true;
    }
    void filterByCategory(const string &category) const{
        bool found = false;
        for(const auto& t: transactions){
            if(category == t.getCategory()){
                t.display();
                found = true;
            }
        }
        if(!found){
            cout<< "No transactions found in this category.\n";
        }
    }
    void sortByAmount(){
        sort(transactions.begin(),transactions.end(),[](const Transaction & t1,const Transaction &t2){
            return t1.getAmount()<t2.getAmount();
        });
    }
    double getTotalExpenses() const{
        double totalExpense = 0;
        for(const auto & t: transactions){
            if(t.getType()=="expense"){
                totalExpense += t.getAmount();
            }
        }
        return totalExpense;
    }
    double getTotalIncome() const{
        double totalIncome = 0;
        for(const auto& t:transactions){
            if(t.getType()=="income"){
                totalIncome += t.getAmount();
            }
        }
        return totalIncome;
    }

    double getBalance() const{
        return getTotalIncome() - getTotalExpenses();
    }

    double getHighestExpense() const{
        double highestExpense = 0;
        for(const auto &t: transactions){
            if(t.getType()=="expense"){
                highestExpense = max(highestExpense,t.getAmount());
            }
        }
        return highestExpense;
    }

    map<string, double> getCategoryWiseExpenses() const {
        map<string, double> categoryExpenses;
        for(const auto &t: transactions){
            if(t.getType()=="expense"){
                categoryExpenses[t.getCategory()]+= t.getAmount();
            }
        }
        return categoryExpenses;
    }
    const vector<Transaction>& getTransactions() const{
        return transactions;
    }
    
};