#include <stdio.h>
#include<iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <fstream>

using std::begin;
using std::end;

using std::cout;
using std::endl;

using std::vector;
using std::list;

struct simple_neuron {
	enum state { LOWER_STATE = -1, UPPER_STATE = 1 };

	typedef float coeff_t; // Тип весовых коэффициентов
	typedef state state_t; // Тип описывающий состояние нейтрона

	static state read(char c) {
		return (c == '*' ? UPPER_STATE : LOWER_STATE); // Задаем значения для нейрона в зависимости от содержимого
	}

	static char write(state s) { // Создаем функцию для записи исправленного числа
		if (s == LOWER_STATE) {
			return ' ';
		}
		else {
			return '*';
		}
	}

	template <typename n_A, typename n_B> // Создаем шаблон  и создаем встроенный тип данных
	static state_t calculate(n_A val_b, n_A val_e, n_B coeff_b) {
		auto value = std::inner_product(
			val_b,
			val_e,
			coeff_b,
			coeff_t(0)
		);

		return value > 0 ? UPPER_STATE : LOWER_STATE;
	}
};

typedef simple_neuron neuron_t;
typedef neuron_t::state_t state_t;
typedef vector<state_t> neurons_line; //тип, описывающий состояние сети в момент t(выбран стандартный контейнер vector);
typedef vector<vector<neuron_t::coeff_t>> link_coeffs; // тип, описывающий матрицу весовых коэффициентов связей нейронов (выбран контейнер vector контейнеров vector).


struct neuro_net_system { // Создаем структуру для нейронной сети
	const link_coeffs &_coeffs; // Создаем переменную для коэффициентов

	neuro_net_system(const link_coeffs &cfs) : _coeffs(cfs) {} 

	bool do_step(neurons_line& line) { // Функция для шага
		bool value_changed = false;

		neurons_line old_val(begin(line), end(line));
		link_coeffs::const_iterator it_cfs = begin(_coeffs);

		std::transform(
			begin(line),
			end(line),
			begin(line),
			[&old_val, &it_cfs, &value_changed](state_t old_value) -> state_t {
			auto new_value = neuron_t::calculate(
				begin(old_val),
				end(old_val),
				begin(*it_cfs++)
			);

			value_changed = (new_value != old_value) || value_changed;

			return new_value;
		});

		return value_changed;
	}

private:
	size_t _steps_done;
};

neurons_line read_neurons_state(const std::string &file_path, size_t len) { // Считываем состояние нейронов
	std::ifstream i_file(file_path);

	size_t i = 0;
	neurons_line result;
	result.reserve(len);

	while (i++ < len) {
		char val;
		i_file >> val;
		auto state = neuron_t::read(val);
		result.push_back(state);
	}

	return result;
}

link_coeffs learn_neuro_net(const list<neurons_line> &src_images) {
	link_coeffs res_cfs;
	size_t neurons_count = src_images.front().size();

	res_cfs.resize(neurons_count);
	for (size_t i = 0; i < neurons_count; ++i) {
		res_cfs[i].resize(neurons_count, 0);
	}

	for (size_t i = 0; i < neurons_count; ++i) {
		for (size_t j = 0; j < i; ++j) {
			neuron_t::coeff_t val = 0;
			val = std::accumulate(
				begin(src_images),
				end(src_images),
				neuron_t::coeff_t(0.0),
				[i, j](neuron_t::coeff_t old_val, const neurons_line &image) -> neuron_t::coeff_t {
				return old_val + (image[i] * image[j]);
			});
			res_cfs[i][j] = val;
			res_cfs[j][i] = val;
		}
	}

	return res_cfs;
}

struct neurons_line_print_descriptor {
	const neurons_line &_line;
	const size_t _width;
	const size_t _height;

	neurons_line_print_descriptor(
		const neurons_line &line,
		size_t width,
		size_t height
	) : _line(line),
		_width(width),
		_height(height)
	{}
};

template <typename Ch, typename Tr>
std::basic_ostream<Ch, Tr>&
operator << (std::basic_ostream<Ch, Tr>&stm, const neurons_line_print_descriptor &line) {
	neurons_line::const_iterator it = begin(line._line), it_end = end(line._line);

	for (size_t i = 0; i < line._height; ++i) {
		for (size_t j = 0; j < line._width; ++j) {
			stm << neuron_t::write(*it);
			++it;
		}
		stm << endl;
	}

	return stm;
}


int main(int argc, char* argv[])
{
	list<neurons_line> src_images;
	std::string target_file_path;
	size_t wdth, hgt;

	if (argc < 4) {
		cout << "Invalid parameters." << endl;
		cout << "Usage: AppName WIDTH HEIGHT SOURCE_FILE LEARNING_FILE_1 [LEARNE_FILE_N]" << endl;
		exit(1);
	}

	int arg_pos = 1;
	wdth = atol(argv[arg_pos++]);
	hgt = atol(argv[arg_pos++]);
	target_file_path = argv[arg_pos++];

	while (arg_pos < argc) {
		src_images.push_back(read_neurons_state(argv[arg_pos++], wdth * hgt));

		cout << "Image to learn: " << endl;
		cout << neurons_line_print_descriptor(src_images.back(), wdth, hgt) << endl;
	}

	link_coeffs coeffs = learn_neuro_net(src_images);

	neuro_net_system net(coeffs);

	neurons_line line;
	line = read_neurons_state(target_file_path, wdth * hgt);

	cout << "---------------------------" << endl;
	cout << "start: " << endl;
	cout << neurons_line_print_descriptor(line, wdth, hgt) << endl;
	cout << "---------------------------" << endl;

	cout << neurons_line_print_descriptor(line, wdth, hgt) << endl;
	cout << "---------------------------" << endl;

#if defined(_WINDOWS)
	system("pause");
#endif

	return 0;
}