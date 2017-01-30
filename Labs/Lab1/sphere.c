/* THis  runs on Visual Studio
 so make sure to use scanf instead of  scanf_s,
and comment out  getch() if you are on Unix. 
*/

#include "sphere.h"

int main() {
	double r;
	double s = 0;
	double v = 0;
	
	printf("Enter radius in inches\n");
	scanf("%lf", &r);

	printf("\n\nSphere parameters: \n radius=%.2f inches \n", r);

	int result = calcAreaAndVolume(r, &s, &v);
	printf("area=%.2f square inches\t volume=%.2f cubic inches\n", s, v);

	//getch();
	return 0;

}

int calcAreaAndVolume(double rad, double *parea, double *pvolume) {
	*parea = 4.0*rad*rad*PI;
	*pvolume = (4.0 / 3.0)*rad*rad*rad*PI;
	return 0;
}

