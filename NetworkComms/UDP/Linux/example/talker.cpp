/*
	Sending and Receiving Packets Example
	From "Networking for Game Programmers" - http://www.gaffer.org/networking-for-game-programmers
	Author: Glenn Fiedler <gaffer@gaffer.org>
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Net.h"

using namespace std;
using namespace net;

int main( int argc, char * argv[] )
{
	// initialize socket layer

	if ( !InitializeSockets() )
	{
		printf( "failed to initialize sockets\n" );
		return 1;
	}
	
	// create socket

	int myPort = 30000;

	if ( argc == 2 )
		myPort = atoi( argv[1] );

	printf( "creating socket on port %d\n", myPort );

	Socket socket;
	if ( !socket.Open( myPort ) )
	{
		printf( "failed to create socket!\n" );
		return 1;
	}

	// read in addresses.txt to get the set of addresses we will send packets to

	vector<Address> addresses;

	string line;
	ifstream file( "addresses.txt" );
	if ( !file.is_open() )
	{
		printf( "failed to open 'addresses.txt'\n" );
		return 1;
	}

	while ( !file.eof() )
	{
		getline( file, line );
		int a,b,c,d,port;
		if ( sscanf( line.c_str(), "%d.%d.%d.%d:%d", &a, &b, &c, &d, &port ) == 5 )
			addresses.push_back( Address( a,b,c,d,port ) );
	}

	file.close();
	// send and receive packets until the user ctrl-breaks...

	while ( true )
	{
		char data[100];
		scanf ("%[^\n]%*c", data);
		
		for ( int i = 0; i < (int) addresses.size(); ++i )
		{
			if(addresses[i].GetPort() != myPort-2)
				socket.Send( addresses[i], data, sizeof( data ) );
		}
	}
	
	// shutdown socket layer
	
	ShutdownSockets();

	return 0;
}
