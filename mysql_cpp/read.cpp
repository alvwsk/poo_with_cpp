#include <iostream>
#include <mysql.h>

int main()
{
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

        MYSQL_RES * res_set;
        MYSQL_ROW row;

        mysql_query(connect, "SELECT * FROM usuarios");

        res_set = mysql_store_result(connect);

        unsigned int num_rows = mysql_num_rows(res_set);

        while((row = mysql_fetch_row(res_set)) != NULL)
        {
            std::cout << row[0] << " | " << row[1] << " - " << row[2] << std::endl; 
        }

        mysql_close(connect);
    
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// g++ read.cpp -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -o read && ./read 
