#include<iostream>
#include<string>
#include"Data.h"
enum class Gander{
    male,
    female
};
class Emploree
{
private:
 
    std::string name;
    Gander gender;
    Data birthday;
public:
    void setname(std::string name){this ->name = name;};
    void setgender(Gander gender){this -> gender = gender;};
    void setbir(Data birthday){this -> birthday = birthday;};
    std::string getname(){return name;};
    Gander getgender(){return gender;};
    Data* getbir(){return &birthday;};
    std::string toString()
    {
        return((name) + " "+(gender == Gander::male ?std::string("male"):std::string("female")) +" "+ birthday.toString());
    };
    Emploree(std::string name ,Gander gender, Data birthday):name{name},gender{gender},birthday{birthday} {};
    Emploree():Emploree("seven",Gander::male,Data(1999,11,21)){}
};

