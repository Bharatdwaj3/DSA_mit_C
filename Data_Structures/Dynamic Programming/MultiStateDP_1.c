#include<stdio.h>
#include<string.h>

#define MOD 10000007
#define MAX_STATES 50
#define MAX_TRANS 10

long long dp_curr[MAX_STATES], dp_next[MAX_STATES];

typedef struct {
    int next;
    long long weight;
}Edge;

Edge transitions[MAX_STATES][MAX_TRANS];
int num_trans[MAX_STATES];

void addTransition(int from, int to, long long weight){
    transitions[from][num_trans[from]].next=to;
    transitions[from][num_trans[from]].weight=weight%MOD;
    num_trans[from]++;
}

long long runStateMachineDP(int states, int steps, int start_state){
    memset(dp_curr, 0, sizeof(dp_curr));
    dp_curr[start_state]=1;
    for(int step=0;step<steps;step++){
        memset(dp_next, 0, sizeof(dp_next));
        for(int s=0;s<states;s++){
            if(dp_curr[s]==0)
                continue;
            for(int t=0;t<num_trans[s];t++){
                int ns=transitions[s][t].next;
                long long w=transitions[s][t].weight;
                dp_next[ns]=(dp_next[ns]+dp_curr[s]*w)%MOD;
            }
        }
        memcpy(dp_curr, dp_next, sizeof(dp_curr));
    }
    long long total=0;
    for(int s=0;s<states;s++){
        total=(total+dp_curr[s])%MOD;
    }
    return total;
}

void example_kinghtDialer(int N){
    memset(num_trans, 0, sizeof(num_trans));
    int moves[10][3] = {
        {4, 6, -1}, {6, 8, -1}, {7, 9, -1}, {4, 8, -1}, {0, 3, 9}, {-1, -1, -1}, {0, 1, 7}, {2, 6, -1}, {1, 3, -1}, {2, 4, -1}};
    for (int s = 0; s < 10; s++){
        for (int k = 0; k < 3; k++){
            if(moves[s][k]==-1)
                break;
            addTransition(s, moves[s][k],1);
        }
    }
    long long total = 0;
    for(int start=0;start<10;start++){
        total=(total+runStateMachineDP(10, N-1, start))%MOD;
    }
    printf("1. Knight Dialer (N=%d) -> %lld\n",N< total);
}

void example_paintFence(int n, int k){
    long long same=k*1LL;
    long long diff=k*(k-1LL);
    for(int i=3;i<=n;i++){
        long long prevDiff=diff;
        diff=(same+diff)*(k-1LL)%MOD;
        same=prevDiff;
    }
    long long ways=(same+diff)%MOD;
    printf("Paint Fence (n=%d, k=%d) -> %lld\n",n,k,ways);
}

void example_numTilings(int N){
    memset(num_trans, 0, sizeof(num_trans));
    addTransition(0, 0, 1);
    addTransition(0, 1, 1);
    addTransition(0, 2, 1);
    addTransition(1, 0, 1);
    addTransition(1, 2, 1);
    addTransition(2, 0, 1);
    addTransition(2, 1, 1);
    long long  ans = runStateMachineDP(3, N, 0);
    printf("3. NumTilings 2x%d -> %lld\n",N, ans);
}

void example_noConsecOnes(int N){
    memset(num_trans, 0, sizeof(num_trans));
    addTransition(0, 0, 1);
    addTransition(0, 1, 1);
    addTransition(1, 0, 1);
    long long totalk=(runStateMachine(2, N-1, 0)+runStateMachineDP(2, N-1, 1))%MOD;
    printf("4. Binary strings len=%d without consecutive 1s → %lld\n", N, totalk);
}

void example_fib(int N){
    long long a=0, b=1;
    for(int i=0;i<N;i++){
        long long tmp=(a+b)%MOD;
        a=b; b=tmp;
    }
    printf("5. Fibonacci(%d) → %lld\n", N, a);
}