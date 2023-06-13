#include "UserChannelController.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

UserChannelController::UserChannelController()
{
}

UserChannelController::UserChannelController( const UserChannelController & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

UserChannelController::~UserChannelController()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

UserChannelController &				UserChannelController::operator=( UserChannelController const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void UserChannelController::AddUser(int fd, std::string nickname, std::string username, std::string hostname)
{
	User user(fd, nickname, username, hostname);
	_users.insert(std::pair<int, User>(fd, user));
}

void UserChannelController::RemoveUser(int id)
{
	_users.erase(id);
}

void UserChannelController::AddChannel(std::string channelName, t_ChannelMode mode)
{
	(void)mode;
	_channelID++;
	Channel channel(_channelID, channelName);
	_channels.insert(std::pair<int, Channel>(_channelID, channel));
}

void UserChannelController::RemoveChannel(int id)
{
	_channels.erase(id);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */