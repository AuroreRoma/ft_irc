#pragma once

#include <map>
#include <queue>
#include <set>
#include <vector>

#include <sstream>
#include <string>

#include <poll.h>
#include <stdint.h>

// used in User.hpp
#define U_MODE_RESTRICTED		0x0001	// r : restricted user
#define U_MODE_INVISIBLE		0x0002	// i : invisible
#define U_MODE_LOCAL_OPERATOR	0x0004	// o : local operator

// Used in Channel.hpp in chan_users_t
#define CU_JOINED				0x0001	//   : user is in channel
#define CU_MODE_CHAN_OPERATOR	0x0002	// o : user is channel operator

// Used in Channel.hpp in mode
#define C_MODE_LIMIT			0x0001	// l : channel limit
#define C_MODE_INVITE_ONLY		0x0002	// i : invite only
#define C_MODE_KEY				0x0004	// k : channel requires key
#define C_MODE_SECRET			0x0008	// s : secret channel
#define C_MODE_TOPIC_LOCK		0x0010	// t : topic locked (can still be changed by op)

/**
 * @brief banned user
 *
 * Can still talk in channel, if U_MODE_CHAN_OPERATOR is set
 * Can still join channel, if invited by chanop
 */

#include "User.hpp"

namespace c_irc
{
	class Message;
	class Channel;

	struct u_compare {
		bool operator()(const c_irc::User *lhs, const c_irc::User *rhs) const
		{
			return (lhs->get_nick() < rhs->get_nick());
		}
	};

	typedef std::queue<c_irc::Message *>				messages_t;
	typedef std::vector<pollfd>							pollfds_t;
	typedef std::vector<std::string>					list_users_t; // list banned and invited users
	typedef std::map<int, c_irc::User*>					serv_users_t;
	typedef std::map<int, uint16_t>						chan_users_t;
	typedef std::map<std::string, c_irc::Channel *>		channels_t;

	typedef std::vector<std::string>					arguments_t;

	typedef serv_users_t::iterator						serv_users_it_t; //suit
	typedef chan_users_t::iterator						chan_users_it_t; //cuit
	typedef channels_t::iterator						channels_it_t;

	typedef list_users_t::iterator						list_it_t;
} // namespace c_irc
