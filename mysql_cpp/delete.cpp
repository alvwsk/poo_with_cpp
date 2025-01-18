#include <iostream>
#include <mysql.h>
#include <cstring>

int main(int argc, char* argv[])
{
    std::string del, id;
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

        // std::cout << "Informe o id: ";
        // std::getline(std::cin, id);

        if(argc > 1)
        {
            id = argv[1];
        }
        else
        {
            std::cout << "Use: " << argv[0] << " [id]" << std::endl;
            return 1;
        }

        del = "DELETE FROM usuarios WHERE id =" + id;

        bool query_state = mysql_query(connect, del.c_str());
        // bool query_state = mysql_query(connect, delete.data());  Também correto (C++17+)

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

// g++ delete.cpp -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o delete && ./delete 