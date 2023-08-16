//
//  main.c
//  cscan
//
//  Created by leonard kb on 14/08/2023.
//

#include <stdio.h>
int main()
{
    int i,j,start=0,r,req[10],head,seek=0,size,dir,temp;
    printf("enter the no of request:\n");
    scanf("%d",&r);
    printf("enter the requests:\n");
    for(i=0;i<r;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("enter the initial head position:\n");
    scanf("%d",&head);
    printf("enter the disk size:\n");
    scanf("%d",&size);
    printf("enter the direction\n 0 from the beg\n 1 from the end:\n");
    scanf("%d",&dir);
    //swap
    for(i=0;i<r-1;i++)
    {
        for(j=0;j<r-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    printf("%d-->",head);
    for(i=0;i<r;i++)
    {
        if(req[i]<head)
        {
            start=i;
        }
        else{
            break;
        }
    }
    if(dir==0)
    {
        //less
        for(i=start;i>0;i--)
        {
            seek+=head-req[i];
            head=req[i];
            printf("%d-->",req[i]);
        }
        seek+=head;
        printf("0-->");
        seek+=(size-1);
        head=size-1;
        printf("%d-->",head);
        for(i=r-1;i>start+1;i--)
        {
            seek+=head-req[i];
            head=req[i];
            printf("%d-->",req[i]);
        }
        seek+=head-req[i];
        printf("%d",req[i]);
    }else{
        for(i=start+1;i<r;i++)
        {
            seek+=req[i]-head;
            head=req[i];
            printf("%d-->",req[i]);
        }
        seek+=((size-1))-head;
        head=size-1;
        printf("%d->",head);
        seek+=head;
        printf("0->");
        head=0;
        for(i=0;i<start;i++)
        {
            seek+=req[i]-head;
            head=req[i];
            printf("%d->",req[i]);
        }
        seek+=req[i]-head;
        printf("%d",req[i]);
    }
    printf("\n total seek distance :%d\n",seek);
    return 0;
}
