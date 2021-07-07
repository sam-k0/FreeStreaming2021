#include <database.h>
#include <film.h>
#include <serie.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

vector <Mediafile*> Database::movieVec;

Database::Database()
{

}

Database::~Database()
{

}

void Database::showAll()
{
    cout << "-----SHOWING ALL-----"<<endl;
    if(movieVec.size() != 0)
    {
        // catch vec empty

        cout << "Showing all "<< movieVec.size() << " mediafiles:" << endl;
        for (auto i : movieVec) // iterate over vector, i is type Movie
        {
            i->showMeta();
        }
    }
    else
    {
        // is empty
        cout << "Sorry, there are no movies available." << endl;
    }

}

bool Database::addVideo(Mediafile* _toAdd)
{
    movieVec.push_back(_toAdd);
    cout << ">> DATABASE : Successfully added movie to database!"<<endl;
    return true;
}

bool Database::removeVideo( int _pos)
{
    // catch empty or invalid position
    int _len = movieVec.size();
    if(_pos < 0)
    {
        cout << ">> Error : Cannot remove: Out of bounds." << endl;
        return false;
    }

    if(_len == 0)
    {
        cout << ">> Error : Cannot remove: Database empty." << endl;
        return false;
    }
    else if(_len < _pos-1)
    {
        cout << ">> Error : Cannot remove: Out of bounds." << endl;
        return false;

    }
    else
    {

        delete movieVec.at(_pos);
        movieVec.erase(movieVec.begin()+_pos);
        cout << ">> DATABASE : Successfully removed media from database!" << endl;;
        return true;
    }

}

void Database::sortByRank()
{
    cout << ">> DATABASE : Sorting by avg. rating:" << endl;

    int _vecsize = movieVec.size();


    for(int i = 0; i<_vecsize; i++)
    {
        for(int j = 0; j < _vecsize-1; j++)
        {
            if(movieVec[i]->getAvgRating() < movieVec[j]->getAvgRating())
            {
                 Mediafile* _temp = movieVec[i];
                 movieVec[i] = movieVec[j];
                 movieVec[j] = _temp;
            }
        }
    }
    //showAll();
}

void Database::showDuration()
{
     int _combinedDur = 0;
     int _avgDur = 0;
     for(Mediafile* _iterator : movieVec)
     {
        _combinedDur += _iterator->getLength();
     }
     _avgDur = _combinedDur/movieVec.size();

     cout << "Total movie duration: "<<_combinedDur << endl;
     cout << "Average movie duration: "<< _avgDur << endl;
}

bool Database::playVideo(const int _pos)
{
    //if(_pos > 0 && _pos < int(movieVec.size()))
    {
        cout << ">> DATABASE : playback!" << endl;
        movieVec[_pos]->playback();
        return true;
    }

    cout << ">> Error : couldnt playback";
    return false;
}

bool Database::init()
{
    char uwu_chan[222];
    ifstream quelle;
    string dateiname = "E:/QT_projects/FreeStreaming2021/database.txt";
    quelle.open(dateiname.c_str(),ios::in);

    if(!quelle) // Check if something went wrong
    {
        cout << "fuck" << endl;
        return false;
    }
    std::string _data;
    int _isReading = 0;
    string _title;
    int _length;
    string _genre;
    vector <int> _ratings;

    while(quelle.getline(uwu_chan,200))
    {

        if(quelle.eof())
        {
            quelle.close();
            cout << ">> Error : End of file.";
            return true;

        }
        _data = uwu_chan;
        //Check if
        if (_data.find("Eintraege:") != std::string::npos) {
            //cout << _data << endl;
            //cout << "found!" << '\n';
            //cout << (_data.substr(11,_data.size()-11)) << endl;
        }

        if(_data.find("*****") != std::string::npos)
        {
            _isReading ++;
            _ratings.clear();

        }

        if(_data.find("Titel: ") != std::string::npos)
        {
            _title = (_data.substr(7,_data.size()-7));
        }

        if(_data.find("Laenge: ") != std::string::npos)
        {
            _length = stoi(_data.substr(8,_data.size()-8));
        }

        if(_data.find("Bewertungen: ") != std::string::npos)
        {

            string __data = (_data.substr(13,_data.size()-13));
            string _r;

            for(int i = 0; i<int(__data.size()); i++)
            {
                if(isdigit(__data[i]))
                {
                    _r = __data[i];
                    //add rating

                    _ratings.push_back(std::stoi(_r));
                   // cout << "added rating: " << std::stoi(_r) << endl;
                }

            }
            __data = "";
            _r = "";



        }

        if(_data.find("Genre: ") != std::string::npos)
        {
            _genre = (_data.substr(7,_data.size()-7));
            Mediafile* _toAdd = new Film(_title,_length,_genre,(rand()%100)+1920);

            for(int i = 0; i<int(_ratings.size());i++)
            {
                _toAdd->addRating(_ratings[i]);
            }

            addVideo(_toAdd);
            //_toAdd.showMeta();
        }
    }

    quelle.close();


    return true;
}

