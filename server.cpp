#include "server.h"


Server::Server(QString name)
{
server_name=name;
}
int Server::connect_server()
{
    virError err;
    //virSetErrorFunc(NULL, customErrorFunc);
    conn = virConnectOpen(server_name.toStdString().c_str());
    if (conn == NULL) {
    fprintf(stderr, "Failed to open connection to qemu:///system\n");
    return 1;
    }

    return 0;
}
void Server::update_server_name(QString name){
    server_name=name;
}
void Server::disconnect_server()
{
    virConnectClose(conn);
}

Server::~Server()
{
virConnectClose(conn);
std::cout<<"closed";
}
