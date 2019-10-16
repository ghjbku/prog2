#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using Submarks = std::map< std::string, std::map< std::string, int > >;

Submarks get_submarks ( std::vector<std::string> folder_names, std::string db_name )
{

        Submarks submarks;

        std::ifstream db ( db_name );

        std::string line;
        while ( std::getline ( db, line ) ) {

                boost::tokenizer<boost::escaped_list_separator<char>> tokens {line};

                auto iter = tokens.begin();
                std::string name = *iter;
                std::string act = *++iter;
                std::string tstamp = *++iter;

                act = act.substr ( 2 );

                for ( const auto & node : folder_names ) {

                        if ( repl_mark ( submarks, name, act, node, "jeles", 5 ) )
                                ;
                        else if ( repl_mark ( submarks, name, act, node, "jó", 4 ) )
                                ;
                        else if ( repl_mark ( submarks, name, act, node, "közepes", 3 ) )
                                ;
                        else if ( repl_mark ( submarks, name, act, node, "elégséges", 2 ) )
                                ;
                        else if ( repl_mark ( submarks, name, act, node, "elégtelen", 1 ) )
                                ;
                }

        }

        return submarks;
}

std::map <std::string, int> get_marks ( Submarks & submarks )
{

        std::map <std::string, int> marks;

        for ( auto & user : submarks ) {


                int sum = std::accumulate ( user.second.begin(), user.second.end(), 0,
                [] ( int total, std::pair<std::string, int> pair ) {
                        return total + pair.second;
                } );

                marks[user.first] = sum / user.second.size();

        }

        return marks;

}

std::vector<std::pair<std::string, int>> sort_map ( std::map <std::string, int> &rank )
{
        std::vector<std::pair<std::string, int>> ordered;

        for ( auto & i : rank ) {
                if ( i.second ) {
                        std::pair<std::string, int> p {i.first, i.second};
                        ordered.push_back ( p );
                }
        }

        std::sort (
                std::begin ( ordered ), std::end ( ordered ),
        [ = ] ( auto && p1, auto && p2 ) {
                return p1.second > p2.second;
        }
        );

        return ordered;
}

int main ( int argc, char *argv[] )
{
	Submarks submarks = get_submarks ( def_ops_roots, vm["db"].as < std::string > () );

	std::map <std::string, int> marks = get_marks ( submarks );

	std::vector<std::pair<std::string, int>> res = sort_map ( marks );

                                for ( auto & i : res )
                                        std::cout << i.first << " "  << i.second << std::endl;

                                return 0;
}
