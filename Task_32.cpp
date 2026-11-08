#include <iostream>
#include <fstream>

class Matrix
{
private:
    int** max;
    int cols;
    int rows;
public:
    Matrix(int cols = 0,int rows = 0) : rows(rows),cols(cols),max(nullptr)
    {

		max = new int*[rows];

	    for (int i = 0;i < rows;i++)
	    {
	    	max[i] = new int[cols];
		  for (int j = 0;j < cols;j++)
		  {
			  max[i][j] = rand() % 100;
		  }    
	    }

    }

	Matrix(const Matrix& other) : rows(other.rows),cols(other.cols),max(nullptr)
    {
		max = new int* [rows];
		for (int i = 0;i < rows;i++)
		{
			max[i] = new int[cols];
			for (int j = 0;j < cols;j++)
			{
				max[i][j] = other.max[i][j];
			}
		}
    }

	~Matrix()
    {
	   for (int i = 0;i < rows;i++)
	   {
		   delete[] max[i];
	   }
	   delete[] max;
    }

	Matrix& operator=(const Matrix &other)
    {
		if (this == &other) return *this;
		
		for (int i = 0;i < rows;i++)
		{
			delete[] max[i];
		}
		delete[] max;

		rows = other.rows;
		cols = other.cols;

		max = new int*[rows];

		for (int i = 0;i < rows;i++)
		{
			max[i] = new int[cols];
			for (int j = 0;j < cols;j++)
			{
				max[i][j] = other.max[i][j];
			}
		}

		return *this;
    }

	friend std::ostream& operator<<(std::ostream& out,const  Matrix& m)
    {
		for (int i = 0; i < m.rows;i++)
		{
			for (int j = 0;j < m.cols;j++)
			{
				out << m.max[i][j] << " ";
			}
			out << '\n';
		}
		return out;
    }

	friend std::istream& operator>>(std::istream& is,Matrix& m)
    {
		for (int i = 0;i < m.rows;i++)
		{
			for (int j = 0;j < m.cols;j++)
			{
				is >> m.max[i][j];
			}
		}

		return is;
    }


};

int main()
{

	srand(time(nullptr));

	Matrix matr(3, 3);
	std::cout << matr;
	
	
	std::ofstream os("matrix.txt");
	os << matr;
	os.close();


	Matrix mart(3, 3);
	std::ifstream is("matrix.txt");
	is >> mart;
	is.close();

	std::cout << "Matrix file\n";
	std::cout << mart;


	Matrix copy = matr;
	std::cout << "Copied matrix:\n";
	std::cout << copy;


	Matrix another(2, 2);
	another = matr;
	std::cout << "Assigned matrix:\n";
	std::cout << another;


	Matrix test(3, 3);
	std::cout << "Enter matrix:\n";
	std::cin >> test;

	std::cout << test;


	
}

