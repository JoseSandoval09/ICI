// Sockets.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>

#define PORT 19056  
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    int ServerSockets = socket(AF_INET, SOCK_STREAM, 0);

    cout << "Server socket created" << endl;

    struct sockaddr_in ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(PORT);
  inet_pton(AF_INET, "172.16.114.12", &ServerAddr.sin_addr);

    cout << "Binding..." << endl;

    bind(ServerSockets, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    listen(ServerSockets, 5);

    cout << "Listening..." << endl;

    int ClientSockets = accept(ServerSockets, NULL, NULL);

    char buffer[BUFFER_SIZE] = {0};
    recv(ClientSockets, buffer, BUFFER_SIZE, 0);

    cout << "Message from client: " << buffer << endl;

    // Invertir el mensaje
  int len = strlen(buffer);
  for (int i = 0; i < len / 2; ++i) {
      swap(buffer[i], buffer[len - i - 1]);
  }

  // Convertir el mensaje a mayúsculas
  for (int i = 0; i < len; ++i) {
      buffer[i] = toupper(buffer[i]);
  }
  
  

    cout << "Reversed and uppercased message: " << buffer << endl;

    // Enviar el mensaje modificado de vuelta al cliente
    send(ClientSockets, buffer, strlen(buffer), 0);

    cout << "Reversed message: " << buffer << endl;

    close(ClientSockets);
    close(ServerSockets);

    return 0;
}

