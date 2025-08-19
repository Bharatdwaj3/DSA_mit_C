#include<stdio.h>
#include<string.h>

#define MOD 1000000007
#define MAX_STATES 50
#define MAX_TRANS 10

long long dp_curr[MAX_STATES], dp_next[MAX_STATES];

int transition[MAX_STATES][MAX_TRANS];
int num_trans[MAX_STATES];

long long runStateMAchineDP(int states, int steps, int start_state){
    memset(dp_curr, 0, sizeof(dp_curr));
    dp_curr[start_state]=1;
    for(int step=0; step<steps;step++){
        memset(dp_next,0,sizeof(dp_next));
        dp_curr[start_state]=1;
        for(int step=0;step<steps;step++){
            memset(dp_next,0, sizeof(dp_next));
            for(int s=0;s<states;s++){
                if(dp_curr[s]==0)
                    continue;
                for(int t=0;t<num_trans[s];t++){
                    int ns = transition[s][t];
                    dp_next[ns]=(dp_next[ns]+dp_curr[s])% MOD;
                }
            }
            memcpy(dp_curr, dp_next, sizeof(dp_curr));
        }
        long long total = 0;
        for(int s=0;s<states;s++){
            total=(total+dp_curr[s])%MOD;
        }
        return total;
    }
}