#include <array>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <string>
#include"morg.h"
using boost::asio::ip::tcp;
int main(int argc, char* argv[])
{
	boost::asio::io_service io_service;
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("127.0.0.1", "1900");
	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoint_iterator);
	boost::system::error_code error;

	string ordid; double pri; int sha; int si;
	cout << "orderid?" << " ";
	cin >> ordid;
	cout << "price?" << " ";
	cin >> pri;
	cout << "share?" << " ";
	cin >> sha;
	cout << "side?(0 for buyer, 1 for seller)" << " ";
	cin >> si;
	map<double, vector<int>> buyer;
	map<double, vector<int>> seller;
	if (si == 0) {
		buyer[pri].push_back(sha);
	}
	else{ seller[pri].push_back(sha); }
	std::string my_name = "35=D";
	boost::asio::write(socket, boost::asio::buffer(my_name), error);

	std::array<char, 256> input_buffer;
	std::size_t rsize = socket.read_some(
		boost::asio::buffer(input_buffer), error);
	

	std::cout<<std::string(input_buffer.data(), input_buffer.data() + rsize) << std::endl;
	return 0;
}