bool Database::initFromFile(string _defaultpath)
{
    srand(time(NULL));
    string dateiname = _defaultpath;
    char uwu_chan[222];
    ifstream quelle;

    try {
        quelle.open(dateiname.c_str(),ios::in);

        if(!quelle || !quelle.is_open()) // Check if something went wrong
        {
            throw std::runtime_error("Something went wrong");

        }
    }  catch (const std::runtime_error &e) {
        std::cerr << e.what() << endl;
        return false;
    }
    /*quelle.open(dateiname.c_str(),ios::in);
    if(!quelle || !quelle.is_open())
    {
        cout << "AAh"<<endl;
        return false;
    }*/


    std::string _data;
    int _isReading = 0;
    string _title;
    int _length;
    string _genre;
    vector <int> _ratings;

    while(quelle.getline(uwu_chan,200))
    {

        if(quelle.eof())
        {
            quelle.close();
            cout << ">> Error : End of file.";
            return true;

        }
        _data = uwu_chan;
        //Check if
        if (_data.find("Eintraege:") != std::string::npos) {
            //cout << _data << endl;
            //cout << "found!" << '\n';
            //cout << (_data.substr(11,_data.size()-11)) << endl;
        }

        if(_data.find("*****") != std::string::npos)
        {
            _isReading ++;
            _ratings.clear();

        }

        if(_data.find("Titel: ") != std::string::npos)
        {
            _title = (_data.substr(7,_data.size()-7));
        }

        if(_data.find("Laenge: ") != std::string::npos)
        {
            _length = stoi(_data.substr(8,_data.size()-8));
        }

        if(_data.find("Bewertungen: ") != std::string::npos)
        {

            string __data = (_data.substr(13,_data.size()-13));
            string _r;

            for(int i = 0; i<int(__data.size()); i++)
            {
                if(isdigit(__data[i]))
                {
                    _r = __data[i];
                    //add rating

                    _ratings.push_back(std::stoi(_r));
                   // cout << "added rating: " << std::stoi(_r) << endl;
                }

            }
            __data = "";
            _r = "";



        }

        if(_data.find("Genre: ") != std::string::npos)
        {
            _genre = (_data.substr(7,_data.size()-7));
            Mediafile* _toAdd = new Film(_title,_length,_genre,(rand()%100)+1920);

            for(int i = 0; i<int(_ratings.size());i++)
            {
                _toAdd->addRating(_ratings[i]);
            }

            addVideo(_toAdd);
            //_toAdd.showMeta();
        }
    }

    quelle.close();


    return true;

}

Mediafile* Database::getMovie(const int _pos)
{

   return movieVec[_pos];

}

bool Database::saveDatabase()
{
    string zdateiname = "E:/QT_projects/FreeStreaming2021/databaseSave.txt";
    cout<< "trying to dump database..."<<endl;

    ofstream ziel(zdateiname.c_str(), ios::out);

    if(!ziel) // uwu
    {
        cerr << zdateiname << " cannot be loaded." << endl;
        return false;
    }

    try {
        if(!ziel) // Check if something went wrong
        {
            throw std::runtime_error("Something went wrong");

        }
    }  catch (const std::runtime_error &e) {
        std::cerr << e.what() << endl;
        return false;
    }

    ziel << "Film-Datenbank" << endl;
    ziel << "Eintraege: " << std::to_string(int(movieVec.size()))<<endl;


    //Loop db
    for(int i =0;i<int(movieVec.size());i++)
    {
        ziel << "*****"<<endl;
        ziel << "Titel: "<<movieVec[i]->getTitle()<<endl;
        ziel << "Laenge: "<<movieVec[i]->getLength()<<endl;
        ziel << "Bewertungen:"<< movieVec[i]->getRatingsString()<<endl;
        ziel << "Genre: "<<movieVec[i]->getGenre()<<endl;
    }


    ziel.close();

    return true;
}

bool Database::saveDatabaseTo(string _defaultpath)
{
    string zdateiname = _defaultpath;
    cout<< "trying to dump database..."<<endl;



    ofstream ziel(zdateiname.c_str(), ios::out);

    try {
        if(!ziel) // Check if something went wrong
        {
            throw std::runtime_error("Something went wrong");

        }
    }  catch (const std::runtime_error &e) {
        std::cerr << e.what() << endl;
        return false;
    }


    ziel << "Film-Datenbank" << endl;
    ziel << "Eintraege: " << std::to_string(int(movieVec.size()))<<endl;


    //Loop db
    for(int i =0;i<int(movieVec.size());i++)
    {
        ziel << "*****"<<endl;
        ziel << "Titel: "<<movieVec[i]->getTitle()<<endl;
        ziel << "Laenge: "<<movieVec[i]->getLength()<<endl;
        ziel << "Bewertungen:"<< movieVec[i]->getRatingsString()<<endl;
        ziel << "Genre: "<<movieVec[i]->getGenre()<<endl;
    }


    ziel.close();

    return true;
}

void Database::simulateReviews(const int numberOfReviews)
{
    int randrating = 0;
    int randmovie = 0;
    srand(time(NULL));

    for(int i = 0; i<numberOfReviews;i++)
    {

        if(int(movieVec.size()) == 1)
        {
             randrating=(rand()%5)+1;
             movieVec[0]->addRating(randrating);

        }
        else
        {

            randrating=(rand()%5)+1;
            randmovie=rand()%movieVec.size();

            cout << ">> Randmovie: "<<randmovie << " randrating: "<< randrating<<endl;

            movieVec[randmovie]->addRating(randrating);

            cout << "added rating "<<int(randrating)<< " to movie "<<movieVec[randmovie]->getTitle() << endl;
        }

    }

    sortByRank();




}

int Database::getMovieCount()
{
    return movieVec.size();
}

void Database::addRatingToVideoDB(int _rating, int _index)
{
    if(_index >= int(movieVec.size())-1)
    {
        cout << "OOB!"<<endl;
        return;
    }
    else if(_index < 0)
    {
        cout << "OOB!"<<endl;
        return;
    }
    else if(movieVec.size() == 0)
    {
        cout << "DB IS EMPTY"<<endl;
        return;
    }

    movieVec[_index]->addRating(_rating);


}


