# include <iostream>

// static - относительно элементов класса

class SequencesGenerator {
public:
	// static позволяет использовать метод, не создавая объект класса
	static int NextNum() {
		//static int n{}; // static - переменная перемещается на храненени не в стэке, в области памяти, где храняться глобальные переменные, {} для заполнения ноликом
		return n++;
	}
private:
	static int n; // неконстантные статитеские поля нельзя использовать без инициализации и их определение должно происходить вне класса
// Константные статические поля допустимо определять в теле класса
};

class Cat {
public:
	static void Name() {
		std::cout << name;
	}
	void Say()const {
		Name();
		std::cout << " Maf" << std::endl;
	}
	void Feed(std::string food)const {
		Name();
		std::cout << " eat: " << food << std::endl;
	}
private:
	static std::string name; // доступна в любой момент времени
};
std::string Cat::name{"Cat"}; // Определение и установка начального значения

void CatDemo() {
	std::cout << "We have a ";
	Cat::Name();
	std::cout << std::endl;
	Cat cat;
	cat.Feed("mice");
	cat.Say();
}

// Определение статических полей всегда выносим в файлы кода
int SequencesGenerator::n{6}; // По факту переменную создаём за телом класса

static int NumSequense() { // static - функция будет запрещена для вызова в других кодовых файлах программы
 	static int n{}; // static - переменная перемещается на храненени не в стэке, в области памяти, где храняться глобальные переменные, {} для заполнения ноликом
	return n++;
}

int main() {
	for (int i = 0; i < 5; ++i) {
		std::cout << NumSequense() << '\n';
	}
	// SequencesGenerator obj; // Можно и не создавать объект класса, т.к. метод static
	for (int i = 0; i < 5; ++i) {
		std::cout << SequencesGenerator::NextNum() << '\n';
	}
	CatDemo();

	return 0;
}