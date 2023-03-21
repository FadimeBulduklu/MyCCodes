#include<stdlib.h>
#include<stdio.h>

void fizzBuzz(int n) {
int i;
for(i=1;i<=n;i++){
    if(i%3==0 && i%5==0){
        printf("\nFizzBuzz");
    }
    else if(i%3==0 && i%5!=0){
        printf("\nFizz");
    }
    else if(i%3!=0 && i%5==0){
        printf("\nBuzz");
    }
    else {
       printf("\n%d",i);
    }
}
}

int main(){
	fizzBuzz(15);
}
