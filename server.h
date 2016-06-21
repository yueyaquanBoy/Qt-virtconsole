#ifndef SERVER_H
#define SERVER_H


#include "eccloud.h"

class Server
{
    QString server_name;
    virConnectPtr conn;

public:
    Server(QString name);
    ~Server();
    void update_server_name(QString name);
    int connect_server();
    void disconnect_server();
};

#endif // SERVER_H
