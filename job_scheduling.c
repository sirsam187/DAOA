#include<stdio.h>
#include<stdlib.h>

struct Job{
    char jobID[5];
    int deadline;
    int profit;
};

void inputjob(struct Job job[], int jobsize){
    int i;
    for(i=0; i<jobsize; i++){
        printf("Input for JOB[%d] : \n",i+1);
        printf("Enter Job ID\n");
        scanf("%s", job[i].jobID);
        printf("Enter Job deadline\n");
        scanf("%d",&job[i].deadline);
        printf("Enter Job Profit\n");
        scanf("%d",&job[i].profit);
    }
}

//using bubble sort we sort the jobs according to its profit in decreasing order.
void sort(struct Job job[], int jobsize){
    int i, j;
    for(i = 0; i<jobsize-1; i++){
        struct Job temp;
        for(j = 0; j<jobsize-i-1; j++){
            if(job[j+1].profit > job[j].profit){
                temp = job[j+1];
                job[j+1] = job[j];
                job[j] = temp;
            }
        }
    }
}

//greedy approach to solve the problem
void schedulejobs(struct Job job[], int jobsize, int timeslot[], int timeslotsize){
    int countTimeSlot = 0;
    int i, j, min;
    
    for(i=0; i<timeslotsize; i++)
        timeslot[i] = -1;
    
    for(i=0;i<jobsize;i++){
        min = timeslotsize<job[i].deadline?timeslotsize : job[i].deadline;
        for(j=min-1; j>=0; j--){
            if(timeslot[j]==-1){
                timeslot[j] = i;
                countTimeSlot++;
                break;
            }
        }
        if(countTimeSlot==timeslotsize) break;
    }   
}

void displayjobs(struct Job job[], int timeslot[], int timeslotsize){
    int profit = 0;
    int i;
    
    printf("Schedule job sequence : \n");
    for(i=0; i<timeslotsize; i++){
        if(timeslot[i]!=-1){
            printf("%s--->", job[timeslot[i]].jobID);
            profit += job[timeslot[i]].profit;
        }
    }
    printf("\nTotal Profit = %d\n", profit);
}


void main(){
    int jobsize, timeslotsize;
    printf("Enter number of jobs: \n");
    scanf("%d", &jobsize);
    printf("Enter time slot size: \n");
    scanf("%d", &timeslotsize);
    struct Job job[jobsize];
    
    int timeslot[timeslotsize];
    
    inputjob(job, jobsize);
    sort(job, jobsize);
    schedulejobs(job,jobsize,timeslot,timeslotsize);
    displayjobs(job, timeslot, timeslotsize);
    
}
