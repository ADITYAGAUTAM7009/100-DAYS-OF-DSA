/*
Problem: Task Scheduler
Name: Aditya Gautam
*/

#include <stdlib.h>

int leastInterval(char* tasks, int n) {

    int freq[26]={0};

    int total=0;

    while(tasks[total]){
        freq[tasks[total]-'A']++;
        total++;
    }

    int maxFreq=0,maxCount=0;

    for(int i=0;i<26;i++)
        if(freq[i]>maxFreq)
            maxFreq=freq[i];

    for(int i=0;i<26;i++)
        if(freq[i]==maxFreq)
            maxCount++;

    int slots=(maxFreq-1)*(n+1)+maxCount;

    return slots>total?slots:total;
}