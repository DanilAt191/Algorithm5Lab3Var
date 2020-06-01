#include <iostream>
#include <fstream>

using namespace std;

struct Birthday
{
	int date;
	int month;
	int year;
	bool isCorrect();
};

struct Student
{
	char surname[56];
	char name[32];
	char patronomyc[56];
	char sex[10];
	int height;
	int weight;
	char nationality[56];
	char country[32];
	char region[32];
	char city[32];
	char street[32];
	int index;
	int home;
	int apartment;
	long long int phone_number;
	char university[56];
	int course;
	char group[32];
	int point;
	char specialty[56];
	Birthday DATE;
};

bool Birthday::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((date <= 31) && (date > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((date <= 30) && (date > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((date <= 28) && (date > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((date <= 29) && (date > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((date == 28) && (date > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((date <= 29) && (date > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

void easy()
{
	cout << endl;
	cout << "Необходимо считать произвольную информацию из файла," << endl;
	cout << "переписать данную информацию в зависимости от задания," << endl;
	cout << "а также сохранить эту информацию в новый файл" << endl << endl;

	char symbol;

	string read = "Old_file.txt"; 
	string new_read = "New_file.txt";

	ofstream write; 
	ofstream new_write;

	ifstream console;

	console.open(read);

	if (!console.is_open()) 
	{
		cout << "Не удалось открыть или найти необходимый файл!" << endl << endl;
	}

	else
	{
		cout << "Файл открыт! В данном файле записано: " << endl;

		while (console.get(symbol)) 
		{
			cout << symbol;
		}

		cout << endl << endl;
	}

	console.close();

	Student* arr;
	int size, count = 0;

	do
	{
		cout << "Введите количество студентов, данные которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	arr = new Student[size];

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Введите фамилию студента под номером " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].surname, 56);
		cout << endl;

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].name, 56);
		cout << endl;

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].patronomyc, 56);
		cout << endl;

		cout << "Введите пол: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 10);
		cout << endl;

		cout << "Введите национальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 56);
		cout << endl;

		do {
			cout << "Введите рост в см: ";
			cin >> arr[i].height;
			cout << endl;
		} while (arr[i].height <= 0);

		do {
			cout << "Введите вес в кг: ";
			cin >> arr[i].weight;
			cout << endl;
		} while (arr[i].weight <= 0);

		cout << "Введите номер телефона: ";
		cin >> arr[i].phone_number;
		cout << endl;

		do
		{
			cout << "Введите День Рождения: ";
			cin >> arr[i].DATE.date;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].DATE.month;
			cout << endl;
			cout << "Год: ";
			cin >> arr[i].DATE.year;
			cout << endl;
		} while (!arr[i].DATE.isCorrect());

		do
		{
			count = 0;

			cout << "Введите почтовый индекс: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> arr[i].index;

			if (arr[i].index < 100000 && arr[i].index >= 10000)
			{
				count++;
			}
			cout << endl;

		} while (count == 0);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].country, 32);
		cout << endl;

		cout << "Введите регион: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].region, 32);
		cout << endl;

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].city, 32);
		cout << endl;

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].street, 32);
		cout << endl;

		cout << "Введите номер дома: ";
		cin >> arr[i].home;
		cout << endl;

		cout << "Введите номер квартиры: ";
		cin >> arr[i].apartment;
		cout << endl;

		cout << "Введите ВУЗ: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].university, 56);
		cout << endl;

		do {
			cout << "Введите курс: ";
			cin >> arr[i].course;
			cout << endl;
		} while (arr[i].course < 0);

		cout << "Введите группу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].group, 32);
		cout << endl;

		do {
			cout << "Введите средний балл: ";
			cin >> arr[i].point;
			cout << endl;
		} while (arr[i].point < 0);

		cout << "Введите специальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].specialty, 56);
		cout << endl << endl;
	}

	
	write.open(read);
	new_write.open(new_read);
	int count1 = 0;

	write << "Информация о студентах со средним баллом ниже 70 " << endl << endl;
	new_write << "Информация о студентах со средним баллом ниже 70 " << endl << endl;

	for (int i = 0; i < size; i++)
	{
		
		if (arr[i].point < 70)
		{
			if (!write.is_open()) 
			{
				cout << "Не удалось открыть или найти необходимый файл!" << endl;
			}

			else
			{
				write << "Фамилия студента под номером " << i + 1 << ": " << arr[i].surname << ", Имя: " << arr[i].name << ", Отчество: " << arr[i].patronomyc << ", Рост в см: " << arr[i].height << ", Вес в кг: " << arr[i].weight << endl;
				write << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Дата Рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				write << "Номер телефона: " << arr[i].phone_number << ", Почтовый индекс: " << arr[i].index << ", Страна: " << arr[i].country << ", Регион: " << arr[i].region << ", Город: " << arr[i].city << endl;
				write << "Улица: " << arr[i].street << ", Дом: " << arr[i].home << ", Квартира: " << arr[i].apartment << ", ВУЗ: " << arr[i].university << ", Курс: " << arr[i].course << ", Средний балл: " << arr[i].point << ", Специальность: " << arr[i].specialty << ", Группа: " << arr[i].group << endl << endl;
				count1++;
			}

			if (!new_write.is_open())
			{
				cout << "Не удалось открыть или найти необходимый файл!" << endl;
			}

			else
			{
				new_write << "Фамилия студента под номером " << i + 1 << ": " << arr[i].surname << ", Имя: " << arr[i].name << ", Отчество: " << arr[i].patronomyc << ", Рост в см: " << arr[i].height << ", Вес в кг: " << arr[i].weight << endl;
				new_write << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Дата Рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << endl;
				new_write << "Номер телефона: " << arr[i].phone_number << ", Почтовый индекс: " << arr[i].index << ", Страна: " << arr[i].country << ", Регион: " << arr[i].region << ", Город: " << arr[i].city << endl;
				new_write << "Улица: " << arr[i].street << ", Дом: " << arr[i].home << ", Квартира: " << arr[i].apartment << ", ВУЗ: " << arr[i].university << ", Курс: " << arr[i].course << ", Средний балл: " << arr[i].point << ", Специальность: " << arr[i].specialty << ", Группа: " << arr[i].group << endl << endl;
				count1++;
			}
		}
	}

	if (count1 == 0)
	{
		write << endl << "Нет cтудентов со средним баллом ниже 70";
		new_write << endl << "Нет cтудентов со средним баллом ниже 70";
	}
	write.close();
	new_write.close();

	cout << endl << "Соответсвенная информация вывелась в текстовый файл";
	cout << endl << endl;
}

void medium()
{
	cout << endl << "Необходимо считать из файла числа и вывести в другой файл те, которые являются квадратами целых чисел" << endl << endl;

	char arr[50], symbol;
	int count = 0, number, number_1;

	string read = "F_medium.txt"; 
	string new_read = "G_medium.txt";

	ofstream write; 

	ifstream console;

	console.open(read);

	if (!console.is_open())
	{
		cout << "Не удалось открыть или найти необходимый файл!" << endl;
	}

	else
	{
		cout << "Файл открыт! В данном файле записано: " << endl;

		while (console.get(symbol)) 
		{
			count++;
			for (int i = count; i <= count; i++)
			{
				arr[i] = symbol;
				cout << arr[i] << " ";
			}
		}
	}

	console.close();

	cout << endl << endl;

	write.open(new_read);

	for (int a = 48; a <= 57; a++)
	{
		for (int i = 1; i <= count; i++)
		{
			if (char(a) == char(arr[i]))
			{
				number_1 = char(arr[i]);
				number = abs(sqrt(char(arr[i])));
				number = pow(char(number), 2);
				if (char(number) == char(number_1))
				{
					if (!write.is_open()) 
					{
						cout << "Не удалось открыть или найти необходимый файл!" << endl;
					}

					else
					{
						write << char(number_1) << " ";
					}
				}
			}
		}
	}
	write.close();

	cout << endl << "Информация была записана в файл" << endl << endl;
}

struct number
{
	int k;
} NUMBER;

void hard()
{
	cout << "Создать k кол-во матриц m на x и m на l, записать их в файлы. Найти произведение данных матриц, записать его в отдельный файл. Вывести информацию из файлов на экран" << endl;

	int x, l, m;

	do {
		cout << endl << "Введите кол-во матриц каждого типа: ";
		cin >> NUMBER.k;
		cout << endl;
	} while (NUMBER.k < 1);

	do {
		cout << "Введите размерность матриц: ";
		cin >> x;
		cout << endl;
	} while (x < 1);

	l = x;
	m = NUMBER.k;

	string read = "One_hard.txt"; 
	string read_1 = "Two_hard.txt";
	string read_2 = "Three_hard.txt";

	ofstream write, write_1, write_2;

	int** arr, ** arr1;
	char symbol;

	arr = new int* [m];
	arr1 = new int* [m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[x];
		arr1[i] = new int[l];
	}

	write.open(read);
	write_1.open(read_1);
	write_2.open(read_2);

	if (!write.is_open() || !write_1.is_open() || !write_2.is_open())
	{
		cout << endl << "Не удалось открыть или найти один из файлов!" << endl;
	}

	
	else
	{
		for (int k = 0; k < NUMBER.k; k++)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < x; j++)
				{
					arr[i][j] = rand() % 10;
					arr1[i][j] = rand() % 15;
					write << arr[i][j] << "\t";
					write_1 << arr1[i][j] << "\t";
					arr[i][j] *= arr1[i][j];
					write_2 << arr[i][j] << "\t";
				}

				write << endl;
				write_1 << endl;
				write_2 << endl;
			}

			write << endl;
			write_1 << endl;
			write_2 << endl;
		}
	}
	write.close();
	write_1.close();
	write_2.close();

	
	ifstream console, console_1, console_2;

	console.open(read);
	console_1.open(read_1);
	console_2.open(read_2);

	if (!console.is_open() || !console_1.is_open() || !console_2.is_open()) 
	{
		cout << endl << "Не удалось открыть или найти один из файлов!" << endl;
	}

	else
	{
		cout << endl << "Файл номер 1 открыт! В данном файле записано: " << endl << endl;

		while (console.get(symbol)) 
		{
			cout << symbol;
		}

		cout << endl << "Файл номер 2 открыт! В данном файле записано: " << endl << endl;

		while (console_1.get(symbol))
		{
			cout << symbol;
		}

		cout << endl << "Файл номер 3 открыт! В данном файле записано: " << endl << endl;

		while (console_2.get(symbol))
		{
			cout << symbol;
		}

		cout << endl << endl;
	}
	console.close();
	console_1.close();
	console_2.close();
}

int main()
{
	setlocale(LC_ALL, "");

	int a;
	int count = 0;

	do
	{
		cout << "Введите номер задания (easy - 1), (medium - 2), (hard - 3): ";

		cin >> a;

		cout << endl;

		if (a == 1)
		{
			easy();
			count++;
		}

		if (a == 2)
		{
			medium();
			count++;
		}

		if (a == 3)
		{
			hard();
			count++;
		}

	} while (count == 0);

	int b;

	do
	{

		count = 0;

		cout << "Продолжить ввод? Да - 1, Нет - 2: ";

		cin >> b;

		cout << endl;

		if (b == 1)
		{
			count++;
			main();
		}

		if (b == 2)
		{
			cout << "Вы решили не продолжать";
			count++;
			break;
		}

	} while (count == 0);
}