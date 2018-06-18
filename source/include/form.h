#ifndef FORM_H_INCLUDED
#define FROM_H_INCLUDED

#define DEFAULT_FONT "data/Caviar Dreams.ttf"

using namespace std;

namespace form {

class Label {
public:
	string text="CHANGE THIS";	//�����
protected:
    sf::Font None;	// ����� ��������� �������������
	double x;		//���������� x
	double y;		//���������� y

	sf::Text TXT;		//������������ �����

public:
	Label(double _x = 0, double _y = 0, string _text ="Text")
	{
		None.loadFromFile(DEFAULT_FONT);			//�������� ������ ������ ���� ������

		x = _x;
		y = _y;
		text = _text;								// ��������� �����
		TXT.setFont(None);							// ��������� �����
		TXT.setCharacterSize(20); 					// � ��������, � �� ������!
		TXT.setFillColor(sf::Color::Black);					// ������������� ���� ���������� ������
		TXT.setPosition(x,y);						// ������� ������
	}
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// ��������� � ��������� ����� ����������� �����
		//return TXT;
	}
};

class Button : public Label {
protected:
	double width;		// ������ ������
	double height;		// ������ ������
	sf::RectangleShape BOX;	// ������� ������������� � �������� width, height
public:
	Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, string _text ="Button")
	{
		None.loadFromFile(DEFAULT_FONT);			//�������� ������ ������ ���� ������

		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;								// ��������� �����
		TXT.setFont(None);							// ��������� �����
		TXT.setCharacterSize(20); 					// � ��������, � �� ������!
		TXT.setFillColor(sf::Color::Black);					// ������������� ���� ���������� ������
		TXT.setPosition(x,y);						// ������� ������

		BOX.setSize(sf::Vector2f(width, height));		// ������ ������
		BOX.setPosition(x,y);						// ���������� ������
		BOX.setFillColor(sf::Color(133, 133, 133));	// ���� ������
		BOX.setOutlineThickness(2);					// ������ X ��������
		BOX.setOutlineColor(sf::Color(66, 66, 66));		// ���� �������
	}
	//�������� ������� �� ������
	bool select(sf::Vector2i _mouse, bool MouseReleased)
	{
		if((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)){
			return MouseReleased;
		} else {
			return false;
		}
	}
	//����� ������
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// ��������� � ��������� ����� ����������� �����
		//return TXT;
	}
	//����� ������
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
		text = _text;								// ��������� �����
		focus = false;								// ����� ���� �����

		TXT.setFont(None);							// ��������� �����
		TXT.setCharacterSize(20); 					// � ��������, � �� ������!
		TXT.setFillColor(sf::Color::Black);					// ������������� ���� ���������� ������
		TXT.setPosition(x,y);						// ������� ������

		BOX.setSize(sf::Vector2f(width, height));		// ������ ���� �����
		BOX.setPosition(x,y);						// ���������� ���� �����
		BOX.setFillColor(sf::Color::White);	// ���� ������
	}
	//����� .reText( char ) �������� ����� ������ ������ ���� ������ Input
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

	// �������� ������ Input
	bool select()
	{
		return focus;
	}

	// ��������� ������ Input
	bool select(sf::Vector2i _mouse)
	{
		if((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)){ 	//���� ����� ������ ��� �������� Input...
			focus = true;
			if(text[text.size()-1] != 124)																	   	// ����� true
                text += "|";																		// � ����� ������ �������� | (��� �� �������� ��� input � ������)
		} else {																				//...����� ���� ������� ��������� �� ��� ��������, ��...
			if(text.size() > 0){																// �������� ���������� �������(����� ��������)
				if(text[text.size()-1] == 124){													// ���� ������ | ...
				text.erase(text.size()-1);														// ... �� ������� ���
				}
			}
			focus = false;																		// ������������� ����� false
		}
		return focus;
	}

	//����� ������
	void displayText(sf::RenderWindow& window)
	{
		TXT.setString(text);
		window.draw(TXT);						// ��������� � ��������� ����� ����������� �����
		//return TXT;
	}

	//����� ���� Input
	void displayBOX(sf::RenderWindow& window)
	{
	    window.draw(BOX);
        //return BOX;
	}

	//��� ����, ��� �� ������� ����� � ���� Ipnut ���������� ���������  readText() ������� ���������� string
	string readText()
	{
		if(text[text.size()-1] == 124){ 	// ������� (���� ����) ������ |
			text.erase(text.size()-1);
		}
		return text;
	}
};

} /* namespace form */


#endif // FORM_H_INCLUDED
