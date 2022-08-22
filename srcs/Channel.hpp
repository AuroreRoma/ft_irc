#pragma once

#include "c_irc.hpp"
#include "User.hpp"

#include <map>
#include <string>

namespace c_irc
{
	class Channel
	{
		private:

		// max length : 50 chars
		// case insensitive
		// start with "#, &, + or !"
		// no spaces, ^G or commas
		std::string		name;

		std::string		topic;
		std::string		key;
		uint16_t		mode;
		uint16_t		limit;

		users_t			users;

		Channel();
		Channel(const Channel &other);
		Channel &operator=(const Channel &other);

		public:

		Channel(std::string	new_name, c_irc::User *user);
		~Channel();

		std::string		get_name() const;
		std::string		get_topic() const;
		std::string		get_key() const;
		uint16_t		get_mode() const;
		uint16_t		get_limit() const;

		void			set_topic(std::string new_topic);
		void			set_key(std::string new_key);
		void			set_mode(uint16_t new_mode);
		void			set_limit(uint16_t new_limit);

		void			set_user_mode(c_irc::User *user, uint16_t new_mode);
		void			unset_user_mode(c_irc::User *user, uint16_t new_mode);

		void			add_user(c_irc::User* new_user);
		void			remove_user(c_irc::User* new_user);

		void			ban_user(std::string new_user);
		void			unban_user(std::string new_user);

		bool			is_name_valid(std::string new_name);
		bool			is_user_banned(std::string new_user);
		bool			is_user_in_channel(std::string new_user);

		users_it_t		begin();
		users_it_t		end();
	};
} // namespace c_irc
