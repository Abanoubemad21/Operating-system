
// CPU-Scheduling-Algorithm-In-C
// Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int i,n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    
	printf("\n Enter the burst time and priority for each process \n");
    for(i=0; i<n; i++)
    {
		printf(" arrival time of P%d : ", i);
        scanf("%d", &a[i].AT);
        printf(" Burst time of P%d : ", i);
        scanf("%d", &a[i].BT);
        printf(" Priority of P%d : ", i);
        scanf("%d", &a[i].PT);
		 temp[i]=a[i].BT;
		
	}
	printf("AT | BT | PT\n");
    for(i=0;i<n;i++)
    {
       printf(" %d | %d | %d\n",a[i].AT,a[i].BT,a[i].PT);
        
        // copying the burst time in
        // a temp array fot futher use
        temp[i]=a[i].BT;
    }
    
    // we initialize the burst time
    // of a process with maximum 
    a[9].PT=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        
        // if any process is completed
        if(a[short_p].BT==0)
        {
            // one process is completed
            // so count increases by 1
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            
            // total calculation
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    // printing of the answer
    printf("\nID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\t%d\n",i+1,a[i].WT,a[i].TAT);
    }
    
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    
    return 0;
}