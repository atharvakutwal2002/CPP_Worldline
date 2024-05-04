#include <iostream>
#include <mqueue.h>
#include <cstring>

const char *QUEUE_NAME = "/my_queue";
const mode_t QUEUE_PERMISSIONS = 0660;

const size_t MAX_MSG_SIZE = 256;

int main() {
    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, QUEUE_PERMISSIONS, nullptr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    const char *message = "Hello from the sender!";
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        return 1;
    }
    
    std::cout << "Message sent successfully." << std::endl;

    mq_close(mq);

    return 0;
}
