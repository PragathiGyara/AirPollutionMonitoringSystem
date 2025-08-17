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
    struct sockaddr_in serv_addr,cli_addr;
    serv_addr.sin_port=htons(8998);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr("115.98.45.146");
    if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)<0))
    {
        perror("Bind error");
        exit(0);
    }
    listen(sockfd,5);
    int i;
    for(i=0;i<5;i++)
    {
        int cli_len=sizeof(cli_addr);
        int newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&cli_len);
        printf("Hello, welcome! To are connected to the server.");
        printf("\nPlease provide the below details: ");
        printf("The content of PM10,SO2,PM2.5,O3,NO2,CO,NO,NH3 in the air: ");
        int arr[8];
        read(newsockfd,arr,sizeof(int)*8);
        printf("The given input is: ");
        int k;
        for(k=0;i<8;i++)
        {
            printf("%d",arr[i]);
        }
        int range[8][2];
        int dev[8];
        char *cause[8];
                    range[0][0]=0;
            range[0][1]=80;
            range[1][0]=0;
            range[1][1]=200;
            range[2][0]=0;
            range[2][1]=50;
            range[3][0]=0;
            range[3][1]=100;
            range[4][0]=0;
            range[4][1]=120;
            range[5][0]=0;
            range[5][1]=30;
            range[6][0]=0;
            range[6][1]=60;
            range[7][0]=0;
            range[7][1]=40;
            int i;
            for(i=0;i<8;i++)
            {
                if(range[i][0]<arr[i] && arr[i]<range[i][1])
                {
                    dev[i]=0;
                }
                else
                {
                    dev[i]=arr[i]-range[i][1];
                }
            }
            cause[1]="Dust from unsealed roads";
            cause[2]="Coal fired power stations";
            cause[3]="Smoke from fires";
            cause[4]="Cars and truck exhausts";
            cause[5]="Car and truck exhausts";
            cause[6]="Faulty gas heaters,BBQs,ovens and cooktops";
            cause[7]="Power stations";
            cause[8]="Fertilizers";
            write(newsockfd,dev,sizeof(int)*8);
            for(i=0;i<8;i++)
            {
                if(dev[i]==0)
                {
                    printf("\nThe pollutant %d is in the safe range",i+1);
                }
                else
                {
                    printf("\nThe pollutant %d is not in a safe range\nAnd is deviating by %d ppm\n",i+1,dev[i]);
                }
            }
            printf("\nThe sources of pollution are: ");
                for(i=0;i<8;i++)
                {
                    if(dev[i]!=0)
                    {
                        printf("\n%s",cause[i]);
                    }
                }
                int max=dev[0];
                int index=0;
                for(i=0;i<8;i++)
                {
                    if(max<dev[i])
                    {
                        max=dev[i];
                        index=i;
                    }
                }
                printf("\nThe major source of pollution is: ",cause[index]);
        close(newsockfd);
    }
    close(sockfd);

}
