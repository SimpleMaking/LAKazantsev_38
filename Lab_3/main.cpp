#include <iostream>

constexpr size_t N = 6; // count of figures
constexpr size_t P = 4; // count of types of figures
constexpr double PI = 3.14; // number pi
constexpr double AREA = 100; // limit of user area value
using namespace std;


struct Circle
{
	double radius;
};


struct Square
{
	double side;
};


struct Rectangle
{
	double first_side;
	double second_side;
};


struct Triangle
{
	double a;
	double b;
	double c;
};


enum Figures
{
	circle,
    square,
	rectangle,
	triangle,
};

/*
 * Finding the radius of a circle that will fit everything
 *
 * @param arr_of_figures array of figures.
 * @param arr_of_types array of types.
 * @return radius that will fit all other figures.
 */
double BigCircle(void* arr_of_figures[N], size_t* arr_of_types)
{
	double radius = 0;
	double semi_perimeter = 0;
	for (size_t i = 0; i < N; i++)
	{
		switch (arr_of_types[i])
		{
		case Figures::circle:
		{
			radius += (((Circle*)arr_of_figures[i])->radius + 1);
			break;
		}
		case Figures::square:
		{
			radius += (((Square*)arr_of_figures[i])->side * sqrt(2)) / 2;
			break;
		}
		case Figures::rectangle:
		{
			radius += (sqrt(pow(((Rectangle*)arr_of_figures[i])->first_side, 2) + pow(((Rectangle*)arr_of_figures[i])->second_side, 2)) / 2);
			break;
		}
		case Figures::triangle:
		{
			semi_perimeter = 0;
			semi_perimeter = (((Triangle*)arr_of_figures[i])->a + ((Triangle*)arr_of_figures[i])->b + ((Triangle*)arr_of_figures[i])->c) / 2;
			double mult_of_sides = ((Triangle*)arr_of_figures[i])->a * ((Triangle*)arr_of_figures[i])->b * ((Triangle*)arr_of_figures[i])->c;
			radius += (mult_of_sides / 4 * sqrt(semi_perimeter * (semi_perimeter - ((Triangle*)arr_of_figures[i])->a) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->b) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->c)));
			break;
		}
		}
	}
	return radius;
}

/*
 * Finding all figures whose area is bigger than entered
 *
 * @param arr_of_figures array of figures.
 * @param arr_of_types array of types.
 */
void FiguresProvided(void* arr_of_figures[N], size_t* arr_of_types)
{
	double value;
	bool flag = 0;
	cout << "input the area of a figure but not more than 100 units" << endl;
	cin >> value;
	do
	{
		if (value > 0 && value <= AREA)
		{
			long double area = 0;
			long double semi_perimeter = 0;
			for (size_t i = 0; i < N; i++)
			{
				switch (arr_of_types[i])
				{
				case Figures::circle:
				{
					area = pow(((Circle*)arr_of_figures[i])->radius, 2) * PI;
					if (area > value)
						cout << "circle area: " << area << endl;
					break;
				}
				case Figures::square:
				{
					area = pow(((Square*)arr_of_figures[i])->side, 2);
					if (area > value)
						cout << "square area: " << area << endl;
					break;
				}
				case Figures::rectangle:
				{
					area = (((Rectangle*)arr_of_figures[i])->first_side * ((Rectangle*)arr_of_figures[i])->second_side);
					if (area > value)
						cout << "rectangle area: " << area << endl;
					break;
				}
				case Figures::triangle:
				{
					semi_perimeter = 0;
					semi_perimeter = (((Triangle*)arr_of_figures[i])->a + ((Triangle*)arr_of_figures[i])->b + ((Triangle*)arr_of_figures[i])->c) / 2;
					area = sqrt(semi_perimeter * (semi_perimeter - ((Triangle*)arr_of_figures[i])->a) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->b) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->c));
					if (area > value)
						cout << "triangle area: " << area << endl;
					break;
				}
				}
			}
			flag = 1;
		}
		else
		{
			cout << "repeat input!" << endl;
			cin >> value;
		}

	} while ((value <= 0 || value > AREA) || !flag);
}

/*
 * Count of all figures types
 *
 * @param arr_of_types array of types.
 * @param arr_for_figures_types array of diversity types.
 * @return pointer on the array of diversity types.
 */
size_t* CountAllTypesFigures(size_t* arr_of_types, size_t* arr_for_figures_types)
{
	for (size_t i = 0; i < N; i++)
	{
		switch (arr_of_types[i])
		{
		case Figures::circle:
		{
			arr_for_figures_types[0] += 1;
			break;
		}
		case Figures::square:
		{
			arr_for_figures_types[1] += 1;
			break;
		}
		case Figures::rectangle:
		{
			arr_for_figures_types[2] += 1;
			break;
		}
		case Figures::triangle:
			arr_for_figures_types[3] += 1;
			break;
		}
	}
	return arr_for_figures_types;
}

/*
 * Finding the total area of all shapes
 *
 * @param arr_of_figures array of figures.
 * @param arr_of_types array of types.
 * @return total area.
 */
