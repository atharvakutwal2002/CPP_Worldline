#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error: Couldn't create socket\n";
        return 1;
    }

    // Bind socket to port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Error: Couldn't bind socket\n";
        return 1;
    }

    // Listen for connections
    if (listen(serverSocket, 5) == -1) {
        cerr << "Error: Couldn't listen on socket\n";
        return 1;
    }

    // Accept connections
    sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
    if (clientSocket == -1) {
        cerr << "Error: Couldn't accept incoming connection\n";
        return 1;
    }

    // Continuous communication loop
    while (true) {
        // Receive message from client
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == -1) {
            cerr << "Error: Couldn't receive message from client\n";
            return 1;
        }
        buffer[bytesReceived] = '\0';
        cout << "Received message from client: " << buffer << endl;

        // Check if the client wants to close the connection
        if (strcmp(buffer, "exit") == 0) {
            cout << "Client requested to close the connection. Closing..." << endl;
            break;
        }

        // Get message from server input
        cout << "Enter message to send to client: ";
        string message;
        getline(cin, message);

        // Send message to client
        int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
        if (bytesSent == -1) {
            cerr << "Error: Couldn't send message to client\n";
            return 1;
        }
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
