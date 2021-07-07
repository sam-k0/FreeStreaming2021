#include <mediafile.h>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Mediafile::Mediafile(std::string _title, int _length, std::string _genre):title(_title), length(_length), genre(_genre)
//{ // list constructor
 //  avgrating = 0;
  // totalratings = 0;
//}
Mediafile::Mediafile(){}

void Mediafile::showMeta()
{
    cout << ">> MOVIE : Information on movie"<<endl;
    cout << "|--Title: " << title << endl;
    cout << "|--Duration: " << length << endl;
    cout << "|--Rating: " << avgrating <<" (based off "<< ratings.size() << " ratings)"<< endl;
    cout << "|--Genre: " << genre << endl;
}

void Mediafile::addRating(int _rating)
{
    try{
        //catch troll
        if(_rating > 5)
        {
            _rating = 5;
        }
        else if(_rating < 1)
        {
            _rating = 1;
        }

        ratings.push_back(_rating);

        double _total =0;

        for(int i = 0; i<int(ratings.size()); i++)
        {
            _total += ratings[i];
        }

        avgrating = _total/ratings.size();
        cout << ">> INFO : MOVIE : Added rating: "<<_rating << " to movie: "<<title<< endl;
        //showRatings();
    }
    catch (...) {
        cout << "Something went wrong.."<<endl;
    }
}

void Mediafile::playback()
{
    cout << ">> INFO : MOVIE : Now playing: " << title <<" with average rating: "<< avgrating << endl;
}

std::string Mediafile::getTitle()
{
    return title;
}

double Mediafile::getAvgRating()
{
    return avgrating;
}

int Mediafile::getLength()
{
    return length;
}

void Mediafile::showRatings()
{
     cout << ">> DEBUG : Displaying all ratings: "<<endl;
    for(int i = 0; i<int(ratings.size());i++)
    {
        cout << ","<<ratings[i];
    }
}

string Mediafile::getRatingsString()
{
    string _rstring = " ";

    for(int i = 0;i<int(ratings.size()); i++)
    {
        _rstring.append(to_string(ratings[i]));
        _rstring.append(" ");
    }

    return _rstring;
}

string Mediafile::getGenre()
{
    return genre;
}

Mediafile::~Mediafile()
{

}

