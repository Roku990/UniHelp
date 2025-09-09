// User function declarations

#pragma once

#include <iostream>
#include <list>


namespace unihelp{
    using json = nlohmann::json;
    using SubjectPtr = std::shared_ptr<Subject>;

    class User{

        public:
        //Construct a new user object
        User(std::string username, std::string password);

        //Get the username of the user
        std::string getUsername();

        //Get the user ID
        std::string GetUserID();

        //Get the password of the user
        std::string getPassword();

        //The User sets a subject for his University
        bool setSubject(SubjectPtr subject);

        //Get the list of subjects of the user
        std::string getUserSubjects();

        private:
        std::string username;
        std::string password;
        std::string userID;
        std::list<SubjectPtr> subjects;
        



    }


}