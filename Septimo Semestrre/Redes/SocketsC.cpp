// Client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>

#define PORT 19056
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    int ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in ServerAddr;
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "172.16.114.89", &ServerAddr.sin_addr);

    if (connect(ClientSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    char message[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    while (true) {
        cout << "Enter message (type 'exit' to quit): ";
        cin.getline(message, BUFFER_SIZE);

        if (strcmp(message, "exit") == 0) {
            break;
        }

        send(ClientSocket, message, strlen(message), 0);

        // Recibir respuesta del servidor
        int bytesReceived = recv(ClientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Null-terminate the received string
            cout << "Message from server: " << buffer << endl;
        }
    }

    close(ClientSocket);
    return 0;
}