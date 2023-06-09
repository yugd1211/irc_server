#ifndef COMMANDHANDLER_HPP
# define COMMANDHANDLER_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <sstream>
# include "User.hpp"
# include "UserChannelController.hpp"
# include "Utility.hpp"
# include "SendMessage.hpp"

#define NICKNUM 1
#define USERNUM 2
#define PASSNUM 3
#define QUITNUM 4

class CommandHandler
{
	public:

		CommandHandler();
		~CommandHandler();
		
		// parsing
		static void NICK(User &user, std::vector<std::string> &params);
		static void PASS(User &user, std::vector<std::string> &params);
		static void USER(User &user, std::vector<std::string> &params);
		static void PRIVMSG(User &user, std::vector<std::string> &params);
		static void JOIN(User &user, std::vector<std::string> &params);
		static void PART(User &user, std::vector<std::string> &params);
		static void KICK(User &user, std::vector<std::string> &params);
		static void MODE(User &user, std::vector<std::string> &params);
		static void TOPIC(User &user, std::vector<std::string> &params);
		static void PING(User &user, std::vector<std::string> &params);
		static void QUIT(User &user, std::vector<std::string> &params);
		static void INVITE(User &user, std::vector<std::string> &params);
		static void NOTICE(User &user, std::vector<std::string> &params);
		static void CAP(User &user, std::vector<std::string> &params);
		// excute
		static int CommandRun(User &user, std::string str);

	private:
		
		// map과 함수포인터를 결합해서 사용
		void CommandInit(std::map<std::string, void(*)(User &user, std::vector<std::string> &param)> &commandMap);
		void CommandNumInit(std::map<std::string, int> &commandNum);
		static std::map<std::string, void(*)(User &user, std::vector<std::string> &param)> _commandMap;
		static std::map<std::string, int> _commandNum;

};


#endif /* ************************************************** COMMANDHANDLER_H */