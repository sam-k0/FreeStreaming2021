#include <iostream>
#include <database.h>
#include <mediafile.h>
#include <serie.h>
#include <main.h>
#include <string>
#include <film.h>
using namespace std;

int errcount = 0;


int main(int argc, char *argv[]) // Zum debuggen auskommentiert. Keine Ahnung wie man kompiliert...
{
    string mainpath = argv[1];//"E:/QT_projects/FreeStreaming2021/databaseSave.txt";//
    //Database::init();

    /*Film* a = new Film("A",5,"a",2000);
    Film* b = new Film("b",5,"b",3000);

    a->amIOlder(b);*/

    // catch wrong params
    /*if(argc < 2)
    {
          cerr << "Verwendung: "<< argv[0]<< "DefaultPath" <<endl;
          exit(-1);
    }
*/
    /// DEBUG!
    Mediafile* a = new Serie("SAO",20,"garbage",0,24);
    Database::addVideo(a);

    ///DEBUG END!
    bool isRunning = true;
    string menuInput = "";

    // Load database
    //Database::init();

    while(isRunning)
    {
        // Show menu
        showMenu();
        // get input
        cin >> menuInput;


        //catch trolls
        if(menuInput.length() > 1)
        {
            cout << "Ungueltige eingabe." << endl;
            continue;
        }
        for(int i = 0; i<int(menuInput.length()); i++)
        {
            if(!isdigit(menuInput[i]))
            {
                cout << "Ungueltige eingabe." << endl;
                continue;
            }
        }

        // Switch input


        switch(stoi(menuInput))
        {
            case 1: // Show all videos
            showVideoLibrary();
            break;

            case 2: // Play one video
            playOneVideo();
            break;

            case 3:
            addRatingToVideo();
            break;

            case 4:

            loadVideoDatabase(mainpath);
            break;

            case 5:
            saveVideoDatabase(mainpath);
            break;

            case 6:
            end();
            break;


            default: // catch trolls
            cout << "Ungueltige eingabe." << endl;
            continue;

        }



    }


    //Database::simulateReviews(500);
    //Database::showDuration();

   // Database::removeVideo(66);
    //Database::saveDatabase();
   // Database::showAll();



cout << endl;


    return 0;*/
}

void showMenu()
{
    // Show menu:
    cout << "(1)  Ausgeben aller Videos (nach Durchschnittsbewertung sortiert)" << endl;
    cout << "(2)  Abspielen eines Videos" << endl;
    cout << "(3)  Hinzufuegen einer Bewertung" << endl;
    cout << "(4)  Datenbank laden..." << endl;
    cout << "(5)  Datenbank speichern" << endl;
    cout << "(6)  Programm beenden" << endl;
    cout << "Errors: "<< errcount <<endl;
}

void playAllVideos()
{
     cout << "Playing all:"<<endl;
    for(int i = 0; i < Database::getMovieCount(); i++)
    {
        Database::playVideo(i);
    }
}

void showVideoLibrary()
{
    Database::sortByRank();
    Database::showAll();
}

bool playOneVideo()
{
    cout<< "What video do you want to play?";
    int _index;
    cin >> _index;


    if(_index >= Database::getMovieCount())
    {
        cout << "Index too high."<<endl;
        return false;

    }
    if(_index < 0)
    {
        cout << "Index below zero."<<endl;
        return false;
    }

    // Play
    Database::playVideo((_index));
    return true;

}

void addRatingToVideo()
{
    int _i, _r;
    cout << "Welches video?" <<endl;
    cin >> _i;
    cout << "Bewertung? (1-5)" << endl;
    cin >> _r;

    Database::addRatingToVideoDB(_r,_i);

}

bool loadVideoDatabase(std::string _defaultPath)
{
   bool success = false;
   string path;

   cout << "From what file?"<<endl;
   //getline(cin, path);
   cin >> path;

   success = Database::initFromFile(path);
   if(!success)
   {
       errcount ++;
       if(errcount>= 3)
       {
           cout << "using default." << endl;
           Database::initFromFile(_defaultPath);
       }
   }
   return success;
}

bool saveVideoDatabase(std::string _defaultPath)
{
    bool success = false;
    string path;

    cout << "To what file?" << endl;
    getline(cin,path);

    success = Database::saveDatabaseTo(path);
    if(!success)
    {
        errcount ++;
        if(errcount>= 3)
        {
            cout << "using default." << endl;
            Database::saveDatabaseTo(_defaultPath);
        }
    }
    return success;
}

void end()
{
    cout << "Alles klar. Bis zum naechsten Mal."<<endl;
    exit(0);
}
