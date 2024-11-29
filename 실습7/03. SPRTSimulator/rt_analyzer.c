#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_TASK 100
#define INT_MAX 0x7FFFFFFF

#define INPUT_FILE_NAME "sched_param_rc.txt"

struct Task {
    char name[16];
    int ID;
    int period;
    int executionTime;
    int deadline;    
    int priority;  
    int releaseTime;
    int nextReleaseTime; // 다음 release 시간
    int nextDeadline; // 다음 데드라인 시간
    int remainTime; // Task 남은 수행 시간
    bool isReady; // ReadyQueue 상태 여부
    
    int responseTime;
} task[MAX_TASK];

float getTotalUtilization();
void startSimulating();

int taskCount = 0;

int readInput() {
    FILE *f;
    int i;
    char temp;

    f = fopen(INPUT_FILE_NAME, "r");
    if (f == NULL) {
        printf("Error: Failed to open %s.\n", INPUT_FILE_NAME);
        return -1;
    }

    fscanf(f, "%c ", &temp);

    for (i = 0; i < MAX_TASK; i++) {
        fscanf(f, "%s ", task[i].name);
        if (task[i].name[0] == '$') {
            fclose(f);
            break;
        }

        task[i].ID = i;
        fscanf(f, "%d ", &task[i].releaseTime);
        fscanf(f, "%d ", &task[i].period);
        fscanf(f, "%d ", &task[i].executionTime);
        fscanf(f, "%d ", &task[i].deadline);
        fscanf(f, "%d \n", &task[i].priority);
        task[i].responseTime = 0;
        taskCount++;
    }

    for (i = 0; i < taskCount; i++) {
        printf("Task %s: ", task[i].name);
        printf("Release time = %d, ", task[i].releaseTime);
        printf("Period = %d, ", task[i].period);
        printf("Execution time = %d, ", task[i].executionTime);
        printf("Deadline = %d, ", task[i].deadline);
        printf("Priority = %d\n", task[i].priority);
    }

    printf("\n");

    return taskCount;
}

int main() {
    

    readInput();

    //  초기 Task 세팅
    for (int i = 0; i < taskCount; i++) {
        task[i].nextReleaseTime = task[i].releaseTime; // 다음 Release 시간(Release 될 때 다음시간으로 초기화)
        task[i].nextDeadline = task[i].nextReleaseTime + task[i].deadline; // 다음 deadline 시간 (테스크 수행 완료시 다음 데드라인 갱신)
        task[i].isReady = false;
        task[i].remainTime = task[i].executionTime;
    }

    startSimulating();

    float totalUtilization = getTotalUtilization();

    printf("\nThe total utilization is %f and the task set is schedulable.\n", totalUtilization);

    return 0;
}

void startSimulating() {

    int time = 0;
    int selectedTask = -1;
    
    // 992250000
    while (time < 1000000) {

        // deadlock 기한 체크
        for (int i = 0; i < taskCount; i++) {

            // 현재 ready큐에 있는 task 중 deadline넘는 task 있는지 확인
            if (task[i].isReady && (time > task[i].nextDeadline)) {
                printf("Task %s miss time %d > deadline %d (Release Time: %d, deadline: %d)\n", task[i].name, time, task[i].nextDeadline,  task[i].nextReleaseTime - task[i].period ,task[i].nextDeadline);
                exit(0);
            }
        }

        // Release Task 확인
        for (int i = 0; i < taskCount; i++) {
            if ((task[i].isReady == false) && (time == task[i].nextReleaseTime)) {
                task[i].isReady = true; // ReadyQueue 넣기
                task[i].nextReleaseTime = task[i].nextReleaseTime + task[i].period; // 다음 Release 시간
                // 데드라인 세팅여부
            }
        }

        // Ready Queue 확인
        for (int i = 0; i < taskCount; i++) {

            if (task[i].isReady) {

                // CPU가 비어있다면
                if (selectedTask == -1) {
                    selectedTask = i;
                } else {
                    if (task[selectedTask].priority > task[i].priority) selectedTask = i;
                }
            }
        }

        // 디버그용
        // printf("Time: %d selectedTask %d\n", time, selectedTask);

        // for (int i = 0; i < taskCount; i++) {
        //     printf("Task %d: currentTime %d, nextRtime %d, remainTime %d, isReady, %d\n", i ,task[i].releaseTime, task[i].nextReleaseTime, task[i].remainTime,  task[i].isReady);
        // }

        // printf("Time: %d, %d, deadline: %d\n",time, selectedTask, task[selectedTask].nextDeadline);

        if (selectedTask != -1) {
            // selectedTask 수행
            task[selectedTask].remainTime--;

            // 테스크 다 수행했으면
            if (task[selectedTask].remainTime == 0) {
                task[selectedTask].isReady = false;
                task[selectedTask].remainTime = task[selectedTask].executionTime; // 다시 초기화
                task[selectedTask].nextDeadline += task[selectedTask].period; // 데드락 기간 갱신
                selectedTask = -1;
            }
        }

        time++;
    }

    printf("Duration of Simulation is %d\n", time);
}

float getTotalUtilization() {
    float utilization = 0;

    for (int i = 0; i < taskCount; i++) {
        utilization += (float)task[i].executionTime / task[i].period;
    }

    return utilization;
}
