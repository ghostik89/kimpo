#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include "morze.h"

using namespace std;

/*! \mainpage Курсовой проект по КИНПО
 *
 *  \author    Тарапатина Екатерина Сергеевна
 *  \version   1.0
 *  \date      2020
 *  \details  Курсовой проект
 *  \details  Программа предназначена для выдачи всех возможных перереводов строки азбуки Морзе
 */


 /*!Массив сообщений об различных ошибках*/
const string ERRORS_ARRAY[3] = {
	"Can't write results to file result.txt",
	"Incorrect fileway!",
	"Incorrect Morze message!"
};

/*!Главная функция проекта
	\param[in] argc - количество аргументов командной строки
	\param[in] argv - аргументы командной строки
	\return - 0, если программа завершилась успешно, иначе код ошибки
*/
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");									   //разрешить русский язык
	ifstream in;												   //поток на считывания из файла
	ofstream out("result.txt", ios_base::out | ios_base::trunc);   //поток на запись файла

																   //проверка возможности записать в файл
	if (!out.is_open()) {
		cout << ERRORS_ARRAY[0];                                   
		return 0;
	}

	string MorzeString;											  //получение пути файла с сообщением на азбуке Морзе
	string TempPath;											
	if (argc > 1) {                                               
		TempPath = argv[1];                                       
	}
	else {                                                        
		cout << "Enter path for message in Morze\n";              
		cin >> TempPath;                                          
	}

	in.open(TempPath);                                            //открываем файл на считывание
	if (!in.is_open()) {                                          //проверка на возможность считывания данных
		out << ERRORS_ARRAY[1];                                   
		cout << ERRORS_ARRAY[1];
		return 0;
	}
	in >> MorzeString;                                            //считать строку

	if (!CheckStringForInvalidChar(MorzeString)) {                //проверка на некорректные символы
		out << ERRORS_ARRAY[2];
		cout << ERRORS_ARRAY[2];
		return 0;
	}

	vector<string> Results;                                      //возможные варианты расшифровки
	DecodeMorze(MorzeString, Results, "");                       //получение возможных вариантов расшифроки

	//запись их в файл
	std::ostream_iterator<std::string> output_iterator(out, "\n");
	std::copy(Results.begin(), Results.end(), output_iterator);
	cout << "Complete translate";                                //уведомление о завершении работ

	return 0;
}