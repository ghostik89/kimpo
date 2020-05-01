#include "morze.h"

void DecodeMorze(const string& DecodeString, vector<string>& DecodedVariants, const string& BuildString)
{
	string CopyBuildString = BuildString;//Изначально работаем с копией строки промежуточных данных
	//Изначально имеем словарь вида буква-ее перевод

	if (DecodeString.empty() || DecodeString.length() == 0) { //Если исходная строка пустая...
		DecodedVariants.push_back(CopyBuildString); //...то необходимо добавить строку с промежуточными данными в список возможных переводов
		CopyBuildString = "";
	}

	else { //Иначе 
		//Поиск в словаре буквы, которая находится в начале исходной строки
		for (auto& elem : Dictionary) { 
			if (DecodeString.find(elem.first) == 0) {  

				CopyBuildString.push_back(elem.second); //Записать перевод найденной буквы в строку с помежуточными данными
				string TempStrig = DecodeString.substr(elem.first.length()); //Создать копию исходной строки без первой переведнной буквы 
				DecodeMorze(TempStrig, DecodedVariants, CopyBuildString);//Рекурсивно вызвать эту же функцию, используя новые значения промежуточных данных и копию подстроки
				CopyBuildString.pop_back(); //Очистить строку с промежуточными данными от перевода текущей буквы
			}
		}
	}
}

bool CheckStringForInvalidSym(const string& CheckedString)
{
	//Изначально считаем, что посторонних символов в строке нет
	for (const char& c : CheckedString)//Просматриваем каждый символ в строке
		if (c != '.' && c != '-')//если обнаружен посторонний символ...
			return false; //...то выдаем ошибку
	return true;//Если посторонних символов не обнаружено, то говорим об отсутствии посторонних символов
}

