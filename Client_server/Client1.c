#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<strings.h>
int main()
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("Socket error");
        exit(0);
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_port=htons(8998);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
    {
        perror("Connection error");
        exit(0);
    }
    printf("You are connected to the server");
    printf("Input the following details: ");
    int arr[8];
    printf("The content of PM10: ");
    scanf("%d",&arr[0]);
    printf("The content of SO2: ");
    scanf("%d",&arr[1]);
    printf("The content of PM2.5: ");
    scanf("%d",&arr[2]);
    printf("The content of O3: ");
    scanf("%d",&arr[3]);
    printf("The content of NO2: ");
    scanf("%d",&arr[4]);
    printf("The content of CO: ");
    scanf("%d",&arr[5]);
    printf("The content of NO:");
    scanf("%d",&arr[6]);
    printf("The content of NH3: ");
    scanf("%d",&arr[7]);
    write(sockfd,arr,sizeof(int)*8);
    close(sockfd);
}