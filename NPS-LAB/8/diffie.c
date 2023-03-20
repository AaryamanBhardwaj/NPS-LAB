//instructor manula appproach

// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<time.h>
// long long int compute(int a, int m, int n)
// {
// 	// int r;
// 	// int y = 1;
// 	// while (m > 0)
// 	// {
// 	// 	r = m % 2;
// 	// 	// fast exponention
// 	// 	if (r == 1)
// 	// 	y = (y*a) % n;
// 	// 	a = a*a % n;
// 	// 	m = m / 2;
// 	// }
// 	// return y;
// 	return (long long int) pow(a,m)%n;
// }
// 	// C program to demonstrate Diffie-Hellman algorithm
// int main()
// {
// 	int p = 23; // modulus
// 	int g = 5; // base
// 	int a, b; // a - Alice Secret Key, b - Bob Secret Key.
// 	int A, B; // A - Alice Public Key, B - Bob Public Key
// 	srand(time(0)) ;
// 	a = rand(); // choose secret integer for Alice&#39;s Pivate Key (only known toAlice)
// 	A = compute(g, a, p);// Calculate Alice&#39;s Public Key (Alice will send A to Bob)
// 	srand(time(0)) ;
// 	b = rand(); // choose secret integer for Bob&#39;s Pivate Key (only known to Bob)
// 	B = compute(g, b, p);// Calculate Bob&#39;s Public Key (Bob will send B to Alice)
// 	// Alice and Bob Exchanges their Public Key A &amp; B with each other
// 	// Find Secret key
// 	int keyA = compute(B, a, p);
// 	int keyB = compute(A, b, p);
// 	printf("\nAlice's Secret Key is %d\nBob's Secret Key is %d\n\n",keyA, keyB);
// 	return 0;
// }




#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main()
{
	long long int p,g;
	long long int a, b;	// a - Alice's private Key, b - Bob's private Key.
	long long int A, B;	// A - Alice's Public Key, B - Bob's Public Key
	printf("Enter the prime no(p) :");
	scanf("%lld",&p);//23
	printf("\nEnter the primitive root of p(g) :");
	scanf("%lld",&g);//5
	printf("\nEnter the alice private key (a) :");
	scanf("%lld",&a);
	printf("\nEnter the Bob private key (b) :");
	scanf("%lld",&b);
	//public key calculation
	A = (long long int) pow(g,a)%p;
	B = (long long int) pow(g,b)%p;
	long long int keyA = (long long int) pow(B,a)%p;
	long long int keyB = (long long int) pow(A,b)%p;
	printf("\nAlice's Secret Key is %lld\nBob's Secret Key is %lld\n\n", keyA, keyB);
	return 0;
}