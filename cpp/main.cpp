#include"emploree.h"
#include"Data.h"


int main()
{
    Emploree e;
    Data* data1 = nullptr;
    e.setname("hig ");
    e.setbir(Data(2002,10,30));
    std::cout << e.toString() << std::endl;
    e.getbir()->setYear(2000);
    std::cout << e.toString() << std::endl;
    Emploree ee;
    ee.setname("yuan");
    ee.setgender(Gander::female);
    ee.setbir(Data(2002,11,21));
    std::cout << ee.toString() << std::endl;
    std::cout << ee.getbir() ->toString()<< std::endl;
    std::cout << ee.getbir() ->getYear()<< std::endl;
    std::cout << ee.getname() << std::endl;
    std:: cout << static_cast<int>(ee.getgender()) << std::endl;
    //枚举类型不能直接作为cout函数的输出值需要进行类型转换
    return 0;
}

