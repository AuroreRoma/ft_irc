#include "Server.hpp"
#include <iostream>

namespace c_irc
{
	void Server::cmd_invite(int fd, arguments_t &args)
	{
		std::cout << "cmd invite" << std::endl; 
		std::cout << fd << &args << std::endl; 
	}
} 