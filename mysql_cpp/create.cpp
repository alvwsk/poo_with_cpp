#include <iostream>
#include <mysql.h>
#include <cstring>

int main(int argc, char* argv[])
{
    std::string create, nome, email;
    MYSQL * connect;
    connect = mysql_init(NULL);

    connect = mysql_real_connect(connect, "localhost", "root", "StrongPassword123!", "cpp", 0, NULL, 0);

    try
    {
        if(!connect)
        {
            throw connect;
            return 1;
        }

        // std::cout << "Informe o nome: ";
        // std::getline(std::cin, nome);

        // std::cout << "Informe o e-mail: ";
        // std::getline(std::cin, email);

        if(argc > 2)
        {
            nome = argv[1];
            email = argv[2];
        }
        else
        {
            std::cout << "Use: " << argv[0] << " '[nome]' [email]" << std::endl;
            return 1;
        }

        create = "INSERT INTO usuarios VALUES(NULL, '" + nome + "', '" + email + "')";

        bool query_state = mysql_query(connect, create.c_str());
        // bool query_state = mysql_query(connect, create.data());  Também correto (C++17+)

        if(query_state) { std::cout << "error: " << mysql_error(connect) << std::endl; }

        std::cout << "sucess" << std::endl;
        mysql_close(connect);
    
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// g++ create.cpp -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o create && ./create 