// #include<stdio.h>
 
// void main() {
//     int data[10];
//     int dataatrec[10],c,c1,c2,c3,i;
 
//     printf("Enter 4 bits of data one by one\n");
//     scanf("%d",&data[0]);
//     scanf("%d",&data[1]);
//     scanf("%d",&data[2]);
//     scanf("%d",&data[4]);
 
//     //Calculation of even parity
//     data[6]=data[0]^data[2]^data[4];
// 	data[5]=data[0]^data[1]^data[4];
// 	data[3]=data[0]^data[1]^data[2];
 
// 	printf("\nEncoded data is\n");
// 	for(i=0;i<7;i++)
//         printf("%d",data[i]);
 
//     printf("\n\nEnter received data bits one by one\n");
//     for(i=0;i<7;i++)
//         scanf("%d",&dataatrec[i]);
 
//     c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
// 	c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
// 	c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
// 	c=c3*4+c2*2+c1 ;
 
//     if(c==0) {
// 		printf("\nNo error while transmission of data\n");
//     }
// 	else {
// 		printf("\nError on position %d",c);
    	
// 		printf("\nData sent : ");
//         for(i=0;i<7;i++)
//         	printf("%d",data[i]);
        
// 		printf("\nData received : ");
//         for(i=0;i<7;i++)
//         	printf("%d",dataatrec[i]);
		
// 		printf("\nCorrect message is\n");
 
// 		//if errorneous bit is 0 we complement it else vice versa
// 		if(dataatrec[7-c]==0)
// 			dataatrec[7-c]=1;
//         else
// 			dataatrec[7-c]=0;
		
// 		for (i=0;i<7;i++) {
// 			printf("%d",dataatrec[i]);
// 		}
// 	}
// }


//Praneeth github
//see yt nps for understanding

#include<stdio.h>
int main()
{
    int data[8],c,c0,c1,c2,recv[8],i;
    printf("Enter four bit data ");
    scanf("%d",&data[3]);
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);
    scanf("%d",&data[7]);
    data[1]=(data[3]+data[5]+data[7])%2;//jo sequence neeche hai, vahi ye hai
    data[2]=(data[3]+data[6]+data[7])%2;
    data[4]=(data[5]+data[6]+data[7])%2;
    printf("The Data encoded is :");
    for(i=1;i<8;i++)
        printf("%d",data[i]);
    printf("\nEnter Data received is : ");
    for(i=1;i<8;i++)
        scanf("%d",&recv[i]);
    c0= (recv[1]+recv[3]+recv[5]+recv[7])%2;//jo sequence upar hai, vahi ye hai
    c1= (recv[2]+recv[3]+recv[6]+recv[7])%2;
    c2= (recv[4]+recv[5]+recv[6]+recv[7])%2;
    c=c2*4+c1*2+c0*1;
    printf("The error is at position %d",c);
    if(recv[c]==0)
        recv[c]=1;
    else 
        recv[c]=0;
    printf("\nThe Data corrected is :");
    for(i=1;i<8;i++)
        printf("%d",recv[i]);
    return 0;
}