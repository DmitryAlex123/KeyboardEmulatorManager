#include <iostream>
#include <WinSock2.h>
#include "Device.cpp"


#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main()
{
    WSADATA ws;
    WSAStartup(MAKEWORD(2, 2), &ws); //загрузка либы
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0); //создание AF_NET - это ip v4 | SOCK_STREAM - протокол tcp
    SOCKADDR_IN sa; //структура настроек соединения
    ZeroMemory(&sa, sizeof(sa));
    //memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1010); //это было заполнение структуры
    bind(s, (SOCKADDR*)&sa, sizeof(sa));
    listen(s, 100);

    SOCKET client_socket; //данные от подкл клиента
    SOCKADDR_IN client_addr;
    int client_addr_size = sizeof(client_addr);

    char buf[1];
    ZeroMemory(buf, 1);
    //memset(buf, 0, sizeof(buf));

  
    Device *dev = new Device();

    while (client_socket = accept(s, (SOCKADDR*)&client_addr, &client_addr_size))
    {
        printf("Connection OK!\n");
        while (recv(client_socket, buf, sizeof(buf), 0) > 0) {
                printf("%d\n", buf[0]);   
                dev->sendCommand();
        }
        
    }
    closesocket(s);
    WSACleanup();
    return 0;
}

