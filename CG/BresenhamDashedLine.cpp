#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

float r, g, b, x, y;
float x_1, x_2, y_1, y_2;
float xin, yin, length;
bool flag = true;

void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0, 640, 0, 480);
	glClear(GL_COLOR_BUFFER_BIT);
}

void mouse(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		flag = true;
		x = mousex;
		y = 480 - mousey;
	}
	cout << "\n\n mousex = " << x;
	cout << "mousey = " << y;
}


int sgn(float d)
{

	if (d == 0)
	{
		return 0;
	}
	else if (d < 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


void Line() {

	float dy, dx, length,G;
	x_2 = x;
	y_2 = y;
	dx = x_2 - x_1;
	dy = y_2 - y_1;

	G = (2 * dy) - dx;

	if (abs(dx) >= abs(dy))
	{
		length = abs(dx);
	}
	else
	{
		length = abs(dy);
	}
	int j = 0;
	x = x_1;
	y = y_1;


	while (j <= length)
	{

		if (abs(dx) >= abs(dy))
		{
			x = x + 1;
			if (G >= 0)
			{
				y = y + 1;
				G = G + 2 * (dy - dx);
			}
			else
			{
				G = G + (2 * dy);
			}

		}
		else
		{
			y = y + 1;
			if (G >= 0)
			{
				x = x + 1;
				G = G + 2 * (dy - dx);
			}
			else
			{
				G = G + (2 * dy);
			}
		}
		cout << "\n x = " << x;
		cout << " y = " << y;
		if (j % 7 == 0)
		{
			x = x + 3;
			y = y + 3;
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
		else
		{
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
		j++;
	}
	glFlush();


}

int main(int argc, char** argv)
{
	cout << "Enter the first point of a line\n";
	cin >> x_1 >> y_1;
	//cout << "Enter the last point of a line\n";
	//cin >> x_2 >> y_2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(0, 600);
	glutCreateWindow("Bresenhams Line Drawing");
	init();
	glutMouseFunc(mouse);
	glutDisplayFunc(Line);
	glutMainLoop();
	return 0;
}
