#include <iostream>
#include <memory>

struct connection {
    std::string ip;
    int port;
    connection(const std::string& ip_, const int port_) : ip(ip_), port(port_) {}
};

struct destination {
    std::string ip;
    int port;
    destination(const std::string& ip_, const int port_) : ip(ip_), port(port_) {}
};

connection connect(destination* ds)
{
    std::shared_ptr<connection> pConn(new connection(ds->ip, ds->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection conn)
{
    std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
              << std::endl;
}

void end_connect(connection* conn)
{
    disconnect(*conn);
}

void f(destination& ds)
{
    connection conn = connect(&ds);
    std::shared_ptr<connection> p(&conn, [](connection* p) {end_connect(p);});
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
    destination ds("192.168.5.3", 3306);
    f(ds);
}
