#include <iostream>
#include <winsock.h>
#include <string>

int main() {
    std::cout << "Welcome, enter your IP to check ports" << std::endl;

    std::string ipUser;

    WSADATA wsadata;
    WORD DLLVersion = MAKEWORD(2, 1);

    if (WSAStartup(DLLVersion, &wsadata) != 0) {
        return -1;
    }

    std::cout << "Your IP: ";
    std::cin >> ipUser;

    SOCKADDR_IN addr;
    addr.sin_addr.s_addr = inet_addr(ipUser.c_str());
    addr.sin_family = AF_INET;

    for (int i = 0; i <= 1023; i++) {
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

        addr.sin_port = htons(i);

        if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) == 0) {
            std::cout << "Port " << i << " is open" << std::endl;
        }
        else {
            std::cout << "Port " << i << " is not open" << std::endl;
        }

        closesocket(sock);
    }  
}