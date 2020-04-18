#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846264338327

double euclideanCircle(int r) {
	return (PI * (double) (r * r));
}

double taxiCircle(int r) {
	return (2.0f * (double) (r * r));
}

int main() {
	int r;
	scanf("%d", &r);

	printf("%f\n%f\n", euclideanCircle(r), taxiCircle(r));

	return 0;
}