#include<stdio.h>
struct process{
    int WT,AT,BT,TAT,PT;
};
struct process a[10]; //Array of processes
//Higher number denotes lower priority
// Therefore 1 means highest priority
int main(){
    int n,temp[10],t,count=0,prior;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process(<=8):");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process:");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        temp[i]=a[i].BT;
    }
    a[9].PT=10000;  // 10000 here denotes very low priority
    for(t=0;count!=n;t++){ //t is time counter here
        prior=9;    // Assuming imaginary process 9 has highest priority
        //Loop for finding highest priority
        for(int i=0;i<n;i++){
            if(a[prior].PT>a[i].PT && a[i].AT<=t && a[i].BT>0){
                prior=i;
            }
        }
        a[prior].BT=a[prior].BT-1;
        //Count denotes number of completed processes
        if(a[prior].BT==0){
            count++;
            a[prior].WT=t+1-a[prior].AT-temp[prior];
            a[prior].TAT=t+1-a[prior].AT;
            total_WT=total_WT+a[prior].WT;
            total_TAT=total_TAT+a[prior].TAT;
        }
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    printf("ID \tWT \tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",i+1,a[i].WT,a[i].TAT);
    }
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    return 0;
}

