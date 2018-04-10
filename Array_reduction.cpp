
#include <stdio.h>
#include<cstdio>
#include<string.h>
#define pathSize 100
using namespace std;


bool fcheck(char arr[],int tempLength){
	for(int i=0;i<tempLength;i++){
		if (arr[i]=='B')
		{
			return true;
		}
	}
	return false;
}




void nullify(char a[]) {
	for (int i=0; i!='\0'; i++) {
		a[i] = '\0';
	}
}





int main(){
	char path[pathSize];
	char a1[pathSize];
	char a2[pathSize];
	char optimizedPath[pathSize];




	printf("enter string: ");
	scanf("%s",path);
	int cnt=0;
	printf("%s",path);
	while(path[cnt]!='\0'){
		cnt++;
	}
	int pathLength=cnt;

	
	int tempLength = pathLength;
	int optimizedPathLength = pathLength;
	int i = 0;
	int j = 0;
	//copies the path array
	for (i=0; i<pathLength; i++) {
	a1[i] = path[i];
	}
	
	while (fcheck(a1,tempLength)) {
		
		
		for (i=0, j=0; i<tempLength; i++, j++) {
			if (a1[i+1] != 'B') {
				a2[j] = a1[i];
				a2[j+1]='\0';
			} 
			else if (a1[i+1] == 'B') {

				if (a1[i] == 'L' && a1[i+2] == 'R') {
						a2[j] = 'B';
				} 
				else if (a1[i] == 'L' && a1[i+2] == 'S') {
					a2[j] = 'R';
				}
				else if (a1[i] == 'R' && a1[i+2] == 'L') {
					a2[j] = 'B';
				}
				else if (a1[i] == 'S' && a1[i+2] == 'L') {
					a2[j] = 'R';
				} 
				else if (a1[i] == 'S' && a1[i+2] == 'S') {
					a2[j] = 'B';
				} 
				else if (a1[i] == 'L' && a1[i+2] == 'L') {
					a2[j] = 'S';
				}
				i+=3;
				j++;
				for (; i<tempLength; i++, j++) {
					a2[j]=a1[i];
					a2[j+1]='\0';
				}
				tempLength -= 2;
			
			
				

				
			} //end elif
			

		} //end for
		nullify(a1);
		int k=0;
		for(;k<tempLength;k++){
			a1[k]=a2[k];
		}
		a1[k]='\0';
		optimizedPathLength=tempLength;
	

	} //end while





	for (i=0; i<optimizedPathLength; i++) {
		optimizedPath[i] = a1[i];
	}
	printf("Path tempLength is: %d\n",optimizedPathLength );
	printf("optimizedPath is: %s\n",optimizedPath );
}
