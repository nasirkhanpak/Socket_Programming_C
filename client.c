 #include <stdio.h>
        #include <sys/types.h>
        #include <sys/socket.h>
        #include <netdb.h>
        #include <string.h>

        int main(int argc,char *argv[])
        {
            // create a socket  
            int network_socket, n;
            char sendline[100];

            // specify an address for the socket  
            struct sockaddr_in serveraddr;
            network_socket=socket(AF_INET,SOCK_STREAM,0);

             //check error with socket  
            if(network_socket == -1)
             {
             perror("Socket not created\n");
             }

            // IP address
            struct hostent *h;
            struct sockaddr_in sin;
            char domain[512];
            sin.sin_addr.s_addr=gethostid();
            h = gethostbyaddr((char *)&sin.sin_addr.s_addr,
            sizeof(struct in_addr), AF_INET);
            if (h==(struct hostent *)0)
               {
                 printf("gethostbyaddr failed\n");
               }

               //specify an address for the socket  

            int result;
            bzero(&serveraddr,sizeof serveraddr);
            serveraddr.sin_family=AF_INET;
            serveraddr.sin_port=htons(22000);
            result = connect(network_socket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

            // check for error with the connection  
            if (result == -1) {
               printf("There was some error in the connection to the server \n\n");
             }

            //read data from keyboard and send it to server  
            while(1)
            {
                bzero(sendline, 100);
                fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
               n = write(network_socket,sendline,strlen(sendline)+1);
             if (n<0)
               {
                perror("Error in writing\n");
               }

            }
            // close the socket  
            close(network_socket);
        }
