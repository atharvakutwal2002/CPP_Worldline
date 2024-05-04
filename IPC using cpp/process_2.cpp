#include <iostream>
#include <mqueue.h>
#include <cstring>

const char *QUEUE_NAME = "/my_queue";
const mode_t QUEUE_PERMISSIONS = 0660;

const size_t MAX_MSG_SIZE = 256;

int main()
{
    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, QUEUE_PERMISSIONS, nullptr);
    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        return 1;
    }

    char buffer[MAX_MSG_SIZE];
    ssize_t bytes_read = mq_receive(mq, buffer, MAX_MSG_SIZE, nullptr);
    if (bytes_read == -1)
    {
        perror("mq_receive");
        mq_close(mq);
        return 1;
    }

    std::cout << "Received message: " << buffer << std::endl;

    mq_close(mq);
    mq_unlink(QUEUE_NAME); // Unlink the queue to remove it from the system

    return 0;
}
