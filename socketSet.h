/*************************************************************************
	> File Name: socketSet.h
	> Author: cjj
	> Created Time: Tue 11 Mar 2014 09:42:08 AM CST
 ************************************************************************/

#ifndef SOCKET_SET_H
#define SOCKET_SET_H

#include <set>

namespace game_server
{

class SocketSet
{
public:
	static SocketSet * GetInstance()
	{
		static SocketSet _instance;
		return &_instance;
	}

	bool AddSocket(int _sock)
	{
		m_socketSet.insert(_sock);
		return true;
	}

	bool RemoveSocket(int _sock)
	{
		std::set<int>::iterator iter = m_socketSet.find(_sock);
		if(iter != m_socketSet.end())
		{
			m_socketSet.erase(iter);
		}
		return true;
	}

	int GetMaxSocket() const
	{
		if(m_socketSet.size() > 0)
		{
			std::set<int>::iterator iter = m_socketSet.end();
			iter--;
			return *iter;
		}
		else
		{
			return -1;
		}
	}

	std::set<int>::iterator GetSocketSetBegin() const
	{
		return m_socketSet.begin();
	}

	std::set<int>::iterator GetSocketSetEnd() const
	{
		return m_socketSet.end();
	}

private:
	SocketSet(){}
	SocketSet(const SocketSet &);
	SocketSet & operator= (const SocketSet &);

private:
	std::set<int> m_socketSet;
};

typedef std::set<int>::iterator SocketSetIter;
}


#endif
