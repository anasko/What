#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include "gui.h"
#include "mt.h"
#include "rk.h"
#include "sc.h"

struct itimerval nval, oval;

void sighandler(int signum)
{
    if (signum == SIGKILL) {
        mt_clrscr();
        exit(0);
    }
    if (signum == SIGUSR1) {
		mt_clrscr();
		exit(0);
		
       init();
        x = 0, y = 0;
        refresh();
    }
    if (signum == SIGALRM) {
        int freq_flg = 0,
            comm_flg = 0,
            inst_curr = 0;
        sc_regGet(FREQ_ERR, &freq_flg);
        sc_regGet(COMMAND_ERR, &comm_flg);
        sc_instGet(&inst_curr);

        if (comm_flg)
            sc_regSet(FREQ_ERR, 1);

        if (!freq_flg) {
            step();
            interface();
        }

        if (inst_curr == 99)
            sc_regSet(FREQ_ERR, 1);
    }
}


void alrm(int run) //óñòàíîâêà òàéìåðà
{
	if (run)
	{
		/* çàïóñêàåì òàéìåð */
		nval.it_interval.tv_sec = 0;        //èíòåðâàë ãåíåðèðîâàíèÿ
		nval.it_interval.tv_usec = 0;       //ñèãíàëîâ
		nval.it_value.tv_sec = 0;           //òàéìåð ñðàáîòàåò ÷åðåç
		nval.it_value.tv_usec = 300000;     //300000 ìëñ
		setitimer(ITIMER_REAL, &nval, &oval);
	}
	else
	{
		/* îñòàíàâëèâàåì òàéìåð */
		nval.it_interval.tv_sec = 0;
		nval.it_interval.tv_usec = 0;
		nval.it_value.tv_sec = 0;
		nval.it_value.tv_usec = 0;
		setitimer(ITIMER_REAL, &nval, &oval);
	}
}


int main()
{
    signal(SIGALRM, sighandler);
    signal(SIGKILL, sighandler);
    signal(SIGUSR1, us_kill);

    nval.it_interval.tv_sec = 0;
    nval.it_interval.tv_usec = 80000;
    nval.it_value.tv_sec = 3;
    nval.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &nval, &oval);

    init();

    simple_computer();

    write(1, "\e[0m", 4);
    rk_mytermrestore();
    mt_clrscr();
    return 0;
}
