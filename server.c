  #include <sys/types.h>
        #include <sys/socket.h>
        #include <netdb.h>
        #include <stdio.h>
        #include<string.h>

        void main()
        {
            char str[100];

            //define and create the server socket  
            int server_socket, comm_fd;
            struct sockaddr_in serveraddr;
            server_socket = socket(AF_INET, SOCK_STREAM, 0);
            if(server_socket == -1)
              {
               perror("Socket not created\n");
              }

            bzero( &serveraddr, sizeof(serveraddr));
            serveraddr.sin_family = AF_INET;
            serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
            serveraddr.sin_port = htons(22000);

            //bind the socket to our specified IP and port  
           int bsocket = bind(server_socket, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
            if(bsocket == -1)
              {
               perror("Socket not bound\n");
              }

            int ulisten = listen(server_socket, 10);
             if(ulisten == -1)
              {
               perror("Unable to listen to the client\n");
              }

            comm_fd = accept(server_socket, (struct sockaddr*) NULL, NULL);

             if(comm_fd == -1)

              {
               perror("Unable to accept connection.\n");
              }
               // read and print the client msg  
            while(1)
            {
                bzero( str, 100);
                read(comm_fd,str,100);
                printf("%s",str);

            }
            // close the socket  
            close(server_socket);
        }