long double TotalAreaAllShapes(void* arr_of_figures[N], size_t* arr_of_types)
{
	long double area = 0;
	long double semi_perimeter = 0;
	for (size_t i = 0; i < N; i++)
	{
		switch (arr_of_types[i])
		{
		case Figures::circle:
		{
			area += pow(((Circle*)arr_of_figures[i])->radius, 2) * PI;
			break;
		}
		case Figures::square:
		{
			area += pow(((Square*)arr_of_figures[i])->side, 2);
			break;
		}
		case Figures::rectangle:
		{
			area += (((Rectangle*)arr_of_figures[i])->first_side * ((Rectangle*)arr_of_figures[i])->second_side);
			break;
		}
		case Figures::triangle:
		{
			semi_perimeter = 0;
			semi_perimeter = (((Triangle*)arr_of_figures[i])->a + ((Triangle*)arr_of_figures[i])->b + ((Triangle*)arr_of_figures[i])->c) / 2;
			area += sqrt(semi_perimeter * (semi_perimeter - ((Triangle*)arr_of_figures[i])->a) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->b) * (semi_perimeter - ((Triangle*)arr_of_figures[i])->c));
			break;
		}
		}
	}
	return area;
}

/*
 * The main function. Does the generation and filling of two main arrays and subsequent function calls
 *
 * @return work flag.
 */
int main(void)
{
	srand(time(0));
	void* arr_of_figures[N];
	size_t arr_of_types[N];
	size_t arr_for_figures_types[P] = { 0 };

	for (size_t i = 0; i < N; i++)
		arr_of_types[i] = rand() % P;

	size_t* arr_for_figures_types_ = CountAllTypesFigures(arr_of_types, arr_for_figures_types);

	Circle* circle_arr = new Circle[arr_for_figures_types_[0]];
	Square* square_arr = new Square[arr_for_figures_types_[1]];
	Rectangle* rectangle_arr = new Rectangle[arr_for_figures_types_[2]];
	Triangle* triangle_arr = new Triangle[arr_for_figures_types_[3]];
    
	size_t arr_of_counters[P] = { 0 };
	for (size_t i = 0; i < N; i++)
	{
		switch (arr_of_types[i])
		{
			case Figures::circle:
			{
				arr_of_figures[i] = &circle_arr[arr_of_counters[0]++];
				((Circle*)arr_of_figures[i])->radius = 1 + rand() % 100;
				break;
			}
			case Figures::square:
			{
				arr_of_figures[i] = &square_arr[arr_of_counters[1]++];
				((Square*)arr_of_figures[i])->side = 1 + rand() % 100;
				break;
			}
			case Figures::rectangle:
			{
				arr_of_figures[i] = &rectangle_arr[arr_of_counters[2]++];
				((Rectangle*)arr_of_figures[i])->first_side = 1 + rand() % 100;
				((Rectangle*)arr_of_figures[i])->second_side = 1 + rand() % 100;

				break;
			}
			case Figures::triangle:
			{
				bool flag = true;
				arr_of_figures[i] = &triangle_arr[arr_of_counters[3]++];
				((Triangle*)arr_of_figures[i])->a = 1 + rand() % 100;
				((Triangle*)arr_of_figures[i])->b = 1 + rand() % 100;
				((Triangle*)arr_of_figures[i])->c = 1 + rand() % 100;
				while (true)
				{
					if (!flag)
					{
						((Triangle*)arr_of_figures[i])->a = 1 + rand() % 100;
						((Triangle*)arr_of_figures[i])->b = 1 + rand() % 100;
						((Triangle*)arr_of_figures[i])->c = 1 + rand() % 100;
					}
					if ((((Triangle*)arr_of_figures[i])->a + ((Triangle*)arr_of_figures[i])->b) > ((Triangle*)arr_of_figures[i])->c)
					{
						if ((((Triangle*)arr_of_figures[i])->a + ((Triangle*)arr_of_figures[i])->c) > ((Triangle*)arr_of_figures[i])->b)
						{
							if ((((Triangle*)arr_of_figures[i])->b + ((Triangle*)arr_of_figures[i])->c) > ((Triangle*)arr_of_figures[i])->a)
								break;
							else
							{
								((Triangle*)arr_of_figures[i])->a = 1 + rand() % 100;
								((Triangle*)arr_of_figures[i])->b = 1 + rand() % 100;
								((Triangle*)arr_of_figures[i])->c = 1 + rand() % 100;
								flag = false;
							}
						}
						flag = false;
					}
					flag = false;
				}
			}
		}
	}
	long double semi_perimeter = TotalAreaAllShapes(arr_of_figures, arr_of_types);
	cout << "area of all shapes: " << semi_perimeter << endl;
	cout << "count of circles: " << arr_for_figures_types_[0] << endl << "count of squares: " << arr_for_figures_types_[1] << endl << "count of rectangles: " << arr_for_figures_types_[2] << endl << "count of triangles: " << arr_for_figures_types_[3] << endl;
	FiguresProvided(arr_of_figures, arr_of_types);
	cout << endl << "the big circle: " << BigCircle(arr_of_figures, arr_of_types) << endl;
	/*
	for (size_t i = 0; i < N; i++)
	{
		switch (arr_of_types[i])
		{
		case Figures::circle:
		{
			cout << ((Circle*)arr_of_figures[i])->radius << " " << endl;
			break;
		}
		case Figures::square:
		{
			
			cout << ((Square*)arr_of_figures[i])->side << " " << endl;
			break;
		}
		case Figures::rectangle:
		{
			
			cout << ((Rectangle*)arr_of_figures[i])->first_side << " ";
			cout << ((Rectangle*)arr_of_figures[i])->second_side << endl;

			break;
		}
		case Figures::triangle:
		{
			
			cout << ((Triangle*)arr_of_figures[i])->a << " " << ((Triangle*)arr_of_figures[i])->b << " " << ((Triangle*)arr_of_figures[i])->c << endl;
			break;
		}
		}
	}
	*/
	return 0;
}