#include "../std_lib_facilities.h"

struct Point
{
	float x, y;
};

// Point operators
istream& operator>>(istream& is, Point& point)
{
	char p1, com, p2;
	float x, y;

	is >> p1 >> x >> com >> y >> p2;
	if (!is) return is;
	if (p1 != '(' || com != ',' || p2 != ')')
	{
		is.clear(ios_base::failbit);
		return is;
	}
	point = Point{x, y};

	return is;
}

ostream& operator<<(ostream& os, Point& point)
{
	return os << '('  << point.x
			  << ", " << point.y
			  << ')';
}

bool operator!=(Point& left, Point& right)
{
	if (left.x != right.x ||
		left.y != right.y)
		return true;
	return false;
}

bool operator!=(vector<Point>& left, vector<Point>& right)
{
	if (left.size() != right.size())
		return true;
	else
	{
		for (int i = 0; i < left.size(); i++)
			if (left[i] != right[i])
				return true;
	}

	return false;
}

// Point vector utility
void cout_points_vector(vector<Point>& points)
{
	for (Point point : points) cout << point << '\n';
}

void write_points_to_file(vector<Point>& points, string file_name)
{
	ofstream os;
	os.open(file_name);

	for (Point point : points) os << point << '\n';
}

vector<Point> read_points_from_file(string file_name)
{
	vector<Point> new_vector;

	ifstream is;
	is.open(file_name);

	for (Point point; is >> point; ) new_vector.push_back(point);

	return new_vector;
}

vector<Point> vector_input_of_size(int size)
{
	vector <Point> points;

	while (points.size() < size)
	{
		Point point;
		cin >> point;
		points.push_back(point);
	}

	return points;
}

int main()
{
	cin.exceptions(cin.exceptions()|ios_base::badbit);

	// original vector
	cout << "Enter 7 points: \n"
		 << "Example: '(2, 3)'\n";
	vector<Point> original_points = vector_input_of_size(2);

	cout << "Original points:\n";
	cout_points_vector(original_points);

	// write to file
	write_points_to_file(original_points, "mydata.txt");
	// read from file
	vector<Point> processed_points = read_points_from_file("mydata.txt");

	// output vector data
	cout << "\nOriginal points:\n";
	cout_points_vector(original_points);

	cout << "\nProcessed vector:\n";
	cout_points_vector(processed_points);

	if (original_points != processed_points)
		cout << "Something's wrong!";

	keep_window_open();
	return 0;
}