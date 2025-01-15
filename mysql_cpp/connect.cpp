#include <iostream>
#include <mysql.h>

int main()
{
    MYSQL * connect;
    connect = mysql_init(NULL);

    if(!connect)
    {
        std::cout << "MYSQL nao inicializado" << std::endl;
        return 1;
    }

    connect = mysql_real_connect(connect, "localhost", "root", "StrongPassword123!", "cpp", 0, NULL, 0);

    if(connect)
    {
        std::cout << "sucess" << std::endl;
    }
    else
    {
        std::cout << "fail" << std::endl;
    }

    mysql_close(connect);

    return 0;
}

