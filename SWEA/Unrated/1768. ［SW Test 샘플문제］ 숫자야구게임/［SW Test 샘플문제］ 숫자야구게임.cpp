#define N 4
 
typedef struct {
    int strike;
    int ball;
} Result;
 
// API
extern Result query(int guess[]);
 
struct node{
    int gu[4];
    struct node* next;
};
 
node head;
node nodes[10000];
int node_cnt;
 
int temp_node[4];
 
int visit[10];
 
void dfs(int level) {
    if (level > 3) {
        node* now = &nodes[node_cnt++];
        for (int i = 0; i < 4; i++) {
            now->gu[i] = temp_node[i];
        }
        now->next = head.next;
        head.next = now;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (visit[i])continue;
        temp_node[level] = i;
        visit[i] = 1;
        dfs(level + 1);
        visit[i] = 0;
    }
}
Result query2(int guess[], int now[])
{
    Result result;
    int check[10] = { 0 };
 
    result.strike = 0;
    result.ball = 0;
 
    for (int i = 0; i < 4; i++) check[guess[i]]++;
 
    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] == now[idx])
            result.strike++;
        else if (check[now[idx]] > 0)
            result.ball++;
 
    return result;
}
void remove_node(int st, int ba,int guess[]) {
    node* now = &head;
    while (now->next) {
        Result result;
        int tmpst, tmpba;
 
        result = query2(guess, now->next->gu);
        tmpst = result.strike;
        tmpba = result.ball;
 
        if (!(tmpst == st && tmpba == ba))
            now->next = now->next->next;
        else
            now = now->next;
    }
}
 
 
void doUserImplementation(int guess[]) {
    // Implement a user's implementation function
    //
    // The array of guess[] is a return array that
    // is your guess for what digits[] would be.
    Result result;
 
    node_cnt = 0;
    head.next = 0;
    dfs(0);
 
    while (1) {
        int st, ba;
        for (int i = 0; i < 4; i++) {
            guess[i] = head.next->gu[i];
            
        }
        head.next = head.next->next;
        result = query(guess);
        st = result.strike;
        ba = result.ball;
 
        if (st == 4)break;
        remove_node(st, ba,guess);
    }
 
 
 
}