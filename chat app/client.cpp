#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

using namespace std;

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Error: Couldn't create socket\n";
        return 1;
    }

    // Connect to server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Error: Couldn't connect to server\n";
        return 1;
    }

    // Continuous communication loop
    while (true) {
        // Get message from user
        cout << "Enter message: ";
        string message;
        getline(cin, message);

        // Send message to server
        int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
        if (bytesSent == -1) {
            cerr << "Error: Couldn't send message to server\n";
            return 1;
        }

        // Check if user wants to close the connection
        if (message == "exit") {
            cout << "Closing connection..." << endl;
            break;
        }

        // Receive response from server
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == -1) {
            cerr << "Error: Couldn't receive response from server\n";
            return 1;
        }
        buffer[bytesReceived] = '\0';
        cout << "Received response from server: " << buffer << endl;
    }

    // Close socket
    close(clientSocket);

    return 0;
}
