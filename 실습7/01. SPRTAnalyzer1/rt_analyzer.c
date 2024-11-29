#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TASK 100
#define INT_MAX 0x7FFFFFFF

#define INPUT_FILE_NAME "sched_param.txt"

struct Task {
    char name[16];
    int ID;
    int period;
    int executionTime;
    int deadline;    
    int priority;       
    
    int responseTime;
} task[MAX_TASK];

int getMaxResponseTime(int response[], int taskId, int previousResponseTime, int depth);
int getInitResponseTime(int response[], int targetId);
float getTotalUtilization();
float getLimitUtilization();

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
        fscanf(f, "%d ", &task[i].period);
        fscanf(f, "%d ", &task[i].executionTime);
        fscanf(f, "%d ", &task[i].deadline);
        fscanf(f, "%d \n", &task[i].priority);
        task[i].responseTime = 0;
        taskCount++;
    }

    for (i = 0; i < taskCount; i++) {
        printf("Task %s: ", task[i].name);
        printf("Period = %d, ", task[i].period);
        printf("Execution time = %d, ", task[i].executionTime);
        printf("Deadline = %d, ", task[i].deadline);
        printf("Priority = %d\n", task[i].priority);
    }

    printf("\n");

    return taskCount;
}

int main() {
    
    float totalUtilization;
    float limitUtilization;
    int unschedulableCount = 0;


    readInput();

    // 각 테스크의 maximumResponse 계산
    for (int i = 0; i < taskCount; i++) {
        int response[1000] = {0, }; // ResponseTime Recursion 결과값 저장 배열

        response[0] = getInitResponseTime(response, i);

        int maximumResponse = getMaxResponseTime(response, i, response[0], 1);

        // deadline 넘기는 테스크라면
        if (maximumResponse > task[i].deadline) {
            printf("Task %s might miss deadline: response time %d > deadline %d\n", task[i].name, maximumResponse, task[i].deadline);
        }
    }

    totalUtilization = getTotalUtilization();
    limitUtilization = getLimitUtilization();

    // Schedulable 확인
    if (totalUtilization <= limitUtilization && unschedulableCount == 0) {
        printf("\nThe total utilization is %f and the task set is schedulable.\n", totalUtilization);
        
    } else {
        printf("\nThe total utilization is %f and the task set is NOT schedulable.\n", totalUtilization);
    }

    return 0;
}

int getMaxResponseTime(int response[], int taskId, int previousResponseTime, int depth) {

//  탈출조건
    if (response[depth] != 0) return response[depth];
    
    int currentResponseTime = task[taskId].executionTime;

    // printf("%d\n", currentResponseTime);

    for (int i = 0; i < taskCount; i++) {
        // 더높은 우선순위를 가지고 있는 테스크 계산
        if (task[taskId].priority > task[i].priority) {
            float param = (float)previousResponseTime / task[i].period;
            currentResponseTime += ceil(param) * task[i].executionTime;
        }
    }

    // 이전 값과 같은 reponseTime이면 종료
    if (currentResponseTime == response[depth - 1]) {

        return currentResponseTime;
    } else {
        response[depth] = currentResponseTime; // 현재 depth의 responseTime 기록
        return getMaxResponseTime(response, taskId, currentResponseTime, depth + 1);
    }

}

int getInitResponseTime(int response[], int targetId) {

    int sum = 0;

    // 자기보다 우선순위 높은 테스크 executionTime 더하기
    for (int i = 0; i < taskCount; i++) {
        if (task[targetId].priority >= task[i].priority) {
            sum += task[i].executionTime;
        }
    }

    return sum;
}

float getTotalUtilization() {
    float utilization = 0;

    for (int i = 0; i < taskCount; i++) {
        utilization += (float)task[i].executionTime / task[i].period;
    }

    return utilization;
}

float getLimitUtilization() {
    float utilization = 0;

    utilization = taskCount * (pow(2, (1.0 / taskCount)) - 1);

    return utilization;
}
