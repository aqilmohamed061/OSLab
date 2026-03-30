#include <stdio.h>
#define MAX 50

struct Process {
    int pid;
    int at, bt, rt;
    int ct, wt, tat;
    int type;
};

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int val) {
    if (q->rear == MAX - 1) return;

    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) return -1;

    int val = q->items[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
            return val;
}


void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }}}}

int main() {
    int n;
    struct Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("PID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Type (1=System, 0=User): ");
        scanf("%d", &p[i].type);

        p[i].rt = p[i].bt;
    }

    sortByArrival(p, n);

    struct Queue systemQ, userQ;
    initQueue(&systemQ);
    initQueue(&userQ);

    int time = 0, completed = 0, i = 0;
    int current = -1;


    int gantt_pid[200], gantt_time[200];
    int g = 0;

    while (completed < n) {


        while (i < n && p[i].at <= time) {
            if (p[i].type == 1)
                enqueue(&systemQ, i);
            else
                enqueue(&userQ, i);
            i++;
        }


        if (current != -1) {
            if (p[current].type == 0 && !isEmpty(&systemQ)) {
                enqueue(&userQ, current);
                current = -1;
            }
        }


        if (current == -1) {
            if (!isEmpty(&systemQ))
                current = dequeue(&systemQ);
            else if (!isEmpty(&userQ))
                current = dequeue(&userQ);
            else {
                time++;
                continue;
            }
        }


        gantt_pid[g] = p[current].pid;
        gantt_time[g] = time;
        g++;


        p[current].rt--;
        time++;


        if (p[current].rt == 0) {
            p[current].ct = time;
            completed++;
            current = -1;
        }
    }


    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }


    printf("\nGantt Chart:\n|");
    for (int i = 0; i < g; i++) {
        printf(" P%d |", gantt_pid[i]);
    }

    printf("\n0");
    for (int i = 0; i < g; i++) {
        printf(" %d", gantt_time[i] + 1);
    }


    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage WT = %.2f", total_wt / n);
    printf("\nAverage TAT = %.2f\n", total_tat / n);

    return 0;
}

