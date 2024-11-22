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
    
    messageStruct messageToSend[MESSAGE_TOTAL] = {
        {"Alice", 1.23}, {"Bob", 4.56}, {"Carol", 7.89}, {"David", 0.12}, {"Erwin", 3.45}
    };                                              // Message to send
     
    /* Create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
 
    /* Configure the size of the shared memory object */
    if (ftruncate(shm_fd, messageSize*MESSAGE_TOTAL) == -1) {
        printf("ftruncate failed.\n");
        return -1;
    }
 
    /* Map the shared memory object */
    shmPointer = (unsigned char*)mmap(0, messageSize*MESSAGE_TOTAL, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    
    /* Write messages into the shared memory object */
    for (i = 0; i < MESSAGE_TOTAL; i++) {
        memcpy(shmPointer + messageSize*i, &messageToSend[i], messageSize);
    }
         
    /* Unmap shared memory */
    munmap(shmPointer, messageSize*MESSAGE_TOTAL);
    
    /* Close shared memory communication */
    close(shm_fd);

    for (i = 0; i < MESSAGE_TOTAL; i++) {
        printf("Wrote %s and %f into %dth area.\n", messageToSend[i].name, messageToSend[i].value, i);
    }

    return 0;
}