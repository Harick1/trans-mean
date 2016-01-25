#include <fstream>
#include <string>
#include <iostream>
#include "BlobProto.pb.h"
using namespace std;

int main(int argc, char **argv) {
	string input_file = argv[1];
	string output_file = argv[2];
	fstream input(input_file.c_str(), ios::in | ios::binary);
	BlobProto sum_blob;
	sum_blob.ParseFromIstream(&input);
	cout << "channels: " << sum_blob.channels() << endl;
	cout << "height: " << sum_blob.height() << endl;
	cout << "width: " << sum_blob.width() << endl;
	double b(0.), g(0.), r(0.);
	fstream output(output_file.c_str(), ios::out);
	int size = sum_blob.data_size() / sum_blob.channels();
	for (int i(0); i < size; i++) {
		double tmp = sum_blob.data(i);
		output << tmp << " ";
		b += tmp;
	}
	output << "\n";
	if (sum_blob.channels() == 1) {
		b /= size;
		cout << "avg pixel: " << b << endl;
		output.close();
		return 0;
	}
	for (int i(0); i < size; i++) {
		double tmp = sum_blob.data(size+i);
		output << tmp << " ";
		g += tmp;
	}
	output << "\n";
	for (int i(0); i < size; i++) {
		double tmp = sum_blob.data(size*2+i);
		output << tmp << " ";
		r += tmp;
	}
	output << "\n";
	output.close();
	b /= size;
	g /= size;
	r /= size;
	cout << "b: " << b << " g: " << g << " r: " << r << endl;
	// cout << "data: " << sum_blob.data() << endl;
	return 0;
}
