#include <stdio.h>
#include <string.h>

struct id{
	char name[10];
	int age;
	float weight;
}

main(){
	struct id Alice;
	struct id Bob;

	strcpy(Alice.name, "Alice");
	Alice.age = 23;
	Alice.weight = 160.4;

	strcpy(Bob.name, "Bob");
	Bob.age = 24;
	Bob.weight = 202.8;

	printf("%s is %d and weighs %.1flbs.\n%s is %d and weighs %.1flbs.\n" ,Alice.name,Alice.age,Alice.weight,Bob.name,Bob.age,Bob.weight); 
}
	
