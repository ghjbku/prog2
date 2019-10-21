#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

//-lboost_system -lboost_filesystem -std=c++14

/*
--A forrás Kovács Ferencz tulajdona
*/
#define GetCurrentDir getcwd
using namespace std;

vector<string> searchRootFolders (vector<string> folders);
void readClasses (string path, vector<string>& classes);

string GetCurrentWorkingDir( void )
{
char buff[FILENAME_MAX];
GetCurrentDir( buff, FILENAME_MAX );
string current_working_dir(buff);
return current_working_dir;
}

int main(int argc, char const *argv[])
{std::move()
vector<string> roots = {
GetCurrentWorkingDir()+"/"+"src"
};

vector<string> classes = searchRootFolders ( roots );
cout<<endl<<"-----------------Printing java classes------------------------"<<endl;
for(auto &i : classes)
{
cout << i << endl;
}
cout << "összesen " << classes.size() << " osztály található\n";
return 0;
}

void readClasses ( boost::filesystem::path path, vector<string>& classes)
{
if ( is_regular_file ( path ) ) {
std::string ext ( ".java" );
if ( !ext.compare ( boost::filesystem::extension ( path ) ) ){
classes.push_back(path.string());
}
} else if ( is_directory ( path ) )
for ( boost::filesystem::directory_entry & entry : boost::filesystem::directory_iterator ( path ) )

readClasses ( entry.path(),classes);
}

vector<string> searchRootFolders (vector<string> folders)
{
vector <string> classes;
for ( const auto & path : folders)
{
boost::filesystem::path root ( path );
readClasses ( root, classes);
}
return classes;
}