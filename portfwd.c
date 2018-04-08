#include <errno.h>
#include <getopt.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/socket.h>

#define CFG "./config"

struct str_fwd {
    char t_conn[3];
    char r_host[32];
    char r_port[5];
    char l_port[5];
    char l_addr[15];
    char r_addr[15];
};

struct str_rc {
    int srv_sock;
    int clt_sock;
    int rmt_sock;
    
    struct sockaddr_in srv_addr;
    struct sockaddr_in clt_addr;
    struct sockaddr_in rmt_addr;    
    struct hostent *rmt_host;
};


void *port_fwd(void *fwd){
    struct str_fwd *pfwd=(struct str_fwd *)fwd;

    printf("%s: %s => %s:%s\n",pfwd->t_conn,pfwd->l_port,pfwd->r_addr,pfwd->r_port);
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    fp=fopen(CFG,"rt");
    while (!feof(fp)){
        
        struct str_fwd *fwd = malloc(sizeof(struct str_fwd));
        fscanf(fp,"%[^:]:%[^:]:%[^:]:%s\n", fwd->t_conn,fwd->l_port,fwd->r_port,fwd->r_addr);
        pthread_t tid;

        if(pthread_create(&tid,NULL,port_fwd, (void*)fwd)!=0)
        {
            perror("could not create thread");
            return 1;
        }
        free (fwd);
    }
    fclose(fp);  /* close the file */
}

