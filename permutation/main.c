#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GMaxCandidates;
int GFinished;

int getTotalOfPermutations(int n);
void permutation(int n);
void backtrack(int result[],int k,int input,int pos);
int is_a_solution(int result[],int k,int input,int pos);
void processSolution(int result[],int k);
void  construct_candidates(int result[],int k,int input,int candidates[], int* nCandidates);

int main() {
    int n = 0;
    scanf("%i",&n);
    permutation(n);
    return 0;
}

int getTotalOfPermutations(int n){
    int result = 1;
    for (int i=1;i<=n;i++)
        result *= i;
    return result;
}
void permutation(int n){
    GMaxCandidates = n;
    int nPermutations = getTotalOfPermutations(n);
    int result[nPermutations];
    memset(result, 0, sizeof(result));
    backtrack(result,n,n,0);
}

int is_a_solution(int result[],int k,int input,int pos){
    
}

void processSolution(int result[],int k) {
    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);
}

void backtrack(int result[],int k,int input,int pos){
    if(is_a_solution(result,k,input,pos)){
        processSolution(result,k);
    }else{
        int nCandidates = 0; // total of candidates for the next position
        int candidates[GMaxCandidates];
        memset(candidates,0, sizeof(candidates));
        construct_candidates(result,k,input,candidates,&nCandidates);

        for(int i=0; i < nCandidates; i++){
            result[k] = candidates[i];
            backtrack(result,k,input,pos++);
            if (GFinished) return;
        }
    }
}
