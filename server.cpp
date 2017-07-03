#include <iostream>
#include <string>
#include <map>
#include <queue>
#include "morg.h"
#include <boost\asio.hpp>
using namespace std;
using namespace boost::asio;
int main(int argc, char* argv[]) {
	
	io_service iosev;
	ip::tcp::acceptor acceptor(iosev,ip::tcp::endpoint(ip::tcp::v4(), 1900));
	
	while (true) {
		ip::tcp::socket socket(iosev);
		acceptor.accept(socket);
		cout << socket.remote_endpoint().address() << endl;
		boost::system::error_code ec;
		socket.write_some(buffer("35=8;150=0;39=0"), ec);
		if (ec)
		{
			cout << boost::system::system_error(ec).what() << endl;
			break;
		}
		
		while (true) {
			std::array<char, 256> input_buffer;
			std::size_t rsize = socket.read_some(boost::asio::buffer(input_buffer), ec);
			string fixmsg(input_buffer.data(), input_buffer.data() + rsize);
			string backmsg;

			
			
		}	
	}
	return 0;
}