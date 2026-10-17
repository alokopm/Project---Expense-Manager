#pragma once
#include<iostream>
#include<string>
using namespace std;   
class Transaction
{
private:
    int  id;
    string date;
    string type;
    string category;
    double amount;
    string description;
public:
    Transaction(int id,string date,string type,string category,double amount,string description){
        this->id = id;
        this->date = date;
        this->type = type;
        this->category = category;
        this->amount = amount;
        this->description  = description;
    }


    int getId() const{
        return id;
    }
    string getDate()const{
        return date;
    }
    string getType()const{
        return type;
    }
    string getCategory()const{
        return category;
    }
    double getAmount()const{
        return amount;
    }
    string getDescription()const{
        return description;
    }
    void display()const{
        cout<<id<<' '
            <<date<<' '
            <<type<<' '
            <<category<<' '
            <<amount<<' '
            <<description<<'\n';
    }
};