#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>


void Usage()
{
    printf("usage: ./server [ip] [port]\n");
}

void ProcessRequest(int client_fd, struct sockaddr_in* client_addr)
{
    char buf[1024] = {0};
    for(;;)
    {
        ssize_t read_size = read(client_fd, buf, sizeof(buf));
        if(read_size < 0)
        {
            perror("read");
            continue;
        }
        if(read_size == 0)
        {
            printf("client: %s say bye!\n", inet_ntoa(client_addr->sin_addr));
            close(client_fd);
            break;
        }
        buf[read_size] = '\0';
        printf("client %s say: %s\n", inet_ntoa(client_addr->sin_addr), buf);

        write(client_fd, buf, strlen(buf));
    }
    return ;
}

void CreateWorker(int client_fd, struct sockaddr_in* client_addr)
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return;
    }
    else if(pid == 0)
    {
        if(fork() == 0)
        {
            ProcessRequest(client_fd, client_addr);
        }
        exit(0);
    }
    else
    {
        close(client_fd);
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        Usage();
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        perror("socket");
        return 2;
    }

    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0)
    {
        perror("bind");
        return 3;
    }

    ret = listen(fd, 10);
    if(ret < 0)
    {
        perror("listen");
        return 1;
    }

    for(;;)
    {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        int client_fd = accept(fd, (struct sockaddr*)&client_addr, &len);
        if(client_fd < 0)
        {
            perror("accept");
            continue;
        }

        CreateWorker(client_fd, &client_addr);
    }
    return 0;
}

