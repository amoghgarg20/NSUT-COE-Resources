#include<stdio.h>
#include<stdlib.h>
int main(){
    int RS[100],i,n,TotalHead=0,initial,count=0;
    printf("Enter the number of Requests:");
    scanf("%d",&n);
    printf("Enter the Requests sequence:");
    for(i=0;i<n;i++)
    scanf("%d",&RS[i]);
    printf("Enter initial head position:");
    scanf("%d",&initial);
    //Count is the count of serviced requests
    while(count!=n){
        //1000 here denotes very large number
        int min=1000,d,index;
        //Finding shortest seek-time
        for(i=0;i<n;i++){
           d=abs(RS[i]-initial);
           if(min>d){
               min=d;
               index=i;
           }
        }
        TotalHead=TotalHead+min;
        initial=RS[index];
        //So that this request doesn't get serviced again
        RS[index]=1000;
        count++;
    }
    printf("Total head movement is %d",TotalHead);
    return 0;
}