#include "morze.h"

void DecodeMorze(const string& DecodeString, vector<string>& DecodedVariants, const string& BuildString)
{
	string CopyBuildString = BuildString;//»значально работаем с копией строки промежуточных данных
	//»значально имеем словарь вида буква-ее перевод

	if (DecodeString.empty() || DecodeString.length() == 0) { //≈сли исходна€ строка пуста€...
		DecodedVariants.push_back(CopyBuildString); //...то необходимо добавить строку с промежуточными данными в список возможных переводов
		CopyBuildString = "";
	}

	else { //»наче 
		//ѕоиск в словаре буквы, котора€ находитс€ в начале исходной строки
		for (auto& elem : Dictionary) { 
			if (DecodeString.find(elem.first) == 0) {  

				CopyBuildString.push_back(elem.second); //«аписать перевод найденной буквы в строку с помежуточными данными
				string TempStrig = DecodeString.substr(elem.first.length()); //—оздать копию исходной строки без первой переведнной буквы 
				DecodeMorze(TempStrig, DecodedVariants, CopyBuildString);//–екурсивно вызвать эту же функцию, использу€ новые значени€ промежуточных данных и копию подстроки
				CopyBuildString.pop_back(); //ќчистить строку с промежуточными данными от перевода текущей буквы
			}
		}
	}
}

