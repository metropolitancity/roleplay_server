#include <YSI_Coding\y_hooks>

new 
    MySQL:SQL_Connection = MYSQL_INVALID_HANDLE;

hook OnGameModeInit()
{
    print("Conectando-se ao banco de dados.");

    SQL_Connection = mysql_connect_file("database.ini");
    if ( SQL_Connection == MYSQL_INVALID_HANDLE || mysql_errno() != 0 )
    {
        print("\tL Não foi possível conectar ao banco de dados.");
        return Y_HOOKS_BREAK_RETURN_1;
    }

    print("- Banco de dados conectado.\n");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    mysql_close(SQL_Connection);
    SQL_Connection = MYSQL_INVALID_HANDLE;
    print("Fechando conexão com o banco de dados.");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

// =================================== [ TABELAS ] =================================== //
#define TABLE_USERS             "users"
#define TABLE_USERS_VEHICLES    ""TABLE_USERS"_vehicles"
#define TABLE_PROPERTY          "property"