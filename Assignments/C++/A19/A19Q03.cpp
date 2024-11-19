#include<iostream>

class Actor
{
    protected :

        std::string name;
        int age;
        bool isValid;

    public :

        Actor(std::string name = "Default Name", int age = 0) 
        {
            if ( !name.empty() && age >= 0)
            {
                this->name = name;
                this->age = age;
                isValid = true;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid Data for an Actor!\n";
            }
        }

        Actor(const Actor &actor)
        :
            name(actor.name), age(actor.age), isValid(actor.isValid) {}

        virtual void setActorData(std::string name, int age)
        {
            if(!name.empty() && age >= 0)
            {
                this->name = name;
                this->age = age;
                isValid = true;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid Data for an Actor!\n";
            }
        }

        void setName(std::string name)
        {
            if(!name.empty())
            {
                this->name = name;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid Name for an Actor!\n";
            }
        }

        void setAge(int age)
        {
            if(age >= 0)
            {
                this->age = age;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid Age for an Actor!\n";
            }
        }

        std::string getName() const
        {
            return this->name;
        }

        int getAge() const
        {
            return this->age;
        }
};

class TVActor : virtual public Actor
{
    protected:
    
        int TVProjectsDone;
        int TVProjectsCurrentlyRunning;

    public :

        TVActor(std::string name = "Default Name", int age = 0, int TVProjectsDone = 0, int TVProjectsCurrentlyRunning = 0)
        :
            Actor(name, age), TVProjectsDone(TVProjectsDone), TVProjectsCurrentlyRunning(TVProjectsCurrentlyRunning)
        {
            if ( isValid == true && (TVProjectsDone < 0 || TVProjectsCurrentlyRunning < 0))
            {
                isValid = false;
                std::cout<<"Invalid projects data!\n";
            }
        }

        TVActor(const TVActor &actor2)
        :
            Actor(actor2), TVProjectsDone(actor2.TVProjectsDone), TVProjectsCurrentlyRunning(actor2.TVProjectsCurrentlyRunning) {}

        void setTVActor(std::string name, int age, int TVProjectsDone, int TVProjectsCurrentlyRunning)
        {
            setActorData(name, age);
            if ( this->isValid == true && TVProjectsDone >= 0 && TVProjectsCurrentlyRunning >= 0)
            {
                this->TVProjectsDone = TVProjectsDone;
                this->TVProjectsCurrentlyRunning = TVProjectsCurrentlyRunning;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid TV Actor data!\n";
            }
        }

        void showTVActor() const
        {
            if ( this->isValid == true )
            {
                std::cout<<"TV Actor Details -\n";
                std::cout<<"Name : "<<name<<"\n"
                    <<"Age : "<<age<<"\n"
                    <<"TV Projects Done : "<<TVProjectsDone<<"\n"
                    <<"TV Projects Currently Running :"<<TVProjectsCurrentlyRunning<<"\n";
            }
            else
            {
                std::cout<<"Can't display TV Actor data as it is Invalid, first correct the data with setTVActor()\n";
            }
        }

};

class MovieActor : virtual public Actor
{
    protected:
    
        int MoviesDone;
        int MoviesCurrentlyRunning;

    public :

        MovieActor(std::string name = "Default Name", int age = 0, int MoviesDone = 0, int MoviesCurrentlyRunning = 0)
        :
            Actor(name, age), MoviesDone(MoviesDone), MoviesCurrentlyRunning(MoviesCurrentlyRunning)
        {
            if ( isValid == true && (MoviesDone < 0 || MoviesCurrentlyRunning < 0))
            {
                isValid = false;
                std::cout<<"Invalid projects data!\n";
            }
        }

        MovieActor(const MovieActor &actor2)
        :
            Actor(actor2), MoviesDone(actor2.MoviesDone), MoviesCurrentlyRunning(actor2.MoviesCurrentlyRunning) {}

        void setMovieActor(std::string name, int age, int MoviesDone, int MoviesCurrentlyRunning)
        {
            setActorData(name, age);
            if ( this->isValid == true && MoviesDone >= 0 && MoviesCurrentlyRunning >= 0)
            {
                this->MoviesDone = MoviesDone;
                this->MoviesCurrentlyRunning = MoviesCurrentlyRunning;
            }
            else
            {
                isValid = false;
                std::cout<<"Invalid Movie Actor data!\n";
            }
        }

        void showMovieActor() const
        {
            if ( this->isValid == true )
            {
                std::cout<<"Movie Actor Details -\n";
                std::cout<<"Name : "<<name<<"\n"
                    <<"Age : "<<age<<"\n"
                    <<"Movie Projects Done : "<<MoviesDone<<"\n"
                    <<"Movie Projects Currently Running :"<<MoviesCurrentlyRunning<<"\n";
            }
            else
            {
                std::cout<<"Can't display Movie Actor data as it is Invalid, first correct the data with setMovieActor()\n";
            }
        }

};

class AllScreenActor : public TVActor, public MovieActor
{

    public :

        AllScreenActor(std::string name, int age, int TVProjectsDone = 0, int TVProjectsCurrentlyRunning = 0, int MoviesDone = 0, int MoviesCurrentlyRunning = 0)
        :
            Actor(name, age),
            TVActor(name, age, TVProjectsDone, TVProjectsCurrentlyRunning),
            MovieActor(name, age, MoviesDone, MoviesCurrentlyRunning) {}

        AllScreenActor(const AllScreenActor &actor)
        :
            Actor(actor), TVActor(actor), MovieActor(actor) {}

        

        void setActorData(std::string name, int age, int TVProjectsDone, int TVProjectsCurrentlyRunning, int MoviesDone, int MoviesCurrentlyRunning)
        {
            setTVActor(name, age, TVProjectsDone, TVProjectsCurrentlyRunning);
            setMovieActor(name, age, MoviesDone, MoviesCurrentlyRunning);
        }

        void showActorData() const
        {
            if ( isValid )
            {
                std::cout<<"Actor all Details :\n";
                std::cout<<"Name : "<<name<<"\n"
                        <<"Age : "<<age<<"\n"
                        <<"TV Projects Done : "<<TVProjectsDone<<"\n"
                        <<"TV Projects Currently Running :"<<TVProjectsCurrentlyRunning<<"\n"
                        <<"Movie Projects Done : "<<MoviesDone<<"\n"
                        <<"Movie Projects Currently Running :"<<MoviesCurrentlyRunning<<"\n";
            }
            else
            {
                std::cout<<"Can't display Actor data as it is Invalid, first correct the data with setActor()\n";
            }
        }

};

int main()
{
    

    std::cin.get();
    return 0;
}