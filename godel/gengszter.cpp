#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>


char data[524288];

std::vector<justine::sampleclient::MyShmClient::Gangster> justine::sampleclient::MyShmClient::gangsters ( boost::asio::ip::tcp::socket & socket, int id,
    osmium::unsigned_object_id_type cop )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<gangsters " );
  length += std::sprintf ( data+length, "%d>", id );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );
    }

int idd{0};
unsigned f,t,s,ret=0;
int n{0};
int nn {0};
std::vector<unsigned> gangsters;

while (std::sscanf (data+nn, "<OK %d %u %u>%n", &idd, &f,&t,&s,&n) == 4)
{
nn+=n;
gangsters.push_back (f);
}
	std::sort (gangsters.begin(), gangsters.end(), [this,cop] (unsigned x, unsigned y){
return dst(cop,x) < dst(cop,y);
} );

std::cout.write (data,length);
std::cout << "Command GANGSTER sent." << std::endl;

if(gangsters-size()>0)
return gangsters[0];
else
return 0;
}



