#ifndef FORM_H_INCLUDED
#define FROM_H_INCLUDED

#define DEFAULT_FONT "data/Caviar Dreams.ttf"

using namespace std;

namespace form {

class Label {
public:
	string text="CHANGE THIS";	//Текст
protected:
    sf::Font None;	// Шрифт первичная инициализация
	double x;		//Координата x
	double y;		//Координата y

	sf::Text TXT;		//Отображаемый текст

public:
	Label(double _x = 0, double _y = 0, string _text ="Text")
	{
		None.loadFromFile(DEFAULT_FONT);			//передаем нашему шрифту файл шрифта

		x = _x;
		y = _y;
		text = _text;								// загружает текст
		TXT.setFont(None);							// загружаем фрифт
		TXT.setCharacterSize(20); 					// в пикселях, а не точках!
		TXT.setFillColor(sf::Color::Black);					// устанавливаем цвет выводимого текста
		TXT.setPosition(x,y);						// позиция текста
	}
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// загружаем в выводимый текст загружаемый текст
		//return TXT;
	}
};

class Button : public Label {
protected:
	double width;		// Ширина Кнопки
	double height;		// Высота Кнопки
	sf::RectangleShape BOX;	// Создаем прямоугольник с размером width, height
public:
	Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text ="Button")
	{
		None.loadFromFile(DEFAULT_FONT);			//передаем нашему шрифту файл шрифта

		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;								// загружает текст
		TXT.setFont(None);							// загружаем фрифт
		TXT.setCharacterSize(20); 					// в пикселях, а не точках!
		TXT.setFillColor(sf::Color::Black);					// устанавливаем цвет выводимого текста
		TXT.setPosition(x,y);						// позиция текста

		BOX.setSize(sf::Vector2f(width, height));		// размер кнопки
		BOX.setPosition(x,y);						// координаты кнопки
		BOX.setFillColor(sf::Color(133, 133, 133));	// цвет кнопки
		BOX.setOutlineThickness(2);					// Контур X пикселей
		BOX.setOutlineColor(sf::Color(66, 66, 66));		// Цвет контура
	}
	//Проверка нажатия на кнопку
	bool select(sf::Vector2i _mouse, bool MouseReleased)
	{
		if((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)){
			return MouseReleased;
		} else {
			return false;
		}
	}
	//Вывод Текста
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// загружаем в выводимый текст загружаемый текст
		//return TXT;
	}
	//Вывод кнопки
	void displayButton(sf::RenderWindow& window)
	{
        window.draw(BOX);
        //return BOX;
	}


};

class Input : public Button{
protected:
	bool focus;
public:
	Input(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text ="")
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;								// загружает текст
		focus = false;								// фокус поля ввода

		TXT.setFont(None);							// загружаем фрифт
		TXT.setCharacterSize(20); 					// в пикселях, а не точках!
		TXT.setFillColor(sf::Color::Black);					// устанавливаем цвет выводимого текста
		TXT.setPosition(x,y);						// позиция текста

		BOX.setSize(sf::Vector2f(width, height));		// размер поля ввода
		BOX.setPosition(x,y);						// координаты поля ввода
		BOX.setFillColor(sf::Color::White);	// цвет кнопки
	}
	//метод .reText( char ) изменяет текст внутри класса Типа данных Input
	void reText(char _tmp)
	{
		text.erase(text.size()-1);

		if(_tmp != 8){
		text += _tmp;
		} else {
			if(text.size() > 0){
				text.erase(text.size()-1);
			}

		}
		text += "|";
		TXT.setString(text);
	}

	// Проверка Фокуса Input
	bool select()
	{
		return focus;
	}

	// Установка Фокуса Input
	bool select(sf::Vector2i _mouse)
	{
		if((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)){ 	//Если нажат клаиша над объектом Input...
			focus = true;
			if(text[text.size()-1] != 124)																	   	// Фокус true
                text += "|";																		// В конец строки добаляем | (что бы понимать что input в фокусе)
		} else {																				//...Иначе если нажатие произошло не над объектом, то...
			if(text.size() > 0){																// проверка последнего символа(иначе вылетает)
				if(text[text.size()-1] == 124){													// если символ | ...
				text.erase(text.size()-1);														// ... то удаляем его
				}
			}
			focus = false;																		// устанавливаем фокус false
		}
		return focus;
	}

	//Вывод Текста
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// загружаем в выводимый текст загружаемый текст
		//return TXT;
	}

	//Вывод фона Input
	void displayBOX(sf::RenderWindow& window)
	{
	    window.draw(BOX);
        //return BOX;
	}

	//Для того, что бы считать текст с поля Ipnut необходимо пременить  readText() который возвращает string
	string readText()
	{
		if(text[text.size()-1] == 124){ 	// удаляем (если есть) символ |
			text.erase(text.size()-1);
		}
		return text;
	}
};

} /* namespace form */


#endif // FORM_H_INCLUDED
