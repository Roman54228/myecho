#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <stdio.h>


int main(int ac, char *av[]){
    int gid, uid;
    struct passwd *s;
    int list[256];
    int lol = 256;
    if(ac > 1){
        
        s = getpwnam(av[1]);
        gid = s->pw_gid;
        printf("uid=%d(%s) ", s->pw_uid, av[1]);
        printf("gid=%d(%s) groups=", gid, getgrgid(gid)->gr_name);
        getgrouplist(av[1], gid, list, &lol);
        
    }
    
    else{
        uid = getuid(), gid = getgid();
        printf("uid=%d(%s) ", uid, getpwuid(uid)->pw_name);
        printf("gid=%d(%s) ", gid, getgrgid(gid)->gr_name );
    
        printf("groups=");
        getgrouplist(getpwuid(uid)->pw_name, gid, list, &lol);
        }
    int i;
    for(int i = 0;i < lol ; i++){
        struct group *gr = getgrgid(list[i]);
        char *grname = gr->gr_name;
        printf("%d(%s),", list[i], grname);
    }
    
    
    return 0;
}



    
    
    







