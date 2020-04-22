#include <iostream> 
#include <vector> 
using namespace std; 

void dfs(vector<bool> check, vector<int> pick_list, int pick, int N, int M, int cnt) { 
    if (pick >= 0) { 
        check[pick] = true; 
        pick_list.push_back(pick + 1); 

        if (cnt == M) { 
            for (int i = 0; i < M; i++) { 
                printf("%d ", pick_list[i]); 
            } 
            printf("\n"); 
            return; 
        } 
    } 

    for (int i = 0; i < N; i++) { 
        if (check[i] == true) { continue; } 
    
        dfs(check, pick_list, i, N, M, cnt + 1);  
    } 
} 

int main() { 
    int N, M; 
    scanf("%d %d", &N, &M); 

    vector<bool> check(N, false); 
    vector<int> pick_list; 

    dfs(check, pick_list, -1, N, M, 0); 

    return 0; 
} 

 