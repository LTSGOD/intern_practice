#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#include "msg_data.h"

int main()
{
    int i;
    const char* name = "SHM_TEST";                  // Name of the shared memory object    
    int shm_fd;                                     // File descriptor for shared memory
    void* shmPointer;                               // Pointer to shared memory object
    int messageSize = sizeof(messageStruct);        // Size of message
    messageStruct ReceiveMessage[MESSAGE_TOTAL];    // Receive 할 메세지 배열
     
    /* Create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm open fail");
    }
 
    /* Map the shared memory object */
    shmPointer = (unsigned char*)mmap(0, messageSize*MESSAGE_TOTAL, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    
    /* Read messages into the shared memory object */
    for (i = 0; i < MESSAGE_TOTAL; i++) {
        memcpy(ReceiveMessage + i, shmPointer + messageSize * i, messageSize);
    }
         
    /* Unmap shared memory */
    munmap(shmPointer, messageSize*MESSAGE_TOTAL);
    
    /* Close shared memory communication */
    close(shm_fd);

    for (i = 0; i < MESSAGE_TOTAL; i++) {
        printf("Read %s and %f into %dth area.\n", ReceiveMessage[i].name, ReceiveMessage[i].value, i);
    }

    return 0;
}