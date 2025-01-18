#include <iostream>
#include <mysql.h>
#include <cstring>

int main(int argc, char* argv[])
{
    std::string update, campo, id, new_campo;
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

        // std::cout << "Informe o campo: ";
        // std::getline(std::cin, campo);

        // std::cout << "Informe o novo campo: ";
        // std::getline(std::cin, new_campo);

        // std::cout << "Informe o id: ";
        // std::getline(std::cin, id);


        if(argc > 3)
        {
            campo = argv[1];
            new_campo = argv[2];
            id = argv[3];
        }
        else
        {
            std::cout << "Use: " << argv[0] << " ['campo'] ['novo campo'] [id]" << std::endl;
            return 1;
        }

        update = "UPDATE usuarios SET " + campo + "='" + new_campo + "' WHERE id =" + id;

        bool query_state = mysql_query(connect, update.c_str());
        // bool query_state = mysql_query(connect, update.data());  Também correto (C++17+)

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

// g++ update.cpp -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o update && ./update 